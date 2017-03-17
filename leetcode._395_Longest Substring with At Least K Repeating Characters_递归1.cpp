int longestSubstring(const string &s, int k) {
    return helper(s, 0, s.size(), k);
}
int helper(const string &s, int beg, int end, int k){
    if(end - beg < k) return 0;
    int cnt[26]{};
    for(int i = beg; i < end; ++i) ++cnt[s[i]-'a'];
    for(int i = 0; i < 26; ++i)
        if (cnt[i] && cnt[i] < k)
            for(int j = beg; j < end; ++j)
                if(s[j] == i + 'a')
                    return max(helper(s, beg, j, k), helper(s, j + 1, end, k));
    return end - beg;
}