class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = 0, end = 0;
        int n = nums.size();
        int maxones = 0;
        for(int i=0;i<n;++i)
        {
            if(nums[i] == 0)
                start = i+1;
            end++;
            maxones = max(maxones, end-start);
        }
        return maxones;
    }
};