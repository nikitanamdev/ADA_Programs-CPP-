#include<iostream>
#include<conio.h>

using namespace std;

int n;
int timeslot[50],d[50],j[50],p[50];

int min(int d[],int n)
{ int m=d[0];
  for(int i=1;i<n;i++)
  { if(m>d[i])
    m=d[i];
  }
  return m;
}

int max(int d[],int n)
{ int m=d[0];
  for(int i=1;i<n;i++)
  { if(m<d[i])
    {  m=d[i];
    }
  }
  return m; 
}
void Job_scheduling(int d[],int n)
{  int k,min1;
   int maxi=max(d,n);
   if(n<maxi)
   min1=n;
   else
   min1=maxi; 
   
   for(int i=0;i<min1;i++)
    { timeslot[i]=0;
	}
	
	for(int u=0;u<n;u++)
	{  if(n<d[u])
	    k=n-1;
	    else
	    k=d[u]-1;
	    
	    while(k>=0)
	    { if(timeslot[k]==0)
	       { timeslot[k]=j[u];
	         break; 
		   }
		   k=k-1;
		}
	    
	}
	cout<<"\nJobs will be scheduled as:";
	for(int i=0;i<min1;i++)
	cout<<timeslot[i]<<" ";
}
int main()
{  int j1[50],d1[50],p1[50];
  cout<<"Enter the total number of jobs:\t";
  cin>>n;
  cout<<"\nEnter the values of jobs(in terms of 1/2/3..n):\t";
  for(int i=0;i<n;i++)
  { cin>>j[i];
  }
  cout<<"\nEnter the corresponding deadlines across the job: ";
  for(int i=0;i<n;i++)
  { cin>>d[i];
  }
  cout<<"\nEnter the profit across each job:\t";
  for(int i=0;i<n;i++)
  { cin>>p[i];
  }
   int min , pos;
    
   for (int i = 0; i < n; i++)
   {   min = p[i];
       pos = i;
       for(int j = i+1; j < n; j++)
	   { if(p[j] > min)
	     { min = p[j];
		   pos = j; 
	     }
	   } 
	   int t1,t2,t3;
	   t1 = p[i];
	   t2 = d[i];
	   t3 = j[i]; 
	   p[i] = p[pos];
	   d[i] = d[pos];
	   j[i] = j[pos];
	   p[pos] = t1;
	   d[pos] = t2;
	   j[pos] = t3;
   }
  /* for(int i=0,k=n;i<n;i++,k--)
   { j1[i]=j[k];
     d1[i]=d[k];
	 p1[i]=p[k]; 
   }
   */
   cout<<"\nThe sequence of jobs on the basis of decreasing profit:";
   for(int i=0;i<n;i++)
   { cout<<j[i]<<" "<<d[i]<<" "<<p[i]<<endl;
   }
   Job_scheduling(d,n);
   return 0;
}
