int characterReplacement(string s, int k) {
        
        set<char> sets;
        int size = s.size();
        for(int i=0;i<size;i++){
            sets.insert(s[i]);
        }
        char chr;
        set<char>::iterator iter;
        char ans_chr;
        int begin_index = 0;
        int end_index = 0;
        int max = -100000;
        for(iter = sets.begin();iter!= sets.end();iter++){
            chr = *iter;
            vector<int> dp(size,0);
            vector<int> first(sets.size(),0);
            int num[124];
            memset(num,0,sizeof(num));

            for(int i=1;i<size;i++){
                if(num[s[i]] == 0) first[s[i]] = i;
                if(s[i]==chr){
                    dp[i] = dp[i-1];
                    if(i==1 && s[i]!=s[i-1]) dp[i] = 1;
                }
                else{
                    if(num[s[i]] < k){
                        num[s[i]]++;
                        dp[i] = dp[i-1];
                    }
                    else{
                        if(first[s[i]] == 0){
                            dp[i] = i;
                            memset(num,0,sizeof(num));
                            first[s[i]] = i;
                        }
                        else{
                            dp[i] = first[s[i]]+1;
                            memset(num,0,sizeof(num));
                            for(int j = first[s[i]]+1;j<=i;j++){
                                if(num[s[j]] == 0){
                                    first[s[j]] = j;
                                }
                                num[s[j]]++;
                            }
                        }
                        
                        
                    }
                }
            }
            for(int i=0;i<size;i++){
                if(i-dp[i]>max){
                    begin_index = dp[i];
                    end_index = i;
                    max = i - dp[i];
                    ans_chr = chr;
                }
            }

        }
        return max+1;
}