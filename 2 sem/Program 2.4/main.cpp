#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


typedef struct unilist
{
    int numkey;
    char wordkey;
    unilist *numnext;
    unilist *numpast;
    unilist *wordnext;
    unilist *wordpast;
}unilist;

unilist *head;
unilist *tail;

void addlist(int innum, char inword)
{
    unilist *node=new unilist;
    node->numkey=innum;
    node->wordkey=inword;
    ///���� ��� ������ ������� ������
    if(head==NULL)
    {
        head=node;
        tail=node;
        node->numnext=NULL;
        node->numpast=NULL;
        node->wordnext=NULL;
        node->wordpast=NULL;
    }
    else{
    ///������� ��������� �� ������� ����������� �����
        ///���� ���� ������ ������
        if(head==tail)
    {
        node->numpast=tail;
        tail->numnext=node;
        node->numnext=NULL;
        node->wordpast=tail;
        tail->wordnext=node;
        node->wordnext=NULL;
        tail=node;
    }
        else
        {
            unilist *p;
            unilist *d;
            p=tail;
            d=tail;
            while(1) ///������� ����
            {
                ///���� ����������� ����� ����� ������ ���������
                if(node->numkey<p->numkey)
                {
                    p->numpast->numnext=node;
                    node->numpast=p->numpast;
                    p->numpast=node;
                    node->numnext=p;
                    break;
                }
                else
                {
                    ///���� �������� ����� ��������� �� ���� ������
                    if(p->numnext==NULL)
                    {
                        p->numnext=node;
                        node->numpast=p;
                        node->numnext=NULL;
                        break;
                    }
                    else{
                    ///����� ���� �� ������
                        p=p->numnext;
                    }

                }
            }
            while(1) ///�������� ����
            {
                ///���� ����������� ������ ����� ������ ���������
                if(node->wordkey<d->wordkey)
                {
                    d->wordpast->wordnext=node;
                    node->wordpast=d->wordpast;
                    d->wordpast=node;
                    node->wordnext=d;
                    break;
                }
                else
                {
                    if(d->wordnext==NULL)
                    {
                        d->wordnext=node;
                        node->wordpast=d;
                        node->wordnext=NULL;
                        break;
                    }
                    else
                    {
                        d=d->wordnext;
                    }
                }
            }
        }
    }
}

void first()
{
    unilist *w;
    w=head;
    while(w->numnext!=NULL)
    {
        cout<<w->numkey<<" "<<w->wordkey<<"\n";
        w=w->numnext;
    }
    cout<<w->numkey<<" "<<w->wordkey<<"\n";
}

void second()
{
    unilist *w;
    w=head;
    while(w->wordnext!=NULL)
    {
        cout<<w->numkey<<" "<<w->wordkey<<"\n";
        w=w->wordnext;
    }
    cout<<w->numkey<<" "<<w->wordkey<<"\n";
}

int main()
{
    setlocale(LC_ALL,"Russian");
    char word;
    int num, m0,m1=0,m2=0;
    while(1)
    {
        cout<<"�������� ��������:\n";
        cout<<"1. ������ ����\n";
        if(m1!=0)
        {
            cout<<"2. ������� ����� � ������� ����� �����\n";
            cout<<"3. ������� ����� � ���������� ������� \n";
        }
        cout<<"0. ��������� ������\n";
        cin>>m0;
        if(m0==1)
        {
            m1=1;
            while(1){
            cout<<"������� ����: [����� ���.������]\n";
            cin>>num>>word;
            addlist(num,word);
            cout<<"����������?[��(1)\���(0)]\n";
            cin>>m2;
            if(m2==0)
                break;
            }
        }
        if(m0==2)
        {
            first();
        }
        if(m0==3)
        {
            second();
        }
        if(m0==0)
        {
            cout<<"���������� ������...\n";
            break;
        }
    }
    return 0;
}
