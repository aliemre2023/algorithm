//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int res = 0;
void recursive(int& n, int curr, int& num1, int& num2){
    
    if(curr == n){
        res++;
        return;
    }
    else if(curr > n){
        return;
    }
    else{
        recursive(n, curr+num1, num1, num2);
        recursive(n, curr+num2, num1, num2);
    }
}

int main() {
// write your code here
    int n; cin >> n;
    int num1, num2; cin >> num1 >> num2;
    
    recursive(n, 0, num1, num2);
    cout << res;
    
	return 0;
}
