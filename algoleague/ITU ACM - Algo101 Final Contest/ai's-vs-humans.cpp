// Question Link = https://algoleague.com/contest/itu-acm-algo101-final-contest/problem/ais-vs-humans/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int x; 
    cin >> x;
    vector<pair<char, int>> arr;
    for(int i = 0; i < x; i++){
        char c;
        cin >> c;
        arr.push_back({c, 0});
    }
    
    int Aholder = 0;
    int Hholder = 0;
    
    while(true){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i].second != 1){
                if(arr[i].first == 'A' && Hholder == 0){
                    Aholder++;
                }
                else if(arr[i].first == 'H' && Aholder == 0){
                    Hholder++;
                }
                else if(arr[i].first == 'A' && Hholder > 0){
                    arr[i].second = 1;
                    Hholder--;
                }
                else if(arr[i].first == 'H' && Aholder > 0){
                    arr[i].second = 1;
                    Aholder--;
                }
            }
        }
        int Acount = 0;
        int Hcount = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i].second == 0 && arr[i].first == 'A'){
                Acount++;
            }
            if(arr[i].second == 0 && arr[i].first == 'H'){
                Hcount++;
            }
        }
        if(Acount == 0){
            cout << "Victory!";
            break;
        }
        if(Hcount == 0){
            cout << "Extinction!";
            break;
        }
        
        
    }
    
    
	return 0;
}
