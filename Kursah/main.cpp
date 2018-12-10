#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <fstream>
#include <math.h>
using namespace std;

int s[3];

///������� ����� ������� � ����������
float* entermat(float *mass,int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        cin>>*(mass+i);
    }
    return mass;
}
///������� ����� ������� �� �����
float* readMatrix(string path, int f) {
    ifstream file;
    file.open(path);
    int dim = 0;
    while (file.peek() != '\n') {
        float ignore;
        file >> ignore;
        dim++;
    }
    s[f]=dim;
    file.clear();
    file.seekg(0, std::ios::beg);
    float* matrix = new float[dim*dim];

    for(int i = 0; i < dim*dim; i++) {
        float element;
        file >> element;
        *(matrix + i) = element;
    }
    return matrix;
}

///������� ��� ������ ������� �� �����
void uniglaz(float *mass, int s)
{
    int h;
    for(h=0;h<(s*s);h++)
    {
        cout<<*(mass+h)<<" ";
        if((h+1)%s==0)
            cout<<"\n";
    }
}
///������� ��� ������ ������� � ����
void fileout(float *mass, int s)
{
    int h;
    ofstream fout;
    fout.open("result.txt");
    for(h=0;h<(s*s);h++)
    {
        fout<<*(mass+h)<<" ";
        if((h+1)%s==0)
            fout<<"\n";
    }
    fout.close();
}
///������� ��� ������������ ������
float uniproz2(float *ma1, float *ma2, int s1, int i, int j)
{
     float summ=0;
     int x, y;
        for(x=0,y=0;x<s1;x++,y=y+s1)
        {
            summ+=*(ma1+i+x)*(*(ma2+j+y));
        }
           return summ;
}
///������� ���������� �����������
float* masmax(float *mass, int s)
{
    int i, j;
    float *bmas;
    bmas = new float[s*s];
    for(i=0;i<s*s;i++)
    *(bmas+i)=*(mass+i);
    delete mass;
    mass= new float[(s+1)*(s+1)];
    for(i=0,j=0;i<((s+1)*(s+1));i++,j++)
    {
        if(i<(s*s)+s-1)
        {
            if((i+1)%(s+1)==0)
            {
                *(mass+i)=0;
                i++;
            }
                *(mass+i)=*(bmas+j);
        }
        else
            *(mass+i)=0;
    }
    return mass;
}
///������� ���������� �����������
float *masmin(float *mass, int s)
{
    int i,j;
    float *bmas;
    bmas = new float[s*s];
    for(i=0;i<s*s;i++)
    *(bmas+i)=*(mass+i);
    delete mass;
    mass= new float[(s-1)*(s-1)];
    for(i=0,j=0;i<((s-1)*(s-1));i++,j++)
    {
        if((j+1)%s==0) j++;
        *(mass+i)=*(bmas+j);
    }
    return mass;
}
///������� ��� ������� ��������������� �������
float maxfun(float* p1, float* p2, int p,int se)
{///������������ �������
    int i,j;
    float q1=0,q2=0;
        for(i=0;i<se*se;i=i+se)
        {
            q1+=*(p1+i+p);
            q2+=*(p2+i+p);
        }
    if(q1>q2) return q1;
    if(q2>q1) return q2;
    else return 1;

}

float first(float* p1, float* p2, int i, int p,int se)
{
    return (*(p1+i)+*(p2+i))/maxfun(p1,p2,p,se);
}
///������� ��� ������� ��������������� �������
float* second(float* p1, float* p2, int s)
{
    float medium[s], su=0;
    int i, j ,k, p=0;
    for(i=0;i<s;i++)
    {
        su=0;
        for(j=0;j<s*s;j=j+s)
        {
            su+=*(p2+j+p);
        }
        medium[i]=su/s;
        p++;
    }

    float *rmas= new float [s*s];
    for(i=0;i<s*s;i++)
    {
        *(rmas+i)=0;
    }
    for(i=0,j=0,k=0;i<s*s;i++,k++)
    {
       if((i+1)%s==0) k=0;
       if(*(p1+i)>medium[k])
       {
           *(rmas+j)=*(p1+i);
           j++;
       }

    }
    return rmas;
}

