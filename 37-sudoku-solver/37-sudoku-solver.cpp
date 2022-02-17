class Solution {
public:
    bool check(vector<vector<char>>& board, char c, int row, int col)
    {
        // for(int i=0;i<9;++i)
        // {
        //     if(board[r][i] == num or board[i][c] == num or board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3])
        //         return false;
        // }
        // return true;
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) 
                return false; 
            
            if(board[row][i] == c) 
                return false; 
            
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false; 
        }
        return true;
    }
    
    bool findSol(vector<vector<char>>& board)
    {
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j] == '.')
                {
                    for(char num='1';num<='9';++num)
                    {
                        if(check(board, num, i, j))
                        {
                            board[i][j] = num;
                            if(findSol(board) == true)
                                return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        findSol(board);
    }
};