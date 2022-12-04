#pragma once

#include "GameFramework/GameModeBase.h" // AGameModeBase

#include "CharacterSelectorMode_1.generated.h"

UCLASS()
// game mode này chạy trò chơi với con chuột được hiện
class CHARACTERSELECTOR_1_API ACharacterSelectorMode_1 : public AGameModeBase
{
	GENERATED_BODY()

public:
	// parent alias
	using Super = AGameModeBase;

	// constructor
	ACharacterSelectorMode_1(const FObjectInitializer& ObjectInitializer);
};