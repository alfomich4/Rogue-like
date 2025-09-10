#pragma once
#include "GameObject.h"
#include "SpriteRendererComponent.h" 

namespace XYZEngine
{
    class AIMovementComponent : public Component 
    {
    public:
        AIMovementComponent(GameObject* gameObject);

        void Update(float deltaTime) override;
        void Render() override;
       void SetSpeed(float newSpeed);
        float GetSpeed() const;
        float GetAccelerationSquared() const;
		float GetDistanceFromTarget() const { return distanceFromTarget; }
        bool IsChasing() const { return chase; }
        void SetTarget(GameObject* target);
        GameObject* GetTarget() const { return objectTarget; }
       

    protected:
        TransformComponent* transform = nullptr;
        GameObject* objectTarget = nullptr;
        SpriteRendererComponent* spriteRenderer = nullptr; 
        float distanceFromTarget=0;
        float speed = 0;
        float viewingRadius = 300.f;
		float meeleeAttackDistance = 55.f;
        bool chase = true;
       
    };
}