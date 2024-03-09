#include "main.h"

int multipilication(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR,linkedlist **headR2,linkedlist **tailR2)
{
    linkedlist *t1 = *tail1;
    linkedlist *t2 = *tail2;
    linkedlist *tR = *tailR;
    *tailR2 = NULL;
    result_insert(headR2,tailR2,0);
    int carry =0;
    int num;
    int temp;
    int count =1;
    while(t2 != NULL)
    {
        while(t1 != NULL)
        {
            num= (t1->data * t2->data) + carry;
            if(num <10)
            {
                carry = 0;
            }
            else
            {
                temp = num /10;
                carry = temp%10;
            }
            if(count == 1)
            {
                if(tR == NULL || tR->prev == NULL)
                {
                    result_insert(headR,tailR,num%10);
                    tR = *headR;
                }
                else
                {
                    tR->data = num % 10;
                }
            }
            else
            {
                result_insert(headR,tailR,num%10);
            }
            tR = tR->prev;
            t1=t1->prev;
        }
        if(carry != 0)
        {
            result_insert(headR,tailR,carry);
        }
        multiplication_result_add(headR,tailR,headR2,tailR2);
        remove_zero(headR,tailR);
        for(int i=0;i<count;i++)
        {
            result_insert(headR,tailR,0);
        }
        count++;
        t2=t2->prev;
    }
    if((*headR2)->next != NULL )
    {
        while ((*headR2)->data ==0)
        {
            remove_zero(headR2,tailR2);
            if((*headR2)==(*tailR2))
            {
                break;
            }
        }
    }
}


int multiplication_result_add(linkedlist **head1,linkedlist **tail1,linkedlist **head2,linkedlist ** tail2)
{
    linkedlist *t1 = *tail1;
    linkedlist *t2 = *tail2;
    int carry =0;
    int num;
    int temp;
    while(t1 != NULL && t2 != NULL)
    {
        num = t1->data + t2->data + carry;
        if(num < 10)
        {
            carry = 0;
        }
        else
        {
            temp = num/10;
            carry = temp%10;
        }
        if(t2 != NULL)
        {
            t2->data = num%10;
        }
        else
        {
            result_insert(head2,tail2,num%10);
        }
        t1 = t1->prev;
        t2 = t2->prev;
    }
    if(t1 == NULL && t2 != NULL)
    {
        while(t2!= NULL)
        {
            num = t2->data + carry;
            if(num <10)
            {
                carry = 0;
            }
            else
            {
                temp = num/10;
                carry = temp%10;
            }
            result_insert(head2,tail2,num%10);
            t2 = t2->prev;
        }
        if(carry != 0)
        {
            result_insert(head2,tail2,num%10);
        }
    }
    else if(t1 != NULL && t2 == NULL)
    {
        while(t1 != NULL)
        {
            num = t1->data + carry;
            if(num<10)
            {
                carry =0;
            }
            else
            {
                temp = num/10;
                carry = temp%10;
            }
            result_insert(head2,tail2,num%10);
            t1=t1->prev;
        }
        if(carry != 0)
        {
            result_insert(head2,tail2,carry);
        }
    }
    else if(carry != 0)
    {
        result_insert(head2,tail2,carry);
    }
}