#ifndef FoursquareShield_h
#define FoursquareShield_h



#define CHECK_IN 0x01

class FoursquareShieldClass
{
public:
	FoursquareShieldClass();
	void checkIn(char* placeId, char* msg);
private:

};
extern FoursquareShieldClass Foursquare;
#endif