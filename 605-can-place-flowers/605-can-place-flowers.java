class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int flower = 1, noflower = 0;
        int len = flowerbed.length;
        if(n == 0)
            return true;
        if(flowerbed[0] == noflower)
        {
            if(len < 2 || flowerbed[1] == noflower)
            {
                flowerbed[0] = flower;
                n --;
            }
        }
        for(int i=1;i<len-1;++i) {
            if(n == 0)
                return true;
            if(flowerbed[i] == noflower && flowerbed[i-1] == noflower && flowerbed[i+1] == noflower)
            {
                flowerbed[i] = flower;
                n --;
            }
        }
        if(flowerbed[len-1] == noflower)
        {
            if(flowerbed[len-2] == noflower)
            {
                flowerbed[len-1] = flower;
                n --;
            }
        }
        return n == 0;
    }
}