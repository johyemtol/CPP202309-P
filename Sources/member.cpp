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