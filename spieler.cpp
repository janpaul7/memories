#pragma once
#include <iostream>
#include "spieler.h"
#include "text.h"
#include <sstream>

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

void Spieler::SetPlaying(bool playing)
{
    this->playing_m = false;
}

bool Spieler::GetDebug()
{
    return this->isDebug_m;
}

void Spieler::PrintCurrentZoneText()
{
    this->currentZone_m.GetZoneText().PrintDelay();
}

void Spieler::AskForInput()
{
    std::string input;
    std::cout << std::endl << ">    ";
    std::getline(std::cin, input);
    this->userInput_m = input;
    std::cout << std::endl;
}

bool Spieler::CheckCMD(std::string input, std::string cmd)
{
    return input.find(cmd) != std::string::npos;
}

short Spieler::CheckInput(std::string input)
{
    if(CheckCMD(input, "help"))
    {
        Spieler::PrintHelpText();
    }

    else if(CheckCMD(input, "umschauen"))
    {
        return 1;
    }

    else if(CheckCMD(input, "gehe"))
    {
        return 4;
    }

    else if(CheckCMD(input, "aufheben"))
    {
        return 2;
    }

    else if(CheckCMD(input, "benutze"))
    {
        return 3;
    }

    else if(CheckCMD(input, "shutdown"))
    {
        Spieler::PrintShutdown();
    }

    else if(CheckCMD(input, "terminal"))
    {
        return 5;
    }

    else if(CheckCMD(input, "konsole"))
    {
        return 6;
    }

    else
    {
        Spieler::PrintInvalid();
    }
    return 0;
}

std::string Spieler::GetParameter(std::string befehl)
{
    std::istringstream iss(befehl);
    std::string cmd, param;
    iss >> cmd >> param;
    return param;
}

void Spieler::PrintUmschauen()
{
    Spieler::GetCurrentZone().GetZoneTextUmschauen().PrintDelay();
    if (Spieler::GetHatCode() == false && Spieler::GetCurrentZone().GetZoneName() == "Intro")
    {
        Spieler::GetCurrentZone().GetzoneTextUmschauenItem1().PrintDelay();
    }
    if (Spieler::GetHatCode() == false && Spieler::GetCurrentZone().GetZoneName() == "Intro")
    {
        Spieler::GetCurrentZone().GetzoneTextUmschauenItem2().PrintDelay();
    }
    if (Spieler::Getschaltschrankoffen() == false && Spieler::GetCurrentZone().GetZoneName() == "Flur")
    {
        Spieler::GetCurrentZone().GetzoneTextUmschauenItem1().PrintDelay();
    }
}

void Spieler::PrintHelpText()
{
    Text help;
    help.SetTextContent("Alle Befehle werden in Kleinbuchstaben geschrieben: \nhelp - Liste aller Befehle\numschauen - Die Umgebung untersuchen\ngehe (ort) - Gehe zum angegebenen Ort\naufheben (gegenstand) - Hebe den angegebenen Gegenstand auf\nbenutze (gegenstand) - Benutzt den Gegenstand an der Stelle an der du dich befindest\nshutdown - Beendet das Spiel\n");
    std::cout << std::endl << std::endl;
    help.PrintDelay();
}

void Spieler::PrintMemory()
{
    Text printMemory;
    printMemory.SetTextContent("Die Erinnerungen verschwinden, was zurueck bleibt ist die echte Welt.\n");
    Spieler::GetCurrentZone().GetZoneTextMemory().PrintDelay();
    printMemory.PrintDelay();
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
}

void Spieler::ToggleDebug()
{
    if (!GetDebug())
    {
        this->isDebug_m = true;
        Text debugEnable;
        debugEnable.SetTextContent("Debug aktiviert!\n");
        debugEnable.PrintDelay();
        std::cout << std::endl << std::endl;
    }

    else
    {
        this->isDebug_m = false;
        Text debugDisable;
        debugDisable.SetTextContent("Debug deaktiviert!\n");
        debugDisable.PrintDelay();
        std::cout << std::endl << std::endl;
    }
    return;
}

void Spieler::PrintInvalid()
{
    Text invalid;
    invalid.SetTextContent("Ungueltiger Befehl, tippe 'help' um eine Liste gueltiger Befehle zu erhalten\n");
    invalid.PrintDelay();
    std::cout << std::endl << std::endl;
}

void Spieler::AufhebenCD()
{
    Text CDaufheben;
    CDaufheben.SetTextContent("CD wurde aufgehoben!\n");
    this->hatCD = true;
    Spieler::currentZone_m.SetItem1Aufgehoben(true);
    CDaufheben.PrintDelay();
}

bool Spieler::GetAufhebenCD()
{
    return this->hatCD;
}

void Spieler::SetHatCode()
{
    this->hatcode = true;
}

bool Spieler::GetHatCode()
{
    return this->hatcode;
}

void Spieler::SetTorOffen()
{
    this->torOffen = true;
}

bool Spieler::GetTorOffen()
{
    return this->torOffen;
}

void Spieler::SetHatWerkzeugsatz()
{
    Text SDaufheben;
    SDaufheben.SetTextContent("Werkzeugsatz wurde aufgehoben!\n");
    this->hatWerkzeugsatz = true;
    Spieler::currentZone_m.SetItem2Aufgehoben();
    SDaufheben.PrintDelay();
}

bool Spieler::GetHatWerkzeugsatz()
{
    return this->hatWerkzeugsatz;
}


void Spieler::SetHatFlurSchonBetreten()
{
    this->hatFlurSchonBetrten = true;
}

bool Spieler::GetHatFlurSchonBetreten()
{
    return this->hatFlurSchonBetrten;
}

void Spieler::Setschaltschrankoffen()
{
    this->schaltschrankoffen = true;
}

bool Spieler::Getschaltschrankoffen()
{
    return this->schaltschrankoffen;
}

void Spieler::Setschaltschrankoffenfirst()
{
    this->schaltschrankoffen = true;
}

bool Spieler::Getschaltschrankoffenfirst()
{
    return this->schaltschrankoffen;
}

void Spieler::SetHatSD()
{
    Text SDaufheben;
    SDaufheben.SetTextContent("SD-Karte wurde aufgehoben!\n");
    this->hatSD = true;
    SDaufheben.PrintDelay();
}

bool Spieler::GetHatSD()
{
    return this->hatSD;
}

void Spieler::SetKonsoleGeloest()
{
    this->konsolegeloest = true;
}

bool Spieler::GetKonsoleGeloest()
{
    return this->konsolegeloest;
}

void Spieler::SetTerminalGeloest()
{
    this->terminalgeloest = true;
}

bool Spieler::GetTerminalGeloest()
{
    return this->terminalgeloest;
}
