static constexpr uint64_t M1 = 1e9 + 7ULL;
static constexpr uint64_t M2 = 1e9 + 9ULL;
static constexpr uint64_t P1 = 1e6 + 32139ULL;
static constexpr uint64_t P2 = 1e6 + 13331ULL;

class Hasher final {
public:
    template<class It>
    explicit Hasher(const It &first, const It &last)
        : sz(static_cast<size_t>(distance(first, last))),
          prefix1(sz + 1),
          pows1(sz + 1, 1),
          prefix2(sz + 1),
          pows2(sz + 1, 1) {
        for (size_t i = 1; i <= sz; ++i) {
            pows1[i] = (pows1[i - 1] * P1) % M1;
            pows2[i] = (pows2[i - 1] * P2) % M2;
        }
        size_t i = 0;
        for (auto it = first; it != last; ++it, ++i) {
            uint64_t x = static_cast<uint64_t>(static_cast<unsigned char>(*it)) + 1ULL;
            prefix1[i + 1] = (prefix1[i] * P1 + x) % M1;
            prefix2[i + 1] = (prefix2[i] * P2 + x) % M2;
        }
    }

    [[nodiscard]] pair<uint64_t, uint64_t> get(const size_t l, const size_t r) const {
        const uint64_t len = r - l + 1;
        const uint64_t without_left1 = (prefix1[l] * pows1[len]) % M1;
        const uint64_t h1 = (prefix1[r + 1] + M1 - without_left1) % M1;
        const uint64_t without_left2 = (prefix2[l] * pows2[len]) % M2;
        const uint64_t h2 = (prefix2[r + 1] + M2 - without_left2) % M2;
        return {h1, h2};
    }

    [[nodiscard]] bool equal(const size_t l1, const size_t r1, const size_t l2, const size_t r2) const {
        return (r1 - l1 != r2 - l2) ? false : get(l1, r1) == get(l2, r2);
    }

private:
    size_t sz;
    vector<uint64_t> prefix1, prefix2;
    vector<uint64_t> pows1, pows2;
};

struct Hash final {
    size_t operator()(const pair<bool, pair<uint64_t, uint64_t> > pr) const {
        return bool_hasher(pr.first) ^ uint64_t_hasher(pr.second.first) ^ uint64_t_hasher(pr.second.second);
    }
    static constexpr hash<bool> bool_hasher{};
    static constexpr hash<uint64_t> uint64_t_hasher{};
};

struct HashHash final {
    size_t operator()(const pair<uint64_t, uint64_t> pr) const {
        return uint64_t_hasher(pr.first) ^ uint64_t_hasher(pr.second);
    }
    static constexpr hash<uint64_t> uint64_t_hasher{};
};

class Solution final {
public:
    vector<vector<int> > palindromePairs(vector<string> &words) {
        const size_t sz = words.size();
        vector<vector<int> > res;
        vector<int> palindromes;
        vector<int> empties;

        empties.reserve(sz / 2);
        palindromes.reserve(sz);
        res.reserve(sz * 2);

        unordered_map<pair<bool, pair<uint64_t, uint64_t> >, vector<int>, Hash> map_wait;

        unordered_map<pair<uint64_t, uint64_t>, int, HashHash> map_has;
        map_has.reserve(sz);
        map_wait.reserve(1000000UL);

        for (size_t i = 0; i < sz; ++i) {
            const string &word = words[i];
            const size_t word_sz = word.size();
            const int int_i = static_cast<int>(i);

            if (word_sz == 0) {
                for (const int j : palindromes) {
                    res.push_back({ j, int_i });
                    res.push_back({ int_i, j });
                }
                empties.push_back(int_i);
                continue;
            }

            const Hasher forward_hasher(word.begin(), word.end());
            const pair<uint64_t, uint64_t> forward = forward_hasher.get(0, word_sz - 1);

            const Hasher backward_hasher(word.rbegin(), word.rend());
            const pair<uint64_t, uint64_t> backward = backward_hasher.get(0, word_sz - 1);

            if (forward == backward) {
                palindromes.push_back(int_i);
                for (const int j : empties) {
                    res.push_back({ j, int_i });
                    res.push_back({ int_i, j });
                }
            }
            

            const auto it_true = map_wait.find({true, forward});
            const auto it_false = map_wait.find({false, forward});

            if (it_true != map_wait.end()) {
                for (const int j : it_true->second) {
                    if (j != int_i) {
                        res.push_back({ int_i, j });
                    }
                }
            }

            if (it_false != map_wait.end()) {
                for (const int j : it_false->second) {
                    if (j != int_i) {
                        res.push_back({ j, int_i });
                    }
                }
            }

            map_wait[{false, backward}].push_back(int_i);
            map_wait[{true,  backward}].push_back(int_i);

            map_has.insert({forward, int_i});

            for (size_t k = 0; k + 1 < word_sz; ++k) {
                if (forward_hasher.get(0, k) == backward_hasher.get(word_sz - k - 1, word_sz - 1)) {
                    const pair<uint64_t, uint64_t> back_here = backward_hasher.get(0, word_sz - k - 2);
                    const auto s = map_has.find(back_here);

                    if (s != map_has.end() && s->second != int_i) {
                        res.push_back({ s->second, int_i });
                    }

                    map_wait[{true, back_here}].push_back(int_i);
                }
            }

            for (size_t k = 0; k + 1 < word_sz; ++k) {
                if (backward_hasher.get(0, k) == forward_hasher.get(word_sz - k - 1, word_sz - 1)) {
                    const pair<uint64_t, uint64_t> back_here = backward_hasher.get(k + 1, word_sz - 1);
                    const auto s = map_has.find(back_here);

                    if (s != map_has.end() && s->second != int_i) {
                        res.push_back({ int_i, s->second });
                    }

                    map_wait[{false, back_here}].push_back(int_i);
                }
            }
        }

        return res;
    }
};