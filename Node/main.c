//
//  main.c
//  Node
//
//  Created by apple on 2018/1/3.
//  Copyright © 2018年 ZY. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    float  score;
    struct Student * next;
}STU;

#pragma mark  链表的创建

#if 0
//头插入法建表
STU * creat_LinkList()
{
    float score;
    STU *head, *p;
    head = (STU *)malloc(sizeof(STU));
    head->next = NULL;
    while (1) {
        scanf("input score:%f",&score);
        p = (STU *)malloc(sizeof(STU));
        if (p!=NULL) {
            p->score = score;
            p->next = head->next;
            head->next = p;
        }else{
            printf("分配内存失败");
        }
    }
    return head;
}
#else
//尾插入建表
STU * creat_LinkList(){
    float score;
    STU * head , *p,*q;
    head = p = (STU *)malloc(sizeof(STU));
    p->next=NULL;
    while (1) {
        scanf("%f",&score);
        q=(STU *)malloc(sizeof(STU));
        q->score = score;
        q->next=p->next;
        p->next = q;
        p=q;
    }
    
    return head;
}
#endif

#pragma mark 链表的查找

//指定个数查找
float getScore(STU * Node,int i){
    int j = 1;
    STU * p = Node->next;
    while (p->next!=NULL&j<i){
        p=p->next;
        j++;
    };
    if (i==j) {
        return p->score;
    }else{
        return 0.f;
    }
    
}


//根据数据值查找节点

STU * getStudent(STU * headLink,float score){
    
    STU * p = headLink;
    while (p->next!=NULL||p->score==score) {
        p=p->next;
    }
    
    return p;
}


int main(int argc, const char * argv[]) {
    // insert code here...

    return 0;
}

