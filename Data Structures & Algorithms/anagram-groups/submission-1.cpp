class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> freq;
        for(int i = 0;i < strs.size();i++) {
            vector<int> count(26);
            for(int j = 0;j < strs[i].size();j++)count[strs[i][j] - 'a']++;
            string key = to_string(count[0]);
            for(int j = 1;j < 26;j++) {
                key += ',' + to_string(count[j]);
            }
            freq[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it : freq) {
            vector<string> t;
            for(auto i : it.second) {
                t.push_back(i);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
