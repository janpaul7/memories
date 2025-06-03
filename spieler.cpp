#pragma once
#include <iostream>
#include "spieler.h"
#include "text.h"

extern std::vector<Text*> textContainer;

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
    return this->playing_m;
}


bool Spieler::GetDebug()
{
    return this->isDebug_m;
}


void Spieler::AddItemToInventory(Item* addItem)
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

bool Spieler::CheckCMD(std::string input, std::string cmd)
{
    return input.find(cmd) != std::string::npos;
}

void Spieler::CheckInput(std::string input)
{
    if(CheckCMD(input, "help"))
    {
        Spieler::PrintHelpText();
    }

    if(CheckCMD(input, "inventar"))
    {
        Spieler::PrintInventar();
    }

    if(CheckCMD(input, "umschauen"))
    {
        Spieler::PrintUmschauen();
    }

    if(CheckCMD(input, "gehe"))
    {

    }

    if(CheckCMD(input, "aufheben"))
    {
        
    }

    if(CheckCMD(input, "benutze"))
    {
        
    }

    if(CheckCMD(input, "shutdown"))
    {

    }

    if(CheckCMD(input, "debug"))
    {
        Spieler::ToggleDebug();
    }

    else
    {
        Spieler::PrintInvalid();
    }
}

void Spieler::PrintInventar()
{
    Text printInventar;
    unsigned short j = 1;
    std::string stringInventar = "";
    std::string natStringZahl = "";
    for(Item* i : spielerInventory)
    {
        natStringZahl = std::to_string(j);
        stringInventar += natStringZahl + ". " //Item
        j++;
    }
    printInventar.SetTextContent();
}

void Spieler::PrintUmschauen()
{
    Spieler::GetCurrentZone().GetZoneTextUmschauen().PrintDelay();
}

void Spieler::PrintHelpText()
{
    Text help;
    help.SetTextContent("Alle Befehle werden in Kleinbuchstaben geschrieben: \nhelp - Liste aller Befehle\ninventar - Inhalt des aktuellen Inventars\numschauen - Die Umgebung untersuchen\ngehe (ort) - Gehe zum angegebenen Ort\naufheben (gegenstand) - Hebe den angegebenen Gegenstand auf\nbenutze (gegenstand) - Benutzt den Gegenstand an der Stelle an der du dich befindest\nshutdown - Beendet das Spiel");
    std::cout << std::endl << std::endl;
    help.PrintDelay();
    help.~Text();
}

void Spieler::PrintShutdown()
{
    Text shutdown;
    this->playing_m = false;
    shutdown.SetTextContent("Herunterfahren");
    shutdown.PrintDelay();
    shutdown.SetTextContent("...");
    shutdown.SetmsPrintDelay(1000);
    shutdown.PrintDelay();
    shutdown.SetmsPrintDelay(50);
    shutdown.~Text();
}

void Spieler::ToggleDebug()
{
    if (!GetDebug())
    {
        this->isDebug_m = true;
        Text debugEnable;
        debugEnable.SetTextContent("Debug aktiviert!");
        debugEnable.PrintDelay();
        std::cout << std::endl << std::endl;
        debugEnable.~Text();
    }

    else
    {
        this->isDebug_m = false;
        Text debugDisable;
        debugDisable.SetTextContent("Debug deaktiviert!");
        debugDisable.PrintDelay();
        std::cout << std::endl << std::endl;
        debugDisable.~Text();
    }
    return;
}

void Spieler::PrintInvalid()
{
    Text invalid;
    invalid.SetTextContent("Ungueltiger Befehl, tippe 'help' um eine Liste gueltiger Befehle zu erhalten");
    invalid.PrintDelay();
    std::cout << std::endl << std::endl;
    invalid.~Text();
}
