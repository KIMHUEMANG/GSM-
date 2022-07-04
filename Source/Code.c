#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//User의 Value
long long gold = 1500;
long long hp = 1000;
long long pow = 100;
int FirstGradePrice = 300;
int makegold = 1;
int makegoldLV = 1;
long long makegoldLvPrice = 100;

int used = 0;
int shopUsed = 0;
int turn = 0;

//학생수
int FirstGrade = 10;
int First2Grade = 0;
int SecondGrade = 0;
int Second2Grade = 0;
int ThirdGrade = 0;
int AllOfStudent = 0;
int AllOfStudentState = 0;

int FirstGradeState = 5;
int First2GradeState = 8;
int SecondGradeState = 12;
int Second2GradeState = 20;
int ThirdGradeState = 30;


//기능반학생
int gameStudent = 0, securityStudent = 0, itStudent = 0, random;
int FeatureGrade = 0;


//시설 장비
int desktop = 0;
int desktopATK = 1200;
int desktopHP = 6000;
int laptop = 0;
int laptopATK = 15000;
int airpod = 0;
int airpotHP = 80000;

int mouse = 0;
int lunch = 0;
int soccer = 0;

int mouseUsed = 0, lunchUsed = 0, soccerUsed = 0;

//boss
int Gclear =0, Bclear = 0, Sclear = 0, Hclear = 0;
//광주공고
int Gatk = 500 , Ghp = 5000;
//부 , 대 마이스터고
int Batk = 10000 , Bhp = 100000;
//서울대
int Satk = 99999, Shp = 9999999;
//하버드
int Hatk = 55555555, Hhp = 444444444;

// 보스전 체력 저장
long long savehp = 0;
long long saveGhp = 0;
long long saveBhp = 0;
long long saveShp = 0;
long long saveHhp = 0;




//Feature Function
void HideCursor();
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
void featurescreen();
void featurecom();
void gamecom();
void securitycom();
void itcom();
void LoadingCom();
void becomeFeature();
void becomeFeatureScreen();
void bossScreen();
void bossSelect();
void Gboss();
void BDboss();
void GbossAction();
void BDbossAction();
void Sboss();
void SbossAction();
void Hboss();
void HbossAction();
void Ending();


//메인화면
void FuckingSchool() {
	gotoxy(45, 14);
	printf("■■■■■■■");
	gotoxy(45, 15);
	printf("■   G S M  ■");
	gotoxy(45, 16);
	printf("■          ■");
	gotoxy(45, 17);
	printf("■          ■");
	gotoxy(37, 18);
	printf("■■■■■          ■■■■■");
	gotoxy(37, 19);
	printf("■                          ■");
	gotoxy(37, 20);
	printf("■    □□   □□   □□    ■");
	gotoxy(37, 21);
	printf("■    □□   □□   □□    ■");
	gotoxy(37, 22);
	printf("■                          ■");
	gotoxy(37, 23);
	printf("■           ┌┬┐            ■");
	gotoxy(37, 24);
	printf("■           │││            ■");
	gotoxy(37, 25);
	printf("■           └┴┘            ■");
	gotoxy(37, 26);
	printf("■■■■■■■■■■■■■■■");
}

void mainscreen() {
	gotoxy(1, 1);
		printf("돈 : %lld 원  \n", gold);
	gotoxy(1, 2);
		printf("돈벌기 [spacebar]");
	gotoxy(1, 3);
		printf("((클릭당 버는 돈 %d 원))",makegold);
	gotoxy(1, 5);
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
		printf("돈벌기 레벨 : %d ", makegoldLV);
	gotoxy(37, 4);
		printf("체력 :%lld  ", hp);
	gotoxy(37, 5);
		printf("공격력 :%lld", pow);
	gotoxy(6, 7);
		printf("□□□□학교 내부□□□□");
	gotoxy(11, 15);
		printf("0    0");
	gotoxy(12, 11);
		printf(" 0   0 ");
		printf("0   0 0");
	gotoxy(13, 22);
		printf("0 0   0");
		printf("   0");
	gotoxy(6, 26);
		printf("□□□□□□□□□□□□");
	gotoxy(70, 20);
		printf("■■■■■■■■■■■■■■■■■■■");
		gotoxy(70, 21);
		printf("■                                  ■");
		gotoxy(70, 22);
		printf("■ 1학년 합치기(G) L1학년 합치기(H) ■");
		gotoxy(70, 23);
		printf("■                                  ■");
		gotoxy(70, 24);
		printf("■ 2학년 합치기(J) L2학년 합치기(K) ■");
		gotoxy(70, 25);
		printf("■                                  ■");
		gotoxy(70, 26);
		printf("■■■■■■■■■■■■■■■■■■■");
		FuckingSchool();

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
			shopUsed = 1;
			shop();
		}
		else if (InputKey == 'z' && shopUsed == 1) {
			if (gold > makegoldLvPrice) {
				goldLvup();
				shop();
			}
		}
		else if (InputKey == 'v' && shopUsed == 1) {
			system("cls");
			mainscreen();
			shopUsed = 0;
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
		else if (InputKey == 'x' && shopUsed == 1) {
			SchoolFacility();
		}
		else if (InputKey == 'o') {
			featurecom();

		}
		else if (InputKey == 'c' && shopUsed == 1) {
			becomeFeature();
		}
		else if (InputKey == 'p') {
			bossSelect();
		}
		

	} while (InputKey != 'q');
}

