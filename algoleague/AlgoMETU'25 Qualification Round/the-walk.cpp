//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  
    int q; cin >> q;
    for(int _ = 0; _ < q; _++){
        int n; cin >> n;
        
        
        vector<int> arr1; 
        for(int x = 0; x < n; x++){
            int a; cin >> a;
            arr1.push_back(a);
        }
        vector<int> arr2;
        for(int x = 0; x < n; x++){
            int a; cin >> a;
            arr2.push_back(a);
        }
        
        int tot = 0;
        int i = 0;
        int j = 0;
        while(i < arr1.size() && j < arr2.size()){
            //cout << arr1[i] << " : " << arr2[j] << "\n";
            if(arr1[i] < arr2[j]){
                i++;

            }
            else if(arr1[i] > arr2[j]){
                j++;
    
            }
            else if(arr1[i] == arr2[j]){
                tot += (i+1)*(j+1);
                
                bool in = false;
                if(i+1 < arr1.size() && j+1 < arr2.size() && arr1[i] == arr1[i+1] && arr2[j] == arr2[j+1]){
                    if(i < j){
                        i++;
                    }
                    else{
                        j++;
                    }
                    in = true;
                }
                
                bool in1 = false;
                if(!in && i+1 < arr1.size() && arr1[i] == arr1[i+1]){
                    i++;
                    in1 = true;
                }
                bool in2 = false;
                if(!in && !in1 && j+1 < arr2.size() && arr2[j] == arr2[j+1]){
                    j++;
                    in2 = true;
                }
                if(!in && !in1 && !in2){
                    i++;
                    j++;
                }
            
            }
            //cout << i << ":::" << j << "\n";

        }
        cout << tot << "\n";
        
    }
	return 0;
}
