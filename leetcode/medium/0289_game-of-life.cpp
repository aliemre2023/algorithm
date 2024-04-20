// Time Complexity = O(m*n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/game-of-life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                vector<int> neighbour_count(2, 0);
                vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

                for (auto dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if (x >= 0 && x < row && y >= 0 && y < col) {
                        if(board[x][y] == 0 || board[x][y] == 1){
                            neighbour_count[board[x][y]] += 1;
                        }
                        if(board[x][y] == 2){
                            neighbour_count[1] += 1;
                        }
                        if(board[x][y] == 3){
                            neighbour_count[0] += 1;
                        }
                    }
                }

                if(board[i][j] == 1 && neighbour_count[1] < 2){
                    board[i][j] = 2;
                }
                if(board[i][j] == 1 && neighbour_count[1] > 3){
                    board[i][j] = 2;
                }
                if(board[i][j] == 0 && neighbour_count[1] == 3){
                    board[i][j] = 3;
                }     
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] > 1){
                    board[i][j] -= 2;
                }
            }
        }
    }
};