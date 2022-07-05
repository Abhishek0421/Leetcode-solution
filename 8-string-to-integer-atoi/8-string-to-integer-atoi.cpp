class Solution {
public:
    int myAtoi(string s) {
        unsigned long long val = 0;
        int sign=1, n = s.size();
        unordered_set<char> sigs = {'-', '+'}; 
        
        
        int i=0;
        while (s[i]==' ') i++;

        if (sigs.count(s[i]) && sigs.count(s[i+1])) return 0; // fuck edge cases
        if (s[i]=='+') sign= 1, i++;
        if (s[i]=='-') sign=-1, i++;
        
        if  (s[i]<=47 ||  s[i]>=58) return 0;
        while (s[i]>47 && s[i]<58) {
            val = val*10 + s[i++]-48;
            if (sign==1 && val>INT_MAX) return INT_MAX;
            if (sign==-1&& val>INT_MAX) return INT_MIN;
        }
        return  sign* ((int)val);
    }
};