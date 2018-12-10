#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int mass[10];
    int i;
    for(i=0;i<10;i++)
    {
        cin>>mass[i];
    }

    //number 1
    int j;
    int smass[5];
    i=0;
    for(j=0;j<5;j++)
    {
        smass[j]=mass[i]+mass[i+1];
        i+=2;
    }

    int sp1,sp2,st;
    for(sp1=0;sp1<5;sp1++)
    {
        for(sp2=0;sp2<4;sp2++){
            if(smass[sp2+1]<smass[sp2])
                {
            st=smass[sp2];
            smass[sp2]=smass[sp2+1];
            smass[sp2+1]=st;
                }
        }
    }
    cout<<"[1] ";
    for(j=0;j<5;j++)
    {
        cout<<smass[j]<<" ";
    }
    cout<<"\n";


//number 2
    int w;
    cout<<"[2] ";
    for(w=9;w>=0;w-=2)
    {
        cout<<mass[w]<<" ";
    }
    cout<<"\n";

//number 3
    cout<<"[3]\n";
    int fp1,fp2,tp, k;
    for(fp1=0;fp1<10;fp1++)
    {
        for(k=0;k<10;k++)
                {
            cout<<mass[k]<<" ";
                }
                cout<<"\n";

        for(fp2=0;fp2<9;fp2++)
        {
            if(mass[fp2+1]<mass[fp2])
                {
            tp=mass[fp2];
            mass[fp2]=mass[fp2+1];
            mass[fp2+1]=tp;
            }
        }
    }

    return 0;
}
