#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[100];
int top=-1;
void push(char ch)
{
	top++;
	stack[top]=ch;
}
char pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}
int priority(char ch)
{
	if(ch=='^')
		return 3;
	else if(ch=='/'||ch=='*')
		return 2;
	else if(ch=='+'||ch=='-')
		return 1;
	else
		return 0;
}
void convertpost(char ch[])
{
	int i;
	for(i=0;i<strlen(ch);i++)
	{
		if(isalnum(ch[i]))
			printf("%c",ch[i]);
		else if(ch[i]=='(')
			push(ch[i]);
		else if(ch[i]==')')
		{
			char x;
			while((x=pop())!='(')
				printf("%c",x);
		}
		else
		{
			while(priority(stack[top])>=priority(ch[i]))
				printf("%c",pop());
			push(ch[i]);
		}
	}
	while(top!=-1)
		printf("%c",pop());
}
main()
{
	char inputEx[100];
	printf("Enter the expression:");
	scanf("%s",inputEx);
	convertpost(inputEx);
	return 0;
}
