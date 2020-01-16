// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Public/EngineGlobals.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Create a camera and a visible object
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (isAlive != true) {
		isAlive = true;
		UE_LOG(LogTemp, Warning, TEXT("AAAAAAAA I'm the character and I'm running now"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LOGGING TO SCREEN"));
		//UKismetSystemLibrary::PrintString("Testing Printing to Screen", true, true, true);
	}
	
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("CreateProjectile", IE_Pressed, this, &ATestCharacter::CreateProjectile);
}

void ATestCharacter::CreateProjectile() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PRESSED THE SPACEBAR"));
	TestSpawnObject::SpawnDefault
}
