class Trie{
    public:
        bool isEnd;
        Trie* mp[26] = {};
        Trie(){
            isEnd = false;
            for(int i=0; i<26; i++){
                mp[i] = nullptr;
            }
        }
};

class PrefixTree {
    Trie* root;
public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie* tempRoot = root;
        for(int i = 0; i<word.size(); i++){
            if( tempRoot->mp[word[i]-'a'] == nullptr){
                tempRoot->mp[word[i]-'a'] = new Trie();
            }
            tempRoot = tempRoot->mp[word[i]-'a'];
        }
        tempRoot->isEnd = true;
    }
    
    bool search(string word) {
        Trie* tempRoot = root;
        for(int i = 0 ; i<word.size(); i++){
            if(tempRoot->mp[word[i]-'a'] == nullptr){
                return false;
            }
            tempRoot = tempRoot->mp[word[i]-'a'];
        }
        if(tempRoot->isEnd){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* tempRoot = root;
        for(int i = 0 ; i<prefix.size(); i++){
            if(tempRoot->mp[prefix[i]-'a'] == nullptr){
                return false;
            }
            tempRoot = tempRoot->mp[prefix[i]-'a'];
        }
        return true;
    }
};
