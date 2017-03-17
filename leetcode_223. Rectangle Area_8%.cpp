class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int val = (C-A)*(D-B) + (G-E)*(H-F);
        if (E > C || G < A || F > D || H < B) return val;
        return val-(min(C,G) - max(A,E))*(min(D,H) - max(B,F));
    }
};