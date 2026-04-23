class Solution {
    unordered_set<int> st;
public:
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(st.find(n) != st.end())
            return false;
        int digit, res = 0;
        st.insert(n);
        while(n){
            digit = n % 10;
            res += (digit*digit);
            n/=10;
        }
        return isHappy(res);
    }
};
