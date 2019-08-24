#include<vector>

using namespace std;

class Disjoinset
{
	private:
		vector<int> padre, rank;
	public:
		Disjoinset(int n)
		{
			rank.assign(n,0);
			for (int i = 0; i < n; ++i)
				padre.push_back(i);
		}
		int miPadre(int x)
		{
			return (padre[x] == x)? x : (padre[x] = miPadre(x));
		}
		bool estamosJuntos(int x , int y)
		{
			return (miPadre(x) == miPadre(y));
		}
		bool conectar(int a , int b)
		{
			int x = miPadre(a);
			int y = miPadre(b);
			if(x != y)
			{
				if(rank[x] > rank[y])
					padre[y] = x;
				else
				{
					padre[x] = y;
					if(rank[x] == rank[y])
						rank[y]++;
				}
			}
		} 
};



int main()
{
	
	return 0;
}