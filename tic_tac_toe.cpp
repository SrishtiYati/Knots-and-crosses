#include<iostream>
using namespace std;

char blank[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x';
string n1 = " ";
string n2=" ";
bool tie= false;
void FunctionOne(){
    cout<<"   |      | "<<endl;
     cout<< " "<<blank[0][0]<<" | "<<"  "<<blank[0][1]<<"  | "<<blank[0][2]<<" \n";
     cout<<"___|______|____"<<endl;
     cout<<"   |      | "<<endl;
     cout<< " "<<blank[1][0]<<" | "<<"  "<<blank[1][1]<<"  | "<<blank[1][2]<<" \n";
     cout<<"   |      | "<<endl;
     cout<<"___|______|____"<<endl;
     cout<<"   |      | "<<endl;
     cout<< " "<<blank[2][0]<<" | "<<"  "<<blank[2][1]<<"  | "<<blank[2][2]<<" \n";
     cout<<"   |      | "<<endl;
}
void FunctionTwo(){

    int digit;
    if(token=='x'){
        cout<<n1<< " please enter ";
        cin>>digit;
    }
    else{
        cout<<n2<<" please enter";
        cin>>digit;
    }

    if(digit==1){
        row=0;
        column=0;
    }

    if(digit==2){
        row=0;
        column=1;
    }

    if(digit==3){
        row=0;
        column=2;
    }

    if(digit==4){
        row=1;
        column=0;
    }

    if(digit==5){
        row=1;
        column=1;
    }

    if(digit==6){
        row=1;
        column=2;
    }

    if(digit==7){
        row=2;
        column=0;
    }

    if(digit==8){
        row=2;
        column=1;
    }

    if(digit==9){
        row=2;
        column=2;
    }

    else if(digit<1|| digit>9){
        cout<<" invalid!!(The digit should be between 0-9.)"<<endl;
    }

    if(token=='x' && blank[row][column]!='x'&& blank[row][column]!='0'){
      blank[row][column]='x';
      token='0';  
    }
    else if(token=='0' && blank[row][column]!='x'&& blank[row][column]!='0'){
        blank[row][column]='0';
      token='x';  
    }
    else if ( blank[row][column]=='x'|| blank[row][column]=='0'){
        cout<<"There is no empty space. "<<endl;
        return;
    }
   
FunctionOne();
}
 

bool FunctionThree(){
    for(int i=0;i<3;i++){
        if(blank[i][0]==blank[i][1]&& blank[i][0]==blank[i][2] || blank[0][i]==blank[1][i]&&blank[0][i]==blank[2][i]){
            return true;

        }

        if(blank[0][0]==blank[1][1]&& blank[1][1]==blank[2][2] || blank[0][2]==blank[1][1] && blank[1][1] ==blank[2][0]){
            return true;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(blank[i][j]!= 'x' && blank[i][j]!= '0'){
                    return false;
                }
            }
        }
       
    }
     tie=true;
        return false;
}
int main(){

     cout<<"Enter the name of the first player : "<<endl;
    cin>>n1;
    cout<<"Enter the name of the second player : "<<endl;
    cin>>n2;

    cout<<n1<<" is player 1 so he/she gets the first turn. "<<endl;
    cout<<n2<<" gets the second turn.  "<<endl;

  while(!FunctionThree() && !tie){
    FunctionOne();
    FunctionTwo();
    FunctionThree();
    
  }  

  if(token=='x' && tie==false){
    cout<<n2<<" Wins!! "<<endl;
  }
  else if( token=='0' && tie == false){
cout<<n1<<" wins!!"<< endl;
  }

  else{
    cout<<" Its a draw."<< endl;
  }
}


