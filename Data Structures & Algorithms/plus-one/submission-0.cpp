class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), digit,carry=1;
        for(int i=n-1;i>=0;i--){
            digit = digits[i] + carry;
            digits[i] = digit%10;
            carry = digit/10;
        }
        if(carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
