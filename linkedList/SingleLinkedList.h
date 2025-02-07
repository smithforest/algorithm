#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

typedef struct node {
    int data;
    struct node *next;
} ListNode, *SingleLinkedList;

/**
 * 初始化单链表
 */
SingleLinkedList init_list();

/**
 * 尾插法创建单链表
 */
SingleLinkedList create_list_rear();

/**
 * 头插法创建单链表
 */
SingleLinkedList create_list_head();

/**
 * 合并成递增单链表
 */
ListNode *merge_linkedList_asc(ListNode *l1, ListNode *l2);


/**
 * 合并成递减法单链表
 */
ListNode *merge_linkedList_desc(ListNode *l1, ListNode *l2);

/**
 * 查找元素并删除
 */
void delete_node(SingleLinkedList L, int x);

/**
 * 删除重复冗余元素
 */
void delete_duplicate(SingleLinkedList L);

/**
 * 删除单链表中的最小值
 */
void delete_min(SingleLinkedList L);

/**
 * 单链表·原地逆置
 */
void reverseList(SingleLinkedList L);

/**
 * 判断单链表是否有环
 */
int hasCycle(SingleLinkedList L);

/**
 * 逆序打印单链表
 */
void print_list_reverse(SingleLinkedList L);

/**
 * 顺序输出单链表
 */
void print_list(SingleLinkedList L);

/**
 * 查找倒数第k的元素
 */
ListNode* find_kth_to_tail(SingleLinkedList L, int k);


#endif
