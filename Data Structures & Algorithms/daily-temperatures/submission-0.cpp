class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size(), curr;
        vector<int> ans(n,0);


        for(int i=0;i<n;i++) {
            curr = temperatures[i];
            while(!st.empty() && curr > st.top().first){
                auto it = st.top();
                st.pop();
                ans[it.second] = i - it.second;
            }
            st.push({curr, i});
        }
        return ans;
    }
};
