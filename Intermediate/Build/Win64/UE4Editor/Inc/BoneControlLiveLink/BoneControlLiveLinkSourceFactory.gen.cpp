// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BoneControlLiveLink/Public/BoneControlLiveLinkSourceFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoneControlLiveLinkSourceFactory() {}
// Cross Module References
	BONECONTROLLIVELINK_API UClass* Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_NoRegister();
	BONECONTROLLIVELINK_API UClass* Z_Construct_UClass_UBoneControlLiveLinkSourceFactory();
	LIVELINKINTERFACE_API UClass* Z_Construct_UClass_ULiveLinkSourceFactory();
	UPackage* Z_Construct_UPackage__Script_BoneControlLiveLink();
// End Cross Module References
	void UBoneControlLiveLinkSourceFactory::StaticRegisterNativesUBoneControlLiveLinkSourceFactory()
	{
	}
	UClass* Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_NoRegister()
	{
		return UBoneControlLiveLinkSourceFactory::StaticClass();
	}
	struct Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULiveLinkSourceFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_BoneControlLiveLink,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoneControlLiveLinkSourceFactory.h" },
		{ "ModuleRelativePath", "Public/BoneControlLiveLinkSourceFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBoneControlLiveLinkSourceFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics::ClassParams = {
		&UBoneControlLiveLinkSourceFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBoneControlLiveLinkSourceFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBoneControlLiveLinkSourceFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBoneControlLiveLinkSourceFactory, 2582000982);
	template<> BONECONTROLLIVELINK_API UClass* StaticClass<UBoneControlLiveLinkSourceFactory>()
	{
		return UBoneControlLiveLinkSourceFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBoneControlLiveLinkSourceFactory(Z_Construct_UClass_UBoneControlLiveLinkSourceFactory, &UBoneControlLiveLinkSourceFactory::StaticClass, TEXT("/Script/BoneControlLiveLink"), TEXT("UBoneControlLiveLinkSourceFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBoneControlLiveLinkSourceFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
