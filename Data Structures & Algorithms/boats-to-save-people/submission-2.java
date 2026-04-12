class Solution {
    public int numRescueBoats(int[] people, int limit) {
        if(people.length <= 1){
            return people.length;
        }
        List<Integer> p = Arrays.stream(people) 
                             .boxed()      
                             .collect(Collectors.toList());
        Collections.sort(p); 
        int l = 0 , r =people.length-1;
        int boats = 0;
        while(/* l < people.length && r >= 0 &&  */l <= r){
            if(p.get(r) == limit){
                boats+=1;
                r-=1;
            }
            else if(p.get(r) + p.get(l) <= limit){
                boats+=1;
                r-=1;
                l+=1;
            }
            else{
                boats+=1;
                r-=1;
            }
        }

        return boats;
    }
}