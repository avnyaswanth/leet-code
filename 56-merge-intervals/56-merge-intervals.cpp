class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        int n = intr.size();
        vector<vector<int>> ans;
        sort(intr.begin(), intr.end());
        ans.push_back(intr[0]);
        for(int i=1;i<n;++i)
        {
            if(intr[i][0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], intr[i][1]);
            else ans.push_back(intr[i]);
        }
        return ans;
    }
};