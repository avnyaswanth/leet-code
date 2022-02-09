class Solution {
public:
    int *temp;
    Solution()
    {
        temp = new int[5e4+1];
        memset(temp, -1, sizeof(temp));
    }
    int merge(vector<int> &nums, int l, int p, int h)
    {
        int count = 0;
        
        int i = l, j = p+1, k = l;
        for(int i=l;i<=p;++i)
        {
            while(j <= h && nums[i] > 1LL*2*nums[j])
                j++;
            count += j-(p+1);
        }
        j = p + 1;
        while(i<=p && j<=h)
        {
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
            {
                temp[k++] = nums[j++];
            }
        }
        while(i<=p)
            temp[k++] = nums[i++];
        while(j<=h)
            temp[k++] = nums[j++];
        for(int i=l;i<=h;++i)
            nums[i] = temp[i];
        return count;
    }
    int mergesort(vector<int> &nums, int l, int h)
    {
        int revp = 0;
        if(l < h)
        {
            int p = l + (h-l)/2;
            revp += mergesort(nums, l, p);
            revp += mergesort(nums, p+1, h);
            revp += merge(nums, l, p, h);
        }
        return revp;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mergesort(nums, 0, n-1);
        for(int i=0;i<n;++i)
            cout << nums[i] <<  ' ';
        return ans;
    }
};