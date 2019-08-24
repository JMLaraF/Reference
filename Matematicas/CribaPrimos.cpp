vector <ll> criba(ll nSize)
{
	vector<short> bs(nSize,0);
	vector<ll> v;
	v.push_back(2);
	for(ll i = 3; i < nSize; i+=2)
	{
		if(bs[i]==0)
			v.push_back(i);
		for(ll j = i*i; j < nSize; j += i)
			bs[j]=1;
	}
}