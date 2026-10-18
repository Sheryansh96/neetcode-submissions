#include<cstring>
class Solution {
public:
    int dp[30001][3];
    int helper(int pos, int state, vector<int>& prices){
        if(pos >= prices.size()) return 0;
        if(dp[pos][state] != -1) return dp[pos][state];
        int ans = 0;
        if(state == 1){
            ans = max(helper(pos, 0, prices)- prices[pos], helper(pos+1, 1, prices));
        }
        else if(state == 0){
            ans = max(helper(pos+1, 1, prices)+ prices[pos], helper(pos+1, 0, prices));
        }
        dp[pos][state] = ans;
        return ans;

    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(0,1,prices);
    }
};