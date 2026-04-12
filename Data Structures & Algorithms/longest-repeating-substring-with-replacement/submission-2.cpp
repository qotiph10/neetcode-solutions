class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char , int> mp;
        int ans = 0 , sum = 0, maxNum = INT_MIN , l =0 , r = 0;
        while(r < s.length()){
            mp[s[r]]+=1;
            sum+=1;
            if(maxNum < mp[s[r]]){
                maxNum = mp[s[r]];
            }

            if(sum - maxNum > k){
                while(sum - maxNum > k && l < r){
                    maxNum = 0;
                    sum-=1;
                    mp[s[l]]-=1;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    for(auto [key , value]:mp){
                        if(value > maxNum){
                            maxNum = value;
                        }
                    }
                    l+=1;
                }
            }
            ans = max(ans , r - l + 1);
            r+=1;
        }
        return ans;
    }
};