//입학
void Admission() {
	if (gold > FirstGradePrice) {
		gold -= 300;
		FirstGrade++;
		pow += FirstGradeState;
		hp += FirstGradeState * 5;

		gotoxy(rand() % 23 + 7, rand() % 19 + 7);
		printf("0");
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

//학생 수 업데이트
void StateUpdate() {
	FeatureGrade = gameStudent + securityStudent + itStudent;
	AllOfStudent = FirstGrade + First2Grade + SecondGrade + Second2Grade + ThirdGrade + FeatureGrade + 1;
}
//상점 화면
void shop() {
	system("cls");
	printf("내 돈 : %lld\n", gold);
	printf("돈 벌기 레벨 : %d\n", makegoldLV);
	printf("기능반 전직 가능 학생 : %d\n\n", ThirdGrade);
	printf("---능력치---\n");
	printf("체력 : %lld\n", hp);
	printf("공격력 : %lld", pow);
	

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
	else if (makegoldLV > 50 && makegoldLV < 100) {
		makegold += 2;
		makegoldLV++;
		makegoldLvPrice = makegoldLvPrice + makegoldLV * 10;
		gold -= makegoldLvPrice;
	}
	else if (makegoldLV >= 100 && makegold < 150) {
		makegold += 5;
		makegoldLV++;
		makegoldLvPrice = makegoldLvPrice + makegoldLV * 10;
		gold -= makegoldLvPrice;
	}
	else if (makegoldLV >= 150 && makegold < 250) {
		makegold += 10;
		makegoldLV++;
		makegoldLvPrice = makegoldLvPrice + makegoldLV * 10;
		gold -= makegoldLvPrice;
	}
	else {
		makegold += 20;
		makegoldLV++;
		makegoldLvPrice = makegoldLvPrice + makegoldLV * 10;
		gold -= makegoldLvPrice;
	}
}
//학교시설 장비 스크린
void SchoolFacilityScreen() {
	shop();
	gotoxy(30, 10);
	printf("------------------------------학교 시설 물품------------------------------");
	gotoxy(30, 12);
	printf("1 쓸만한 중고 데스크탑 (30만원) : 공격력 : 1200 증가 , 체력 6000증가  // 현재 %d개 소유중",desktop);
	gotoxy(30, 14);
	printf("2 최신형 노트북 (300만원) : 공격력 : 15000 증가  // 현재 %d개 소유중",laptop);
	gotoxy(30, 16);
	printf("3 에어팍 프로 (150만원) : 체력 80000증가 //현재 %d개 소유중",airpod);
	gotoxy(30, 18);
	printf("4 오로지택 마우스 (2000만원) : 10퍼센트 확률로 스페셜 공격 // 현재 %d개 소유중",mouse);
	gotoxy(30, 20);
	printf("5 맛있는 급식(5000만원) : 5퍼센트 확률로 체력 전부 회복 // 현재 %d개 소유중",lunch);
	gotoxy(30, 22);
	printf("6 GSM 축구부(1억) : 30퍼센트 확률로 연속으로 공격한다. // 현재 %d개 소유중",soccer);
	gotoxy(30, 24);
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
				hp += desktopHP;

				gotoxy(73, 26);
				printf("구입이 완료되었습니다");
				Sleep(500);
				SchoolFacility();
			}
			else if (gold < 300000) {
				gotoxy(73, 26);
				printf("돈이 부족합니다");
				Sleep(500);
				SchoolFacility();
			}
		}
		else if (input == 2) {
			if (gold >= 3000000) {
				gold -= 3000000;
				laptop += 1;
				pow += laptopATK;
				gotoxy(73, 26);
				printf("구입이 완료되었습니다");
				Sleep(500);
				SchoolFacility();
			}
			else if (gold < 3000000) {
				gotoxy(73, 26);
				printf("돈이 부족합니다");
				Sleep(500);
				SchoolFacility();
			}
		}
		else if (input == 3) {
			if (gold >= 1500000) {
				gold -= 1500000;
				airpod += 1;
				hp += airpotHP;
				gotoxy(73, 26);
				printf("구입이 완료되었습니다");
				Sleep(500);
				SchoolFacility();
			}
			else if (gold < 1500000) {
				gotoxy(73, 26);
				printf("돈이 부족합니다");
				Sleep(500);
				SchoolFacility();
			}
		}
		else if (input == 4) {
			if (mouse < 1 && gold >= 20000000) {
				mouse += 1;
				gotoxy(73, 26);
				printf("구입이 완료되었습니다");
				Sleep(500);
				SchoolFacility();
			}
			else {
				gotoxy(73, 26);
				printf("돈이 부족하거나 이미 구입했습니다.");
				Sleep(500);
				SchoolFacility();
			}
		}
		else if (input == 5) {
			if (lunch < 1 && gold >= 50000000) {
				lunch += 1;
				gotoxy(73, 26);
				printf("구입이 완료되었습니다");
				Sleep(500);
				SchoolFacility();
			}
			else {
				gotoxy(73, 26);
				printf("돈이 부족하거나 이미 구입했습니다.");
				Sleep(500);
				SchoolFacility();
			}
		}
		else if (input == 6) {
			if (soccer < 1 && gold >= 100000000) {
				soccer += 1;
				gotoxy(73, 26);
				printf("구입이 완료되었습니다");
				Sleep(500);
				SchoolFacility();
			}
			else {
				gotoxy(73, 26);
				printf("돈이 부족하거나 이미 구입했습니다.");
				Sleep(500);
				SchoolFacility();
			}
		}

		else if (input == 0) {
			system("cls");
			shop();
		}
		else {
			while (getchar() != '\n');
			system("cls");
			SchoolFacility();
		}
}

//기능반 전직
void becomeFeature() {
	shop();
	becomeFeatureScreen();
	int input;

	gotoxy(44, 20);
	printf("무엇으로 전직 시킬것인가요 ?  나가기(0):");
	scanf_s("%d", &input);
	if (input == 1) {
		if (gameStudent < 3 && gold >= 100000) {
			ThirdGrade--;
			gameStudent++;
			gold -= 100000;
			gotoxy(44, 22);
			printf("전직 성공 ! ");
			Sleep(1000);
			system("cls");
			becomeFeature();
		}
		else if(gameStudent >= 3 || ThirdGrade < 1) {
			gotoxy(44, 22);
			printf("기능반 수가 다 찼거나 전직할 학생이 없습니다");
			Sleep(1000);
			becomeFeature();
		}
		else if (gold < 100000) {
			gotoxy(44, 22);
			printf("돈이 부족합니다.");
			Sleep(1000);
			becomeFeature();
		}
	}
	if (input == 2) {
		if (securityStudent < 3 && gold >= 100000) {
			ThirdGrade--;
			securityStudent++;
			gold -= 100000;
			gotoxy(44, 22);
			printf("전직 성공 ! ");
			Sleep(1000);
			system("cls");
			becomeFeature();
		}
		else if (securityStudent >= 3 || ThirdGrade < 0) {
			gotoxy(44, 22);
			printf("기능반 수가 다 찼거나 전직할 학생이 없습니다");
			Sleep(1000);
			becomeFeature();
		}

	}
	if (input == 3) {
		if (itStudent < 3 && gold >= 100000) {
			ThirdGrade--;
			itStudent++;
			gold -= 100000;
			gotoxy(44, 22);
			printf("전직 성공 ! ");
			Sleep(1000);
			system("cls");
			becomeFeature();
		}
		else if (itStudent > 2 || ThirdGrade < 0) {
			gotoxy(44, 22);
			printf("기능반 수가 다 찼거나 전직할 학생이 없습니다");
			Sleep(1000);
			becomeFeature();
		}
	}
	else if (input == 0) {
		system("cls");
		shop();
	}

	else {
		while (getchar() != '\n');
		system("cls");
		becomeFeature();
	}
}


void becomeFeatureScreen() {
	gotoxy(40, 10);
	printf("★☆★☆★☆기능반 전직★☆★☆★☆");
	gotoxy(45, 12);
	printf("게임개발 전직 (1)");
	gotoxy(45, 14);
	printf("사이버 보안 전직 (2)");
	gotoxy(45, 16);
	printf("IT 네트워크 전직 (3)");
	gotoxy(40, 18);
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆");
}

//합치기
void fusionFirst() {
	if (FirstGrade > 1) {
		FirstGrade -= 2;
		First2Grade++;
		pow += First2GradeState;
		hp += First2GradeState * 5;
	}
}

void fusionFirst2() {
	if (First2Grade > 1) {
		First2Grade -= 2;
		SecondGrade++;
		pow += SecondGradeState;
		hp += SecondGradeState * 5;
	}
}

void fusionSecond() {
	if (SecondGrade > 1) {
		SecondGrade -= 2;
		Second2Grade++;
		pow += Second2GradeState;
		hp += Second2GradeState * 5;
	}
}

