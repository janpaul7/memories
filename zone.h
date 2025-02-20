#pragma once
#include <string>
#include <vector>
#include "item.h"
#include "text.h"

class Zone{
private:
unsigned int zoneID_m = 0;
std::string zoneName_m = "";
std::vector<Item> zoneItem_m;
Text zoneText_m;

public:
Zone();

void SetZoneID(unsigned int zoneID);
unsigned int GetZoneID();

void SetZoneName(std::string zoneName);
std::string GetZoneName();

void SetZoneText(Text zoneText);
Text GetZoneText();

void SetZoneItem(Item zoneItem);
Item GetZoneItem(std::string itemName);
};
