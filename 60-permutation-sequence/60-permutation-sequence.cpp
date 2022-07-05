class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s += to_string(i);
        }
        do{
            if(k==1){
                break;
            }
            k--;
        }while(next_permutation(s.begin(),s.end()));
        
        return s;
    }
};