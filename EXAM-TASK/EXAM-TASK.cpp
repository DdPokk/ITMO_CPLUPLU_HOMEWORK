#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

//������� ������
void cls() {
	cin.clear();
	cin.ignore(numeric_limits<int>::max(), '\n');
	cout << "uncorrect input" << endl;
}

//������� �����
class Person {
protected:
	string fio; //���
	string phone; //�������
	int age; //�������

public:

	//������������
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

	//�������� ���
	string getFio() {
		return fio;
	}

	//����
	virtual void read() {
		cout << "input FIO: ";
		getchar();
		getline(cin, fio);
		cout << "input Phone: ";
		cin >> phone;
		cout << "input age: ";
		cin >> age;
	}

	//�����
	virtual void show(ostream& out) {
		out << "FIO: " << fio << endl;
		out << "Phone: " << phone << endl;
		out << "Age: " << age << endl;
	}
};

//������� (��������� ���������� �������� ������)
class Student : public Person {
private:
	string group; //������ ��������
	int rating[3]; //������ �� ������

public:

	//������������
	Student() {
		group = "_";
		rating[0] = rating[1] = rating[2] = 0;
	}

	Student(string fio, string phone, int age, string group) : Person(fio, phone, age) {
		this->group = group;
		rating[0] = rating[1] = rating[2] = 0;
	}

	//����
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

	//�������������� �����
	void show(ostream& out) override {
		out << "<- Student ->" << endl;
		Person::show(out);
		out << "Group: " << group << endl;
		out << "Rating: " << rating[0] << ", " << rating[1] << ", " << rating[2] << endl;
	}

	//����������� �������� �������� � ������� ������
	void setRating(int i, int value) {
		rating[i] = value;
	}
};

//��� ����������
enum class Subjects {
	maths = 0, //����������
	informatics, //�����������
	english //���������� ����
};

//�������
class Teacher : public Person {
private:
	Subjects subject; //����������, ������� ���������
	string tsubject; //����������� ����������
	float salary; //�����

public:

	//������������
	Teacher() : Person() {
		tsubject = "maths";
		subject = Subjects::maths;
		salary = 0.0f;
	}

	Teacher(string fio, string phone, int age, int sub, float salary) : Person(fio, phone, age) {
		setSub(sub);
		this->salary = salary;
	}

	//��������� ������ �������� �� �������� �������� (���������)
	void setRating(Student* s, int rating) {
		s->setRating((int)subject, rating);
	}

	//��������� ��������
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

	//��������
	int getSub() {
		return (int)subject + 1;
	}

	//����
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

	//�����
	void show(ostream& out) override {
		out << "<- Teacher ->" << endl;
		Person::show(out);
		out << "Subject: " << tsubject << endl;
		out << "Salary: " << salary << endl;
	}
};

//�������� �����
class ABook {
private:
	vector<Person*> mas; //������ ���������

public:

	//�����������
	ABook() {}

	//�������� ���������
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

		//������� ������ ������ ���� ����
		for (int i = 0; i < mas.size(); i++) {
			delete mas[i];
		}
		mas.clear();
		mas.resize(size);

		//������ ������ � ����� � ������
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

	//���������� ������ �������
	void add(Person* p) {
		mas.push_back(p);
	}

	//������ ������ �������� �������������� �� ��� (��� ����������)
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
			//�� ������� ���������
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
			//���� �������������, ������� ����� ������� ������� � ���������� ��������
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

	//����� �������
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

	//���������� � ����
	void save(string file) {
		if (mas.size() == 0) {
			cout << "collection is empty" << endl;
			return;
		}
		ofstream out(file);
		show(out);
	}

	//����������
	~ABook() {
		for (int i = 0; i < mas.size(); i++) {
			delete mas[i];
		}
	}
};

//����
class Menu {
public:

	//����
	void menu() {
		cout << "1 - create new collection" << endl;
		cout << "2 - show all" << endl;
		cout << "3 - update rating" << endl;
		cout << "4 - save in file" << endl;
		cout << "5 - exit" << endl;
		cout << ">> ";
	}

	//�������� ����
	void update() {
		int choice = 0;
		ABook bk;

		//��������� ���������� ������� ��� ������������
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
			//�������� �����
			if (cin.fail()) {
				cls();
			}
			cout << endl;
		} while (choice != 5);
	}
};

//�������� �������
int main() {
	Menu m;
	m.update();
	system("pause");
	return 0;
}