#pragma once
#include "zone.h"
#include <string>
#include <vector>

class Spieler{
private:
std::string userInput_m = "";
std::vector<Item> spielerInventory;
Zone currentZone_m;
bool playing = true;

//Flags:

public:
Spieler();

void SetUserInput(std::string userInput);
std::string GetUserInput();

void Spieler::SetCurrentZone(Zone currentZone);
Zone GetCurrentZone();

bool GetPlaying();

void AddItemToInventory(Item addItem);
void PrintCurrentZoneText();
void AskForInput();
void CheckInput();
};
