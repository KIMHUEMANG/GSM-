#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

long long gold = 11500;
long long hp = 1000;
long long pow = 100;
int FirstGradePrice = 300;

int FirstGrade = 0;
int First2Grade = 0;
int SecondGrade = 0;
int Second2Grade = 0;
int ThirdGrade = 0;
int AllOfStudent = 0;

void gotoxy(int x, int y);
void Admission();
void GoldScreenUpdate();

//메인화면
void mainscreen() {
	int AllOfStudent = FirstGrade + First2Grade + SecondGrade + Second2Grade + ThirdGrade;
	
	0;
	gotoxy(1, 1);
		printf("돈 : %lld 원  \n", gold);
	gotoxy(1, 2);
		printf("돈벌기 (s) ");
	gotoxy(71, 1);
		printf("입학받기[ - 300원 ] (a) ");
	gotoxy(71, 3);
		printf("총 학생 수 : %d", AllOfStudent);
	gotoxy(71, 5);
		printf("1학년 신입생 수 : %d", FirstGrade);
	gotoxy(71, 7);
		printf("1학년 엘리트 수 : %d", First2Grade);
	gotoxy(71, 9);
		printf("2학년 일반생 수 : %d", SecondGrade);
	gotoxy(71, 11);
		printf("2학년 엘리트 수 : %d", Second2Grade);
	gotoxy(71, 13);
		printf("3학년 취준생 수 : %d", ThirdGrade);
	gotoxy(70, 15);
		printf(" ---------------------------------------\n");
	gotoxy(70, 16);
		printf("|   상점가기 (1) 기능대회(2) 보스전(3)  |\n");
	gotoxy(70, 17);
		printf(" ---------------------------------------\n");
}

int main() {
	int InputKey;
	mainscreen();
	do {
		InputKey = _getch();
		if (InputKey == 'a') {
			Admission();
		}
		if (InputKey == 's') {
			GoldScreenUpdate();
		}
	} while (InputKey != 'q');
}

//입학
void Admission() {
	if (gold > FirstGradePrice) {
		gold -= 300;
		FirstGrade++;
		gotoxy(rand() % 17 + 5, rand() % 17 + 5);
		printf("1");
		mainscreen();
	}
}

//돈벌기
void GoldScreenUpdate() {
	gold++;
	COORD pos = { 1 , 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	mainscreen();
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
