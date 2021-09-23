#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <iomanip>
using namespace std;
class Character{
public:
	Character(int m=10){
		n=m;
	}
	bool CheckDead(char *name, char b){
		int i;
		for(i=0;i<n;i++){
			if(name[i]==b)
				return false;
		}
		return true;
	}
	bool CheckName(int a, char b, char *name){
		return name[a-1]==b;
	}
	void kill(char *name, int a){
		name[a-1]=' ';
	}
	int decide(){
		return decision;
	}
protected:
	int n;
	int decision;
};
#endif
