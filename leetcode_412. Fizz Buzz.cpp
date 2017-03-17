class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int count = 0;
        vector<string> vec;
        while(count<n) {
            count++;
            if(count%15 == 0) {
            	vec.push_back("FizzBuzz");
            }
            else if(count%5 == 0) {
            	vec.push_back("Buzz");
            }
            else if(count%3 == 0) {
            	vec.push_back("Fizz");
            }
            else vec.push_back(to_string(count));
        }
        return vec;
    }
};