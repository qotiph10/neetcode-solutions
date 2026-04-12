class Solution {
    public int[] replaceElements(int[] arr) {
        int []ans = new int[arr.length];
        int max = -1;
        for(int i = arr.length - 1 ; i >= 0 ; i--){
            if(max == -1){
                ans[i] = -1;
                max = arr[i];
                continue;
            }
            ans[i] = max;
            max = Math.max(max , arr[i]);
        }

        return ans;
    }
}