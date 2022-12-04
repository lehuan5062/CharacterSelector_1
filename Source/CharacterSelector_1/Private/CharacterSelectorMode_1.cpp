// CharacterSelector_1
#include "CharacterSelectorMode_1.h" // ACharacterSelectorMode_1
#include "CharacterSelectorController_1.h" // ACharacterSelectorController_1

// engine
#include "GameFramework/Pawn.h" // APawn

// constructor
ACharacterSelectorMode_1::ACharacterSelectorMode_1(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// dùng player controller hiện chuột
	PlayerControllerClass = ACharacterSelectorController_1::StaticClass();

	// chạy trò chơi với nhân vật vô hình
	DefaultPawnClass = APawn::StaticClass();
}