#pragma once

#include <atlas/core.hpp>

namespace Simple {
class MainLayer : public Atlas::Layer {
  protected:
    virtual void on_attach() override;
    virtual void on_event(Atlas::Event &event) override;
    virtual void on_update() override;
};
}  // namespace Simple
