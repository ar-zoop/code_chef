class Solution {
public:
    bool dfs(int i,int j,int word_idx,vector<vector<char>>& board, string& word){
        
        if(i<0 || i>=board.size() || j<0 ||  j>=board[0].size()) return false;
        if(word[word_idx] != board[i][j]) return false;
        if(word_idx==word.length()-1) return true;
        char c= board[i][j];
        board[i][j]='#';
        bool res= dfs(i-1,j, word_idx+1,board, word)|| dfs(i+1,j, word_idx+1,board, word)|| dfs(i,j-1, word_idx+1,board, word)|| dfs(i,j+1, word_idx+1,board, word);
        board[i][j] = c;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i <board.size();i++){
            for(int j=0;j <board[i].size(); j++){
                if(word[0]==board[i][j]  && dfs(i,j,0,board, word)){
                    return true;
                }
            }
        }
        return false;
    }    
};