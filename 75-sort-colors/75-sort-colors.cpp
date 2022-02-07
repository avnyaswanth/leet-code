class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l = 0, h = arr.size()-1, m = 0;
        while(m <= h)
        {
            switch(arr[m])
            {
                case 0:
                    swap(arr[l++], arr[m++]);
                    break;
                case 1 : m++;
                    break;
                default: swap(arr[h--], arr[m]);
                    break;
            }
        }
    }
};