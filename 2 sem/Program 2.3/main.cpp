#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef struct unilist
{
    char city[20];
    int region;
    int people;
    unilist *next;
    unilist *past;
} unilist;

unilist *head;
unilist *tail;

void AddList(char city[20], int region, int people/*, int position*/)
{
unilist *node=new unilist; //�������� ������ ��������
strcpy(node->city,city);
node->people=people;
node->region=region;
///�������� ��������� � �������

node->past=NULL;
node->next=NULL;
 //���������� �������� ��������
if (head==NULL) //���� ������ ����
{
node->next=NULL; //��������� ��������� next
node->past=NULL; //��������� ��������� prev
head=node;
tail=node;
}
else
{
    ///���� ���� ������ ������
    if(head==tail)
    {
        node->past=tail;
        tail->next=node;
        node->next=NULL;
        tail=node;
    }
    else
    {
    unilist *p;
    p=tail;
    ///���� ����������� ������ ����� ������ ���������
    while(1){
    if(node->region<p->region)
    {
        p->past->next=node;
        node->past=p->past;
        p->past=node;
        node->next=p;
        break;
    }
    if(node->region>p->region){
        ///���� �������� ��������� �� ���� ������
        if(p->next==NULL)
        {
            p->next=node;
            node->past=p;
            node->next=NULL;
            break;
        }
        else{
            ///����� ���� �� ������
            p=p->next;
        }
    }
    ///���������� ������
    if(node->region==p->region){
        if(strcmp(node->city,p->city)==-1)
        {
        p->past->next=node;
        node->past=p->past;
        p->past=node;
        node->next=p;
        break;
        }
    else{
        ///���� �������� ��������� �� ���� ������
        if(p->next==NULL)
        {
            p->next=node;
            node->past=p;
            node->next=NULL;
            break;
        }
        else{
            ///����� ���� �� ������
            p=p->next;
        }
    }
    }
    }
    }
}
}

void First(int rg){
    unilist *p;
    p=head;
    cout<<"������ ������� "<<rg<<"\n";
    while(p->next!=NULL)
    {
        if(p->region==rg)
            cout<<p->city<<"\n";
        p=p->next;
    }
}

void second()
{
    unilist *p;
    p=head;
    int sum=0, reg;
    while(1)
    {
        ///������� ���������  ����
        reg=p->region;
        sum=p->people;
        while(1)
        {
           if(p->next!=NULL && p->next->region==reg)
           {
               p=p->next;
           }
           else break;
           sum=sum+p->region;
        }
        cout<<"������ "<<reg<<" - ��������� "<<sum<<"\n";
        if(p->next!=NULL)
           {
               p=p->next;
               sum=0;
           }
        else break;
    }
}
int main()
{
    int u=0;
    char incity[20];
    int inregion;
    int incitizen;
    setlocale(LC_ALL,"Russian");

    while(1)
    {
    cout<<"������� [����� #������� ���-�� �������]:\n";
    cin>>incity>>inregion>>incitizen;

            AddList(incity,inregion, incitizen);
      cout<<"����������?[��(1)\���(0)]\n";
        cin>>u;
        if(u==0)
            break;
        }
    while(1)
    {
        int andl, mr;
        cout<<"�������� �������\n";
        cout<<"1. ������� ������ �������\n";
        cout<<"2. ��������� ��������\n";
        cout<<"0. ������\n";
        cin>>andl;
       if(andl==1){
           cout<<"�������� ������\n";
            cin>>mr;
           First(mr);
          break;
       }
      if(andl==2){
        second();
          break;
      }
      if(andl==0)
            break;
    }
    return 0;
}
