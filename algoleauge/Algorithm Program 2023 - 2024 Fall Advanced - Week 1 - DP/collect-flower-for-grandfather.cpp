// Question Link =  https://algoleague.com/contest/algorithm-program-2023-2024-fall-advanced-week-1-dp/problem/collect-flowers-for-grandfather/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int r; cin >> r;
	int c; cin >> c;
	vector<vector<int>> arr(r, vector<int>(c));
	
	for(int i = 0; i < r; i++){
	    for(int j = 0; j < c; j++){
	        int x; cin >> x;
	        if(i == 0 && j == 0){
	            arr[i][j] = x;
	        }
	        else if(j == 0){
	            arr[i][j] = arr[i-1][j] + x;
	        }
	        else if(i == 0){
	            arr[i][j] = arr[i][j-1] + x;
	        }
	        else{
	            arr[i][j] = max(arr[i][j-1], arr[i-1][j]) + x;
	        }
	    }
	}
	cout << arr[r-1][c-1];
	
	return 0;
}
