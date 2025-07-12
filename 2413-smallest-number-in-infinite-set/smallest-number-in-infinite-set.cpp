class SmallestInfiniteSet {
public:
     set<int> st;
    int currSmallest ;
    SmallestInfiniteSet() {
       currSmallest = 1;
    }
    
    int popSmallest() {
       int result;
       if(!st.empty()){
        result = * st.begin();
        st.erase(st.begin());
        
       }
       else{
        result = currSmallest++;
       }
       return result;
    }
    
    void addBack(int x) {
        if(x<currSmallest){
            if(st.find(x) == st.end()){
     st.insert(x);
            }
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */