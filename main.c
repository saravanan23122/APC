#include "main.h"

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("USAGE : operand operator operand\n");
        exit(0); //SUCCESS
    }
    if(!validate_operand(argv+1) || !validate_operand(argv+3))
    {
        printf("ERROR : : operand must have only 0-9\n");
        exit(0); //SUCCESS
    }
    if(strlen(argv[2]) != 1)
    {
        printf("ERROR : : operator invalid\n");
        exit(0); //SUCCESS
    }

    linkedlist * head1 = NULL;
    linkedlist * tail1 = NULL;
    linkedlist * head2 = NULL;
    linkedlist * tail2 = NULL;
    linkedlist * headR = NULL;
    linkedlist * tailR = NULL;
    linkedlist * headR2 = NULL;
    linkedlist * tailR2 = NULL;

    linkedlist * temp = NULL;
    linkedlist * h1 = NULL;
    linkedlist * h2 = NULL;


    int check;
    char operator;
    check = operator_validation(argv);
    if(check == 0)
        operator = '+';
    else if(check == 1)
        operator = '-';
    else if(check == 2)
        operator = 'x';
    else if(check == 3)
        operator = '/';
    
    //creating and inserting the values from the linked list
    c_i_list(argv,&head1,&tail1,&head2,&tail2);
    printf("list1 : ");
    print_list(head1);
    //printf("%c\n",operator);
    printf("list2 : ");
    print_list(head2);


    if(operator == '-')
    {
        //if length of the strings not equal
        if(strlen(argv[1]) < strlen(argv[3]))
        {
            temp = head1;
            head1 = head2;
            head2 = temp;

            temp = tail1;
            tail1 = tail2;
            tail2 = temp;
        }
        //if the length of the string is equal and value is greater in string 2
        h1 = head1;
        h2 = head2;
        if(strlen((argv[1])) == strlen(argv[3]))
        {
            while(h1 != NULL && h2 != NULL)
            {
                if(h1->data == h2->data)
                {
                    h1 = h1->next;
                    h2 = h2->next;
                }
                else
                {
                    break;
                }
            }
            if(h1 != NULL && h2 != NULL)
            {
                if(h1->data < h2->data)
                {
                    temp = head1;
                    head1 = head2;
                    head2 = temp;

                    temp = tail1;
                    tail1 = tail2;
                    tail2 = temp;
                }
            }

        } 
    }
    
    switch (operator)
    {
    case '+':
        add(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        printf("listR : ");
        print_list(headR);
        break;
    case '-':
        sub(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        printf("listR : ");
        print_list(headR);
        break;
    case 'x':
        multipilication(&head1, &tail1, &head2, &tail2, &headR, &tailR ,&headR2 ,&tailR2);
        printf("listR : ");
        print_list(headR2);
        break;
    case '/':
        //division;
        division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        print_list(headR);
        break;


    default:
        break;
    }

}