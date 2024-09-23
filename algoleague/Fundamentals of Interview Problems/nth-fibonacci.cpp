//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
 
// Finds nth fibonacci number
ll fib(ll f[], ll n)
{
    // 0th and 1st number of
    // the series are 0 and 1
    f[0] = 0;
    f[1] = 1;
 
    // Add the previous 2 numbers 
    // in the series and store 
    // last digit of result
    for (ll i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 10;
 
    return f[n];
}
 
// Returns last digit of n'th Fibonacci Number
int findLastDigit(ll n)
{
    ll f[60] = {0};
 
    // Precomputing units digit of  
    // first 60 Fibonacci numbers
    fib(f, 60);
 
    return f[n % 60];
}
int main() {
// write your code here

    ll n; cin >> n;
    cout << findLastDigit(n);

    

	return 0;
}
