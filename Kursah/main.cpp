#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <fstream>
#include <math.h>
using namespace std;

int s[3];

///ФУНКЦИЯ ВВОДА МАТРИЦЫ С КЛАВИАТУРЫ
float* entermat(float *mass,int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        cin>>*(mass+i);
    }
    return mass;
}
///ФУНКЦИЯ ВВОДА МАТРИЦЫ ИЗ ФАЙЛА
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

///ФУНКЦИЯ ДЛЯ ВЫВОДА МАТРИЦЫ НА ЭКРАН
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
///ФУНКЦИЯ ДЛЯ ВЫВОДА МАТРИЦЫ В ФАЙЛ
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
///ФУНКЦИЯ ДЛЯ ПЕРЕМНОЖЕНИЯ МАТРИЦ
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
///ФУНКЦИЯ УВЕЛИЧЕНИЯ РАЗМЕРНОСТИ
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
///ФУНКЦИЯ УМЕНЬШЕНИЯ РАЗМЕРНОСТИ
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
///ФУНКЦИИ ДЛЯ ПЕРВОГО ИНДИВИДУАЛЬНОГО ЗАДАНИЯ
float maxfun(float* p1, float* p2, int p,int se)
{///МАКСИМАЛЬНЫЙ СТОЛБЕЦ
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
///ФУНКЦИЯ ДЛЯ ВТОРОГО ИНДИВИДУАЛЬНОГО ЗАДАНИЯ
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
     cout<<"\tМЕНЮ\n";
     cout<<"1 - Ввести матрицу\n";
     cout<<"2 - Вывести матрицу\n";
     cout<<"3 - Перемножение\n";
     cout<<"4 - Изменить размер матрицы\n";
     cout<<"5 - Индивидуальное задание\n";
     cout<<"0 - Выход\n";
     cin>>c;
    switch(c){
    case 0: break;///ВЫХОД ИЗ ПРОГРАММЫ
    case 1:///ВВОД МАТРИЦ
   cout<<"1 - Считать матрицу c клавиатуры\n";
    cout<<"2 - Считать матрицу с файла\n";
     cout<<"3 - Отмена\n";
    cin>>k;
    if(k==1){///ВВОД МАТРИЦЫ С КЛАВИАТУРЫ
      cout<<"Выберите ячейку для записи:\n";
       cout<<"1 - Матрица А -";
       if(checkA==0)
            cout<<" не задана\n";
        else cout<<" записана\n";

        cout<<"2 - Матрица B -";
        if(checkB==0)
            cout<<" не задана\n";
        else cout<<" записана\n";
        cout<<"4 - Отмена\n";
       cin>>a;
        switch(a){
            case 1:///ВВЕСТИ МАТРИЦУ А
            if(checkA!=0)    delete p1;
                cout<<"Введите размер матрицы:\n";
                cin>>s[0];
                if(s[0]<=0){
                    cout<<"Ошибка, введите натуральное число!\n";
                    break;
                }
                p1= new float[s[0]*s[0]];
                p1=entermat(p1,s[0]*s[0]);
                checkA=1;
                cout<<"Матрица A записана!\n";
            break;
        case 2:///ВВЕСТИ МАТРИЦУ В
         if(checkB!=0)   delete p2;
                cout<<"Введите размер матрицы:\n";
                cin>>s[1];
                if(s[1]<=0){
                    cout<<"Ошибка, введите натуральное число!\n";
                    break;
                }
                p2= new float[s[1]*s[1]];
                p2=entermat(p2,s[1]*s[1]);
                checkB=1;
                cout<<"Матрица B записана!\n";
            break;
        case 4: break;
        }
            }
        if(k==2){///ВВОД МАТРИЦЫ С ФАЙЛА
        cout<<"Выберите ячейку для записи:\n";
            cout<<"1 - Матрица А -";
                if(checkA==0)
                    cout<<" не задана\n";
            else cout<<" записана\n";

        cout<<"2 - Матрица B -";
            if(checkB==0)
                cout<<" не задана\n";
            else cout<<" записана\n";
        cout<<"3 - Отмена\n";
       cin>>z;
       if(z==1){///ВВОД С ФАЙЛА В МАТРИЦУ А
            cout<<"Введите название файла\n";
        cin>>zip;
       p1= readMatrix(zip/*"enter.txt"*/, 0);
       checkA=1;
       cout<<"Матрица записана!\n";
       break;
       }
       if(z==2){///ВВОД С ФАЙЛА В МАТРИЦУ В
            cout<<"Введите название файла\n";
        cin>>zip;
       p2= readMatrix(zip/*"enter.txt"*/, 1);
       checkB=1;
       cout<<"Матрица записана!\n";
       break;
       }
       if(z==3) break;
        }
   break;

  case 2:///ВЫВОД МАТРИЦ
        if(checkA==0 && checkB==0 && checkC==0){
            cout<<"Ошибка:Нет ни одной заданной матрицы!\n";
            break;
        }
        cout<<"Вывести матрицу:\n";
     cout<<"1 - Ввести матрицу на экран\n";
     cout<<"2 - Вывести файлом\n";
     cout<<"3 - Отмена\n";
    cin>>f;
    if(f==1){///ВЫВОД НА ЭКРАН

        cout<<"Выберите матрицу для вывода на экран:\n";
        if(checkA!=0)
            cout<<"1 - Матрица A\n";
        if(checkB!=0)
            cout<<"2 - Матрица B\n";
        if(checkC!=0)
            cout<<"3 - Матрица C\n";
        cout<<"4 - Отмена\n";

        cin>>b;
        switch(b){
        case 1:///ВЫВОД МАТРИЦЫ А
            uniglaz(p1,s[0]);
            break;
        case 2:///ВЫВОД МАТРИЦЫ В
            uniglaz(p2,s[1]);
            break;
        case 3:///ВЫВОД МАТРИЦЫ С
            uniglaz(p3,s[2]);
            break;
        case 4: break;
        }
    }
    if(f==2){///ВЫВОД В ФАЙЛ RESULT
    cout<<"Выберите матрицу для вывода в файл:\n";
        if(checkA!=0)
            cout<<"1 - Матрица A\n";
        if(checkB!=0)
            cout<<"2 - Матрица B\n";
        if(checkC!=0)
            cout<<"3 - Матрица C\n";
        cout<<"4 - Отмена\n";
        cin>>b;
        switch(b){
        case 1:///ВЫВОД МАТРИЦЫ А
            fileout(p1,s[0]);
            break;
        case 2:///ВЫВОД МАТРИЦЫ В
           fileout(p2,s[1]);
            break;
        case 3:///ВЫВОД МАТРИЦЫ С
           fileout(p3,s[2]);
            break;
        case 4: break;
        }
    }/*
    if(f==3) break;*/
            break;

    case 3:///ПЕРЕМНОЖЕНИЕ
            if(checkA==1 || checkB==1 || checkC==1)
            {
                cout<<"Выберите матрицу 1\n";
                if(checkA==1)
                    cout<<"1 - Матрица А\n";
                if(checkB==1)
                    cout<<"2 - Матрица B\n";
                cin>>d;
                cout<<"Выберите матрицу 2\n";
                if(checkA==1)
                    cout<<"1 - Матрица А\n";
                if(checkB==1)
                    cout<<"2 - Матрица B\n";
                cin>>e;
            switch(d)
            {
            case 1:
                ///МАТРИЦА А*А
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
                ///МАТРИЦА A*B
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
                else cout<<"Ошибка: Размеры матриц не совпадают!\n";
                break;

            case 2: ///МАТРИЦА B*A
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
                ///МАТРИЦА B*B
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
                        }cout<<"Матрица записана!\n";
                    }
                    break;
                }
                else cout<<"Ошибка: Размеры матриц не совпадают!\n";
                break;
            }
    }
            else cout<<"Ошибка: Отсуствуют матрицы!\n";//*/
           break;
    case 4:///ИЗМЕНЕНИЕ РАЗМЕРНОСТИ
               if(checkA==0 && checkB==0 && checkC==0){
            cout<<"Ошибка:Нет ни одной заданной матрицы!\n";
            break;
                }
                cout<<"1 - Увеличить размерность на 1\n";
                cout<<"2 - Уменьшить размерность на 1\n";
            cout<<"3 - Отмена\n";
            cin>>l;
            switch(l)
            {
            case 1:///УВЕЛИЧЕНИЕ НА 1
                cout<<"Выберите матрицу\n";
                if(checkA!=0) cout<<"1 - Матрица А\n";
                if(checkB!=0) cout<<"2 - Матрица B\n";
                cin>>l1;
                if(l1==1)
                {
                    p1=masmax(p1,s[0]);
                    s[0]++;
                    cout<<"Готово!\n";
                }
                if(l1==2)
                {
                    p2=masmax(p2,s[1]);
                    s[1]++;
                    cout<<"Готово!\n";
                }
                break;
            case 2:///УМЕНЬШЕНИЕ НА 1
                cout<<"Выберите матрицу\n";
                if(checkA!=0) cout<<"1 - Матрица А\n";
                if(checkB!=0) cout<<"2 - Матрица B\n";
                cin>>l1;
                if(l1==1)
                {
                    p1=masmin(p1,s[0]);
                    s[0]--;
                    cout<<"Готово!\n";
                }
                if(l1==2)
                {
                    p2=masmin(p2,s[1]);
                    s[1]--;
                    cout<<"Готово!\n";
                }
                break;
            case 3:
                break;
            }

                break;
   case 5:///ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ
                cout<<"Выберите задание:\n1 - Первое задание\n2 - Второе задание\n3 - Отмена\n";
                cin>>indz;
                switch(indz){
            case 1:///ПЕРВОЕ ИНДИВИДУАЛЬНОЕ
                if(checkA==0 || checkB==0)
                {
                    cout<<"Ошибка: Не хватает матриц для выполнения задания!\n";
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
            case 2:///ВТОРОЕ ИНДИВИДУАЛЬНОЕ
                if(checkA==0 && checkB==0)
                {
                    cout<<"Ошибка: Не хватает матриц для выполнения задания!\n";
                    break;
                }
                if(checkC!=0) delete p3;
                p3=second(p1,p2,s[0]);
                checkC=1;
                s[2]=s[0];
                cout<<"Индивидуальное задание #2 выполнено!\n";
                break;
            case 3:
                break;
                }

                break;
   default:
        cout<<"Ошибка: Неизвестная команда\n";
        break;//*/
        }
    }
    if(checkA!=0) delete p1;
    if(checkB!=0) delete p2;
    if(checkC!=0) delete p3;
    return 0;
}
