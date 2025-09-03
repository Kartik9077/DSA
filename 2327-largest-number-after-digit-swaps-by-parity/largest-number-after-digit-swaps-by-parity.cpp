class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> oddParity;
        priority_queue<int> evenParity;
        vector<int> arr;
        int temp = num;
        while(num > 0){
            int rem = num%10;
            arr.push_back(rem);
            if(rem %2 == 0){
                evenParity.push(rem);
            }else{
                oddParity.push(rem);
            }
            num = num/10;
        }
        int result = 0;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i] %2 == 0){
                result = result*10 + evenParity.top();
                evenParity.pop();
            }else{
                result = result*10 + oddParity.top();
                oddParity.pop();
            }
        }
        return result;
    }
};