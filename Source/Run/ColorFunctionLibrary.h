// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ColorFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RUN_API UColorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static FLinearColor GetAverageColorFromRT(UTextureRenderTarget2D* RT);

	UFUNCTION(BlueprintCallable, Category = "Cleaning")
	static float GetCleaningRate(UTextureRenderTarget2D* RenderTarget);

};
