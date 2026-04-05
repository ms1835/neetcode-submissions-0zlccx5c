class Solution {
public:
    bool isAlphaNumeric(char ch){
        return (ch>= 'A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9');
    }
    bool isPalindrome(string s) {
        int start=0, end = 0, size = s.length();
        for(int i=0;i<size;i++){
            if(isAlphaNumeric(s[i]))
                s[end++] = tolower(s[i]);
        }
        end--;
        cout<< s<< endl;
        cout<<end<<endl;;
        while(start<=end){
            if(s[start] != s[end]){
                cout<< start << " "<< end<<endl;
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
