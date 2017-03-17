class Solution {
public:
    bool isPerfectSquare(int num) {
  		      if( num == 0 ) return true;
  		      if( num < 46341 ) return dfs(1,num,num,num-1);
  		      else
  		      return dfs( 1 , 46340 , num , 46339 ); 
    }
    bool dfs( int low , int high , int target , int step )
    {
    	if( step == 1 ) {
    		for( int i = low ; i < high ; i ++ ){
    			if( i * i == target ) return true;
    		}
    		return false;
    	}
    	int i,flag = 0;
    	for( i = low ; i <= high ; i += step )
    	{ 
    		if( i * i == target ) return true; 
    		if( i * i > target ){
    			flag = 1;
    			break;
    		} 
    	}
    	if( flag == 1) return dfs( i - step , i , target , step/2 );
    	return false;
    	
    }
};