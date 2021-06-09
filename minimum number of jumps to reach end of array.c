//This is O(n) solution!!

#include<stdio.h>

//Its a short form of if-else statement!
int max(int x,int y)
{
	return (x>y)?x:y;        //Its a short form of if-else statement!
}

//Returns the minimum number of jumps.
int minJumps(int a[],int n)  //Returns the minimum number of jumps.
{
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
	
	//Initialization
	//stores all time the maximal reachable index in the array.
	int maxReach=a[0];
	
	//initialization
	//stores the number of steps we can still take
	int step=a[0];
	
	//stores the number of jumps necessary to reach that maximal reachable position.
	int jump=1;
	
	//Start traversing the array
	int i=1;
	for(i=1;i<n;i++)
	{
		
		//Check if we reached end of the array
		if(i==n-1)
		{
			return jump;
		}
		
		//updating maxReach
		maxReach=max(maxReach,i+a[i]); 
		
		//we are using a step to get the current index
		step--;
		
		//if no further steps left
		if(step==0)
		{
			//we must have used a jump
			jump++;
			
			//check if the current index/position or lesser index is the maximum reach point from the previous indexes.
			if(i>=maxReach)
			{
				return -1;
			}
		
			//re-initialize the steps to the amount of steps to reach maxReach from position i.
			step=maxReach-i;
		}
		
	}
	return -1;
}

int main()
{
int a[100],i,j,n;
printf("\t\t\nHow many elements do you want? => ");
scanf("%d",&n);
printf("\t\nPlz start filling your elements one by one.(NON NEGATIVE INTEGERS ONLY!!)");

	for(i=0;i<n;i++)
	{
		printf("\n\nElement no %d ",i+1);
		scanf("%d",&a[i]);
	}

printf("\nMinimum number of jumps to reaach the end of the array is %d",minJumps(a,n));

return 0;
}



