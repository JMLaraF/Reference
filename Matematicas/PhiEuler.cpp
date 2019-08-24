//////////PHI DE EULER
// v es un vector de primos
ll Eulerphi(ll  N)
{
	ll PF_dix = 0 ;
	ll PF = v[PF_dix];
	ll ans = N;
	
	while(PF * PF <= N)
	{
		if(N % PF == 0) ans -= ans/ PF;
		while( N % PF == 0) N /= PF;
		PF = v[++PF_dix];
	}
	if(N!=1) ans -= ans/N;
	return ans;
}