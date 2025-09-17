#pragma once
#include "GameObject.h"
#include "ResourceSystem.h"
#include "SpriteRendererComponent.h"
#include "StatsComponent.h"

namespace XYZEngine
{

class ItemAnimationComponent : public Component
{
  public:
    ItemAnimationComponent(GameObject *gameObject);
    void Initialize(float newFramerate);
    void Update(float deltaTime) override;
    void Render() override {};
    void SetTarget(GameObject *target);

  private:
    GameObject *object = nullptr;
    GameObject *objectTarget = nullptr;
    SpriteRendererComponent *renderer = nullptr;
    TransformComponent *transform = nullptr;
    StatsComponent *stats = nullptr;
    std::vector<const sf::Texture *> itemFramesTex;
    std::string itemKey;
    float secondsForFrame = 0.f;
    float counter = 0.f;
    float pickupDistance = 55.f;
    int heartFrame = 0;
};
} // namespace XYZEngine