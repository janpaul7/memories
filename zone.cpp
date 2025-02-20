#pragma once
#include "zone.h"

std::vector<Zone*> zoneContainer;

Zone::Zone()
{
    zoneContainer.push_back(this);
    SetZoneID(zoneContainer.size());
}


void Zone::SetZoneID(unsigned int zoneID)
{
    this->zoneID_m = zoneID;
}

unsigned int Zone::GetZoneID()
{
    return this->zoneID_m;
}


void Zone::SetZoneName(std::string zoneName)
{
    this->zoneName_m = "\033[1;31m" + zoneName + "\033[1;0m";
}

std::string Zone::GetZoneName()
{
    return this->zoneName_m;
}


void Zone::SetZoneText(Text zoneText)
{
    this->zoneText_m = zoneText;
}

Text Zone::GetZoneText()
{
    return this->zoneText_m;
}


void Zone::SetZoneItem(Item zoneItem)
{
    this->zoneItem_m.push_back(zoneItem);
}

Item Zone::GetZoneItem(std::string itemName)
{
    for (Item i : this->zoneItem_m)
    {
        if (i.GetItemName() == itemName)
        {
            return i;
        }
    }
}
