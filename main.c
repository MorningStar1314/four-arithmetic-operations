#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct{
	int top;
	int item[MAX];
} Stack;

void initStack(Stack *s){
	s->top = -1;
}

int isEmpty(Stack *s){
	return s->top == -1;
}

void push(Stack *s, int value){
	if (s->top < MAX - 1){
		s->top++;
		s->item[s->top] = value;
	}
}

int pop(Stack *s){
	if (!isEmpty(s)){
		return s->item[s->top--];
	}
}

int peek(Stack *s){
	if (!isEmpty(s)){
		return s->item[s->top];
	}
}

int operatorPriorty(char op){
	if (op == '+' || op == '-'){
		return 1;
	}
	else if (op == '*' || op == '/'){
		return 2;
	}
}

int Operation(int a, int b, char op){
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/'){
		if (b != 0){
			return a / b;
		}
		else{
			return 0;
		}
	}
}

void process(Stack *numbers, Stack *operators){
	int a, b;
	char op;
	b = pop(numbers);
	a = pop(numbers);
	op = pop(operators);
	push(numbers, Operation(a, b, op));
}

int parseNumber(char *ch, int *i){
	int num = 0;
	while (isdigit(ch[*i])){
		num = num * 10 + (ch[*i] - '0');
		(*i)++;
	}
	return num;
}

int evaluate(char *ch){
	Stack numbers, operators;
	int i = 0;
	initStack(&numbers);
	initStack(&operators);

	while (ch[i] != '\0'){
		if (isdigit(ch[i])){
			push(&numbers, parseNumber(ch, &i));
		}
		else if (ch[i] == '('){
			push(&operators, ch[i]);
			i++;
		}
	}

	

}



int main() {
	
	int result = 0;
	char ch[MAX];
	printf("Enter a formula:");
	scanf("%s", ch);
	
	result = evaluate(ch);
	printf("Result: %d", result);
	
	return 0;
}