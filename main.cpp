#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void printDelay(unsigned int ms, std::string text);
void sleepms(unsigned int ms);

int main()
{
    unsigned int msPrintDelay = 50;


    printDelay(msPrintDelay, "Hallo Welt!");
    return 0;
}

void printDelay(unsigned int ms, std::string text)
{
    for (std::string::size_type i = 0; i < text.size(); ++i)
    {
        std::cout << text[i];
        sleepms(ms);
    }
}

void sleepms(unsigned int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}