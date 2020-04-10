#pragma once

#include <memory>
#include "EventHandler.h"

class Game
{
public:
  Game();
  ~Game();

  void setEventHandler(std::shared_ptr<EventHandler> eh);

private:
  std::shared_ptr<EventHandler> _eh;
};

