class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0 , r =0 , ans =0 ;
        unordered_map<char,int> mp;
        while(r < s.length()){
            if(mp[s[r]] > 0){
                while(mp[s[r]] > 0 && l < r){
                    mp[s[l]]-=1;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    l+=1;
                }
            }
            mp[s[r]]+=1;
            ans = max(ans , r - l + 1);
            r+=1;
        }
        return ans;
    }
};
