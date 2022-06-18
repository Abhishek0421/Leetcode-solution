// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    vector<int> mi={1,1,0,-1,-1,-1,0,1};
    vector<int> mj={0,1,1,1,0,-1,-1,-1};
    bool dfs(int si,int sj,int l,vector<vector<char>> &board,vector<vector<int>> &visi,string &s){
        if(si<0 || sj<0 || si>=board.size() || sj>=board[0].size() || visi[si][sj]!=0 || board[si][sj]!=s[l]){
               return false;
        }
        if(l==s.length()-1){
            return true;
        }
        if(l>=s.length()) return false;
        visi[si][sj]=1;
        for(int k=0;k<8;k++){
            int x = si+mi[k];
            int y = sj+mj[k];
            if(dfs(x,y,l+1,board,visi,s)){
                return true;
            }
        }
        visi[si][sj]=0;
        return false;
    }
    bool search(vector<vector<char>> &board,string s,int n,int m){
        vector<vector<int>> visi(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
	       for(int j=0;j<m;j++){
	           if(board[i][j]==s[0]){
	               if(dfs(i,j,0,board,visi,s)){
	                   return true;
	               }
	           }
	       }
	   }
	   return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    int s = dictionary.size();
	    vector<string> v;
	    int n = board.size();
	    int m = board[0].size();
	    for(auto s:dictionary){
	        if(search(board,s,n,m)){
	            v.push_back(s);
	        }
	    }
	    return v;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends