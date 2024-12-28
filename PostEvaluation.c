#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int stack[100];
int top=-1;
void push(int val)
{
	top++;
	stack[top]=val;
}
int pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}
void postEvaluation(char ch[])
{
	int i,a,b;
	for(i=0;ch[i]!='\0';i++)
	{
		if(isdigit(ch[i]))
			push(ch[i]-'0');
		else
		{
			char op=ch[i];
			a=pop();
			b=pop();
			switch(op)
			{
				case '+':
					push(b+a);
					break;
				case '-':
					push(b-a);
					break;
				case '*':
					push(b*a);
					break;
				case '/':
					push(b/a);
					break;
				case '^':
					push(pow(b,a));
					break;
			}
		}
	}
	printf("Output:%d\n",pop());
}
int main()
{
	char ch[100];
	printf("Enter the expression:");
	scanf("%s",ch);
	int i,l=strlen(ch),len=0;
	for(i=0;ch[i]!='\0';i++)
	{
		if(isdigit(ch[i]))
			len++;
	}
	int oplen=l-len;
	if(len==(oplen+1))
		postEvaluation(ch);
	else if(len<=oplen)
		printf("Not enough operants\n");
	else
		printf("Too many operants\n");
	return 0;
}
