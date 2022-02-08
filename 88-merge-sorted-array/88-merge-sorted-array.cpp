class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tot = m;
        for(int i=0;i<n;++i)
        {
            int j = tot-1;
            while(j >= 0 and nums1[j] > nums2[i])
            {
                nums1[j+1] = nums1[j];
                j --;
            }
            nums1[j+1] = nums2[i];
            tot++;
        }
    }
};