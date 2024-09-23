//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int idx_left = 0;
    int idx_right = height.size()-1;
    int h_left = height[idx_left];
    int h_right = height[idx_right];
    int width = idx_right - idx_left;

    int area = 0;
    while(width != 0){
        int temp_area;
        
        temp_area = min(h_left, h_right) * width;
        width--;
        if(temp_area > area){
            area = temp_area;
        }

        if(h_left > h_right){
            idx_right--;
            h_right = height[idx_right];
        }
        else{
            idx_left++;
            h_left = height[idx_left];
        }
        width = idx_right - idx_left;
    }

    return area;
}

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    
    int most = maxArea(arr);
    cout << most;
    

	return 0;
}
