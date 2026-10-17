class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string i: strs){
            int len = i.size();
            ans = ans + to_string(len)+"@"+i; 
        }
        return ans;
    }

    vector<string> decode(string s) {
        int head = 0;
        vector<string> ans;
        while(head < s.size()){
            int pos = s.find_first_of('@', head);
            int len = stoi(s.substr(head, pos-head));
            head = pos+1;
            ans.push_back(s.substr(head,len));
            head+=len;
        }
        return ans;
    }
};
