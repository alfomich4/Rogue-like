#include "HealthPickup.h"



namespace XYZRoguelike
{
    HealthPickup::HealthPickup(const XYZEngine::Vector2Df& position, XYZEngine::GameObject* target)
    {
  
     gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("health_pickup");
	 auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
     transform->SetWorldPosition(position);

	 auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
     renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("health_item",0));
     renderer->SetPixelSize(100, 100);

     auto itemAnimation = gameObject->AddComponent<XYZEngine::ItemAnimationComponent>();
     itemAnimation->Initialize(6.f);
     itemAnimation->SetTarget(target);
     

    
      
        

    
}

    XYZEngine::GameObject* HealthPickup::GetGameObject()
    { 
       return gameObject;
   
    }















}
