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
    //Function to get the maximum total value in the knapsack.
    struct comp{
       bool operator()(pair<double,Item> &a,pair<double,Item> &b){
           return a.first > b.first;
       }
   };
   
   double fractionalKnapsack(int W, Item arr[], int n){
       vector<pair<double,Item>> v;
       for(int i = 0; i < n; i++){
           double val = arr[i].value;
           double w = arr[i].weight;
           double ratio = (double)val/w;
           v.push_back({ratio,arr[i]});
       }
       
       sort(v.begin(),v.end(),comp());
       double maxProfit = 0.0;
       for(int i = 0; i < n && W > 0; i++){
           double ratio = v[i].first;
           Item it = v[i].second;
           
           if(W >= it.weight){
               maxProfit += it.value;
               W -= it.weight;
           }
           else{
               maxProfit += ratio * W;
               W = 0;
           }
       }
       
       return (maxProfit);
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