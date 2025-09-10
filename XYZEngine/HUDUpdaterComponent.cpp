#include "pch.h"
#include "HUDUpdaterComponent.h"
#include <cassert>

namespace XYZEngine
{
	HUDUpdaterComponent::HUDUpdaterComponent(GameObject* gameObject) : Component(gameObject)
	{
	   renderer = gameObject->GetComponent<SpriteRendererComponent>();
	   object = gameObject;
      

		if (object == nullptr)
		{
			std::cout << "Need object for switch component" << std::endl;
			gameObject->RemoveComponent(this);
		}
		else if (renderer == nullptr)
		{
			std::cout << "Need SpriteRenderer component for switch component" << std::endl;
			gameObject->RemoveComponent(this);
		}
		
	
	
	}

	void HUDUpdaterComponent::Initialize()
	{
		
		const auto& name = object->GetName();
		

		if (name == "Health_bar") 
		{
			barKey = "health_bar";
			
			
			
		}

		if(name== "Armor_bar")
		{
			transform = object->GetComponent<TransformComponent>();
			barKey = "armor_bar";
			assert(uiFont.loadFromFile("Resources/Fonts/Roboto-Regular.ttf"));
			{
            armorText.setFont(uiFont);
            armorText.setCharacterSize(40);
            armorText.setFillColor(sf::Color::White);
			armorText.setStyle(sf::Text::Bold);
            armorText.setOutlineColor(sf::Color::Black);
            armorText.setOutlineThickness(4.f);
            armorText.setScale(1.f, -1.f);
			
           
            }

        }

        switchTex.clear();

		for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(barKey); i++)
		{
			switchTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(barKey, i));
		}
		
	}
	void HUDUpdaterComponent::Update(float deltaTime)
	{
		if(barKey=="health_bar")
		{ 
		const float hp  = stats->GetCurrentHealth();
		barFrame = 0;

		for (int i = 0; i < cuts.size(); ++i)
		{
		  if (hp <= cuts[i])
		  {
			  barFrame += 1;
		  }
		 else break;
		}
		if (barFrame >= (int)switchTex.size()) 
		{
			barFrame = (int)switchTex.size() - 1;
		}

		renderer->SetTexture(*switchTex[barFrame]);
		return;
		}
		if (barKey == "armor_bar")
		{
			 int armor = std::round(stats->GetArmor());
             armorText.setString(std::to_string(armor));
			 auto pos = transform->GetWorldPosition();  
             armorText.setPosition(pos.x, pos.y);
			
		
			
			
            return;
		}
		
    }


	

	void HUDUpdaterComponent::Render()
	{
		 if (barKey == "armor_bar") 
		 {
		 
        auto& window = RenderSystem::Instance()->GetMainWindow();
        window.draw(armorText);
        }
	}








}

