#ifndef InternetShield_h
#define InternetShield_h


#define SEND_URL	0x01
#define SEARCH 		0x02
#define CONNECT 	0x03
#define DISCONNECT 	0x04
#define RESULT 		0x01
#define STATUS 		0x02



class InternetShield
{
public:
	InternetShield();
	void open(char *);
	void search(char *);
	char  * getResult();
	bool getStatus();
	void connect();
	void disconnect();
private:
	
	bool status;
	char *result;
	void processData();

	friend class OneSheeldClass;

};

extern InternetShield Internet;
#endif