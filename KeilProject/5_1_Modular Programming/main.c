#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
void main()
{
	while(1)
	{
		NixieTube(1,1);
		NixieTube(2,2);
		NixieTube(3,3);
		NixieTube(4,4);
		NixieTube(5,5);
		NixieTube(6,6);
	}
}