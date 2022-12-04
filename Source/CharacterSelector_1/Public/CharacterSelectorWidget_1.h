#pragma once

// CharacterSelector_1
#include "CharacterSelectorActor_1.h" // ACharacterSelectorActor_1
#include "CharacterSelectorButton_1.h" // UCharacterSelectorButton_1

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr
#include "Templates/SubclassOf.h" // TSubclassOf

// UMG
#include "Blueprint/UserWidget.h" // UUserWidget
#include "Components/VerticalBox.h" // UVerticalBox

//
#include "CharacterSelectorWidget_1.generated.h"

UCLASS(Abstract)
// widget để chọn nhân vật
class CHARACTERSELECTOR_1_API UCharacterSelectorWidget_1 : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UVerticalBox> ButtonBox;

	// chỉnh trong editor
	UPROPERTY(EditAnywhere, Category = CharacterSelector)
		// widget để chọn nhân vật
		TSubclassOf<UCharacterSelectorButton_1> SelectorButtonClass;

	// parent alias
	using Super = UUserWidget;

	// event construct
	virtual void NativeConstruct() override;

public:
	// chứa ACharacterSelectorActor_1 để lấy danh sách nhân vật được chọn và gửi con trỏ tới widget button
	// set từ chính ACharacterSelectorActor_1
	static inline TObjectPtr<ACharacterSelectorActor_1> SelectorActor;
};