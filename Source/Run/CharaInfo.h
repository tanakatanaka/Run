// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharaInfo.generated.h"

UCLASS()
class RUN_API ACharaInfo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACharaInfo();

	UFUNCTION(BlueprintCallable)
		void SetupBaseParam();

	UFUNCTION(BlueprintCallable)
		FORCEINLINE void UpdateHP(int hp) { _hp = hp; }

	UFUNCTION(BlueprintCallable)
		FORCEINLINE  int GetHP() { return _hp; }

	UFUNCTION(BlueprintCallable)
		FORCEINLINE  int GetMaxHP() { return _maxhp; }

	UFUNCTION(BlueprintCallable)
		bool CheckHP(int point);

private:
	int _hp;
	int _maxhp;

	float _startTime;
	float _totalTime;

};
