#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}

void Game::setEventHandler(std::shared_ptr<EventHandler> eh)
{
  _eh = eh;
}
