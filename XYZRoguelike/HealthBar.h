#pragma once
#include "GameObject.h"
#include "GameWorld.h"
#include "RenderSystem.h"
#include "SpriteRendererComponent.h"
#include "Vector.h"
#include "ResourceSystem.h"
#include "StatsComponent.h"

namespace XYZRoguelike

{
class HealthBar
{
  public:
    HealthBar(const XYZEngine::Vector2Df &position);

  private:
    XYZEngine::GameObject *gameObject;
    XYZEngine::StatsComponent *playerHP;
};

} // namespace XYZRoguelike