void fusionSecond2() {
	if (Second2Grade > 1) {
		Second2Grade -= 2;
		ThirdGrade++;
		pow += ThirdGradeState;
		hp += ThirdGradeState * 5;
	}
}
//기능대회
void featurescreen() {
	gotoxy(30, 0);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(30, 1);
	printf("□                   기능대회                   □");
	gotoxy(30, 2);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(0, 0);
	printf("내 기능반 학생 수");
	gotoxy(0, 1);
	printf("▶ 게임 개발 : %d", gameStudent);
	gotoxy(0, 2);
	printf("▶ 사이버 보안 : %d", securityStudent);
	gotoxy(0, 3);
	printf("▶ IT 네트워크 : %d", itStudent);
	gotoxy(20, 5);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(20, 6);
	printf("□                                                                  □");
	gotoxy(20, 7);
	printf("□     게임 개발 대회 나가기( 1 )                                   □");
	gotoxy(20, 8);
	printf("□     (확률 : 1명 20%%, 2명 40%%, 3명 66%%)                           □");
	gotoxy(20, 9);
	printf("□                                                                  □");
	gotoxy(20, 10);
	printf("□     사이버 보안 대회 나가기 ( 2 )                                □");
	gotoxy(20, 11);
	printf("□     (확률 : 1명 25%% 2명 55%%, 3명 80%%)                            □");
	gotoxy(20, 12);
	printf("□                                                                  □");
	gotoxy(20, 13);
	printf("□     IT 네트워크(<--우웩) 대회 나가기 ( 3 )                       □");
	gotoxy(20, 14);
	printf("□     (확률 : 1명 33%%, 2명 66%%, 3명 99%%)                           □");
	gotoxy(20, 15);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(20, 17);
}

void featurecom() {
	system("cls");
	featurescreen();
	int input;
	printf("나가실 대회를 입력하세요 ( 나가기 : 0  ): ");
	scanf_s("%d", &input);
	if (input == 0) {
		system("cls");
		main();
		mainscreen();
	}
	else if (input == 1) {
		gamecom();
	}
	else if (input == 2) {
		securitycom();
	}
	else if (input == 3) {
		itcom();
	}
	else {
		while (getchar() != '\n');
		system("cls");
		featurecom();
	}
}

