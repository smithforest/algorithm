#ifndef SQLLIST_H
#define SQLLIST_H
# define MAX_SIZE 100

typedef struct {
    int *data;
    int length;
} SqlList;

int initSqlList(SqlList *L);

int insertSqlList(SqlList *L, int index, int value);


void printSqlList(SqlList *L);


#endif
