#include "pch.h"
#include "SpriteMovementAnimationComponent.h"
#include "AttackComponent.h"
#include "GameWorld.h"
#include "AudioSFX.h"

XYZEngine::SpriteMovementAnimationComponent::SpriteMovementAnimationComponent(GameObject *gameObject) : Component(gameObject)
{
    movement = gameObject->GetComponent<MovementComponent>();
    renderer = gameObject->GetComponent<SpriteRendererComponent>();
    input = gameObject->GetComponent<InputComponent>();
    stats = gameObject->GetComponent<StatsComponent>();

    if (movement == nullptr)
    {
        std::cout << "Need movement component for movement animation" << std::endl;
        gameObject->RemoveComponent(this);
    }
    else if (renderer == nullptr)
    {
        std::cout << "Need renderer component for movement animation" << std::endl;
        gameObject->RemoveComponent(this);
    }
    else if (input == nullptr)
    {
        std::cout << "Need input component for movement animation" << std::endl;
        gameObject->RemoveComponent(this);
    }
    else if (stats == nullptr)
    {
        std::cout << "Need stats component for movement animation" << std::endl;
        gameObject->RemoveComponent(this);
    }
}

void XYZEngine::SpriteMovementAnimationComponent::Initialize(float newFramerate, float FramerateAttack)
{

    for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_walking"); i++)
    {
        playerWalkTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_walking", i));
    }

    for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_idle"); i++)
    {
        playerIdleTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_idle", i));
    }

    for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_attack"); i++)
    {
        playerAttackTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_attack", i));
    }

    for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_hurt"); i++)
    {
        playerHurtTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_hurt", i));
    }

    for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_dying"); i++)
    {
        playerDeathTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_dying", i));
    }

    secondsForFrame = 1.f / newFramerate;
    secondsForFrameAttack = 1.f / FramerateAttack;
}

void XYZEngine::SpriteMovementAnimationComponent::Update(float deltaTime)
{
    const bool isHurt = stats->IsHurt();

    if (stats->IsDead())
    {
        if (playerDeathTex.empty())
        {
            return;
        }

        const int last = static_cast<int>(playerDeathTex.size()) - 1;

        if (deathFrame > last)
        {
            deathFrame = last;
        }

        renderer->SetTexture(*playerDeathTex[deathFrame]);

        counter += deltaTime;
        if (counter > secondsForFrame && deathFrame < last)
        {
            counter = 0.f;
            ++deathFrame;
            if (deathFrame > last)
            {
                deathFrame = last;
            }
        }
        if (deathFrame >= last)
        {
            GameWorld::Instance()->SetGameOver(true);
        }

        return;
    }

    if (input->IsMousePressed() && !isAttacking)
    {
        auto tmp = std::make_unique<AudioSFX>("PlayerAttack");
        if (playerAttackTex.empty())
        {
            return;
        }

        isAttacking = true;
        renderer->SetTexture(*playerAttackTex[0]);
    }

    if (isAttacking && !stats->IsHurt())
    {

        renderer->SetTexture(*playerAttackTex[attackFrame]);
        counter += deltaTime;
        if (counter > secondsForFrameAttack)
        {
            counter = 0;
            attackFrame++;
            if (attackFrame == playerAttackTex.size())
            {
                isAttacking = false;
                attackFrame = 0;
                didHitThisSwing = false;
            }
        }
        if (!didHitThisSwing && attackFrame == attackHitFrame)
        {
            auto *selfT = gameObject->GetComponent<TransformComponent>();
            if (!selfT)
            { 
                return;
            }
            const auto selfPos = selfT->GetWorldPosition();
            auto *enemy = XYZEngine::GameWorld::Instance()->FindClosestByName("Cobald", selfPos, meleeAttackDistance);
            if (enemy)
            {
                if (auto *atk = gameObject->GetComponent<AttackComponent>())
                {
                    atk->Attack(enemy);
                }
                didHitThisSwing = true;
            }
            return;
            /* auto *enemy = XYZEngine::GameWorld::Instance()->FindObjectByName("Cobald");*/

            /*if (enemy)
            {
                auto *selfT = gameObject->GetComponent<TransformComponent>();
                auto *enemyT = enemy->GetComponent<TransformComponent>();

                if (selfT && enemyT)
                {
                    float dist = selfT->GetWorldPosition().CalculateDistance(enemyT->GetWorldPosition());
                    if (dist <= meleeAttackDistance)
                    {
                        if (auto *atk = gameObject->GetComponent<AttackComponent>())
                        {
                            atk->Attack(enemy);
                        }
                    }
                }
            }
            didHitThisSwing = true;*/
        }
        return;
    }

    if (isHurt && !wasHurtLastFrame)
    {

        auto tmp = std::make_unique<XYZEngine::AudioSFX>("PlayerHurt");
    }

    wasHurtLastFrame = isHurt;

    if (stats->IsHurt())
    {

        if (playerHurtTex.empty())
        {
            return;
        }
        renderer->SetTexture(*playerHurtTex[hurtFrame]);
        counter += deltaTime;
        if (counter > secondsForFrame)
        {
            counter = 0;
            renderer->SetTexture(*playerIdleTex[idleFrame]);
            hurtFrame++;
            if (hurtFrame == playerHurtTex.size())
            {
                hurtFrame = 0;
            }
        }
        return;
    }
    if (movement->GetAccelerationSquared() == 0.f)
    {
        if (playerDeathTex.empty())
        {
            return;
        }

        renderer->SetTexture(*playerIdleTex[idleFrame]);
        counter += deltaTime;
        if (counter > secondsForFrame)
        {
            counter = 0;
            idleFrame++;
            if (idleFrame == playerIdleTex.size())
            {
                idleFrame = 0;
            }
        }

        return;
    }

    else

        counter += deltaTime;
    if (counter > secondsForFrame)
    {
        if (playerWalkTex.empty())
        {
            return;
        }

        renderer->SetTexture(*playerWalkTex[walkFrame]);
        counter = 0;
        walkFrame++;

        if (walkFrame == playerWalkTex.size())
        {
            walkFrame = 0;
        }
    }
}

void XYZEngine::SpriteMovementAnimationComponent::Render()
{
}
