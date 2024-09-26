#pragma once

#include "atlas/debug/assert.hpp"
#include "atlas/window/window.hpp"

#include <map>

namespace Atlas {
class Application {
  public:
    /**
     * @brief Run the application
     */
    void run();

    /**
     * @brief Create a window.
     * @param tag User defined tag to access window later, should be unique to
     * each window.
     * @param stage Stage to attach to the window.
     * @param parent Parent window, or null for no parent.
     * @return The newly created window.
     */
    Window &create_window(
        Size tag, std::unique_ptr<Stage> stage, Window *parent = nullptr);

    /**
     * @brief Get the current application.
     * @return The current application.
     */
    inline static Application &get_current();

  protected:
    Application();
    ~Application();

  private:
    std::map<Size, Window> m_windows;
    bool m_running = false;

    static Application *m_current;
};

inline Application &Application::get_current()
{
    Debug::assert(m_current != nullptr,
        "Cannot get current application, application has not yet been created "
        "or has been destroyed.");
    return *m_current;
}
}  // namespace Atlas
