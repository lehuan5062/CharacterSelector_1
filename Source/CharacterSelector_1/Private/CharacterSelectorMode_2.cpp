// CharacterSelector_1
#include "CharacterSelectorMode_2.h" // ACharacterSelectorMode_2
#include "CharacterSelectorInstance_1.h" // UCharacterSelectorInstance_1
#include "CharacterSelectorAlias_1.h" // CharacterClass_t

// CoreUObject
#include "Templates/SubclassOf.h" // TSubclassOf

// lấy game instance ở dạng UCharacterSelectorInstance_1
const UCharacterSelectorInstance_1* const ACharacterSelectorMode_2::GetCharacterSelectorInstance() const
{
	// thử lấy UCharacterSelectorInstance_1
	const TObjectPtr<const UCharacterSelectorInstance_1>& CharacterSelectorInstance{ GetGameInstance<UCharacterSelectorInstance_1>() };

	// nếu game instance là UCharacterSelectorInstance_1
	if (CharacterSelectorInstance->IsValidLowLevel())
	{
		// trả về game instance ở dạng UCharacterSelectorInstance_1
		return CharacterSelectorInstance;
	}
	
	// trả về một UCharacterSelectorInstance_1 trống
	return TObjectPtr<const UCharacterSelectorInstance_1>{};
}

// thay đổi DefaultPawnClass
void ACharacterSelectorMode_2::SetDefaultPawnClass(const TSubclassOf<ACharacter>& ToDefaultPawnClass) noexcept
{
	// nếu ToDefaultPawnClass valid
	if (ToDefaultPawnClass->IsValidLowLevel())
	{
		// thay đổi DefaultPawnClass
		DefaultPawnClass = ToDefaultPawnClass;
	}
}