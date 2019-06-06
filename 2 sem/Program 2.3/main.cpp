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
unilist *node=new unilist; //ñîçäàíèå íîâîãî ýëåìåíòà
strcpy(node->city,city);
node->people=people;
node->region=region;
///ÔÈÊÑÀÖÈß ÓÊÀÇÀÒÅËß Ê ÐÅÃÈÎÍÓ

node->past=NULL;
node->next=NULL;
 //ïðèñâîåíèå ýëåìåíòó çíà÷åíèÿ
if (head==NULL) //åñëè ñïèñîê ïóñò
{
node->next=NULL; //óñòàíîâêà óêàçàòåëÿ next
node->past=NULL; //óñòàíîâêà óêàçàòåëÿ prev
head=node;
tail=node;
}
else
{
    ///ÅÑËÈ ÅÑÒÜ ÒÎËÜÊÎ ÊÎÐÅÍÜ
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
    ///ÅÑËÈ ÏÎÑËÅÄÓÞÙÈÉ ÐÅÃÈÎÍ ÇÂÅÍÀ ÁÎËÜØÅ ÂÂÎÄÈÌÎÃÎ
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
        ///ÅÑËÈ ÂÂÎÄÈÌÎÅ ÎÊÀÇÀËÎÑÜ ÍÀ ÊÐÀÞ ÑÏÈÑÊÀ
        if(p->next==NULL)
        {
            p->next=node;
            node->past=p;
            node->next=NULL;
            break;
        }
        else{
            ///ÈÍÀ×Å ÈÄÅÌ ÏÎ ÑÏÈÑÊÓ
            p=p->next;
        }
    }
    ///ÑÐÀÂÍÈÂÀÅÌ ÃÎÐÎÄÀ
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
        ///ÅÑËÈ ÂÂÎÄÈÌÎÅ ÎÊÀÇÀËÎÑÜ ÍÀ ÊÐÀÞ ÑÏÈÑÊÀ
        if(p->next==NULL)
        {
            p->next=node;
            node->past=p;
            node->next=NULL;
            break;
        }
        else{
            ///ÈÍÀ×Å ÈÄÅÌ ÏÎ ÑÏÈÑÊÓ
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
    cout<<"Ãîðîäà ðåãèîíà "<<rg<<"\n";
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
        ///ÑÍÀ×ÀËÀ ÍÀ×ÀËÜÍÛÉ  ÓÇÅË
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
        cout<<"Ðåãèîí "<<reg<<" - íàñåëåíèå "<<sum<<"\n";
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
    cout<<"Ââåäèòå [Ãîðîä #ðåãèîíà êîë-âî æèòåëåé]:\n";
    cin>>incity>>inregion>>incitizen;

            AddList(incity,inregion, incitizen);
      cout<<"Ïðîäîëæèòü?[Äà(1)\Íåò(0)]\n";
        cin>>u;
        if(u==0)
            break;
        }
    while(1)
    {
        int andl, mr;
        cout<<"Âûáåðèòå âàðèàíò\n";
        cout<<"1. Âûâåñòè ãîðîäà ðåãèîíà\n";
        cout<<"2. Íàñåëåíèå ðåãèîíîâ\n";
        cout<<"0. Îòìåíà\n";
        cin>>andl;
       if(andl==1){
           cout<<"Âûáåðèòå ðåãèîí\n";
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
