class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int k = (i/3)*3 + j/3;
                    char c = board[i][j];
                    if(row[i].count(c) || col[j].count(c) || box[k].count(c)){
                        return false;
                    }
                    row[i].insert(c);
                    col[j].insert(c);
                    box[k].insert(c);
                }
            }
        }
        return true;
    }
};
