// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */

class UButton;
class UWidgetSwitcher;

UCLASS()
class DUCKDUCK_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

    virtual bool Initialize() override;

    UPROPERTY(meta = (BindWidget))
    UButton* SingleButton;

    UPROPERTY(meta = (BindWidget))
    UButton* LocalButton;

    UPROPERTY(meta = (BindWidget))
    UButton* OnlineButton;

    UPROPERTY(meta = (BindWidget))
    UButton* HostButton;

    UPROPERTY(meta = (BindWidget))
    UButton* JoinButton;

    UPROPERTY(meta = (BindWidget))
    UButton* BackButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitButton;

    UPROPERTY(meta = (BindWidget))
    UWidgetSwitcher* MenuSwitcher;

    UFUNCTION()
    void OnSingleClicked();

    UFUNCTION()
    void OnLocalClicked();

    UFUNCTION()
    void OnOnlineClicked();

    UFUNCTION()
    void OnQuitClicked();

    UFUNCTION()
    void OnHostClicked();

    UFUNCTION()
    void OnJoinClicked();

    UFUNCTION()
    void OnBackClicked();

	
};
