#include "member.h"

int main() {
	int choice=0;
	vector<Member> members;
	UserSession session;

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
			memberLogin(members,session);
			break;
		case 3:
			if (session.login==true) {
				cout << session.username << "�� �̿���� �Ұ����ְڽ��ϴ�.\n";
				int ticketchoice=0;
				cout << "1. 1���� �̿�� 60,000\n";
				cout << "2. 3���� �̿�� 150,000\n";
				cout << "3. 6���� �̿�� 250,000\n";
				cout << "4. 12���� �̿�� 400,000\n";
				cout << "5. �Ϸ� �̿�� 8,000\n";
				cout << "6. 1:1 PT 5ȸ �̿�� + 1���� �̿�� 150,000\n";
				cout << "7. 1:1 PT 10ȸ �̿�� + 3���� �̿�� 300,000\n";
				cout << "�̿���� ���ڷ� ���� �ٶ��ϴ�: ";
				cin >> ticketchoice;
			}
			else {
				cout << "�α����� �ʿ��� ����Դϴ�!\n";
			}
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