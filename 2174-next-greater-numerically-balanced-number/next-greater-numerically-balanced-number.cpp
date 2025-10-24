class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int>t1 = {1 , 22 , 122 , 212 , 221 , 333 , 1333 , 3133 , 3313 , 3331 , 4444 , 14444 , 22333 , 23233 , 23323 , 23332 , 32233 , 32323 , 32332 , 33223 , 33232 , 33322 , 41444 , 44144 , 44414 , 44441 , 55555};
        for(auto i:t1)
            if(i>n)return i;
        vector<int>t2;
        string s = "122333";
        do{
            t2.push_back((int)stoi(s));
        } while(next_permutation(s.begin(), s.end()));

        s="155555";
        do{
            t2.push_back((int)stoi(s));
        } while(next_permutation(s.begin(), s.end()));

        s="224444";
        do{
            t2.push_back((int)stoi(s));
        } while(next_permutation(s.begin(), s.end()));

        t2.push_back(666666);
        sort(t2.begin(),t2.end());
        for(auto i:t2)
            if(i>n)return i;

        return 1224444;
    }
};