#include "DataManager.h"

DataManager* DataManager::m_DataManager = nullptr;

DataManager* DataManager::GetInstance() {
	if (m_DataManager == nullptr) {
		m_DataManager = new DataManager();
	}
	return m_DataManager;
	
}
void DataManager::DeleteInstance() {
	if (m_DataManager) {
		delete m_DataManager;
		m_DataManager = nullptr;
	}

}

DataManager::DataManager() {
	this->buildBoneTypeMap(0);
}


DataManager::~DataManager() {

}

TMap<FName, FTransform> DataManager::GetBonesMap() {
	return bonesTransformMap;
}
void DataManager::SetBonesMap(TMap<FName, FTransform>bonesMap) {
	bonesTransformMap = bonesMap;
}


void DataManager::setBoneSelected(const int boneType) {
	boneSelected = boneType;
	this->buildBoneTypeMap(boneType);
	
}
void DataManager::setIsMetahumans(bool _isMetahumans) {
	if (_isMetahumans) {
		isMetahumans = true;
	}
	else {
		isMetahumans = false;
	}
}

bool DataManager::getIsMetahumans() {
	return isMetahumans;
}

void DataManager::buildBoneTypeMap(int boneType) {
	switch (boneType) {
	case 2:
	{
		boneTypeMap.Add(FName("spine_01"), daz_spine);
		boneTypeMap.Add(FName("spine_03"), daz_spine2);
		boneTypeMap.Add(FName("head"), daz_head);

		boneTypeMap.Add(FName("clavicle_l"), daz_leftShoulder);
		boneTypeMap.Add(FName("upperarm_l"), daz_leftArm);
		boneTypeMap.Add(FName("lowerarm_l"), daz_leftForeArm);
		boneTypeMap.Add(FName("hand_l"), daz_leftHand);

		boneTypeMap.Add(FName("clavicle_r"), daz_rightShoulder);
		boneTypeMap.Add(FName("upperarm_r"), daz_rightArm);
		boneTypeMap.Add(FName("lowerarm_r"), daz_rightForeArm);
		boneTypeMap.Add(FName("hand_r"), daz_rightHand);

		boneTypeMap.Add(FName("thigh_l"), daz_leftUpLeg);
		boneTypeMap.Add(FName("calf_l"), daz_leftLeg);
		boneTypeMap.Add(FName("foot_l"), daz_leftFoot);

		boneTypeMap.Add(FName("thigh_r"), daz_rightUpLeg);
		boneTypeMap.Add(FName("calf_r"), daz_rightLeg);
		boneTypeMap.Add(FName("foot_r"), daz_rightFoot);
	};
	break;
	case 1:
	{
		boneTypeMap.Add(FName("spine_01"), FName("spine_01"));
		boneTypeMap.Add(FName("spine_03"), FName("spine_05"));
		boneTypeMap.Add(FName("head"), FName("head"));

		boneTypeMap.Add(FName("clavicle_l"), FName("clavicle_l"));
		boneTypeMap.Add(FName("upperarm_l"), FName("upperarm_l"));
		boneTypeMap.Add(FName("lowerarm_l"), FName("lowerarm_l"));
		boneTypeMap.Add(FName("hand_l"), FName("hand_l"));

		boneTypeMap.Add(FName("clavicle_r"), FName("clavicle_r"));
		boneTypeMap.Add(FName("upperarm_r"), FName("upperarm_r"));
		boneTypeMap.Add(FName("lowerarm_r"), FName("lowerarm_r"));
		boneTypeMap.Add(FName("hand_r"), FName("hand_r"));

		boneTypeMap.Add(FName("thigh_l"), FName("thigh_l"));
		boneTypeMap.Add(FName("calf_l"), FName("calf_l"));
		boneTypeMap.Add(FName("foot_l"), FName("foot_l"));

		boneTypeMap.Add(FName("thigh_r"), FName("thigh_r"));
		boneTypeMap.Add(FName("calf_r"), FName("calf_r"));
		boneTypeMap.Add(FName("foot_r"), FName("foot_r"));
	};
	break;
	case 0:
	{
		boneTypeMap.Add(FName("spine_01"), FName("spine_01"));
		boneTypeMap.Add(FName("spine_03"), FName("spine_03"));
		boneTypeMap.Add(FName("head"), FName("head"));

		boneTypeMap.Add(FName("clavicle_l"), FName("clavicle_l"));
		boneTypeMap.Add(FName("upperarm_l"), FName("upperarm_l"));
		boneTypeMap.Add(FName("lowerarm_l"), FName("lowerarm_l"));
		boneTypeMap.Add(FName("hand_l"), FName("hand_l"));

		boneTypeMap.Add(FName("clavicle_r"), FName("clavicle_r"));
		boneTypeMap.Add(FName("upperarm_r"), FName("upperarm_r"));
		boneTypeMap.Add(FName("lowerarm_r"), FName("lowerarm_r"));
		boneTypeMap.Add(FName("hand_r"), FName("hand_r"));

		boneTypeMap.Add(FName("thigh_l"), FName("thigh_l"));
		boneTypeMap.Add(FName("calf_l"), FName("calf_l"));
		boneTypeMap.Add(FName("foot_l"), FName("foot_l"));

		boneTypeMap.Add(FName("thigh_r"), FName("thigh_r"));
		boneTypeMap.Add(FName("calf_r"), FName("calf_r"));
		boneTypeMap.Add(FName("foot_r"), FName("foot_r"));
	};
	break;
	}
}

TMap<FName, FName> DataManager::getBoneTypeName() {
	return boneTypeMap;
}

void DataManager::buildDAZMap() {
	for (int i = 0; i < boneNum; i++) {
		DazMap.Add(FName("spine_01"), daz_spine);
		DazMap.Add(FName("spine_03"), daz_spine2);
		DazMap.Add(FName("head"), daz_head);

		DazMap.Add(FName("clavicle_l"), daz_leftShoulder);
		DazMap.Add(FName("upperarm_l"), daz_leftArm);
		DazMap.Add(FName("lowerarm_l"), daz_leftForeArm);
		DazMap.Add(FName("hand_l"), daz_leftHand);

		DazMap.Add(FName("clavicle_r"), daz_rightShoulder);
		DazMap.Add(FName("upperarm_r"), daz_rightArm);
		DazMap.Add(FName("lowerarm_r"), daz_rightForeArm);
		DazMap.Add(FName("hand_r"), daz_rightHand);

		DazMap.Add(FName("thigh_l"), daz_leftUpLeg);
		DazMap.Add(FName("calf_l"), daz_leftLeg);
		DazMap.Add(FName("foot_l"), daz_leftFoot);
		
		DazMap.Add(FName("thigh_r"), daz_rightUpLeg);
		DazMap.Add(FName("calf_r"), daz_rightLeg);
		DazMap.Add(FName("foot_r"), daz_rightFoot);
	}
}