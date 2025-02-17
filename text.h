#include <string>
#include <vector>

class Text{
private:
unsigned int textID_m = 0;
std::string textContent_m = "";

public:
Text();

void SetTextID(unsigned int textID);
unsigned int GetTextID();

void SetTextContent(std::string textContent);
std::string GetTextContent();
};