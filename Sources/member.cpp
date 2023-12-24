#include "member.h"

//특별한 숫자 지정해서 볼수 있게 지정함
void memberSave(const vector<Member>& members) {
	for (const auto& member : members) {
		cout << "회원 이름: " << member.username << ", 회원 비밀번호: " << member.password << endl;
	}
}
//회원가입 함수
void memberJoin(vector<Member>& members) {
	Member newMember;
	cout << "이름: ";
	cin >> newMember.username;
	cout << "비밀번호: ";
	cin >> newMember.password;

	members.push_back(newMember);

	cout << "회원가입이 완료되었습니다!\n";
}

//로그인 함수
void memberLogin(const vector<Member>& members,UserSession& session) {
	string username, password;
	cout << "이름: ";
	cin >> username;
	cout << "비밀벌호: ";
	cin >> password;

	//회원 정보가 있을경우
	for (const auto& member : members) {
		if (member.username == username && member.password == password) {
			session.username = username;
			session.login = true;
			cout << "로그인 성공!\n";
			break;
		}
	}
	//회원 정보가 없을경우
	if (session.login == false) {
		cout << "로그인 실패! 처음 화면으로 돌아갑니다\n";
	}
}


//화면 띄우기
void memberDisplay() {
	cout << "\n------------------------------------\n";
	cout << "1. 1개월 이용권 60,000\n";
	cout << "2. 3개월 이용권 150,000\n";
	cout << "3. 6개월 이용권 250,000\n";
	cout << "4. 12개월 이용권 400,000\n";
	cout << "5. 하루 이용권 8,000\n";
	cout << "6. 1:1 PT 5회 이용권 + 1개월 이용권 150,000\n";
	cout << "7. 1:1 PT 10회 이용권 + 3개월 이용권 300,000\n";
	cout << "------------------------------------\n";

}

//이용권 가격 설정과 이용권 순위
void memberPrice(UserSession& session, map<int, int>& optionCounts){
	memberDisplay();
	int optionChoice;
	cout << "이용권을 선택하세요(1~7)\n";
	cout << "이용권 순위를 보고싶으면 10을 입력하시오";
	cin >> optionChoice;
	optionCounts[optionChoice]++;
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
	case 10:
		cout << "회원권 선택 횟수\n";
		for (const auto& count : optionCounts) {
			cout << "옵션 " << count.first << ": " << count.second << "회\n";
		}
		return;
	default:
		cout << "잘못된 선택입니다.\n";
		return;
	}

	cout << "선택한 이용권이 " << optionChoice << "번이고 가격이 " << price << "원입니다." << endl;
	PrintExpirationDate(optionChoice);

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


//멤버 찾을 수 있도록함
void memberSearch(const vector<Member>& members, const string& memberTarget) {
	bool found = false;

	for (const auto& member : members) {
		if (member.username == memberTarget) {
			cout << "회원 이름: " << member.username << ", 회원 비밀번호: " << member.password << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "해당하는 회원이 존재하지 않습니다." << endl;
	}
}


//만료일
system_clock::time_point CalculateExpirationDate(int months) {
	system_clock::time_point currentDate = system_clock::now();
	auto expirationDate = currentDate + months * hours(24 * 30);

	return expirationDate;
}

void PrintExpirationDate(int optionChoice) {
	system_clock::time_point expirationDate = CalculateExpirationDate(optionChoice);

	time_t expirationTime = system_clock::to_time_t(expirationDate);

	tm expirationTM;
	localtime_s(&expirationTM, &expirationTime);

	cout << "만료일: " << setfill('0') << setw(4) << expirationTM.tm_year + 1900 << '-'
		<< setw(2) << expirationTM.tm_mon + 1 << '-' << setw(2) << expirationTM.tm_mday << '\n';
}
