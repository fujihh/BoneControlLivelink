#include"FParseJson.h"

#define LOCTEXT_NAMESPACE "ParseJosn"
FParseJson::FParseJson(TSharedPtr<FJsonObject> JsonObject) {
	Bones = JsonObject->GetObjectField("Bones");
	Frames = JsonObject->GetObjectField("Frames");
}
FParseJson::~FParseJson() {

}
void FParseJson::ParseBone() {
	
	FString boneName;
	FVector boneTranslation;
	FRotator boneRotation;
	FVector boneScale(1.0, 1.0, 1.0);
	FQuat boneQuat;
	for (TPair<FString, TSharedPtr<FJsonValue>>& Bone : Bones->Values) {
		TSharedPtr<FJsonObject> singalBoneObject = Bone.Value->AsObject();
		boneName = Bone.Key;
		const TArray<TSharedPtr<FJsonValue>>* RotationArray;
		const TArray<TSharedPtr<FJsonValue>>* LocationArray;

		if (singalBoneObject->TryGetArrayField(TEXT("Rotation"), RotationArray)){
			if (RotationArray->Num() == 3) {
				isRotation = true;
				double X = (*RotationArray)[0]->AsNumber();
				double Y = (*RotationArray)[1]->AsNumber();
				double Z = (*RotationArray)[2]->AsNumber();
				boneRotation = FRotator(X, Y, Z);
			}
			else if (RotationArray->Num() == 4) {
				double X = (*RotationArray)[0]->AsNumber();
				double Y = (*RotationArray)[1]->AsNumber();
				double Z = (*RotationArray)[2]->AsNumber();
				double W = (*RotationArray)[3]->AsNumber();
				boneQuat = FQuat(X, Y, Z, W);
				isRotation = false;
			}
		}
		if (singalBoneObject->TryGetArrayField(TEXT("Position"), LocationArray)) {
			double X = (*LocationArray)[0]->AsNumber();
			double Y = (*LocationArray)[1]->AsNumber();
			double Z = (*LocationArray)[2]->AsNumber();
			boneTranslation = FVector(X, Y, Z);
		}

		FTransform boneTransform = FTransform((isRotation ? boneRotation.Quaternion() : boneQuat), boneTranslation, boneScale);
		bonesTransform.Add(FName(boneName), boneTransform);

	}
}

#undef LOCTEXT_NAMESPACE