// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item a, Item b)
    {
        double pa = (double)a.value / (double)a.weight;
        double pb = (double)b.value / (double)b.weight;
        return pa > pb;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       sort(arr, arr+n, comp);
       int curW = 0;
       double profit = 0.0;
       for(int i=0;i<n;++i)
       {
           if(curW + arr[i].weight <= W)
           {
               curW += arr[i].weight;
               profit += arr[i].value;
           }
           else
           {
               int rem = W - curW;
               profit += (arr[i].value / (double)arr[i].weight)*rem;
               break;
           }
       }
       return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends