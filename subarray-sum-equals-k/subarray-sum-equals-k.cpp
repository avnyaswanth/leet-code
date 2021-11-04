class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        int sum = 0, ans = 0;
        for(int i=0; i<n;++i)
        {
            sum += arr[i];
            if(sum == k)
                ans ++;
            if(mp[sum - k] > 0)
                ans += mp[sum-k];
            mp[sum]++; 
        }
        return ans;
    }
};