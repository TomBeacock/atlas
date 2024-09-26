#pragma once

#include <atlas/core.hpp>

namespace Simple {
class MainStage : public Atlas::Stage {
  protected:
    virtual void on_attach() override;
    virtual void on_event() override;
    virtual void on_update() override;
};
}  // namespace Simple
