#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct link)

struct link //节点
{int num;
 struct link *next;
};

struct link *creat() //建立链表
{int a;
 struct link *head,*p,*q;
 head=(struct link *)malloc(LEN);
 head->num=-1;
 head->next=NULL;
 q=head;
 printf("请输入链表(以0结束):\n");
 scanf("%d",&a);
 while(a)
 {p=(struct link *)malloc(LEN);
 p->next=NULL;
 p->num=a;
 q->next=p;
 q=p;
 scanf("%d",&a);
 }
 return head;
 free(p);free(q);
}

void print_(struct link *q) //输出链表
{printf("您的链表为:");
 while(q->next!=NULL) 
 {printf("%d ",q->next->num);
 q=q->next;
 }
 printf("\n");
}

void sort(struct link *head) //单链表排序
{struct link *p,*q,*r;
 int temp;
 for(p=head->next;p!=NULL;p=p->next)
 {r=p;
 for(q=p->next;q!=NULL;q=q->next)
 if(q->num<r->num) r=q;
 temp=p->num;
 p->num=r->num;
 r->num=temp;
 }
}

void mix(struct link *p,struct link *q) //合并链表
{struct link *head1,*head2;
 head1=p;head2=q;
 if(p->next==NULL)
 {printf("A表为空!，组合后的链表为B表:\n"); //A表为空时
 print_(q);
 }
 else if(q->next==NULL) //B表为空时
 {printf("B表为空!，组合后的链表为A表:\n");
 print_(p);
 }
 else
 {p=p->next;q=q->next;
 while(p->next!=NULL&&q->next!=NULL) //合并A、B表
 {head2->next=q->next;
 q->next=p->next;
 p->next=q;
 p=q->next;
 q=head2->next;
 }
 if(q->next==NULL&&p->next!=NULL) //如果A表长于B表
{q->next=p->next;
 p->next=q;
 head2->next=NULL;
} 
else if(p->next==NULL) //如果A表不长于B表
{p->next=q; 
 head2->next=NULL;
}
printf("合并后"); //打印合并后的表
sort(head1);
print_(head1); 
 }

}

void main()
{struct link *A,*B;
 printf("A链表:");
 A=creat();
 printf("B链表:");
 B=creat();
 mix(A,B);
}

