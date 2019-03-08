#include <bits/stdc++.h>
#define INF (ll)1<<62
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;

struct nodo
{
	ll dist , padre;
	bool encola;
	set<pll> Fx;
	nodo()
	{
		dist = INF;
		padre = -1;
		encola = false;
	}
};

bool bellmanFord(vector<nodo> &v , ll x)
{
	ll aux;
	set<pll>::iterator it;
	queue<ll> cola;
	cola.push(x);
	v[x].dist = 0;
	v[x].encola = true;
	vector<ll> procesados (v.size() , 0);
	while(!cola.empty())
	{
		aux = cola.front() , cola.pop();
		v[aux].encola = false;
		if(++procesados[aux] == v.size())
			return true;
		for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
		{
			if(v[it->first].dist > v[aux].dist + it->second)
			{
				v[it->first].dist = v[aux].dist + it->second;
				if(!v[it->first].encola)
					cola.push(it->first);
				v[it->first].encola = true;	
			}
		}
	}
	return false;
}
int main()
{
	
	return 0;
}