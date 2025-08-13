class Solution {
public:
long long ans=1;
bool pow(int n,int x)
{
     
    if(ans==n)return 1;
    if(ans>n)return 0;
    ans*=x;
    return pow(n,3);
}

    bool isPowerOfThree(int n) {
        if(pow(n,3))return 1;
        return false;
        
    }
};