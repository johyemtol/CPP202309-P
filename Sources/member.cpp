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