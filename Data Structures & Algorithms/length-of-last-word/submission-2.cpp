class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 1 && s[0] != ' '){
            return 1;
        }
        int start = -1 , end = -1;
        int i = s.length() -1;
        while(i >= 0 && s[i] == ' '){
            i-=1;
        }
        end = i;
        while(i >= 0 && s[i] != ' '){
            i-=1;
        }
        start = i;
        return end - start ;
    }
};