#pragma once
#include "zone.h"
#include <string>
#include <vector>

class Spieler{
private:
std::string userInput_m = "";
Zone currentZone_m;
bool playing_m = true;
bool isDebug_m = false;

//Flags:
bool hatCD = false;
bool hatWerkzeugsatz = false;
bool hatcode = false;
bool torOffen = false;
bool hatFlurSchonBetrten = false;
bool schaltschrankoffen = false;
bool schaltschrankoffenfirst = false;
bool hatSD = false;

bool terminalgeloest = false;
bool konsolegeloest = false;

public:
Spieler();

void SetUserInput(std::string userInput);
std::string GetUserInput();

void SetCurrentZone(Zone currentZone);
Zone GetCurrentZone();

bool GetPlaying();
void SetPlaying(bool playing);

bool GetDebug();

void PrintCurrentZoneText();
void AskForInput();
bool CheckCMD(std::string input, std::string cmd);
short CheckInput(std::string input);

std::string GetParameter(std::string befehl);
void PrintUmschauen();
void PrintHelpText();
void PrintMemory();
void PrintShutdown();
void ToggleDebug();
void PrintInvalid();

void AufhebenCD();
bool GetAufhebenCD();

void SetHatCode();
bool GetHatCode();

void SetTorOffen();
bool GetTorOffen();

void SetHatWerkzeugsatz();
bool GetHatWerkzeugsatz();

void SetHatFlurSchonBetreten();
bool GetHatFlurSchonBetreten();

void Setschaltschrankoffen();
bool Getschaltschrankoffen();

void Setschaltschrankoffenfirst();
bool Getschaltschrankoffenfirst();

void SetHatSD();
bool GetHatSD();

void SetKonsoleGeloest();
bool GetKonsoleGeloest();

void SetTerminalGeloest();
bool GetTerminalGeloest();
};
