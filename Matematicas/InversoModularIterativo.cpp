///////Inverso Modular Iterativo
//Definimos MOD
	ll inversoMod(ll a)
	{
		ll b = MOD;
		ll b0 = b, t , q;
		ll x0 = 0 , x1 = 1;
		if(b == 1) return 1;
		while(a > 1)
		{
			q = a / b;
			t = b , b = a % b , a = t;
			t = x0 , x0 = x1 - q * x0 , x1 = t;
		}
		if(x1 < 0) x1 += b0;
		return x1;
	}

//Otra implementacion

ll inversoMod(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}