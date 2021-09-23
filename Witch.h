#ifndef WITCH_H
#define WITCH_H
#include "Character.h"
#include <iostream>
using namespace std;
class Witch: public Character{
public:
	Witch(int m=10):Character(m){
		potionR=true;
		potionP=true;
		used = false;
	}
	void Revive(char* name, int a){
		decision = 0;
		while(potionR&&!CheckDead(name, 'W')){
			cout<<"女巫請睜眼\n今晚 "<<a<<" 號遭到殺害，是否拯救？是 1 否 0：";
			cin>>decision;
			if(decision==1){
				potionR=false;
				used=true;
				//system("pause");
				system("cls");
				break;
			}
			else if(decision==0){ 
				//kill.(name, a);
				//system("pause");
				system("cls");
				break;
			} 
			else{
				system("cls");
				continue;	
			}
		}
	}
	void Poison(char *name){
		cout<<"女巫請睜眼\n";
		cout<<"請問您要對誰下毒？輸入該玩家號碼或輸入0不執行：";
		while(potionP&&!CheckDead(name, 'W')){
			cin>>decision;
			if(decision==0){
				break;
			}
			else if(decision>0 && decision<=n){
				kill(name, decision);
				potionP=false;
				break;
			}
			else{
				system("cls");
				cout<<"女巫請睜眼\n";
				cout<<"請問您要對誰下毒？輸入該玩家號碼或輸入0不執行：";
				continue;				
			}
			system("cls");
		}
		system("pause");
		system("cls");
	}
	bool Revived(){
		return used;
	}
	void Reset(){
		used = false;
	}
private:
	bool potionR;
	bool potionP;
	bool used;//當回使用revive 
};
#endif
