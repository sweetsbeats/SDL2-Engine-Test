/*
  SWEETSBEATS 2018
*/
#pragma once
#include <SDL.h>
#include "Component.h"
#include "Entity.h"


namespace Player {
  Entity* createPlayer(SDL_Renderer* r);
}
