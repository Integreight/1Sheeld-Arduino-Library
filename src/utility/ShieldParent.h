/*

  Project:       1Sheeld Library 
  File:          ShieldParent.h
                 
  Version:       1.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/

#ifndef ShieldParent_h
#define ShieldParent_h


/* Output functions ID. */
#define QUERY_SELECTED		0xFF
#define SELECT_SHIELD		0xFE	
#define DESELECT_SHIELD		0xFD


/* Input functions ID. */
#define CHECK_SELECTED		0xFF

class OneSheeldClass;

class ShieldParent
{
protected:
	ShieldParent(byte);
	virtual void processFrame(void);
	virtual void processData(void){};
	void enteringACallback();
	void exitingACallback();
	bool isInACallback();
	OneSheeldClass & getOneSheeldInstance();
public:
	/* Functions will be inherited by all shields. */
	void select(void);
	void deselect(void);
	void setOnSelected(void(*)(void));
	byte getShieldId(void);
private:
	bool isCallBackSet;
	byte shieldID;
	void (*selectedCallBack)(void);
	static OneSheeldClass * oneSheeldInstance;
	static bool oneSheeldInstanceAvailable;
	static void setOneSheeldInstance(OneSheeldClass &);
	static void unSetOneSheeldInstance();

friend class OneSheeldClass;
};

#endif