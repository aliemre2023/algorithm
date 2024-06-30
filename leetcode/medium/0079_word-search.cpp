class Solution {
public:
    vector<int> around_creator(vector<vector<int>>& board, vector<int> c) {
        vector<int> res;
        int i = c[0], j = c[1];

        int x1 = i - 1, y1 = j;
        int x2 = i, y2 = j + 1;
        int x3 = i + 1, y3 = j;
        int x4 = i, y4 = j - 1;

        if ((x1 >= 0 && x1 < board.size()) && (y1 >= 0 && y1 < board[0].size())) res.push_back(board[x1][y1]);
        if ((x2 >= 0 && x2 < board.size()) && (y2 >= 0 && y2 < board[0].size())) res.push_back(board[x2][y2]);
        if ((x3 >= 0 && x3 < board.size()) && (y3 >= 0 && y3 < board[0].size())) res.push_back(board[x3][y3]);
        if ((x4 >= 0 && x4 < board.size()) && (y4 >= 0 && y4 < board[0].size())) res.push_back(board[x4][y4]);

        return res;
    }

    bool helper(vector<vector<char>>& board, string word, int word_idx, int i, int j) {
        if (word_idx == word.length()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[word_idx]) return false;

        char temp = board[i][j];
        board[i][j] = ' '; // visited char

        bool res = helper(board, word, word_idx + 1, i - 1, j) ||
                   helper(board, word, word_idx + 1, i + 1, j) ||
                   helper(board, word, word_idx + 1, i, j - 1) ||
                   helper(board, word, word_idx + 1, i, j + 1);

        board[i][j] = temp; // restore for different start
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
