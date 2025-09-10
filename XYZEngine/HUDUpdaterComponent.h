#pragma once
#include"GameObject.h"
#include "ResourceSystem.h"
#include "SpriteRendererComponent.h"
#include "StatsComponent.h"
#include "RenderSystem.h"
namespace XYZEngine
{
	class HUDUpdaterComponent : public Component
	{
 public:
		HUDUpdaterComponent(GameObject* gameObject);
        void Initialize();
        void Render() override;
		void Update(float deltatime) override;
		void SetTargetStats(StatsComponent* s) { stats = s; }

 private:
	     std::vector<const sf::Texture*> switchTex;
		 SpriteRendererComponent* renderer = nullptr;
         GameObject* object = nullptr;
         StatsComponent* stats = nullptr;
		 std::vector<float> cuts{90,80,70,60,50,40,30,20,10,0};
		 std::string barKey;
		 int barFrame=0;
		 sf::Font uiFont;
         sf::Text armorText;
		 TransformComponent* transform = nullptr;
		 
	};
}


