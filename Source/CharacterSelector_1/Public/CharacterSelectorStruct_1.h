#pragma once

// core
#include "Internationalization/Text.h" // FText

// CoreUObject
#include "Templates/SubclassOf.h" // TSubclassOf

// engine
#include "GameFramework/Character.h" // ACharacter

//
#include "CharacterSelectorStruct_1.generated.h"

USTRUCT()
// cần một struct để tạo danh sách chứa nhân vật và các thông tin tương ứng
struct CHARACTERSELECTOR_1_API FCharacterSelectorStruct_1
{
	GENERATED_BODY()

public:
	// set value trong detail panel trong level editor
	UPROPERTY(EditAnywhere)
		// cần lưu tên nút để gửi sang widget
		FText ButtonName;

	// set value trong detail panel trong level editor
	UPROPERTY(EditAnywhere)
		// cần biến để chứa nhân vật được chọn
		TSubclassOf<ACharacter> ChooseACharacterClass;
};