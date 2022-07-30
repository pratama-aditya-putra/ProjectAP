#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <MyLibrary.h>
using namespace std;

int score=0, confirmation=0;
struct ID{
	char username[40];
	char NIM[40];
};
ID bio;

void Guide(){
	int i=0,j;
	setcolor(185);
	system("cls");
	box(0,3,25,100);
	header();
	box(18,5,17,63);
	const int maks = 1000;
	string array[50];
	char penyangga[maks+1];
	ifstream file_input("C:/B.Inggris/Guide.txt");
	while(file_input){
		file_input.getline(penyangga,maks);
		array[i]+=penyangga;
		i++;
	}
	for(j=0;j<=i;j++){
		gotoxy(20,6+j);cout << array[j];
	}
	gotoxy(32,25);system("pause");
}

void Question(int j, char x){
	const long long maks = 100000;
	int i;
	string array[210];
	char penyangga[maks+1];
	ifstream file_input("C:/B.Inggris/Soal.txt");
	while(file_input){
		file_input.getline(penyangga,maks);
		array[i]+=penyangga;
		i++;
	}
	file_input.close();
	for(i=j*7;i<(j+1)*7-1;i++){
		if(i%7>1){
			box(28,(i%7)*3+2,2,50);
			gotoxy(30,(i%7)*3+3);
			if(x==array[i][0]){
				setcolor(175);
				cout << array[i] << endl;
				setcolor(185);
			}
			else
				cout << array[i] << endl;
		}
		else{
		gotoxy(28,(i%7)+6);
		cout << array[i] << endl;
		}
	}
}

void Login(){
	int x=0;
	setcolor(185);
	system("cls");
	box(0,3,25,100);
	box(25,12,4,50);
	header();
	gotoxy(48,11);puts("LOGIN");
	gotoxy(37,12);cout << char(x=203);
	gotoxy(27,13);cout << " USERNAME " << char(x=186);
	vertical_line(25,14,50);gotoxy(37,14);cout << char(x=206);
	gotoxy(27,15);cout << " NIM      " << char(x=186);
	gotoxy(37,16);cout << char(x=202);
	gotoxy(38,13); setcolor(159);
	for(int i=1;i<38;i++)
		cout << " ";
	gotoxy(38,15); setcolor(159);
	for(int i=1;i<38;i++)
		cout << " ";
	gotoxy(38,13); gets(bio.username);
	gotoxy(38,15); gets(bio.NIM);                   
}

int Check(){
	const int maks = 51;
	int i=0,j;
	char array[100][maks+1];
	char penyangga[maks+1];
	ifstream file_input("C:/B.Inggris/AbsenKomB.txt");
	
	while(file_input){
		file_input.getline(penyangga,maks);
		for(j=0;j<=maks;j++){
			array[i][j]=penyangga[j];
		}
		i++;
	}confirmation=0;
	for(j=0;j<(i/2);j++){
		if(array[j*2][0]==toupper(bio.username[0])){
			if(stricmp(array[j*2],bio.username)==0){
				if(stricmp(array[(j*2)+1],bio.NIM)==0){
					confirmation=1;
					break;
				}
			}
		}
	}
}

void Caution(){
	int i=0,j;
	setcolor(185);
	system("cls");
	box(0,3,25,100);
	header();
	box(18,5,10,63);
	gotoxy(46,6); cout << "CAUTION";
	vertical_line(18,7,63);
	gotoxy(24,8); cout << "It seems that the username or NIM that you have been";
	gotoxy(24,9); cout << "inputed doesn't registered in this computer reinput";
	gotoxy(25,10); cout << "your username and NIM or contact the invigilator";
	gotoxy(33,12);system("pause");
}

void Main_Page(){
	int i=0, j, k=0;
	int check, temp, *ptr;
	char answer[30],x,y;
	score=0;
	for(int i=0;i<30;i++){
		answer[i]='\0';
	}
	while(i<=30){
		back:
		check=1;
		setcolor(185);system("cls");
		box(0,3,25,100);
		header();
		box(3,4,19,23);
		for(j=0;j<30;j++){
			box((j%5)*4+5,(j/5)*3+5,2,3);
			gotoxy((j%5)*4+6,(j/5)*3+6);
			if(answer[j]!='\0')
				setcolor(175);
			else 
				setcolor(207);
			cout << j+1;
			if(j<9)
				cout << " ";
			setcolor(185);
		}
		if(i==30){
			temp=1;
			box(30,12,5,46);
			gotoxy(35,13);cout << "Would you really want to end you test";
			for(j=0;j<30;j++){
				if(answer[j]==0)
					k++;
				}
				if(k>0){
					gotoxy(32,14);
					cout << "You still have " << k << " question remain unanswerd";
				}
			vertical_line(30,15,46);
			gotoxy(38,16);cout << "Esc[No]";
			horizontal_line(52,15,2);
			gotoxy(58,16);cout << "Enter[Yes]";
			while(temp){
				gotoxy(58,18);
				y=getch();
				if(y==27){
					i--;
					goto back;
					temp=0;
				}
				else if(y==13){
					goto end;
					temp=0;
				}
			}
		}
		if(i==0){
			gotoxy(78,25);cout << "Enter " << char(175);
		}
		else{
			gotoxy(29,25);cout << char(174) << " Esc";
			gotoxy(78,25);cout << "Enter " << char(175);
		}
		Question(i,answer[i]);
		box(80,20,2,4);
		input:
		gotoxy(82,21);cout << " ";
		while(check){
			temp=1;
			gotoxy(82,21);x=getche();
			x=toupper(x);
			if((x>=65)&&(x<=68)){
				while(temp){
					y=getch();
					if(y==27){
						answer[i]=x;
						i--;
						temp=0;
					}
					else if(y==13){
						answer[i]=x;
						i++;
						temp=0;
					}
					else if(y==8){
						goto input;
					}
				}
				check=0;
			}
			else if(x==8){
				goto input;
			}
			else if(x==27){
				if(i==0)
					goto input;
				else{
					i--;
					check=0;
				}
			}
			else if(x==13){
				i++;
				check=0;
			}
			else 
				goto input;
		}
	}
	end: i=0;
	const int maks = 10;
	string array[50];
	char penyangga[maks+1];
	ifstream file_input("C:/B.Inggris/Keys.txt");
	while(file_input){
		file_input.getline(penyangga,maks);
		array[i]+=penyangga;
		i++;
	}
	ptr=&score;
	for(int i=0;i<30;i++){
		(array[i][0]==answer[i])? *ptr+=1:*ptr+=0;
	}
}

void Result(){
	setcolor(185);
	system("cls");
	box(0,3,25,100);
	header();
	box(20,6,7,53);
	gotoxy(40,7); cout << "Congratulations";
	gotoxy(21,8); cout << "Username : "<< bio.username;
	gotoxy(21,9); cout << "NIM      : "<< bio.NIM;
	gotoxy(28,10); cout << "You have completed the test with result";
	if(score>1){
		gotoxy(30,11); cout << score<< " right answers out of 30 questions";
	}
	else{
		gotoxy(30,11); cout << score<< " right answer out of 30 questions";
	}
	gotoxy(31,15); system("pause");
}

int main(){
	start:
	Guide(); 
	relogin:
	Login();
	Check();
	if(confirmation==0){
		Caution();
		goto relogin;
	}
	Main_Page();
	Result();
	goto start;
}
