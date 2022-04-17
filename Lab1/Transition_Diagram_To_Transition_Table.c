#include<stdio.h>
#include<stdlib.h>
struct setStates
{
	int state;
	int final; // 0 - NO    1 - YES
	int start; // 0 - NO    1 - YES
};
typedef struct setStates sstate; 
int main()
{
	int s,v,i,j;
	int **sv,*var; 
	sstate *states;

	printf("\nInput the number of finite set of states : ");
	scanf("%d",&s);
	printf("\nInput the number of finite set of input variables : ");
	scanf("%d",&v);
	sv = (int **)malloc(v*sizeof(int));
	for(i=0;i<s;i++)
	{
		sv[i]=(int *)malloc(sizeof(int));
	}
	states = (sstate *)malloc(s*sizeof(sstate));
	printf("\nInput the states and its info (state start final): \n");
	for(i=0;i<s;i++)
	{
		scanf("%d%d%d",&states[i].state,&states[i].start,&states[i].final);
	}	 
	var = (int *)malloc(v*sizeof(int));
	printf("\nInput the veriables : \n");
	for(i=0;i<v;i++)
	{
		scanf("%d",&var[i]);
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("\nThe sates %c with input veribale %c move to state : ",states[i].state,var[j]);
			scanf("%d",&sv[i][j]);
		}
	}
	printf("\nThe Transition Table : \n");
	printf("\t");
	for(i=0;i<v;i++)
	{
		printf("%c\t",var[i]);
	}	
	printf("\n------------------------------------------------");
	for(i=0;i<s;i++)
	{
		printf("\n%c  %c  %c\t",states[i].state,(states[i].start==0)?' ':'$',(states[i].final==0)?' ':'*');
		for(j=0;j<v;j++)
		{
			printf("%c\t",sv[i][j]);
		}
		printf("\n");
	}
	return 0;
}
// Input
Input the number of finite set of states : 4
Input the number of finite set of input veriables : 2

Input the states and its info (state start final):
97 1 1
98 0 0
99 0 0
100 0 0

Input the variables :
48
49

The sates a with input variable 0 move to state : 98
The sates a with input variable 1 move to state : 99
The sates b with input variable 0 move to state : 100
The sates b with input variable 1 move to state : 97
The sates c with input variable 0 move to state : 97
The sates c with input variable 1 move to state : 100
The sates d with input variable 0 move to state : 100
The sates d with input variable 1 move to state : 98
// Output
The Transition Table :
        0       1
------------------------------------------------
a  $  * b       c

b       d       a

c       a       d

d       d       b
// Alg
Algorithm:
- Start
- Enter the number of states.
- Enter the number of input variables.
- Enter the state and its information.
- Enter the input variables.
- Enter the transition function information i.e. transition value from a state with a input variable.
- Show the Transition Table.
- Stop
