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

void Window::set_position(Math::Nat2 position) const
{
    SetWindowPos(m_handle, nullptr, static_cast<Int>(position.x),
        static_cast<Int>(position.y), 0, 0, SWP_NOSIZE | SWP_NOREPOSITION);
}

void Window::set_size(Math::Nat2 size) const
{
    SetWindowPos(m_handle, nullptr, 0, 0, static_cast<Int>(size.x),
        static_cast<Int>(size.y), SWP_NOMOVE | SWP_NOREPOSITION);
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
                Math::Nat2{static_cast<Int16>(LOWORD(l_param)),
                           static_cast<Int16>(HIWORD(l_param))}
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
