#ifndef SQLLIST_H
#define SQLLIST_H
# define MAX_SIZE 100

typedef struct {
    int *data;
    int length;
} SqlList;
// 初始化链表
int initSqlList(SqlList *L);
// 插入元素
int insertSqlList(SqlList *L, int index, int value);\
// 查找元素
int findElement(SqlList *L, int value);
// 删除元素
int deleteElement(SqlList *L, int index);
// 翻转链表
void reverse_list(SqlList *L);
// 删除区间
int delete_range(SqlList *L, int i, int j);
//删除区间2.0写法
int delete_range2(SqlList *L ,int i,int j);
// 分组链表
int partition(SqlList *L, int low, int high);


void printSqlList(SqlList *L);





#endif
