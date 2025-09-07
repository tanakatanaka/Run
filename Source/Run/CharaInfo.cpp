// Fill out your copyright notice in the Description page of Project Settings.


#include "CharaInfo.h"

// Sets default values
ACharaInfo::ACharaInfo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
_startTime = 0;
_totalTime = 0;
}

void ACharaInfo::SetupBaseParam()
{
	_maxhp = 100;
	_hp = _maxhp;
}

bool ACharaInfo::CheckHP(int point)
{
	if (_hp + point < 0)
	{
		return false;
	}

	return true;
}