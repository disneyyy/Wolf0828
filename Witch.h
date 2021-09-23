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
			cout<<"�k�ŽиC��\n���� "<<a<<" ���D����`�A�O�_�@�ϡH�O 1 �_ 0�G";
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
		cout<<"�k�ŽиC��\n";
		cout<<"�аݱz�n��֤U�r�H��J�Ӫ��a���X�ο�J0������G";
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
				cout<<"�k�ŽиC��\n";
				cout<<"�аݱz�n��֤U�r�H��J�Ӫ��a���X�ο�J0������G";
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
	bool used;//��^�ϥ�revive 
};
#endif
