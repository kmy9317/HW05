// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HWActor.generated.h"

UCLASS()
class UNREALHW05_API AHWActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AHWActor();

	virtual void Tick(float DeltaTime) override;

	FVector GetStartLocation() const { return StartLocation; }

protected:
	virtual void BeginPlay() override;
	
	void Move();
	int32 Step();

private:
	float Distance(FVector A, FVector B);

	bool TriggerEventWithProbability(float Probability);
	
private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	FVector StartLocation = FVector::ZeroVector;
	
	FVector CurrentLocation = FVector::ZeroVector;
};
