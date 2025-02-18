#include "text.h"

std::vector<Text*> textContainer;

void Sleepms(unsigned int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

Text::Text()
{
    textContainer.push_back(this);
    SetTextID(textContainer.size());
}

void Text::PrintDelay(unsigned int ms)
{
    for (std::string::size_type i = 0; i < GetTextContent().size(); ++i)
    {
        std::cout << GetTextContent()[i];
        Sleepms(GetmsPrintDelay());
    }
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

void Text::SetmsPrintDelay(unsigned int msPrintDelay)
{
    this->msPrintDelay_m = msPrintDelay;
}

unsigned int Text::GetmsPrintDelay()
{
    return this->msPrintDelay_m;
}
