/*
author: HAN Shanglin
Use: For reference only, please ignore typo
Description: 
    The simplest tic-tac-toe, hope there are no bugs.
*/


#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;

int qipan[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
int state = 0;
bool easy = true;

inline int check_win(){
    // 1 for 'O' win 
    // 2 for 'X' win
    // 0 for tie
    // -1 for no win 
    // heng
    for (int i =0;i<3;i++){
        int t = qipan[i][0]+qipan[i][1]+qipan[i][2];
        if(t==3)return 1;
        if(t==30)return 2;
    }
    // shu
    for (int i =0;i<3;i++){
        int t = qipan[0][i]+qipan[1][i]+qipan[2][i];
        if(t==3)return 1;
        if(t==30)return 2;
    }
    //xie
    int t = qipan[0][0]+qipan[1][1]+qipan[2][2];
    if(t==3)return 1;
    if(t==30)return 2;
    t = qipan[0][2]+qipan[1][1]+qipan[2][0];
    if(t==3)return 1;
    if(t==30)return 2;
    for(int i = 0;i<3;i++)
        for(int j = 0;j<3;j++)
            if(qipan[i][j]==-1)return -1;
    // tie
    return 0;
}

inline void print_qipan(bool f){
    if(f){
        cout<<"-------\n|1|2|3|\n-------\n|4|5|6|\n-------\n|7|8|9|\n-------\n"<<endl;
        return;
    }
    vector<char>tmp;
    for (int i =0;i<3;i++)
        for(int j =0;j<3;j++){
            if(qipan[i][j]==-1) tmp.push_back(' ');
            else if(qipan[i][j]==1) tmp.push_back('O');
            else if(qipan[i][j]==10) tmp.push_back('X');
        }
    printf("-------\n|%c|%c|%c|\n-------\n|%c|%c|%c|\n-------\n|%c|%c|%c|\n-------\n",
    tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],tmp[8]);
}

inline bool check(int x){
    if(x<1 || x >9)return false;
    if(qipan[(x-1)/3][(x-1)%3]==-1)return true;
    return false;
}

int compter(){
    if(easy){
        int t = rand()%9;
        while(qipan[t/3][t%3]!=-1)
            t = rand()%9;
        return t;
    }

    // todo hard
    return -1;
}

void pvp(){
    // todo
    return ;
}

void pve(){
    srand(time(0));
    int human = -1;
    if(rand()%2 == 1){
        // human first
        human = 1;
        cout<<"after throw a dice, you first. use 'O' as your chess"<<endl;
    }else{
        human = 2;
        cout<<"after throw a dice, you first. use 'X' as your chess"<<endl;
    }
    cout<<"\nnow Game Strat!\n"<<endl;
    int win = -1;
    bool is_human_round = human==1?true:false;
    while(win == -1){
        if(is_human_round){
            print_qipan(true);
            cout<<"pls use number 1~9 to make your step"<< endl;
            int t = -1;
            cin>>t;
            while(t<1 || t>9){
                cout<<"pls use number 1~9 to make your step"<< endl;
                cin>>t;
            }
            while(check(t)==false){
                cout<<"you can't sit here please try again"<< endl;
                cin>>t;
                while(t<1 || t>9){
                    cout<<"pls use number 1~9 to make your step"<< endl;
                    cin>>t;
                }
            }
            qipan[(t-1)/3][(t-1)%3]= human==1?1:10;
            is_human_round = false;
        }else
        {
            int t = compter();
            qipan[t/3][t%3]= human==1?10:1;
            is_human_round = true;
        }
        cout<<"After this round the qipan shi zhe yang de"<< endl;
        print_qipan(false);
        win = check_win();
    }
    if(win==0){
        //tie
        cout<< "gan ba die, ping ju , try again"<<endl;
        return;
    }else if(win == human){
         cout<< "cong!!!!!!!"<<endl;
        return;
    }else{
        cout<< "looooooooooser!!!!!!!"<<endl;
        return;
    }
}

int init_game(){
    while(true){
        // step 2
        cout<<"please enter 0 for :Exit the system"<<endl;
        cout<<"please enter 1 for :Begin entering a new game"<<endl;
        int enter = -1;
        cin>>enter;
        while (enter != 0 && enter != 1){
            cout<<"wrong input, pls enter 0 or 1"<<endl;
            cin>>enter;
        }
        if(enter == 0){
            cout<<"bu ci hou le"<<endl;
            exit(0);
        }
        // step 3
        for (int i =0;i<3;i++)
            for(int j =0;j<3;j++)
                qipan[i][j] = -1;
        cout<<"please enter 0 for :The human player plays against the computer player"<<endl;
        cout<<"please enter 1 for :Two human players play against each other"<<endl;
        enter = -1;
        cin>>enter;
        while (enter != 0 && enter != 1){
            cout<<"wrong input, pls enter 0 or 1"<<endl;
            cin>>enter;
        }
        if(enter == 0) pve();
        else if(enter == 1)pvp();
        else {cout<<"error! bu ci hou le"<<endl; exit(0);}
    }


}


int main(){
    cout<<"Hi, huang ying lai dao TTT"<<endl;
    init_game();
    
    return 0;
}