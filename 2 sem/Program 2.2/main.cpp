#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct metrolist{
int line;
char station[20];
char nextst[20];
char pastst[20];
};

struct legenda{
    int line;
    char** station;
};


int main()
{
    setlocale(LC_ALL,"Russian");
    ifstream filein;
    ofstream fileout;
    int stcount, i,j=0,k=0, x=0,y=0,z=1;
    int line=0;
    char just[25], point[20]="0",epoint[20];
    //cout<<point<<"\n";
    filein.open("enter.txt");
    for(stcount=0;!filein.eof();stcount++){
    filein>>just>>just>>just>>just;
    }
    filein.close();

    metrolist mlist[stcount];
    filein.open("enter.txt");
    for(i=0;i<stcount;i++)
    {
        filein>>mlist[i].line>>mlist[i].station>>mlist[i].nextst>>mlist[i].pastst;
        if(line<mlist[i].line)
            line=mlist[i].line;
    }
    filein.close();

    legenda mleg[line]; ///ÑÒÐÓÊÒÓÐÀ ÑÎ ÑÒÀÍÖÈßÌÈ
    int secount[line]; ///ÌÀÑÑÈÂ Ñ ÊÎËËÈ×ÅÑÒÂÎÌ ÑÒÀÍÖÈÉ ÍÀ ËÈÍÈÞ
    for(j=0;j<line;j++)
    {
        secount[z]=0;
         for(k=0;k<stcount;k++)
        {
            if(mlist[k].line==j+1)
                secount[z]++;
        }
    mleg[j].station= new char*[secount[z]];
    for(i=0;i<secount[z];i++)
        {
            mleg[j].station[i]=new char[20];
        }
        z++;
    }

    for(j=0;j<line;j++)
    {
        x=0;
        for(i=0;i<stcount;i++)
        {
            if(mlist[i].line==j+1 && strcmp(mlist[i].pastst,point)==0)
            {
                strcpy(epoint,mlist[i].pastst);
                mleg[i].line=j+1;
                strcpy(mleg[j].station[x],mlist[i].station);
                strcpy(point,mlist[i].station);
                x++;
                for(k=0;k<stcount;k++){
                    if(mlist[k].line==j+1 && strcmp(point,mlist[k].pastst)==0)
                    {
                       strcpy(mleg[j].station[x],mlist[k].station);
                       strcpy(point,mlist[k].station);
                       x++;
                       k=0;
                    }
                }
              strcpy(point,epoint);
            }
        }
    }
        fileout.open("result.txt");

        for(j=0;j<line;j++)
        {
            fileout<<"=====Ëèíèÿ íîìåð "<<j+1<<" =====\n";
            for(i=0;i<secount[j+1];i++)
            {
                fileout<<mleg[j].station[i]<<"\n";
                for(k=0;k<line;k++)
                    if(k!=j)
                {
                    for(z=0;z<secount[k+1];z++)
                    {
                        if(strcmp(mleg[j].station[i],mleg[k].station[z])==0)
                            fileout<<"   [Ïåðåõîä íà ëèíèþ "<<k+1<<"]\n";
                    }
                }
            }
        }
        fileout.close();


    return 0;
}
