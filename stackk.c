#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* element;

typedef struct
{
    element* data;
    int top;
    int capacity;
} stacktype;

void init(stacktype* s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity * sizeof(element));
}

void delete(stacktype* s)
{
    for (int i = 0; i <= s->top; i++)
    {
        free(s->data[i]);
    }
    free(s->data);
    free(s);
}

int is_empty(stacktype* s)
{
    return (s->top == -1);
}

int is_full(stacktype* s)
{
    return (s->top == (s->capacity - 1));
}

void push(stacktype* s, element input)
{
    if (is_full(s))
    {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    /*
    char* copied_input = (char*)malloc(strlen(input) + 1);
    if (copied_input != NULL)
    {
        strcpy(copied_input, input);
    }
    s->data[++(s->top)] = copied_input;
    */
    s->data[++(s->top)] = __strdup(input);
}

element pop(stacktype* s)
{
    if (is_empty(s))
    {
        printf("-1\n");
        return NULL;
    }
    else
    {
        element temp = s->data[s->top];
        s->data[s->top--] = NULL;
        return temp;
    }
}

element print_top(stacktype* s)
{
    if (is_empty(s))
    {
        printf("-1\n");
        return NULL;
    }
    return s->data[s->top];
}

int how_many(stacktype* s)
{
    return s->top + 1;
}

int main(void)
{
    stacktype s;
    init(&s);
    int n;
    char order;
    char* arr = (char*)malloc(sizeof(char) * 1000000);

    scanf("%d", &n);
    getchar();  // 버퍼에 남아 있는 개행 문자 제거

    if (1 <= n && n <= 1000000)
    {
        for (int i = 0; i < n; i++)
        {
            fgets(arr, 10, stdin);
            arr[strlen(arr) - 1] = '\0';  // 개행 문자 제거
            order = arr[0];

            if (order == '1')
            {
                char* str = arr + 2;  // 명령 문자와 공백을 건너뛴 문자열
                push(&s, str);
            }
            else if (order == '2')
            {
                char* popped = pop(&s);
                if (popped != NULL)
                {
                    printf("%s\n", popped);
                    //free(popped);
                }
            }
            else if (order == '3')
                printf("%d\n", how_many(&s));
            else if (order == '4')
            {
                if (is_empty(&s))
                    printf("1\n");
                else
                    printf("0\n");
            }
            else if (order == '5')
            {
                char* top = print_top(&s);
                if (top != NULL)
                {
                    printf("%s\n", top);
                    //free(top);
                }
            }
        }
        free(arr);
        //exit(1);

    }
    //delete(&s);

    return 0;
}