#include "main.h"

int sub(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR)
{
    linkedlist *t1 = *tail1;
    linkedlist *t2 = *tail2;
    int flag =0;
    int num;

    while(t1 != NULL && t2 != NULL)
    {
        if(flag == 1)
        {
            t1->data = t1->data - 1;
        }
        if(t1->data < t2->data)
        {
            flag =1;
            num = 10+t1->data - t2->data;
        }
        else
        {
            flag =0;
            num = t1->data - t2->data;
        }
        result_insert(headR,tailR,num);
        t1 = t1->prev;
        t2 = t2->prev;
    }

    if(t1 != NULL && t2== NULL)
    {
        while(t1 != NULL)
        {
            if(flag ==1)
            {
                if(t1->data == 0)
                {
                    flag =1;
                    t1->data = t1->data -1;
                    num = t1->data +10;
                    result_insert(headR,tailR,num);
                }
                else
                {
                    flag = 0;
                    t1->data = t1->data-1;
                    result_insert(headR,tailR,t1->data);
                }
            }
            else
            {
                result_insert(headR,tailR,t1->data);
            }
            t1 =t1->prev;
        }
    }
    if((*headR)->next !=NULL)
    {
        while((*headR)->data ==0)
        {
            remove_zero(headR,tailR);
            if((*headR)==(*tailR))
            {
                break;
            }
        }
    }
    if((*headR) == (*tailR) && (*headR)->data ==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int remove_zero(linkedlist ** head ,linkedlist ** tail)
{
    if(*head == NULL || *tail == NULL)
    {
        return 1; // FAILURE
    }
    if((*head)->next == NULL)
    {
        free((*head));
        *head = *tail = NULL;
        return 0; //SUCCESS
    }

    *head = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL;
}
