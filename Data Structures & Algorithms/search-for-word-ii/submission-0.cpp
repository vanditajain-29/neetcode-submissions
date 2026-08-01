class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Solution {
public:
    TrieNode* root;

    void insert(string word){
        TrieNode* cur= root;
        for(char c: word){
            if(cur->children.find(c)==cur->children.end()){
                cur->children[c]=new TrieNode();
            }
            cur=cur->children[c];
        }
        cur->word=word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur, vector<string>&res){
        char ch=board[r][c];
        if(cur->children.find(ch)==cur->children.end()) return;

        cur=cur->children[ch];
        if(!cur->word.empty()){
            res.push_back(cur->word);
            cur->word="";
        }

        board[r][c]= '#';

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc= c+dc[i];
            if (nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc]!='#'){
                dfs(board, nr, nc, cur, res);
            }
        }
        board[r][c]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new TrieNode();
        for(string w: words){
            insert(w);
        }

        vector<string> result;

        int row=board.size();
        int col=board[0].size();
        for(int r=0;r<row;r++){
            for(int c=0; c<col; c++){
                dfs(board,r,c,root,result);
            }
        }

        return result;
    }
};
