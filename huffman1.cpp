//huffman code
#include<iostream>
#include<conio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
	int freq;
	node *left,*right;
	string binaryCode;
	int symbolIndex; 
}*tree[20];
string code[20];
void InsertRoot(node *root,int a,int &n)
{ int i=0;
  for(i=n-1;i>=a && tree[i]->freq>root->freq;i--)
    tree[i+1]=tree[i];
    
    tree[i+1]=root;
    n++;
}

bool cmp(node *a,node *b)
{
	return a->freq<b->freq;
}

void GenerateCode(node *root,int n)
{
  if(root->left==NULL)
    code[root->symbolIndex]=root->binaryCode;
    
  else{
  	root->left->binaryCode=root->binaryCode+'0';
  	root->right->binaryCode=root->binaryCode+'1';
  	
  	GenerateCode(root->left,n);
  	GenerateCode(root->right,n);
  }  
  
}

void Huffman(int freq[],int n)
{
	for(int i=0;i<n;i++)
	{ node *P= new node;
	  P->freq=freq[i];
	  P->left=P->right=NULL;
	  P->symbolIndex=i;
	  P->binaryCode=new char[n];
	  P->binaryCode="";
	  tree[i]=P;
	}
	sort(tree,tree+n,cmp);

   node *L,*R;
   node *root;
   int a=0,m=n;
   for(int i=0;i<n-1;i++)
   { L=tree[a++];
     R=tree[a++];
     cout<<L->freq<<" "<<R->freq<<endl;
     root=new node;
     root->left=L;
     root->right=R;
     root->freq=L->freq+R->freq;
     root->binaryCode="";
     InsertRoot(root,a,m);
   }
   GenerateCode(root,n);
}

int main()
{
	char A[20];
	int n,freq[20];
	cout<<"\nEnter the no. of symbols you want to generate code for:\t";
	cin>>n;
	cout<<"\nEnter the symbols along with their frequency:\t";
    for(int i=0;i<n;i++)
	{ cin>>A[i]>>freq[i];
	
	}
	Huffman(freq,n);
	for(int i=0;i<n;i++)
	cout<<A[i]<<"="<<code[i]<<endl;
	return 0;	
}
