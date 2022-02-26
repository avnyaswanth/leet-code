class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = INT_MIN;
        int n(arr.size());
        int leftsmall[n], rightsmall[n];
        stack<int> stk;
        for(int i=0;i<n;++i)
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            if(stk.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = stk.top() + 1;
            stk.push(i);
        }
        
        while(!stk.empty())
            stk.pop();
        
        for(int i=n-1;i>=0;--i)
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            if(stk.empty())
                rightsmall[i] = n-1;
            else rightsmall[i] = stk.top() - 1;
            stk.push(i);
        }
        for(int i=0;i<n;++i)
        {
            maxArea = max(maxArea, (rightsmall[i] - leftsmall[i] + 1) * arr[i]);
        }
        return maxArea;
    }
};