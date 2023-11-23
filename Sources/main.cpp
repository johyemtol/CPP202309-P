#include "member.h"

int main() {
	int choice=0;
	vector<Member> members;

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
			memberLogin(members);
			break;
		case 3:
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