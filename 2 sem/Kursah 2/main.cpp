#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

typedef struct group{
    int number;
   struct student* people;
   struct group* next;
   //struct group* past;
}group;

typedef struct student{
    int bpoint;
    char fio[40];
    int rating[5];
    char priznak;
    int money;
    struct student* next;
   // struct student* past;
}student;

typedef struct contract
{
    char fio[40];
    struct contract* next;
}contract;

typedef struct table
{
    int group;
    int studnum;
    int stepsum;
    int rate;
    struct table* next;
}table;

int basepoint, aimp=0;
group *head;
student *fc;
contract *syd;
table *zip;
void enterkon(int grp,char fio[40],int rate[5],char priznak,int money)
{
    int u;
    group *node=new group;
    student *vode=new student;

    node->number=grp;
    node->next=NULL;
   // node->past=NULL;
    //node->people=vode;

    vode->bpoint=basepoint;
    basepoint++;
    strcpy(vode->fio,fio);
    vode->money=money;
    vode->priznak=priznak;
    vode->next=NULL;
   // vode->past=NULL;
    for(u=0;u<5;u++)
    {
        vode->rating[u]=rate[u];
    }

    if(head==NULL)
    {
        head=node;
        node->people=vode;
    }
    else
    {
        group *p=head;
        while(1)
        {
            if(node->number==p->number)
            {
                student* d=p->people;
                while(1)
                {
                    if(d->next==NULL)
                    {
                        d->next=vode;
                        break;
                    }
                    else
                      d=d->next;
                }
                break;
            }
            if(p->next==NULL)
            {
                p->next=node;
                node->people=vode;
                break;
            }
            else
                p=p->next;
        }
    }

}

void enterfile(string path)
{
    int grp, money;
    char fio[40];
    char priznak;
    int rate[5];
    int i,p=0;

    ifstream file;
    file.open(path);
    while(file!=NULL)
    {
        if(p!=0)
        enterkon(grp,fio,rate,priznak,money);
        file>>grp>>fio;
                for(i=0;i<5;i++)
                    file>>rate[i];
                file>>priznak>>money;
                p=1;
               // enterkon(grp,fio,rate,priznak,money);
    }

}

void outcon()
{
  group* a=head;
  student* b;
  int i;
  while(1)
  {
      cout<<a->number<<"\n";
      b=a->people;
      while(1)
      {
          cout<<"\t"<<b->bpoint<<" "<<b->fio<<" ";
          for(i=0;i<5;i++)
            cout<<b->rating[i]<<" ";
          cout<<b->priznak<<" "<<b->money<<"\n";
          if(b->next==NULL)
            break;
          else
          {
              b=b->next;
          }
      }
      if(a->next==NULL)
      {
          break;
      }
      else
      {
          a=a->next;
      }
  }
}

void outfile()
{
    int i;
    ofstream fout;
    fout.open("result.txt");
    group* a=head;
  student* b;
  while(1)
  {
      fout<<a->number<<"\n";
      b=a->people;
      while(1)
      {
          fout<<"\t"<<b->bpoint<<" "<<b->fio<<" ";
          for(i=0;i<5;i++)
            fout<<b->rating[i]<<" ";
          fout<<b->priznak<<" "<<b->money<<"\n";
          if(b->next==NULL)
            break;
          else
          {
              b=b->next;
          }
      }
      if(a->next==NULL)
      {
          break;
      }
      else
      {
          a=a->next;
      }
  }
  fout.close();
}

