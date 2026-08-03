class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSpace = -1;
        for(int i = 0 ; i < s.length() ;i++){
            if(s[i] == ' '){
                lastSpace = i;
            }
        }
        if(lastSpace == s.length() -1){
            int i = s.length() -1;
            int end = -1 , start = -1;
            while(s[i] == ' '){
                i-=1;
            }
            end = i;
            while(s[i] != ' '){
                i-=1;
            }
            start = i;
            return end - start;
        }
        return s.length() - lastSpace -1;
    }
};