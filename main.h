#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct linkedlist * next;
    struct linkedlist * prev;
}linkedlist;

//validations
int operator_validation(char *val[]);
int validate_operand(char *val);

//creating and inserting the values in the list
int c_i_list(char *argv[],linkedlist **head1,linkedlist **tail1,linkedlist **head2,linkedlist **tail2);
int i_list(linkedlist **head, linkedlist **tail,int num);
int print_list(linkedlist *head);

//addition
int add(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR);
int result_insert(linkedlist **head,linkedlist **tail,int data);
//subtraction
int sub(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR);
int remove_zero(linkedlist ** head ,linkedlist ** tail);
//multiplication
int multipilication(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR,linkedlist **headR2,linkedlist **tailR2);
int multiplication_result_add(linkedlist **head1,linkedlist **tail1,linkedlist **head2,linkedlist ** tail2);

//division
int division(linkedlist **head1,linkedlist ** tail1,linkedlist ** head2,linkedlist **tail2,linkedlist ** headR,linkedlist** tailR);
int delete_list(linkedlist **head,linkedlist **tail);
#endif