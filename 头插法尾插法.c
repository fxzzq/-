#include "stdio.h" 
#include "stdlib.h" 
typedef struct List 
{  
int data;  
struct List *next; //指针域
}List;  

void HeadCreatList (List *L) //头插法建立链表
{ List *s;
int i; 
L->next=NULL;
for (i=0;i<10;i++)
	{ 
  	s=(struct List*)malloc(sizeof(struct List)); 
  	s->data=i;
  	s->next=L->next;
  	L->next=s;
	} 
}  

void TailCreatList(List *L) //尾插法建立链表
{
	List *s,*r; 
	int j;
	r=L; 
for (j=0;j<10;j++) 
		{ 
			s=(struct List*)malloc(sizeof(struct List)); 
			s->data=j; 
			r->next=s;
			r=s; 
		} 
			r->next=NULL; 
}  

void DisPlay(List *L) 
{
      List *p=L->next; 
      while(p!=NULL) 
      { 
      printf ("%d ",p->data);
      
      p=p->next; 
      } 
      printf("\n"); 

} 
int main () 
{  
        List *L1,*L2;  
        
        L1=(struct List*)malloc(sizeof(struct List)); 
        
        L2=(struct List*)malloc(sizeof(struct List)); 
        
        HeadCreatList(L1); 
        
        DisPlay(L1);  
        
        TailCreatList(L2); 
        
        DisPlay(L2); 

} 
