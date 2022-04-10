#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine.h"
#include "UObject/ObjectMacros.h"

class DataManager {

public:
	static DataManager* GetInstance();
	static void DeleteInstance();
	TMap<FName, FTransform>GetBonesMap();
	void SetBonesMap(const TMap<FName, FTransform>bonesMap);
	void setIsMetahumans(bool _isMetahumans);

private:
	DataManager();
	~DataManager();

private:
	static DataManager* Data_Instance;
	
	const DataManager &operator = (const DataManager &signal ) = delete;

	
private:
	static DataManager* m_DataManager;
	bool isMetahumans = false;
	TMap<FName, FTransform>bonesTransformMap;


};