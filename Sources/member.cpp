#include "member.h"

//특별한 숫자 지정해서 볼수 있게 지정함
void memberSave(const vector<Member>& members) {
	for (const auto& member : members) {
		cout << "회원 이름: " << member.username << ", 회원 비밀번호: " << member.password << endl;
	}
}
void memberJoin(vector<Member>& members) {
	Member newMember;
	cout << "이름: ";
	cin >> newMember.username;
	cout << "비밀번호: ";
	cin >> newMember.password;

	members.push_back(newMember);

	cout << "회원가입이 완료되었습니다!\n";
}
void memberLogin(const vector<Member>& members,UserSession& session) {
	string username, password;
	cout << "이름: ";
	cin >> username;
	cout << "비밀벌호: ";
	cin >> password;

	for (const auto& member : members) {
		if (member.username == username && member.password == password) {
			session.username = username;
			session.login = true;
			cout << "로그인 성공!\n";
			break;
		}
	}
	if (session.login == false) {
		cout << "로그인 실패! 처음 화면으로 돌아갑니다\n";
	}
}

void memberDisplay() {
	cout << "1. 1개월 이용권 60,000\n";
	cout << "2. 3개월 이용권 150,000\n";
	cout << "3. 6개월 이용권 250,000\n";
	cout << "4. 12개월 이용권 400,000\n";
	cout << "5. 하루 이용권 8,000\n";
	cout << "6. 1:1 PT 5회 이용권 + 1개월 이용권 150,000\n";
	cout << "7. 1:1 PT 10회 이용권 + 3개월 이용권 300,000\n";
}

void memberPrice(UserSession& session) {
	memberDisplay();
	int optionChoice;
	cout << "이용권을 선택하세요(1~7)";
	cin >> optionChoice;
	int price;
	switch (optionChoice) {
	case 1:
		price = 60000;
		break;
	case 2:
		price = 150000;
		break;
	case 3:
		price = 250000;
		break;
	case 4:
		price = 400000;
		break;
	case 5:
		price = 8000;
		break;
	case 6:
		price = 150000;
		break;
	case 7:
		price = 300000;
		break;
	default:
		cout << "잘못된 선택입니다.\n";
		return;
	}
	cout << "선택한 이용권이 " << optionChoice << "번이고 가격이 " << price << "원입니다." << endl;

	cout << "<결제 방법> \n";
	cout << "1. 신용카드";
	cout << "2.계좌이체\n";

	int payChoice;
	cout << "결제 방법을 선택하세요(1 또는 2): ";
	cin >> payChoice;
	if (payChoice == 1 || payChoice == 2) {
		cout << "결제 진행중입니다." << endl;
		cout << "결제가 완료되었습니다." << endl;
	}
}