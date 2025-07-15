class Solution {
public:
    bool isValid(string word) {
      
          

        if(word.size()<3)return 0;
        bool v=0,k=0;
        for(auto c:word){
            
            if(isdigit(c))continue;
            if(isalpha(c)){
              char it=tolower(c);
                if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u')v=1;
                else k=1;    
            }
            else return 0;
        }
        if(v&k)return 1;
        return 0;
        
    }
};