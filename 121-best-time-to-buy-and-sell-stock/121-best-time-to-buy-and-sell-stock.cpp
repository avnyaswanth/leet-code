class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int buy = arr[0];
        for(int i=1;i<n;++i)
        {
            if(arr[i] > buy)
                ans = max(arr[i] - buy, ans);
            else buy = arr[i];
        }
        return ans;
    }
};