void gamecom() {
	random = rand() % 100 + 1;
	if (gameStudent  <  1) {
		gotoxy(20, 18);
		printf("인원이 부족합니다.");
		Sleep(1000);
		system("cls");
		featurecom();
	}
	gotoxy(20, 18);
	printf("                    ");
	LoadingCom();
	gotoxy(20, 18);
	printf("                    ");
	gotoxy(20, 18);
	if (gameStudent == 1) {
		if (random <= 20) {
			printf("success !! 상금을 획득하였습니다. (1000만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 10000000;
			gameStudent -= 1;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			gameStudent -= 1;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	else if (gameStudent == 2) {
		if (random <= 40) {
			printf("success !! 상금을 획득하였습니다. (1000만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 10000000;
			gameStudent -= 2;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			gameStudent -= 2;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	else if (gameStudent == 3) {
		if (random <= 66) {
			printf("success !! 상금을 획득하였습니다. (1000만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 10000000;
			gameStudent -= 3;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			gameStudent -= 3;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	featurescreen();
}

void securitycom() {
	random = rand() % 100 + 1;
	if (securityStudent < 1) {
		gotoxy(20, 18);
		printf("인원이 부족합니다.");
		Sleep(1000);
		system("cls");
		featurecom();
	}
	gotoxy(20, 18);
	printf("                    ");
	LoadingCom();
	gotoxy(20, 18);
	printf("                    ");
	gotoxy(20, 18);
	if (securityStudent == 1) {
		if (random <= 20) {
			printf("success !! 상금을 획득하였습니다. (800만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 8000000;
			securityStudent -= 1;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			securityStudent -= 1;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	else if (securityStudent == 2) {
		if (random <= 40) {
			printf("success !! 상금을 획득하였습니다. (800만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 8000000;
			securityStudent -= 2;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			securityStudent -= 2;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	else if (securityStudent == 3) {
		if (random <= 66) {
			printf("success !! 상금을 획득하였습니다. (800만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 8000000;
			securityStudent -= 3;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			securityStudent -= 3;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	featurescreen();
}

void itcom() {
	random = rand() % 100 + 1;
	if (itStudent < 1) {
		gotoxy(20, 18);
		printf("인원이 부족합니다.");
		Sleep(1000);
		system("cls");
		featurecom();
	}
	gotoxy(20, 18);
	printf("                    ");
	LoadingCom();
	gotoxy(20, 18);
	printf("                    ");
	gotoxy(20, 18);
	if (itStudent == 1) {
		if (random <= 20) {
			printf("success !! 상금을 획득하였습니다. (600만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 6000000;
			itStudent -= 1;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			itStudent -= 1;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	else if (itStudent == 2) {
		if (random <= 40) {
			printf("success !! 상금을 획득하였습니다. (600만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 6000000;
			itStudent -= 2;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			itStudent -= 2;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	else if (itStudent == 3) {
		if (random <= 66) {
			printf("success !! 상금을 획득하였습니다. (600만원) \n\n                    기능반 학생들이 채용됐습니다. 학교를 떠납니다");
			gold += 6000000;
			itStudent -= 3;
			Sleep(2000);
			system("cls");
			featurecom();
		}
		else {
			printf("fail .. 기능반 학생들이 자퇴했습니다.");
			itStudent -= 3;
			Sleep(1300);
			system("cls");
			featurecom();
		}
	}
	featurescreen();
}

void LoadingCom() {
	gotoxy(20, 18);
	printf("기능 대회 진행중");

	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
}

void bossSelect() {
	system("cls");
	bossScreen();
	int input;
	
	printf("\n\n                                             도전하실 보스를 선택하세요 : ");
	scanf_s("%d", &input);

	if (input == 1) {
		if (Gclear == 0) {
			system("cls");
			Sleep(500);
			printf("                                           광주공고  보스전 시작 ! ");
			Sleep(2000);
			system("cls");
			Gboss();
		}
		else {
			printf("                                            이미 클리어 하셨습니다");
			Sleep(1000);
			system("cls");
			bossSelect();
		}
	}
	if (input == 2) {
		if (Bclear == 1) {
			printf("                                            이미 클리어 하셨습니다");
			Sleep(1000);
			system("cls");
			bossSelect();
		}
		if (Gclear == 1) {
			mouseUsed = 0;
			lunchUsed = 0;
			soccerUsed = 0;
			system("cls");
			Sleep(500);
			printf("                                           부산, 대덕 소마고  보스전 시작 ! ");
			Sleep(2000);
			system("cls");
			BDboss();
			
		}
		else {
			printf("                                             광주공고를 클리어 해야합니다.");
			Sleep(1000);
			system("cls");
			bossSelect();
		}
	}
	if (input == 3) {
		if (Sclear == 1) {
			printf("                                            이미 클리어 하셨습니다");
			Sleep(1000);
			system("cls");
			bossSelect();
		}

		if (Bclear == 1) {
			mouseUsed = 0;
			lunchUsed = 0;
			soccerUsed = 0;
			system("cls");
			Sleep(500);
			printf("                                               서울대학교  보스전 시작 ! ");
			Sleep(2000);
			system("cls");
			Sboss();

		}
		else {
			printf("                                          부산,대덕 소마고를 클리어 해야합니다.");
			Sleep(1000);
			system("cls");
			bossSelect();
		}
	}
	if (input == 4) {
		if (Hclear == 1) {
			printf("                                            이미 클리어 하셨습니다");
			Sleep(1000);
			system("cls");
			bossSelect();
		}
		if (Sclear == 1) {
			mouseUsed = 0;
			lunchUsed = 0;
			soccerUsed = 0;
			system("cls");
			Sleep(500);
			printf("                                              하버드대학교  보스전 시작 ! ");
			Sleep(2000);
			system("cls");
			Hboss();
		}
		else {
			printf("                                        서울대학교를 클리어 해야합니다.");
			Sleep(1000);
			system("cls");
			bossSelect();
		}
	}
	else if (input == 0) {
		system("cls");
		mainscreen();
	}

	else {
		while (getchar() != '\n');
		system("cls");
		bossSelect();
	}
}

// 보스전
void GbossAction() {
	gotoxy(97, 16);
	printf("┌──────────┐");
	gotoxy(97, 17);
	printf("│          │");
	gotoxy(97, 18);
	printf("│ 광주공고 │");
	gotoxy(97, 19);
	printf("│          │");
	gotoxy(97, 20);
	printf("│          │");
	gotoxy(97, 21);
	printf("│          │");
	gotoxy(97, 22);
	printf("│          │");
	gotoxy(97, 23);
	printf("│          │");
	gotoxy(97, 24);
	printf("│          │");
	gotoxy(97, 25);
	printf("│          │");
	gotoxy(97, 26);
	printf("└──────────┘");


	gotoxy(18, 14);
	printf("■■■■■■■");
	gotoxy(18, 15);
	printf("■   G S M  ■");
	gotoxy(18, 16);
	printf("■          ■");
	gotoxy(18, 17);
	printf("■          ■");
	gotoxy(10, 18);
	printf("■■■■■          ■■■■■");
	gotoxy(10, 19);
	printf("■                          ■");
	gotoxy(10, 20);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 21);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 22);
	printf("■                          ■");
	gotoxy(10, 23);
	printf("■           ┌┬┐            ■");
	gotoxy(10, 24);
	printf("■           │││            ■");
	gotoxy(10, 25);
	printf("■           └┴┘            ■");
	gotoxy(10, 26);
	printf("■■■■■■■■■■■■■■■");
}

void Gboss() {
	if (turn == 0) {
		savehp = hp;
		saveGhp = Ghp;
		turn++;
	}

	if (Gclear == 1) {
		system("cls");
		mainscreen();
		return;
	}

	gotoxy(1, 1);
	printf("GSM");
	gotoxy(1, 2);
	printf("체력 : %lld", hp);
	gotoxy(1, 3);
	printf("공격력: %lld", pow);

	gotoxy(95, 1);
	printf("광주공고");
	gotoxy(95, 2);
	printf("체력 : %d", Ghp);
	gotoxy(95, 3);
	printf("공격력: %d", Gatk);

	GbossAction();

	gotoxy(50, 5);
	printf("무엇을 하시겠습니까 ?\n");
	gotoxy(50, 6);
	printf("     1 공격하기\n");
	gotoxy(50, 7);
	printf("     2 아이템\n");


	printf("                                                         ");
	int input;
	scanf_s("%d", &input);
	//1 공격 2 아이템 
	if (input == 1) {
		printf("                                                       GSM의 공격..\n");
		Sleep(1500);
		Ghp -= pow;
		printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow, Ghp);
		Sleep(1500);
		if (Ghp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("승리하셨습니다 !");
			hp = savehp;
			Ghp = saveGhp;
			Gclear = 1;
			Sleep(2000);
			system("cls");
			mainscreen();
			return;
		}
		printf("                                                     광주공고의 공격\n");
		hp -= Gatk;
		Sleep(1500);
		printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Gatk, hp);
		Sleep(1000);
		if (hp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("죽었습니다.");
			hp = savehp;
			Ghp = saveGhp;
			Sleep(2000);
			system("cls");
			mainscreen();
		}
		system("cls");
		Gboss();
	}
	if (input == 2) {
		used = 1;
		system("cls");

		gotoxy(80, 5);
		printf("3. 오로지택 마우스 사용하기");
		gotoxy(80, 6);
		printf("4. 맛있는 급식 사용하기");
		gotoxy(80, 7);
		printf("5. GSM 축구 팀 사용하기");
		printf("                                                                                                      ( 닫기 : 0 )");
		Gboss();

	}
	//아이템사용 전투
	if (used == 1 && input == 3) {
		if (mouseUsed == 0) {
			mouseUsed = 1;
			printf("                                                GSM의 오로지택 마우스 공격!\n");
			Sleep(1500);
			Ghp -= pow * 2;
			printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow * 2, Ghp);
			
			Sleep(1500);
			if (Ghp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Ghp = saveGhp;
				Gclear = 1;
				Sleep(2000);
				Gboss();
				return;
			}

		printf("                                                     광주공고의 공격\n");
		hp -= Gatk;
		Sleep(1500);
		printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Gatk, hp);
		Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Ghp = saveGhp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			Gboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Gboss();
		}
	}
	if (used == 1 && input == 4) {
		if (lunchUsed == 0) {
			lunchUsed = 1;
			hp = savehp;
			printf("                                                GSM은 맛있는 급식을 먹었다 !\n");
			Sleep(1500);
			
			printf("                                                체력을 전부 회복하셨습니다.");

			Sleep(1500);
			if (Ghp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Ghp = saveGhp;
				Gclear = 1;
				Sleep(2000);
				mainscreen();
				return;
			}

			printf("                                                                                                  광주공고의 공격\n");
			hp -= Gatk;
			Sleep(1500);
			printf("                                           %d만큼에 피해를 입었다. - 내 체력 %lld", Gatk, hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Ghp = saveGhp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			Gboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Gboss();
		}
	}
	if (used == 1 && input == 5) {
		if (soccerUsed == 0) {
			soccerUsed = 1;
			Ghp -= pow / 3 * 11;
			gotoxy(50, 12);
			printf(" GSM 축구부가 출동한다 !\n");
			Sleep(1500);
			gotoxy(50, 13);
			printf("1번선수의 공격 %lld 데미지 !",pow / 3);
			Sleep(200);
			gotoxy(50, 14);
			printf("2번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 15);
			printf("3번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 16);
			printf("4번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 17);
			printf("5번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 18);
			printf("6번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 19);
			printf("7번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 20);
			printf("8번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 21);
			printf("9번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 22);
			printf("10번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 23);
			printf("11번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(1000);
			gotoxy(50, 24);
			printf("광주공고의 남은 체력 : %d", Ghp);

			Sleep(1500);
			if (Ghp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Ghp = saveGhp;
				Gclear = 1;
				Sleep(2000);
				Gboss();
				return;
			}
			gotoxy(50, 25);
			printf("광주공고의 공격\n");
			hp -= Gatk;
			Sleep(1500);
			gotoxy(49, 26);
			printf(" %d만큼에 피해를 입었다. - 내 체력 %lld", Gatk, hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Ghp = saveGhp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			Gboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Gboss();
		}
	}
	if (used == 1 && input == 0) {
		system("cls");
		Gboss();
	}
	else {
		while (getchar() != '\n');
		system("cls");
		Gboss();
	}

}

void BDbossAction() {
	gotoxy(96, 13);
	printf("□□□□□□□□□□□");
	gotoxy(96, 14);
	printf("□                  □");
	gotoxy(96, 15);
	printf("□ 대덕,부산 소마고 □");
	gotoxy(96, 16);
	printf("□                  □");
	gotoxy(96, 17);
	printf("□                  □");
	gotoxy(96, 18);
	printf("□                  □");
	gotoxy(96, 19);
	printf("□                  □");
	gotoxy(96, 20);
	printf("□                  □");
	gotoxy(96, 21);
	printf("□                  □");
	gotoxy(96, 22);
	printf("□                  □");
	gotoxy(96, 23);
	printf("□                  □");
	gotoxy(96, 24);
	printf("□                  □");
	gotoxy(96, 25);
	printf("□                  □");
	gotoxy(96, 26);
	printf("□□□□□□□□□□□");

	gotoxy(18, 14);
	printf("■■■■■■■");
	gotoxy(18, 15);
	printf("■   G S M  ■");
	gotoxy(18, 16);
	printf("■          ■");
	gotoxy(18, 17);
	printf("■          ■");
	gotoxy(10, 18);
	printf("■■■■■          ■■■■■");
	gotoxy(10, 19);
	printf("■                          ■");
	gotoxy(10, 20);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 21);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 22);
	printf("■                          ■");
	gotoxy(10, 23);
	printf("■           ┌┬┐            ■");
	gotoxy(10, 24);
	printf("■           │││            ■");
	gotoxy(10, 25);
	printf("■           └┴┘            ■");
	gotoxy(10, 26);
	printf("■■■■■■■■■■■■■■■");


}

void BDboss() {
	if (turn == 0) {
		savehp = hp;
		saveBhp = Bhp;
		turn++;
	}

	if (Bclear == 1) {
		system("cls");
		mainscreen();
		return;
	}

	gotoxy(1, 1);
	printf("GSM");
	gotoxy(1, 2);
	printf("체력 : %lld", hp);
	gotoxy(1, 3);
	printf("공격력: %lld", pow);

	gotoxy(87, 1);
	printf("부산,대덕 소프트웨어 마이스터고");
	gotoxy(95, 2);
	printf("체력 : %d", Bhp);
	gotoxy(95, 3);
	printf("공격력: %d", Batk);

	BDbossAction();

	gotoxy(50, 5);
	printf("무엇을 하시겠습니까 ?\n");
	gotoxy(50, 6);
	printf("     1 공격하기\n");
	gotoxy(50, 7);
	printf("     2 아이템\n");


	printf("                                                         ");
	int input;
	scanf_s("%d", &input);
	//1 공격 2 아이템 
	if (input == 1) {
		printf("                                                       GSM의 공격..\n");
		Sleep(1500);
		Bhp -= pow;
		printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow, Ghp);
		Sleep(1500);
		if (Bhp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("승리하셨습니다 !");
			hp = savehp;
			Bhp = saveBhp;
			Bclear = 1;
			Sleep(2000);
			system("cls");
			BDboss();
			return;
		}
		printf("                                                 부산,대덕 소마고 의 공격\n");
		hp -= Batk;
		Sleep(1500);
		printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Batk, hp);
		Sleep(1000);
		if (hp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("죽었습니다.");
			hp = savehp;
			Bhp = saveBhp;
			Sleep(2000);
			system("cls");
			mainscreen();
		}
		system("cls");
		BDboss();
	}
	if (input == 2) {
		used = 1;
		system("cls");

		gotoxy(80, 5);
		printf("3. 오로지택 마우스 사용하기");
		gotoxy(80, 6);
		printf("4. 맛있는 급식 사용하기");
		gotoxy(80, 7);
		printf("5. GSM 축구 팀 사용하기");
		printf("                                                                                                      ( 닫기 : 0 )");
		BDboss();

	}
	//아이템사용 전투
	if (used == 1 && input == 3) {
		if (mouseUsed == 0) {
			mouseUsed = 1;
			printf("                                                GSM의 오로지택 마우스 공격!\n");
			Sleep(1500);
			Bhp -= pow * 2;
			printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow * 2, Bhp);

			Sleep(1500);
			if (Bhp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Bhp = saveBhp;
				Bclear = 1;
				Sleep(2000);
				BDboss();
				return;
			}

			printf("                                                     부산 , 대덕 소마고의 더 강한 공격\n");
			hp -= Batk * 1.5;
			Sleep(1500);
			printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Batk * 1.5 , hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Bhp = saveBhp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			BDboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			BDboss();
		}
	}
	if (used == 1 && input == 4) {
		if (lunchUsed == 0) {
			lunchUsed = 1;
			hp = savehp;
			printf("                                                GSM은 맛있는 급식을 먹었다 !\n");
			Sleep(1500);

			printf("                                                체력을 전부 회복하셨습니다.");

			Sleep(1500);
			if (Bhp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Bhp = saveBhp;
				Bclear = 1;
				Sleep(2000);
				return;
			}

			printf("                                                                                            부산,대덕 소마고는 싸이버거를 먹었다\n");
			Bhp += 20000;
			Sleep(1500);
			printf("                                           20000만큼 회복했다 부산,대덕 소마고의 체력 : %d", Bhp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Bhp = saveBhp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			BDboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			BDboss();
		}
	}
	if (used == 1 && input == 5) {
		if (soccerUsed == 0) {
			soccerUsed = 1;
			Bhp -= pow / 3 * 11;
			gotoxy(50, 10);
			printf(" GSM 축구부가 출동한다 !\n");
			Sleep(1500);
			gotoxy(50, 11);
			printf("1번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 12);
			printf("2번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 13);
			printf("3번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 14);
			printf("4번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 15);
			printf("5번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 16);
			printf("6번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 17);
			printf("7번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 18);
			printf("8번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 19);
			printf("9번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 20);
			printf("10번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(50, 21);
			printf("11번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(1000);
			gotoxy(50, 22);
			printf("부산,대덕 소마고의 남은 체력 : %d", Bhp);

			Sleep(1500);
			if (Bhp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Bhp = saveBhp;
				Bclear = 1;
				Sleep(2000);
				BDboss();
				return;
			}
			gotoxy(50, 23);
			printf("부산 ,대덕 소마고의 아주 강력한 공격\n");
			hp -= Batk * 2.5;
			Sleep(1500);
			gotoxy(49, 24);
			printf(" %d만큼에 피해를 입었다. - 내 체력 %lld", Batk * 3, hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Sleep(2000);
				system("cls");
				mainscreen();
				return;
			}
			system("cls");
			BDboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			BDboss();
		}
	}
	else {
		while (getchar() != '\n');
		system("cls");
		bossSelect();
	}
}

void SbossAction() {

	gotoxy(79, 11);
	printf("◈◈◈◈◈◈◈◈◈◈◈◈◈◈");
	gotoxy(79, 12);
	printf("◈                        ◈");
	gotoxy(79, 13);
	printf("◈                        ◈");
	gotoxy(79, 14);
	printf("◈       서울대학교       ◈");
	gotoxy(79, 15);
	printf("◈                        ◈");
	gotoxy(79, 16);
	printf("◈                        ◈");
	gotoxy(79, 17);
	printf("◈                        ◈");
	gotoxy(79, 18);
	printf("◈                        ◈");
	gotoxy(79, 19);
	printf("◈                        ◈");
	gotoxy(79, 20);
	printf("◈                        ◈");
	gotoxy(79, 21);
	printf("◈                        ◈");
	gotoxy(79, 22);
	printf("◈                        ◈");
	gotoxy(79, 23);
	printf("◈                        ◈");
	gotoxy(79, 24);
	printf("◈                        ◈");
	gotoxy(79, 25);
	printf("◈                        ◈");
	gotoxy(79, 26);
	printf("◈                        ◈");
	gotoxy(79, 27);
	printf("◈                        ◈");
	gotoxy(79, 28);
	printf("◈◈◈◈◈◈◈◈◈◈◈◈◈◈");

	gotoxy(18, 14);
	printf("■■■■■■■");
	gotoxy(18, 15);
	printf("■   G S M  ■");
	gotoxy(18, 16);
	printf("■          ■");
	gotoxy(18, 17);
	printf("■          ■");
	gotoxy(10, 18);
	printf("■■■■■          ■■■■■");
	gotoxy(10, 19);
	printf("■                          ■");
	gotoxy(10, 20);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 21);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 22);
	printf("■                          ■");
	gotoxy(10, 23);
	printf("■           ┌┬┐            ■");
	gotoxy(10, 24);
	printf("■           │││            ■");
	gotoxy(10, 25);
	printf("■           └┴┘            ■");
	gotoxy(10, 26);
	printf("■■■■■■■■■■■■■■■");


}

void Sboss() {
	if (turn == 0) {
		savehp = hp;
		saveShp = Shp;
		turn++;
	}

	if (Sclear == 1) {
		system("cls");
		mainscreen();
		return;
	}

	gotoxy(1, 1);
	printf("GSM");
	gotoxy(1, 2);
	printf("체력 : %lld", hp);
	gotoxy(1, 3);
	printf("공격력: %lld", pow);

	gotoxy(91, 1);
	printf("서울대학교");
	gotoxy(95, 2);
	printf("체력 : %d", Shp);
	gotoxy(95, 3);
	printf("공격력: %d", Satk);

	SbossAction();

	gotoxy(50, 5);
	printf("무엇을 하시겠습니까 ?\n");
	gotoxy(50, 6);
	printf("     1 공격하기\n");
	gotoxy(50, 7);
	printf("     2 아이템\n");


	printf("                                                         ");
	int input;
	scanf_s("%d", &input);
	//1 공격 2 아이템 
	if (input == 1) {
		printf("                                                       GSM의 공격..\n");
		Sleep(1500);
		Shp -= pow;
		printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow, Shp);
		Sleep(1500);
		if (Shp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("승리하셨습니다 !");
			hp = savehp;
			Shp = saveShp;
			Sclear = 1;
			Sleep(2000);
			system("cls");
			Sboss();
			return;
		}
		printf("                                                     서울대학교의 공격\n");
		hp -= Satk;
		Sleep(1500);
		printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Satk, hp);
		Sleep(1000);
		if (hp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("죽었습니다.");
			hp = savehp;
			Shp = saveShp;
			Sleep(2000);
			system("cls");
			mainscreen();
		}
		system("cls");
		Sboss();
	}
	if (input == 2) {
		used = 1;
		system("cls");

		gotoxy(80, 5);
		printf("3. 오로지택 마우스 사용하기");
		gotoxy(80, 6);
		printf("4. 맛있는 급식 사용하기");
		gotoxy(80, 7);
		printf("5. GSM 축구 팀 사용하기");
		printf("                                                                                                      ( 닫기 : 0 )");
		Sboss();

	}
	//아이템사용 전투
	if (used == 1 && input == 3) {
		if (mouseUsed == 0) {
			mouseUsed = 1;
			printf("                                                GSM의 오로지택 마우스 공격!\n");
			Sleep(1500);
			Shp -= pow * 2;
			printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow * 2, Shp);

			Sleep(1500);
			if (Shp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Shp = saveShp;
				Sclear = 1;
				Sleep(2000);
				Sboss();
				return;
			}

			printf("                                                          서울대학교의 엄청 강한 공격\n");
			hp -= Satk * 1.5;
			Sleep(1500);
			printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Satk * 2, hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Shp = saveShp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			Sboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Sboss();
		}
	}
	if (used == 1 && input == 4) {
		if (lunchUsed == 0) {
			lunchUsed = 1;
			hp = savehp;
			printf("                                                GSM은 맛있는 급식을 먹었다 !\n");
			Sleep(1500);

			printf("                                                체력을 전부 회복하셨습니다.");

			Sleep(1500);
			if (Shp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Shp = saveShp;
				Sclear = 1;
				Sleep(2000);
				return;
			}

			printf("                                                                                             서울대학교는 소고기에 소주한잔을 먹었다\n");
			Shp += 10000000;
			Sleep(1500);
			printf("                                              1000000만큼 회복했다 서울대학교의 체력 : %d", Shp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Shp = saveShp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			Sboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Sboss();
		}
	}
	if (used == 1 && input == 5) {
		if (soccerUsed == 0) {
			soccerUsed = 1;
			Shp -= pow / 3 * 11;
			gotoxy(48, 10);
			printf(" GSM 축구부가 출동한다 !\n");
			Sleep(1500);
			gotoxy(48, 11);
			printf("1번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 12);
			printf("2번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 13);
			printf("3번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 14);
			printf("4번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 15);
			printf("5번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 16);
			printf("6번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 17);
			printf("7번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 18);
			printf("8번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 19);
			printf("9번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 20);
			printf("10번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 21);
			printf("11번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(1000);
			gotoxy(48, 22);
			printf("서울대학교의 남은 체력 : %d", Shp);

			Sleep(1500);
			if (Shp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Shp = saveShp;
				Sclear = 1;
				Sleep(2000);
				Sboss();
				return;
			}
			gotoxy(50, 23);
			printf("서울대학교의 아주 강력한 샤프심공격\n");
			hp -= Satk * 2.5;
			Sleep(1500);
			gotoxy(49, 24);
			printf(" %d만큼에 피해를 입었다. - 내 체력 %lld", Satk * 3, hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Sleep(2000);
				system("cls");
				mainscreen();
				return;
			}
			system("cls");
			Sboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Sboss();
		}
	}
	else {
		while (getchar() != '\n');
		system("cls");
		bossSelect();
	}
}

void HbossAction() {

	gotoxy(75, 7);
	printf("★★★★★★★★★★★★★★★★★★★★");
	gotoxy(75, 8);
	printf("★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★");
	gotoxy(75, 9);
	printf("★☆            『최종전』          ☆★");
	gotoxy(75, 10);
	printf("★☆                                ☆★");
	gotoxy(75, 11);
	printf("★☆           하버드 대학교        ☆★");
	gotoxy(75, 12);
	printf("★☆                                ☆★");
	gotoxy(75, 13);
	printf("★☆                                ☆★");
	gotoxy(75, 14);
	printf("★☆                                ☆★");
	gotoxy(75, 15);
	printf("★☆                                ☆★");
	gotoxy(75, 16);
	printf("★☆                                ☆★");
	gotoxy(75, 17);
	printf("★☆                                ☆★");
	gotoxy(75, 18);
	printf("★☆                                ☆★");
	gotoxy(75, 19);
	printf("★☆                                ☆★");
	gotoxy(75, 20);
	printf("★☆                                ☆★");
	gotoxy(75, 21);
	printf("★☆                                ☆★");
	gotoxy(75, 22);
	printf("★☆                                ☆★");
	gotoxy(75, 23);
	printf("★☆                                ☆★");
	gotoxy(75, 24);
	printf("★☆                                ☆★");
	gotoxy(75, 25);
	printf("★☆                                ☆★");
	gotoxy(75, 26);
	printf("★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★");
	gotoxy(75, 27);
	printf("★★★★★★★★★★★★★★★★★★★★");

	gotoxy(18, 14);
	printf("■■■■■■■");
	gotoxy(18, 15);
	printf("■   G S M  ■");
	gotoxy(18, 16);
	printf("■          ■");
	gotoxy(18, 17);
	printf("■          ■");
	gotoxy(10, 18);
	printf("■■■■■          ■■■■■");
	gotoxy(10, 19);
	printf("■                          ■");
	gotoxy(10, 20);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 21);
	printf("■    □□   □□   □□    ■");
	gotoxy(10, 22);
	printf("■                          ■");
	gotoxy(10, 23);
	printf("■           ┌┬┐            ■");
	gotoxy(10, 24);
	printf("■           │││            ■");
	gotoxy(10, 25);
	printf("■           └┴┘            ■");
	gotoxy(10, 26);
	printf("■■■■■■■■■■■■■■■");


}

void Hboss() {
	if (turn == 0) {
		savehp = hp;
		saveHhp = Hhp;
		turn++;
	}

	if (Hclear == 1) {
		system("cls");
		Ending();
		return;
	}

	gotoxy(1, 1);
	printf("GSM");
	gotoxy(1, 2);
	printf("체력 : %lld", hp);
	gotoxy(1, 3);
	printf("공격력: %lld", pow);

	gotoxy(90, 1);
	printf("하버드대학교");
	gotoxy(95, 2);
	printf("체력 : %d", Hhp);
	gotoxy(95, 3);
	printf("공격력: %d", Hatk);

	HbossAction();

	gotoxy(50, 5);
	printf("무엇을 하시겠습니까 ?\n");
	gotoxy(50, 6);
	printf("     1 공격하기\n");
	gotoxy(50, 7);
	printf("     2 아이템\n");


	printf("                                                         ");
	int input;
	scanf_s("%d", &input);
	//1 공격 2 아이템 
	if (input == 1) {
		printf("                                                       GSM의 공격..\n");
		Sleep(1500);
		Hhp -= pow;
		printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow, Hhp);
		Sleep(1500);
		if (Hhp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("승리하셨습니다 !");
			hp = savehp;
			Hhp = saveHhp;
			Hclear == 1;
			Ending();
			Sleep(2000);
			system("cls");

			return;
		}
		printf("                                                    하버드대학교의 공격\n");
		hp -= Hatk;
		Sleep(1500);
		printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Hatk, hp);
		Sleep(1000);
		if (hp <= 0) {
			system("cls");
			gotoxy(45, 10);
			printf("죽었습니다.");
			hp = savehp;
			Hhp = saveHhp;
			Sleep(2000);
			system("cls");
			mainscreen();
		}
		system("cls");
		Hboss();
	}
	if (input == 2) {
		used = 1;
		system("cls");

		gotoxy(80, 5);
		printf("3. 오로지택 마우스 사용하기");
		gotoxy(80, 6);
		printf("4. 맛있는 급식 사용하기");
		gotoxy(80, 7);
		printf("5. GSM 축구 팀 사용하기");
		printf("                                                                                                      ( 닫기 : 0 )");
		Hboss();

	}
	//아이템사용 전투
	if (used == 1 && input == 3) {
		if (mouseUsed == 0) {
			mouseUsed = 1;
			printf("                                                GSM의 오로지택 마우스 공격!\n");
			Sleep(1500);
			Hhp -= pow * 2;
			printf("                                        %lld 만큼의 피해를 입혔다 - 상대체력 %d\n", pow * 2, Hhp);

			Sleep(1500);
			if (Hhp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Hhp = saveHhp;
				Hclear == 1;
				Sleep(2000);
				Ending();
				return;
			}

			printf("                                                          하버드대학교의 엄청 강한 공격\n");
			hp -= Hatk * 1.5;
			Sleep(1500);
			printf("                                        %d만큼에 피해를 입었다. - 내 체력 %lld", Hatk * 2, hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Hhp = saveHhp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			Hboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Sboss();
		}
	}
	if (used == 1 && input == 4) {
		if (lunchUsed == 0) {
			lunchUsed = 1;
			hp = savehp;
			printf("                                                GSM은 맛있는 급식을 먹었다 !\n");
			Sleep(1500);

			printf("                                                체력을 전부 회복하셨습니다.");

			Sleep(1500);
			if (Hhp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Hhp = saveHhp;
				Hclear = 1;
				Sleep(2000);
				return;
			}

			printf("                                                                                           하버드대학교는 피쉬앤칩스와 박주홍의 다리살을 먹었다\n");
			Hhp += 2000000;
			Sleep(1500);
			printf("                                            20000000만큼 회복했다 하버드대학교의 체력 : %d", Hhp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Hhp = saveHhp;
				Sleep(2000);
				system("cls");
				mainscreen();
			}
			system("cls");
			Hboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Hboss();
		}
	}
	if (used == 1 && input == 5) {
		if (soccerUsed == 0) {
			soccerUsed = 1;
			Hhp -= pow / 3 * 11;
			gotoxy(48, 10);
			printf(" GSM 축구부가 출동한다 !\n");
			Sleep(1500);
			gotoxy(48, 11);
			printf("1번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 12);
			printf("2번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 13);
			printf("3번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 14);
			printf("4번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 15);
			printf("5번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 16);
			printf("6번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 17);
			printf("7번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 18);
			printf("8번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 19);
			printf("9번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 20);
			printf("10번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(200);
			gotoxy(48, 21);
			printf("11번선수의 공격 %lld 데미지 !", pow / 3);
			Sleep(1000);
			gotoxy(48, 22);
			printf("하버드대학교의 남은 체력 : %d", Hhp);

			Sleep(1500);
			if (Hhp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("승리하셨습니다 !");
				hp = savehp;
				Hhp = saveHhp;
				Hclear = 1;
				Sleep(2000);
				Ending();
				return;
			}
			gotoxy(50, 23);
			printf("하버드대하교의 아주 강력한 볼펜공격\n");
			hp -= Hatk * 2.5;
			Sleep(1500);
			gotoxy(49, 24);
			printf(" %d만큼에 피해를 입었다. - 내 체력 %lld", Hatk * 3, hp);
			Sleep(1000);

			if (hp <= 0) {
				system("cls");
				gotoxy(45, 10);
				printf("죽었습니다.");
				hp = savehp;
				Sleep(2000);
				system("cls");
				Ending();
				return;
			}
			system("cls");
			Hboss();
		}
		else {
			printf("                                                     이미 사용했습니다.");
			Sleep(1000);
			system("cls");
			Hboss();
		}
	}
	else {
		while (getchar() != '\n');
		system("cls");
		bossSelect();
	}
}



void bossScreen() {
	gotoxy(30, 0);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(30, 1);
	printf("□                   보스전                     □");
	gotoxy(30, 2);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(3, 15);
	printf("┌──────────┐");
	gotoxy(3, 16);
	printf("│          │");
	gotoxy(3, 17);
	printf("│ 광주공고 │");
	gotoxy(3, 18);
	printf("│          │");
	gotoxy(3, 19);
	printf("│ 체력 :   │");
	gotoxy(3, 20);
	printf("│ 5000     │");
	gotoxy(3, 21);
	printf("│          │");
	gotoxy(3, 22);
	printf("│ 공격력 : │");
	gotoxy(3, 23);
	printf("│ 500      │");
	gotoxy(3, 24);
	printf("│      1   │");
	gotoxy(3, 25);
	printf("└──────────┘");

	gotoxy(20, 12);
	printf("□□□□□□□□□□□");
	gotoxy(20, 13);
	printf("□                  □");
	gotoxy(20, 14);
	printf("□ 대덕,부산 소마고 □");
	gotoxy(20, 15);
	printf("□                  □");
	gotoxy(20, 16);
	printf("□                  □");
	gotoxy(20, 17);
	printf("□   체력 : 100,000 □");
	gotoxy(20, 18);
	printf("□                  □");
	gotoxy(20, 19);
	printf("□                  □");
	gotoxy(20, 20);
	printf("□  공격력 : 10,000 □");
	gotoxy(20, 21);
	printf("□                  □");
	gotoxy(20, 22);
	printf("□          2       □");
	gotoxy(20, 23);
	printf("□                  □");
	gotoxy(20, 24);
	printf("□                  □");
	gotoxy(20, 25);
	printf("□□□□□□□□□□□");


	gotoxy(45, 8);
	printf("◈◈◈◈◈◈◈◈◈◈◈◈◈◈");
	gotoxy(45, 9);
	printf("◈                        ◈");
	gotoxy(45, 10);
	printf("◈                        ◈");
	gotoxy(45, 11);
	printf("◈       서울대학교       ◈");
	gotoxy(45, 12);
	printf("◈                        ◈");
	gotoxy(45, 13);
	printf("◈                        ◈");
	gotoxy(45, 14);
	printf("◈   체력 : 99,999,99     ◈");
	gotoxy(45, 15);
	printf("◈                        ◈");
	gotoxy(45, 16);
	printf("◈                        ◈");
	gotoxy(45, 17);
	printf("◈   공격력 : 9,999,99    ◈");
	gotoxy(45, 18);
	printf("◈                        ◈");
	gotoxy(45, 19);
	printf("◈                        ◈");
	gotoxy(45, 20);
	printf("◈              3         ◈");
	gotoxy(45, 21);
	printf("◈                        ◈");
	gotoxy(45, 22);
	printf("◈                        ◈");
	gotoxy(45, 23);
	printf("◈                        ◈");
	gotoxy(45, 24);
	printf("◈                        ◈");
	gotoxy(45, 25);
	printf("◈◈◈◈◈◈◈◈◈◈◈◈◈◈");

	gotoxy(75, 5);
	printf("★★★★★★★★★★★★★★★★★★★★");
	gotoxy(75, 6);
	printf("★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★");
	gotoxy(75, 7);
	printf("★☆            『최종전』          ☆★");
	gotoxy(75, 8);
	printf("★☆                                ☆★");
	gotoxy(75, 9);
	printf("★☆           하버드 대학교        ☆★");
	gotoxy(75, 10);
	printf("★☆                                ☆★");
	gotoxy(75, 11);
	printf("★☆                                ☆★");
	gotoxy(75, 12);
	printf("★☆   체력 :  444,444,444          ☆★");
	gotoxy(75, 13);
	printf("★☆                                ☆★");
	gotoxy(75, 14);
	printf("★☆                                ☆★");
	gotoxy(75, 15);
	printf("★☆   공격력 :  55,555,555         ☆★");
	gotoxy(75, 16);
	printf("★☆                                ☆★");
	gotoxy(75, 17);
	printf("★☆                                ☆★");
	gotoxy(75, 18);
	printf("★☆                                ☆★");
	gotoxy(75, 19);
	printf("★☆                                ☆★");
	gotoxy(75, 20);
	printf("★☆              4                 ☆★");
	gotoxy(75, 21);
	printf("★☆                                ☆★");
	gotoxy(75, 22);
	printf("★☆                                ☆★");
	gotoxy(75, 23);
	printf("★☆                                ☆★");
	gotoxy(75, 24);
	printf("★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★");
	gotoxy(75, 25);
	printf("★★★★★★★★★★★★★★★★★★★★");

}


void Ending() {
	gotoxy(20, 3);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(20, 4);
	printf("■                                                                ■");
	gotoxy(20, 5);
	printf("■                                                                ■");
	gotoxy(20, 6);
	printf("■                                                                ■");
	gotoxy(20, 7);
	printf("■                                                                ■");
	gotoxy(20, 8);
	printf("■                                                                ■");
	gotoxy(20, 9);
	printf("■                                                                ■");
	gotoxy(20, 10);
	printf("■                                                                ■");
	gotoxy(20, 11);
	printf("■                                                                ■");
	gotoxy(20, 12);
	printf("■                                                                ■");
	gotoxy(20, 13);
	printf("■                                                                ■");
	gotoxy(20, 14);
	printf("■                                                                ■");
	gotoxy(20, 15);
	printf("■                                                                ■");
	gotoxy(20, 16);
	printf("■                                                                ■");
	gotoxy(20, 17);
	printf("■                                                                ■");
	gotoxy(20, 18);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	Sleep(1000);
	gotoxy(52, 5);
	printf("End");
	Sleep(2000);
	gotoxy(38, 8);
	printf("게임을 플레이 해주셔서 감사합니다.");
	Sleep(2000);
	gotoxy(43, 11);
	printf("제작자 : 김희망, 이기환");
	Sleep(2000);

	exit(0);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor() //커서를 숨김
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
