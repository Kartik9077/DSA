class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
         if(start > destination){
            int temp = start;
            start = destination;
            destination = temp;
        }
        
        int total = 0;
        for(int i : distance){
            total += i;
        }

        int dist1 = 0;
        for(int i = start; i < destination; i++){
            dist1 += distance[i];
        }

        return min(dist1, total - dist1);
    }
};