#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


struct work
{
    int numproz;
    char id[10];
    int time;
};

int main()
{
    setlocale(LC_ALL,"Russian");
    int i,j, country, pcount=0;
    ///pcount - ����������� �����������
    ///country - ����������� �����
    char nadesuat[10];
///��������� ����������� ����� � �����������
    ifstream filein;
    filein.open("enter.txt");
    for(country=0;!filein.eof();country++){
        filein>>j;
        if(pcount<j)
            pcount=j;
        filein>>nadesuat>>nadesuat;
    }
    filein.close();
///��������� ���������� �����
    work sup[country]; ///��������� � ������� �����
   // int* masiv4ik= new int[pcount];
   // int* schetchik= new int[pcount];
   int masiv4ik[pcount], schetchik[pcount];
///��� ������� � ������
    for(i=0;i<pcount;i++){
        masiv4ik[i]=0; ///������ �� ������������ ����� �� ���������
        schetchik[i]=0;
    }
///������ ����� � ���������� ����������� ����� �� �����������
    filein.open("enter.txt");
    for(i=0;i<country;i++)
        {
            filein>>sup[i].numproz>>sup[i].id>>sup[i].time;
            masiv4ik[sup[i].numproz-1]++;
        }
    filein.close();

    work*** korobka = new work**[pcount];
    for(i=0;i<pcount;i++)
    {
       korobka[i]= new work*[masiv4ik[i]];
    }
///������ ���������� ������� ������ ������ ������
    for(i=0;i<country;i++)
    {
        korobka[sup[i].numproz-1][schetchik[sup[i].numproz-1]]=&(sup[i]);
        schetchik[sup[i].numproz-1]++;
    }
    ///abc - ���������� �����
    ///pointer - �������� �� ����������� ������
    int* pointer = new int[pcount];
    for(i=0;i<pcount;i++){
        pointer[i]=0;
    }
    int abs=0, mindex,k;
    for(j=0;j<country;j++)
    {
         mindex=0;
            for(i=1;i<pcount;i++)
        {
            if(pointer[i]==masiv4ik[i])
                break;
            if(korobka[mindex][pointer[mindex]]->time>korobka[i][pointer[i]]->time)
                mindex=i;
        }
         abs+=korobka[mindex][pointer[mindex]]->time;
         cout<<abs<<" "<<korobka[mindex][pointer[mindex]]->numproz<<" "<<korobka[mindex][pointer[mindex]]->id<<" "<<korobka[mindex][pointer[mindex]]->time<<"\n";
         for(k=0;k<pcount;k++)
         {
                if(pointer[k]==masiv4ik[k])
                break;
             korobka[k][pointer[k]]->time-=korobka[mindex][pointer[mindex]]->time;
             pointer[mindex]++; ///��� �?
         }

         cout<<"\n";
    }
    return 0;
}
