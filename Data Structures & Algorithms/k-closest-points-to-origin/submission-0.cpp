class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int> >> pq;

        for(auto it: points){
            int dist = pow(it[0],2) + pow(it[1],2);
            pq.push({dist, it});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
