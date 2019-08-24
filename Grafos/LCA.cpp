#include <bits/stdc++.h>
#define NOP 20		//Number Of Fathers
using namespace std;

struct nodo
{
	int lv;
	set<int>Fx;
	vector<int>Pb;
	nodo()
	{
		lv = 0;
		Pb.assign(NOP,0);
	}
};

class tree
{
	private:
		vector<nodo> v;
		int root;
	public:	
	tree(int n)
	{
		v.assign(n,nodo());
		root = 0;
	}
	tree(int n , int r)
	{
		v.assign(n,nodo());
		root = r;
		v[r].Pb[0] = r;
	}
	void conect(int x , int y)
	{
		v[x].Fx.insert(y);
		v[y].Fx.insert(x);
		v[y].Pb[0] = x;
	}
	void LV(int x , int l , int p)	//Assign the level for the nodes
	{
//		cout << x << " , " << l << '\n';
		v[x].lv = l;
		set<int>::iterator it;
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
			if(*it != p)
				LV(*it , l + 1 , x);
	}
	void BinaryP()	//Binary Search to get the fhater of the node
	{
		for(int i = 1 ; i < NOP ; i++)
			for(int j = 0 ; j < v.size() ; j++)
				v[j].Pb[i] = v[v[j].Pb[i-1]].Pb[i-1];
	}
	int LCA(int x , int y)		//last common ancestor of two nodes
	{
		int dif = abs(v[x].lv - v[y].lv);
		int p1 , p2;
		if(v[x].lv > v[y].lv)
		{
			p1 = x;
			p2 = y;
		}
		else
		{
			p1 = y;
			p2 = x;
		}
		if(dif > 0)
		{
			for(int i = 0 ; (1<<i) <= dif ; i++)
			{
				if(((1<<i)&dif) != 0)
					p1 = v[p1].Pb[i];
			}
		}
		if(p1 == p2)
			return p1;
		else
		{
			for(int i = NOP - 1 ; i >= 0 ; i--)
			{
				if(v[p1].Pb[i] != v[p2].Pb[i])
				{
					p1 = v[p1].Pb[i];
					p2 = v[p2].Pb[i];
				}
			}
			return v[p1].Pb[0];
		}
	}
};


