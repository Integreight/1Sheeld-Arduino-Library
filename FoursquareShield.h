#ifndef FoursquareShield_h
#define FoursquareShield_h



#define CHECK_IN 0x01

class FoursquareShieldClass
{
public:
	FoursquareShieldClass();
	void checkIn(char* placeName);
private:

};
extern FoursquareShieldClass FSQ;
#endif