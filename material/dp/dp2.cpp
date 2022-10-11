#include "bits/stdc++.h"
#define MAXN 20
using namespace std;

int dp[MAXN];

int num_palavra(int n){
    
    if( dp[n] != -1)
        return dp[n];
    else{
        dp[n] = 2*num_palavra(n-1) + 2*num_palavra(n-2);
        return dp[n];
    }
}

int main()
{
	int n;
    cin >> n;
    memset(dp, -1, sizeof(dp) );
    dp[1] = 3;
    dp[2] = 8;
    cout << num_palavra(n) << endl;
    return 0;
}
