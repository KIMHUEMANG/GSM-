//User의 Value
long long gold = 11500;
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
int AllOfStudent = 0;

//Feature Function
void gotoxy(int x, int y);
void Admission();
void GoldScreenUpdate();
void StateUpdate();
void shop();
void shopfeature();
void goldLvup();

//메인화면
void mainscreen() {
	gotoxy(1, 1);
		printf("돈 : %lld 원  \n", gold);
	gotoxy(1, 2);
		printf("돈벌기 (s)");
	gotoxy(1, 4);
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
}

int main() {
	mainscreen();
	int InputKey = "";
	do {
		InputKey = _getch();
		if (InputKey == 'a') {
			Admission();
			StateUpdate();
		}
		if (InputKey == 's') {
			GoldScreenUpdate();
		}
		if (InputKey == 'i') {
			shop();
		}
	} while (InputKey != 'q');
}

//입학
void Admission() {
	if (gold > FirstGradePrice) {
		gold -= 300;
		FirstGrade++;
		gotoxy(rand() % 17 + 7, rand() % 17 + 7);
		printf("1");
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
	int AllOfStudent = FirstGrade + First2Grade + SecondGrade + Second2Grade + ThirdGrade;
	hp += AllOfStudent * 5;
	pow += AllOfStudent;
}
//상점 화면
void shop() {
	system("cls");
	printf("내 돈 : %lld", gold);
	gotoxy(44, 6);
	printf("-------GSM SHOP-------\n\n");
	gotoxy(44, 7);
	printf("노동력 키우기(z)\n");
	gotoxy(44, 8);
	printf("학교 시설 강화(x)\n");
	gotoxy(44, 9);
	printf("기능반 전직시키기(c)\n\n");
	gotoxy(44, 10);
	printf("----------------------");
}
//돈벌기 강화 소모비용 업데이트
void goldLvup() {
	makegold++;
	makegoldLvPrice += makegoldLvPrice + makegoldLV * 30;
	gold -= makegoldLvPrice;
}

//상점 기능
void shopfeature() {
	shop();
	int inputkey = "";
	do {
		inputkey = _getch();
		//노동력키우기
		if (inputkey == 'z' && gold > makegoldLvPrice) {
			gotoxy(46, 11);
			printf("노동력 레벨업!");
				goldLvup();
				shop();
			}
	} while (inputkey != 'q');
		
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
