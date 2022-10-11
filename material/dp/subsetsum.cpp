#include "bits/stdc++.h"
#define MAXN 100
#define MAXSUM 10000

using namespace std;

bool m[MAXN][MAXSUM];
vector <int> a;


int main()
{
	int n, K;
    cin >> n >> K;
    a.resize(n);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    //Caso Base
    m[0][0] = true;
    for(int j = 1; j <= K; j++){
        m[0][j] = false;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= K; j++){
            if( j < a[i])
                m[i][j] = m[i-1][j];
            else
                m[i][j] = m[i-1][j] | m[i-1][j - a[i]]; 
        }
    }
    

    cout << m[n][K] << endl;


    return 0;
}
