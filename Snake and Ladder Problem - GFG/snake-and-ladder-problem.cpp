// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
       unordered_map<int,int> ladders;
       unordered_map<int,int> snakes;
       int n = N*2;
       for(int i=1;i<n;i+=2){
           if(arr[i-1]<arr[i]) ladders[arr[i-1]] = arr[i];
           else if(arr[i-1]>arr[i]) snakes[arr[i-1]] = arr[i];
       }
       //from 1 to 6 kuch bhi aa skta hai phele
       queue<pair<int,int>>q; //position, no. of moves
       q.push({1,0});
       while(!q.empty()){
           int node = q.front().first;
           int moves = q.front().second;
           q.pop();
           if(node==30) return moves;
           for(int i=1;i<=6;i++){
               int x = i+node;
               if(ladders.find(x)!=ladders.end()){
                   q.push({ladders[x],moves+1});
               }else if(snakes.find(x)!=snakes.end()){
                   q.push({snakes[x],moves+1});
               }else{
                   q.push({x,moves+1});
               }
           }
       }
       return -1;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends