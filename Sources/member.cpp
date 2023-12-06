#include "member.h"

//Ư���� ���� �����ؼ� ���� �ְ� ������
void memberSave(const vector<Member>& members) {
	for (const auto& member : members) {
		cout << "ȸ�� �̸�: " << member.username << ", ȸ�� ��й�ȣ: " << member.password << endl;
	}
}
void memberJoin(vector<Member>& members) {
	Member newMember;
	cout << "�̸�: ";
	cin >> newMember.username;
	cout << "��й�ȣ: ";
	cin >> newMember.password;

	members.push_back(newMember);

	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�!\n";
}
void memberLogin(const vector<Member>& members,UserSession& session) {
	string username, password;
	cout << "�̸�: ";
	cin >> username;
	cout << "��й�ȣ: ";
	cin >> password;

	for (const auto& member : members) {
		if (member.username == username && member.password == password) {
			session.username = username;
			session.login = true;
			cout << "�α��� ����!\n";
			break;
		}
	}
	if (session.login == false) {
		cout << "�α��� ����! ó�� ȭ������ ���ư��ϴ�\n";
	}
}

void memberDisplay() {
	cout << "1. 1���� �̿�� 60,000\n";
	cout << "2. 3���� �̿�� 150,000\n";
	cout << "3. 6���� �̿�� 250,000\n";
	cout << "4. 12���� �̿�� 400,000\n";
	cout << "5. �Ϸ� �̿�� 8,000\n";
	cout << "6. 1:1 PT 5ȸ �̿�� + 1���� �̿�� 150,000\n";
	cout << "7. 1:1 PT 10ȸ �̿�� + 3���� �̿�� 300,000\n";
}

void memberPrice(UserSession& session) {
	memberDisplay();
	int optionChoice;
	cout << "�̿���� �����ϼ���(1~7)";
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
		cout << "�߸��� �����Դϴ�.\n";
		return;
	}
	cout << "������ �̿���� " << optionChoice << "���̰� ������ " << price << "���Դϴ�." << endl;

	cout << "<���� ���> \n";
	cout << "1. �ſ�ī��";
	cout << "2.������ü\n";

	int payChoice;
	cout << "���� ����� �����ϼ���(1 �Ǵ� 2): ";
	cin >> payChoice;
	if (payChoice == 1 || payChoice == 2) {
		cout << "���� �������Դϴ�." << endl;
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	}
}