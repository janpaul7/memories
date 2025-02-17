#include "spieler.h"

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