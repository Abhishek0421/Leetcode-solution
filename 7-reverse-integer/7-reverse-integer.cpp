class Solution {
public:
    int reverse(int x) {
        bool f=false;
        if(x<0){
            f=true;
        }
        x = abs(x);
        string s=to_string(x);
        for(int i=0;i<s.length()/2;i++){
            swap(s[i],s[s.length()-i-1]);
        }
        long long int res=stoll(s);
        if(res > 2147483647){
            return 0;
        }
        if(f){
            return (-1)*res;
        }
        return res;
    }
};