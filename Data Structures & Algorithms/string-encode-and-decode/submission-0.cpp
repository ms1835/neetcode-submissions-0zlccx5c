class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        vector<int> sizes;
        string ans;

        for(auto str: strs){
            sizes.push_back(str.size());
        }
        for(int len: sizes){
            ans += to_string(len) + "," ;
        }
        ans+= "#";
        for(string str: strs){
            ans += str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int> sizes;
        vector<string> ans;

        int i=0;
        while(s[i] != '#'){
            string curr = "";
            while(s[i] != ','){
                curr += s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++;
        for(int len: sizes){
            ans.push_back(s.substr(i, len));
            i+= len;
        }
        return ans;
    }
};
