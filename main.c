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

void push(Stack *s, int value){
	s->top++;
	s->item[s->top] = value;
}

int pop(Stack *s){
	return s->item[s->top--];
}

int parseNumber(char *ch, int *i){
	int num = 0;
	while (isdigit(ch[*i])){
		num = num * 10 + (ch[*i] - '0');
		(*i)++;
	}
	return num;
}



int main() {
	
	Stack numbers;
	Stack operators;
	
	initStack(&numbers);
	initStack(&operators);
	
	char ch[MAX];
	printf("Enter a formula:");
	scanf("%s", ch);
	
	int i = 0;
	while (ch[i] != '\0' && ch[i] != '\n'){
		if(isdigit(ch[i])){
			int num = parseNumber(ch, &i);
			push(&numbers, num);
		}
		
		else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/'){
			push(&operators, ch[i]);
			i++;
		}
		
		i++;
	}
	
	
	return 0;
}