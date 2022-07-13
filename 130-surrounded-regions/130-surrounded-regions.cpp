class Solution {
public:
    bool isValid(int i,int j, vector<vector<char>>& board){
        return (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == 'O');
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(!isValid(i,j,board))
            return ;
        
        board[i][j] = '#';
        
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size() , n = size(board[0]);
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i*j == 0 || i == m - 1 || j == n -1){
                    if(board[i][j] == 'O'){
                        dfs(board,i,j);
                    }
                }
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};