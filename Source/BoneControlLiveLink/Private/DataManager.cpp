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

}

DataManager::~DataManager() {

}

TMap<FName, FTransform> DataManager::GetBonesMap() {
	return bonesTransformMap;
}
void DataManager::SetBonesMap(TMap<FName, FTransform>bonesMap) {
	bonesTransformMap = bonesMap;
}

void DataManager::setIsMetahumans(bool _isMetahumans) {
	if (_isMetahumans) {
		isMetahumans = true;
	}
	else {
		isMetahumans = false;
	}
}