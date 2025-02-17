#include "item.h"

std::vector<Item*> itemContainer;

Item::Item()
{
    itemContainer.push_back(this);
    SetItemID(itemContainer.size());
}

void Item::SetItemID(unsigned int itemID)
{
    this->itemID_m = itemID;
}

unsigned int Item::GetItemID()
{
    return this->itemID_m;
}

void Item::SetItemName(std::string itemName)
{
    this->itemName_m = itemName;
}

std::string Item::GetItemName()
{
    return this->itemName_m;
}