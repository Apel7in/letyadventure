#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int matA[3][3];
    int matB[3][3];
    int matC[3][3];
    int matD[3][3];
    int a=1,c,b, pointA=0,pointB=0;
    while(c!=0){
            cout<<"********MENU************\n"<<"Vyberyte deustvie:\n";
            cout<<"[1] - Vvod matrici A\n";
            cout<<"[2] - Vvod matrici B\n";
            if(pointB>0 && pointA>0){
            cout<<"[3] - SUMMA (A+B)\n";
            cout<<"[4] - PROIZ (A*B)\n";
            }
            if(pointA>0)
            cout<<"[5] - STEPE  A^n\n";
            cout<<"[0] - Vyxod\n";
            cout<<"************************\n";
    cin>>c;
   switch(c){

   case 0: break;
   case 1:
   cout<<"Vvvedite matricu A:\n";
   cin>>matA[0][0]>>matA[0][1]>>matA[0][2];
   cin>>matA[1][0]>>matA[1][1]>>matA[1][2];
   cin>>matA[2][0]>>matA[2][1]>>matA[2][2];
   pointA++;
   break;

   case 2:
    cout<<"Vvvedite matricu B:\n";
   cin>>matB[0][0]>>matB[0][1]>>matB[0][2];
   cin>>matB[1][0]>>matB[1][1]>>matB[1][2];
   cin>>matB[2][0]>>matB[2][1]>>matB[2][2];
   pointB++;
   break;
//matA+matB
   case 3:
    if(pointA==0&&pointB==0){
    cout<<"ERROR:Vvedite matrici!\n";
    break;
    }
    cout<<matA[0][0]+matB[0][0]<<" "<<matA[0][1]+matB[0][1]<<" "<<matA[0][2]+matB[0][2]<<"\n";
    cout<<matA[1][0]+matB[1][0]<<" "<<matA[1][1]+matB[1][1]<<" "<<matA[1][2]+matB[1][2]<<"\n";
    cout<<matA[2][0]+matB[2][0]<<" "<<matA[2][1]+matB[2][1]<<" "<<matA[2][2]+matB[2][2]<<"\n";
    break;
//matA*matB
   case 4:
    if(pointA==0&&pointB==0){
    cout<<"ERROR:Vvedite matrici!\n";
    break;
    }
    cout<<matA[0][0]*matB[0][0]+matA[0][1]*matB[1][0]+matA[0][2]*matB[2][0]<<" ";
    cout<<matA[0][0]*matB[0][1]+matA[0][1]*matB[1][1]+matA[0][2]*matB[2][1]<<" ";
    cout<<matA[0][0]*matB[0][2]+matA[0][1]*matB[1][2]+matA[0][2]*matB[2][2]<<"\n";

    cout<<matA[1][0]*matB[0][0]+matA[1][1]*matB[1][0]+matA[1][2]*matB[2][0]<<" ";
    cout<<matA[1][0]*matB[0][1]+matA[1][1]*matB[1][1]+matA[1][2]*matB[2][1]<<" ";
    cout<<matA[1][0]*matB[0][2]+matA[1][1]*matB[1][2]+matA[1][2]*matB[2][2]<<"\n";

    cout<<matA[2][0]*matB[0][0]+matA[2][1]*matB[1][0]+matA[2][2]*matB[2][0]<<" ";
    cout<<matA[2][0]*matB[0][1]+matA[2][1]*matB[1][1]+matA[2][2]*matB[2][1]<<" ";
    cout<<matA[2][0]*matB[0][2]+matA[2][1]*matB[1][2]+matA[2][2]*matB[2][2]<<"\n";
    break;
//stepen matA
   case 5:
    if(pointA==0&&pointB==0){
    cout<<"ERROR:Vvedite matrici!\n";
    break;
    }
    matC[0][0]=matA[0][0];
    matC[0][1]=matA[0][1];
    matC[0][2]=matA[0][2];
    matC[1][0]=matA[1][0];
    matC[1][1]=matA[1][1];
    matC[1][2]=matA[1][2];
    matC[2][0]=matA[2][0];
    matC[2][1]=matA[2][1];
    matC[2][2]=matA[2][2];
    //matC[3][3]=matA[3][3];
    cout<<"Vvedite stepen:\n";
    cin>>b;
    while(a<b)
    {
    matD[0][0]=matC[0][0]*matA[0][0]+matC[0][1]*matA[1][0]+matC[0][2]*matA[2][0];
    matD[0][1]=matC[0][0]*matA[0][1]+matC[0][1]*matA[1][1]+matC[0][2]*matA[2][1];
    matD[0][2]=matC[0][0]*matA[0][2]+matC[0][1]*matA[1][2]+matC[0][2]*matA[2][2];

    matD[1][0]=matC[1][0]*matA[0][0]+matC[1][1]*matA[1][0]+matC[1][2]*matA[2][0];
    matD[1][1]=matC[1][0]*matA[0][1]+matC[1][1]*matA[1][1]+matC[1][2]*matA[2][1];
    matD[1][2]=matC[1][0]*matA[0][2]+matC[1][1]*matA[1][2]+matC[1][2]*matA[2][2];

    matD[2][0]=matC[2][0]*matA[0][0]+matC[2][1]*matA[1][0]+matC[2][2]*matA[2][0];
    matD[2][1]=matC[2][0]*matA[0][1]+matC[2][1]*matA[1][1]+matC[2][2]*matA[2][1];
    matD[2][2]=matC[2][0]*matA[0][2]+matC[2][1]*matA[1][2]+matC[2][2]*matA[2][2];

    matC[0][0]=matD[0][0];
    matC[0][1]=matD[0][1];
    matC[0][2]=matD[0][2];
    matC[1][0]=matD[1][0];
    matC[1][1]=matD[1][1];
    matC[1][2]=matD[1][2];
    matC[2][0]=matD[2][0];
    matC[2][1]=matD[2][1];
    matC[2][2]=matD[2][2];
    a++;
    }
    a=1;
    cout<<matC[0][0]<<" "<<matC[0][1]<<" "<<matC[0][2]<<"\n";
    cout<<matC[1][0]<<" "<<matC[1][1]<<" "<<matC[1][2]<<"\n";
    cout<<matC[2][0]<<" "<<matC[2][1]<<" "<<matC[2][2]<<"\n";
    break;
   default:cout<<"ERROR 404"<<"\n";
   }
    }
    return 0;
}
