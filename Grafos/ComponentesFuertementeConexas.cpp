#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

///////////PLANTILLA//////////////////

struct nodo				
{
	ll x,e,s,y;
	ll cp;
	set<ll> Fx;
	nodo():x(-1),y(-1),cp(-1),e(0),s(0){}
};

class Graph
{
	private:
		ll idMax , z;		//Used for not repeat conexed componets id
		stack<ll> pila;

	public:
	vector<nodo> v;
	Graph(ll n)			//Constructor
	{
		v.assign(n,nodo());
		idMax = 0;
		z = 0;
	}
	void conect(ll x , ll y)	//Conect 2 nodes with one edge
	{
		v[x].Fx.insert(y);
		v[x].s++;
		v[y].e++; 
	}

	ll CFC(ll x , ll &y)			// Strong Conex componets from x node
	{
		ll aux;
		if(v[x].x == -1)
		{
			v[x].x = y;
			v[x].y = y;
		}else
			return v[x].y;
		pila.push(x);
		set<ll>::iterator it = v[x].Fx.begin();
		while(it != v[x].Fx.end())
		{
			v[x].y = min(v[x].y,CFC(*it,++y));
			it++;
		}
		aux = v[x].y;
		if(v[x].x == v[x].y)
			z++;
		while(v[x].x == v[x].y && !pila.empty())
		{
			v[pila.top()].cp = z-1;
			v[pila.top()].y = INF;
			pila.pop();
		}
		return aux;
	}

	Graph DAG()
	{
		idMax = -1;
		z = 0;
		for(int i = 0 ; i < v.size() ; i++)			//Make a Strong Conex Componets for all separated subGraphs
			if(v[i].y == -1)
				CFC(i,++idMax);
		
		Graph gn(z);
		set<ll>::iterator it;
		for(int i = 0 ; i < v.size() ; i++)		//Conect the graph
		{
			it = v[i].Fx.begin();
			while(it != v[i].Fx.end())
			{
				if(v[i].cp != v[*it].cp)
					gn.conect(v[i].cp,v[*it].cp);
				it++;
			}
		}
		return gn;
	}

};

componentes fuertemente conexas

int main()
{_C
	ll m, n, a, b;
	cin >> m >> n;
	Graph gp(m);
	forn
	{
		cin >> a >> b;
		gp.conect(a,b);
	}
	Graph g2 = gp.DAG();

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}