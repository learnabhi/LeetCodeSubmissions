class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
    int cols[9][9] = {0};
    int blocks[9][9] = {0};
    
    for(int r=0;r<9;r++)
    {
        for(int c=0;c<9;c++)
        {
            if(board[r][c]=='.')continue;
            int num = board[r][c]-'1';
            int for_block = r/3 * 3 + c/3;
            if(cols[num][c]++ || rows[r][num]++ || blocks[for_block][num]++)
                return false;
        }
    }
    
    return true;
    }
};