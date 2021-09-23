#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "God.h"
#include "Wolf.h"
#include "KingWolf.h"
#include "Witch.h"
#include "Prophet.h"
#include "Hunter.h"
#include "Knight.h"
using namespace std;
int main() {
	char *name;
	int n,witch;
	while(true){
		cout<<"輸入遊玩人數（8~10人）：";
		cin>>n;
		if(n>=8&&n<=10)
			break;
		system("cls");
	}
	system("cls");
	//設定 
	God God(n);
	Wolf Wolf(n);
	KingWolf KingWolf(n);
	Witch Witch(n);
	Prophet Prophet(n);
	Hunter Hunter(n);
	Knight Knight(n);
	srand(time(NULL) );
	name = new char[n];
	God.Set(n, name);
	God.PrintChar(name);
	while(true){
		God.PrintLive(name);
		//遊戲開始 
		Wolf.skill(name);
		Prophet.skill(name);
		Witch.Revive(name, Wolf.decide());
		witch = Witch.decide();
		if(!Witch.Revived())
			Witch.Poison(name);
		else
			Witch.Reset();
		if(witch==0){
			char a;
			if(God.CheckName(Wolf.decide(), 'H', name)){
				a=Hunter.skill(name, Wolf.decide());
				if(a=='L')
					KingWolf.skill(name, Hunter.decide());
			}
			if(God.CheckName(Wolf.decide(), 'L', name)){
				a=KingWolf.skill(name, Wolf.decide());
				if(a=='H')
					Hunter.skill(name, KingWolf.decide());
			}
			God.kill(name, Wolf.decide());
		}
		cout<<"天亮了\n";
		God.PrintLive(name);
		if(God.CheckGame(name))
			break;
		God.Discuss(name, Knight.Attacked());
		if(God.decide()==0&&n==10){
			if(!Knight.Attacked() && !God.CheckDead(name, 'K')){
				Knight.skill(name);
				char p=name[Knight.decide()-1];
				Knight.kill(name, Knight.decide());
				if(God.CheckGame(name)){
					break;
				}
				if(p == 'H'){
					char pp=Hunter.skill(name, Knight.decide());
					if(pp=='L')
						KingWolf.skill(name, Hunter.decide());
				}
				if(p == 'L'){
					char pp=KingWolf.skill(name, Knight.decide());
					if(pp=='H')
						Hunter.skill(name, KingWolf.decide());
				}
				if(God.CheckGame(name)){
					break;
				}
				if(p=='K'){
					God.Discuss(name, Knight.Attacked());
					if(God.CheckName(God.decide(), 'H', name)){
						char pp=Hunter.skill(name, God.decide());
						if(pp=='L')
							KingWolf.skill(name, Hunter.decide());
					}	
					if(God.CheckName(God.decide(), 'L', name)){
						char pp=KingWolf.skill(name, God.decide());
						if(pp=='H')
							Hunter.skill(name, KingWolf.decide());
					}
					God.kill(name, God.decide());
				}
			}
		}
		else{
			if(God.CheckName(God.decide(), 'H', name)){
				char p=Hunter.skill(name, God.decide());
				if(p=='L')
					KingWolf.skill(name, Hunter.decide());
			}
			if(God.CheckName(God.decide(), 'L', name)){
				char p=KingWolf.skill(name, God.decide());
				if(p=='H')
					Hunter.skill(name, KingWolf.decide());
			}
			God.kill(name, God.decide());
		}
		if(God.CheckGame(name))
			break;
	}
	cout<<endl;
	delete [] name;
	return 0;
}
