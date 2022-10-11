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


int main(){
    vector <int> a;
    int n, K;

    cin >> n >> K;
    a.resize(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    sort( a.begin(), a.end() ); //complexidade O(n log n)

    tiii res = sum3(a, K);

    cout << a[get<0>(res)] << " " << a[get<1>(res)] << " " << a[get<2>(res)] << endl;

}


/*
Input
7 10
2 4 1 6 3 7 5
Output
1 2 7
*/