void delstud(int gp,int bp)
{
    int u=0;
  student *l;
  group *p=head;
  student *w;
  while(1)
  {
      if(p->number==gp)
      {
          l=p->people;
          break;
      }
      if(p->next==NULL)
      {
          cout<<"Группа не была найдена!\n";
          return;
      }
      else
        p=p->next;
  }

  if(l->bpoint==bp)
     {
         p->people=l->next;
         delete l;
         return;
     }
  while(1)
  {
     if(l->next->bpoint==bp)
     {

         if(l->next!=NULL && l->next->next!=NULL)
         w=l->next->next;
         else
            w=NULL;
         delete l->next;
         l->next=w;
         delete w;
         return;
     }
     if(l->next==NULL)
     {
         cout<<"Студент не был найден!\n";
          return;
     }
     else
        l=l->next;
  }
}

void delgroup(int gr)
{
    group *p=head;
    group *w;
    if(p->number==gr)
        {
            head=p->next;
                delete p;
                return;
        }
    while(1)
    {
        if(p->next->number==gr)
        {
            if(p->next!=NULL && p->next->next!=NULL)
                w=p->next->next;
         else
            w=NULL;
         delete p->next;
         p->next=w;
         delete w;
         return;
        }
        if(p->next==NULL)
        {
            cout<<"Группа не былa найденa!\n";
          return;
        }
        else
        p=p->next;
    }
}

void changroup(int gr, int chgr)
{
    student* o;
    group* l=head;
    int u=0;
    while(1)
    {
        if(chgr==l->number)
        {
            u=1;
            o=l->people;
            while(1)
            {
                if(o->next!=NULL)
                    o=o->next;
                else
                    break;
            }
            break;
        }
        if(l->next!=NULL)
        {
            l=l->next;
        }
        else
            break;
    }
    l=head;
    while(1)
    {
       if(gr==l->number)
       {
           if(u!=0)
           {
               o->next=l->people;
               delgroup(gr);
               return;
           }
           if(u==0)
           {
               l->number=chgr;
               return;
           }
       }
       if(l->next==NULL)
           {
               cout<<"Группа не былa найденa!\n";
               return;
           }
           else
            l=l->next;
    }

}

void changstud(int grp,int chgroup, int chcode,  char fio[40],int rate[5],char priznak,int money)
{
    int u;
    int t=0;
    group* p=head;
    student* i;
    student* w;

    student *vode=new student;
    vode->bpoint=chcode;
    strcpy(vode->fio,fio);
    vode->money=money;
    vode->priznak=priznak;
    vode->next=NULL;
   // vode->past=NULL;
    for(u=0;u<5;u++)
    {
        vode->rating[u]=rate[u];
    }

    if(grp==chgroup)
    {
        t=1;
    }
    while(1)
    {
        if(p->number==grp)
        {
            i=p->people;
            if(i->bpoint==chcode)
            {
                vode->next=i->next;
                p->people=vode;
                return;
            }
            while(1)
            {
                if(i->next->bpoint==chcode)
                {
                    if(t==1){
                    if(i->next->next!=NULL)
                        {
                            vode->next=i->next->next;
                            delete i->next;
                            i->next=vode;
                            return;
                        }
                    else
                        {
                            delete i->next;
                            i->next=vode;
                            return;
                        }
                    }
                    if(t!=1)
                    {
                        delstud(grp,chcode);
                        enterkon(chgroup,fio,rate,priznak,money);
                    }
                }
                if(i->next==NULL)
                {
                    cout<<"Студент не найден!\n";
                }
                else
                    i=i->next;
            }
        }
        if(p->next==NULL)
        {
            cout<<"Группа не былa найденa!\n";
            return;
        }
        else
            p=p->next;
    }
}

void firstout()
{
    contract* io=syd;
    cout<<"ФИО всех контрактников, не вносящих оплату в обучение:\n";
    while(1)
    {
        cout<<io->fio<<"\n";
        if(io->next==NULL)
            break;
        else
        {
            io=io->next;
        }
    }
}

