#pragma once
#include "text.h"

std::atomic<bool> stopThread(false);
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

Text::~Text()
{

}

void Text::SkipDelayThread()
{
    while(!(stopThread))
    {
        if(kbhit())
        {
            char ch = getch();
            this->msPrintDelay_m = 0;
        }
    }
}

void Text::PrintDelay()
{
    unsigned int delay = this->msPrintDelay_m;
    stopThread = false;
    std::thread checkInput(&Text::SkipDelayThread, this);
    for (std::string::size_type i = 0; i < this->textContent_m.size(); ++i)
    {
        std::cout << textContent_m[i];
        Sleepms(this->msPrintDelay_m);
    }
    stopThread = true;
    checkInput.join();
    this->msPrintDelay_m = delay;
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
