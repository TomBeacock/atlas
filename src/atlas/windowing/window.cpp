#include "atlas/windowing/window.hpp"

#include "atlas/application.hpp"
#include "atlas/events/event.hpp"

#ifdef ATLAS_PLATFORM_WIN32
  #include "atlas/windowing/win32/win32_window.hpp"
#endif

namespace Atlas {
Window::Window(Window *parent)
  : m_parent(parent),
    m_native_window(std::make_unique<NativeWindow>(
        parent != nullptr ? parent->m_native_window.get() : nullptr))
{
    Application::current().register_window(this);
}

Window::~Window()
{
    Application::current().unregister_window(this);
}

void Window::poll_events()
{
    m_native_window->poll_events();

    Event event;
    while (m_native_window->pop_event(event)) {
        // Begin close
        if (event.is<Event::WindowClosing>()) {
            m_closing = true;
        }

        // Pass event to handler
        for (auto &layer : m_layers) {
            layer->on_event(event);
        }

        // Close window
        if (m_closing) {
            if (m_parent == nullptr) {
                Application::current().destroy_top_level_window(this);
            }
            else {
                m_parent->destroy_child(this);
            }
            return;
        }
    }
}

void Window::update()
{
    for (auto &layer : m_layers) {
        layer->on_update();
    }
}

void Window::show()
{
    m_native_window->show();
}

void Window::cancel_close()
{
    m_closing = false;
}

void Window::set_title(const std::string_view title) const
{
    m_native_window->set_title(title);
}

void Window::set_position(Math::Int2 position) const
{
    m_native_window->set_position(position);
}

void Window::set_size(Math::Nat2 size) const
{
    m_native_window->set_size(size);
}

Window &Window::create(Window *parent)
{
    if (parent == nullptr) {
        return Application::current().create_top_level_window();
    }
    else {
        return parent->create_child();
    }
}

Window &Window::create_child()
{
    m_children.push_back(std::make_unique<Window>(this));
    return *m_children.back();
}

void Window::destroy_child(Window *child)
{
    bool erased = std::erase_if(
        m_children, [child](auto &window) { return window.get() == child; });
    Debug::assert(erased, "Failed to destroy window, could not find child.");
}
}  // namespace Atlas
