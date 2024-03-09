#include "main.h"
int validate_operand(char *val)
{
    int i =0;
    while(val[i] !='\0')
    {
        if(val[i] >=48 && val[i]<=57)
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int operator_validation(char *val[])
{
    int minus=0;
    if(val[2][0]  == '+')
        return 0;
    else if(val[2][0] == '-')
        return 1;
    else if(val[2][0] == 'x')
        return 2;
    else if(val[2][0] == '/')
        return 3;
}

int c_i_list(char *argv[],linkedlist **head1,linkedlist **tail1,linkedlist **head2,linkedlist **tail2)
{
    int num;
    for(int i=0;i<strlen(argv[1]);i++)
    {
        if(argv[1][i] != '+' || argv[1][i] != '-')
        {
            num = (int)argv[1][i] - '0';
            i_list(head1,tail1,num);
        }
    }

    for(int i=0;i<strlen(argv[3]);i++)
    {
        if(argv[3][i] != '+' || argv[3][i] != '-')
        {
            num = (int)argv[3][i] - '0';
            i_list(head2,tail2,num);
        }
    }
}

int i_list(linkedlist **head, linkedlist **tail,int num)
{
    linkedlist *new =malloc(sizeof(linkedlist));
    new->prev = NULL;
    new->next = NULL;
    new->data = num;
    if(*head == NULL || *tail == NULL)
    {
        *tail = *head = new;
        return 0; //SUCCESS
    }
    new->prev =*tail;
    (*tail)->next = new;
    *tail = new;
}

int print_list(linkedlist *head)
{
    if(head == NULL)
    {
        printf("INFO : LIST IS EMPTY ");
    }
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}