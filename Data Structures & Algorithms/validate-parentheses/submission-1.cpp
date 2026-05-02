class Solution {
    unordered_map<char, char> mp = {
        { ')', '('}, 
        {'}', '{'}, 
        {']', '['}
    };
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch: s){
            if(mp.find(ch) != mp.end()){
                if(st.empty())
                    return false;
                else if(mp[ch] != st.top())
                    return false;
                else
                    st.pop();
            }
            else{
                st.push(ch);
            }
        }
        return st.empty();
    }
};
