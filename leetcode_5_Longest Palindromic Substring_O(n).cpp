public class Solution {
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    String preProcess(String s) {
        int n = s.length();
        if (n == 0) return "^$";

        String ret = "^";
        for (int i = 0; i < n; i++)
        {
            ret += "#" + s.substring(i, i + 1);
        }
        
        ret += "#$";
        return ret;
    }
    public String longestPalindrome(String s) {
        String T = preProcess(s);
        int length = T.length();
        int[] p = new int[length];
        int C = 0, R = 0;
        
        for (int i = 1; i < length - 1; i++)
        {
            int i_mirror = C - (i - C);
            int diff = R - i;
            if (diff >= 0)//当前i在C和R之间，可以利用回文的对称属性
            {
                if (p[i_mirror] < diff)//i的对称点的回文长度在C的大回文范围内部
                { p[i] = p[i_mirror]; }
                else
                {
                    p[i] = diff;
                    //i处的回文可能超出C的大回文范围了
                    while (T.charAt(i + p[i] + 1) == T.charAt(i - p[i] - 1))
                    { p[i]++; }
                    C = i;
                    R = i + p[i];
                }
            }
            else
            {
                p[i] = 0;
                while (T.charAt(i + p[i] + 1) == T.charAt(i - p[i] - 1))
                { p[i]++; }
                C = i;
                R = i + p[i];
            }
        }

        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < length - 1; i++) {
            if (p[i] > maxLen) {
              maxLen = p[i];
              centerIndex = i;
            }
        }
        return s.substring((centerIndex - 1 - maxLen) / 2, (centerIndex - 1 - maxLen) / 2 + maxLen);        
    }
}

Manacher's