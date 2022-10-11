#include "bits/stdc++.h"
#define MAXP 100
using namespace std;

double dp[MAXP+1][MAXP+1];

double prob(int i, int j, int n){
    
    if( i == n) return 1.0;
    else if( j == n ) return 0.0;
    else if( dp[i][j] > 0) return dp[i][j];
    else {
        dp[i][j] = 0.5*prob(i+1, j, n) + 0.5*prob(i, j+1, n);
        return dp[i][j];
    }    
}

int main()
{
	int n;
    
    for(int i = 0; i <= MAXP; i++)
        for(int j = 0; j <= MAXP; j++)
            dp[i][j] = -1;

    cout << prob(15,13,20) << endl;

    return 0;
}
