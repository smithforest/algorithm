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

int insertSqlList(SqlList *L, int index, int value) {
    if (index < 1 || index > L->length + 1) {
        return 0;
    }
    if (L->length >= MAX_SIZE) {
        return 0;
    }
    for (int i = L->length; i >= index; --i) {
        L->data[i] = L->data[i - 1];
    }
    L->data[index - 1] = value;
    return 1;
}

void printSqlList(SqlList *L) {
    for (int i = 0; i < L->length; ++i) {
        printf("%d ", L->data[i]);
    }
}
