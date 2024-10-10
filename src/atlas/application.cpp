#include "atlas/application.hpp"

#include "atlas/debug/log.hpp"

namespace Atlas {
void Application::run()
{
    if (m_running) {
        Debug::log_warning(
            "Trying to run Application whilst it is already running.");
        return;
    }

    m_running = true;
    while (m_running) {
        // Poll all windows for events
        for (auto &window : m_windows) {
            if (window != nullptr) {
                window->poll_events();
            }
        }

        // Update all windows
        for (auto &window : m_windows) {
            if (window != nullptr) {
                window->update();
            }
        }

        // Cleanup old window pointers
        if (m_windows_dirty) {
            std::erase(m_windows, nullptr);
            m_windows_dirty = false;
        }
    }
}

void Application::exit()
{
    m_running = false;
}

Application::Application()
{
    Debug::assert(m_current == nullptr,
        "Error creating application, an application already exists.");
    m_current = this;
}

Application::~Application()
{
    for (auto &top_level_window : m_top_level_windows) {
        top_level_window.reset(nullptr);
    }
    m_current = nullptr;
    m_main_window = nullptr;
}

Window &Application::create_top_level_window()
{
    m_top_level_windows.push_back(std::make_unique<Window>(nullptr));
    if (m_main_window == nullptr) {
        m_main_window = m_top_level_windows.front().get();
    }
    return *m_top_level_windows.back();
}

void Application::destroy_top_level_window(Window *top_level_window)
{
    bool erased
        = std::erase_if(m_top_level_windows, [top_level_window](auto &window) {
              return window.get() == top_level_window;
          });
    Debug::assert(
        erased, "Failed to destroy window, could not find top level window.");

    if (m_exit_mode == ExitMode::LastWindowClose
        && m_top_level_windows.empty()) {
        exit();
    }

    if (m_main_window == top_level_window) {
        m_main_window = nullptr;

        if (!m_top_level_windows.empty()) {
            m_main_window = m_top_level_windows.front().get();
        }

        if (m_exit_mode == ExitMode::MainWindowClose) {
            exit();
        }
    }
}

void Application::register_window(Window *window)
{
    m_windows.push_back(window);
}

void Application::unregister_window(Window *window)
{
    auto it = std::find(m_windows.begin(), m_windows.end(), window);
    if (it != m_windows.end()) {
        *it = nullptr;
        m_windows_dirty = true;
    }
}

Application *Application::m_current = nullptr;
}  // namespace Atlas
