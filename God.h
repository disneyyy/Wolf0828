#ifndef GOD_H
#define GOD_H
#include "Character.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class God: public Character{
public:
	God(int m=10):Character(m){
	}
	~God(){

	}
	void Set(int n, char *name){
		int i, pos, temp;
		int player[10];
	 	player[0] = n;
	 	for(i = 1; i < n; ++i)
	  		player[i] = i;
	  		
	 	for(i = 0; i < n; ++i){//座位洗牌
	 		pos=rand()%n;
	 		temp=player[i];
	 		player[i]=player[pos];
	 		player[pos]=temp; 		
	 	}
	 	for(i = 0; i < n; ++i)//分配職業 
		 	switch(player[i]){
		 		case 1:
		 			name[i]='L';//狼王
		 			break;
		 		case 9:
		 			name[i]='S';//雪狼
		 			break;
		 		case 4:
		 			name[i]='F';//狼 
		 			break;
		 		case 2:
		 		case 6:
		 		case 8:
		 			name[i]='M';//平民
					break;
				case 5:
					name[i]='W';//女巫 
					break;
				case 3:
					name[i]='P';//預言家 
					break;
				case 7:
					name[i]='H';//獵人
					break;
				case 10:
					name[i]='K';//騎士 
					break; 
			}
	}
	bool CheckGame(char *a){
		if(CheckDead(a, 'F')&&CheckDead(a, 'S')&&CheckDead(a, 'L')){
			cout<<"Human Win"<<endl;
			system("pause");
			system("cls");
			return true;
		}
		else if(CheckDead(a, 'M')){
			cout<<"Wolf Win"<<endl;
			system("pause");
			system("cls");
			return true;
		}
		else if(CheckDead(a, 'W')&&CheckDead(a, 'P')&&CheckDead(a, 'H')&&CheckDead(a, 'K')){
			cout<<"Wolf Win"<<endl;
			system("pause");
			system("cls");
			return true;
		}
		else
			return false;
	}
	void PrintChar(char *a){
		int i;
		for(i=1; i<=n; i++){
	 		cout<<"玩家"<<setw(2)<<setfill('0')<<i<<"  "<<a[i-1]<<" "<<PrintName(a, i-1)<<endl;
	 		system("pause");
	 		system("cls");
	 	}
	}
	void PrintLive(char *a){
		int i;
		fout.open("_LiveList.txt", ios::out| ios::trunc);
		for(i = 0; i < n; ++i){
			if(a[i] == ' '){
	 			cout<<"玩家"<<setw(2)<<setfill('0')<<i+1<<" X"<<endl;
	 			fout<<"玩家"<<setw(2)<<setfill('0')<<i+1<<" X"<<endl;
			}
	 		else{
	 			cout<<"玩家"<<setw(2)<<setfill('0')<<i+1<<" O"<<endl;
	 			fout<<"玩家"<<setw(2)<<setfill('0')<<i+1<<" O"<<PrintName(a, i)<<endl;
			}
		}
		fout.close();
		system("pause");
 		system("cls");	
	}
	void Discuss(char *name, bool knight){//knight >>> Attacked
		while(true){
			system("cls");
			cout<<"請輸入大家票選的狼人，若要跳過則輸入-1";
			if(n==10 && !knight)
				cout<<"，若騎士要發動技能請輸入0";
			cout<<"：";
			cin>>decision;
			if((n<10&&decision==0)||((CheckDead(name, 'K')||knight)&&decision==0)||decision>n||decision<-1)
				continue;
			else if(decision>0&&decision<=n)
				if(CheckName(decision, ' ', name))
					continue;
			system("cls");
			break;
		}
	}
private:
	string PrintName(char* a, int i){
	 		switch(a[i]){
	 			case 'F':
	 				return " 小狼";
	 				break;
	 			case 'S':
	 				return " 雪狼";
	 				break;
	 			case 'L':
	 				return " 狼王";
	 				break;
	 			case 'M':
	 				return " 平民";
	 				break;
	 			case 'W':
	 				return " 女巫";
	 				break;
	 			case 'P':
	 				return " 預言家";
	 				break;
	 			case 'H':
	 				return " 獵人";
	 				break;
	 			case 'K':
	 				return " 騎士";
	 				break;
			 }
	}
	fstream fout;
};
#endif
