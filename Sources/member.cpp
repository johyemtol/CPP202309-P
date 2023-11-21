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