#pragma once
#include "GameObject.h"
#include "ResourceSystem.h"
#include "AIMovementComponent.h"
#include "StatsComponent.h"
#include "AudioSFX.h"
namespace XYZEngine
{
class AIAnimationComponent : public Component
{
  public:
    AIAnimationComponent(GameObject *gameObject);
    void Initialize(float newFramerate, float FramerateAttack);
    void Update(float deltaTime) override;
    void Render() override;

  private:
    AIMovementComponent *AImove = nullptr;
    SpriteRendererComponent *renderer = nullptr;
    GameObject *object = nullptr;
    StatsComponent *stats = nullptr;
    std::vector<const sf::Texture *> idleFramesTex;
    std::vector<const sf::Texture *> walkFramesTex;
    std::vector<const sf::Texture *> attackFramesTex;
    std::vector<const sf::Texture *> hurtFramesTex;
    float meeleeAttackDistance = 55.f;
    float attackCooldown = 1.f;
    float secondsForFrame = 0.f;
    float secondsForFrameAttack = 0.f;
    float walkCounter = 0.f;
    float idleCounter = 0.f;
    float attackCounter = 0.f;
    int walkFrame = 0;
    int idleFrame = 0;
    int attackFrame = 0;
    int attackHitFrame = 0;
    bool didHitThisSwing = false;
};
} // namespace XYZEngine
