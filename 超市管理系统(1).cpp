#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20],     //�������ƣ�����������˶����������
         no[12];       //������
    int num;           //��������
}good;                //����������͵Ľṹ��
typedef struct  node     //�ڵ����͵Ľṹ��
{
    good data;         //����������
    struct  node *next;  //�����һ���������ݵĵ�ַ����ָ����
}LNode;
//�˵�����
void menu()
{
    printf("%60s","|--------------------------------------|\n");
    printf("%60s","|---------------*�˵�*-----------------|\n");
    printf("%60s","|1--------¼���������ơ����ź�����---|\n");
    printf("%60s","|2-----------������л�����Ϣ----------|\n");
    printf("%60s","|3---------�������ţ����һ���λ��------|\n");
    printf("%60s","|4--------------���-------------------|\n");
    printf("%60s","|5--------------����-------------------|\n");
    printf("%60s","|0------------�˳�ϵͳ-----------------|\n");
    printf("%60s","|--------------------------------------|\n");
}
//¼�������Ϣ
 LNode *input(LNode *head) 
       //����һ����������Ϊ������͵ĺ�������ΪҪ����ͷָ�룬����������������������
{
    LNode *s,*r;
    printf("������������\n");
    int i,len;
    good x;
    scanf_s("%d",&len);
    printf("����������ơ������ź�������\n");
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
//������л�����Ϣ
void P(LNode *head)
{
    LNode *p=head->next;
    printf("��������     ������      ��������\n");
    while(p!=NULL)
        {
            printf("%5s%12s%15d\n",p->data.name,p->data.no,p->data.num);
            p=p->next;
        }
}
//���ݻ��Ų��һ�����Ϣ
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
    printf("������Ҫ���Ļ���:\n");
    scanf_s("%s",x.no);
    good y=x;
    while((p!=NULL)&&strcmp(p->data.no,x.no)!=0)
        p=p->next;
    if(p==NULL)
                {
                    printf("�û��ﲻ���ڣ���¼��û�����Ϣ�����Ա���������\n");
                    printf("������������ơ����ź�����\n");
                    scanf_s("%s%s%d",x.name,x.no,&(x.num));
                    if(strcmp(x.no,y.no)!=0)
                        printf("����������ѯ���Ų�һ��,����\n");
                    else
                    {
                     k=(LNode *)malloc(sizeof(LNode));
                    while(r->next!=NULL&&strcmp(r->next->data.no,x.no)<0)
                        r=r->next;
                    k->data=x;
                    k->next=r->next;
                    r->next=k;
                    printf("��ʾ�����½��:\n");
                    printf("��������     ������      ��������\n");
                    printf("%5s%12s%15d\n",k->data.name,k->data.no,k->data.num);
                    printf("������������Ϣ:\n");
                    P(head);
                    }
                }
    else
      {
        printf("���������������\n");
        scanf_s("%d",&In_Num);
        printf("��ʾ�����:\n");
        p->data.num+=In_Num;
        printf("��������     ������      ��������\n");
        printf("%5s%12s%15d\n",p->data.name,p->data.no,p->data.num);
        printf("������������Ϣ\n");
        P(head);
      }
}
void getout(LNode *head,good x)
{
    int Out_Num;
    LNode *k;
    k=search(head,x);
    if(k==NULL)
        printf("�����ڴ˱�Ż���\n");
    else
    {
        printf("���������������\n");
        scanf_s("%d",&Out_Num);
        if(k->data.num<Out_Num)
                       printf("������������������û�ȷ���Ƿ�������ȷ\n");
           else
           {
               if(k->data.num>Out_Num)
                      k->data.num-=Out_Num;
              else
                   if(k->data.num==Out_Num)//�������������ԭ�л�������������û���
                         {
                            LNode *q=head;
                            while(q->next!=k)
                                q=q->next;
                            q->next=k->next;//kԪ��ǰ��Ľڵ�ĵ�ַָ��k����ڵ�ĵ�ַ
                            free(k);  //�ͷ�k�ڵ�
                            printf("�û���ȫ�����⣬��ɾ��\n");
                         }
                   printf("��������ʣ�������Ϣ\n");
                   P(head);
                   printf("����ɹ���\n");

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
         printf("������ʵ�ֹ��ܵ���ţ�\n");
         scanf_s("%d",&sel);
        switch(sel)
        {
        case 1: head=input(head);
                P(head);
                printf("¼����ɣ�\n");
                break;
        case 2: printf("������л������ơ����ź�����\n");
                P(head);break;
        case 3: printf("������Ҫ��ѯ����Ļ���\n");
                    scanf_s("%s",x.no);
                    k=search(head,x);
                       if(k==NULL)
                            printf("���иû��ﲻ���ڣ���Ҫ�������Ƿ�������ȷ��������\n");
                       else
                        {
                             printf("�û��ŵĻ�����Ϣ���£�\n");
                             printf("��������     ������      ��������\n");
                             printf("%5s%12s%15d\n",k->data.name,k->data.no,k->data.num);
                        }
                        break;
       case 4:getin(head,x);
                break;
       case 5:printf("�����������ţ�\n");
               scanf_s("%s",x.no);
               getout(head,x);
               break;
       default:break;
       }
    }while(sel!=0);
return 0;
}