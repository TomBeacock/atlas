#include "event.hpp"

namespace Atlas {
inline Event::Event()
  : m_data(Empty{})
{
}

template<typename T>
inline Event::Event(const T &data)
{
    static_assert(is_event_type<T>, "T must be a subtype of Atlas::Event.");
    if constexpr (is_event_type<T>) {
        m_data = data;
    }
}

template<typename T>
bool Event::is() const
{
    static_assert(is_event_type<T>, "T must be a subtype of Atlas::Event.");
    if constexpr (is_event_type<T>) {
        return std::holds_alternative<T>(m_data);
    }
}

template<typename T>
const T *Event::get_if() const
{
    static_assert(is_event_type<T>, "T must be a subtype of Atlas::Event.");
    if constexpr (is_event_type<T>) {
        return std::get_if<T>(&m_data);
    }
}

inline Event::operator bool() const
{
    return !is<Empty>();
}
}  // namespace Atlas
