#pragma once
#include "GameObject.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "ResourceSystem.h"
#include "StatsComponent.h"
#include "HUDUpdaterComponent.h"


namespace XYZRoguelike 
{
class ArmorBar
{
public:
	ArmorBar(const XYZEngine::Vector2Df& position);
	
        
	 
	

private:
	XYZEngine::GameObject* gameObject;
    XYZEngine::StatsComponent* playerArmor;
	
	
};

}