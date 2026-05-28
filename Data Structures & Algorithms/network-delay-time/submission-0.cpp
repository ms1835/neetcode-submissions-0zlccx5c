class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &time: times){
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v,t});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        int ans = 0;

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int wt = it.second;
                int adjNode = it.first;
                if(dist[node] + wt < dist[adjNode]){
                    dist[adjNode] = dist[node]+wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
