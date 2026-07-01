// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "Components/EditableTextBox.h"
#include "DuckGameInstance.h"

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
    if (!ensure(IPAddressJoin)) {
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

    GameInstance = GetGameInstance<UDuckGameInstance>();
    MenuSwitcher->SetActiveWidgetIndex(0);

    return true;


}

void UMainMenuWidget::OnSingleClicked() {

    UWorld* World = GetWorld();
    if (!ensure(World))
    {
        return;
    }

    World->ServerTravel("/Game/MAP/LVL_MAPTEST?listen");
    
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
    if (!ensure(GameInstance))
    {
        return;
    }

    GameInstance->Host();

}

void UMainMenuWidget::OnJoinClicked() {
    if (!ensure(GameInstance))
    {
        return;
    }

    FString IP = IPAddressJoin->GetText().ToString();
    GameInstance->Join(IP);

}

void UMainMenuWidget::OnBackClicked() {

    MenuSwitcher->SetActiveWidgetIndex(0);

}