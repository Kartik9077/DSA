class Solution {
public:
    bool checkIsInt(string s) {
        bool hasSign = false;
        bool hasVal = false;
        if (s.empty()) return false;
        if (s[0] == '-' || s[0] == '+') hasSign = true;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (hasSign && i == 0) continue;
            if (c == '.') return false;
            if (!isdigit(c)) return false;
            hasVal = true;
        }
        return hasVal;
    }

    bool checkIsDec(string s) {
        bool hasSign = false;
        bool hasVal = false;
        bool hasDot = false;
        if (s.empty()) return true;
        if (s[0] == '-' || s[0] == '+') hasSign = true;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (hasSign && i == 0) continue;
            if (!hasDot && c == '.') {
                hasDot = true;
            }
            else if(hasDot && c == '.') return false;
            else if (!isdigit(c)) return false;
            else {
                hasVal = true;
            }
        }
        return hasVal;        
    }

    bool isNumber(string s) {
        size_t ePos = s.find_first_of("eE");

        if (ePos != string::npos)
            return !s.substr(0, ePos).empty() && checkIsDec(s.substr(0, ePos)) && checkIsInt(s.substr(ePos+1));
        else
            return checkIsDec(s);        
    }
};

