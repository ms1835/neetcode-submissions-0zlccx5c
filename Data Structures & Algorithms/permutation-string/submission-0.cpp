class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) return false;

        unordered_map<char,int> mp1, mp2;
        for(int i=0; i<n1; i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if(mp1 == mp2) return true;

        int left = 0;
        for(int i=n1;i<n2;i++){
            mp2[s2[i]]++;
            mp2[s2[left]]--;
            if(mp2[s2[left]] == 0)
                mp2.erase(s2[left]);
            left++;

            if(mp1 == mp2) return true;
        }
        return false;
    }
};
