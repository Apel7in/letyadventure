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
    ///ÅÑËÈ ÝÒÎ ÏÅÐÂÛÉ ÝËÅÌÅÍÒ ÑÏÈÑÊÀ
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
    ///ÑÍÀ×ÀËÀ ÑÎÐÒÈÐÓÅÌ ÏÎ ÏÎÐßÄÊÓ ÂÎÇÐÀÑÒÀÍÈß ×ÈÑËÀ
        ///ÅÑËÈ ÅÑÒÜ ÒÎËÜÊÎ ÊÎÐÅÍÜ
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
            while(1) ///ÍÀÌÎÂÛÉ ÂÀÉË
            {
                ///ÅÑËÈ ÏÎÑËÅÄÓÞÙÀß ÖÈÔÐÀ ÇÂÅÍÀ ÁÎËÜØÅ ÂÂÎÄÈÌÎÃÎ
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
                    ///ÅÑËÈ ÂÂÎÄÈÌÀß ÖÈÔÐÀ ÎÊÀÇÀËÎÑÜ ÍÀ ÊÐÀÞ ÑÏÈÑÊÀ
                    if(p->numnext==NULL)
                    {
                        p->numnext=node;
                        node->numpast=p;
                        node->numnext=NULL;
                        break;
                    }
                    else{
                    ///ÈÍÀ×Å ÈÄÅÌ ÏÎ ÑÏÈÑÊÓ
                        p=p->numnext;
                    }

                }
            }
            while(1) ///ÂÎÐÄÎÂÛÉ ÂÀÉË
            {
                ///ÅÑËÈ ÏÎÑËÅÄÓÞÙÈÉ ÑÈÌÂÎË ÇÂÅÍÀ ÁÎËÜØÅ ÂÂÎÄÈÌÎÃÎ
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
        cout<<"Âûáåðèòå äåéñòâèå:\n";
        cout<<"1. Ââåñòè êëþ÷\n";
        if(m1!=0)
        {
            cout<<"2. Âûâåñòè êëþ÷è â ïîðÿäêå ðîñòà ÷èñåë\n";
            cout<<"3. Âûâåñòè êëþ÷è â àëôàâèòíîì ïîðÿäêå \n";
        }
        cout<<"0. Çàâåðøèòü ðàáîòó\n";
        cin>>m0;
        if(m0==1)
        {
            m1=1;
            while(1){
            cout<<"Ââåäèòå êëþ÷: [÷èñëî ëàò.ñèìâîë]\n";
            cin>>num>>word;
            addlist(num,word);
            cout<<"Ïðîäîëæèòü?[Äà(1)\Íåò(0)]\n";
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
            cout<<"Çàâåðøåíèå ðàáîòû...\n";
            break;
        }
    }
    return 0;
}
