#pragma once

// engine
#include "Engine/GameInstance.h" // UGameInstance
#include "GameFramework/Character.h" // ACharacter

// CoreUObject
#include "Templates/SubclassOf.h" // TSubclassOf

//
#include "CharacterSelectorInstance_1.generated.h"

UCLASS()
class CHARACTERSELECTOR_1_API UCharacterSelectorInstance_1 : public UGameInstance
{
	GENERATED_BODY()

public:
	// lấy trong blueprint thì không crash
	UPROPERTY(BlueprintReadOnly, Category = CharacterSelector)
		// lưu nhân vật được chọn
		// lưu từ UCharacterSelectorButton_1
		TSubclassOf<ACharacter> SelectedCharacterClass;
};