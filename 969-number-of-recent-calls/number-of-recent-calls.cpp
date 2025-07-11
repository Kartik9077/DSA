class RecentCounter {
public:
queue<__int128>requests={};
    RecentCounter() {
        
        
    }
    
    int ping(int t) {
        const __int128 mini=t-3000;
        this->requests.push(t);
        __int128 ea=this->requests.front();
        while(ea<mini){
            this->requests.pop();
            ea=this->requests.front();

        }
        return this->requests.size();
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */