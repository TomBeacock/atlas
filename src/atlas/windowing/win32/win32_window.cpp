#include "atlas/windowing/win32/win32_window.hpp"

#include "atlas/debug/assert.hpp"
#include "atlas/debug/log.hpp"
#include "atlas/system/win32/win32_error.hpp"
#include "atlas/system/win32/win32_string.hpp"

namespace Atlas::Win32 {
bool Window::initialized = false;

Window::Window(Window *parent)
{
    if (!initialized) {
        init();
    }
    const HWND parent_window = parent != nullptr ? parent->m_handle : nullptr;
    m_handle = CreateWindowEx(0, L"Atlas Window", L"Unnamed Window",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, parent_window, nullptr, GetModuleHandle(nullptr), this);
    Debug::assert(m_handle != nullptr, get_last_error_message());
}

Window::~Window()
{
    DestroyWindow(m_handle);
}

void Window::poll_events()
{
    MSG msg{};
    while (PeekMessage(&msg, m_handle, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

bool Window::pop_event(Event &out_event)
{
    if (m_events.empty()) {
        return false;
    }
    out_event = std::move(m_events.front());
    m_events.pop();
    return true;
}

void Window::show() const
{
    ShowWindow(m_handle, SW_SHOWDEFAULT);
}

void Window::set_title(const std::string_view title) const
{
    const std::wstring wide_title = utf8_to_wstring(std::string(title));
    SetWindowText(m_handle, wide_title.c_str());
}

void Window::set_position(Math::Int2 position) const
{
    SetWindowPos(m_handle, nullptr, position.x, position.y, 0, 0,
        SWP_NOSIZE | SWP_NOREPOSITION);
}

void Window::set_size(Math::Nat2 size) const
{
    RECT rect{0, 0, static_cast<INT>(size.x), static_cast<INT>(size.y)};
    AdjustWindowRectEx(
        &rect, GetWindowStyle(m_handle), FALSE, GetWindowExStyle(m_handle));
    SetWindowPos(m_handle, nullptr, 0, 0, rect.right - rect.left,
        rect.bottom - rect.top, SWP_NOMOVE | SWP_NOREPOSITION);
}

LRESULT Window::handle_message(UINT msg, WPARAM w_param, LPARAM l_param)
{
    switch (msg) {
        case WM_CLOSE: {
            m_events.push(Event::WindowClosing{});
            return 0;
        }
        case WM_MOVE: {
            m_events.push(Event::WindowMoved{
                Math::Nat2{static_cast<Nat>(LOWORD(l_param)),
                           static_cast<Nat>(HIWORD(l_param))}
            });
            return 0;
        }
        case WM_SIZE: {
            m_events.push(Event::WindowResized{
                Math::Nat2{static_cast<Nat>(LOWORD(l_param)),
                           static_cast<Nat>(HIWORD(l_param))}
            });
            return 0;
        }
        case WM_LBUTTONDOWN: {
            m_events.push(Event::MouseButtonPressed{
                Atlas::MouseButton::Left,
                {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
            });
            return 0;
        }
        case WM_LBUTTONUP: {
            m_events.push(Event::MouseButtonReleased{
                Atlas::MouseButton::Left,
                {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
            });
            return 0;
        }
        case WM_RBUTTONDOWN: {
            m_events.push(Event::MouseButtonPressed{
                Atlas::MouseButton::Right,
                {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
            });
            return 0;
        }
        case WM_RBUTTONUP: {
            m_events.push(Event::MouseButtonReleased{
                Atlas::MouseButton::Right,
                {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
            });
            return 0;
        }
        case WM_MBUTTONDOWN: {
            m_events.push(Event::MouseButtonPressed{
                Atlas::MouseButton::Middle,
                {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
            });
            return 0;
        }
        case WM_MBUTTONUP: {
            m_events.push(Event::MouseButtonReleased{
                Atlas::MouseButton::Middle,
                {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
            });
            return 0;
        }
        case WM_XBUTTONDOWN: {
            if (GET_XBUTTON_WPARAM(w_param) == XBUTTON1) {
                m_events.push(Event::MouseButtonPressed{
                    Atlas::MouseButton::X1,
                    {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
                });
            }
            else {
                m_events.push(Event::MouseButtonPressed{
                    Atlas::MouseButton::X2,
                    {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
                });
            }
            return TRUE;
        }
        case WM_XBUTTONUP: {
            if (GET_XBUTTON_WPARAM(w_param) == XBUTTON1) {
                m_events.push(Event::MouseButtonReleased{
                    Atlas::MouseButton::X1,
                    {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
                });
            }
            else {
                m_events.push(Event::MouseButtonReleased{
                    Atlas::MouseButton::X2,
                    {GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)}
                });
            }
            return TRUE;
        }
        case WM_MOUSEWHEEL: {
            float delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(w_param))
                          / WHEEL_DELTA;
            m_events.push(Event::MouseWheelScrolled{Math::Float2(0, delta)});
            return 0;
        }
        case WM_MOUSEHWHEEL: {
            float delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(w_param))
                          / WHEEL_DELTA;
            m_events.push(Event::MouseWheelScrolled{Math::Float2(delta, 0)});
            return 0;
        }
        case WM_MOUSEMOVE: {
            Math::Float2 position(GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param));
            Math::Float2 delta = position - m_last_mouse_position;
            m_events.push(Event::MouseMoved{position, delta});
            m_last_mouse_position = position;
            return 0;
        }
    }
    return DefWindowProc(m_handle, msg, w_param, l_param);
}

void Window::init()
{
    WNDCLASSEX window_class{
        .cbSize = sizeof(WNDCLASSEX),
        .lpfnWndProc = proc,
        .hInstance = GetModuleHandle(nullptr),
        .lpszClassName = L"Atlas Window",
    };
    ATOM class_atom = RegisterClassEx(&window_class);
    Debug::assert(class_atom != 0, get_last_error_message());
    initialized = true;
}

LRESULT Window::proc(HWND wnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
    Window *window = nullptr;
    if (msg == WM_NCCREATE) {
        CREATESTRUCT *create = reinterpret_cast<CREATESTRUCT *>(l_param);
        window = reinterpret_cast<Window *>(create->lpCreateParams);
        SetWindowLongPtr(
            wnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
        window->m_handle = wnd;
    }
    else {
        window
            = reinterpret_cast<Window *>(GetWindowLongPtr(wnd, GWLP_USERDATA));
    }

    if (window != nullptr) {
        return window->handle_message(msg, w_param, l_param);
    }
    else {
        return DefWindowProc(wnd, msg, w_param, l_param);
    }
}
}  // namespace Atlas::Win32
