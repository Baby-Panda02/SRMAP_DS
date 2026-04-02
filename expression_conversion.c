#include <stdio.h>
#include <ctype.h> // preserve the function for checking the char type data

#define MAX 100

char stack[MAX];
int top = -1;

/* Perform push operation */
void push(char x)
{
	stack[++top] = x;
}

/* Perform pop operation */
char pop()
{
	return stack[top--];
}

/* Function to check operator precedence */
int precedence(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	if (x == '^')
		return 3;
	return 0;
}

int main(void)
{
	char infix[MAX], postfix[MAX];
	int i = 0, k = 0;
	char ch;

	printf("Enter infix expression: ");
	scanf("%s", infix);

	while (infix[i] != '\0')
	{
		ch = infix[i];

		/* If operand, add to postfix */
		if (isalnum((unsigned char)ch)) /* isalnum is in ctype.h */
		{
			postfix[k++] = ch;
		}
		/* If left parenthesis, push */
		else if (ch == '(')
		{
			push(ch);
		}
		/* If right parenthesis, pop until '(' */
		else if (ch == ')')
		{
			while (top != -1 && stack[top] != '(')
				postfix[k++] = pop();
			if (top != -1)
				pop(); /* Remove '(' */
		}
		/* If operator */
		else
		{
			while (top != -1 && precedence(stack[top]) >= precedence(ch))
				postfix[k++] = pop();
			push(ch);
		}
		i++;
	}

	/* Pop remaining operators */
	while (top != -1)
		postfix[k++] = pop();

	postfix[k] = '\0';

	printf("Postfix expression: %s\n", postfix);
	return 0;
}