class DisjointSet {
    vector<int> size;
    vector<int> parent;
    public:
    DisjointSet(int n) {
        size.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        parent[u] = findParent(parent[u]);
        return parent[u];
    }

    void unionBySize(int u, int v) {
        int uni_u = findParent(u);
        int uni_v = findParent(v);
        if(uni_u == uni_v) return;
        if(size[uni_u] > size[uni_v]){
            parent[uni_v] = uni_u;
        }
        else if(size[uni_u] < size[uni_v]){
            parent[uni_u] = uni_v;
        }
        else{
            parent[uni_u] = uni_v;
            size[uni_v]++;
        }
    }
};

class Solution {
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u,v);
            }
            else{
                ans = edges[i];
            }
        }
        return ans;
    }
};
