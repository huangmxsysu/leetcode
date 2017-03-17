class Solution {
public:
	int read_int(int pos1,int pos2 = 10,int pos3 = 10){
    int temp = 0;
    if(pos1 == 10){
        return 0;
    }
    else if(pos2 == 10 && pos3 == 10){
        temp = pow(2,pos1);
    }
    else if(pos2!=10 && pos3 == 10){
        temp = pow(2,pos1)+pow(2,pos2);
    }
    else{
        temp = pow(2,pos1)+pow(2,pos2)+pow(2,pos3);
    }
    return temp;
    
}
string read_string(int flag,bool rev,int pos1,int pos2=10, int pos3=10){
    string s="";
    int temp = 0;
    temp = read_int(pos1,pos2,pos3);
    if(rev == false){
        temp = temp;
    }
    else{
        if(flag == 0){
            temp = 15-temp;
        }
        else{
            temp = 63-temp;
        }
    }
    if(temp>9){
        s += char(temp/10+'0');
        s += char(temp%10+'0');
    }
    else{
        if(flag == 1) 
            s+=char('0');
        s += char(temp + '0');
    }
    return s;
}
struct P{
    int a0,a1,a2;
    P(int b1,int b2,int b3){
        a0 = b1;
        a1 = b2;
        a2 = b3;
    }
};
vector<string> readBinaryWatch(int num) {

    vector<string> v_s;
    if(num==0) v_s.push_back("0:00");
    else{
        int i = num;
        int j = 0;
        vector<P> a[3],b[4];
        a[0].push_back(P(10,10,10));

        a[1].push_back(P(0,10,10));
        a[1].push_back(P(1,10,10));
        a[1].push_back(P(2,10,10));

        a[2].push_back(P(0,1,10));
        a[2].push_back(P(1,2,10));
        a[2].push_back(P(2,3,10));
        a[2].push_back(P(0,2,10));
        a[2].push_back(P(1,3,10));

        b[0].push_back(P(10,10,10));

        b[1].push_back(P(0,10,10));
        b[1].push_back(P(1,10,10));
        b[1].push_back(P(2,10,10));
        b[1].push_back(P(3,10,10));
        b[1].push_back(P(4,10,10));
        b[1].push_back(P(5,10,10));
        b[2].push_back(P(0,1,10));
        b[2].push_back(P(1,2,10));
        b[2].push_back(P(2,3,10));
        b[2].push_back(P(3,4,10));
        b[2].push_back(P(4,5,10));
        b[2].push_back(P(0,2,10));
        b[2].push_back(P(1,3,10));
        b[2].push_back(P(2,4,10));
        b[2].push_back(P(3,5,10));
        b[2].push_back(P(0,3,10));
        b[2].push_back(P(1,4,10));
        b[2].push_back(P(2,5,10));
        b[2].push_back(P(0,4,10));
        b[2].push_back(P(1,5,10));
        b[2].push_back(P(0,5,10));
        b[3].push_back(P(0,1,2));
        b[3].push_back(P(1,2,3));
        b[3].push_back(P(2,3,4));
        b[3].push_back(P(3,4,5));
        b[3].push_back(P(0,1,3));
        b[3].push_back(P(0,1,4));
        b[3].push_back(P(0,1,5));
        b[3].push_back(P(1,2,4));
        b[3].push_back(P(1,2,5));
        b[3].push_back(P(0,2,3));
        b[3].push_back(P(2,3,5));
        b[3].push_back(P(0,3,4));
        b[3].push_back(P(1,3,4));
        b[3].push_back(P(0,4,5));
        b[3].push_back(P(1,4,5));
        b[3].push_back(P(2,4,5));
        b[3].push_back(P(0,2,4));
        b[3].push_back(P(0,2,5));
        b[3].push_back(P(0,3,5));
        b[3].push_back(P(1,3,5));
         while(i>6){
            i--;
            j++;
        }
        while(j<=4&&j>=0&&i<=6&&i>=0){
            int len1 = 0,len2 = 0;
            string s1[20],s2[20];

            if(j<=2){
                for(int h = 0;h < a[j].size();h++){
                    s1[h] = read_string(0,false,a[j][h].a0,a[j][h].a1,a[j][h].a2);
                    len1 = h;
                }
            }
            else if(j>2){
                for(int h = 0;h<a[4-j].size();h++){
                    s1[h] = read_string(0,true,a[4-j][h].a0,a[4-j][h].a1,a[4-j][h].a2);
                    len1 = h;
                }
            }
            if(i<=3){
                for(int g = 0;g < b[i].size();g ++){
                    s2[g]=read_string(1,false,b[i][g].a0,b[i][g].a1,b[i][g].a2);
                    len2 = g;
                }
            }
            else if(i>3){
                for(int g = 0;g < b[6-i].size();g ++){
                    s2[g]=read_string(1,true,b[6-i][g].a0,b[6-i][g].a1,b[6-i][g].a2);
                    len2 = g;
                }

            }
            len1++;
            len2++;
            for(int k1 = 0;k1<len1;k1++){
                for(int k2 = 0;k2<len2;k2++){
                    string s = "";
                    if(s2[k2].size() == 2 && s2[k2][0] == '6'){
                        continue;
                    }
                    if(s1[k1].size() == 2 && s1[k1][1] >= '2'){
                        continue;
                    }

                    s = s1[k1] + ":" + s2[k2];

                    v_s.push_back(s);
                }
            }
            j++;
            i--;
        }
    }
    return v_s;

    
}
};