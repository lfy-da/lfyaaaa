#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20],     //货物名称（巧妙的运用了逗号运算符）
         no[12];       //货物编号
    int num;           //货物数量
}good;                //定义货物类型的结构体
typedef struct  node     //节点类型的结构体
{
    good data;         //货物数据域
    struct  node *next;  //存放下一个货物数据的地址，即指针域
}LNode;
//菜单函数
void menu()
{
    printf("%60s","|--------------------------------------|\n");
    printf("%60s","|---------------*菜单*-----------------|\n");
    printf("%60s","|1--------录入货物的名称、货号和数量---|\n");
    printf("%60s","|2-----------输出所有货物信息----------|\n");
    printf("%60s","|3---------给定货号，查找货物位置------|\n");
    printf("%60s","|4--------------入库-------------------|\n");
    printf("%60s","|5--------------出库-------------------|\n");
    printf("%60s","|0------------退出系统-----------------|\n");
    printf("%60s","|--------------------------------------|\n");
}
//录入基本信息
 LNode *input(LNode *head) 
       //定义一个返回类型为结点类型的函数，因为要返回头指针，方便主函数进行其他操作
{
    LNode *s,*r;
    printf("输入货物个数：\n");
    int i,len;
    good x;
    scanf_s("%d",&len);
    printf("输入货物名称、货物编号和数量：\n");
    r=head;
         for(i=1;i<=len;i++){
            scanf_s("%s%s%d",x.name,x.no,&x.num);
            s=(LNode*)malloc(sizeof(LNode));
            s->data=x;
            s->next=NULL;    
            r->next=s;
            r=s;        
         }
         return head;
}
//输出所有货物信息
void P(LNode *head)
{
    LNode *p=head->next;
    printf("货物名称     货物编号      货物数量\n");
    while(p!=NULL)
        {
            printf("%5s%12s%15d\n",p->data.name,p->data.no,p->data.num);
            p=p->next;
        }
}
//根据货号查找货物信息
LNode* search(LNode *head,good x)
{
    LNode *p=head->next;
    while((p!=NULL)&&strcmp(p->data.no,x.no)!=0)
    p=p->next;
    return p;
}
void getin(LNode *head,good x)
{

    int In_Num;
    LNode *k,
          *p=head->next,
          *r=head;
    printf("输入需要入库的货号:\n");
    scanf_s("%s",x.no);
    good y=x;
    while((p!=NULL)&&strcmp(p->data.no,x.no)!=0)
        p=p->next;
    if(p==NULL)
                {
                    printf("该货物不存在，需录入该货物信息，并以编号有序插入\n");
                    printf("请输入货物名称、货号和数量\n");
                    scanf_s("%s%s%d",x.name,x.no,&(x.num));
                    if(strcmp(x.no,y.no)!=0)
                        printf("输入货号与查询货号不一致,重来\n");
                    else
                    {
                     k=(LNode *)malloc(sizeof(LNode));
                    while(r->next!=NULL&&strcmp(r->next->data.no,x.no)<0)
                        r=r->next;
                    k->data=x;
                    k->next=r->next;
                    r->next=k;
                    printf("显示入库更新结果:\n");
                    printf("货物名称     货物编号      货物数量\n");
                    printf("%5s%12s%15d\n",k->data.name,k->data.no,k->data.num);
                    printf("输出出库后库存信息:\n");
                    P(head);
                    }
                }
    else
      {
        printf("请输入入库数量：\n");
        scanf_s("%d",&In_Num);
        printf("显示入库结果:\n");
        p->data.num+=In_Num;
        printf("货物名称     货物编号      货物数量\n");
        printf("%5s%12s%15d\n",p->data.name,p->data.no,p->data.num);
        printf("输出出库后库存信息\n");
        P(head);
      }
}
void getout(LNode *head,good x)
{
    int Out_Num;
    LNode *k;
    k=search(head,x);
    if(k==NULL)
        printf("不存在此编号货物\n");
    else
    {
        printf("请输入出库数量：\n");
        scanf_s("%d",&Out_Num);
        if(k->data.num<Out_Num)
                       printf("输入出库数量错误，请用户确认是否输入正确\n");
           else
           {
               if(k->data.num>Out_Num)
                      k->data.num-=Out_Num;
              else
                   if(k->data.num==Out_Num)//如果出库数等于原有货物数量，清除该货物
                         {
                            LNode *q=head;
                            while(q->next!=k)
                                q=q->next;
                            q->next=k->next;//k元素前面的节点的地址指向k后面节点的地址
                            free(k);  //释放k节点
                            printf("该货物全部出库，已删除\n");
                         }
                   printf("输出出库后剩余货物信息\n");
                   P(head);
                   printf("出库成功！\n");

           }
    }
}
int main()
{
    LNode *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    good x;
    int sel;
    LNode *k;
    do
    {
         menu();
         printf("请输入实现功能的序号：\n");
         scanf_s("%d",&sel);
        switch(sel)
        {
        case 1: head=input(head);
                P(head);
                printf("录入完成！\n");
                break;
        case 2: printf("输出已有货物名称、货号和数量\n");
                P(head);break;
        case 3: printf("输入需要查询货物的货号\n");
                    scanf_s("%s",x.no);
                    k=search(head,x);
                       if(k==NULL)
                            printf("库中该货物不存在，需要检查货号是否输入正确，并重来\n");
                       else
                        {
                             printf("该货号的货物信息如下：\n");
                             printf("货物名称     货物编号      货物数量\n");
                             printf("%5s%12s%15d\n",k->data.name,k->data.no,k->data.num);
                        }
                        break;
       case 4:getin(head,x);
                break;
       case 5:printf("请输入出库货号：\n");
               scanf_s("%s",x.no);
               getout(head,x);
               break;
       default:break;
       }
    }while(sel!=0);
return 0;
}