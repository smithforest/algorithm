#include "SingleLinkedList.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * 初始化单链表
 */
SingleLinkedList init_list()
{
    SingleLinkedList l = (SingleLinkedList)malloc(sizeof(ListNode));
    l->next = NULL;
    return l;
}


/**
 * 尾插法创建单链表
 */
SingleLinkedList create_list_rear()
{
    SingleLinkedList l = init_list();
    ListNode* rear = l;
    int x;
    while (scanf("%d", &x) != EOF)
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        p->data = x;
        rear->next = p;
        rear = p;
    }
    return l;
}

/**
 * 顺序输出单链表
 */
void print_list(SingleLinkedList L)
{


}
