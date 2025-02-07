#include "SqlList.h"

#include <stdio.h>
#include <stdlib.h>

int initSqlList(SqlList *L) {
    L->data = (int *) malloc(sizeof(int) * MAX_SIZE);
    if (L->data == NULL) {
        return 0;
    }
    L->length = 0;
    return 1;
}

/**
 * index和length 比实际索引>1
 *  index: 0 1 2 3
 *  data:  1 2 3 4
 */
int insertSqlList(SqlList *L, int index, int value) {
    if (index < 1 || index > L->length + 1) {
        return 0;
    }
    if (L->length >= MAX_SIZE) {
        return 0;
    }
    for (int i = L->length; i >= index; i++) {
        L->data[i] = L->data[i - 1];
    }
    L->data[index - 1] = value;
    L->length++;
    return 1;
}

/**
 * index和length 比实际索引>1
 *  index: 0 1 2 3
 *  data:  1 2 3 4
 */
int deleteElement(SqlList *L, int index) {
    if (index < 1 || index > L->length) {
        return 0;
    }
    for (int i = index - 1; i < L->length; ++i) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return 1;
}


int findElement(SqlList *L, int value) {
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == value) {
            return i;
        }
    }
    return -1;
}
/**
 * index和length 比实际索引>1
 *  index: 0 1 2 3
 *  data:  1 2 3 4
 * index:  0 1 2 3 4
 *  data:  1 2 3 4 5
 */
void reverse_list(SqlList *L) {
    for (int i=0; i<L->length/2; i++) {
        int temp=L->data[i];
        L->data[i]=L->data[L->length-1-i];
        L->data[L->length-1-i]=temp;
    }
};
/**
 * index和length 比实际索引>1
 * data:  0 1 2 3 4
 * index: 1 2 3 4 5
 */
int delete_range(SqlList *L, int i, int j) {
    if (i<1 || i>L->length || j<1 || j>L->length) {
        return 0;
    }
    if (i>=j) {
        return 0;
    }
    for (int k = i-1; k <= j-1; ++k) {
       L->data[k] = L->data[k+(j-i+1)];
    }
    L->length -= j-i+1;
    return 1;
};

/**
 * 分类 使左边的都小于右边的 分为两部分 类似于快速排序的一次
 */
int partition(SqlList *L, int low, int high) {
    int pivot=L->data[low];
    while (low<high) {
        while (low<high && L->data[high]>=pivot) {
            high--;
        }
        L->data[low]=L->data[high];
        while (low<high && L->data[low]<=pivot) {
            low++;
        }
        L->data[high]=L->data[low];
    }
    L->data[low]=pivot;
    return low;
};


void printSqlList(SqlList *L) {
    for (int i = 0; i < L->length; ++i) {
        printf("%d ", L->data[i]);
    }
}
