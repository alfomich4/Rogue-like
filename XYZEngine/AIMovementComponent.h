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
        bool IsChasing() const { return chase; }
        void SetTarget(GameObject* target);
       

    protected:
        TransformComponent* transform = nullptr;
        GameObject* objectTarget = nullptr;
        SpriteRendererComponent* spriteRenderer = nullptr; 
       
        float speed = 0;
        float viewingRadius = 300.f;
        bool chase = true;
        Vector2Df previousPosition = { 0, 0 };
        Vector2Df acceleration = { 0, 0 };
    };
}