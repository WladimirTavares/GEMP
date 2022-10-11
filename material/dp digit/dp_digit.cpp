
#include "bits/stdc++.h"
using namespace std;
#define max_digit 20
#define max_sum max_digit*9

long long dp[max_digit][max_sum][2];


long long digitSum(int idx, int sum, int tight,
						vector <int> &digit)
{
	
    

    if (idx == -1)
	    return sum;

	if (dp[idx][sum][tight] != -1)
		return dp[idx][sum][tight];

	
    if(!tight){
        long long ret = 0;

        for (int i = 0; i <= 9 ; i++)
        {
            
            ret += digitSum(idx-1, sum + i, 0, digit); 
        }
        return dp[idx][sum][0] = ret;
    }else{

        
        long long ret = digitSum( idx-1, sum + digit[idx], 1, digit);

        for(int i = 0; i < digit[idx]; i++){
            
            ret += digitSum( idx-1, sum + i, 0, digit);
        }

        return dp[idx][sum][1] = ret;

    }

	
}

void decrement(string & a){

    for(int i = a.size()-1; i >= 0; i--){
        if( a[i] >= '1' && a[i] <= '9'){
            a[i] = a[i] - 1;
            break;
        }else{
            a[i] = '9';
        }
    }

}

vector <int >getDigits(string ss){
    vector <int> digits;
    digits.resize( ss.size() ); 
    int pos = ss.size()-1;
    for(int i = 0; i < ss.size(); i++){
        digits[pos--] = ss[i] - '0';
    }
    return digits;
}


int rangeDigitSum(string a, string b)
{
	vector<int> digitA;
    decrement(a);
	digitA = getDigits(a);
    memset(dp, -1, sizeof(dp));
    long long ans1 = digitSum(digitA.size()-1, 0, 1, digitA);

    cout << ans1 << endl;

    vector<int> digitB;
	digitB  = getDigits(b);
	
    memset(dp, -1, sizeof(dp));
    long long ans2 = digitSum(digitB.size()-1, 0, 1, digitB);
	
    cout << ans2 << endl;


    return (ans2 - ans1);
}

long long  sumOfDigits(long long x)
{
    long long sum = 0;
    while (x != 0)
    {
        sum += x %10;
        x   = x /10;
    }
    return sum;
}

long long sumOfDigitsFrom1ToN(long long n)
{
    long long  result = 0; 
 
    
    for (int x = 1; x <= n; x++)
        result += sumOfDigits(x);
 
    return result;
}

int main()
{
	string a, b;    
    getline(cin, a);
    vector<int> digitA;
	digitA = getDigits(a);
    memset(dp, -1, sizeof(dp));
    long long ans1 = digitSum(digitA.size()-1, 0, 1, digitA);
    cout << ans1 << endl;
    return 0;
}
