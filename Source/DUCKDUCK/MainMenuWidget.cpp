// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenuWidget::Initialize() {
    if (!Super::Initialize())
    {
        return false;
    }
    if (!ensure(SingleButton)) {

        return false;
    }
    if (!ensure(LocalButton)) {
        return false;
    }
    if (!ensure(OnlineButton)) {
        return false;
    }
    if (!ensure(QuitButton)) {
        return false;
    }
    if (!ensure(HostButton)) {
        return false;
    }
    if (!ensure(JoinButton)) {
        return false;
    }
    if (!ensure(BackButton)) {
        return false;
    }
    if (!ensure(MenuSwitcher)) {
        return false;
    }


    SingleButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSingleClicked);
    LocalButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLocalClicked);
    OnlineButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnOnlineClicked);
    QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitClicked);
    HostButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnHostClicked);
    JoinButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnJoinClicked);
    BackButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnBackClicked);


    MenuSwitcher->SetActiveWidgetIndex(0);

    return true;


}

void UMainMenuWidget::OnSingleClicked() {

    UGameplayStatics::OpenLevel(GetWorld(), TEXT("LVL_MAPTEST"));
    
}

void UMainMenuWidget::OnLocalClicked() {

    MenuSwitcher->SetActiveWidgetIndex(1);

}

void UMainMenuWidget::OnOnlineClicked() {

}

void UMainMenuWidget::OnQuitClicked() {

        UKismetSystemLibrary::QuitGame(GetWorld(),nullptr,EQuitPreference::Quit,false);

}

void UMainMenuWidget::OnHostClicked() {

}

void UMainMenuWidget::OnJoinClicked() {

}

void UMainMenuWidget::OnBackClicked() {

    MenuSwitcher->SetActiveWidgetIndex(0);

}