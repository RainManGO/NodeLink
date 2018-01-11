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
STU * creat_LinkList(int n)
{
    float score;
    STU *head, *p;
    head = (STU *)malloc(sizeof(STU));
    head->next = NULL;
    for (int i=0; i<n; i++) {
        printf("请输入分数：");
        scanf("%f",&score);
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
STU * creat_LinkList(int n){
    float score;
    STU * head , *p,*q;
    head = p = (STU *)malloc(sizeof(STU));
    p->next=NULL;
    
    for (int i=0; i<n; i++) {
        printf("请输入分数：");
        scanf("%f",&score);
        q = (STU *)malloc(sizeof(STU));
        if (p!=NULL) {
            q->score = score;
            q->next=p->next;
            p->next = q;
            p=q;
        }else{
            printf("分配内存失败");
        }
    }
    return head;
}
#endif

#pragma mark 链表的查找

//指定个数查找
float getScore(STU * Node,int i){
    int j = 1;
    STU * p = Node->next;
    while (p->next!=NULL&&j<i){
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
    while (p->next!=NULL||p->score!=score) {
        p=p->next;
    }
    if (p->score==score) {
        return p;
    }
    
    return NULL;
}


#pragma mark 链表的插入

STU * insertStudent(STU * headLink,int i,float score){
    int j=1;
    STU * q;
    STU * p = headLink->next;
    while (p!=NULL &&j<i-1) {
        p=p->next;
        j++;
    }
    
    if (j==i-1) {
        q = (STU*)malloc(sizeof(STU));
        q->score = score;
        q->next=p->next;
        p->next=q;
    }
    
    
    return headLink;
}

#pragma mark 链表的删除

//删除第几个节点
STU * deleteStudent(STU * headLink,int i){
    int j;
    STU *p,*q;
    p = headLink;j=0;
    q = headLink->next;
    while (p->next!=NULL&&j<i) {
        p=q;
        q=q->next;
        j++;
    }
    
    if (j==i) {
        p->next=q->next;
        free(q);
    }
    return headLink;
}

//按值删除所有节点
STU * deleteStudentByScore(STU * headLink,float score){
    STU *p,*q;
    p = headLink;
    q = headLink->next;
    while (p!=NULL) {
        if (q->score==score) {
            p->next=q->next;
            free(q);
            q=p->next;
        }else{
            p=q;
            q=q->next;
        }
       
    }
    
    return headLink;
}

//删除重复节点

void deleteSameDataNode(STU * headLink){
    STU *p,*q,*p1;
    p=headLink->next;
    while (p->next!=NULL) {
        q=p;
        p1=p->next;
        while (p1->next!=NULL) {
            if (p->score==p1->score) {
                q->next=p1->next;
                free(p1);
                p1=q->next;
            }else{
                q=p1;
                p1=p1->next;
            }
        }
        p=p->next;
    }
}


void printfLink(STU * headLink){
    STU * p = headLink->next;
    printf("打印链表如下：\n");
    while (p!=NULL) {
        printf("%.2f\n",p->score);
        p=p->next;
    }
    printf("\n");
}



int main(int argc, const char * argv[]) {
    
    //创建链表
    STU * nodeLink = creat_LinkList(5);
    printfLink(nodeLink);
    
    //根据序号查找链表节点值
    printf("第%d个链表值为:%.2f\n",3,getScore(nodeLink,3));
    
    
    //链表值的插入
    insertStudent(nodeLink,4,6.6);
    printfLink(nodeLink);
    
    //删除链表的值
    deleteStudent(nodeLink,1);
    printfLink(nodeLink);
    
    //删除重复节点
    deleteSameDataNode(nodeLink);
    printfLink(nodeLink);
    return 0;
}

