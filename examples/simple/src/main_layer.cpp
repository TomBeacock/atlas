#include "main_layer.hpp"

namespace Simple {
void MainLayer::on_attach() {}

void MainLayer::on_event(Atlas::Event &event)
{
    if (const auto data = event.get_if<Atlas::Event::WindowResized>()) {
        Atlas::Debug::log_info(
            std::format("Window size changed: {}", data->size));
    }
    else if (const auto data = event.get_if<Atlas::Event::WindowMoved>()) {
        Atlas::Debug::log_info(
            std::format("Window position changed: {}", data->position));
    }
    else if (const auto data = event.get_if<Atlas::Event::WindowClosing>()) {
        Atlas::Debug::log_warning("Window closing");
    }
}

void MainLayer::on_update() {}
}  // namespace Simple