void firstenter(char fio[40])
{
    contract* f=syd;
    contract* node=new contract;
    strcpy(node->fio,fio);
    node->next==NULL;
    if(syd==NULL)
    {
        syd=node;
    }
    else
    {
        contract* v=syd;
        if(strcmp(v->fio,node->fio)>0)
        {
            node->next=v;
            syd=node;
        }
        else
        {
            while(1)
            {
                if(strcmp(v->next->fio,node->fio)>0)
                {
                    node->next=v->next;
                    v->next=node;
                    break;
                }
                if(v->next==NULL)
                {
                    v->next=node;
                    break;
                }
                else
                    v=v->next;
            }
        }
    }
}

void first()
{
    if(aimp!=0)
    {
     firstout();
     return;
    }
    group* p=head;
    student* q;
    while(1)
    {
        q=p->people;
        while(1)
        {
            if(q->priznak=='k' && q->money==0)
            {
                firstenter(q->fio);
            }
            if(q->next==NULL)
                break;
            else
                q=q->next;
        }
        if(p->next==NULL)
            break;
        else
            p=p->next;
    }
    aimp=1;
    firstout();
}

void secout()
{
    table* io=zip;
    cout<<"Таблица:\n";
    cout<<"ГРУППА \t КОЛ-ВО СТУДЕНТОВ \t СУММА СТИПЕНДИЙ \t СРЕДНИЙ БАЛЛ:\n";
    while(1)
    {
        cout<<io->group<<"\t\t\t"<<io->studnum<<"\t\t\t"<<io->stepsum<<"\t\t\t"<<io->rate<<"\n";
        if(io->next==NULL)
            break;
        else
        {
            io=io->next;
        }
    }
}

void secin(int grp,int stud,int sum, int seball)
{
    table* node=new table;
    node->group=grp;
    node->studnum=stud;
    node->stepsum=sum;
    node->rate=seball;
    node->next=NULL;

    if(zip==NULL)
    {
        zip=node;
    }
    else
    {
        table* v=zip;
        if(node->stepsum>v->stepsum)
        {
            node->next=v;
            zip=node;
        }
            else
            {
                while(1)
            {
                if(v->next->stepsum<node->stepsum)
                {
                    node->next=v->next;
                    v->next=node;
                    break;
                }
                if(v->next==NULL)
                {
                    v->next=node;
                    break;
                }
                else
                    v=v->next;
            }
            }
    }
}

void second()
{
    int i;
    group* w=head;
    student* b;

    int grp;
    int stud=0;
    int sum=0;
    int seball=0;

    while(1)
    {
        stud=0;
        sum=0;
        seball=0;
        grp=w->number;
        b=w->people;
        while(1)
        {
            for(i=0;i<5;i++)
            {
                seball=seball+b->rating[i];
            }
            stud++;
            if(b->priznak=='b')
            sum=sum+b->money;
            if(b->next==NULL)
                break;
            else
                b=b->next;
                seball=seball/5;
        }
        seball=seball/stud-1;
        secin(grp,stud,sum,seball);

        if(w->next==NULL)
            break;
        else
            w=w->next;
    }
    secout();
}

