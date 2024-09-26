#pragma once

#include "atlas/math.hpp"

#include <memory>
#include <string>
#include <string_view>

namespace Atlas {
class Stage;

#ifdef ATLAS_PLATFORM_WIN32
namespace Win32 {
class Window;
}  // namespace Win32

using NativeWindow = Win32::Window;
#endif
}  // namespace Atlas

namespace Atlas {
class Window {
  public:
    /**
     * @brief Construct window.
     * @param stage Stage to attach.
     * @param parent Parent window, or null for no parent.
     */
    Window(std::unique_ptr<Stage> stage, Window *parent = nullptr);
    ~Window();

    /**
     * @brief Poll window events.
     */
    void poll_events();

    /**
     * @brief Frame based update.
     */
    void update();

    /**
     * @brief Show the window.
     */
    void show();

    /**
     * @brief Get the attached stage.
     * @return The attached stage.
     */
    inline Stage &get_stage() const;

    /**
     * @brief Set the window's title.
     * @param title The title.
     */
    void set_title(const std::string_view title) const;

    /**
     * @brief Set the window's position.
     * @param position New position.
     */
    void set_position(Math::Nat2 position) const;

    /**
     * @brief Set the window's size.
     * @param size The new size.
     */
    void set_size(Math::Nat2 size) const;

  private:
    std::unique_ptr<NativeWindow> m_native_window;
    std::unique_ptr<Stage> m_stage;
    bool m_open = false;
};

inline Stage &Window::get_stage() const
{
    return *m_stage;
}
}  // namespace Atlas
