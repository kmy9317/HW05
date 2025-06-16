// Fill out your copyright notice in the Description page of Project Settings.


#include "HWGameModeBase.h"
#include "Actor/HWActor.h"

void AHWGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (UWorld* World = GetWorld())
	{
		FActorSpawnParameters Params;
		World->SpawnActor<AHWActor>(AHWActor::StaticClass(), AHWActor::StaticClass()->GetDefaultObject<AHWActor>()->GetStartLocation(),FRotator::ZeroRotator, Params);
	}
}
