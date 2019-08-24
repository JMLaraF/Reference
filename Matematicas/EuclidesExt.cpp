/////// EUCLIDES EXTENDIDO
// d regresa el GCD.
// x regresa el inverso multiplicativo.
long long euclidesExtendido(int a , int b , int &x , int &y)
{
	if(b == 0)
	{
		d = a;
		x = 1;
		y = 0;
		return d;
	}else
	{
		int x1 , y1;
		euclidesExtendido(b,a%b , x1 , y1);
		x = y1;
		y = x1 - (a/b)*y1;
	}
	return d;
}