class MyCalendarTwo {
public:
    vector<pair<int, int>>doubleOverlapp; 
    vector<pair<int, int>>bookings; 

    MyCalendarTwo() {
        
    }
    bool checkOverlapp(int a1, int b1, int a2, int b2){
        return max(a1, a2) < min(b1, b2); 
    }

    pair<int, int> findOverlappRegion(int a1, int b1, int a2, int b2){
        return {max(a1, a2), min(b1, b2)};
    }
    bool book(int start, int end) {
        for(pair<int, int>region: doubleOverlapp){
            if(checkOverlapp(region.first, region.second, start, end)){
                return false;
            }
        }     
        for(pair<int, int>booking : bookings){
            if(checkOverlapp(booking.first, booking.second, start, end)){
                doubleOverlapp.push_back(findOverlappRegion(booking.first, booking.second, start, end));

            }
        }
        bookings.push_back({start, end});
        return true;
    }
};
