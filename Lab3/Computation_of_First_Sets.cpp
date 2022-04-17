#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
using namespace std;
void searchFirst(int n, int i, char pl[], char r[], char result[], int k)
{
	int j,flag;
	for(j=i+1;j<n;j++)
	{
		if(r[i]==pl[j])
		{
			if(isupper(r[j]))
			{
				searchFirst(n,j,pl,r,result,k);
			}
			if(islower(r[j]) || r[j]== '+' || r[j]=='*' || r[j]==')' || r[j]=='(')
			{
				result[k++]=r[j];
				result[k++]=','; flag=0;
			}
		}
	}
	if(flag==0)
	{
		for(j=0;j<k-1;j++)cout<<result[j];
	}
}
int main()
{
    char pr[10][10],pl[10],r[10],prev,result[10];
	int i,n,k,j;
	cout<<"\nHow many production rule : ";
	cin>>n;
	if(n==0) exit(0);
	for(i=0;i<n;i++)
	{
		cout<<"\nInput left part of production rules : ";
		cin>>pl[i];
		cout<<"\nInput right part of production rules : ";
		cin >> pr[i];
		r[i]=pr[i][0];
	}
	cout<<"\nProduction Rules are : \n";
	for(i=0;i<n;i++)
	{
		cout<<pl[i]<<"->"<<pr[i]<<"\n";
	}
	cout<<"\n----O U T P U T---\n\n";
	prev=pl[0];k=0;
	for(i=0;i<n;i++)
	{
		if(prev!=pl[i])
		{
			cout<<"\nFIRST("<<prev<<")={";
			for(j=0;j<k-1;j++)cout<<result[j];
			cout<<"}";
			k=0;prev=pl[i];
		}
		if(prev==pl[i])
		{
			if(islower(r[i]) || r[i]== '+' || r[i]=='*' || r[i]==')' || r[i]=='(')
			{
				result[k++]=r[i];
				result[k++]=',';
			}
			if(isupper(r[i]))
			{
				cout<<"\nFIRST("<<prev<<")={";
				searchFirst(n,i,pl,r,result,k);
				cout<<"}";
				k=0;prev=pl[i+1];
			}
		}
	}
	if(i==n)
	{
		cout<<"\nFIRST("<<prev<<")={";
		for(j=0;j<k-1;j++)cout<<result[j];
		cout<<"}";
		k=0;prev=pl[i];
	}
	return 0;
}
// Input
How many production rule : 8

Input left part of production rules : E
Input right part of production rules : TX
Input left part of production rules : X
Input right part of production rules : +TX
Input left part of production rules : X
Input right part of production rules : e
Input left part of production rules : T
Input right part of production rules : FY
Input left part of production rules : Y
Input right part of production rules : *FY
Input left part of production rules : Y
Input right part of production rules : e
Input left part of production rules : F
Input right part of production rules : (E)
Input left part of production rules : F
Input right part of production rules : i


// Output
Production Rules are :
E->TX
X->+TX
X->e
T->FY
Y->*FY
Y->e
F->(E)
F->i

----O U T P U T---

FIRST(E)={(,i}
FIRST(X)={+,e}
FIRST(T)={(,i}
FIRST(Y)={*,e}
FIRST(F)={(,i}

// Alg
Procedure First
- Input the number of production N.
- Input all the production rule PArray
- Repeat steps a, b, c until process all input production rule i.e. PArray[N]
  a. If X i ≠ X i+1 then
  i. Print Result array of X i which contain FIRST(X i )
  b. If first element of X i of PArray is Terminal or ε Then
  i. Add Result = Result U first element
  c. If first element of X i of PArray is Non-Terminal Then
  i. searchFirst(i, PArray, N)

- End Loop
- If N (last production) then
  a. Print Result array of X i which contain FIRST(X i )
- End

Procedure searchFirst(i, PArray, N)
- Repeat steps Loop j=i+1 to N
  a. If first element of X j of PArray is Non-Terminal Then
  i. searchFirst(j, of PArray, N)
  b. If first element of X j of PArray is Terminal or ε Then
  i. Add Result = Result U first element
  ii. Flag=0

- End Loop
- If Flag = 0 Then
  a. Print Result array of X j which contain FIRST(X j )
- End
