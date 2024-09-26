#pragma once

namespace Atlas {
class Stage {
    friend Atlas::Window;

  protected:
    /**
     * @brief Called once when the stage is attached to a window.
     */
    virtual void on_attach() {}

    /**
     * @brief Called for each event recieved.
     */
    virtual void on_event() {}

    /**
     * @brief Called once per frame.
     */
    virtual void on_update() {}
};
}  // namespace Atlas
