//simultaneous min max
#include<iostream>
#include<conio.h>

using namespace std;

struct Pair
{ int min=0;
  int max=0;
};

Pair MaxMin(int A[],int first,int last)
{ Pair minmax;
  Pair minmax1;
  Pair minmax2;

  int mid;
  if(first==last)
   { minmax.max=A[first];
     minmax.min=A[first];
     
     return minmax;
   }
   
   else if(first==last-1)
   { if(A[first]>A[last])
      { minmax.max=A[first];
        minmax.min=A[last];
      }
      else
      { minmax.max=A[last];
        minmax.min=A[first];
	  }
	  return minmax;
   }
   
   else{ mid=(first+last)/2;
         minmax1=MaxMin(A,first,mid);
		 minmax2=MaxMin(A,mid+1,last);
	    
		if(minmax1.max>minmax2.max)
		  minmax.max=minmax1.max;
		else
		  minmax.max=minmax2.max;
		  
		if(minmax1.min<minmax2.min)
		  minmax.min=minmax1.min;
		else
		  minmax.min=minmax2.min;
		         
	 return minmax;		  
       }
}

int main()
{ int A[20],size;
  Pair Min_Max;
  cout<<"Enter the total number of elements in the array-";
  cin>>size;
  
  cout<<"\nNow enter the elements in the array-";
  for(int i=0;i<size;i++)
  cin>>A[i];
  
  Min_Max=MaxMin(A,0,size-1);
  
  cout<<"\nThe maximum element in the array is-"<<Min_Max.max;
  cout<<"\nThe minimum element in the array is-"<<Min_Max.min;
  
  return 0;   
}
