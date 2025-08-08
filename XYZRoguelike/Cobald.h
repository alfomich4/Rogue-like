#pragma once

#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "GameObject.h"
#include "Vector.h"
class Cobald
{
public:
	Cobald(const XYZEngine::Vector2Df& position);
	XYZEngine::GameObject* GetGameObject();
private:
	XYZEngine::GameObject* gameObject;
};

