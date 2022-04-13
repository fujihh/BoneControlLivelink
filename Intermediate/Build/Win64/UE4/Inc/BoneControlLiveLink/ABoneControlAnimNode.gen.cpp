// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BoneControlLiveLink/Public/ABoneControlAnimNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABoneControlAnimNode() {}
// Cross Module References
	BONECONTROLLIVELINK_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_BoneControl();
	UPackage* Z_Construct_UPackage__Script_BoneControlLiveLink();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_Base();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FPoseLink();
// End Cross Module References

static_assert(std::is_polymorphic<FAnimNode_BoneControl>() == std::is_polymorphic<FAnimNode_Base>(), "USTRUCT FAnimNode_BoneControl cannot be polymorphic unless super FAnimNode_Base is polymorphic");

class UScriptStruct* FAnimNode_BoneControl::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern BONECONTROLLIVELINK_API uint32 Get_Z_Construct_UScriptStruct_FAnimNode_BoneControl_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_BoneControl, Z_Construct_UPackage__Script_BoneControlLiveLink(), TEXT("AnimNode_BoneControl"), sizeof(FAnimNode_BoneControl), Get_Z_Construct_UScriptStruct_FAnimNode_BoneControl_Hash());
	}
	return Singleton;
}
template<> BONECONTROLLIVELINK_API UScriptStruct* StaticStruct<FAnimNode_BoneControl>()
{
	return FAnimNode_BoneControl::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAnimNode_BoneControl(FAnimNode_BoneControl::StaticStruct, TEXT("/Script/BoneControlLiveLink"), TEXT("AnimNode_BoneControl"), false, nullptr, nullptr);
static struct FScriptStruct_BoneControlLiveLink_StaticRegisterNativesFAnimNode_BoneControl
{
	FScriptStruct_BoneControlLiveLink_StaticRegisterNativesFAnimNode_BoneControl()
	{
		UScriptStruct::DeferCppStructOps<FAnimNode_BoneControl>(FName(TEXT("AnimNode_BoneControl")));
	}
} ScriptStruct_BoneControlLiveLink_StaticRegisterNativesFAnimNode_BoneControl;
	struct Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BasePose_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BasePose;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//extern \"C\" TMap<FName, FTransform>bonesTransformMap__temp;\n" },
		{ "ModuleRelativePath", "Public/ABoneControlAnimNode.h" },
		{ "ToolTip", "extern \"C\" TMap<FName, FTransform>bonesTransformMap__temp;" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_BoneControl>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::NewProp_BasePose_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/ABoneControlAnimNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::NewProp_BasePose = { "BasePose", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAnimNode_BoneControl, BasePose), Z_Construct_UScriptStruct_FPoseLink, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::NewProp_BasePose_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::NewProp_BasePose_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::NewProp_BasePose,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BoneControlLiveLink,
		Z_Construct_UScriptStruct_FAnimNode_Base,
		&NewStructOps,
		"AnimNode_BoneControl",
		sizeof(FAnimNode_BoneControl),
		alignof(FAnimNode_BoneControl),
		Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_BoneControl()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAnimNode_BoneControl_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_BoneControlLiveLink();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AnimNode_BoneControl"), sizeof(FAnimNode_BoneControl), Get_Z_Construct_UScriptStruct_FAnimNode_BoneControl_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAnimNode_BoneControl_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAnimNode_BoneControl_Hash() { return 1494257910U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
