class Solution {
    public int totalFruit(int[] fruits) {
        if(fruits.length <= 1){
            return fruits.length;
        }
        int l = 0 , r = 0 , ans = 0;
        Map<Integer,Integer> mp = new HashMap<>();
        while(r < fruits.length){
            mp.put(fruits[r] , mp.getOrDefault(fruits[r],0) +1);
            if(mp.size() > 2){
                while(l < r && mp.size() > 2){
                    mp.put(fruits[l] , mp.get(fruits[l]) - 1);
                    if(mp.get(fruits[l]) <= 0){
                        mp.remove(fruits[l]);
                    }
                    l+=1;
                }
            }
            ans = Math.max(ans , r - l + 1);
            r+=1;
        }
        return ans;
    }
}