/*
* @brief C++ STL sort() 개념을 익히기 위한 코드
* @date 2021/08/11
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O N*logN (같은 시간복잡도의 algorithm 중 가장 강력하다.)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/*
실무에서는 자료형으로 객체를 주로 다루기 때문에
단순 정렬을 하는 경우는 거의 없다.

따라서 실무에서와 유사하게 객체를 만들어
정렬을 하는 경우를 알아보도록 하자.
*/

class Student {
public:
	string name;
	int score;

	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	// 다른 학생의 객체와 비교할 때 내 점수가 더 낮다면 우선순위가 높다.
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

// 우리가 정의한 함수로 정렬을 의도한대로 작동시킬 수 있다.
bool compare(int a, int b) {
	return a < b;
}

int main() {
	Student students[] = {
		Student("강동훈", 90),
		Student("김하영", 80),
		Student("공혜원", 100),
		Student("김태욱", 70)
	};

	sort(students, students + 4);

	for (int i = 0; i < 4; i++) {
		cout << students[i].name << " " << students[i].score << endl;
	}

	return 0;
}