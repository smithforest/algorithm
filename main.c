#include "SqlList/SqlList.h"

int main(void) {
    SqlList L;
    initSqlList(&L);
    for (int i = 1; i < MAX_SIZE; i++) {
        insertSqlList(&L, i, i);
    }
    deleteElement(&L, 1);
    printSqlList(&L);
}