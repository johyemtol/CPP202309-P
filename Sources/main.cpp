#include "member.h"

int main() {
	int choice=0;
	vector<Member> members;

	while (choice!=4) {
		cout << "1~4���� ���ùٶ��ϴ�\n";
		cout << "1. ȸ������\n";
		cout << "2. �α���\n";
		cout << "3. �̿��\n";
		cout << "4. ����\n";
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
			cout << "�����մϴ�.\n";
			break;
		case 38:
			memberSave(members);
			break;
		default:
			cout << "�߸��� �����Դϴ�. �ٽ� ���� �ٶ��ϴ�,\n";
		}
	}


}