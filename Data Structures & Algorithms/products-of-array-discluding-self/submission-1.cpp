class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_ct = 0;
        int n = nums.size();
        vector<int> pref(n),suff(n);int prod = 1;
        vector<int> ans(n);
        for(int i = 0;i < n;i++) {
            if(nums[i] == 0)zero_ct++;
            else {
                prod *= nums[i];
                pref[i] = prod;
            }
        }
        prod = 1;
        for(int i = n-1;i >= 0;i--) {
            if(zero_ct > 1)ans[i] = 0;
            else if(zero_ct == 1) {
                if(nums[i] == 0) {
                    ans[i] = i > 0 ? pref[i - 1] : 1;
                    ans[i] *= prod;
                }else {
                    ans[i] = 0;
                    prod *= nums[i];
                }
            }else {
                ans[i] = i > 0 ? pref[i - 1] : 1;
                ans[i] *= prod;
                prod *= nums[i];
            }
        }
        return ans;
    }
};
