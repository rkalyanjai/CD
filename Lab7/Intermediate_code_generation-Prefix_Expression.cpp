#include<bits/stdc++.h>
using namespace std;
char s[50];
int top=-1; /* Global declarations */
void push(char elem)
{ /* Function for PUSH operation */
 s[++top]=elem;
}
char pop()
{ /* Function for POP operation */
 return(s[top--]);
}
int pr(char elem)
{ /* Function for precedence */
 switch(elem)
 {
 case '#': return 0;
 case ')': return 1;
 case '+':
 case '-': return 2;
 case '*':
 case '/': return 3;
 }
 return -1;
}

int main()
{ /* Main Program */
 string infx,prfx;
 char ch,elem;
 int i=0,k=0;
 cout << "Read the Infix Expression : ";
 cin >> infx;
 push('#');
 reverse(infx.begin(), infx.end());
 while( (ch=infx[i++]) != '\0')
 {
 if( ch == ')') push(ch);
 else
 if(isalnum(ch)) prfx[k++]=ch;
 else
 if( ch == '(')
 {
 while( s[top] != ')')
 prfx[k++]=pop();
 elem=pop(); /* Remove ) */
 }
 else
 { /* Operator */
 while( pr(s[top]) >= pr(ch) )
 prfx[k++]=pop();
 push(ch);
 }
 }
 while( s[top] != '#') /* Pop from stack till empty */
 prfx[k++]=pop();
 prfx[k]='\0'; /* Make prfx as valid string */
 reverse(prfx.begin(), prfx.end());
 reverse(infx.begin(), infx.end());
 cout<<"Given Infix Expn: "<< infx << " Prefix Expn: "<<prfx;
 return 0;
}
// Alg
// Input
Read the Infix Expression : a+b
// Output
Given Infix Expn: a+b Prefix Expn: +ab
