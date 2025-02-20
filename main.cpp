#pragma once
#include <iostream>
#include "text.h"
#include "item.h"
#include "zone.h"
#include "spieler.h"


int main()
{    
    //DEBUG INITS
    Spieler currentPlayer;

    Text DebugText1;
    DebugText1.SetTextContent("Hello World!, Hello World!, Hello World!, Hello World!, Hello World!, Hello World!");

    Zone DebugZone1;
    DebugZone1.SetZoneText(DebugText1);

    currentPlayer.SetCurrentZone(DebugZone1);

    //GAME LOOP
    while (currentPlayer.GetPlaying())
    {
        currentPlayer.PrintCurrentZoneText();
        currentPlayer.AskForInput();
        currentPlayer.CheckInput();
    }
    return 0;
}
