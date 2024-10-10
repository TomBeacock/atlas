#pragma once

#include "atlas/debug/assert.hpp"
#include "atlas/windowing/window.hpp"

#include <vector>

namespace Atlas {
class Application {
    friend class Window;

  public:
    enum class ExitMode : Nat8 {
        LastWindowClose = 0,
        MainWindowClose = 1,
        Explicit = 2,
    };

  public:
    /**
     * @brief Run the application.
     */
    void run();

    /**
     * @brief Exit the application.
     */
    void exit();

    inline void set_exit_mode(ExitMode exit_mode);

    /**
     * @brief Get the current application.
     * @return The current application.
     */
    inline static Application &current();

  protected:
    Application();
    ~Application();

  private:
    Window &create_top_level_window();
    void destroy_top_level_window(Window *top_level_window);

    void register_window(Window *window);
    void unregister_window(Window *window);

  private:
    Window *m_main_window = nullptr;
    std::vector<Window *> m_windows;
    std::vector<std::unique_ptr<Window>> m_top_level_windows;
    bool m_running = false;
    bool m_windows_dirty = false;
    ExitMode m_exit_mode = ExitMode::LastWindowClose;

    static Application *m_current;
};

inline void Atlas::Application::set_exit_mode(ExitMode exit_mode)
{
    m_exit_mode = exit_mode;
}

inline Application &Application::current()
{
    Debug::assert(m_current != nullptr,
        "Cannot get current application, application has not yet been created "
        "or has been destroyed.");
    return *m_current;
}
}  // namespace Atlas
