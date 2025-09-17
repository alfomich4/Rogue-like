#include "HealthBar.h"
#include "GameWorld.h"
#include "Player.h"
#include "HUDUpdaterComponent.h"

namespace XYZRoguelike
{
HealthBar::HealthBar(const XYZEngine::Vector2Df &position)
{
    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Health_bar");
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(position);

    auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("health_bar", 0));
    renderer->SetPixelSize(250, 200);
    if (auto *player = XYZEngine::GameWorld::Instance()->FindObjectByName("Player"))
    {
        auto *playerT = player->GetComponent<XYZEngine::TransformComponent>();
        playerHP = player->GetComponent<XYZEngine::StatsComponent>();
        transform->SetParent(playerT);
        transform->SetLocalPosition({-525.f, 295.f});
    }

    auto change = gameObject->AddComponent<XYZEngine::HUDUpdaterComponent>();
    change->Initialize();
    change->SetTargetStats(playerHP);
}

} // namespace XYZRoguelike
