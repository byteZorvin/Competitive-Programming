class Solution {
public:
    map<string, string> m;
    int count;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = to_string(count++);
        m[code] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));