#include "MenuState.h"

#include "StateManager.h"

#include "ResourceManager.h"

void MenuState::onEnterState(GameStateManager* sm) {
  setStateManager(sm);
}

void MenuState::onExitState() {
  releaseStateManager();
}

void MenuState::handleEvents() {
  const Uint8* keystate = SDL_GetKeyboardState(NULL);
  if (keystate[SDL_SCANCODE_RETURN]) {  
    if (stateManager){
      stateManager->switchState(GameState::PLAYING);
    }
    else {
      printf("error is stateManager not being set!\n");
    }
  }
}

void MenuState::update(float deltaTime) {
  handleEvents();
}

void MenuState::render(SDL_Renderer *r) {
  backgroundLogo->render(r);
}

MenuState::MenuState(SDL_Renderer* r, ResourceManager* resourceManager) {
  backgroundLogo = new Sprite(r, resourceManager, Atlas::ATLAS_MENU_TEXTURE, bgLogoName, 0, 0);
}

MenuState::~MenuState() {
  delete backgroundLogo;
  backgroundLogo = nullptr;
}

