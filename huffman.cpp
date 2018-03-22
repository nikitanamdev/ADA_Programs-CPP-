//Huffman Coding
#include<iostream>
#include<conio.h>
#include<queue>

using namespace std;

struct Node
  {	int freq;
	Node *left,*right;
	int symbolIndex;
    int binaryCode;	
  };
int code[10]; 
Node *tree[10];
struct node_cmp
{
   bool operator()( const Node* a, const Node* b ) const 
   {
    return a->freq < b->freq;
   }
};
/*void CreatePriorityQueue(Node *tree[], int count)
{ priority_queue<Node*,vector<Node*>,greater<int> > h;

		if(count==5){
			return;
		}
		h.push(tree[count]);
		CreatePriorityQueue(tree,count+1);
}*/
void GenerateCode(Node *root,int code[])
{ if(root->left==NULL)
  code[root->symbolIndex]=root->binaryCode;
  
  else
  { root->left->binaryCode=root->binaryCode<<1;//left shift to add 0
    root->right->binaryCode=(root->binaryCode<<1)+1;
    GenerateCode(root->left,code);
    GenerateCode(root->right,code);
  }
}
void Huffman(char A[],int freq[],int n)
{
  priority_queue<Node*,vector<Node*>,node_cmp > h; 
for(int i=0;i<n;i++)
  { Node *P=new Node;
    P->freq=freq[i];
    P->left=NULL;
    P->right=NULL;
    P->symbolIndex=i;
    P->binaryCode=' ';
    tree[i]=P;
		h.push(tree[i]);
  }
  
  	Node *root = new Node;
  for(int i=0;i<n;i++){
  	Node *L = h.top();
	  h.pop();
  	Node *R = h.top();
  	  h.pop();
  	root->left = L;
  	root->right = R;
  	root->freq = L->freq + R->freq;
  	root->binaryCode = ' ';
  	h.push(root);
  }
  GenerateCode(root,code);
}

int main(){
	int freq[] = {10,5,20,2,3};
	char A[] = {'a','b','c','d','e'};
	Huffman(A,freq,5);
	return 0;
}
