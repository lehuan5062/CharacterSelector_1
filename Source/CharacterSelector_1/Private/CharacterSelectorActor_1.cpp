// CharacterSelector_1
#include "CharacterSelectorActor_1.h" // ACharacterSelectorActor_1
#include "CharacterSelectorAlias_1.h" // CharacterClass_t
#include "CharacterSelectorWidget_1.h" // UCharacterSelectorWidget_1

// core
#include "Math/Vector.h" // FVector
#include "Templates/UnrealTemplate.h" // MoveTemp

// CoreUObject
#include "UObject/Object.h" // CreateDefaultSubobject
#include "Templates/SubclassOf.h" // TSubclassOf
#include "UObject/ObjectPtr.h" // TObjectPtr

// engine
#include "Components/ChildActorComponent.h" // UChildActorComponent
#include "Components/SceneComponent.h" // USceneComponent
#include "Components/CapsuleComponent.h" // GetScaledCapsuleHalfHeight
#include "Components/SkeletalMeshComponent.h" // USkeletalMeshComponent

// UMG
#include "Blueprint/UserWidget.h" // CreateWdiget

// constructor
ACharacterSelectorActor_1::ACharacterSelectorActor_1()
	: CharacterToSpawn{ CreateDefaultSubobject<UChildActorComponent>(TEXT("character_1")) }
{
	// tạo root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("root"));

	// gắn ChildActor vô root
	CharacterToSpawn->SetupAttachment(RootComponent);

#if UE_EDITOR

	// không cần chạy construction script liên tục khi kéo actor
	bRunConstructionScriptOnDrag = 0;

#endif
}

// struct từ ListOfCharacters sẽ được lấy tại nhiều nơi (gồm widget nút), cần một hàm
// trả copy vì dữ liệu gửi qua level khác được mở sau đó
const FCharacterSelectorStruct_1 ACharacterSelectorActor_1::GetCharacterData(const CharacterIndex_t& index) const noexcept
{
	// nếu danh sách có dữ liệu tại index
	if (ListOfCharacters.IsValidIndex(index))
	{
		// trả dữ liệu trong danh sách tại index
		return ListOfCharacters[index];
	}

	// trả FCharacterSelectorStruct_1 trống nếu không có dữ liệu
	return FCharacterSelectorStruct_1{};
}

// cần một hàm để chuyển nhân vật
void ACharacterSelectorActor_1::ChangeCharacter(const CharacterIndex_t index = 0) noexcept
{
	// class nhân vật sẽ dùng tới nhiều, cần lưu vào biến nội bộ
	const TSubclassOf<CharacterClass_t>&& CharacterClass{ GetCharacterData(index).ChooseACharacterClass };

	// nếu CharacterClass chưa được chọn từ editor hoặc giống class nhân vật hiện tại thì không cần đổi
	if (CharacterClass->IsValidLowLevel() && CharacterClass != CharacterToSpawn->GetChildActorClass())
	{
		// đổi sang class được chọn
		CharacterToSpawn->SetChildActorClass(CharacterClass);

		// thử lấy child actor ở dạng CharacterClass_t (ACharacter)
		const TObjectPtr<CharacterClass_t>& CharacterActor{ Cast<CharacterClass_t>(CharacterToSpawn->GetChildActor()) };

		// nếu ChildActor là một CharacterClass_t
		if (CharacterActor->IsValidLowLevel())
		{
			// dời nhân vật lên một nửa cái capsule
			CharacterToSpawn->SetRelativeLocation
			(FVector{ 0, 0, CharacterActor->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() });
		}
	}
}

// construction script
void ACharacterSelectorActor_1::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// hiện nhân vật đầu danh sách khi bắt đầu chơi, mặc định nhân vật 0
	ChangeCharacter();
}

// event begin play
void ACharacterSelectorActor_1::BeginPlay()
{
	Super::BeginPlay();

	// hiện widget chọn nhân vật nếu có class được chọn
	if (SelectorWidgetClass->IsValidLowLevel())
	{
		// tạo biến chứa UCharacterSelectorWidget_1
		const TObjectPtr<UCharacterSelectorWidget_1> SelectorWidget
		{
			CreateWidget<UCharacterSelectorWidget_1>(GetWorld(), MoveTemp(SelectorWidgetClass))
		};

		// gửi self reference đến UCharacterSelectorWidget_1 để gửi đến nút
		UCharacterSelectorWidget_1::SelectorActor = this;

		// thêm vào viewport
		SelectorWidget->AddToViewport();
	}
}