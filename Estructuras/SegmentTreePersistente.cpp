struct nodo
{
	ll v;
	struct nodo *l , *r;
	nodo()
	{
		v = 0;
		l = NULL;
		r = NULL;
	}
	nodo(const struct nodo *n)
	{
		if(n!= NULL)
		{
			v = n->v;
			l = n->l;
			r = n->r;
		}else
		{
			nodo();
		}
	}
};



class STP
{
	private:
		vector<nodo> v;

		void update(nodo *a , nodo *b , ll l , ll r , ll x , ll z)
		{
			if((r-l) == 1 && l == x)
			{
				a->v = z;
			}else
			{
				ll m = (l+r)/2;
				if(x < l || x >= m)
				{
					if(b != NULL)
						a->l = b->l;
					else
						a->l = NULL;
				}else
				{
					nodo * n = new nodo();
					a->l = n;
					if(b != NULL)
						update(n,b->l,l,m,x,z);
					else
						update(n,b,l,m,x,z);
				}


				if(x < m || x >= r)
				{
					if(b != NULL)
						a->r = b->r;
					else
						a->r = NULL;
				}else
				{
					nodo * n = new nodo();
					a->r = n;
					if(b != NULL)
						update(n,b->r,m,r,x,z);
					else
						update(n,b,m,r,x,z);
				}
				ll x = 0 , y = 0;
				if(a->l != NULL)
					x = a->l->v;
				if(a->r != NULL)
					y = a->r->v;
				a->v = x+y;
			}
		}
	public:
		STP()
		{
			v.push_back(nodo());
		}
	/*	ll op(nodo *a , ll z)
		{
			a->v += z;
		}
	*/	void updateV(ll l , ll r , ll x , ll z)
		{
			v.push_back(nodo(&v[v.size()-1]));
			update(&v[v.size()-1] , &v[v.size()-2],l,r,x,z);
			
		}
		ll query(ll ver , nodo *a , ll l , ll r , ll i , ll j)
		{
			if(ver > -1 && ver < v.size())
			a = &v[ver];
			if(a == NULL)
			{
				return 0;
			}
			if(j < l || i >= r)
			{
				return 0;
			}
			else if(i <= l && r-1 <= j)
			{
				return a->v;
			}
			else
			{
				ll m = (l+r)/2 , x = 0 , y = 0;
				if(a->l != NULL)
					x = query(-1,a->l,l,m,i,j);
				if(a->r != NULL)
					y = query(-1,a->r,m,r,i,j);
				return x+y;
			}
		}
		ll vr()
		{
			return v.size()-1;
		}
};