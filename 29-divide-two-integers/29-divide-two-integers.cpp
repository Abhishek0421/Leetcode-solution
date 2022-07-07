class Solution {
public:
int divide(int dividend, int divisor) {
if(dividend==INT_MIN && divisor==-1) return INT_MAX;
long long int dvd=abs(dividend);
long long int dvr=abs(divisor);

   long int result=0;
    long long int temp=dvr;
    while(dvd>=temp){
        dvr=temp;
        long int count=1;
        while(dvd>=dvr){
            count<<=1;
            dvr<<=1;
        }
        result+=count>>1;
        dvd-=dvr>>1;
    }
    
    if((dividend<0 && divisor>0) ||(dividend>0 && divisor<0 ))
    return -result;
    return result;
}
    
};
