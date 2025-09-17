#include "Cobald.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
#include <SpriteDirectionComponent.h>
#include <AIMovementComponent.h>
#include <AIAnimationComponent.h>
#include <AttackComponent.h>

namespace XYZRoguelike
{
Cobald::Cobald(const XYZEngine::Vector2Df &position, XYZEngine::GameObject *target)
{
    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Cobald");
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(position);

    auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("cobald_idle", 0));
    renderer->SetPixelSize(100, 120);

    auto movement = gameObject->AddComponent<XYZEngine::AIMovementComponent>();
    movement->SetSpeed(100.f);
    movement->SetTarget(target);
    auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
    rigidbody->SetKinematic(false);
    auto statsComponent = gameObject->AddComponent<XYZEngine::StatsComponent>(10.f, 0.f);
    auto AIAnimation = gameObject->AddComponent<XYZEngine::AIAnimationComponent>();
    AIAnimation->Initialize(6.f, 5.f);
    auto collider = gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
    collider->SetPadding({50.f, 0.f});
    auto attack = gameObject->AddComponent<XYZEngine::AttackComponent>(10.f);
}

} // namespace XYZRoguelike
