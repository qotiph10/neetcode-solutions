class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    unordered_map <char , int> map1 , map2;
    for(int i =0 ; i < s1.length() ;i++){
        map1[s1[i]]++;
    }  
    int l =0 , r = 0;
    while(r < s2.length()){
        map2[s2[r]]++;
        if(r - l + 1 == s1.length()){
            if(map1 == map2){
                return true;
            }
            map2[s2[l]]--;
            if(map2[s2[l]] == 0){
                map2.erase(s2[l]);
            }
            l++;
        }
        r++;
    }
    return false;
}
};
