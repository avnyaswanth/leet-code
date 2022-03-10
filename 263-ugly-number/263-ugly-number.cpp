class Solution {
public:
    bool isprime(long n)
    {
        if(n < 2)
            return false;
        for(long i=2;i*i<=n;++i)
            if(n % i == 0)
                return false;
        return true;
    }
    bool isUgly(int n) 
    {
        long N = n;
        if(N <= 0)
            return false;
        
        if(N < 7)
            return true;
        
        if(isprime(N))
            return false;
        
        for(long i=2;i*i<=N;++i)
        {   
            if(N % i == 0)
            {
                if(N/i != 2 && N/i !=3 && N/i !=5)
                    if(isprime(N / i))
                        return false;
                        
                if(i != 2 && i != 3 && i != 5)
                    if(isprime(i))
                        return false;
            }
            
        }
        return true;
    }
};