class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = grumpy.length;
        int l = 0 , r = 0;
        int maxL = 0 , maxR = 0;
        int not = 0 , maxNot = 0, ans = 0;
        
        if(minutes >= n){
            for(int i:customers){
                ans+=i;
            }
            return ans;
        }
        for(int i = 0 ; i<minutes ;i++){
            if(grumpy[i] == 1){
                not += customers[i];
            }
            r+=1;
        }
        maxNot = not;
        maxR = r;
        while(r < n){
            if(grumpy[r] == 1){
                not+=customers[r];
            }
            if(grumpy[l] == 1){
                not-=customers[l];
            }
            r+=1;
            l+=1;
            if(not > maxNot){
                maxNot = not;
                maxL = l;
                maxR = r;
            }
        }

        /* for(int i = maxL;i < maxR ;i++){
            grumpy[i] = 0;
        } */

        for(int i = 0 ; i< n; i++){
            if(grumpy[i] == 0 || (i >= maxL && i< maxR)){
                ans+= customers[i];
            }
        }

        return ans;
    }
}