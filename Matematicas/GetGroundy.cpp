/////// getGroudy (FALTA OPTIMIZAR)

struct nodo
{
	vector <int> fx;
	map <int,char> mp;
	int gx;
	nodo()
	{
		gx = -1;
	}	
};

int getGx(int x , vector <nodo> &v)
{
//	cout << "gx = " << v[x].gx << " x= " << x << " ENT\n";
	if(v[x].gx == -1 && v[x].fx.empty() )
	{
//		cout << "gx = 0 x= " << x << '\n';
		v[x].gx = 0;
		return 0;
	}else if(v[x].gx == -1 && !v[x].fx.empty() )
	{
		int gdxAct = 0;
		for(int i = 0 ; i < v[x].fx.size() ; i++)
		{
			v[x].mp[getGx(v[x].fx[i] , v)] = true;
		}
//		cout << gdxAct << "QASD\n";
		while(v[x].mp[gdxAct++] != NULL);
		{}
//		cout << "gx = " << gdxAct<< " x= " << x << '\n';
		v[x].gx = --gdxAct;
		return gdxAct;
	}
//	cout << "gx S= " << v[x].gx<< " x= " << x << '\n';
	return v[x].gx;
}