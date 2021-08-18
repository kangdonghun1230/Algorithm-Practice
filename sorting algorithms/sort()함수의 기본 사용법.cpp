/*
* @brief C++ STL sort() ������ ������ ���� �ڵ�
* @date 2021/08/11
* @author ������
* @parameter nothing
* @return nothing
* @big O N*logN (���� �ð����⵵�� algorithm �� ���� �����ϴ�.)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/*
�ǹ������� �ڷ������� ��ü�� �ַ� �ٷ�� ������
�ܼ� ������ �ϴ� ���� ���� ����.

���� �ǹ������� �����ϰ� ��ü�� �����
������ �ϴ� ��츦 �˾ƺ����� ����.
*/

class Student {
public:
	string name;
	int score;

	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	// �ٸ� �л��� ��ü�� ���� �� �� ������ �� ���ٸ� �켱������ ����.
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

// �츮�� ������ �Լ��� ������ �ǵ��Ѵ�� �۵���ų �� �ִ�.
bool compare(int a, int b) {
	return a < b;
}

int main() {
	Student students[] = {
		Student("������", 90),
		Student("���Ͽ�", 80),
		Student("������", 100),
		Student("���¿�", 70)
	};

	sort(students, students + 4);

	for (int i = 0; i < 4; i++) {
		cout << students[i].name << " " << students[i].score << endl;
	}

	return 0;
}