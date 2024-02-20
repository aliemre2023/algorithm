#include <iostream>
#include <vector>

using namespace std;
#define int long long


void printGrid(const vector<vector<int> >& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int mac_x, mac_y;
    cin >> mac_y >> mac_x;

    mac_x -= 1;
    mac_y -= 1;

    int mamax = max(m+2, n+2);
    mamax = 100;
    m = mamax;
    n = mamax;
    vector<vector<int> > arr(mamax, vector<int>(mamax, 0)); 
    // düzlemde partler
    pair<int,int> corner1 = make_pair(mac_x, mac_y);; // 2
    corner1.first--;
    corner1.second--;
    pair<int,int> corner2 = make_pair(mac_x, mac_y); // 1
    corner2.first++;
    corner2.second--;
    pair<int,int> corner3 = make_pair(mac_x, mac_y); // 3
    corner3.first--;
    corner3.second++;
    pair<int,int> corner4 = make_pair(mac_x, mac_y); // 4
    corner4.first++;
    corner4.second++;
    bool contn = true;
    while(contn){
        contn = false;
        
        
        if(corner1.first >= 0 && corner1.first < m){
            if(corner1.second >= 0 && corner1.second < n){
                arr[corner1.first][corner1.second] = 1;
                contn = true;
                corner1.first -= 2;
                corner1.second -= 2;
            }
        }
        if(corner2.first >= 0 && corner2.first < m){
            if(corner2.second >= 0 && corner2.second < n){
                arr[corner2.first][corner2.second] = 1;
                contn = true;
                corner2.first += 2;
                corner2.second -= 2;
            }
        }
        if(corner3.first >= 0 && corner3.first < m){
            if(corner3.second >= 0 && corner3.second < n){
                arr[corner3.first][corner3.second] = 1;
                contn = true;
                corner3.first -= 2;
                corner3.second += 2;
            }
        }
        if(corner4.first >= 0 && corner4.first < m){
            if(corner4.second >= 0 && corner4.second < n){
                arr[corner4.first][corner4.second] = 1;
                contn = true;
                corner4.first += 2;
                corner4.second += 2;
            }
        }    
    }

    // fullfillng betweens
// fullfillng betweens
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // 2
            if(arr[i][j] == 1 && i < mac_x){
                if(j < mac_y){
                    int copy_j = j;
                    int copy_i = i;
                    while(arr[0].size() > copy_j+1 && arr[i][copy_j+1] == 0){
                        copy_j++;
                        arr[i][copy_j] = 2;
                    }
                    while(arr.size() > copy_i+1 && arr[copy_i+1][j] == 0){
                        copy_i++;
                        arr[copy_i][j] = 2;
                    }
                }
            }
            // 1 
            if(arr[i][j] == 1 && i > mac_x){
                if(j < mac_y){
                    int copy_j = j;
                    int copy_i = i;
                    while(arr[0].size() > copy_j+1 && arr[i][copy_j+1] == 0){
                        copy_j++;
                        arr[i][copy_j] = 2;
                    }
                    while(0 <= copy_i-1 && arr[copy_i-1][j] == 0){
                        copy_i--;
                        arr[copy_i][j] = 2;
                    }
                }
            }
            // 3
            if(arr[i][j] == 1 && i < mac_x){
                if(j > mac_y){
                    int copy_j = j;
                    int copy_i = i;
                    while(0 <= copy_j-1 && arr[i][copy_j-1] == 0){
                        copy_j--;
                        arr[i][copy_j] = 2;
                    }
                    while(arr.size() > copy_i+1 && arr[copy_i+1][j] == 0){
                        copy_i++;
                        arr[copy_i][j] = 2;
                    }
                }
            }
            // 4
            if(arr[i][j] == 1 && i > mac_x){
                if(j > mac_y){
                    int copy_j = j;
                    int copy_i = i;
                    while(0 <= copy_j-1 && arr[i][copy_j-1] == 0){
                        copy_j--;
                        arr[i][copy_j] = 2;
                    }
                    while(0 <= copy_i-1 && arr[copy_i-1][j] == 0){
                        copy_i--;
                        arr[copy_i][j] = 2;
                    }
                }
            }
        }
    }







    



    vector<vector<int> > flow;
    for(int i = 0; i < k; i++){
        vector<int> temp;
        int x, y;
        cin >> x >> y;
        temp.push_back(x - 1);
        temp.push_back(y - 1);
        flow.push_back(temp);
    }
    
    arr[mac_x][mac_y] = 0;
    int count = 0;
    for(int i = 0; i < k; i++){
        if(arr[flow[i][1]][flow[i][0]] != 0){  
            count++;
        }
    }
    
    //printGrid(arr);

    cout << count << endl;
    return 0;
}
