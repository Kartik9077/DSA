#include <bits/stdc++.h>
using namespace std;

class MKAverage {
public:
    multiset<int> left, right, mid;
    deque<int> dq;
    long m, k, sum, midSize;

    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        sum = 0;
        midSize = m - 2 * k;
    }

    void remove(int x) {
        auto it = right.find(x);
        if (it != right.end()) {
            right.erase(it);
            return;
        }
        else
        {
            auto rit=right.begin();
            mid.insert(*rit);
            sum+=*rit;
            right.erase(rit);
        }
        it = mid.find(x);
        if (it != mid.end()) {
            sum -= x;
            mid.erase(it);
            return;
        }
        else
        {
            auto mit=mid.begin();
            left.insert(*mit);
            sum-=*mit;
            mid.erase(mit);
        }
        it = left.find(x);
        left.erase(it);
    }

    void add(int x) {
        left.insert(x);
        if (left.size() > k) {
            auto it = prev(left.end());
            mid.insert(*it);
            sum += *it;
            left.erase(it);
        }

        if (mid.size() > midSize) {
            auto it = prev(mid.end());
            right.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
    }

    void addElement(int num) {
        if (dq.size() == m) {
            remove(dq.front());
            dq.pop_front();
        }
        dq.push_back(num);
        add(num);
    }

    int calculateMKAverage() {
        if (dq.size() < m)
            return -1;
        return sum / midSize;
    }
};