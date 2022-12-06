// CharacterSelector_1
#include "CharacterSelectorButton_1.h" // UCharacterSelectorButton_1
#include "CharacterSelectorWidget_1.h" // UCharacterSelectorWidget_1
#include "CharacterSelectorInstance_1.h" // UCharacterSelectorInstance_1

// core
#include "Templates/UnrealTemplate.h" // MoveTemp

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr

// engine
#include "Kismet/GameplayStatics.h" // UGameplayStatics

// đổi nhân vật, dùng với event on hovered của nút
void UCharacterSelectorButton_1::UCharacterSelectorButton_1::ChangeCharacter() noexcept
{
	// SelectorActor đã có giá trị trước event contruct (từ trước AddToViewport, set từ UCharacterSelectorWidget_1)
	// hàm này có sẵn lệnh kiểm tra xem có cần đổi nhân vật hay không
	UCharacterSelectorWidget_1::SelectorActor->ChangeCharacter(CharacterIndex);
}

// chọn nhân vật, dùng với event on clicked của nút
void UCharacterSelectorButton_1::SelectCharacter() noexcept
{
	// nếu game instance là UCharacterSelectorGameInstance_1 và ChooseACharacterClass có giá trị
	if (CharacterData.ChooseACharacterClass->IsValidLowLevel())
	{
		// thử lấy UCharacterSelectorInstance_1
		const TObjectPtr<UCharacterSelectorInstance_1>& CharacterSelectorInstance{ GetGameInstance<UCharacterSelectorInstance_1>() };

		// nếu game instance là UCharacterSelectorInstance_1
		if (CharacterSelectorInstance->IsValidLowLevel())
		{
			// lưu class nhân vật được chọn vào UCharacterSelectorInstance_1
			CharacterSelectorInstance->SelectedCharacterClass = MoveTemp(CharacterData.ChooseACharacterClass);
		}

		// kiểm tra LevelToOpen (TSoftObjectPtr) không bao giờ null
		// IsValidLowLevel luôn trả về 0 trong trường hợp này, dùng !IsNull
		if (!UCharacterSelectorWidget_1::SelectorActor->LevelToOpen.IsNull())
		{
			// mở level được chọn sau khi chọn nhân vật
			UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), MoveTemp(UCharacterSelectorWidget_1::SelectorActor->LevelToOpen));
		}
	}
}

// event construct
void UCharacterSelectorButton_1::NativeConstruct()
{
	Super::NativeConstruct();

	// lưu struct dữ liệu nhân vật
	CharacterData = UCharacterSelectorWidget_1::SelectorActor->GetCharacterData(CharacterIndex);

	// đổi tên nút theo struct dữ liệu nhân vật
	text->SetText(MoveTemp(CharacterData.ButtonName));

	// gọi ChangeCharacter khi rê chuột vào nút
	button->OnHovered.AddDynamic(this, &UCharacterSelectorButton_1::ChangeCharacter);

	// gọi SelectCharacter khi nhấn nút
	button->OnClicked.AddDynamic(this, &UCharacterSelectorButton_1::SelectCharacter);
}