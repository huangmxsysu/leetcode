struct pairhash {   //double hash function for pair key
        template <typename T, typename U>
        size_t operator()(const pair<T, U> &p) const {
            size_t l = hash<T>()(p.first), r = hash<U>()(p.second);
            return l + 0x9e3779b9 + (r << 6) + (r >> 2);
        }
    };
    
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int area = 0, xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;
        unordered_map<pair<int, int>, int, pairhash> m;
        
        // Calculate area, and count points of appearances
        vector<pair<int, int>> points = {{0, 1}, {0, 3}, {2, 3}, {2, 1}};
        for (auto v : rectangles) {
            for (auto point : points) {
                if (++m[make_pair(v[point.first], v[point.second])] > 4) { return false; }
            }
            area += (v[2] - v[0]) * (v[3] - v[1]);
            xmin = min(xmin, v[0]), ymin = min(ymin, v[1]), xmax = max(xmax, v[2]), ymax = max(ymax, v[3]);
        }
        if (area != (xmax - xmin) * (ymax - ymin)) { return false; }
        
        // Check if points appearing odd number of times are exactly large rectangles' 4 corners
        unordered_set<pair<int, int>, pairhash> s = {{xmin, ymin}, {xmin, ymax}, {xmax, ymax}, {xmax, ymin}};
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second & 1 == 1) {
                if (s.count(it->first) > 0) {
                    s.erase(it->first); 
                } else {
                    return false;
                }
            }
        }
        return s.empty();
    }