#pragma once
#include <SFML/Graphics.hpp>
#include "framework/TimerManager.hpp"
#include "gameplay/GameStage.hpp"
namespace ly
{
	class UFOStage : public GameStage
	{
	public:
		UFOStage(World* world);
		virtual void StartStage() override;
	private:
		virtual void StageFinished() override;
		sf::Vector2f GetRandomSpawnLoc() const;
		void SpawnUFO();

		float mSpawnInterval;
		int mSpawnAmt;
		int mCurrentSpawnAmt;
		float mUFOSpeed;
		
		TimerHandle mSpawnTimer;
	};
}