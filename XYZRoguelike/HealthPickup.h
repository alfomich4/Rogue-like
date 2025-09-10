#pragma once
#include "GameObject.h"
#include "GameWorld.h"
#include "RenderSystem.h"
#include "SpriteRendererComponent.h"
#include "ResourceSystem.h"
#include "ItemAnimationComponent.h"


namespace XYZRoguelike
{
class HealthPickup 
  {
 public:
  HealthPickup(const XYZEngine::Vector2Df& position, XYZEngine::GameObject* target);
  XYZEngine::GameObject* GetGameObject();
 

 private:
  XYZEngine::GameObject* gameObject;
 
 
};
} 
