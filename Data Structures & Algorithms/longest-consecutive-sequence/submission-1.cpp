class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        if(nums.size()==0) return 0;
        for(int i : nums){
            s.insert(i);
        }
        auto itr = s.begin();
        int last = *itr;
        itr++;
        int len = 1;
        int ans = 1;
        for(;itr!=s.end();itr++){
            if(*itr-last != 1){
                ans = max(ans,len);
                len = 1;
            }
            else{
                len++;
            }
            last = *itr;
        }
        ans = max(len,ans);
        return ans;
    }
};
