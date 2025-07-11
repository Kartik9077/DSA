class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
         vector<long long> meet(n,0);
        vector<long long> roomsBookedTill(n,0);

        sort(meetings.begin(), meetings.end());
       
        long long time=0;
        for(long long i=0; i<meetings.size(); i++){
            long long r=-1;
            long long small=LLONG_MAX;
            long long smallr=-1;

            if(time<meetings[i][0])
                time= meetings[i][0];
            for(long long j=0; j<n; j++){
                if(roomsBookedTill[j]<=time){
                    r= j;
                    break;
                }
                if(roomsBookedTill[j]<small){
                    small= roomsBookedTill[j];
                    smallr= j;
                }

            }

            if(r ==-1){
                time= small;
                r= smallr;
            }
            meet[r]++;
            roomsBookedTill[r]=time+ meetings[i][1]-meetings[i][0];
         
        }


        long long number=0;
        long long ans=0;
        for(long long i=n-1; i>=0; i--){
            if(number<= meet[i]){
                number = meet[i];
                ans =i;
            }
        }

        return ans;
    }
};