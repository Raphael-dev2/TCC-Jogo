#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PathSplineActor.generated.h"

UCLASS()
class OUP_API APathSplineActor : public AActor
{
	GENERATED_BODY()

public:
	APathSplineActor();

	// Spline visível e editável no editor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Path")
	USplineComponent* Spline;

	// Comprimento total do spline (para sabermos quando o inimigo chegou ao fim)
	UFUNCTION(BlueprintCallable, Category = "Path")
	float GetSplineLength() const;

	// Pega posição no spline por distância percorrida
	UFUNCTION(BlueprintCallable, Category = "Path")
	FVector GetLocationAtDistance(float Distance) const;

	// Pega orientação (para rotacionar o inimigo)
	UFUNCTION(BlueprintCallable, Category = "Path")
	FRotator GetRotationAtDistance(float Distance) const;
};
