#pragma once

#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "GameObject.h"


namespace XYZRoguelike
{
class Cobald
{
  public:
    Cobald(const XYZEngine::Vector2Df &position, XYZEngine::GameObject *target);
    XYZEngine::GameObject *GetGameObject();

  private:
    XYZEngine::GameObject *gameObject;
};
} // namespace XYZRoguelike
