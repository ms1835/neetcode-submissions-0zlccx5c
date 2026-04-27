class Solution {
    int numberofBits(int num){
        int count = 0;
        while(num){
            count += (num & 1);
            num >>=1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(numberofBits(i));
        }
        return ans;
    }
};
