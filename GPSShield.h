#ifndef GPSShield_h
#define GPSShield_h

//#define POS 0x01

#define PACKET_SIZE 12
#define DATA_IN 0x01 

class GPSCoordinate {

public:

GPSCoordinate (char deg,char min ,char sec,char side);
char getDeg();
char getMin();
char getSec();
char getChar();


private:
	unsigned char degree;
	unsigned char minutes;
	unsigned char seconds;
	unsigned char type;

};

class GPSShieldClass 
{
public:
	GPSShieldClass();
	GPSCoordinate getLat();
	GPSCoordinate getLon();
	bool islongitude();
	bool islatitude();
	void Proc ();
	
private:
	char Long[4],Latt[4];
	//char *readpacket[PACKET_SIZE]; 
	

};

extern GPSShieldClass GPS;
#endif 