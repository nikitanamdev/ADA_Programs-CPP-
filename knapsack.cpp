#include<iostream>
#include<conio.h>


using namespace std;
void Frac_Knapsack(float V[],float W[],float C,int n)
{ float v[10];
  for(int i=0;i<n;i++)
  { v[i]=V[i]/W[i];
   // cout<<v[i]<<endl;
  }
  float max;
  int pos;
    
   for (int i = 0; i < n; i++)
   {   max = v[i];
       pos = i;
       for(int j = i+1; j < n; j++)
	   { if(v[j] > max)
	     { max= v[j];
		   pos = j; 
	     }
	   } 
	   float t1,t2,t3;
	   t1 = v[i];
	   t2 = W[i];
	   t3 = V[i]; 
	   v[i] = v[pos];
	   W[i] = W[pos];
	   V[i] = V[pos];
	   v[pos] = t1;
	   W[pos] = t2;
	   V[pos] = t3;
   }
   for(int i=0;i<n;i++)
   { cout<<endl;
     cout<<v[i]<<" "<<V[i]<<" "<<W[i]<<endl;
   }
  float currw=0;
  float value=0;
  for(int i=0;i<n;i++)
  {   if(currw+W[i]<=C)
      {currw+=W[i];
       value+=V[i];
      } 
      else{
            float remain=C-currw;
            value=value+V[i]*(remain/W[i]);
            currw+=remain;
  }
  //cout<<"\nThe final value is "<<value;
  
}
cout<<"\nThe final value is "<<value;
}

int main()
{ float V[10],W[10];
  float C,n;
  cout<<"Enter the total number of items:";
  cin>>n;
  cout<<"\nEnter the capacity of Knapsack:";
  cin>>C;
  cout<<"\nEnter the values of the items:";
  for(int i=0;i<n;i++)
  cin>>V[i];
  cout<<"\nNow enter the weight of the corresponding items:";
  for(int i=0;i<n;i++)
  cin>>W[i];
  
  Frac_Knapsack(V,W,C,n);
  return 0;
}
