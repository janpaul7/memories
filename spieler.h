#include "item.h"
#include <string>
#include <vector>

class Spieler{
private:
std::string userInput_m = "";
std::vector<Item*> spielerInv;

public:
Spieler();

void SetUserInput(std::string userInput);
std::string GetUserInput();

};