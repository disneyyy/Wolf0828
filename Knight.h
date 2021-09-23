#ifndef KNIGHT_H
#define KNIGHT_H
#include "Character.h"
#include <iostream>
using namespace std;
class Knight: public Character{
public:
	Knight(int m=10):Character(m){
		used=false;
	}
	int skill(char* name){
		while(true){
			system("cls");
			used = true;
			cout<<"請選擇決鬥對象："<<endl;
			cin>>decision;
			if(decision>n||decision<1||CheckName(decision, ' ', name)||CheckName(decision, 'K', name))
				continue;
			if(isWolf(name[decision-1])){
				cout<<"Success"<<endl;
				break;
			}
			else{
				cout<<"Failed"<<endl;
				for(int i=0; i<n; i++){
					if(name[i]=='K')
						decision=i+1;
				}
				break;
			}
		}
		system("pause");
		system("cls");
		return decision;
	}
	bool Attacked(){
		return used;
	}
private:
	bool used;
	bool isWolf(char b){
		switch(b){
			case 'F':
			case 'S':
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
