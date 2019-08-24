bool BPC(vector<nodo> &v , ll i)
{
	bool bip = true;
	queue< int > cola;
	cola.push(i);
	v[i].color = 0;
	set<int>::iterator it;
	while(!cola.empty())
	{
		int aux = cola.front();
		cola.pop();
		for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
		{
			if(v[(*it)].color == -1)
			{
				v[(*it)].color = 1 - v[aux].color;
				cola.push((*it));
			}else if (v[(*it)].color == v[aux].color)
				bip = false;
		}
	}
	return bip;
}