class Solution {
public:
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     sort(begin(nums), end(nums));
    //     return kSum(nums, target, 0, 4);
    // }
	
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
	
//     vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
//         vector<vector<int>> res;
//         int lo = start, hi = nums.size() - 1;
    
//         while (lo < hi) {
//             int curr_sum = nums[lo] + nums[hi];
//             if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
//                 ++lo;
//             } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
//                 --hi;
//             } else {
//                 res.push_back({ nums[lo++], nums[hi--] });
//             }
//         }
                                                           
//         return res;
};