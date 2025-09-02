class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;

        for (int i = deck.size() - 1; i >= 0; --i) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }

        return vector<int>(dq.begin(), dq.end());
    }
};