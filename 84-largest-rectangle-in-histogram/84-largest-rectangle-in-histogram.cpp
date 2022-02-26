class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = INT_MIN;
        int n(arr.size());
        
        stack<int> stk;
        for(int i=0;i<=n;++i)
        {
            while(!stk.empty() && (i == n || arr[stk.top()] >= arr[i]))
            {
                int height = arr[stk.top()];
                stk.pop();
                int area = 0;
                if(stk.empty())
                    area = i * height;
                else area = (i - (stk.top()+1)) * height;
                maxArea = max(maxArea, area);
            }  
            stk.push(i);
        }
        return maxArea;
    }
};