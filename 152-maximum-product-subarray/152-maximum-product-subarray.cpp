class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n(nums.size());
        int curmax(1), curmin(1);
        int res = *max_element(nums.begin(), nums.end());
        for(auto num : nums)
        {
            int temp = num * curmax;
            curmax = max(num * curmax, num * curmin);
            curmax = max(curmax, num);
            curmin = min(temp, num * curmin);
            curmin = min(curmin, num);
            res = max(res, curmax);
        }
        return res;
    }
};