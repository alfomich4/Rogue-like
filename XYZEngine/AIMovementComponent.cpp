#include "pch.h"
#include "AIMovementComponent.h"
#include "TransformComponent.h"


namespace XYZEngine
{
    AIMovementComponent::AIMovementComponent(GameObject* gameObject)
        : Component(gameObject)
    {
        transform = gameObject->GetComponent<TransformComponent>();
		spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
    }


	void AIMovementComponent::Update(float deltaTime)
    {
        Vector2Df positionAI = transform->GetWorldPosition();
        auto targetTransform = objectTarget->GetComponent<TransformComponent>();
        float distanceFromTarget = positionAI.CalculateDistance(targetTransform->GetWorldPosition());

        if (distanceFromTarget > viewingRadius)
        {
			chase = false;
            return;
        }
		chase = true;
       
       Vector2Df direction = targetTransform->GetWorldPosition() - transform->GetWorldPosition();
       direction = direction.Normalize();
       transform->MoveBy(speed * deltaTime * Vector2Df{ direction.x, direction.y });
       if (direction.x > 0.9f)
       {
           spriteRenderer->FlipX(false);
       }
      
       else if (direction.x < -0.9f)
       {
           spriteRenderer->FlipX(true);
       } 
       
     
      
       
         
       
       
    }
   
    void AIMovementComponent::Render()
    {

    }

    void AIMovementComponent::SetSpeed(float newSpeed)
    {

        speed = newSpeed;
    }
    void AIMovementComponent::SetTarget(GameObject* target)
    {
        if (gameObject)
        {
            objectTarget = target;
          
        }
    }
}

