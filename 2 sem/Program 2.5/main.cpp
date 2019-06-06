#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
///��������� ������
typedef struct tree {
    int number;
    struct tree *left;
    struct tree *right;
} tree;
tree* head;
///��������� �������
typedef struct lifo{
    struct tree* a;
    struct lifo* next;
}lifo;
lifo* fc;
lifo* tail;
///���������� �������� � ������
void addlist(int newnumber){
    tree *node=new tree;
    node->number=newnumber;
    node->left=NULL;
    node->right=NULL;
    if(head==NULL)
    {
        node->left=NULL;
        node->right=NULL;
        head=node;
    }
    else
    {
        tree* p=head;
        while(1)
        {
            if(node->number<p->number)
            {
                if(p->left==NULL)
                {
                    p->left=node;
                    break;
                }
                else
                {
                    p=p->left;
                }
            }
            else
            {
              if(p->right==NULL)
                {
                    p->right=node;
                    break;
                }
                else
                {
                 p=p->right;
                }
            }
        }
    }
}
///������� ���������� � �������
void entoch(tree* loud)
{
    lifo* come=new lifo;
    come->a=loud;
    come->next=NULL;
    if(fc==NULL){
        fc=come;
        tail=fc;
    }
    else
    {
        lifo* g=tail;
        while(1)
        {
            if(g->next==NULL)
                {
                g->next=come;
                tail=come;
                break;
            }
            else
                g=g->next;
        }
    }
}
///������� �������� �� �������
void deloch()
{
  lifo* l;
  l=fc->next;
  free(fc);
  fc=l;
}
///������� ������ � ������ � ��������
void ochered()
{
    tree* w=head;
    entoch(w);
    while(1)
    {
        if(w->left!=NULL)
            entoch(w->left);
        if(w->right!=NULL)
            entoch(w->right);
        cout<<fc->a->number<<" ";
        if(fc->next==NULL)
            break;
        deloch();
        w=fc->a;
    }
}
///������� ������ �� �����������
void inorder(tree *d)
{
    if (d == NULL)
        return;
    inorder(d->left);
    if (d->number)
        cout<<d->number<<" ";
    inorder(d->right);
}
int main()
{
    setlocale(LC_ALL,"Russian");
    int number,m;
    while(1)
    {
        cout<<"������� �����:\n";
        cin>>number;
        addlist(number);
        cout<<"����������?[��(1)\���(0)]\n";
            cin>>m;
        if(m==0) break;
    }
    cout<<"1. �� �����������:\n";
    inorder(head);
    cout<<"\n";
    cout<<"2. ����� � ������:\n";
	ochered();
    lifo* y=fc;
    while(y->next!=NULL)
    {
        cout<<y->a->number<<" ";
        y=y->next;
    }
    return 0;
}
