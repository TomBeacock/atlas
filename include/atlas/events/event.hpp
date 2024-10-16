#pragma once

#include "atlas/events/key_codes.hpp"
#include "atlas/events/mouse_codes.hpp"
#include "atlas/math.hpp"

#include <variant>

namespace Atlas {
class Event {
  public:
    struct Empty {};

    struct WindowClosing {};

    struct WindowMoved {
        Math::Nat2 position;
    };

    struct WindowResized {
        Math::Nat2 size;
    };

    struct KeyChanged {
        KeyCode key_code;
        ScanCode scan_code;
    };

    struct KeyPressed : KeyChanged {};

    struct KeyReleased : KeyChanged {};

    struct MouseButtonChanged {
        MouseButton button;
        Math::Int2 position;
    };

    struct MouseButtonPressed : MouseButtonChanged {};

    struct MouseButtonReleased : MouseButtonChanged {};

    struct MouseWheelScrolled {
        Math::Float2 delta;
    };

    struct MouseMoved {
        Math::Float2 position;
        Math::Float2 delta;
    };

  public:
    Event();

    template<typename T>
    Event(const T &data);

    /**
     * Checks whether the event is of type.
     *
     * @tparam T The type to compare against.
     * @return If the event and given types match.
     */
    template<typename T>
    bool is() const;

    /**
     * Gets the event data of the given type.
     *
     * @tparam T The type of event to retrieve.
     * @return Event data of type, or the empty event if types don't match.
     */
    template<typename T>
    const T *get_if() const;

    explicit operator bool() const;

  private:
    std::variant<Empty, WindowClosing, WindowMoved, WindowResized, KeyPressed,
        KeyReleased, MouseButtonPressed, MouseButtonReleased,
        MouseWheelScrolled, MouseMoved>
        m_data;

  private:
    template<typename T, typename... Ts>
    constexpr static bool is_variant_type(const std::variant<Ts...> &)
    {
        return (std::is_same_v<T, Ts> || ...);
    }

    template<typename T>
    constexpr static bool is_event_type
        = is_variant_type<T>(decltype(m_data)());
};
}  // namespace Atlas

#include "event.inl"
