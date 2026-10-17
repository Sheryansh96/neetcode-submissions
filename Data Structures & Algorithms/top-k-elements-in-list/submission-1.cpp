class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }
        for(auto i: mp){
            pq.push({i.second, i.first});
        }
        vector<int> ans;
        while(k--){
            auto i = pq.top();
            pq.pop();
            ans.push_back(i.second);
        }
        return ans;
    }
};
