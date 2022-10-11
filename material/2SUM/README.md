# 2 SUM Problem

Professor: Wladimir Araújo Tavares


Dado um vetor de inteiros $L$. Determine se existe dois  elementos distintos $x$ e $y$ em $L$, tal que $x+y = K$.
A ideia mais trivial seria um algoritmo $\mathcal{O}( n^2 )$, mas podemos fazer melhor. Se o vetor $L$ estiver ordenado podemos resolver esse problema com complexidade $\mathcal{O}( n^2 )$. 

```C++
#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;
pii sum2(vector <int> L, int K){
  pii res = {-1,-1};
  int i = 0, j = j = L.size()-1;
  while(i<j){
    if(L[i]+L[j] > K ) //diminua a soma 
        j--;
    else if(L[i]+L[j] < K ) //aumente a soma
        i++;
    else if(L[i]+L[j] ==K ) {
      res.first = i;
      res.second = j;
      return res;
    }
  }
  return res;
}

int main(){
    vector <int> a;
    int n, K;

    cin >> n >> K;
    a.resize(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    sort( a.begin(), a.end() ); //complexidade O(n log n)

    pii res = sum2(a, K);

    cout << a[res.first] << " " << a[res.second] << endl;

}


/*
Input
7 10
2 4 1 6 3 7 5
Output
3 7
*/
```

Se o vetor L não estiver ordenado, podemos resolver esse problema com complexidade $\mathcal{O}( n \log n )$. Primeiramente, ordenando o vetor e depois aplicando a ideia acima.

## 3sum problem

Seja $L$ um vetor de inteiros. Determine se existe três  elementos distintos $x, y$ e $z$ em $L$, tal que $x+y+z= K$.

Um algoritmo de força bruta simplesmente enumeraria todas $\mathcal{O}( n^3 )$ possiveis escolhas de elementos $x,y$ e $z$ e testaria se $x+y+z = K$. Considerando o vetor ordenado, uma ideia simples seria  para cada par $x,y$ em $L$ e realizar uma busca binária pelo  valor $(K-x-y)$. Neste caso, o algoritmo teria como  complexidade no pior caso $\mathcal{O}( n^2 \log n )$

Uma idéia melhor é reduzir este problema ao problema 2SUM. Para cada valor $x$ em L, determine se existe $y,z$ em $L$ tal que $y+z=K-x$. Este algoritmo tem complexidade de tempo no pior caso $\mathcal{O}( n^2 )$.

```C++
typedef tuple<int, int, int> tiii;

tiii sum3(vector <int> L, int K){
  tiii res = make_tuple(-1,-1,-1);
  for(int i = 0; i < L.size(); i++){
    int x = L[i];
    pii temp = sum2(L, K-x);
    if( temp.first > i){
      res = tie(i, temp.first, temp.second);
      return res;
    }
  }
  return res;
}

/*
Input
7 10
2 4 1 6 3 7 5
Output
1 2 7
*/
```