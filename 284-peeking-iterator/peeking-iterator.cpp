class PeekingIterator : public Iterator {
private:
    bool hasPeeked;
    int peekVal;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasPeeked = false;
        peekVal = 404;
    }
	int peek() {
        if(hasPeeked) return peekVal;
        hasPeeked = true;
        return peekVal = Iterator::next();
	}
	int next() {
	    if(hasPeeked){
            hasPeeked = false;
            return peekVal;
        }
        return Iterator::next();
	}
	bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
	}
};