#pragma once

#include "CoreMinimal.h"
//#include "Serialization/JsonReader.h"
//#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
//#include"FParseJson.generated.h"



//UCLASS()
class BONECONTROLLIVELINK_API FParseJson{
	//GENERATED_BODY()
public:
	FParseJson(TSharedPtr<FJsonObject>JsonObject);
	~FParseJson();
	void ParseBone();
	TMap<FName, FTransform> getBonesTransform() { return bonesTransform; }
	void setIsMetahumans(bool _isMetahumans);

private:

	TSharedPtr<FJsonObject>Frames;
	TSharedPtr<FJsonObject>Bones;
	bool isRotation = false;
	int boneIndex = 0;
	bool isMetahumans = false;
	TMap<FName, FTransform>bonesTransform;

};