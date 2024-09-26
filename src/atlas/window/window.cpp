#include "atlas/window/window.hpp"

#include "atlas/window/stage.hpp"

#ifdef ATLAS_PLATFORM_WIN32
  #include "atlas/window/win32/window.hpp"
#endif

namespace Atlas {
Window::Window(std::unique_ptr<Stage> stage, Window *parent)
  : m_native_window(std::make_unique<NativeWindow>(
      parent != nullptr ? parent->m_native_window.get() : nullptr)),
    m_stage(std::move(stage))
{
    m_stage->on_attach();
}

Window::~Window() {}

void Window::poll_events()
{
    m_native_window->poll_events();
}

void Window::update()
{
    m_stage->on_update();
}

void Window::show()
{
    m_native_window->show();
}

void Window::set_title(const std::string_view title) const
{
    m_native_window->set_title(title);
}

void Window::set_position(Math::Nat2 position) const
{
    m_native_window->set_position(position);
}

void Window::set_size(Math::Nat2 size) const
{
    m_native_window->set_size(size);
}
}  // namespace Atlas
