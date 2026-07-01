// Fill out your copyright notice in the Description page of Project Settings.


#include "DuckGameInstance.h"


void UDuckGameInstance::Host() {

	UWorld* World = GetWorld();
	if (!ensure(World))
	{
		return;
	}

	World->ServerTravel("/Game/MAP/LVL_MAPTEST?listen");

}

void UDuckGameInstance::Join(const FString& IPAddressJoin) {

	APlayerController* Controller = GetFirstLocalPlayerController();
	if (!ensure(Controller))
	{
		return;
	}

	Controller->ClientTravel(*IPAddressJoin, ETravelType::TRAVEL_Absolute);

}
