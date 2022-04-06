#include "BoneControlLiveLinkEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

#define LOCTEXT_NAMESPACE "BoneControlLiveLinkEditor"

void FBoneControlLiveLinkEditorModule::StartupModule() {

}

void FBoneControlLiveLinkEditorModule::ShutdownModule() {

}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_GAME_MODULE(FBoneControlLiveLinkEditorModule, BoneControlLiveLinkEditor);
DEFINE_LOG_CATEGORY(BoneControlLiveLinkEditor)

