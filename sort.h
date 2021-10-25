#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);

/* 1-insert_sort_list.c file*/
void insertion_sort_list(listint_t **list);
void swap(listint_t **list, listint_t *c_inner);
listint_t *remove_node(listint_t **node);
void insert_node(listint_t **list, listint_t *nAdd);
/* 2-selection_sort.c file */
void selection_sort(int *array, size_t size);
/* 3-quick_sort.c file*/
void quick_sort(int *array, size_t size);
void sort(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);
#endif /* sort.h */