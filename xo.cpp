#include <iostream>

using namespace std;

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player ='X';
void play(){
    char pos;
    cout<<"chose your position - ("<<player<<") : ";
    do{cin>>pos;}while (pos!='1'&&pos!='2'&&pos!='3'&&pos!='4'&&pos!='5'&&pos!='6'&&pos!='7'&&pos!='8'&&pos!='9');
    
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(matrix[i][j]==pos){
                matrix[i][j]=player; 
            }
        }
    }   
     if(player=='X'){
        player='O';
     }else player='X';

    
}
void PrintMatrix()
{
    system("cls");

    for (int i = 0; i < 3; i++)
    {
        cout << endl<<"--------------------"<<endl;
        cout<<"| ";
        for (int j = 0; j < 3; j++)
        {
            cout <<" "<<matrix[i][j] << "  "<<"|  ";
        }
    }   cout << endl<<"--------------------"<<endl;
}
char chickWin(){
    int xc=0,oc=0,counter;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(matrix[i][j]!='X'&&matrix[i][j]!='O') counter++;
             if(matrix[i][j]=='X') xc++;
             else if(matrix[i][j]=='O') oc++;
             if(xc==3||oc==3) return xc>oc?'X':'O';
        }
        xc=0;
        oc=0;
    }for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
             if(matrix[j][i]=='X') xc++;
             else if(matrix[j][i]=='O') oc++;
             if(xc==3||oc==3) return xc>oc?'X':'O';
        }
        xc=0;
        oc=0;
    }
    if (matrix[0][0]=='X'&&matrix[1][1]=='X'&&matrix[2][2]=='X')return 'X';
    else if (matrix[0][0]=='O'&&matrix[1][1]=='O'&&matrix[2][2]=='O')return 'O';
    else if (matrix[0][2]=='X'&&matrix[1][1]=='X'&&matrix[2][0]=='X')return 'X'; 
    else if (matrix[0][2]=='O'&&matrix[1][1]=='O'&&matrix[2][0]=='O')return 'O';


    if  (counter ==0) return 'Z';

    return '.';
}
int main()
{

while (chickWin()=='.'){
    PrintMatrix();
    play();
}
PrintMatrix();
if(chickWin()=='Z'){
    cout<<" DRAW ! ";
}else {
    cout<<"the winner is player ("<<chickWin()<<") , congratsulation !!"<<endl;
}


    system("pause");
}