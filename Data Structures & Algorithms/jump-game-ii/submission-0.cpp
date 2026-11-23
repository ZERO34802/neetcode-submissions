class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n,1e9);
        p[n - 1] = 0;
        for(int i = n - 2;i >= 0;i--) {
            int jd = nums[i];
            for(int j = 0;j <= jd;j++) {
                if((i + j < n) && p[i + j] != 1e9) {
                    p[i] = min(p[i],1 + p[i + j]);
                }
            }
        }
        return p[0];
    }
};
