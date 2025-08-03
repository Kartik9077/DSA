class Solution {
public:
    bool isValidSerialization(string preorder) {
       if(preorder.empty())return false;
        int cnt=1,i=0;
        while(i<preorder.size()){
            if(preorder[i]=='#')cnt--;
            else cnt++;
            if(cnt==0)break;
            while(i<preorder.size()&&preorder[i++]!=',');
        }
        return cnt==0&&i==preorder.size()-1;
    }
};