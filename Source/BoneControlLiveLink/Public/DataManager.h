#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine.h"
#include "UObject/ObjectMacros.h"


//#define daz_hips				FName("hips")
#define daz_spine				FName("spine")
#define daz_spine2				FName("spine2")
#define daz_head				FName("head")
#define daz_leftShoulder		FName("leftShoulder")
#define daz_leftArm				FName("leftArm")
#define daz_leftForeArm			FName("leftForeArm")
#define daz_leftHand			FName("leftHand")

#define daz_rightShoulder		FName("rightShoulder")
#define daz_rightArm			FName("rightArm")
#define daz_rightForeArm		FName("rightForeArm")
#define daz_rightHand			FName("rightHand")

#define daz_leftUpLeg			FName("leftUpLeg")
#define daz_leftLeg				FName("leftLeg")
#define daz_leftFoot			FName("leftFoot")

#define daz_rightUpLeg			FName("rightUpLeg")
#define daz_rightLeg			FName("rightLeg")
#define daz_rightFoot			FName("rightFoot")


enum bones {
	MetaHumans = 0,
	mannequin =1,
	daz = 2,
};

class DataManager {

public:
	static DataManager* GetInstance();
	static void DeleteInstance();
	TMap<FName, FTransform>GetBonesMap();
	void SetBonesMap(const TMap<FName, FTransform>bonesMap);
	void setIsMetahumans(bool _isMetahumans);
	
	bool getIsMetahumans();
	void setBoneSelected(int boneType);
	void buildDAZMap();
	const int boneNum =17;
	void buildBoneTypeMap(const int boneType);
	TMap<FName, FName> getBoneTypeName();
private:
	DataManager();
	~DataManager();

private:
	static DataManager* Data_Instance;
	
	const DataManager &operator = (const DataManager &signal ) = delete;

	
private:
	int boneSelected;
	static DataManager* m_DataManager;
	bool isMetahumans = false;
	TMap<FName, FTransform>bonesTransformMap;
	TMap<FName, FName>DazMap;
	TMap<FName, FName>boneTypeMap;

};
