class NumArray {
    int n;
    vector<int> bit;  
    vector<int> nums;  
    void add(int idx, int delta) {
        for (int i = idx + 1; i <= n; i += (i & -i)) {
            bit[i] += delta;
        }
    }
    int prefixSum(int idx) const {
        int s = 0;
        for (int i = idx + 1; i > 0; i -= (i & -i)) {
            s += bit[i];
        }
        return s;
    }

public:
    NumArray(vector<int>& arr) {
        n = (int)arr.size();
        nums = arr;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            add(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - (left > 0 ? prefixSum(left - 1) : 0);
    }
};