class Solution {
public:
    bool isValid(string word) {
        unordered_set<char>st;
        st.insert('a');  st.insert('e');  st.insert('i');  st.insert('o');  st.insert('u');
          st.insert('A');  st.insert('E');  st.insert('I');  st.insert('O');  st.insert('U');

        if(word.size()<3)return 0;
        bool v=0,c=0;
        for(auto it:word){
            if(isdigit(it))continue;
            if(isalpha(it)){
                if(st.find(it)!=st.end())v=1;
                else c=1;    
            }
            else return 0;
        }
        if(v&c)return 1;
        return 0;
        
    }
};