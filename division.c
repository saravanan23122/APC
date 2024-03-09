#include "main.h"
int division(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR)
{
    if((*head2)->data == 0 &&(*head2)->prev == NULL)
    {
        printf("infinity\n");
        exit(0);
    }
    int c1 = 0;
    int c2 = 0;
    int q = 1;
    linkedlist *t1 = *head1;
    linkedlist *t2 = *head2;
    while(t1 != NULL)
    {
        t1 = t1->next;
        c1++;
    }
    while(t2 != NULL)
    {
        t2 = t2->next;
        c2++;
    }
    t1 = *head1;
    t2 = *head2;
    if(c1 == c2)
    {
        while(t1 != NULL &&t2 != NULL && t1->data == t2->data)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1 != NULL && t2 != NULL)
        {
            if(t2->data > t1->data)
            {
                printf("0\n");
                exit(0);
            }
        }
    }
    else if (c2 > c1)
    {
        printf("0\n");
        exit(0);
    }
    while(1)
    {
        c1 =0;
        c2 =0;
        sub(head1,tail1,head2,tail2,headR,tailR);
        delete_list(head1,tail1);
        *head1 = *headR;
        *tail1 = *tailR;
        *headR = NULL;
        *tailR = NULL;
        t1 = *head1;
        t2 = *head2;
        while(t1!=NULL)
        {
	        t1=t1->next;
	        c1++;
        }

        while(t2!=NULL)
        {
	    t2=t2->next;
	    c2++;
        }
        t1=*head1;
        t2=*head2;
        if(c1==c2)
        {
            while(t1!=NULL && t2!=NULL && t1->data==t2->data){
	            t1=t1->next;
                t2=t2->next;
            }

            if(t1!=NULL&&t2!=NULL){ 
            if((t1)->data < (t2)->data)
            {
                break;
            }
            }
        }
        else if(c1 < c2)
        {
            break;
        }
        q++; 
    }
    printf("%d\n",q);  
    exit(0);  
}

int delete_list(linkedlist **head,linkedlist **tail)
{
    if(*head == NULL || *tail == NULL)
    {
        return -1;
    }
    while((*head)->next != NULL)
    {
        *head = (*head)->next;
        free((*head)->prev);
    }
    free(*head);
    *head = *tail = NULL;
}