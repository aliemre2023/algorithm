class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> >& matrix) {

        int minval = -239587;

        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;

        int x = 0; 
        int y = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool cont = true;
        while(cont){
            cout << x << " " << y << "\n";
            while(y < matrix[0].size() && matrix[x][y] != minval){
                res.push_back(matrix[x][y]);
                matrix[x][y] = minval;
                y++;
            }
            x++; y--;
            if (x >= rows || y >= cols || x < 0 || y < 0 || matrix[x][y] == minval) break;
        
            cout << x << " " << y << "\n";
            while(x < matrix.size() && matrix[x][y] != minval){
                res.push_back(matrix[x][y]);
                matrix[x][y] = minval;
                x++;
            }
            x--; y--;
            if (x >= rows || y >= cols || x < 0 || y < 0 || matrix[x][y] == minval) break;

            cout << x << " " << y << "\n";
            while(y >= 0 && matrix[x][y] != minval){
                res.push_back(matrix[x][y]);
                matrix[x][y] = minval;
                y--;
            }
            x--; y++;
            if (x >= rows || y >= cols || x < 0 || y < 0 || matrix[x][y] == minval) break;
        
            cout << x << " " << y << "\n";
            while(x >= 0 && matrix[x][y] != minval){
                res.push_back(matrix[x][y]);
                matrix[x][y] = minval;
                x--;
            }
            x++; y++;
            if (x >= rows || y >= cols || x < 0 || y < 0 || matrix[x][y] == minval) break;
        }

        return res;
    }
};