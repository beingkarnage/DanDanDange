#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
//both the versions of grid designed by me both are optimized but i prefer this code because it is less error and crashing probability
using namespace std;

void up();
void down();
void left();
void right();
void gridupdate(int x,int y);
void sgrid();

int i,j,r,c,f1,f2,e1,e2,score,health,esco;//here i and j is grid coordinates. r and c is the character coordinates. f1 and f2 is fruit and e1 and e2 is enemy coordinates
bool fruit=false;
bool enemy=false;
char grid[25][50];
int main()
{
    srand(time(0));
    score=0;
    esco=-5;
    health=3;
    gridupdate(0,0);
    return 0;
}

void gridupdate(int x,int y){
    char cho;
    system("cls");
    r=x,c=y;
    if(e1==f1&&e2==f2){
            fruit=false;
            esco=esco+5;
            }else{
                if(e1>f1){
            e1--;
            }
        if(e1<f1){
            e1++;
            }
        if(e2>f2){
            e2--;
            }
        if(e2<f2){
            e2++;
            }}
    if(esco==150){
        cout<<"Game Over Enemy Won !!!";
        system("pause");
        exit(0);
    }else if(score==50){
        cout<<"You Won !!!";
        system("pause");
        exit(0);
    }
    if(fruit==false){
        f1=rand()%25;
        f2=rand()%50;
        fruit=true;
    }else if(f1==r&&f2==c){
    score=score+5;
    fruit=false;
    }
    if(enemy==false){
        e1=rand()%25;
        e2=rand()%50;
        enemy=true;
    }else if(e1==r&&e2==c){
    health--;
    if(health<=0){
        system("cls");
        cout<<"\n\n\n\t\t-----------------"<<endl;
        cout<<"\t\t||Game Over !!!||"<<endl;
        cout<<"\t\t-----------------"<<endl;
        cout<<"\t\t     Score : "<<score<<endl;
        exit(0);
                    }
                }

        for(i=0;i<25;i++){
        for(j=0;j<50;j++){
            grid[i][j]=177;
        }
    }
    grid[r][c]=219;
    grid[f1][f2]=48;
    grid[e1][e2]='*';
    cout<<"Players Score : "<<score<<"\t"<<"Health : "<<health<<endl;
    cout<<"Enemy Score   : "<<esco<<endl;
    for(i=0;i<25;i++){
        for(j=0;j<50;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    cin>>cho;
    switch(cho){
case 'w':
    --r;
    up();
    break;
case 's':
    ++r;
    down();
    break;
case 'a':
--c;
    left();
    break;
case 'd':
++c;
    right();
    break;
default:
    gridupdate(r,c);
    break;
    }}

void up(){
if(r<0||r>25||c<0||c>50){
    ++r;//to prevent the character to move out of the grid and crashing the program.
    gridupdate(r,c);
}else{
gridupdate(r,c);}
}

void down(){
if(r<=0||r>=25||c<0||c>50){
    --r;//to prevent the character to move out of the grid and crashing the program.
gridupdate(r,c);
}else{
gridupdate(r,c);}
}

void left(){
if(r<0||r>25||c<=0||c>=50){
    ++c;//to prevent the character to move out of the grid and crashing the program.
gridupdate(r,c);
}else{
gridupdate(r,c);}
}

void right(){
if(r<0||r>25||c<=0||c>=50){
    --c;//to prevent the character to move out of the grid and crashing the program.
gridupdate(r,c);

}else{
    gridupdate(r,c);}
}
/*

*/
