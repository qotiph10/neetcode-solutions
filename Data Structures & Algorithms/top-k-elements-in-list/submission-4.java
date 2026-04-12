class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i =0 ; i<nums.length;i++){
            if(mp.containsKey(nums[i])){
                mp.put(nums[i] , mp.get(nums[i])+1);
            }
            else{
                mp.put(nums[i] , 1);
            }
        } 

        Map<Integer, Integer> sortedByValue = mp.entrySet()
        .stream()
        .sorted(Map.Entry.comparingByValue()) 
        .collect(Collectors.toMap(
            Map.Entry::getKey, 
            Map.Entry::getValue, 
            (e1, e2) -> e1, 
            LinkedHashMap::new 
        ));


    System.out.println(sortedByValue.keySet());
    System.out.println(sortedByValue.values());  
    int[] ans = sortedByValue.keySet().stream()
                .mapToInt(Integer::intValue)                    
                .toArray();


    return Arrays.copyOfRange(ans, ans.length - k , ans.length);
    }
}
