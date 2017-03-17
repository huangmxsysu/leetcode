class Solution {
public:
    string addStrings(string num1, string num2) {
    vector<char> v;
    int size1 = num1.length();
    int size2 = num2.length();
    int flag = 0;
    if ( size1 <= size2){
        int len = size2 - size1;
        for (int i = size1-1;i>=0;i--){
            int temp = num1[i] + num2[i+len]-96;
            if(flag == 1){
                temp +=1;
            } 
            if(temp > 9){
                flag = 1;
                v.push_back(char(temp-10+'0'));
            }
            else{
                flag = 0;
                v.push_back(temp+'0');
            }
        }
        for(int j = len-1;j>=0;j--){
            int temp = num2[j]-48;
            if(flag == 1){
                 temp = temp + 1;
                
            }
            if(temp > 9){
                    flag = 1;
                    v.push_back(char(temp-10+'0'));
                }
                else{
                    flag = 0;
                    v.push_back(char(temp+'0'));
                }
            
        }
        
        if(flag == 1) v.push_back('1');
        string ans = "";
        while(!v.empty()){
            ans +=v.back();
            v.pop_back();
        }
        return ans;
    }
    

    else{
        int len = size1 - size2;
        for (int i = size2-1;i>=0;i--){
            int temp = num2[i] + num1[i+len]-96;
            if(flag == 1){
                temp +=1;
            } 
            if(temp > 9){
                flag = 1;
                v.push_back(char(temp-10+'0'));
            }
            else{
                flag = 0;
                v.push_back(temp+'0');
            }
        }
        for(int j = len-1;j>=0;j--){
            int temp = num1[j]-48;
            if(flag == 1){
                 temp = temp + 1;
                
            }
            if(temp > 9){
                    flag = 1;
                    v.push_back(char(temp-10+'0'));
                }
                else{
                    flag = 0;
                    v.push_back(char(temp+'0'));
                }
        }
        
        if(flag == 1) v.push_back('1');
        string ans = "";
        while(!v.empty()){
            ans +=v.back();
            v.pop_back();
        }
        return ans;
    }
    
}
};