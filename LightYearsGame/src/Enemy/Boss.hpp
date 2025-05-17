#pragma once

#include "Enemy/EnemySpaceship.hpp"
#include "weapon/BulletShooter.hpp"
#include "weapon/ThreeWayShooter.hpp"
#include "weapon/FrontalWiper.hpp"

namespace ly
{
	class Boss : public EnemySpaceship
	{
	public:
		Boss(World* world);
		virtual void Tick(float deltaTime) override;
		virtual void BeginPlay() override;
	private:
		float mSpeed;
		float mBaseSpeed;
		float mSwitchDistanceToEdge;
		void CheckMove();

		BulletShooter mBaseShooterLeft;
		BulletShooter mBaseShooterRight;

		ThreeWayShooter mThreeWayShooter;
		FrontalWiper mFrontalWiperLeft;
		FrontalWiper mFrontalWiperRight;

		BulletShooter mFinalStageShooterLeft;
		BulletShooter mFinalStageShooterRight;

		void ShootBaseShooters();
		void ShootThreeWayShooter();
		void ShootFrotnalWipers();
		void HealthChanged(float amt, float currentHealth, float maxHealth);

		void SetStage(int newStage);
		int mStage;
	};
}
