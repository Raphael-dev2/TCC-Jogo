#include "PathSplineActor.h"

APathSplineActor::APathSplineActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SetRootComponent(Spline);
	// Dica: marque "Closed Loop" = false no editor, a menos que queira loop.
}

float APathSplineActor::GetSplineLength() const
{
	return Spline ? Spline->GetSplineLength() : 0.f;
}

FVector APathSplineActor::GetLocationAtDistance(float Distance) const
{
	return Spline ? Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World) : FVector::ZeroVector;
}

FRotator APathSplineActor::GetRotationAtDistance(float Distance) const
{
	return Spline ? Spline->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World) : FRotator::ZeroRotator;
}
