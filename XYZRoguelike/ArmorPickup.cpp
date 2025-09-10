#include "ArmorPickup.h"

namespace XYZRoguelike
{
	
	ArmorPickup::ArmorPickup(const XYZEngine::Vector2Df& position, XYZEngine::GameObject* target)
	{
		gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("armor");
		auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
		transform->SetWorldPosition(position);
		auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
		renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("armor_item", 0));
		renderer->SetPixelSize(32, 32);
		auto itemAnimation = gameObject->AddComponent<XYZEngine::ItemAnimationComponent>();
		itemAnimation->Initialize(6.f);
        itemAnimation->SetTarget(target);







	}


}

