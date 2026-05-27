class Solution {
    private:
    vector<int> topoSort(vector<int> adj[]) {
        
    }
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<int, unordered_set<int>> mp;
        for(auto word: words){
            for(auto &ch: word){
                mp[ch-'a'] = {};
            }
        }

        for(int i=0;i<n-1;i++){
            int a = words[i].length();
            int b = words[i+1].length();
            int j=0;
            for(;j<min(a,b);j++){
                if(words[i][j] != words[i+1][j]){
                    mp[words[i][j]-'a'].insert(words[i+1][j]-'a');
                    break;
                }
            }
            if(j == words[i+1].size() && j<words[i].size()) return "";
        }

        vector<int> indegree(26, 0);

        for(auto &[from, to]: mp){
            for(int x: to){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<26;i++){
            if(indegree[i] == 0 && mp.count(i))
                q.push(i);
        }
        string ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans += (curr + 'a');
            for(auto child: mp[curr]){
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }
        return ans.size() == mp.size() ? ans : "";

    }
};
