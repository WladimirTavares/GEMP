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