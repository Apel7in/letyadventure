#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int a=0, b=0, c=0, d=0, e=0, f=0;

    int ch0=0, ch1=0;
    int sum=0, sum1=0;
    int srzn=0, fsum=0;
    while(1)
    {
        f=e;
        e=d;
        d=c;
        c=b;
        b=a;
        cin>>a;
        //if(ch0==0) b=a;
        if(a==0) break;
        ch0++;
        //number 3
          sum=sum+a;
          if(!(ch0%5))
          {
             srzn=sum/5;
             sum=0;
             cout<<"[3] sred znach 5 vvedennix = "<<srzn<<"\n";
          }
          //number 2
            int i=3;
          while(1){
                if(i>a) break;
          if(i==a){
                printf("[2] Chislo %d - stepyen troiki\n",a);
            break;
            }
            i*=3;
          }
        //number 1
        if(ch0>5) sum1=sum1-f;
        sum1=sum1+a;
        if(fsum<sum1)
            {
                fsum=sum1;
            }


       // printf("%d = %d + %d + %d + %d + %d\n",sum1,a,b,c,d,e);
    }

    cout<<"[1] Summa max 5-ti podryad ="<<fsum<<"\n";
    return 0;
}
