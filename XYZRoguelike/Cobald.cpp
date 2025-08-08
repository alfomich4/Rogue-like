#include "Cobald.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
#include <SpriteDirectionComponent.h>
#include <SpriteMovementAnimationComponent.h>
#include <StatsComponent.h>
#include <AttackComponent.h>

Cobald::Cobald(const XYZEngine::Vector2Df& position)
{

	gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Cobald");
	auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
	transform->SetWorldPosition(position);

	auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
	renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("cobald_idle", 0));
	renderer->SetPixelSize(100, 120);

}
