#include "pch.h"
#include "DestroyStopAudio.h"
namespace XYZEngine
{
	DestroyStopAudio::DestroyStopAudio(GameObject* gameObject): Component(gameObject)
	{
       
	}
	void DestroyStopAudio::Update(float deltaTime)
	{
		 auto a = GetGameObject()->GetComponent<XYZEngine::AudioComponent>();
		if (a && !a->IsPlaying())
		{ 
			 XYZEngine::GameWorld::Instance()->DestroyGameObject(GetGameObject());
		}
		
	}
	void DestroyStopAudio::Render()
	{
	}
}

