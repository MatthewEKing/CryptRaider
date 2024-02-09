// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetOwner()->GetActorLocation();
	// ...
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector TargetLocation = OriginalLocation;

	if (ShouldMove)
	{
		TargetLocation = OriginalLocation + MoveOffset;
	}

	FVector CurrentLocation = GetOwner()->GetActorLocation();
	float Speed = MoveOffset.Length() / MoveTime;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	GetOwner()->SetActorLocation(NewLocation);

	/*AActor* Owner = GetOwner();
	FString Name = Owner->GetActorNameOrLabel();
	//FString Name = (*Owner).GetActorNameOrLabel(); //same thing as line above, other line is easier.

	FVector Location = Owner->GetActorLocation();
	FString LocationString = Location.ToCompactString();

	UE_LOG(LogTemp, Display, TEXT("Actor Location: %s"), *LocationString);
	UE_LOG(LogTemp, Display, TEXT("Actor Name: %s"), *Name);
	
	/*
	float MyFloat = 5;
	float* FloatAddress = &MyFloat;
	//float FloatValue = *FloatAddress;

	UE_LOG(LogTemp, Display, TEXT("Memory Address: %u"), *FloatAddress);
	*/
}

void UMover::SetShouldMove(bool NewShouldMove)
{
	ShouldMove = NewShouldMove;
}