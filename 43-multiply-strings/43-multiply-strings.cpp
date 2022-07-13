string addStrings(string num1, string num2) {
        int n1=num1.size()-1;
        int n2=num2.size()-1;
        int carry=0;
        string str="";
        while(n1>=0 || n2>=0 || carry!=0){
            char a,b;
            
            if(n1<0)
                a='0';
            else
                a=num1[n1];
            if(n2<0)
                b='0';
            else
                b=num2[n2];
            
            str+=(a-'0'+b-'0'+carry)%10+'0';
            carry=(a-'0'+b-'0'+carry)/10;
            
            n1--;
            n2--;
            
        }
        reverse(str.begin(),str.end());
        return str;
        
        
    }
    
    
class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1=="0" || num2=="0")return "0";
        int n1=num1.size()-1;
        int n2=num2.size()-1;
        int carry=0;
        string ans,prev="0";
        int i=0;
        while(n1>=0){
            char ch=num1[i];
            int carry=0;
            int tn2=n2;
            string temp="";
            while(tn2>=0 || carry!=0){
                char b;
                if(tn2<0)
                    b='0';
                else
                    b=num2[tn2];
                    
                temp+=((b-'0')*(num1[n1]-'0')+carry)%10+'0';
                carry=((b-'0')*(num1[n1]-'0')+carry)/10;
                tn2--;
            }
            reverse(temp.begin(),temp.end());
            int t=i;
            while(t--)
                temp+='0';
            ans=addStrings(temp,prev);
            prev=ans;
            n1--;
            i++;
        }
        return ans;
         
    }
};