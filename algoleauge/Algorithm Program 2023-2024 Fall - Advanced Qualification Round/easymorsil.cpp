// Question Link = https://algoleague.com/contest/algorithm-program-2023-2024-fall-advanced-qualification-round/problem/easymorsil/

#include <iostream>

using namespace std;

long long greatestOddFactor(long long n){
    
    
    while(n % 4 == 0){
        n = n / 4;
    }
    if(n % 2 == 0) n = n / 2;
    
    return n;
}

int main() {
    long long n;
    cin >> n;
    long long sum = 0;
    
    
    // cift 
    if(n % 2 == 0){
        sum += (n/2) * (n/2);
        
        for(long long i = 2; i <= n; i+= 2){
            sum += greatestOddFactor(i);
        }
    }
    //tek
    else{
        n+=1;
        sum += (n/2) * (n/2);
        
        for(long long i = 2; i < n; i+= 2){
            sum += greatestOddFactor(i);
        }
    }
    cout << sum;
    
    return 0;
}
