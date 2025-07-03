/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
       stack<NestedInteger> S;
        NestedInteger curr;
        for (int i = 0; i < s.size();) {
            if (std::isdigit(s[i]) || s[i] == '-') {
                bool negative = false;
                if (s[i] == '-') {negative = true; i++; }
                int num = 0;
                while (i < s.size() && std::isdigit(s[i])) {
                    num = 10 * num + (s[i++] - '0');
                }
                NestedInteger el(negative ? -num : num);
                curr.add(el);
            } else if (s[i] == ',') {
                i++;
            } else if (s[i] == '[') {
                S.push(move(curr));
                curr = NestedInteger();
                i++;
            } else if (s[i] == ']') {
                NestedInteger top = move(S.top()); S.pop();
                top.add(move(curr));
                curr = move(top);
                i++;
            }
        }
        return curr.getList()[0]; 
    }
};