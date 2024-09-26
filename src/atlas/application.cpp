#include "atlas/application.hpp"

#include "atlas/debug/log.hpp"
#include "atlas/window/stage.hpp"

namespace Atlas {

Application *Application::m_current = nullptr;

Application::Application()
{
    Debug::assert(m_current == nullptr,
        "Error creating application, an application already exists.");
    m_current = this;
}

Application::~Application()
{
    m_current = nullptr;
}

void Application::run()
{
    if (m_running) {
        Debug::log_warning(
            "Trying to run Application whilst it is already running.");
        return;
    }
    m_running = true;
    while (m_running) {
        for (auto &[tag, window] : m_windows) {
            window.poll_events();
        }
        for (auto &[tag, window] : m_windows) {
            window.update();
        }
    }
}

Window &Application::create_window(
    Size tag, std::unique_ptr<Stage> stage, Window *parent)
{
    if (auto it = m_windows.find(tag); it != m_windows.end()) {
        Debug::log_warning(std::format(
            "A window with tag '{}' already exists, use get_window instead.",
            tag));
        return it->second;
    }
    auto [it, success] = m_windows.try_emplace(tag, std::move(stage), parent);
    Debug::assert(success, "Failed to create window.");
    return it->second;
}
}  // namespace Atlas
