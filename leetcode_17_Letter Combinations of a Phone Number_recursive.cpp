class Solution {
public:
    vector<string> vec = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        backtracking(ans, "", 0, digits);
        return ans;
    }
    void backtracking(vector<string>& ans, string str, int index, string& digits){
        if(str.size() == digits.size()){
            if(str.size() != 0) ans.push_back(str);
            return;
        }
        int id = digits[index] - '0';
        for(int i = 0; i < vec[id].size(); i++){
            backtracking(ans, str + vec[id][i], index + 1, digits);
        }
    }
};