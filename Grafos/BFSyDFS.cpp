#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<30
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

struct nodo
{
	int x;
	bool visitado;
	set<int> Fx;
	set<int>::iterator it;
	nodo():x(INF),visitado(false),it(NULL){}
};

class Grafo
{
	private:
		vector<nodo> v;
	public:
		Grafo(int n)
		{
			v.assign(n,nodo());
		}
		void conect(int x , int y)
		{
			v[x].Fx.insert(y);
			v[y].Fx.insert(x);
		}
		int BFS(int x)
		{
			queue<int> cola;
			cola.push(x);
			int aux;
			v[x].x = 0;
			v[x].visitado = true;
			set<int>::iterator it;
			while(!cola.empty())
			{
				aux = cola.front();
				cola.pop();
				
				for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
				{
					if(v[*it].visitado == true)
						continue;
					v[*it].visitado = true;
					cola.push(*it);
					v[*it].x = v[aux].x+1;
				}
			}
		}

		int DFSIterativa(int x)
		{
			stack<int> pila;
			pila.push(x);
			int aux;
			v[x].x = 0;
			v[x].it = v[x].Fx.begin();
			set<int>::iterator it;
			while(!pila.empty())
			{
				aux = pila.top();
				v[aux].visitado = true;
				if(v[aux].it == v[aux].Fx.end())
					pila.pop();
				else
				{
					if(!v[*v[aux].it].visitado)
					{
						pila.push(*v[aux].it);
						v[*v[aux].it].it = v[*v[aux].it].Fx.begin();
						v[*v[aux].it].x = v[aux].x+1;
					}
					v[aux].it++;
				}
			}
		}
		void DFS(int x , int y)
		{
			v[x].x = y;
			v[x].visitado = true;
			set<int>::iterator it;
			for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
			{
				if(!v[*it].visitado)
					DFS(*it,y+1);
			}
			return;
		}

		void imprimir()
		{
			for(int i = 0 ; i < v.size() ; i++)
				cout << i << ' ' << v[i].x << '\n';
		}	
};


int main()
{_C
	ll n , m , a , b;
	cin >> n >> m;
	Grafo g1(n);
	Grafo g2(n);
	while(m--)
	{
		cin >> a >> b;
		g1.conect(a,b);
		g2.conect(a,b);

	}
	g1.DFSIterativa(0);
	g2.DFS(0,0);
	g1.imprimir();
	cout << "\n\n";
	g2.imprimir();
	#ifdef LOCAL
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}