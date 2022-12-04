#pragma once

// CharacterSelector_1
#include "CharacterSelectorMode_1.h" // ACharacterSelectorMode_1
#include "CharacterSelectorInstance_1.h" // UCharacterSelectorInstance_1

// CoreUObject
#include "Templates/SubclassOf.h" // TSubclassOf

// engine
#include "GameFramework/Character.h" // ACharacter

//
#include "CharacterSelectorMode_2.generated.h"

UCLASS(Abstract)
// game mode này chạy trò chơi với nhân vật được chọn
class CHARACTERSELECTOR_1_API ACharacterSelectorMode_2 : public ACharacterSelectorMode_1
{
	GENERATED_BODY()

protected:
	// parent alias
	using Super = ACharacterSelectorMode_1;

	// lấy biến của game instance trong blueprint thì không crash
	UFUNCTION(BlueprintPure, Category = CharacterSelector)
		// lấy game instance ở dạng UCharacterSelectorInstance_1
		const UCharacterSelectorInstance_1* const GetCharacterSelectorInstance() const;

	// lấy SelectedCharacterClass từ GetCharacterSelectorInstance() rồi nhét vô hàm này
	UFUNCTION(BlueprintCallable, Category = CharacterSelector)
		// thay đổi DefaultPawnClass
		void SetDefaultPawnClass(UPARAM(ref) const TSubclassOf<ACharacter>& ToDefaultPawnClass) noexcept;
};