// Question Link = https://algoleague.com/contest/algorithm-program-2023-2024-fall-advanced-week-4-contest/problem/inzvac/detail

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long MOD = (1e9 + 7);
	// write your code here
	
	long long n; 
	cin >> n; 
	vector<char> word;
	vector<long long> arr;
    for(long long i = 0; i < n; i++){
        char x; cin >> x;
        word.push_back(x);
        arr.push_back(0);
    }
    
    for(long long i = word.size()-1; 0 <= i; i--){
        if(word[i] == 'c'){
            arr[i] = 1;
        }
        // inzvac
        else if(word[i] == 'a'){
            for(long long j = i+1; j < word.size(); j++){
                if(word[j] == 'c'){
                    arr[i] += arr[j];
                }
            }
        }
        else if(word[i] == 'v'){
            for(long long j = i+1; j < word.size(); j++){
                if(word[j] == 'a'){
                    arr[i] += arr[j];
                }
            }
        }
        else if(word[i] == 'z'){
            for(long long j = i+1; j < word.size(); j++){
                if(word[j] == 'v'){
                    arr[i] += arr[j];
                }
            }
        }
        else if(word[i] == 'n'){
            for(long long j = i+1; j < word.size(); j++){
                if(word[j] == 'z'){
                    arr[i] += arr[j];
                }
            }
        }
        else if(word[i] == 'i'){
            for(long long j = i+1; j < word.size(); j++){
                if(word[j] == 'n'){
                    arr[i] += arr[j];
                }
            }
        }
        else{
            continue;
        }
        arr[i] = arr[i] % MOD;
    }
    long long res = 0;
    
    for(long long i = 0; i < arr.size(); i++){
        if(word[i] == 'i'){
            res = res % MOD;
            res += arr[i];
            
        }
    }
    cout << res % MOD;
    
    
    
	return 0;
}