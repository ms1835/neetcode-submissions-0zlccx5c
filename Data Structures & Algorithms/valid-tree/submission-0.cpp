class Solution {
    bool checkCycle(int index, int parent, vector<vector<int>> adj, vector<bool> &vis) {
        vis[index] = true;
        for(int child: adj[index]){
            if(!vis[child]){
                if(checkCycle(child, index, adj, vis) == true)
                    return true;
            }
            else if(child != parent) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1) return false;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(checkCycle(0, -1, adj, vis)) return false;
        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }
        return true;
    }
};
