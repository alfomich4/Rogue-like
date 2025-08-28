#include "pch.h"
#include "GameOverUi.h"
#include <cassert>
#include <cmath>

namespace XYZEngine
{
	void InitUI(GameOverUi& ui)
	{
		assert(ui.font.loadFromFile("Resources/Fonts/Roboto-Regular.ttf"));
		ui.gameOverText.setFont(ui.font);
		ui.gameOverText.setCharacterSize(68);
		ui.gameOverText.setStyle(sf::Text::Bold);
		ui.gameOverText.setFillColor(sf::Color::Red);
		ui.gameOverText.setString("GAME OVER");
		ui.gameOverText.setScale(1.f, -1.f);
		

	}
	void AttachTextToPlayer(GameOverUi& ui, GameObject* player)
	{
		if (!player)
		{
			ui.targetTransform = nullptr;
			ui.targetStats = nullptr;
			return;
		}
		ui.targetTransform = player->GetComponent<TransformComponent>();
		ui.targetStats = player->GetComponent<StatsComponent>();
	}
	void UpdateUI(GameOverUi& ui, float timeDelta)
	{
		const bool isGO = GameWorld::Instance()->IsGameOver();
		if (!isGO)
		{
			ui.timeSinceGameOver = 0.f;                 
			return;
		}
		ui.timeSinceGameOver += timeDelta;
		sf::Color gameOverTextColor = (int)ui.timeSinceGameOver % 2 ? sf::Color::Red : sf::Color::Yellow;
		ui.gameOverText.setFillColor(gameOverTextColor);

	}
	void DrawUI(GameOverUi& ui, sf::RenderWindow& window)
	{
		
		if (!ui.targetTransform || !ui.targetStats)
		{
			return;
		}
			

		
		if (!ui.targetStats->IsDead())
		{

			return;
		}
		const auto wp = ui.targetTransform->GetWorldPosition(); // Vector2Df {x,y}
		sf::Vector2f pos{ wp.x, wp.y };
		float offset = 100.f; 
		auto lb = ui.gameOverText.getLocalBounds();
		ui.gameOverText.setOrigin(lb.left + lb.width * 0.5f, lb.top + lb.height); 
		ui.gameOverText.setPosition(pos.x, pos.y + offset);

		window.draw(ui.gameOverText);
	
		

	}
	
}