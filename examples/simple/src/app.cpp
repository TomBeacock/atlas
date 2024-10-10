#include "app.hpp"

#include "main_layer.hpp"

using namespace Atlas;

namespace Simple {
App::App()
{
    Window &window = Window::create();
    window.attach_layer<MainLayer>();
    window.set_title("Simple example");
    window.set_size({1280, 720});
    window.show();
}
}  // namespace Simple
