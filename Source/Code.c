#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//User의 Value
long long gold = 1503330;
long long hp = 1000;
long long pow = 100;
int FirstGradePrice = 300;
int makegold = 1;
int makegoldLV = 1;
long long makegoldLvPrice = 100;

//학생수
int FirstGrade = 0;
int First2Grade = 0;
int SecondGrade = 0;
int Second2Grade = 0;
int ThirdGrade = 0;
int FeatureGrade = 0;
int AllOfStudent = 0;
int AllOfStudentState = 0;

//기능반학생

//시설 장비
int desktop = 0;
int desktopATK = 1200;
int laptop = 0;
int laptopATK = 15000;
int airpod = 0;
int airpotHP = 80000;


//Feature Function
void gotoxy(int x, int y);
void Admission();
void GoldScreenUpdate();
void StateUpdate();
void shop();
void goldLvup();
void fusionFirst();
void fusionFirst2();
void fusionSecond();
void fusionSecond2();
void SchoolFacility();
void SchoolFacilityScreen();

//메인화면
void mainscreen() {
	gotoxy(1, 1);
		printf("돈 : %lld 원  \n", gold);
	gotoxy(1, 2);
		printf("돈벌기 (spacebar)");
	gotoxy(1, 4);
		printf("입학받기[ - 300원 ] (a) or (s) ");
	gotoxy(71, 1);
		printf("총 학생 수 : %d ", AllOfStudent);
	gotoxy(71, 3);
		printf("1학년 신입생 수 : %d ", FirstGrade);
	gotoxy(71, 5);
		printf("1학년 엘리트 수 : %d ", First2Grade);
	gotoxy(71, 7);
		printf("2학년 일반생 수 : %d ", SecondGrade);
	gotoxy(71, 9);
		printf("2학년 엘리트 수 : %d ", Second2Grade);
	gotoxy(71, 11);
		printf("3학년 취준생 수 : %d ", ThirdGrade);
	gotoxy(71, 13);
		printf("3학년 기능반 수 : %d ", FeatureGrade);
	gotoxy(70, 15);
		printf(" ---------------------------------------\n");
	gotoxy(70, 16);
		printf("|   상점가기 (i) 기능대회(o) 보스전(p)  |\n");
	gotoxy(70, 17);
		printf(" ---------------------------------------\n");
	gotoxy(37, 1);
		printf("--GSM--");
	gotoxy(37, 3);
		printf("돈벌기 레벨 : %d", makegoldLV);
	gotoxy(37, 4);
		printf("체력 : %lld ", hp);
	gotoxy(37, 5);
		printf("공격력 : %lld ", pow);
	gotoxy(6, 6);
		printf("□□□□학교 내부□□□□");
	gotoxy(11, 14);
		printf("ㅇ    ㅇ");
	gotoxy(12, 10);
		printf("  ㅇ   ㅇ ");
		printf("ㅇ   ㅇㅇ");
	gotoxy(13, 21);
		printf("ㅇㅇ   ㅇ");
		printf("   ㅇ");
	gotoxy(6, 25);
		printf("□□□□□□□□□□□□");
	gotoxy(70, 19);
		printf("■■■■■■■■■■■■■■■■■■■");
		gotoxy(70, 20);
		printf("■                                  ■");
		gotoxy(70, 21);
		printf("■ 1학년 합치기(G) L1학년 합치기(H) ■");
		gotoxy(70, 22);
		printf("■                                  ■");
		gotoxy(70, 23);
		printf("■ 2학년 합치기(J) L2학년 합치기(K) ■");
		gotoxy(70, 24);
		printf("■                                  ■");
		gotoxy(70, 25);
		printf("■■■■■■■■■■■■■■■■■■■");
	
		
}

int main() {
	mainscreen();
	char InputKey = "";
	do {
		InputKey = _getch();
		if (InputKey == 'a' || InputKey == 's') {
			Admission();
			StateUpdate();
		}
		else if (InputKey == ' ') {
			GoldScreenUpdate();
		}
		else if (InputKey == 'i') {
			shop();
		}
		else if (InputKey == 'z') {
			if (gold > makegoldLvPrice) {
				goldLvup();
				shop();
			}
		}
		else if (InputKey == 'v') {
			system("cls");
			mainscreen();
		}
		else if (InputKey == 'g') {
			fusionFirst();
			StateUpdate();
			mainscreen();
		}
		else if (InputKey == 'h') {
			fusionFirst2();
			StateUpdate();
			mainscreen();
		}
		else if (InputKey == 'j') {
			fusionSecond();
			StateUpdate();
			mainscreen();
		}
		else if (InputKey == 'k') {
			fusionSecond2();
			StateUpdate();
			mainscreen();
		}
		else if (InputKey == 'x') {
			SchoolFacility();
		}
	} while (InputKey != 'q');
}

