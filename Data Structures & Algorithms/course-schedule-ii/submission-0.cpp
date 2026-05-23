class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(auto it: adj[top]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(numCourses == ans.size()) return ans;
        return {};
    }
};
