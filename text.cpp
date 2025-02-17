#include "text.h"

std::vector<Text*> textContainer;

Text::Text()
{
    textContainer.push_back(this);
    SetTextID(textContainer.size());
}

void Text::SetTextID(unsigned int textID)
{
    this->textID_m = textID;
}

unsigned int Text::GetTextID()
{
    return this->textID_m;
}

void Text::SetTextContent(std::string textContent)
{
    this->textContent_m = textContent;
}

std::string Text::GetTextContent()
{
    return this->textContent_m;
}