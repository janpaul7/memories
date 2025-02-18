#include <string>
#include <vector>
#include <chrono>
#include <thread>

class Text{
private:
unsigned int textID_m = 0;
std::string textContent_m = "";
static unsigned int msPrintDelay_m = 50;

public:
Text();

void PrintDelay(unsigned int ms);

void SetTextID(unsigned int textID);
unsigned int GetTextID();

void SetTextContent(std::string textContent);
std::string GetTextContent();

void SetmsPrintDelay(unsigned int msPrintDelay);
unsigned int GetmsPrintDelay();
};