int main()
{
    setlocale(0, "Russian");
    int a,b,c,d,e,f,k,l,l1,i=0, pa, z, j=0, indz, checkA=0, checkB=0,checkC=0; //s[3];
    int fc=0, temp;
    char zip[15];
    float *p1, *p2, *p3;
    while(c!=0){
     cout<<"\t����\n";
     cout<<"1 - ������ �������\n";
     cout<<"2 - ������� �������\n";
     cout<<"3 - ������������\n";
     cout<<"4 - �������� ������ �������\n";
     cout<<"5 - �������������� �������\n";
     cout<<"0 - �����\n";
     cin>>c;
    switch(c){
    case 0: break;///����� �� ���������
    case 1:///���� ������
   cout<<"1 - ������� ������� c ����������\n";
    cout<<"2 - ������� ������� � �����\n";
     cout<<"3 - ������\n";
    cin>>k;
    if(k==1){///���� ������� � ����������
      cout<<"�������� ������ ��� ������:\n";
       cout<<"1 - ������� � -";
       if(checkA==0)
            cout<<" �� ������\n";
        else cout<<" ��������\n";

        cout<<"2 - ������� B -";
        if(checkB==0)
            cout<<" �� ������\n";
        else cout<<" ��������\n";
        cout<<"4 - ������\n";
       cin>>a;
        switch(a){
            case 1:///������ ������� �
            if(checkA!=0)    delete p1;
                cout<<"������� ������ �������:\n";
                cin>>s[0];
                if(s[0]<=0){
                    cout<<"������, ������� ����������� �����!\n";
                    break;
                }
                p1= new float[s[0]*s[0]];
                p1=entermat(p1,s[0]*s[0]);
                checkA=1;
                cout<<"������� A ��������!\n";
            break;
        case 2:///������ ������� �
         if(checkB!=0)   delete p2;
                cout<<"������� ������ �������:\n";
                cin>>s[1];
                if(s[1]<=0){
                    cout<<"������, ������� ����������� �����!\n";
                    break;
                }
                p2= new float[s[1]*s[1]];
                p2=entermat(p2,s[1]*s[1]);
                checkB=1;
                cout<<"������� B ��������!\n";
            break;
        case 4: break;
        }
            }
        if(k==2){///���� ������� � �����
        cout<<"�������� ������ ��� ������:\n";
            cout<<"1 - ������� � -";
                if(checkA==0)
                    cout<<" �� ������\n";
            else cout<<" ��������\n";

        cout<<"2 - ������� B -";
            if(checkB==0)
                cout<<" �� ������\n";
            else cout<<" ��������\n";
        cout<<"3 - ������\n";
       cin>>z;
       if(z==1){///���� � ����� � ������� �
            cout<<"������� �������� �����\n";
        cin>>zip;
       p1= readMatrix(zip/*"enter.txt"*/, 0);
       checkA=1;
       cout<<"������� ��������!\n";
       break;
       }
       if(z==2){///���� � ����� � ������� �
            cout<<"������� �������� �����\n";
        cin>>zip;
       p2= readMatrix(zip/*"enter.txt"*/, 1);
       checkB=1;
       cout<<"������� ��������!\n";
       break;
       }
       if(z==3) break;
        }
   break;

  case 2:///����� ������
        if(checkA==0 && checkB==0 && checkC==0){
            cout<<"������:��� �� ����� �������� �������!\n";
            break;
        }
        cout<<"������� �������:\n";
     cout<<"1 - ������ ������� �� �����\n";
     cout<<"2 - ������� ������\n";
     cout<<"3 - ������\n";
    cin>>f;
    if(f==1){///����� �� �����

        cout<<"�������� ������� ��� ������ �� �����:\n";
        if(checkA!=0)
            cout<<"1 - ������� A\n";
        if(checkB!=0)
            cout<<"2 - ������� B\n";
        if(checkC!=0)
            cout<<"3 - ������� C\n";
        cout<<"4 - ������\n";

        cin>>b;
        switch(b){
        case 1:///����� ������� �
            uniglaz(p1,s[0]);
            break;
        case 2:///����� ������� �
            uniglaz(p2,s[1]);
            break;
        case 3:///����� ������� �
            uniglaz(p3,s[2]);
            break;
        case 4: break;
        }
    }
    if(f==2){///����� � ���� RESULT
    cout<<"�������� ������� ��� ������ � ����:\n";
        if(checkA!=0)
            cout<<"1 - ������� A\n";
        if(checkB!=0)
            cout<<"2 - ������� B\n";
        if(checkC!=0)
            cout<<"3 - ������� C\n";
        cout<<"4 - ������\n";
        cin>>b;
        switch(b){
        case 1:///����� ������� �
            fileout(p1,s[0]);
            break;
        case 2:///����� ������� �
           fileout(p2,s[1]);
            break;
        case 3:///����� ������� �
           fileout(p3,s[2]);
            break;
        case 4: break;
        }
    }/*
    if(f==3) break;*/
            break;

    case 3:///������������
            if(checkA==1 || checkB==1 || checkC==1)
            {
                cout<<"�������� ������� 1\n";
                if(checkA==1)
                    cout<<"1 - ������� �\n";
                if(checkB==1)
                    cout<<"2 - ������� B\n";
                cin>>d;
                cout<<"�������� ������� 2\n";
                if(checkA==1)
                    cout<<"1 - ������� �\n";
                if(checkB==1)
                    cout<<"2 - ������� B\n";
                cin>>e;
            switch(d)
            {
            case 1:
                ///������� �*�
                if(e==1){
                      if(checkC!=0)  delete p3;
                        p3= new float[s[0]*s[0]];
                        checkC=1;
                        s[2]=s[0];
                    for(i=0;i<s[0]*s[0];i=i+s[0])
                    {
                        for(j=0;j<s[0];j++)
                        {
                          *(p3+i+j)=uniproz2(p1,p1,s[0], i, j);
                        }
                    }
                    break;
                }
                ///������� A*B
              if(e==2 && s[0]==s[1]){
                  if(checkC!=0)  delete p3;
                        p3= new float[s[0]*s[0]];
                        checkC=1;
                        s[2]=s[0];
                    for(i=0;i<s[0]*s[0];i=i+s[0])
                    {
                        for(j=0;j<s[0];j++)
                        {
                          *(p3+i+j)=uniproz2(p1,p2,s[0], i, j);
                        }
                    }
                    break;

                }
                else cout<<"������: ������� ������ �� ���������!\n";
                break;

            case 2: ///������� B*A
               if(e==1 && s[0]==s[1]){
                   if(checkC!=0) delete p3;
                        p3= new float[s[1]*s[1]];
                        checkC=1;
                        s[2]=s[1];
                    for(i=0;i<s[1]*s[1];i=i+s[1])
                    {
                        for(j=0;j<s[1];j++)
                        {
                          *(p3+i+j)=uniproz2(p2,p1,s[1], i, j);
                        }
                    }
                    break;
                }
                ///������� B*B
               if(e==2){
                   if(checkC!=0) delete p3;
                        p3= new float[s[1]*s[1]];
                        checkC=1;
                        s[2]=s[1];
                    for(i=0;i<s[1]*s[1];i=i+s[1])
                    {
                        for(j=0;j<s[1];j++)
                        {
                          *(p3+i+j)=uniproz2(p2,p2,s[1], i, j);
                        }cout<<"������� ��������!\n";
                    }
                    break;
                }
                else cout<<"������: ������� ������ �� ���������!\n";
                break;
            }
    }
            else cout<<"������: ���������� �������!\n";//*/
           break;
    case 4:///��������� �����������
               if(checkA==0 && checkB==0 && checkC==0){
            cout<<"������:��� �� ����� �������� �������!\n";
            break;
                }
                cout<<"1 - ��������� ����������� �� 1\n";
                cout<<"2 - ��������� ����������� �� 1\n";
            cout<<"3 - ������\n";
            cin>>l;
            switch(l)
            {
            case 1:///���������� �� 1
                cout<<"�������� �������\n";
                if(checkA!=0) cout<<"1 - ������� �\n";
                if(checkB!=0) cout<<"2 - ������� B\n";
                cin>>l1;
                if(l1==1)
                {
                    p1=masmax(p1,s[0]);
                    s[0]++;
                    cout<<"������!\n";
                }
                if(l1==2)
                {
                    p2=masmax(p2,s[1]);
                    s[1]++;
                    cout<<"������!\n";
                }
                break;
            case 2:///���������� �� 1
                cout<<"�������� �������\n";
                if(checkA!=0) cout<<"1 - ������� �\n";
                if(checkB!=0) cout<<"2 - ������� B\n";
                cin>>l1;
                if(l1==1)
                {
                    p1=masmin(p1,s[0]);
                    s[0]--;
                    cout<<"������!\n";
                }
                if(l1==2)
                {
                    p2=masmin(p2,s[1]);
                    s[1]--;
                    cout<<"������!\n";
                }
                break;
            case 3:
                break;
            }

                break;
   case 5:///�������������� �������
                cout<<"�������� �������:\n1 - ������ �������\n2 - ������ �������\n3 - ������\n";
                cin>>indz;
                switch(indz){
            case 1:///������ ��������������
                if(checkA==0 || checkB==0)
                {
                    cout<<"������: �� ������� ������ ��� ���������� �������!\n";
                    break;
                }
                if(checkC!=0) delete p3;
                p3=new float[s[0]*s[0]];
                for(i=0;i<s[0]*s[0];i++)
                    {
                        if(i%s[0]==0) pa=0;
                    *(p3+i)=first(p1,p2,i,pa,s[0]);
                    pa++;
                    }
                    checkC=1;
                    s[2]=s[0];
                break;
            case 2:///������ ��������������
                if(checkA==0 && checkB==0)
                {
                    cout<<"������: �� ������� ������ ��� ���������� �������!\n";
                    break;
                }
                if(checkC!=0) delete p3;
                p3=second(p1,p2,s[0]);
                checkC=1;
                s[2]=s[0];
                cout<<"�������������� ������� #2 ���������!\n";
                break;
            case 3:
                break;
                }

                break;
   default:
        cout<<"������: ����������� �������\n";
        break;//*/
        }
    }
    if(checkA!=0) delete p1;
    if(checkB!=0) delete p2;
    if(checkC!=0) delete p3;
    return 0;
}
