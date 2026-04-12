class Solution {
public:

    string encode(vector<string>& strs) {
        string enStr = "";
        for(int i =0 ; i<strs.size();i++){
            enStr+= "||" + strs[i];
        }
        return enStr;
    }

    vector<string> decode(string s) {
        cout << s << endl;
        vector<string> deStr;
        int i = 0;
        while(i < s.length()){
            if(s[i] == '|' && s[i+1] == '|'){
                i+=2;
                string temp = "";
                while((s[i] != '|' || s[i+1] != '|') && i < s.length()){
                    temp+=s[i];
                    i+=1;
                }
                deStr.push_back(temp);
            }
            /* i+=1; */
        }
        return deStr;
    }
};
