// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends

bool b_search(int arr[],int start,int end,int target){
    int i = start;
    int j = end;
    while(i<=j){
        int mid = (start+end)/2;
        if(arr[mid] == target){
            return true;
        }
        if(target>arr[mid]){
            return b_search(arr,mid+1,j,target);
        }
        else{
            return b_search(arr,i,mid-1,target);
        }
    }
    return false;
}
bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
        if(b_search(arr,i+1,size-1,arr[i]+n)){
            return true;
        }
    }
    return false;
}