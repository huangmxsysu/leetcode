string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    int startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);//这些操作全都返回 string::size_type 类型的值，
        //以下标形式标记查找匹配所发生的位置；或者返回一个名为 string::npos 的特殊值，
        //说明查找没有匹配。string 类将 npos 定义为保证大于任何有效下标的值。
    }
    return "0";
}