#pragma once
#include "zone.h"
#include <string>
#include <vector>

class Spieler{
private:
std::string userInput_m = "";
std::vector<Item*> spielerInventory;
Zone currentZone_m;
bool playing_m = true;
bool isDebug_m = false;

//Flags:

public:
Spieler();

void SetUserInput(std::string userInput);
std::string GetUserInput();

void Spieler::SetCurrentZone(Zone currentZone);
Zone GetCurrentZone();

bool GetPlaying();

bool GetDebug();

void AddItemToInventory(Item* addItem);
void PrintCurrentZoneText();
void AskForInput();
bool CheckCMD(std::string input, std::string cmd);
int CheckInputPosition(std::string input, std::string contains);
void CheckInput(std::string input);

void PrintInventar();
void PrintUmschauen();
void PrintHelpText();
void PrintShutdown();
void ToggleDebug();
void PrintInvalid();
};
