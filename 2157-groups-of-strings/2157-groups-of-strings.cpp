class Solution {
unordered_map<int, int> m;
int dfs(int mask) {
    int res = 0;
    auto it = m.find(mask);
    if (it != end(m)) {
        res += it->second;
        m.erase(it);
        for (int i = 0; i < 26; ++i) {
            res += dfs(mask ^ (1 << i));
            for (int j = i + 1; j < 26; ++j)
                if (((mask >> i) & 1) != ((mask >> j) & 1))
                    res += dfs(mask ^ (1 << i) ^ (1 << j));
        }
    }
    return res;
}
public:
    
vector<int> groupStrings(vector<string>& words) {
    int groups = 0, max_size = 0;
    for (auto &w : words)
        ++m[accumulate(begin(w), end(w), 0, [](int m, char ch){ return m | (1 << (ch - 'a')); })];
    while (!m.empty()) {
        auto size = dfs(begin(m)->first);
        max_size = max(max_size, size);
        groups += size > 0;
    }
    return { groups, max_size };
}
};