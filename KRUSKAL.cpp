///////KRUSKAL /////////////

// Necesitamos un Disjoinset
// ll es typedef long long ll;

typedef pair < ll , ll > pll;

void kruskal(vector < pair < ll , pll > > &EdgeList , ll numberOfNodes)
{
	Disjoinset ds(numberOfNodes);
	sort(EdgeList.begin() , EdgeList.end());
	for(ll i = 0 ; i < EdgeList.size() ; i++)
	{
		if(dc.unir(EdgeList[i].second.first , EdgeList[i].second.second))
		{
			// OPERACION EN CASO DE UNION;
			// dd-- Medir el nuemero de uniones , dd = numero de nodos , cuando dd == 1 hacer
			// mst += EdgeList[i].first Aumenta algo cuado se genera un union
		}
	}
}