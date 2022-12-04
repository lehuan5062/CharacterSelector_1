// CharacterSelector_1
#include "CharacterSelectorWidget_1.h" // UCharacterSelectorWidget_1
#include "CharacterSelectorStruct_1.h" // FCharacterSelectorStruct_1
#include "CharacterSelectorButton_1.h" // UCharacterSelectorButton_1

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr

// event construct
void UCharacterSelectorWidget_1::NativeConstruct()
{
	Super::NativeConstruct();

	// kiểm tra danh sách có ít nhất 1 thành viên và SelectorButtonClass đã được cho giá trị từ editor
	if (SelectorActor->ListOfCharacters.IsValidIndex(0) && SelectorButtonClass->IsValidLowLevel())
	{
		// index loop tạo nút
		uint8 index{};

		// tạo nút dựa trên số nhân vật và gửi con trỏ ACharacterSelectorActor_1 đến các nút
		for (FCharacterSelectorStruct_1 ButtonData : SelectorActor->ListOfCharacters)
		{
			// tạo biến chứa UCharacterSelectorWidget_1
			const TObjectPtr<UCharacterSelectorButton_1> SelectorButton{
				CreateWidget<UCharacterSelectorButton_1>(GetWorld(), SelectorButtonClass) };

			// gán index nhân vật trong danh sách cho nút
			SelectorButton->CharacterIndex = index;

			// thêm nút vào hộp, đã lên hình
			ButtonBox->AddChildToVerticalBox(SelectorButton);

			// chuyển đến nút tiếp theo
			index++;
		}
	}
}