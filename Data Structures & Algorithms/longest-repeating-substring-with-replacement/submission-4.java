class Solution {
    char getMax(Map<Character, Integer> mp) {
    if (mp == null || mp.isEmpty()) return '\0'; 

    int max = -1;
    char ans = '\0';

    for (Map.Entry<Character, Integer> entry : mp.entrySet()) {
        if (entry.getValue() > max) {
            max = entry.getValue();
            ans = entry.getKey();
        }
    }

    return ans;
}
    public int characterReplacement(String s, int k) {
        Map<Character,Integer> mp = new HashMap<>();
        int l = 0 , r = 1 , ans = 1;
        char max = s.charAt(0);
        mp.put(max,1);
        while(r < s.length()){
            mp.put(s.charAt(r) , mp.getOrDefault(s.charAt(r) , 0)+1);
            if(mp.get(s.charAt(r)) >= mp.get(max)){
                max = s.charAt(r);
                /* System.out.println("max while increasing:"+max+"->"+mp.get(max)); */
            }
            int length = (r - l + 1);
            if(length - mp.get(max) > k){
               while(l < r && length - mp.get(max) > k){
                    mp.put(s.charAt(l),mp.get(s.charAt(l))-1);
                    l+=1;
                    max = getMax(mp);
                    length = (r - l + 1);
                    /* System.out.println("max while decreasing:"+max+"->"+mp.get(max)); */
               }
            }
            ans = Math.max(ans , length);
            r+=1;
        }

        return ans;
    }
}
