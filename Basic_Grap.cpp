#include <set>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

//	Grafo sin ponderacion en la aristas	//

struct nodo		/* Estructura basica de un nodo */
{
	ll v;
	set<ll> Fx;		//Utilizar un vector en lugar de un set hace algunas operaciones constantes pero otras las vuelve lineales respecto al tamaño del set.
	nodo(){v = 0;}
};


class Grap
{
	private:
		vector<nodo> gp;
	public:
		Grap(ll n)
		{
			gp.assign(n , nodo());
		}
		void join(ll x , ll y)
		{
			gp[x].Fx.insert(y);
//			gp[y].Fx.insert(x);	/* Para un grafo vidireccional 	*/
		}
		void setValue(ll x , ll z)
		{
			gp[x].v =z;
		}
		ll getValue(ll x)
		{
			return gp[x].v;	
		}
};


// Grafo ponderado	//

struct nodo
{
	ll v;
	set<pll> Fx;
	nodo(){v = 0;}
};

class Grap
{
	private:
		vector<nodo> gp;
	public:
		Grap(ll n)
		{
			gp.assign(n , nodo());
		}
		void join(ll x , ll y , ll z)
		{
			gp[x].Fx.insert(pll(y,z));
//			gp[y].Fx.insert(pll(x,z));	/* Para un grafo vidireccional 	
		}
		void setValue(ll x , ll z)
		{
			gp[x].v =z;
		}
		ll getValue(ll x)
		{
			return gp[x].v;	
		}
};



