#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c, d;
    int ch0=0, ch2=0, ch3=0, ch4=0, ch5=0;

        int mx, mn;
        int sum=0;

    int di1,di2;
    cout<<"Vvedite nachalo diapozona:";
    cin>>di1;
    cout<<"Vvedite konec diapozona:";
    cin>>di2;

    while(ch5!=1){
        cin>>a;
        ch0++;
    if(a==0) break;
//number 4
        if(ch0>=di1 && ch0<=di2)
        {
            if(a%5==0) ch4++;
        }
//
        if(ch0==1)
        {
         mx=a;
         mn=a;
        }

//number 1
        if(mx<a) mx=a;
        if(mn>a) mn=a;
        cout<<"[1] suma diapozona = "<<mx-mn<<"\n";
//number 2
        if(a>0){
        sum=sum+a;
        ch2++;
        }
        cout<<"[2] srednyee arif.chislo = "<<(sum/ch2)<<"\n";
//number 3

        if(ch0>=3)
        {
            d=b+c;
            if(d==a) ch3++;
        cout<<"[3] chisel, ravnix proshlim dvum = "<<ch3<<"\n";
        }
        c=b;
        b=a;
//number 4
        cout<<"[4] chisel, kratnix 5 ="<<ch4<<"\n";
    }
    return 0;
}