int main()
{
    basepoint=0;
    setlocale(LC_ALL,"Russian");
    int p1=0,p2=0,p3=0;
    int u0,u1,u2,u3,u4,u5,u6;
    int i1;
    int t1,t2,t3;
    ///для ввода потока
    int grp, money;
    char fio[40];
    char priznak;
    int rate[5];
    while(1)
    {
        cout<<"Выберите действие:\n";
        cout<<"1. Ввести данные о потоке\n";
        if(p1!=0)
            cout<<"2. Изменить данные\n";
        if(p2!=0)
            cout<<"3. Вывести данные о потоке\n";
        if(p1!=0)
            cout<<"4. Доп.задание\n";
        cout<<"0. Выйти\n";
        if(p3==0)
        cin>>u0;
        else{
            p3=0;
            u0=2;
        }
        if(u0==0){
            cout<<"Завершение работы...\n";
            break;
        }
        if(u0==1)
        {
            cout<<"Ввести данные о потоке\n";
            cout<<"\t1.Консольный ввод\n";
            cout<<"\t2.Файловый ввод\n";
            cout<<"\t0.Назад\n";
            cin>>u1;
            if(u1==0)
                continue;
            if(u1==1)
            {

                p1=p2=1;
                cout<<"Введите данные студентов\n";
               while(1){
                cout<<"[группа] [ФИО] [оценки] [B/K] [ФИНАНСЫ]\n";
                cin>>grp>>fio;
                for(i1=0;i1<5;i1++)
                    cin>>rate[i1];
                cin>>priznak>>money;
                enterkon(grp,fio,rate,priznak,money);
                cout<<"Продолжить? [ДА(1)\НЕТ(0)]\n";
                cin>>u2;
                if(u2==0)
                    break;
               }
            }
            if(u1==2)
            {
                p1=p2=1;
                enterfile("enter.txt");
            }

        }
        if(u0==2)
            {
                cout<<"Выберите действия:\n";
                cout<<"\t1.Изменить данные\n";
                cout<<"\t2.Удалить данные\n";
                cout<<"\t0.Назад\n";
                cin>>u4;
                if(u4==0)
                    continue;
                if(u4==1)
                {
                    cout<<"Выберите действия:\n";
                    cout<<"\t\t1.Изменить номер группы\n";
                    cout<<"\t\t2.Изменить данные студента\n";
                    cout<<"\t\t0.Назад\n";
                    cin>>u5;
                    if(u5==0)
                        p3=1;
                    if(u5==1)
                    {
                        cout<<"\t\tВведите старый и новый номер группы:\n";
                        cin>>t1;
                        cin>>t2;
                        changroup(t1,t2);
                    }
                    if(u5==2)
                    {
                        cout<<"\t\tВведите группу и код студента: [группа код]\n";
                        cin>>t1;
                        cin>>t2;
                        cout<<"[группа] [ФИО] [оценки] [B/K] [ФИНАНСЫ]\n";
                        cin>>grp;
                        cin>>fio;
                        for(i1=0;i1<5;i1++)
                            cin>>rate[i1];
                            cin>>priznak>>money;
                        changstud(t1,grp,t2,fio,rate,priznak,money);
                    }
                }
                if(u4==2)
                    {
                    cout<<"Выберите действие:\n";
                    cout<<"\t\t1.Удалить группу [Zheleznyak-protocol]\n";
                    cout<<"\t\t2.Удалить данные студента\n";
                    cout<<"\t\t0.Назад\n";
                    cin>>u5;
                    if(u5==0)
                        {
                         p3=1;
                        }
                    if(u5==1)
                    {
                        cout<<"\t\tВведите группу:\n";
                        cin>>t3;
                        delgroup(t3);
                    }
                    if(u5==2)
                    {
                        cout<<"\t\tВведите группу и код студента: [группа код]\n";
                        cin>>t1;
                        cin>>t2;
                        delstud(t1,t2);
                    }
            }
            }
        if(u0==3)
        {
            cout<<"Ввести данные о потоке\n";
            cout<<"\t1.Консольный вывод\n";
            cout<<"\t2.Файловый вывод\n";
            cout<<"\t0.Назад\n";
            cin>>u3;
            if(u3==0)
                continue;
            if(u3==1)
            {
                outcon();
            }
            if(u3==2){
                outfile();
                cout<<"Данные выведены в файл result.txt\n";
            }
        }
        if(u0==4)
        {
            cout<<"Выберите действие:\n";
                    cout<<"\t1.Вывести в алф порядке фио всех контрактников \n";
                    cout<<"\t2.Таблица группа-колво студентов-сумма стипендий-средбалл\n";
                    cout<<"\t0.Назад\n";
            cin>>u6;
            if(u6==0)
                continue;
            if(u6==1)
            {
                first();
            }
            if(u6==2)
            {
                second();
            }
        }

    }
    return 0;
}
