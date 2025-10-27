class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev_dev{1};
        int result{0};
        int current_dev{0};
        bool got_first_value=false;
        
        for(int r=0;r<bank.size();r++){
        for(int c=0;c<bank[0].size();c++){
            if(bank[r][c]=='1'){
                current_dev++;
            }   
        }    
        if(current_dev!=0){
            if(got_first_value==true){
                result=result+prev_dev*current_dev;}
                got_first_value=true;
                prev_dev=current_dev;
                current_dev=0;
            }
        }
        return result;
        
    }
};