class TimeMap {
    map<string, vector<pair<string, int>> > mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> data = mp[key];
        int left = 0, right = data.size()-1, mid;
        string ans="";
        while(left <= right){
            mid = left + (right-left)/2;
            if(data[mid].second == timestamp)
                return data[mid].first;
            else if(data[mid].second > timestamp)
                right = mid-1;
            else{
                left = mid+1;
                ans = data[mid].first;
            }
        }
        return ans;
    }
};
