#pragma once

namespace Atlas {
class Event;
}  // namespace Atlas

namespace Atlas {
class Layer {
    friend class Window;

  protected:
    /**
     * @brief Called once when the layer is attached to a window.
     */
    virtual void on_attach() {}

    /**
     * @brief Called for each event recieved.
     */
    virtual void on_event(Event &event) {}

    /**
     * @brief Called once per frame.
     */
    virtual void on_update() {}
};
}  // namespace Atlas
