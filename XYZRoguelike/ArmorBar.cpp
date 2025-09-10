#include "ArmorBar.h"
namespace XYZRoguelike
{
	ArmorBar::ArmorBar(const XYZEngine::Vector2Df& position)
	{
	  gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Armor_bar");
	  auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
	  transform->SetWorldPosition(position);

	  auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
	  renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("armor_bar", 0));
	  renderer->SetPixelSize(100, 100);

	  if (auto* player =XYZEngine:: GameWorld::Instance()->FindObjectByName("Player"))
	  {
		  auto* playerT = player->GetComponent<XYZEngine::TransformComponent>();
		  playerArmor = player->GetComponent<XYZEngine::StatsComponent>();
          transform->SetParent(playerT); 
	      transform->SetLocalPosition({-610.f,175.f});
	  }
	   auto change = gameObject->AddComponent<XYZEngine::HUDUpdaterComponent>();
	  change->Initialize();
	  change->SetTargetStats(playerArmor);
	}
	




	

	

}

