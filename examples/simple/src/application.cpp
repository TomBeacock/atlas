#include "application.hpp"

#include "main_stage.hpp"

using namespace Atlas;

namespace Simple {
constexpr Size main_window_tag = 0;

App::App()
{
    std::unique_ptr<MainStage> main_stage = std::make_unique<MainStage>();
    Window &main_window = create_window(main_window_tag, std::move(main_stage));
    main_window.set_title("Simple example");
    main_window.set_size({1280, 720});
    main_window.show();
}
}  // namespace Simple
