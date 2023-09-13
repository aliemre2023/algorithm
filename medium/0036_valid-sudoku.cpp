// Time Complexity = O(n^3)
// Space Complexity = O(1)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if(board[i][j] != '.') {
                    for(int x = i+1; x < board.size(); x++) {
                        if(board[i][j] == board[x][j]) {
                            return false;
                        }
                    }
                    for(int y = j+1; y < board.size(); y++) {
                        if(board[i][j] == board[i][y]) {
                            return false;
                        }
                    }
                    int row = i / 3;
                    int col = j / 3;
                    int ridx = row * 3;
                    int cidx = col * 3;
                    int count = 0;
                    for(int r = ridx; r < ridx + 3; r++){
                        for(int c = cidx; c < cidx + 3; c++){
                            if(board[i][j] == board[r][c]){
                                count++;
                            }
                        }
                    }
                    if(count > 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
