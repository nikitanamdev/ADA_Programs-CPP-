//disjoint set program
#include<iostream>
#include<conio.h>

using namespace std;
int Parent[20],Rank[20];

void MakeSet(int x)
{ Parent[x]=x;
  Rank[x]=0;
}

int FindSet(int x)
{ if(x!=Parent[x])
  Parent[x]=FindSet(Parent[x]);
  
  return Parent[x];
}

void Union(int x,int y)
{ int rep1=FindSet(x);
  int rep2=FindSet(y);
  
  if(Rank[rep1]>Rank[rep2])
   { 
     Parent[rep2]=rep1;
   }
  else if(Rank[rep1]<Rank[rep2])
    {
	  Parent[rep1]=rep2;
    }
   else
    { Parent[rep2]=rep1;
      Rank[rep1]=Rank[rep1]+1;
    }
  cout<<"\nParent of x-"<<Parent[x];
  cout<<"\nParent of y-"<<Parent[y];  
    
}

	
int main()
{ int x,y,n,i,j;
  
  int ch;
  char ch1;
  
  do{
   	
  cout<<"\nEnter 1 to make the set.";
  cout<<"\nEnter 2 to find an element. ";
  cout<<"\nEnter 3 to make union of the two sets.";
  
  cout<<"\nEnter your choice:\t";
  cin>>ch;
  
  if(ch==1)
  {
    cout<<"\nEnter the element you want to make set of:\t";
    cin>>x;
	MakeSet(x);
	
  }
  
  if(ch==2)
  { cout<<"\nEnter the element you want to search :";
    cin>>n;
    int F=FindSet(n);
    cout<<F;
    /*for(int a=1;a<range;a++)
    { cout<<Parent[a];
	}*/
    
  }
  
  if(ch==3)
  { cout<<"\nEnter the elements of the sets you want to unite.";
    cin>>i;
    cin>>j;
    Union(i,j);
    
  }
  cout<<"\nDo you want to perform more operations?(y/n)";
  cin>>ch1;
  
  }while(ch1=='y'||ch1=='Y');
  
  return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	   
	  

