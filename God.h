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
	  		
	 	for(i = 0; i < n; ++i){//�y��~�P
	 		pos=rand()%n;
	 		temp=player[i];
	 		player[i]=player[pos];
	 		player[pos]=temp; 		
	 	}
	 	for(i = 0; i < n; ++i)//���t¾�~ 
		 	switch(player[i]){
		 		case 1:
		 			name[i]='L';//�T��
		 			break;
		 		case 9:
		 			name[i]='S';//���T
		 			break;
		 		case 4:
		 			name[i]='F';//�T 
		 			break;
		 		case 2:
		 		case 6:
		 		case 8:
		 			name[i]='M';//����
					break;
				case 5:
					name[i]='W';//�k�� 
					break;
				case 3:
					name[i]='P';//�w���a 
					break;
				case 7:
					name[i]='H';//�y�H
					break;
				case 10:
					name[i]='K';//�M�h 
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
	 		cout<<"���a"<<setw(2)<<setfill('0')<<i<<"  "<<a[i-1]<<" "<<PrintName(a, i-1)<<endl;
	 		system("pause");
	 		system("cls");
	 	}
	}
	void PrintLive(char *a){
		int i;
		fout.open("_LiveList.txt", ios::out| ios::trunc);
		for(i = 0; i < n; ++i){
			if(a[i] == ' '){
	 			cout<<"���a"<<setw(2)<<setfill('0')<<i+1<<" X"<<endl;
	 			fout<<"���a"<<setw(2)<<setfill('0')<<i+1<<" X"<<endl;
			}
	 		else{
	 			cout<<"���a"<<setw(2)<<setfill('0')<<i+1<<" O"<<endl;
	 			fout<<"���a"<<setw(2)<<setfill('0')<<i+1<<" O"<<PrintName(a, i)<<endl;
			}
		}
		fout.close();
		system("pause");
 		system("cls");	
	}
	void Discuss(char *name, bool knight){//knight >>> Attacked
		while(true){
			system("cls");
			cout<<"�п�J�j�a���諸�T�H�A�Y�n���L�h��J-1";
			if(n==10 && !knight)
				cout<<"�A�Y�M�h�n�o�ʧޯ�п�J0";
			cout<<"�G";
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
	 				return " �p�T";
	 				break;
	 			case 'S':
	 				return " ���T";
	 				break;
	 			case 'L':
	 				return " �T��";
	 				break;
	 			case 'M':
	 				return " ����";
	 				break;
	 			case 'W':
	 				return " �k��";
	 				break;
	 			case 'P':
	 				return " �w���a";
	 				break;
	 			case 'H':
	 				return " �y�H";
	 				break;
	 			case 'K':
	 				return " �M�h";
	 				break;
			 }
	}
	fstream fout;
};
#endif
