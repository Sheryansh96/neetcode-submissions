class TimeMap {
public:
    map<string, vector<pair<int,string>>> mp;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";
        const auto& v = it->second;
        int n = v.size();
        int lo = 0;
        int hi = n-1;
        int ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int t = v[mid].first;
            string val = v[mid].second;
            if( t <= timestamp){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans == -1 ? "" : v[ans].second;
    }
};
