class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character,Integer> mp1 = new HashMap<>();
        Map<String,Integer> mp2 = new HashMap<>();

        StringBuilder p1 = new StringBuilder();
        StringBuilder p2 = new StringBuilder();

        int c = 1;
        for(int i = 0 ; i < pattern.length();i++){
            if(mp1.get(pattern.charAt(i)) == null){
                mp1.put(pattern.charAt(i) , c);
                c+=1;
            }
            p1.append(mp1.get(pattern.charAt(i)));
        }

        c = 1;
        String []sstr = s.split(" ");
        for(int i = 0 ; i<sstr.length;i++){
             if(mp2.get(sstr[i]) == null){
                mp2.put(sstr[i], c);
                c+=1;
            }
            p2.append(mp2.get(sstr[i]));
        }

        String pat1 = p1.toString();
        String pat2 = p2.toString();

        /* System.out.print() */
        return pat1.equals(pat2) ? true : false ;
    }
}