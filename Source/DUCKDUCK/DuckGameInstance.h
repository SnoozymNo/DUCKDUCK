// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DuckGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DUCKDUCK_API UDuckGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	void Host();

	void Join(const FString& IPAddressJoin);
	
};
