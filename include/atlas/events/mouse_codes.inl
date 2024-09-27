namespace Atlas {
inline std::ostream &operator<<(std::ostream &os, MouseButton mouse_button)
{
    return os << to_string(mouse_button);
}
}  // namespace Atlas
