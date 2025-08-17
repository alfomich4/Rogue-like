#include "pch.h"
#include "AIAnimationComponent.h"

namespace XYZEngine
{


	AIAnimationComponent::AIAnimationComponent(GameObject* gameObject) :Component(gameObject)
	{
		AImove = gameObject->GetComponent<AIMovementComponent>();
		renderer = gameObject->GetComponent<SpriteRendererComponent>();
		object = gameObject;
		
		if (AImove == nullptr)
		{
			std::cout << "Need AIMovement component for AI Animation" << std::endl;
			gameObject->RemoveComponent(this);
		}
		else if (renderer == nullptr)
		{
			std::cout << "Need SpriteRenderer component for AI Animation" << std::endl;
			gameObject->RemoveComponent(this);
		}

	}
	void AIAnimationComponent::Update(float deltaTime)
	{
	
		if (AImove->IsChasing() == true)
		{
			renderer->SetTexture(*walkFramesTex[walkFrame]);
			walkCounter += deltaTime;
			if (walkCounter > secondsForFrame)
			{
				walkCounter = 0;
				walkFrame++;
				if (walkFrame == walkFramesTex.size())
				{
					walkFrame = 0;
				}


			}
		}
		else
		{
			renderer->SetTexture(*idleFramesTex[idleFrame]);
			idleCounter += deltaTime;
			if (idleCounter > secondsForFrame)
			{
				idleCounter = 0;
				idleFrame++;
				if (idleFrame == idleFramesTex.size())
				{
					idleFrame = 0;
				}
			}


		
	}





	}

	void AIAnimationComponent::Render()
	{

	}


	void AIAnimationComponent::Initialize(float newFramerate)
	{
		const auto& name = object->GetName();
		std::string idleKey, walkKey;

		if (name == "Cobald") 
		{
			idleKey = "cobald_idle";
			walkKey = "cobald_walking";
		}
		else if (name == "Demon") 
		{
			idleKey = "demon_idle";
			walkKey = "demon_walk";
		}
		else if (name == "Medusa")
		{
			idleKey = "medusa_idle";
			walkKey = "medusa_walk";
		}

		idleFramesTex.clear(); walkFramesTex.clear();

		for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(idleKey); i++)
		{
			idleFramesTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(idleKey, i));
		}

		for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(walkKey); i++)
		{
			walkFramesTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(walkKey, i));
		}

	    



		secondsForFrame = 1.f / newFramerate;
	}
}

