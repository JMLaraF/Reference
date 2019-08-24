#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define ERR 0.00000001
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;


struct point
{
	ld x , y;
	point(){x=0;y=0;}
	point(ld a , ld b){x=a;y=b;}
	point(const point &p){x = p.x; y = p.y;}
	struct point &operator +=(const point &p2) 
	{
		x += p2.x;
		y += p2.y;
		return *this;
	}
	struct point &operator -=(const point &p2) 
	{
		x -= p2.x;
		y -= p2.y;
		return *this;
	}
	bool operator ==(const point &p2)
	{
		return (fabs(x - p2.x) <= ERR && fabs(y - p2.y) <= ERR);
	}

	bool operator <(const point &p2) { return ((x < p2.x) || (x == p2.x && y < p2.y));}
	bool operator <=(const point &p2) { return ((x < p2.x) || (x == p2.x && y <= p2.y));}
	bool operator >(const point &p1) { return ((p1.x < x) || (p1.x == x && p1.y < y));}
	bool operator >=(const point &p1) { return ((p1.x < x) || (p1.x == x && p1.y <= y));}
	ld operator %(const point &p1) {return (x*p1.x + y*p1.y);}
	ld operator ^(const point &p1) {return ((x*p1.y) - (y*p1.x));}

	ld dist(const point p){return hypot(p.x - x , p.y - y);}
	struct point &scale(const ld s){x *= s; y *= s; return *this;}
	ld norm_sq() {return x*x + y*y;}
	double mgt(){return sqrt(norm_sq());}

};

typedef vector<point> poligono;

struct line
{
	point p1 , p2;

	line(){p1 = point() ; p2 = point();}

	line(point _p1 , point _p2)
	{
		p1 = (_p1 <= _p2)? _p1 : _p2;
		p2 = (_p1 <= _p2)? _p2 : _p1;
	}

	ld dist_pto(point p)
	{
		line lx(p1,p2);
		lx.p2 -= lx.p1;
		p -= lx.p1;
		lx.p1 -= lx.p1;
		if(fabs(lx.p2.norm_sq()) <= ERR)
			return sqrt(p.norm_sq());
		ld u = (lx.p2 % p) / (lx.p2.norm_sq());
		point px;
		
		px += lx.p2.scale(u);
		return px.dist(p);
	}
	//////////REVISAR//////////////

	ld dist_Segpto(point p)
	{
//		cout << p.x << " , " << p.y << " | " << p1.x << " , " << p1.y << " | " << p2.x << " , " << p2.y << "\n";
		if(p == p1 || p == p2)
			return 0;
		point px(0,1000);
		point pd1 = p1;
		pd1 -= p;
		point pd2 = p2;
		pd2 -= p;
		bool izq1 = ((px ^ pd1) > 0)? true : false;
		bool izq2 = ((px ^ pd2) > 0)? true : false;
//		cout << izq1 << " {} " << izq2 << '\n';
		if(izq1 != izq2)
			return dist_pto(p);
		else if((px ^ pd1) == 0 && (px ^ pd2) == 0)
			if(p.y >= min(p1.y , p2.y) && p.x <= max(p1.y , p2.y))
				return 0;
			else
				return min(p1.dist(p) , p2.dist(p));	
		else if((px ^ pd1) == 0 && (px ^ pd2) != 0 || (px ^ pd1) != 0 && (px ^ pd2) == 0)
			return dist_pto(p);
		else
		{
//			cout << min(p1.dist(p) , p2.dist(p)) << '\n';
			return min(p1.dist(p) , p2.dist(p));
		}
	}

	///////////////////////////////////////////////////
	int interSgSg(line ln)
	{
		point px = p2 , px2 = ln.p1;
		px -= p1;
		px2 -= p1;
		ld sg1 = (px ^ px2);
		px2 = ln.p2;
		px2 -= p1;
		ld sg2 = (px ^ px2);
		px = ln.p2;
		px -= ln.p1;
		px2 = p1;
		px2 -= ln.p1;
		ld sg3 = px ^ px2;
		px2 = p2;
		px2 -= ln.p1;
		ld sg4 = px ^ px2;
	//	cout << sg1 << " , " << sg2 << " , " << sg3 << " , " << sg4 << " SG\n";
		if(((sg1 > 0 && sg2 < 0) && ((sg3 >= 0 && sg4 <= 0) || (sg3 <= 0 && sg4 >= 0))) || ((sg1 < 0 && sg2 > 0) && ((sg3 >= 0 && sg4 <= 0) || (sg3 <= 0 && sg4 >= 0))) || ((sg1 == 0 || sg2 == 0) && ((sg3 > 0 && sg4 < 0) || (sg3 < 0 && sg4 > 0))))
			return 0;
		else if (sg1 < 0 && sg2 < 0)
			return 1;
		else if (sg1 > 0 && sg2 > 0)
			return -1;		
		else
			return -2;
	}
};

// Overloading operators

point operator +(point p1 , const point &p2) {return p1 += p2;} 
point operator -(point p1 , const point &p2) {return p1 -= p2;}

bool sortpoints(const point &p1 , const point &p2) { return ((p1.y < p2.y) || (p1.y == p2.y && p1.x < p2.x));}
bool grahamSort(point &p1 , point &p2)
{
	point px(500,0);
	return ((acos((px % p1)/((p1.mgt())*500)) < acos((px % p2)/(p2.mgt()*500))) || ((acos((px % p1)/(p1.mgt()*500)) == acos((px % p2)/(p2.mgt()*500))) && p1.mgt() > p2.mgt()));
}

// Funciones.
poligono grahamScan (poligono v)
{
	if(v.size() < 2)
		return poligono();
	sort(v.begin() , v.end() , sortpoints);
	point px = v[0] , pxx = v[0];
	for(int i = 1 ; i < v.size() ; i++)
		v[i] -= v[0];
	v[0] -= v[0];
	sort(v.begin() + 1 , v.end() , grahamSort);
	poligono ans;
	ans.push_back(v[0] + pxx);
	ans.push_back(v[1] + pxx);
	px = v[0];
	point py = v[1] , pz;
	while((py^v[2]) == 0)
		v.erase(v.begin() + 2);
	for(int i = 2 ; i < v.size() ; i++)
	{
		pz = v[i];
		if(((pz - py)^(px - py)) > 0)
		{
			ans.push_back(pz + pxx);
			px = py;
			py = pz;
		}
		else if(((pz - py)^(px - py)) < 0)
		{
			ans.pop_back();
			px = ans[ans.size() - 2] - pxx;
			py = ans[ans.size() - 1] - pxx;
			i--;
		}else
		{
//			ans.pop_back();
			ans.push_back(pz + pxx);
		}
	}
	return ans;
}

ld areaPoligono(poligono &v)
{
	ld area = 0;
		for (int i = 1; i <= v.size(); ++i)
		{
			area += v[i - 1] ^ v[i%v.size()];
		}

  return fabs(area) / 2.0;
}

ld perimetroPoligno(poligono &v)
{
	ld p = 0;
//	if(v.size() == 2)
//		return	(v[1] - v[1]).mgt();
	for(int i = 1 ; i <= v.size() ; i++)
		p += (v[i%v.size()] - v[i-1]).mgt();
	return fabs(p);
}