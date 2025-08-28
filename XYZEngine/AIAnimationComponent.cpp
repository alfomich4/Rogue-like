#include "pch.h"
#include "AIAnimationComponent.h"
#include "AttackComponent.h"

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
		
		
		if(AImove->GetDistanceFromTarget() <= meeleeAttackDistance )
		{
			
			
			renderer->SetTexture(*attackFramesTex[attackFrame]);
			attackCounter += deltaTime;
			if (attackCounter > secondsForFrameAttack)
			{
				attackCounter = 0;
				attackFrame++;
				if (attackFrame == attackFramesTex.size())
				{
					attackFrame = 0;
					didHitThisSwing = false;
					
				}
				
			}
			if (!didHitThisSwing && attackFrame == attackHitFrame)
			{
				
				auto target = AImove->GetTarget();
				
				auto atk = object->GetComponent<AttackComponent>();
					
				atk->Attack(target);    

				didHitThisSwing = true;
					
				
				
				
			}
			return;
		}
		
	
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


	void AIAnimationComponent::Initialize(float newFramerate,float FramerateAttack)
	{
		const auto& name = object->GetName();
		std::string idleKey, walkKey,attackKey,hurtKey;

		if (name == "Cobald") 
		{
			idleKey = "cobald_idle";
			walkKey = "cobald_walking";
			attackKey = "cobald_attacking";
			attackHitFrame = 3;
			
		}
		else if (name == "Demon") 
		{
			idleKey = "demon_idle";
			walkKey = "demon_walk";
			attackKey = "demon_attack";
			hurtKey = "demon_hurt";

		}
		else if (name == "Medusa")
		{
			idleKey = "medusa_idle";
			walkKey = "medusa_walk";
			attackKey = "medusa_attack";
			hurtKey = "medusa_hurt";
			attackHitFrame = 8;

		}

		idleFramesTex.clear(); walkFramesTex.clear(); attackFramesTex.clear();

		for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(idleKey); i++)
		{
			idleFramesTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(idleKey, i));
		}

		for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(walkKey); i++)
		{
			walkFramesTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(walkKey, i));
		}

		for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(attackKey); i++)
		{
			attackFramesTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(attackKey, i));
		}

		





	    



		secondsForFrame = 1.f / newFramerate;
		secondsForFrameAttack = 1.f / FramerateAttack;
	}
}

