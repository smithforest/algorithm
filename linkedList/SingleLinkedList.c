#include "SingleLinkedList.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * 初始化单链表
 */
SingleLinkedList init_list() {
    SingleLinkedList l = (SingleLinkedList) malloc(sizeof(ListNode));
    l->next = NULL;
    return l;
}


/**
 * 尾插法创建单链表
 */
SingleLinkedList create_list_rear() {
    SingleLinkedList l = init_list();
    ListNode *rear = l;
    int x;
    while (scanf("%d", &x) != EOF) {
        ListNode *p = (ListNode *) malloc(sizeof(ListNode));
        p->data = x;
        rear->next = p;
        rear = p;
    }
    return l;
}

/**
 * 顺序输出单链表 with head
 */
void print_list(SingleLinkedList L) {
    ListNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

/**
 * 头插法创建单链表
 */
SingleLinkedList create_list_head() {
    SingleLinkedList l = init_list();
    int x;
    while (scanf("%d", &x) != EOF) {
        ListNode *p = malloc(sizeof(ListNode));
        p->data = x;
        p->next = l->next;
        l->next = p;
    }
    return l;
}

/**
 * 合并成递增单链表 小的尾插
 */
ListNode *merge_linkedList_asc(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1->next;
    ListNode *p2 = l2->next;
    ListNode *result = init_list();
    ListNode *p3 = result;
    while (p1 && p2) {
        if (p1->data <= p2->data) {
            p3->next = p1;
            p1 = p1->next;
        } else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if (p1) {
        p2 = p1;
    }
    while (p2) {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return result;
}

/**
 * 合并成递减法单链表 合并到l1上 小的头插
 */
ListNode *merge_linkedList_desc(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1->next;
    ListNode *p2 = l2->next;
    l1->next = NULL;
    while (p1 && p2) {
        if (p1->data <= p2->data) {
            ListNode *p = p1->next;
            p1->next = l1->next;
            l1->next = p1;
            p1 = p->next;
        } else {
            ListNode *p = p2->next;
            p2->next = l1->next;
            l1->next = p2;
            p2 = p->next;
        }
        if (p1) {
            p2 = p1;
        }
        while (p2) {
            ListNode *p = p2->next;
            p2->next = l1->next;
            l1->next = p2;
            p2 = p->next;
        }
    }
    return l1;
}


/**
 * 查找元素并删除
 */
void delete_node(SingleLinkedList L, int x) {
    if (!L || L->next == NULL) {
        return;
    }
    ListNode *current = L->next;
    ListNode *pre = L;
    while (current) {
        if (current->data == x) {
            pre->next = current->next;
            free(current);
            return;
        }
        pre = current;
        current = current->next;
    }
}

/**
 * 递增链表 删除重复冗余元素
 */
void delete_duplicate(SingleLinkedList L) {
    if (!L || L->next == NULL) {
        return;
    }
    ListNode *current = L->next;
    ListNode *p = current;
    while (current) {
        p = current->next;
        while (p && current->data == p->data) {
            ListNode *temp = p;
            p = p->next;
            free(temp);
        }
        current->next = p;
        current = p;
    }
}


/**
* 删除单链表中的最小值 擂台法 需要双节点遍历 不然没办法知道最小值的前一个节点是多少
*/
void delete_min(SingleLinkedList L) {
    // 用来遍历的节点
    ListNode *p = L->next;
    //遍历的前一个节点
    ListNode *pre = L;
    //记录最小值的节点
    ListNode *min = p;
    //记录最小值前面一个值的节点
    ListNode *pre_min = pre;
    while (p) {
        if (p->data <= min->data) {
            min = p;
            pre_min = pre;
        }
        pre = p;
        p = p->next;
    }
    pre_min->next = min->next;
    free(min);
}

/**
* 单链表·原地逆置 双节点遍历法[需要辅助节点记住当前节点 以便继续遍历]
*/
void reverseList(SingleLinkedList L) {
    if (!L || L->next == NULL) {
        return;
    }
    ListNode *p = L->next;
    ListNode *pre = L;
    while (p) {
        ListNode *temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }
}

/**
 * 逆序打印单链表
 * 1 2 3
 */
void print_list_reverse(SingleLinkedList L) {
    if (L->next != NULL) {
        print_list_reverse(L->next);
        printf("%d", L->next->data);
    }
}

/**
 * 查找倒数第k的元素 双指针 快慢指针
 */
ListNode *find_kth_to_tail(SingleLinkedList L, int k) {
    if (!L || L->next == NULL) {
        return NULL;
    }
    if (k <= 0) {
        return NULL;
    }
    ListNode *p = L->next;
    ListNode *q = p;
    //走k-1步
    while (q && k > 1) {
        k--;
        q = q->next;
    }
    // 如果链表长度不足 k，直接返回 NULL
    if (!q) {
        return NULL;
    }
    while (q) {
        p = p->next;
        q = q->next;
    }
    return p;
}

/**
 * 判断单链表是否有环  如果有环 while循环中就会相遇 如果没有环 while就会中断
 */
int hasCycle(SingleLinkedList L) {
    if (!L || L->next == NULL) {
        return 0;
    }
    ListNode *p = L->next;
    ListNode*q=p->next;
    while (q&& q->next) {
        if (p == q) {
            return 1;
        }
        p = p->next;
        q=q->next->next;
    }
    return 0;

}
