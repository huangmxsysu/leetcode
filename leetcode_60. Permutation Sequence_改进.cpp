class Solution {
public:
    int get( int n , int k , int & yushu , vector<int> & flag , int num){
        int temp = 1 , ans = 0 , first = 0 , count = 0;
        for( int i = n-1 ; i > 0 ; i -- )   temp *= i;
        yushu = k % temp;
        if( yushu ) first = k / temp + 1;
        else{
        	yushu = temp;
			first = k / temp;
		} 
        for( int i = 1 ; i <= num ; i ++ ){
            if( flag[i] ) continue;
            count ++;
            if( count == first ){
                ans = i;
                break;
            }
        }
        return ans;
    }
    string getPermutation(int n, int k) {
        string s = "";
        vector<int> v;
        vector<int> flag( n + 1 , 0 );
        int m = n;
        while( m != 1 )
        {
            int yushu = 0;
            int first = get( m , k , yushu , flag , n );
            v.push_back(first);
            flag[first] = 1;
            k = yushu;
            m--;
        }
        for( int i = 1 ; i <= n ; i ++ ){
            if( !flag[i] ) v.push_back( i );
        }
        for( int i = 0 ; i < v.size() ; i ++ )  s += char(v[i] + '0');
        return s;
    }
};