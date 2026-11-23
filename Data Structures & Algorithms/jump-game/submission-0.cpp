class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> p(n,false);
        p[n - 1] = true;
        for(int i = n - 2;i >= 0;i--) {
            int jd = nums[i];
            for(int j = 0;j <= jd;j++) {
                if(p[i + j] == true) {
                    p[i] = true;
                    break;
                }
            }
        }
        return p[0];
    }
};
