#include "sqList/SqList.h"

int main(void) {
    SqlList L;
    initSqlList(&L);
    for (int i = 1; i < MAX_SIZE; i++) {
        insertSqlList(&L, i, i);
    }
    delete_range(&L, 4, 97);
    deleteElement(&L, 99);
    reverse_list(&L);
    partition(&L, 0, L.length-1);
    printSqlList(&L);
}