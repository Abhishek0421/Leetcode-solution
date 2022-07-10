class Solution {
public:
    inline string convert(string s, int numRows) {
        if (numRows == 1 || !s.size() ){
            return s;
        }
        
        string pic[numRows], res;
        int row = 0 , dir = -1 , sz = numRows - 1;
        
        for(auto& elm: s){
            cout<<row<<" ";
            pic[row].push_back(elm);
            if (row == 0 || row == sz){
                dir *= -1;
            }
            row += dir;
        }
        
        for (auto& elm : pic){
            res += elm;
        }
        
        return res;  
    }
};
