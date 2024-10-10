#pragma once

#include "atlas/events/event.hpp"
#include "atlas/math.hpp"
#include "atlas/system/win32/win32.hpp"

#include <queue>
#include <string_view>

namespace Atlas {
struct Event;
}  // namespace Atlas

namespace Atlas::Win32 {
class Window {
  public:
    Window(Window *parent = nullptr);
    ~Window();

    void poll_events();
    bool pop_event(Event &out_event);
    void show() const;

    void set_title(const std::string_view title) const;
    void set_position(Math::Nat2 position) const;
    void set_size(Math::Nat2 size) const;

  private:
    LRESULT handle_message(UINT msg, WPARAM w_param, LPARAM l_param);

    static void init();
    static LRESULT proc(HWND wnd, UINT msg, WPARAM w_param, LPARAM l_param);

  private:
    HWND m_handle = nullptr;
    std::queue<Event> m_events;

    static bool initialized;
};
}  // namespace Atlas::Win32