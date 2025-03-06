class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            long long size = (grid.size())*(grid[0].size());
            long long n = (size*(size+1))/2;
            long long nn = (size)*(size+1)*((2*size)+1)/6;
    
            long long grid_n = 0;
            long long grid_nn = 0;
            for(long long i = 0; i < grid.size(); i++){
                for(long long ii = 0; ii < grid[0].size(); ii++){
                    grid_n += grid[i][ii];
                    grid_nn += grid[i][ii]*grid[i][ii];
                }
            }
    
            //cout << nn << " " << n << "\n";
            //cout << grid_nn << " " << grid_n << "\n";
    
            long long x2_y2 = grid_nn - nn;
            //cout << x2_y2 << "\n";
            long long x_y = grid_n - n;
            //cout << x_y << "\n";
            long long xty = x2_y2 / x_y;
            //cout << xty << "\n";
            //cout << x_y << " " << xty <<"\n"; 
    
            int fir = (xty - x_y) / 2;
            int sec = (xty + x_y) / 2;
    
            vector<int> res = {};
            if(grid_n > n){
                res.push_back(max(fir,sec));
                res.push_back(min(fir,sec));
            }
            if(grid_n < n){
                res.push_back(min(fir,sec));   
                res.push_back(max(fir,sec));
            }
      
            return res;
    
        }
    };