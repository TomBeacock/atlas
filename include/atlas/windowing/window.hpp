#pragma once

#include "atlas/math.hpp"
#include "atlas/windowing/layer.hpp"

#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace Atlas {
class Event;

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
    Window(Window *parent = nullptr);
    ~Window();

    template<typename T, typename... Args>
    constexpr Layer &attach_layer(Args &&...args);

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
     * @brief Stop the window from closing.
     */
    void cancel_close();

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

    static Window &create(Window *parent = nullptr);

  private:
    Window &create_child();
    void destroy_child(Window *child);

  private:
    Window *m_parent;
    std::vector<std::unique_ptr<Window>> m_children;
    std::vector<std::unique_ptr<Layer>> m_layers;
    std::unique_ptr<NativeWindow> m_native_window;
    bool m_open = false;
    bool m_closing = false;
};

template<typename T, typename... Args>
constexpr inline Layer &Window::attach_layer(Args &&...args)
{
    static_assert(std::is_base_of<Layer, T>());
    m_layers.push_back(std::make_unique<T>(args...));
    Layer &layer = *m_layers.back();
    layer.on_attach();
    return layer;
}
}  // namespace Atlas
