
class Poly {
public:
    unordered_map<vector<string>, int, 
        function<size_t(const vector<string>&)>> count;

    Poly() : count(0, [](const vector<string>& v) {
        size_t h = 0;
        for (auto &s : v) {
            for (auto c : s) {
                h = h * 131 + c;
            }
        }
        return h;
    }) {}

    void update(vector<string> key, int val) {
        count[key] += val;
    }

    Poly add(const Poly &that) const {
        Poly ans;
        for (auto &kv : count) ans.update(kv.first, kv.second);
        for (auto &kv : that.count) ans.update(kv.first, kv.second);
        return ans;
    }

    Poly sub(const Poly &that) const {
        Poly ans;
        for (auto &kv : count) ans.update(kv.first, kv.second);
        for (auto &kv : that.count) ans.update(kv.first, -kv.second);
        return ans;
    }

    Poly mul(const Poly &that) const {
        Poly ans;
        for (auto &kv1 : count) {
            for (auto &kv2 : that.count) {
                vector<string> kNew = kv1.first;
                kNew.insert(kNew.end(), kv2.first.begin(), kv2.first.end());
                sort(kNew.begin(), kNew.end());
                ans.update(kNew, kv1.second * kv2.second);
            }
        }
        return ans;
    }

    Poly evaluate(unordered_map<string, int> &evalMap) const {
        Poly ans;
        for (auto &kv : count) {
            int c = kv.second;
            vector<string> free;
            for (auto &token : kv.first) {
                if (evalMap.count(token)) {
                    c *= evalMap[token];
                } else {
                    free.push_back(token);
                }
            }
            ans.update(free, c);
        }
        return ans;
    }

    static int compareList(const vector<string>& A, const vector<string>& B) {
        for (int i = 0; i < (int)A.size(); i++) {
            if (A[i] != B[i]) return A[i] < B[i] ? -1 : 1;
        }
        return 0;
    }

    vector<string> toList() const {
        vector<vector<string>> keys;
        for (auto &kv : count) keys.push_back(kv.first);

        sort(keys.begin(), keys.end(), [&](const vector<string>& a, const vector<string>& b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return compareList(a, b) < 0;
        });

        vector<string> ans;
        for (auto &key : keys) {
            int v = count.at(key);
            if (v == 0) continue;
            string word = to_string(v);
            for (auto &token : key) {
                word += "*" + token;
            }
            ans.push_back(word);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalVars, vector<int>& evalInts) {
        unordered_map<string, int> evalMap;
        for (int i = 0; i < evalVars.size(); i++) {
            evalMap[evalVars[i]] = evalInts[i];
        }
        return parse(expression).evaluate(evalMap).toList();
    }

    Poly make(string expr) {
        Poly ans;
        vector<string> list;
        if (isdigit(expr[0])) {
            ans.update(list, stoi(expr));
        } else {
            list.push_back(expr);
            ans.update(list, 1);
        }
        return ans;
    }

    Poly combine(Poly left, Poly right, char symbol) {
        if (symbol == '+') return left.add(right);
        if (symbol == '-') return left.sub(right);
        if (symbol == '*') return left.mul(right);
        throw runtime_error("Invalid operator");
    }

    Poly parse(string expr) {
        vector<Poly> bucket;
        vector<char> symbols;
        int i = 0;
        while (i < expr.size()) {
            if (expr[i] == '(') {
                int bal = 0, j = i;
                for (; j < expr.size(); j++) {
                    if (expr[j] == '(') bal++;
                    if (expr[j] == ')') bal--;
                    if (bal == 0) break;
                }
                bucket.push_back(parse(expr.substr(i + 1, j - i - 1)));
                i = j;
            } else if (isalnum(expr[i])) {
                int j = i;
                while (j < expr.size() && expr[j] != ' ' && expr[j] != ')' && expr[j] != '(' && expr[j] != '+' && expr[j] != '-' && expr[j] != '*')
                    j++;
                bucket.push_back(make(expr.substr(i, j - i)));
                i = j - 1;
            } else if (expr[i] != ' ') {
                symbols.push_back(expr[i]);
            }
            i++;
        }

        for (int j = symbols.size() - 1; j >= 0; j--) {
            if (symbols[j] == '*') {
                bucket[j] = combine(bucket[j], bucket[j + 1], symbols[j]);
                bucket.erase(bucket.begin() + j + 1);
                symbols.erase(symbols.begin() + j);
            }
        }

        if (bucket.empty()) return Poly();
        Poly ans = bucket[0];
        for (int j = 0; j < symbols.size(); j++) {
            ans = combine(ans, bucket[j + 1], symbols[j]);
        }
        return ans;
    }
};