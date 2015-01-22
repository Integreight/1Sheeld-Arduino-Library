#ifndef ShieldParent_h
#define ShieldParent_h


/* Output functions ID. */
#define QUERY_SELECTED		0xFF
#define SELECT_SHIELD		0xFE	
#define DESELECT_SHIELD		0xFD


/* Input functions ID. */
#define CHECK_SELECTED		0xFF

class ShieldParent
{
protected:
	ShieldParent(byte);
public:
	/* Functions will be inherited by all shields. */
	void select(void);
	void deselect(void);
	void setOnSelected(void(*)(void));
	virtual void processData(void);
private:
	bool isCallBackSet ;
	byte shieldID;
	void (*selectedCallBack)(void);
};

#endif