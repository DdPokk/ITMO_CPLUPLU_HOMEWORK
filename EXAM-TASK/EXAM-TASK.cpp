#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

//очистка потока
void cls() {
	cin.clear();
	cin.ignore(numeric_limits<int>::max(), '\n');
	cout << "uncorrect input" << endl;
}

//базовый класс
class Person {
protected:
	string fio; //ФИО
	string phone; //телефон
	int age; //возраст

public:

	//конструкторы
	Person(string fio, string phone, int age) {
		this->fio = fio;
		this->phone = phone;
		this->age = age;
	}

	Person() {
		fio = "_";
		phone = "_";
		age = 0;
	}

	//получаем фио
	string getFio() {
		return fio;
	}

	//ввод
	virtual void read() {
		cout << "input FIO: ";
		getchar();
		getline(cin, fio);
		cout << "input Phone: ";
		cin >> phone;
		cout << "input age: ";
		cin >> age;
	}

	//вывод
	virtual void show(ostream& out) {
		out << "FIO: " << fio << endl;
		out << "Phone: " << phone << endl;
		out << "Age: " << age << endl;
	}
};

//студент (наследует функционал базового класса)
class Student : public Person {
private:
	string group; //группа обучения
	int rating[3]; //оценки за сессию

public:

	//конструкторы
	Student() {
		group = "_";
		rating[0] = rating[1] = rating[2] = 0;
	}

	Student(string fio, string phone, int age, string group) : Person(fio, phone, age) {
		this->group = group;
		rating[0] = rating[1] = rating[2] = 0;
	}

	//ввод
	void read() override {
		cout << "<- Student ->" << endl;
		Person::read();
		if (cin.fail()) {
			cls();
			age = 0;
		}
		cout << "input Group: ";
		cin >> group;
		rating[0] = rating[1] = rating[2] = 0;
	}

	//переопределяем вывод
	void show(ostream& out) override {
		out << "<- Student ->" << endl;
		Person::show(out);
		out << "Group: " << group << endl;
		out << "Rating: " << rating[0] << ", " << rating[1] << ", " << rating[2] << endl;
	}

	//возможность изменить значение в массиве оценок
	void setRating(int i, int value) {
		rating[i] = value;
	}
};

//все дисциплины
enum class Subjects {
	maths = 0, //математика
	informatics, //информатика
	english //английский язык
};

//учитель
class Teacher : public Person {
private:
	Subjects subject; //дисциплина, которую преподает
	string tsubject; //расшифровка дисциплины
	float salary; //оклад

public:

	//конструкторы
	Teacher() : Person() {
		tsubject = "maths";
		subject = Subjects::maths;
		salary = 0.0f;
	}

	Teacher(string fio, string phone, int age, int sub, float salary) : Person(fio, phone, age) {
		setSub(sub);
		this->salary = salary;
	}

	//поставить оценку студенту по текущему предмету (агрегация)
	void setRating(Student* s, int rating) {
		s->setRating((int)subject, rating);
	}

	//установка предмета
	void setSub(int sub) {
		if (sub == 1) {
			tsubject = "maths";
			subject = Subjects::maths;
		}
		else if (sub == 2) {
			tsubject = "informatics";
			subject = Subjects::informatics;
		}
		else {
			tsubject = "english";
			subject = Subjects::english;
		}
	}

	//получаем
	int getSub() {
		return (int)subject + 1;
	}

	//ввод
	void read() override {
		cout << "<- Teacher ->" << endl;
		Person::read();
		if (!cin.fail()) {
			int sub;
			cout << "choice subject:" << endl;
			cout << "1 - maths" << endl;
			cout << "2 - informatics" << endl;
			cout << "3 - english" << endl;
			cout << ">> ";
			cin >> sub;
			if (cin.fail()) {
				cls();
				sub = 1;
			}
			setSub(sub);
			cout << "input salary: ";
			cin >> salary;
			if (cin.fail()) {
				cls();
				salary = 0.0f;
			}
			else if (salary < 0) {
				salary = 0.0f;
			}
		}
	}

	//вывод
	void show(ostream& out) override {
		out << "<- Teacher ->" << endl;
		Person::show(out);
		out << "Subject: " << tsubject << endl;
		out << "Salary: " << salary << endl;
	}
};

//адресная книга
class ABook {
private:
	vector<Person*> mas; //список абонентов

public:

	//конструктор
	ABook() {}

