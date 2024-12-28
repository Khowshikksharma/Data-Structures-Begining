#include <stdio.h>
#include <string.h>
#define max 100
char stack[max];
int top=-1;
void push(char a)
{
	if(top==max-1)
		printf("Stack is full\n");
	else 
	stack[++top]=a;
}
void pop()
{
	if(top==-1)
		printf("Stack is empty\n");
	else
		top--;
}
int checkBalance(char *a)
{
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='('||a[i]=='{'||a[i]=='[')
			push(a[i]);
		else
		{
			char v1=stack[top],v2=a[i];
			if(top==-1)
				return 0;
			else if(v1=='('&&v2==')'||v1=='{'&&v2=='}'||v1=='['&&v2==']')
				pop();
		}
	}
	if(top!=-1)
		return 0;
	else
		return 1;
}
main()
{
	char s[max];
	printf("Enter the expression:");
	scanf("%s",s);
	checkBalance(s)?printf("Balanced\n"):printf("Not Balanced\n");
	return 0;
}
