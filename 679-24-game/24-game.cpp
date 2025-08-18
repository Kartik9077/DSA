class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(),cards.end());
        if(isValid(cards)) return true;
        while(next_permutation(cards.begin(),cards.end())){
            if(isValid(cards)) return true;
        }
        return false;
    }
    bool isValid(vector<int>& cards){
        double a = cards[0], b = cards[1], c = cards[2], d = cards[3];
        if(isValid(a+b,c,d) ||isValid(a-b,c,d) ||isValid(a*b,c,d) ||isValid(a/b,c,d)) return true;
        if(isValid(a,b+c,d) ||isValid(a,b-c,d) ||isValid(a,b*c,d) ||isValid(a,b/c,d)) return true;
        if(isValid(a,b,c+d) ||isValid(a,b,c-d) ||isValid(a,b,c*d) ||isValid(a,b,c/d)) return true;
        return false;
    }
    bool isValid(double a,double b,double c){
        if(isValid(a+b,c) ||isValid(a-b,c) ||isValid(a*b,c) || b&&isValid(a/b,c)) return true;
        if(isValid(a,b+c) ||isValid(a,b-c) ||isValid(a,b*c) || c&&isValid(a,b/c)) return true;
        return false;
    }
    bool isValid(double a,double b){
        if(abs(a+b-24) <= 1e-5 ||abs(a-b-24) <= 1e-5 ||abs(a*b-24) <= 1e-5 || b&&abs(a/b-24) <= 1e-5 ) return true;
        return false;
    }
};