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
void memberLogin(const vector<Member>& members) {
	string username, password;
	cout << "�̸�: ";
	cin >> username;
	cout << "��й�ȣ: ";
	cin >> password;

	bool checkMember = false;
	for (const auto& member : members) {
		if (member.username == username && member.password == password) {
			checkMember = true;
			cout << "�α��� ����!\n";
			break;
		}
	}
	if (checkMember == false) {
		cout << "�α��� ����! ó�� ȭ������ ���ư��ϴ�\n";
	}
}