#include "framework/TimerManager.hpp"
#include "gameplay/WaitStage.hpp"
namespace ly
{
	WaitStage::WaitStage(World* world, float waitDuration)
		: GameStage{world},
		mWaitDuration{waitDuration}
	{
	}
	void WaitStage::StartStage()
	{
		TimerManager::Get().SetTimer(GetWeakRef(), &WaitStage::FinishStage, mWaitDuration);
	}
}