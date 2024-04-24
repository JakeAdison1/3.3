#include <iostream>
#include <fstream>


using namespace std;

struct Student{
protected:
	char name[80];
	short course; 
	short mark;
public:
	void getData(int& first,int& second, int& third, int& four ) {
		
		cout << "Введите ФИО:"; cout << " "; cin >> name; cout << endl;
		cout << "Введите курс:"; cout << " "; cin >> course; cout << endl;
		cout << "Введите средний балл:"; cout << " "; cin >> mark; cout << endl;
		if (course == 1 && mark < 4) {
			first++;
		}
		
	
		if (course == 2 && mark < 4) {
			second++;
		}
		

		if (course == 3 && mark < 4) {
		third++;
		}
		
	
		if (course == 4 && mark < 4) {
			four ++;
		}
		
	
	}
	void showData() {
		cout << "ФИО:" << " " << name << endl << "Курс:" << " " << course << endl << "Средний балл:" << " " << mark << endl;
		
	}
	
	void input(Student& person, fstream& stud, char& ch) {
		int first=0,second=0,third=0, four=0;
		do {
			cout << "Введите данные о студенте:";
			cout << endl;
			person.getData(first, second, third, four);
			stud.write(reinterpret_cast<char*>(&person), sizeof(person));
			cout << "Продолжить ли ввод?(y/n):";
			cin >> ch;
			cout << endl;
		} while (ch == 'y');

		cout << "Студенты имеющие неудовлетворительные отметки по курсу:" << endl;
		cout << "Введите курс:";
		cin >> course;
		if (course == 1) {
			cout << "Кол-во неуспевающих на 1 курсе:";
			cout << first;
		}
		if (course == 2) {
			cout << "Кол-во неуспевающих на 2 курсе:";
			cout << second;
		}
		if (course == 3) {
			cout << "Кол-во неуспевающих на 3 курсе:";
			cout << third;
		}
		if (course == 4) {
			cout << "Кол-во неуспевающих на 4 курсе:";
			cout << four;
		}
		cout << endl;

	}

	void output(Student& person, fstream& stud) {
		cout << endl;
		cout << "Список введеных студентов:";
		cout << endl;
		while (!stud.eof()) {
			cout << "Person:"<<endl;
			person.showData();
			stud.read(reinterpret_cast<char*>(&person), sizeof(person));
		}
	}
};

int main() {
	int course;
	short mark;
	char ch;
	Student person;
	setlocale(LC_ALL, "RU");
	fstream stud;
	stud.open("students.txt", ios::in | ios::out | ios::app | ios::binary);
	while (!stud.is_open()) {
		cout << "Ошибка 1";
		return 1;
	}
	person.input(person, stud, ch);

	stud.seekg(0);//читаем данные о первом студенте
	stud.read(reinterpret_cast<char*>(&person), sizeof(person));
	person.output(person, stud);//читаем данные о следующих студентах
	cout << endl;
	cout << endl;





	stud.close();
	remove("students.txt");

}