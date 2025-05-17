#include "Level/MainMenuLevel.hpp"
#include "widgets/MainMenuHUD.hpp"
#include "framework/Application.hpp"
#include "Level/GameLevelOne.hpp"
#include "framework/BackdropActor.hpp"

namespace ly
{
	MainMenuLevel::MainMenuLevel(Application* owningApplication)
		: World{owningApplication}
	{
		mMainMenuHUD = SpawnHUD<MainMenuHUD>();
	}

	void MainMenuLevel::BeginPlay()
	{
		mMainMenuHUD.lock()->onStartButtonClicked.BindAction(GetWeakRef(), &MainMenuLevel::StartGame);
		mMainMenuHUD.lock()->onQuitButtonClicked.BindAction(GetWeakRef(), &MainMenuLevel::QuitGame);
		SpawnActor<BackdropActor>("SpaceShooterRedux/mainMenuBg.png", sf::Vector2f{0.f,0.f});
	}

	void MainMenuLevel::StartGame()
	{
		GetApplication()->LoadWorld<GameLevelOne>();
	}

	void MainMenuLevel::QuitGame()
	{
		GetApplication()->QuitApplication();
	}


}