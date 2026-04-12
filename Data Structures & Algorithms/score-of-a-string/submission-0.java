class Solution {
    public int scoreOfString(String s) {
        int sum = 0;
        for(int i =0 ; i< s.length();i++){
            if(i+1 < s.length()){
                int x , y;
                x = s.charAt(i) - '0';
                y = s.charAt(i+1) -'0';
                sum += Math.abs(x - y); 
            }
        }

        return sum;
    }
}