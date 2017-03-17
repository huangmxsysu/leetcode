class Solution {
struct pairhash {//double hash function for pair key

    template <typename T, typename U>
    size_t operator()(const pair<T, U> &rhs) const {
        size_t l = hash<T>()(rhs.first);
        size_t r = hash<U>()(rhs.second);
        return l + 0x9e3779b9 + (r << 6) + (r >> 2);
    }
};
public:
bool isRectangleCover(vector<vector<int>>& rectangles) {
    // step 1: counting
    unordered_map<pair<int, int>, int, pairhash> corner_count;
    int minx = INT_MAX, maxx=INT_MIN, miny=INT_MAX, maxy=INT_MIN;
    for (auto& rect : rectangles) {
        minx = min(minx, rect[0]);
        maxx = max(maxx, rect[2]);
        miny = min(miny, rect[1]);
        maxy = max(maxy, rect[3]);
        
        int& m1 = corner_count[make_pair(rect[0], rect[1])]; 
        if (m1 & 1) return false; else m1 |= 1;
        int& m2 = corner_count[make_pair(rect[2], rect[1])];
        if (m2 & 2) return false; else m2 |= 2;
        int& m3 = corner_count[make_pair(rect[0], rect[3])]; 
        if (m3 & 4) return false; else m3 |= 4;
        int& m4 = corner_count[make_pair(rect[2], rect[3])]; 
        if (m4 & 8) return false; else m4 |= 8;
    }
    
    //step2: checking
    for (const auto& kv: corner_count) {
        pair<int, int> pos; int mask;
        tie(pos, mask) = kv;
        if ((pos.first != minx && pos.first != maxx) || (pos.second != miny && pos.second != maxy)) {
            if (mask != 3 && mask != 5 && mask != 10 && mask != 12 && mask != 15) return false;
        }
    }
    return true;
}
};




class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> m;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN, area = 0, cnt = 0;
        for (auto rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[1]), 1)) return false; // bottom-left
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[3]), 2)) return false; // top-left
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[3]), 4)) return false; // top-right
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[1]), 8)) return false; // bottom-right
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            int t = it->second;
            if (t != 15 && t != 12 && t != 10 && t != 9 && t != 6 && t != 5 && t!= 3) {
                ++cnt;
            }
        }
        return cnt == 4 && area == (max_x - min_x) * (max_y - min_y);
    }
    bool isValid(unordered_map<string, int>& m, string corner, int type) {
        int& val = m[corner];
        if (val & type) return false;
        val |= type;
        return true;
    }
};

