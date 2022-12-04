#pragma once

// CoreUObject
#include "UObject/UObjectGlobals.h" // FObjectInitializer

// engine
#include "GameFramework/PlayerController.h" // APlayerController

//
#include "CharacterSelectorController_1.generated.h"

UCLASS()
// controller hiện chuột
class CHARACTERSELECTOR_1_API ACharacterSelectorController_1 : public APlayerController
{
	GENERATED_BODY()

public:
	// parent alias
	using Super = APlayerController;

	// constructor
	ACharacterSelectorController_1(const FObjectInitializer& ObjectInitializer);
};