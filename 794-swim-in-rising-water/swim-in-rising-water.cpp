class Solution {
public:
    struct Cell {
        int i;
        int j;
    };

    __attribute__((always_inline))
    static int cellId(int n, int i, int j) {
        return i * n + j;
    }

    class ConnectedComponents {
    public:
        explicit ConnectedComponents(int n)
        : xs_(createData(n)), heights_(n) {}

        __attribute__((always_inline))
        void connect(int i, int j) {
            auto ri = root(i);
            auto rj = root(j);

            auto hi = heights_[ri];
            auto hj = heights_[rj];
            if (hi > hj) {
                std::swap(ri, rj);
                std::swap(hi, hj);
            }

            // hi <= hj
            xs_[ri] = rj;
            heights_[rj] = std::max(hj, hi + 1);
        }

        __attribute__((always_inline))
        bool connected(int i, int j) const {
            return root(i) == root(j);
        }

    private:
        __attribute__((always_inline))
        int root(int id) const {
            while (true) {
                int parent = xs_[xs_[id]];
                if (parent == id) {
                    return parent;
                }

                // Lazy path compression, O(log*(n)) average lookup
                xs_[id] = parent;
                id = parent;
            }

            std::unreachable();
        }

        __attribute__((always_inline))
        static std::vector<int> createData(int n) {
            std::vector<int> xs;
            xs.reserve(n);
            for (int i = 0; i < n; ++i) {
                xs.push_back(i);
            }
            return xs;
        }

        mutable std::vector<int> xs_;
        std::vector<int> heights_;
    };

    static constexpr std::array<std::pair<int, int>, 4> kDirs = {
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
    };

    template <typename T, typename Callback>
    __attribute__((flatten, always_inline))
    void doInsertionSort(std::vector<T>& xs, Callback& cb, int lb, int ub) {
        // lb --- (sorted: xs[i-1] <= xs[i]) --- end --- (unsorted) --- ub
        for (int end = lb + 1; end < ub; ++end) {
            for (int i = end; i > lb && cb(xs[i], xs[i-1]) < 0; --i) {
                std::swap(xs[i], xs[i-1]);
            }
        }
    }

    __attribute__((always_inline))
    int orderingToInt(std::weak_ordering cmp) {
        if (cmp < 0) {
            return -1;
        }

        if (cmp == 0) {
            return 0;
        }

        return 1;
    }

    template <typename T, typename Callback>
    __attribute__((flatten))
    void doSort(std::vector<T>& xs, Callback& cb, int lb, int ub) {
        while (ub - lb > 1) {
            if (ub - lb < 16) {
                doInsertionSort(xs, cb, lb, ub);
                return;
            }

            // lb --- (<) -- pb --- (=) --- pe --- (>) --- end --- (todo) -- ub
            int pb = lb;
            int pe = lb + 1;
            int end = lb + 1;

            while (end < ub) {
                int cmp = orderingToInt(cb(xs[end], xs[pb]));
                switch (cmp) {
                    case -1:
                        std::swap(xs[end], xs[pb]); // now xs[end] == pivot
                        pb++;
                        [[fallthrough]];

                    case 0:
                        std::swap(xs[end], xs[pe]); // now xs[end] > pivot
                        pe++;
                        [[fallthrough]];

                    case 1:
                        end++;
                        break;

                    default:
                        std::unreachable();
                }
            }

            if (pb - lb < ub - pe) {
                doSort(xs, cb, lb, pb);
                lb = pe;
            } else {
                doSort(xs, cb, pe, ub);
                ub = pb;
            }
        }
    }

    template <typename T, typename Callback>
    __attribute__((flatten))
    void sort(std::vector<T>& xs, Callback&& cb) {
        std::mt19937 rng;
        std::shuffle(xs.begin(), xs.end(), rng);
        doSort(xs, cb, 0, xs.size());
    }

    /*
    Statement:

    You are given an n x n integer matrix grid where each value grid[i][j]
    represents the elevation at that point (i, j).

    It starts raining, and water gradually rises over time.
    At time t, the water level is t, meaning any cell with elevation less than
    equal to t is submerged or reachable.

    You can swim from a square to another 4-directionally adjacent square if
    and only if the elevation of both squares individually are at most t.
    You can swim infinite distances in zero time. Of course, you must stay
    within the boundaries of the grid during your swim.

    Return the minimum time until you can reach the bottom right square
    (n - 1, n - 1) if you start at the top left square (0, 0).

    Analysis: basically a Kruskal algorithm in disguise.
    */
    __attribute__((flatten))
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        assert(n > 0);
        assert(grid[0].size() == n);

        if (n == 1) {
            return grid[0][0];
        }

        const int kStartId = cellId(n, 0, 0);
        const int kFinishId = cellId(n, n - 1, n - 1);

        //
        // Stage 1: Preparing the data structures, O(n^2 log n)
        //

        std::vector<Cell> cells;
        cells.reserve(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cells.push_back(Cell{i, j});
            }
        }

        sort(cells, [&](auto lhs, auto rhs) {
            return grid[lhs.i][lhs.j] <=> grid[rhs.i][rhs.j];
        });

        ConnectedComponents cc(n * n);

        //
        // Stage 2: Queries, O(n^2 log* n)
        //

        int t = 0;
        for (auto cell : cells) {
            t = std::max(t, grid[cell.i][cell.j]);
            auto id = cellId(n, cell.i, cell.j);

            for (auto [di, dj] : kDirs) {
                auto i = cell.i + di;
                auto j = cell.j + dj;
                if (0 <= i && i < n && 0 <= j && j < n) {
                    if (grid[i][j] <= t) {
                        cc.connect(cellId(n, i, j), id);
                        if (cc.connected(kStartId, kFinishId)) {
                            return t;
                        }
                    }
                }
            }
        }

        std::unreachable();
    }
};