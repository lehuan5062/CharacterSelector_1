#pragma once

// CharacterSelector_1
#include "CharacterSelectorAlias_1.h" // CharacterIndex_t
#include "CharacterSelectorStruct_1.h" // FCharacterSelectorStruct_1

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr

// UMG
#include "Blueprint/UserWidget.h" // UUserWidget
#include "Components/Button.h" // UButton
#include "Components/TextBlock.h" // UTextBlock

//
#include "CharacterSelectorButton_1.generated.h"

UCLASS(Abstract)
// nút để chọn nhân vật
class CHARACTERSELECTOR_1_API UCharacterSelectorButton_1 : public UUserWidget
{
	GENERATED_BODY()

private:
	// struct dữ liệu nhân vật dùng lại nhiều, cần lưu một biến
	// nhận value trong SetButtonName
	FCharacterSelectorStruct_1 CharacterData;

	// bind nút
	UFUNCTION()
		// đổi nhân vật
		void ChangeCharacter() noexcept;

	// bind nút
	UFUNCTION()
		// chọn nhân vật
		void SelectCharacter() noexcept;

protected:
	// bind trong blueprint
	UPROPERTY(meta = (BindWidget))
		// tên nút
		TObjectPtr<UButton> button;

	// bind trong blueprint
	UPROPERTY(meta = (BindWidget))
		// tên nút
		TObjectPtr<UTextBlock> text;

	// parent alias
	using Super = UUserWidget;

	// event construct
	virtual void NativeConstruct() override;

public:
	// index để chọn nhân vật tương ứng trong danh danh sách
	// nhận từ UCharaterSelectorWidget_1
	CharacterIndex_t CharacterIndex;
};