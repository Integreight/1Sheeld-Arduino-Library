#include "OneSheeld.h"






ShieldParent::ShieldParent(byte shieldNo)
{
	shieldID = shieldNo ;
	isCallBackSet=false;
}

void ShieldParent::select()
{
	OneSheeld.sendPacket(shieldID,0x00,SELECT_SHIELD,0x00);
}

void ShieldParent::deselect()
{
	OneSheeld.sendPacket(shieldID,0x00,DESELECT_SHIELD,0x00);
}

void ShieldParent::setOnSelected(void (*userFunction)(void))
{
	OneSheeld.sendPacket(shieldID,0x00,QUERY_SELECTED,0x00);
	isCallBackSet=true;
	selectedCallBack=userFunction;
}

void ShieldParent::processData()
{
	byte functionID = OneSheeld.getFunctionId();

	if(functionID == CHECK_SELECTED && isCallBackSet)
	{
		(*selectedCallBack)();
	}
}
