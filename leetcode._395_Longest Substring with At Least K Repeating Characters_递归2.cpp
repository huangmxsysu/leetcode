int longestSubstring(const string &s, int k) {
    return helper(s, 0, s.size(), k);
}
int helper(const string &s, int beg, int end, int k){
    if(end - beg < k) return 0;
    int cnt[26]{};
    for(int i = beg; i < end; ++i) ++cnt[s[i]-'a'];
    for(int i = beg; i < end; ++i)
        if (cnt[s[i] - 'a'] < k)
            return max(helper(s, beg, i, k), helper(s, i + 1, end, k));
    return end - beg;
}