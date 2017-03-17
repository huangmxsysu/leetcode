int miss = 0, i = 0;
    for (int num : nums)
        miss += ++i - num;
    return miss;