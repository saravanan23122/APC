#include "main.h"

int add(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR)
{
    int flag= 0;
    int num;
    int temp;
    linkedlist *t1 = *tail1;
    linkedlist *t2 = *tail2;

    while(t1 != NULL && t2 != NULL)
    {
        num = t1->data + t2->data + flag;
        if(num < 10)
        {
            flag =0;
        }
        else
        {
            temp=num/10;
            flag=temp %10;
        }
        result_insert(headR,tailR,num%10);
        t1 = t1->prev;
        t2 = t2->prev;
    }
    if(t1 == NULL && t2!=NULL)
    {
        while(t2 != NULL)
        {
            num = t1->data + flag;
            if(num < 10)
            {
                flag = 0;
            }
            else
            {
                temp = num/10;
                flag = temp%10;
            }
            result_insert(headR,tailR,num%10);
            t1 = t1->prev;
        }
        if(flag != 0)
        {
            result_insert(headR,tailR,flag);
        }
    }
    else if(t1 != NULL && t2 ==NULL)
    {
        while(t1 != NULL)
        {
            num = t2->data+flag;
            if(num <10)
            {
                flag=0;
            }
            else
            {
                temp = num/10;
                flag = temp%10;
            }
            result_insert(headR,tailR,num%10);
            t2 = t2->prev;
        }
        if(flag !=0)
        {
            result_insert(headR,tailR,flag);
        }
    }
}

int result_insert(linkedlist **head,linkedlist **tail,int data)
{
    linkedlist *new = malloc(sizeof(linkedlist));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    if(*head == NULL || *tail ==NULL)
    {
        *tail = *head =new;
        return 0;//SUCCESS
    }
    new->next = *head;
    (*head)->prev = new;
    (*head) = new;
    return 0;
}