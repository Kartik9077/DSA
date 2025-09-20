class Router {
public:
    int len;
    deque<vector<int>> q;
    set<vector<int>> packets;
    unordered_map<int, vector<int>> destStamp;
    Router(int memoryLimit) { len = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        if (packets.find(packet) != packets.end())
            return false;
        if (q.size() == len)
            forwardPacket();
        q.push_back(packet);
        destStamp[destination].push_back(timestamp);
        packets.insert(packet);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.size()) {
            vector<int> res = q.front();
            destStamp[res[1]].erase(destStamp[res[1]].begin());
            packets.erase(res);
            q.pop_front();
            return res;
        }
        return {};
    }
    int findLess(vector<int>& dest, int time) {
        int ans = -1;
        int low = 0, high = dest.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (dest[mid] <= time) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans + 1;
    }
    int getCount(int destination, int startTime, int endTime) {
       
        int upLimit = findLess(destStamp[destination], endTime);
        int lowLimit = findLess(destStamp[destination], startTime - 1);
        return upLimit - lowLimit;
    }
};
