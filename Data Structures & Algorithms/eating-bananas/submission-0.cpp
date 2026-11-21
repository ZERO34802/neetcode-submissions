class Solution {
public:
    int check(int k,vector<int>& piles,int h) {
        int ct = 0;
        for(int i = 0;i < piles.size();i++) {
            if(piles[i]%k == 0)ct += (piles[i]/k);
            else ct += ((piles[i]/k) + 1);
        }
        return ct <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(mid,piles,h)) {
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};
