#pragma once
#include <string>
#include <vector>
#include "text.h"

class Zone{
private:
unsigned int zoneID_m = 0;
std::string zoneName_m = "";
Text zoneText_m;
Text zoneTextMemory_m;
Text zoneTextUmschauen_m;

Text zoneTextUmschauenItem1_m;
Text zoneTextUmschauenItem2_m;

//FLAGS
bool Item1Aufgehoben = false;
bool Item2Aufgehoben = false;

public:
Zone();

void SetZoneID(unsigned int zoneID);
unsigned int GetZoneID();

void SetZoneName(std::string zoneName);
std::string GetZoneName();

void SetZoneText(Text zoneText);
Text GetZoneText();

void SetZoneTextMemory(Text zoneTextMemory);
Text GetZoneTextMemory();

void SetZoneTextUmschauen(Text zoneTextUmschauen);
Text GetZoneTextUmschauen();

void SetzoneTextUmschauenItem1(Text zoneTextUmschauenItem1);
Text GetzoneTextUmschauenItem1();

void SetItem1Aufgehoben(bool aufgehoben);
bool GetItem1Aufgehoben();

void SetItem2Aufgehoben();
bool GetItem2Aufgehoben();

void SetzoneTextUmschauenItem2(Text zoneTextUmschauenItem2);
Text GetzoneTextUmschauenItem2();
};
