// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ILiveLinkSource.h"
#include "HAL/Runnable.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"


/**
 *
 */

class ILiveLinkClient;

class BONECONTROLLIVELINK_API FBoneControlLiveLinkSource : public ILiveLinkSource, public FRunnable
{
public:
	FBoneControlLiveLinkSource(FIPv4Endpoint Endpoint);
	virtual ~FBoneControlLiveLinkSource();

	//ILiveLink Interface
	virtual void ReceiveClient(ILiveLinkClient* InClient, FGuid InSourceGuid) override;
	virtual bool IsSourceStillValid() const override;
	virtual bool RequestSourceShutdown() override;

	virtual FText GetSourceType()const override { return SourceType; }
	virtual FText GetSourceMachineName()const override { return SourceMachineName; }
	virtual FText GetSourceStatus() const override { return SourceStatus; }


	//FRunnable Interface
	virtual bool Init() override { return true; }
	virtual uint32 Run() override;
	void Start();
	virtual void Stop() override;
	virtual void Exit() override { };


	void HandleSuitData();
	//End FRunnable Interface  
	void HandleReceivedData(TSharedPtr<TArray<uint8>, ESPMode::ThreadSafe> ReceivedData);//pending 

private:
	ILiveLinkClient* Client;

	FGuid SourceGuid;


	// Our identifier in LiveLink


	// Source Infos

	FText SourceType;
	FText SourceMachineName;
	FText SourceStatus;

	FName SubjectName;

	/*int NumBones;
	int NumCurves;
	TSet<int> Roots;*/

	// Machine/Port we're connected to
	FIPv4Endpoint DeviceEndpoint;  //Implements an endpoint for IPv4 networks. Variables Address Port

	// Socket to receive data on
	FSocket* Socket;

	// Subsystem associated to Socket
	ISocketSubsystem* SocketSubsystem;

	// Threadsafe Bool for terminating the main thread loop
	FThreadSafeBool Stopping;

	// Thread to run socket operations on
	FRunnableThread* Thread;

	// Name of the sockets thread
	FString ThreadName;

	// Time to wait between attempted receives
	FTimespan WaitTime;

	// List of subjects we've already encountered
	TSet<FName> EncounteredSubjects;

	// Buffer to receive socket data into
	TArray<uint8> RecvBuffer;

	TArray<FRotator>LastFrameBonesRotation;
};