//입학
void Admission() {
	if (gold > FirstGradePrice) {
		gold -= 300;
		FirstGrade++;
			gotoxy(rand() % 17 + 7, rand() % 17 + 7);
			printf("ㅇ");
			mainscreen();
		
	}
}

//돈벌기
void GoldScreenUpdate() {
	gold += makegold;
	COORD pos = { 1 , 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	mainscreen();
}

//능력치
void StateUpdate() {
	hp = 1000;
	pow = 100;
	AllOfStudent = FirstGrade + First2Grade + SecondGrade + Second2Grade + ThirdGrade + FeatureGrade;
	AllOfStudentState = FirstGrade + 4 * First2Grade + 16 * SecondGrade + 48 * Second2Grade + 108 * ThirdGrade + 108 * FeatureGrade;
	hp += AllOfStudentState * 5;
	pow += AllOfStudentState;
}
//상점 화면
void shop() {
	system("cls");
	printf("내 돈 : %lld\n", gold);
	printf("돈 벌기 레벨 : %d", makegoldLV);
	gotoxy(44, 3);
	printf("---------------------------GSM SHOP---------------------------\n\n");
	gotoxy(44, 4);
	printf("              학교 노동력 키우기 [ 가격 : %lld ]  (z)\n",makegoldLvPrice);
	gotoxy(44, 5);
	printf("                   학교 시설 장비 구입           (x)\n");
	gotoxy(44, 6);
	printf("                    기능반 전직시키기            (c)\n\n");
	gotoxy(44, 7);
	printf("                      상점 나가기                (v)");
	gotoxy(44, 8);
	printf("--------------------------------------------------------------");
}
//돈벌기 강화 소모비용 업데이트
void goldLvup() {
	if (makegoldLV <= 50) {
		makegold++;
		makegoldLV++;
		makegoldLvPrice = makegoldLvPrice + makegoldLV * 10;
		gold -= makegoldLvPrice;
	}
	else if (makegoldLV > 50) {
		makegold += 2;
		makegoldLV++;
		makegoldLvPrice = makegoldLvPrice + makegoldLV * 10;
		gold -= makegoldLvPrice;
	}
}
//학교시설 장비 스크린
void SchoolFacilityScreen() {
	shop();
	gotoxy(40, 10);
	printf("------------------------------학교 시설 물품------------------------------");
	gotoxy(40, 12);
	printf("1 쓸만한 중고 데스크탑 (30만원) : 공격력 : 1200 증가  // 현재 %d개 소유중",desktop);
	gotoxy(40, 14);
	printf("2 최신형 노트북 (300만원) : 공격력 : 15000 증가  // 현재 %d개 소유중",laptop);
	gotoxy(40, 16);
	printf("3 에어팍 프로 (150만원) : 체력 80000증가 //현재 %d개 소유중",airpod);
	gotoxy(40, 18);
	printf("4 오로지택 마우스 (2000만원) : 10퍼센트 확률로 스페셜 공격");
	gotoxy(40, 20);
	printf("5 맛있는 급식(5000만원) : 5퍼센트 확률로 체력 전부 회복");
	gotoxy(40, 22);
	printf("6 GSM 축구부(1억) : 30퍼센트 확률로 연속으로 공격한다.");
	gotoxy(40, 24);
	printf("----------------------------------------------------------------------------");
}
//학교 시설 장비
void SchoolFacility(){
	SchoolFacilityScreen();
	gotoxy(44, 26);
	int input;
	printf("사고싶은거 골라라(나가기 : 0) : ");
	scanf_s("%d", &input);
		if (input == 1) {
			if (gold >= 300000) {
				gold -= 300000;
				desktop++;
				pow += desktopATK;
				gotoxy(80, 26);
				printf("구입이 완료되었습니다");
				Sleep(500);
				SchoolFacility();
			}
			else if (gold < 300000) {
				gotoxy(80, 26);
				printf("돈이 부족합니다");
				Sleep(500);
				SchoolFacility();
			}
		}
		if (input == 0) {
			system("cls");
			shop();
		}
}
//합치기
void fusionFirst() {
	if (FirstGrade > 1) {
		FirstGrade -= 2;
		First2Grade++;
	}
}

void fusionFirst2() {
	if (First2Grade > 1) {
		First2Grade -= 2;
		SecondGrade++;
	}
}

void fusionSecond() {
	if (SecondGrade > 1) {
		SecondGrade -= 2;
		Second2Grade++;
	}
}

void fusionSecond2() {
	if (Second2Grade > 1) {
		Second2Grade -= 2;
		ThirdGrade++;
	}
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
