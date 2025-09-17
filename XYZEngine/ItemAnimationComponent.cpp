#include "pch.h"
#include "ItemAnimationComponent.h"
#include "TransformComponent.h"
#include "GameWorld.h"

namespace XYZEngine
{
ItemAnimationComponent::ItemAnimationComponent(GameObject *gameObject) : Component(gameObject)
{
    renderer = gameObject->GetComponent<SpriteRendererComponent>();
    transform = gameObject->GetComponent<TransformComponent>();
    object = gameObject;
    stats = gameObject->GetComponent<StatsComponent>();

    if (renderer == nullptr)
    {
        std::cout << "Need SpriteRenderer component for Item Animation" << std::endl;
        gameObject->RemoveComponent(this);
    }
}
void ItemAnimationComponent::Initialize(float newFramerate)
{
    const auto &name = object->GetName();

    if (name == "health_pickup")
    {
        itemKey = "health_item";
    }
    else if (name == "armor")
    {
        itemKey = "armor_item";
    }

    itemFramesTex.clear();

    for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(itemKey); i++)
    {
        itemFramesTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(itemKey, i));
    }

    secondsForFrame = 1.f / newFramerate;
}

void ItemAnimationComponent::Update(float deltaTime)
{

    Vector2Df heartPosition = transform->GetWorldPosition();
    auto targetTransform = objectTarget->GetComponent<TransformComponent>();
    auto distanceFromTarget = heartPosition.CalculateDistance(targetTransform->GetWorldPosition());
    stats = objectTarget->GetComponent<StatsComponent>();
    if (distanceFromTarget < pickupDistance)
    {
        if (itemKey == "health_item")
        {

            stats->Heal(25.f);
            XYZEngine::GameWorld::Instance()->DestroyGameObject(gameObject);
        }
        else if (itemKey == "armor_item")
        {

            stats->AddArmor(25.f);
            XYZEngine::GameWorld::Instance()->DestroyGameObject(gameObject);
        }
    }

    renderer->SetTexture(*itemFramesTex[heartFrame]);

    counter += deltaTime;
    if (counter > secondsForFrame)
    {
        counter = 0;
        heartFrame++;
        if (heartFrame == itemFramesTex.size())
        {
            heartFrame = 0;
        }
    }
}

void ItemAnimationComponent::SetTarget(GameObject *target)
{
    if (gameObject)
    {
        objectTarget = target;
    }
}

} // namespace XYZEngine
