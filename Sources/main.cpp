#include "member.h"

int main() {
	int choice=0;
	vector<Member> members;
	UserSession session;

	while (choice!=4) {
		cout << "1~4까지 선택바랍니다\n";
		cout << "1. 회원가입\n";
		cout << "2. 로그인\n";
		cout << "3. 이용권\n";
		cout << "4. 종료\n";
		cin >> choice;

		switch (choice) {
		case 1:
			memberJoin(members);
			break;
		case 2:
			memberLogin(members,session);
			break;
		case 3:
			if (session.login==true) {
				cout << session.username << "님 이용권을 소개해주겠습니다.\n";
				int ticketchoice=0;
				cout << "1. 1개월 이용권 60,000\n";
				cout << "2. 3개월 이용권 150,000\n";
				cout << "3. 6개월 이용권 250,000\n";
				cout << "4. 12개월 이용권 400,000\n";
				cout << "5. 하루 이용권 8,000\n";
				cout << "6. 1:1 PT 5회 이용권 + 1개월 이용권 150,000\n";
				cout << "7. 1:1 PT 10회 이용권 + 3개월 이용권 300,000\n";
				cout << "이용권을 숫자로 선택 바랍니다: ";
				cin >> ticketchoice;
			}
			else {
				cout << "로그인이 필요한 기능입니다!\n";
			}
			break;
		case 4:
			cout << "종료합니다.\n";
			break;
		case 38:
			memberSave(members);
			break;
		default:
			cout << "잘못된 선택입니다. 다시 선택 바랍니다,\n";
		}
	}


}