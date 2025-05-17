#include "gameFramework/GameApplication.hpp"
#include "Level/GameLevelOne.hpp"
#include "Level/MainMenuLevel.hpp"
#include "framework/AssetManager.hpp"
#include "config.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{600, 980, "Light Years" , sf::Style::Titlebar | sf::Style::Close }
	{
		AssetManager::Get().SetAssetRootDirectory(GetResourceDir());
		weak<MainMenuLevel> newWorld = LoadWorld<MainMenuLevel>();
	}
}

