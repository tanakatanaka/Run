// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorFunctionLibrary.h"

FLinearColor UColorFunctionLibrary::GetAverageColorFromRT(UTextureRenderTarget2D* RT)
{
    FTextureRenderTargetResource* RTResource = RT->GameThread_GetRenderTargetResource();

    TArray<FColor> OutBMP;
    RTResource->ReadPixels(OutBMP);

    int32 NumPixels = OutBMP.Num();
    FVector4 Sum = FVector4(0, 0, 0, 0);

    for (auto& Pixel : OutBMP)
    {
        Sum.X += Pixel.R;
        Sum.Y += Pixel.G;
        Sum.Z += Pixel.B;
        Sum.W += Pixel.A;
    }

    return FLinearColor(
        Sum.X / (255.f * NumPixels),
        Sum.Y / (255.f * NumPixels),
        Sum.Z / (255.f * NumPixels),
        Sum.W / (255.f * NumPixels)
    );
}

float UColorFunctionLibrary::GetCleaningRate(UTextureRenderTarget2D* RenderTarget)
{
    if (!RenderTarget) return 0.0f;

    TArray<FColor> OutBMP;
    FRenderTarget* RTResource = RenderTarget->GameThread_GetRenderTargetResource();
    RTResource->ReadPixels(OutBMP);

    int32 CleanCount = 0;
    int32 TotalCount = OutBMP.Num();

    if (TotalCount == 0) return 0.0f;

    for (const FColor& Pixel : OutBMP)
    {
        if (!(Pixel.R == 255 && Pixel.G == 255 && Pixel.B == 255))
        {
            CleanCount++;
        }
    }

    return (float)CleanCount / (float)TotalCount; // �|�����i0.0�`1.0�j
}