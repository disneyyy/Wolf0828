#ifndef WOLF_H
#define WOLF_H
#include "Character.h"
#include <iostream>
using namespace std;
class Wolf: public Character{
public:
	Wolf(int m=10):Character(m){
		
	}
	void skill(char *name){
		cout<<"天黑請閉眼"<<endl;
 		system("pause");
 		system("cls");
 		//狼人 殺掉的人要讓預言家這輪還能測 
	 	while(true){
	 		system("cls");
	 		cout<<"狼人請睜眼\n請問要殺哪位玩家？輸入該玩家號碼："<<endl;
			cin>>decision;
			
			if(CheckName(decision, ' ', name)||decision>n||decision<1)
				continue;
			
			cout<<"玩家"<<decision<<"遭到殺害"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}
};
#endif
