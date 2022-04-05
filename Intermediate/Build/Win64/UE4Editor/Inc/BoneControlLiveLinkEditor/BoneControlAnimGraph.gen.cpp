// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BoneControlLiveLinkEditor/Public/BoneControlAnimGraph.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoneControlAnimGraph() {}
// Cross Module References
	BONECONTROLLIVELINKEDITOR_API UClass* Z_Construct_UClass_UBoneControl_AnimGraphNode_NoRegister();
	BONECONTROLLIVELINKEDITOR_API UClass* Z_Construct_UClass_UBoneControl_AnimGraphNode();
	ANIMGRAPH_API UClass* Z_Construct_UClass_UAnimGraphNode_Base();
	UPackage* Z_Construct_UPackage__Script_BoneControlLiveLinkEditor();
	BONECONTROLLIVELINK_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_BoneControl();
// End Cross Module References
	void UBoneControl_AnimGraphNode::StaticRegisterNativesUBoneControl_AnimGraphNode()
	{
	}
	UClass* Z_Construct_UClass_UBoneControl_AnimGraphNode_NoRegister()
	{
		return UBoneControl_AnimGraphNode::StaticClass();
	}
	struct Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Node;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_BoneControlLiveLinkEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoneControlAnimGraph.h" },
		{ "ModuleRelativePath", "Public/BoneControlAnimGraph.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::NewProp_Node_MetaData[] = {
		{ "Category", "Setting" },
		{ "ModuleRelativePath", "Public/BoneControlAnimGraph.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBoneControl_AnimGraphNode, Node), Z_Construct_UScriptStruct_FAnimNode_BoneControl, METADATA_PARAMS(Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::NewProp_Node_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::NewProp_Node_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::NewProp_Node,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBoneControl_AnimGraphNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::ClassParams = {
		&UBoneControl_AnimGraphNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBoneControl_AnimGraphNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBoneControl_AnimGraphNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBoneControl_AnimGraphNode, 2401232978);
	template<> BONECONTROLLIVELINKEDITOR_API UClass* StaticClass<UBoneControl_AnimGraphNode>()
	{
		return UBoneControl_AnimGraphNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBoneControl_AnimGraphNode(Z_Construct_UClass_UBoneControl_AnimGraphNode, &UBoneControl_AnimGraphNode::StaticClass, TEXT("/Script/BoneControlLiveLinkEditor"), TEXT("UBoneControl_AnimGraphNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBoneControl_AnimGraphNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
