void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
			i = 195;
		j = 138;
		do
		{
			while (--j);
		} while (--i);
	}
}