#pragma once

#include "CoreMinimal.h"
//#include "Serialization/JsonReader.h"
//#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
//#include"FParseJson.generated.h"
#include "ABoneControlAnimNode.h"


//UCLASS()
class  FParseJson{
	//GENERATED_BODY()
public:
	FParseJson(TSharedPtr<FJsonObject>JsonObject);
	~FParseJson();
	void ParseBone();
	TMap<FName, FTransform> getBonesTransform() { return bonesTransform; }

private:

	TSharedPtr<FJsonObject>Frames;
	TSharedPtr<FJsonObject>Bones;
	bool isRotation = false;
	int boneIndex = 0;
	TMap<FName, FTransform>bonesTransform;

};