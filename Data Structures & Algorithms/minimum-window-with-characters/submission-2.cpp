class Solution {
public:
   string minWindow(string s, string t) {
    int l =0  , r = 0;
    unordered_map<char , int> mp1 , mp2;
    int count = 0 , countOrg = 0;
    for(auto i : t) {
        mp1[i]++;
        if(mp1[i] == 1){
            countOrg++;
        }
    }    
    
    string ans = "";
    int minlen = INT_MAX;
    cout << endl << "countOrg : " << countOrg << endl;
    while(r != s.length()){
        cout << endl<< "l :" << l << " r : " << r  << endl;
        mp2[s[r]]++; 
        
        if(mp1[s[r]] != 0){
            if(mp2[s[r]] == mp1[s[r]]){
                count++;
            }
            cout << "equales : " << s[r]  << " count : " << count << endl;
        }
        if(count == countOrg){
            cout << "possable ans : " << endl;
            while(mp2[s[l]] > mp1[s[l]] || mp1[s[l]] == 0){
                mp2[s[l]]--;
                l++;
                cout << "L : : " << l << " moving el" << endl;
            }
            if(minlen >= r - l + 1){
                cout << "find one !" << endl;
                minlen = r - l + 1;
                ans = s.substr(l , minlen);
            }
            else{
                cout << "didn't find one !" << endl;
            }
            count -=1;
            mp2[s[l]]--;
            l+=1;

            cout << "l : " << l << " r : " << r << " ans : " << ans << " minlen : " << minlen<< endl;
        }
        r++;
    }
    if(ans.length() >= t.length()){
        return ans;
    }
    return "";
}
};
