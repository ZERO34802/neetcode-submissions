class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> freq(2001);
        for(auto it : nums)freq[it + 1000]++;
        for(int i = 0;i <= 2000;i++) {
            pq.push({freq[i],i - 1000});
        }
        vector<int> ans;
        while(k > 0) {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
            k -= 1;
        }
        return ans;
    }
};
