class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, n = nums.size();
        int high = n - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(mid > 0 && mid < n-1 && nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid])
                return nums[mid];
            else if(mid > 0 && nums[mid-1] == nums[mid])
            {
                if((mid - low) % 2 == 0)
                    high = mid - 2;
                else low = mid + 1;
            }
            else if(mid < n-1 && nums[mid+1] == nums[mid])
            {
                if((high - mid) % 2 == 1)
                    high = mid - 1;
                else low =  mid + 2;
            }
        }
        return nums[high]; // nums[high];
    }
};