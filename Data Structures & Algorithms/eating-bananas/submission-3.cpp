class Solution {
public:
    bool canEeat(vector<int>& piles, int h, int k){
    int time = 0;
    for(int i = 0; i < piles.size(); i++){
        time += ceil((double)piles[i]/k);
        if(time > h) {return false;}
    }
    return true;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int k = 0;
    sort(piles.rbegin(), piles.rend());   
    int l , r ;
    r = *max_element(piles.begin() , piles.end());
    l = 1;
    k = l + (r - l)/2;

    /* int prevK = 0; */
    while(l < r){
        if(canEeat(piles, h, k)){
            /* prevK = k; */
            r = k;
        }else{
            /* if(prevK != 0){
                return prevK;   
            } */
            l = k + 1;
        }
        k = l + (r - l)/2;
    }
    return k;
}
};
