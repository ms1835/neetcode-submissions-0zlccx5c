class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    bool unionSet(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return false;
        if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int,int>>> edges;
        int n = points.size();
        DSU ds(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> a = points[i];
                vector<int> b = points[j];
                int dist =  abs(a[0]-b[0]) + abs(a[1]-b[1]);
                edges.push_back({dist,{i,j}});
            }
        }
        sort(edges.begin(), edges.end());
        int ans = 0;

        for(auto edge: edges){
            int u = edge.second.first;
            int v = edge.second.second;
            int wt = edge.first;
            if(ds.unionSet(u, v))
                ans += wt;
        }
        return ans;
    }
};
