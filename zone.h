#include <string>
#include <vector>

class Zone{
private:
unsigned int zoneID_m = 0;
std::string zoneName_m = "";

public:
Zone();

void SetZoneID(unsigned int zoneID);
unsigned int GetZoneID();

void SetZoneName(std::string zoneName);
std::string GetZoneName();
};