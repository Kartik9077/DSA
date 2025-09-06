class Solution {
public:
    struct BoxType {
        int numberOfBoxes;
        int unitsPerBox;
    };
    
    static bool comp(BoxType a, BoxType b) {
        return a.unitsPerBox > b.unitsPerBox;
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<BoxType> boxes(n);
        
        for(int i = 0; i < n; i++) {
            boxes[i] = {boxTypes[i][0], boxTypes[i][1]};
        }
        
        sort(boxes.begin(), boxes.end(), comp);
        
        int currentBoxes = 0;
        int totalUnits = 0;
        
        for(int i = 0; i < n; i++) {
            int boxesToTake = min(boxes[i].numberOfBoxes, truckSize - currentBoxes);
            
            currentBoxes += boxesToTake;
            totalUnits += boxesToTake * boxes[i].unitsPerBox;
            
            if(currentBoxes == truckSize) {
                break;
            }
        }
        
        return totalUnits;
    }
};