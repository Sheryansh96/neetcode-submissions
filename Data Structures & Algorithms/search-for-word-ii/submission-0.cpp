class Trie{
    public:
    bool isEnd;
    Trie* mp[26] = {};
    string word;
    Trie(){
        for(int i =0; i<26; i++){
            mp[i]=nullptr;
        }
        isEnd = false;
        word = "";
    }
};
class Solution {
    Trie* root;
public:
    vector<string> ans;
    void insert(vector<string>& words){
        root = new Trie();
        for(string s: words){
            Trie* temproot = root;
            for(int i=0; i<s.size(); i++){
                if(temproot->mp[s[i]-'a'] == nullptr){
                    temproot->mp[s[i]-'a'] = new Trie();
                }
                temproot = temproot->mp[s[i]-'a'];
            }
            temproot->isEnd = true;
            temproot->word = s;
        }
    }

    void dfs(int x, int y, vector<vector<char>>& board, Trie* t){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == '#') return;
        int pos = board[x][y] - 'a';
        char c = board[x][y];
        if(t->mp[pos] == nullptr) return;
        t = t->mp[pos];
        if(t->isEnd){
            ans.push_back(t->word);
            t->isEnd = false;
        }
        board[x][y] = '#';
        dfs(x+1,y,board,t);
        dfs(x,y+1,board,t);
        dfs(x,y-1,board,t);
        dfs(x-1,y,board,t);
        board[x][y] = c;
        return;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        insert(words);
        for(int i =0; i<board.size(); i++){
            for(int j=0; j<board[i].size();j++){
                if(root->mp[board[i][j] - 'a']!=nullptr){
                    dfs(i,j,board,root);
                }
            }
        }
        return ans;
    }
};
