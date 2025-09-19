#pragma once
#include "Component.h"
#include "GameWorld.h"
#include "AudioComponent.h"


namespace XYZEngine
{
	class DestroyStopAudio : public Component
	{
	public:
		DestroyStopAudio(GameObject *gameObject);
		
		void Update(float deltaTime) override;
        void Render() override;
	private:
       
	};
}


