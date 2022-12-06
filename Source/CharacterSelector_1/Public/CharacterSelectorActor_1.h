#pragma once

// CharacterSelector_1
#include "CharacterSelectorStruct_1.h" // FCharacterSelectorStruct_1
#include "CharacterSelectorAlias_1.h" // CharacterIndex_t

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr
#include "Containers/Array.h" // TArray
#include "Templates/SubclassOf.h" // TSubclassOf
#include "UObject/SoftObjectPtr.h" // TSoftObjectPtr

// engine
#include "GameFramework/Actor.h" // AActor
#include "Components/ChildActorComponent.h" // UChildActorComponent
#include "Engine/World.h" // UWorld

//
#include "CharacterSelectorActor_1.generated.h"

class UCharacterSelectorWidget_1;

UCLASS()
// thả actor này vào level, actor sẽ hiện menu và spawn nhân vật để chọn
class CHARACTERSELECTOR_1_API ACharacterSelectorActor_1 : public AActor // #include "GameFramework/Actor.h"
{
	GENERATED_BODY()

private:
	// cần child actor để chứa nhân vật được chọn
	// nằm trước constructor
	const TObjectPtr<UChildActorComponent> CharacterToSpawn;

protected:
	// parent alias
	using Super = AActor;

	// construction script
	virtual void OnConstruction(const FTransform& Transform) override;

	// event begin play
	virtual void BeginPlay() override;

public:
	// set value trong detail panel trong level editor
	UPROPERTY(EditAnywhere, Category = CharacterSelector)
		// cần một danh sách chứa nhân vật và các thông tin tương ứng, như tên nút chẳng hạn
		TArray<FCharacterSelectorStruct_1> ListOfCharacters;

	// set value trong detail panel trong level editor
	UPROPERTY(EditAnywhere, Category = CharacterSelector)
		// widget để chọn nhân vật
		TSubclassOf<UCharacterSelectorWidget_1> SelectorWidgetClass;

	// set trong editor
	UPROPERTY(EditAnywhere, Category = CharacterSelector)
		// level để mở sau khi nhấn nút
		// sẽ move sang CharacterSelectorButton_1 khi bấm chọn nhân vật
		TSoftObjectPtr<UWorld> LevelToOpen;

	// constructor
	ACharacterSelectorActor_1();

	// struct từ ListOfCharacters sẽ được lấy từ nhiều nơi (gồm widget nút), cần một hàm
	// trả copy vì dữ liệu gửi qua level khác được mở sau đó
	const FCharacterSelectorStruct_1 GetCharacterData(const CharacterIndex_t& index) const noexcept;

	// cần một hàm để chuyển nhân vật
	void ChangeCharacter(const CharacterIndex_t index) noexcept;
};