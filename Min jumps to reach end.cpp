/*
MY LOGIC:

in terms of jumps hi khelo yaani actually jump karne ki jarurat nhi

jumps minimum rakhne ke liye maximum possible distance cover karo(GREEDY)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int a[], int n){
        // Your code here
        /*
        {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
         |
       
        
        */
        
         
        int Max=0;
        int jump=0;
        int halt=0;
        
        //The number of jumps needed to reach the starting index 0.
	    if(n<=1)
	    {
		    return 0;
	    }
	
	    //Return -1 if not possible to jump
	    if(a[0]==0)
	    {
		    return -1;
	    }
	    
	    for(int i=0;i<n-1;i++)
	    {
	        Max=max(Max,i+a[i]);
	        if(Max>=n-1)
	        {
	            jump++;
	            return jump;
	        }
	        if(i==halt)
	        {
	            halt=Max;
	            jump++;
	        }
	    }
	    
	    if(halt>=n-1)
	    {
	        return jump;
	    }
	    else
	    {
	        return -1;
	    }
	    
	    
	    
    }
};



int main()
{
	int arr[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"\nANSWER => "<<MinJumps(arr,n);
	
}
