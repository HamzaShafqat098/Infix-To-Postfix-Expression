#include <stdio.h>

#include <ctype.h>

# define SIZE 30

int top = -1;

int topEvaluation = -1;

char stack[SIZE];

int stackEvaluation[SIZE];

void push(char x){

    stack[++top] = x;

}

char pop(){

    if(top == -1){

        return -1;

    } else{

        return stack[top--];

    }

}

int priority(char x){

    if(x == '('){

        return 0;

    }
    if(x == '+' || x == '-'){

        return 1;

    }
    if(x == '*' || x == '/'){

        return 2;

    }

}

void pushEvaluation(int xEvaluation){

    stackEvaluation[++topEvaluation] = xEvaluation;

}

int popEvaluation(){

    return stackEvaluation[topEvaluation--];

}

int main() {

    //printf("Hello, World!\n");

    char expression[SIZE];

    char *a;

    char x;

    printf("Enter The Expression In Infix Form :: \n");
    scanf("%s",&expression);

    a = expression;

    printf("The Expression In Postfix Form Is Given As :: \n");

    while (*a != '\0'){

        if(isalnum(*a)){

            printf("%c",*a);

        } else if(*a == '('){

            push(*a);

        } else if(*a == ')'){

            while ((x = pop()) != '('){

                printf("%c",x);

            }
        } else{

            while (priority(stack[top]) >= priority(*a)){

                printf("%c",pop());

            }

            push(*a);

        }

        a++;

    }

    while (top != -1){

        printf("%c",pop());

    }

    char expressionEvaluation[SIZE];

    char *b;

    int op1 , op2 , op3;

    int number;

    printf("\n");

    printf("Enter The Postfix Expression With Values If There Are Characters In The Expression :: \n");
    scanf("%s",&expressionEvaluation);

    b = expressionEvaluation;

    while (*b != '\0'){

        if(isdigit(*b)){

            number = *b - 48;

            pushEvaluation(number);

        } else{

            op2 = popEvaluation();

            op1 = popEvaluation();

            switch (*b) {

                case '+':
                    op3 = op1 + op2;
                    break;

                case '-':
                    op3 = op1 - op2;
                    break;

                case '*':
                    op3 = op1 * op2;
                    break;

                case '/':
                    op3 = op1 / op2;
                    break;

                default:
                    printf("Wrong Operator Inserted \n");

            }

            pushEvaluation(op3);

        }

        b++;

    }

    printf("The Value Of The Postfix Expression %s After Evaluation Is :: %d \n",expressionEvaluation , popEvaluation());

    //return 0;

    getchar();

    return 0;

}