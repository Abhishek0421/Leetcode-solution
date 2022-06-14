class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n = digits.size();
        int s = (digits[n-1]+1);
        digits[n-1] = s%10;
        carry = s/10;
        for(int i=n-2;i>=0;i--){
            
            int sum = digits[i]+carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
       
        if(carry!=0){
            reverse(digits.begin(),digits.end());
            digits.push_back(carry);
            reverse(digits.begin(),digits.end());
            return digits;
        }
        return digits;
    }
};