class Trie{
    public:
    Trie* mp[26] = {};
    bool isEnd;
    Trie(){
        isEnd = false;
        for(int i=0; i<26; i++){
            mp[i] = nullptr;
        }
    }
};

class WordDictionary {
    Trie* root;
public:
    WordDictionary() {
        root  = new Trie();
    }
    
    void addWord(string word) {
        Trie* temproot = root;
        for(int i=0; i<word.size(); i++){
            int pos = word[i] - 'a';
            if(temproot->mp[pos] == nullptr){
                temproot->mp[pos] = new Trie();
            }
            temproot = temproot->mp[pos];
        }
        temproot->isEnd = true;
    }

    bool dfs(int pos, string& word, Trie* t){
        if(pos == word.size()){
            return t->isEnd;
        }
        int ans = false;
        if(word[pos]!='.'){
            if(t->mp[word[pos]-'a'] == nullptr) return false;
            t = t->mp[word[pos]-'a'];
            ans = dfs(pos+1, word, t);
        }
        else{
            for(int i = 0; i<26; i++){
                if(t->mp[i]!=nullptr){
                    ans = ans||dfs(pos+1, word, t->mp[i]);
                }
            }
        }
        return ans;
    }
    bool search(string word) {
        Trie* temproot = root;
        return dfs(0, word, temproot);
    }
};
