using namespace std;

int n, z;
int sT[4*100000];


void updateElement(int v , int l , int r , int x , int val)	
// v = Nodo actual.
// l = rango a la izquierda que abarcar el nodo. [
// r = rango a derecha que abarcar el nodo. )
// x = posicion a actualizar. 
// val = valor a introducir.
{
	if(x < l || x >= r)
	{
		return;
	}
	if( (r - l) == 1)
	{
		sT[v] += val;
		return;
	}else
	{
		int m = (l+r)/2;
		u(2*v,	l,m ,x,val);
		u(2*v+1,m,r,x,val);
		sT[v] += val;
	}
}
int queryRange(int v , int l , int r , int i , int j)
{
	/*
	V = nodo Actual
	l =  rango a la izquierda que abarca el nodo [
	r = rango a la derecha que abarca el nodo )
	i = rango a la izquierda a consultar [
	j = rango a la derecha a consultar ]
	*/
	if(j < l || i >= r)
	{
		return 0;
	}
	else if(i <= l && r-1 <= j)
	{
		return sT[v];
	}else
	{
		int m = (l+r)/2;
		return (q(2*v , l , m , i , j) + q(2*v+1 , m , r , i , j));
	}
}


//////////// LAZY

int operacion(int iz , int der)
{
	//OPERACION DE ACTUALIZACION PUEDE SER CUALQUIERA;
	return st[iz].first + st[der].first;
}

void push(int v , int l , int r)
{
	//ereda deuda en este caso la deuda
	//se guarda en el second del pair
	if(r-l == 1)
		return;
	int m = (l+r)/2;
	st[2*v].second += st[v].second;
	st[2*v].first += st[v].second*(m-l);	//La operacion puede cambiar , (m-l) es el numero de elementos a actualizar;
	st[2*v+1].second += st[v].second;
	st[2*v+1].first += st[v].second*(r-m);
	st[v].second = 0;
}

void updateRange(int v , int l , int r , int i , int j , int x)
{
	/*
		v = nodo actual
		l =  rango a la izquierda que abarca el nodo [
		r = rango a la derecha que abarca el nodo )
		i = rango a la izquierda a consultar [
		j = rango a la derecha a consultar ]
		x = elemento de actualizacion.
	*/
	push(v , l , r);
	if(j < l || i >= r)	// Si esta fuerra del rango de actualizacion
	{
		return;
	}else if (i <= l && r-1 <= j)	// Si esta totalmente contenido en el rango de actualizacion
	{
		st[v].second += x;
		st[v].first += // OPERACION DE ACTUALIZACION-> (r-l)*x;
	}else 	// Si esta parcialmente contenido en el rango de actualizacion.
	{
		int m = (r+l)/2;
		updateRange(2*v , l , m , i , j , x);
		updateRange(2*v+1 , m , r , i , j , x);
		st[v].first + operacion(2*v , 2*v+1);
	}
	return;
}

int queryElement(int v , int l , int r , int x)
{
	/*
		v = nodo actual
		l = rango a la izquierda que reprecenta el nodo
		r = rango a la derecha que reprecenta el nodo
	*/
	push(v , l , r);
	if(x < l || x >= r) // Si esta fuerra del rango de actualizacion
	{
		return 0;
	}else // Si esta dentro del rango de actualizacion
	{
		if(r-l == 1) // Si esta en el nodo de consulta
		{
			return st[v].first;
		}else
		int m = (r+l)/2;
		return max(queryElement(2*v , l , m , x) , queryElement(2*v+1 , m , r , x));
	}
}

// Mandar llamar R la primera vez con rango + 1 por el uso del intervalo abierto cerrado.
