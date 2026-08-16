class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        if(asteroids.length <= 1){
            return asteroids;
        }
        Stack<Integer> st = new Stack<>();
        st.push(asteroids[0]);
        for(int i =1 ; i < asteroids.length ;i++){
            int num = asteroids[i];
            if(!st.isEmpty()){
                while(!st.isEmpty()){
                    if(st.peek() > 0 && num < 0){
                        if(Math.abs(st.peek()) > Math.abs(num)){
                            
                            num = 0;
                            break;
                        }
                        else if(Math.abs(st.peek()) < Math.abs(num)){
                            
                            st.pop();
                        }
                        else{
                            
                            st.pop();
                            num = 0;
                            break;
                        }
                    }
                    else{
                        
                        st.push(num);
                        num = 0;
                        break;  
                    }
                }
                if(num != 0){
                    st.push(num);
                }
            }
            else{
                st.push(num);
            }
             
        }
        int size = st.size();
        int ans[] = new int[st.size()];
        int index = 0;
        while (!st.isEmpty()) {
            ans[size - index - 1] = st.pop();
            index++;
        }
        return ans;
    }
}