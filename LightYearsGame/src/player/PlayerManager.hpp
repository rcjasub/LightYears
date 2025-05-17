#pragma once
#include "framework/Core.hpp"
#include "player/Player.hpp"
namespace ly
{
	class PlayerManager
	{
	public:
		Player& CreateNewPlayer();
		Player* GetPlayer(int playerIndex = 0);
		const Player* GetPlayer(int playerIndex = 0) const;
		static PlayerManager& Get();
		void Reset();
	protected:
		PlayerManager();
		
	private:
		List<Player> mPlayers;
		static unique<PlayerManager> playerManager;
	};
}