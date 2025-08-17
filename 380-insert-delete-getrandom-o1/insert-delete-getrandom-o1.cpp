class RandomizedSet {
public:
  unordered_set<int>st;
  queue<int>q1,q2;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(st.find(val)==st.end()){st.insert(val);q1.push(val);return 1;}
        return 0;   
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            st.erase(val);
            while(!q1.empty()&&q1.front()!=val){
                q2.push(q1.front());
                q1.pop();
         }
         q1.pop();
        while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            return 1;
        }
        return 0;
        
    }
    
    int getRandom() {
        auto it=st.begin();
        int p=st.size();
        int a=rand()%p;
        advance(it,a);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */