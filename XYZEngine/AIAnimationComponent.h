#pragma once
#include "GameObject.h"
#include "ResourceSystem.h"
#include "AIMovementComponent.h"
namespace XYZEngine
{
	class AIAnimationComponent :public Component
	{   
	public:
		AIAnimationComponent(GameObject* gameObject);
		void Initialize(float newFramerate);
		void Update(float deltaTime) override;
		void Render() override;
		
	private:
		AIMovementComponent* AImove = nullptr;
		SpriteRendererComponent* renderer = nullptr;
		GameObject* object = nullptr;
		std::vector<const sf::Texture*> idleFramesTex;
		std::vector<const sf::Texture*> walkFramesTex;
		float secondsForFrame = 0.f;
		float walkCounter = 0.f;
		float idleCounter = 0.f;
		int walkFrame = 0;
		int idleFrame = 0;
		
	};
}


