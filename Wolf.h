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
		cout<<"�Ѷ½г���"<<endl;
 		system("pause");
 		system("cls");
 		//�T�H �������H�n���w���a�o���ٯ�� 
	 	while(true){
	 		system("cls");
	 		cout<<"�T�H�иC��\n�аݭn�����쪱�a�H��J�Ӫ��a���X�G"<<endl;
			cin>>decision;
			
			if(CheckName(decision, ' ', name)||decision>n||decision<1)
				continue;
			
			cout<<"���a"<<decision<<"�D����`"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}
};
#endif