	//создание коллекции
	void create() {
		int size;
		cout << "input size = ";
		cin >> size;
		if (cin.fail()) {
			return;
		}
		if (size <= 0) {
			cout << "uncorrect input" << endl;
			return;
		}

		//удаляем старые данные если есть
		for (int i = 0; i < mas.size(); i++) {
			delete mas[i];
		}
		mas.clear();
		mas.resize(size);

		//запись данных о людях в массив
		int choice;
		for (int i = 0; i < size; i++) {
			cout << "1 - Student" << endl;
			cout << "2 - Teacher" << endl;
			cout << ">> ";
			cin >> choice;
			if (cin.fail()) {
				cls();
				choice = 1;
			}
			cout << endl;
			if (choice == 1) {
				Student* s = new Student();
				s->read();
				mas[i] = s;
			}
			else {
				Teacher* t = new Teacher();
				t->read();
				mas[i] = t;
			}
			cout << endl;
		}
	}

	//добавление нового объекта
	void add(Person* p) {
		mas.push_back(p);
	}

	//ставим оценку студенту преподавателем по фио (для ассоциации)
	void update() {
		if (mas.size() == 0) {
			cout << "collection is empty" << endl;
			return;
		}
		string fio;
		cout << "input fio student: ";
		getchar();
		getline(cin, fio);
		int idx1 = -1;
		for (int i = 0; i < mas.size(); i++) {
			//по первому вхождению
			if (mas[i]->getFio().find(fio) != string::npos && string(typeid(*mas[i]).name()).compare("class Student") == 0) {
				idx1 = i;
				break;
			}
		}
		if (idx1 != -1) {
			int sub;
			cout << "choice subject:" << endl;
			cout << "1 - maths" << endl;
			cout << "2 - informatics" << endl;
			cout << "3 - english" << endl;
			cout << ">> ";
			cin >> sub;
			if (cin.fail()) {
				cls();
				sub = 1;
			}
			//ищем преподавателя, который может принять предмет у найденного студента
			int idx2 = -1;
			for (int i = 0; i < mas.size(); i++) {
				if (string(typeid(*mas[i]).name()).compare("class Teacher") == 0) {
					Teacher* t = (Teacher*)mas[i];
					if (t->getSub() == sub) {
						idx2 = i;
						break;
					}
				}
			}
			if (idx2 != -1) {
				int rating;
				do {
					cout << "input rating: ";
					cin >> rating;
					if (cin.fail()) {
						cls();
					}
					else if (rating <= 0 || rating > 5) {
						cout << "uncorrect input" << endl;
					}
					else
						break;
					cout << endl;
				} while (1);
				((Teacher*)mas[idx2])->setRating((Student*)mas[idx1], rating);
				cout << "rating has been changed" << endl;
			}
			else {
				cout << "can't find Teacher..." << endl;
			}
		}
		else {
			cout << "can't find Student..." << endl;
		}
	}

	//вывод массива
	void show(ostream& out) {
		if (mas.size() == 0) {
			cout << "collection is empty" << endl;
			return;
		}
		for (int i = 0; i < mas.size(); i++) {
			mas[i]->show(out);
			out << endl;
		}
	}

	//сохранение в файл
	void save(string file) {
		if (mas.size() == 0) {
			cout << "collection is empty" << endl;
			return;
		}
		ofstream out(file);
		show(out);
	}

	//деструктор
	~ABook() {
		for (int i = 0; i < mas.size(); i++) {
			delete mas[i];
		}
	}
};

//меню
class Menu {
public:

	//меню
	void menu() {
		cout << "1 - create new collection" << endl;
		cout << "2 - show all" << endl;
		cout << "3 - update rating" << endl;
		cout << "4 - save in file" << endl;
		cout << "5 - exit" << endl;
		cout << ">> ";
	}

	//основной цикл
	void update() {
		int choice = 0;
		ABook bk;

		//заполняем начальными данными для тестирования
		bk.add(new Teacher("Ivanov Ivan Ivanovich", "123", 33, 1, 1500));
		bk.add(new Teacher("Leonov Sergey Nikolaevich", "153", 45, 2, 1800));
		bk.add(new Teacher("Markova Anna Vladimirovna", "153", 39, 3, 2300));
		bk.add(new Student("Barkova Inna Olegovna", "512", 22, "MK101"));
		bk.add(new Student("Smirnov Oleg Sergeevich", "341", 24, "MK102"));
		bk.add(new Student("Karpov Nikolay Alexeevich", "446", 26, "MK104"));

		do {
			menu();
			cin >> choice;
			switch (choice) {
			case 1: {
				bk.create();
				break;
			}
			case 2: {
				cout << endl;
				bk.show(cout);
				break;
			}
			case 3: {
				bk.update();
				break;
			}
			case 4: {
				bk.save("result.txt");
				cout << "collection was saved in result.txt file" << endl;
				break;
			}
			}
			//проверка ввода
			if (cin.fail()) {
				cls();
			}
			cout << endl;
		} while (choice != 5);
	}
};

//основная функция
int main() {
	Menu m;
	m.update();
	system("pause");
	return 0;
}