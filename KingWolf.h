#ifndef KINGWOLF_H
#define KINGWOLF_H
#include "Character.h"
#include <iostream>
using namespace std;
class KingWolf: public Character{
public:
	KingWolf(int m=10):Character(m){
		
	}
	char skill(char* name, int b){
		char a=' ';
		while(true){
			system("cls");
			cout<<b<<"號技能發動！請輸入要殺害哪位玩家，若放棄則輸入0："<<endl;
			cin>>decision;
			if(decision>n||decision<0)
				continue;
			else{
				if(decision!=0){
					if(CheckName(decision, ' ', name)||CheckName(decision, 'L', name))
						continue;
					a= name[decision-1];
					kill(name, decision);
				}
				//system("pause");
				//system("cls");
				return a;
			}
		}
	}
};
#endif
