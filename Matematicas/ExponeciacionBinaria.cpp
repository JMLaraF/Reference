////////POTENCIACION BINARIA

#define MOD (ll)10e9+7

ll pot(ll a , ll b)
{
	ll ans = 1;
	if(b == 0)
		return 1;
	for(int i = 0 ; i < 63 ; i++)
	{
		if((((ll)1 << i)&(b)) != 0)
			ans = ((ans*a)+MOD)%MOD;
		a = ((a*a)+MOD)%MOD;
	}
	return ans;
}