//strassen matrix multiplication
#include<iostream>
#include<conio.h>
using namespace std;

void strassen(int a[40][40],int b[40][40],int n,int c[40][40])
{
 if(n==1)
  {   c[0][0]=a[0][0]*b[0][0];
   }
  else
  { int a11[40][40];
    int a12[40][40];
    int a21[40][40];
    int a22[40][40];
    int b11[40][40];
    int b12[40][40];
    int b21[40][40];
    int b22[40][40];
    int k,l;
    int m=0;
    int h=0;
    for(k=0;k<n/2;k++)
     {
       for(l=0;l<n/2;l++)
	{
	  a11[m][h]=a[k][l];
	  b11[m][h]=b[k][l];
	  h++;
	  }
	  m++;
	  }
	  m=0;
	  h=0;
	  for(k=n/2;k<n;k++)
	{
       for(l=n/2;l<n;l++)
	{
	  a22[m][h]=a[k][l];
	  b22[m][h]=b[k][l];
	  h++;
	  }
	  m++;
	  }
	  m=0;h=0;
	  for(k=0;k<n/2;k++)
	{
       for(l=n/2;l<n;l++)
	{
	  a12[m][h]=a[k][l];
	  b12[m][h]=b[k][l];
	  h++;
	  }
	  m++;
	  }
	  m=0;
	  h=0;
	  for(k=n/2;k<n;k++)
	{
       for(l=0;l<n/2;l++)
	{
	  a21[m][h]=a[k][l];
	  b21[m][h]=b[k][l];
	  h++;
	  }
	  m++;
	  }
	  int p1[40][40];
	  int p2[40][40];
	  int p3[40][40];
	  int p4[40][40];
	  int p5[40][40];
	  int p6[40][40];
	  int p7[40][40];
	  int r1[40][40];
	  int r2[40][40];
	  int r3[40][40];
	  int r4[40][40];
	  int r5[40][40];
	  int r6[40][40];
	  int r7[40][40];
	  int r8[40][40];
	  int r9[40][40];
	  int r10[40][40];
	  int c11[40][40];
	  int c12[40][40];
	  int c21[40][40];
	  int c22[40][40];
	  for(int y=0;y<n/2;y++)
	   {
	     for(int d=0;d<n/2;d++)
	      {
		r1[y][d]=a11[y][d]+a22[y][d];
		}
	    }
	    for(int y1=0;y1<n/2;y1++)
	   {
	     for(int d1=0;d1<n/2;d1++)
	      {
		r2[y1][d1]=b11[y1][d1]+b22[y1][d1];
		}
	    }
	    strassen(r1,r2,n/2,p1);
	    for(int y2=0;y2<n/2;y2++)
	   {
	     for(int d2=0;d2<n/2;d2++)
	      {
		r3[y2][d2]=a21[y2][d2]+a22[y2][d2];
		}
	    }
	    strassen(r3,b11,n/2,p2);
	    for(int y3=0;y3<n/2;y3++)
	   {
	     for(int d3=0;d3<n/2;d3++)
	      {
		r4[y3][d3]=b12[y3][d3]-b22[y3][d3];
		}
	    }
	    strassen(a11,r4,n/2,p3);
	    for(int y4=0;y4<n/2;y4++)
	   {
	     for(int d4=0;d4<n/2;d4++)
	      {
		r5[y4][d4]=b21[y4][d4]-b11[y4][d4];
		}
	    }
	    strassen(a22,r5,n/2,p4);
	    for(int y5=0;y5<n/2;y5++)
	   {
	     for(int d5=0;d5<n/2;d5++)
	      {
		r6[y5][d5]=a11[y5][d5]+a12[y5][d5];
		}
	    }
	    strassen(r6,b22,n/2,p5);
	    for(int y6=0;y6<n/2;y6++)
	   {
	     for(int d6=0;d6<n/2;d6++)
	      {
		r7[y6][d6]=a21[y6][d6]-a11[y6][d6];
		}
	    }
	    for(int y7=0;y7<n/2;y7++)
	   {
	     for(int d7=0;d7<n/2;d7++)
	      {
		r8[y7][d7]=b11[y7][d7]+b12[y7][d7];
		}
	    }
	    strassen(r7,r8,n/2,p6);
	    for(int y8=0;y8<n/2;y8++)
	   {
	     for(int d8=0;d8<n/2;d8++)
	      {
		r9[y8][d8]=a12[y8][d8]-a22[y8][d8];
		}
	    }
	    for(int y9=0;y9<n/2;y9++)
	   {
	     for(int d9=0;d9<n/2;d9++)
	      {
		r10[y9][d9]=b21[y9][d9]+b22[y9][d9];
		}
	    }
	    strassen(r9,r10,n/2,p7);

	   for(int g=0;g<n/2;g++)
	    {
	       for(int x=0;x<n/2;x++)
		{
		  c11[g][x]=(p1[g][x]+p4[g][x])-p5[g][x]+p7[g][x];
		  c12[g][x]=p3[g][x]+p5[g][x];
		  c21[g][x]=p2[g][x]+p4[g][x];
		  c22[g][x]=p1[g][x]+p3[g][x]+p6[g][x]-p2[g][x];
		  }
		  }
		  m=0;h=0;
		  for(k=0;k<n/2;k++)
     {
       for(l=0;l<n/2;l++)
	{
	  c[k][l]=c11[m][h];
	  h++;
	  }
	  m++;
	  }
	  m=0;
	  h=0;
	  for(k=n/2;k<n;k++)
	{
       for(l=n/2;l<n;l++)
	{
	    c[k][l]=c22[m][h];
		  h++;
	  }
	  m++;
	  }
	  m=0;h=0;
	  for(k=0;k<n/2;k++)
	{
       for(l=n/2;l<n;l++)
	{
	  c[k][l]=c12[m][h];
	  h++;
	  }
	  m++;
	  }
	  m=0;
	  h=0;
	  for(k=n/2;k<n;k++)
	{
       for(l=0;l<n/2;l++)
	{
	  c[k][l]=c21[m][h];

	  h++;
	  }
	  m++;
	  }
   }
}

int main()
{
 int n;
 cout<<"enter the size of matrix\n";
 cin>>n;
 int a[40][40];
 int b[40][40];
 int i,j,k;
 cout<<"now enter the elements for the first matrix\n";
	for(i=0;i<n;i++)
	  {
	    for(j=0;j<n;j++)
	     {
		cin>>a[i][j];
		}
	    }
 cout<<"\nEnter the elements for the second matrix\n";	    
	    for(i=0;i<n;i++)
	  {
	    for(j=0;j<n;j++)
	     {
		cin>>b[i][j];
		}
	    }
	    int c[40][40];
  strassen(a,b,n,c);
  for(int f=0;f<n;f++)
   {
     for(int u=0;u<n;u++)
     {
	cout<<c[f][u]<<" ";
	}
	}
  return 0;

  }
