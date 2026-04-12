class Solution {
public:
    map<char,string> buttons = {{'1',""},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> ans;
    void backtrack(vector<string> arr , int cur, string comp){
        if(cur == arr.size()){
            ans.push_back(comp);
            return;
        }
        for(int i = 0 ; i<arr[cur].size();i++){
                string temp = comp + arr[cur][i];
                cout << "comp:" << temp << endl;
                backtrack(arr , cur+1 , temp);
            }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()){
            return {};
        }

        vector<string>arr;
        for(int i = 0 ; i< digits.length() ;i++){
            arr.push_back(buttons[digits[i]]);
        }
        string temp = "";
        backtrack(arr , 0 , temp);


        return ans;
    }
};
