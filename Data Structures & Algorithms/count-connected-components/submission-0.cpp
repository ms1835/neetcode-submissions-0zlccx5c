class Solution {
    private:
    void dfs(int index, vector<int> adj[], vector<bool> &vis) {
        vis[index] = true;
        for(auto child: adj[index]){
            if(!vis[child])
                dfs(child, adj, vis);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<int> adj[n];
        vector<bool> vis(n, false);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};
