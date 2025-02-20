#pragma once
#include <iostream>
#include "spieler.h"

Spieler::Spieler()
{

}


void Spieler::SetUserInput(std::string userInput)
{
    this->userInput_m = userInput;
}

std::string Spieler::GetUserInput()
{
    return this->userInput_m;
}


void Spieler::SetCurrentZone(Zone currentZone)
{
    this->currentZone_m = currentZone;
}

Zone Spieler::GetCurrentZone()
{
    return this->currentZone_m;
}


bool Spieler::GetPlaying()
{
    return this->playing;
}


void Spieler::AddItemToInventory(Item addItem)
{
    this->spielerInventory.push_back(addItem);
}

void Spieler::PrintCurrentZoneText()
{
    this->currentZone_m.GetZoneText().PrintDelay();
}

void Spieler::AskForInput()
{
    std::string input;
    std::cout << std::endl << ">    ";
    std::cin >> input;
    this->userInput_m = input;
    std::cout << std::endl;
}

void Spieler::CheckInput()
{

}
