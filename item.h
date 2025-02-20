#pragma once
#include <string>
#include <vector>

class Item{
private:
unsigned int itemID_m = 0;
std::string itemName_m = "";

public:
Item();

void Item::SetItemID(unsigned int itemID);
unsigned int GetItemID();

void SetItemName(std::string itemName);
std::string GetItemName();
};
