
#include "Gamemodes/TLBGamemodeBase.h"
#include "Player/TLBPlayerPawn.h"

ATLBGamemodeBase::ATLBGamemodeBase()
{
	// Make TLBPlayer be default pawn for this gamemode
	DefaultPawnClass = ATLBPlayerPawn::StaticClass();
	
	
}
