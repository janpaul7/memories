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
    this->zoneName_m = zoneName;
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

void Zone::SetZoneTextMemory(Text zoneTextMemory)
{
    this->zoneTextMemory_m = zoneTextMemory;
}

Text Zone::GetZoneTextMemory()
{
    return this->zoneTextMemory_m;
}

void Zone::SetZoneTextUmschauen(Text zoneTextUmschauen)
{
    this->zoneTextUmschauen_m = zoneTextUmschauen;
}

Text Zone::GetZoneTextUmschauen()
{
    return this->zoneTextUmschauen_m;
}

void Zone::SetzoneTextUmschauenItem1(Text zoneTextUmschauenItem1)
{
    this->zoneTextUmschauenItem1_m = zoneTextUmschauenItem1;
}

Text Zone::GetzoneTextUmschauenItem1()
{
    return this->zoneTextUmschauenItem1_m;
}

void Zone::SetItem1Aufgehoben(bool aufgehoben)
{
    this->Item1Aufgehoben = aufgehoben;
}

bool Zone::GetItem1Aufgehoben()
{
    return this->Item1Aufgehoben;
}

void Zone::SetItem2Aufgehoben()
{
    this->Item2Aufgehoben = true;
}

bool Zone::GetItem2Aufgehoben()
{
    return this->Item2Aufgehoben;
}

void Zone::SetzoneTextUmschauenItem2(Text zoneTextUmschauenItem2)
{
    this->zoneTextUmschauenItem2_m = zoneTextUmschauenItem2;
}

Text Zone::GetzoneTextUmschauenItem2()
{
    return this->zoneTextUmschauenItem2_m;
}
