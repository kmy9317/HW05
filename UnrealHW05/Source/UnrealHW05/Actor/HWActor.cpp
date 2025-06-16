#include "HWActor.h"

AHWActor::AHWActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHWActor::BeginPlay()
{
	Super::BeginPlay();

	CurrentLocation = StartLocation;
	SetActorLocation(CurrentLocation);

	Move();
}

void AHWActor::Tick(float DeltaTime)
{
	// Tick 필요 없어 보이므로 false 플래그 지정
	Super::Tick(DeltaTime);
}

int32 AHWActor::Step()
{
	return FMath::RandRange(0, 1);
}

void AHWActor::Move()
{
	float TotalDistance = 0.f;
	int32 TotalEvents = 0;
	FVector PrevLocation = CurrentLocation;
	
	for (int32 i = 0; i < 10; ++i)
	{
		PrevLocation = CurrentLocation;
		
		CurrentLocation.X += Step();
		CurrentLocation.Y += Step();

		SetActorLocation(CurrentLocation);

		float StepDistance = Distance(PrevLocation, CurrentLocation);
		TotalDistance += StepDistance;
		
		UE_LOG(LogTemp, Warning, TEXT("Prev Location: %s, Current Location: %s"), *PrevLocation.ToString(), *CurrentLocation.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Step Distance: %f"),StepDistance);

		if (TriggerEventWithProbability(50.f)) TotalEvents++;
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Distance Moved: %f"), TotalDistance);
	UE_LOG(LogTemp, Warning, TEXT("Total Events Triggered: %d"), TotalEvents);
}

float AHWActor::Distance(FVector A, FVector B)
{
	float da = A.X - B.X;
	float db = A.Y - B.Y;
	float dc = A.Z - B.Z;

	return FMath::Sqrt(da * da + db * db + dc * dc);
}

bool AHWActor::TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100);
	bool bTriggered = RandomValue <= Probability;
	
	if (bTriggered)
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Triggered!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Not Triggered"));
	}

	return bTriggered;;
}

