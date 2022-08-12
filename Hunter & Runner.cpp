#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

int skor = 0;
string hunter = "H", runner = "R";
string notification = "    You are (H)unter, \n    Catch the (R)unner ...";
string line[10]={"+-----------------------+",
                 "|                       |",
                 "|                       |",
                 "|                       |",
                 "|                       |",
                 "|                       |",
                 "|                       |",
                 "|                       |",
                 "|                       |",
                 "+-----------------------+"};

int enemyLineJalan(int num);
int enemyIndexLineJalan(int num);
void menangGak(int myLine, int myIndexLine, int enemyLine, int enemyIndexLine);
void acak();
void tampilan(int myLine, int myIndexLine, int enemyLine, int enemyIndexLine);

int enemyLineJalan(int num){
	int newNum;
	while(true){
		srand(time(0));
		int acak = rand()%2;
		switch(acak){
			case 0:
				newNum = num +1;
				break;
			case 1:
				newNum = num -1;
				break;
		}
		if(newNum!=0 && newNum<9){
			break;
		}
	}
	return newNum;
}

int enemyIndexLineJalan(int num){
	int newNum;
	while(true){
		srand(time(0));
		int acak = rand()%2;
		switch(acak){
			case 0:
				newNum = num +2;
				break;
			case 1:
				newNum = num -2;
				break;
		}
		if(newNum!=0 && newNum<39){
			break;
		}
	}
	return newNum;
}

void menangGak(int myLine, int myIndexLine, int enemyLine, int enemyIndexLine){
	if(myLine==enemyLine && myIndexLine==enemyIndexLine){
		skor = skor + 10;
		notification = "    You Caught The (R)unner !\n";
		system("cls");
		cout << endl;
		cout << notification << endl;
		for(int i=0; i<10; i++){
			cout << "    " << line[i] << endl;
		}
		cout << "    Your Skor : " << skor << endl;
		notification = "    You are (H)unter, \n    Catch the (R)unner ...";
		line[myLine][myIndexLine]=' ';
		Sleep(1500);
		acak();
	}
}

void acak(){
	srand(time(0));
	int num = 1+rand()%8;
	int num1 = 1+rand()%21;
	int num2 = 1+rand()%8;
	int num3 = 1+rand()%21;
	while(true){
		if(num1%2==0){
			break;
		}
		num1 = 1+rand()%21;
	}
	while(true){
		if(num3%2==0){
			break;
		}
		num3 = 1+rand()%21;
	}
	tampilan(num,num1,num2,num3);
}

void tampilan(int myLine, int myIndexLine, int enemyLine, int enemyIndexLine){
	system("cls");
	
	cout << endl;
	cout << notification << endl;
	
	line[enemyLine][enemyIndexLine]='R';
	line[myLine][myIndexLine]='H';
	for(int i=0; i<10; i++){
		cout << "    " << line[i] << endl;
	}
	cout << "    Your Skor : " << skor << endl;
	
	menangGak(myLine,myIndexLine,enemyLine,enemyIndexLine);
	
	line[myLine][myIndexLine]=' ';
	line[enemyLine][enemyIndexLine]=' ';
	
	cout << "        ^" << endl;
	cout << "        W" << endl;
	cout << "    < A   D >" << endl;
	cout << "        S" << endl;
	cout << "        v" << endl << endl;
	
	string pil;
	cout << "    => "; cin >> pil;
	if(pil=="W" || pil=="w"){
		if(line[myLine-1][myIndexLine]==' '){
			line[myLine][myIndexLine]=' ';
			myLine = myLine-1;
		}
	}else if(pil=="S" || pil=="s"){
		if(line[myLine+1][myIndexLine]==' '){
			line[myLine][myIndexLine]=' ';
			myLine = myLine+1;
		}
	}else if(pil=="A" || pil=="a"){
		if(line[myLine][myIndexLine-2]==' '){
			line[myLine][myIndexLine]=' ';
			myIndexLine = myIndexLine-2;
		}
	}else if(pil=="D" || pil=="d"){
		if(line[myLine][myIndexLine+2]==' '){
			line[myLine][myIndexLine]=' ';
			myIndexLine = myIndexLine+2;
		}
	}
	line[myLine][myIndexLine]='H';
	menangGak(myLine,myIndexLine,enemyLine,enemyIndexLine);
	srand(time(0));
	int acak = rand()%2;
	if(acak%2==0){ enemyLine=enemyLineJalan(enemyLine); }
	else{ enemyIndexLine=enemyIndexLineJalan(enemyIndexLine); }
	tampilan(myLine,myIndexLine,enemyLine,enemyIndexLine);
}

int main(){
	acak();
}
