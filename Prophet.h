#ifndef PROPHET_H
#define PROPHET_H
#include "Character.h"
#include <iostream>
using namespace std;
class Prophet: public Character{
public:
	Prophet(int m=10):Character(m){
		
	}
	void skill(char *name){
		while(true){
			system("cls");
			cout<<"預言家請睜眼\n請問你要檢查誰的身分？輸入該玩家號碼："<<endl;
		 	if(!CheckDead(name, 'P')){
		 		cin>>decision;
		 		if(decision>n||decision<1||CheckName(decision, ' ', name)||CheckName(decision, 'P', name))
		 			continue;
		 		if(isWolf(name[decision-1]))
			 		cout<<"BAD"<<endl;
			 	else
			 		cout<<"GOOD"<<endl;
			 	break;
			}else{
				break;
			}
		}
	 	system("pause");
		system("cls");
	}
private:
	bool isWolf(char b){
		switch(b){
			case 'F':
			case 'L':
				return true;
				break;
			default:
				return false;
				break;
		}
	}
};
#endif
