class Solution {
public:
using ll=long long;

    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
         ll i = arr1.size() - 1, j = arr2.size() - 1;
         ll carry = 0;
        vector<int> res;

        while (i >= 0 || j >= 0 || carry != 0) {
            ll x = (i >= 0 ? arr1[i--] : 0);
            ll y = (j >= 0 ? arr2[j--] : 0);

            ll s = x + y + carry;
            ll digit ;
            if(x+y==0 && carry==-1){digit=1;carry=1;}
            else{digit=s%2;carry=-s/2;
            }
            res.push_back(digit);
        }
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
        
         
    }
};