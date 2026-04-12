bool equle(string s1 , string s2){
            if(s1.length() == s2.length()){
                sort(s1.begin(), s1.end());    
                sort(s2.begin(), s2.end());    
                if(s1 == s2){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
       }
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> arr;
       int n = strs.size();
       vector<bool> mem (n , false);
       for(int i =0 ; i< n; i++){
            vector<string> item;
            if(mem[i] == false){
                item.push_back(strs[i]);
                mem[i] = true;
                for(int j = i ; j< n; j++){
                    if(mem[j] == false){
                        if(equle(strs[i] , strs[j])){
                            item.push_back(strs[j]);
                            mem[j] = true;
                        }
                    }
                }
            }
            if(item.size() > 0){
                arr.push_back(item);
            }
       }
       return arr;
    }
};
