#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n---------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
private:
	std::string last_name;
	std::string first_name;
	int age;

public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{
		return first_name;
	}
	int get_age() const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);

		cout << "HConstructor: " << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor: " << this << endl;
	}

	virtual void info() const
	{
		cout << last_name << ' ' << first_name << ' ' << age << endl;
	}
};

std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << ' ' << obj.get_first_name() << ' ' << obj.get_age();
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student : public Human
{
private:
	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality() const
	{
		return speciality;
	}
	const std::string& get_group() const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	double get_attendance() const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) : Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);

		cout << "SConstructor: " << this << endl;
	}
	~Student()
	{
		cout << "SDestructor: " << this << endl;
	}

	void info() const override
	{
		Human::info();
		cout << speciality << ' ' << group << ' ' << attendance << endl;
	}
};

std::ostream& operator<< (std::ostream& os, const Student& obj)
{
	return os << (Human&)obj << ' ' << obj.get_speciality() << ' ' << obj.get_group() << ' ' << obj.get_rating() << ' ' << obj.get_attendance();
}

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher : public Human
{
private:
	std::string speciality;
	int experience;

public:
	const std::string& get_speciality() const
	{
		return speciality;
	}
	int get_experience() const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) : Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);

		cout << "TConstructor: " << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor: " << this << endl;
	}

	void info() const override
	{
		Human::info();
		cout << speciality << ' ' << experience << endl;
	}
};

std::ostream& operator<< (std::ostream& os, const Teacher& obj)
{
	return os << (Human&)obj << ' ' << obj.get_speciality() << ' ' << obj.get_experience();
}

#define GRADUATE_TAKE_PARAMETERS const std::string& thesis_topic, const std::string& supervisor, int grade
#define GRADUATE_GIVE_PARAMETERS thesis_topic, supervisor, grade

class Graduate : public Student
{
private:
	std::string thesis_topic;
	std::string supervisor;
	int grade;
public:
	const std::string& get_thesis_topic() const
	{
		return thesis_topic;
	}
	const std::string& get_supervisor() const
	{
		return supervisor;
	}
	int get_grade() const
	{
		return grade;
	}
	void set_thesis_topic(const std::string& thesis_topic)
	{
		this->thesis_topic = thesis_topic;
	}
	void set_supervisor(const std::string& supervisor)
	{
		this->supervisor = supervisor;
	}
	void set_grade(int grade)
	{
		this->grade = grade;
	}

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
		: Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_thesis_topic(thesis_topic);
		set_supervisor(supervisor);
		set_grade(grade);

		cout << "GConstructor: " << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor: " << this << endl;
	}

	void info() const override
	{
		Student::info();
		cout << thesis_topic << ' ' << supervisor << ' ' << grade << endl;
	}
};

std::ostream& operator<< (std::ostream& os, const Graduate& obj)
{
	return os << (Student&)obj << ' ' << obj.get_thesis_topic() << ' ' << obj.get_supervisor() << ' ' << obj.get_grade();
}

//#define INHERITANCE
#define POLYMORPHISM

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pincman", "Jessie", 22, "Chemistry", "WW_240", 99, 95);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate graduate("Boetticher", "Gale", 30, "Chemistry", "WW_240", 99.9, 100,
		"Advanced methamphetamine synthesis", "Gustavo Fring", 5);
	graduate.info();
#endif // INHERITANCE

	std::ofstream fout("group.txt");

	Human* group[]
	{
		new Student("Pincman", "Jessie", 22, "Chemistry", "WW_240", 99, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Boetticher", "Gale", 30, "Chemistry", "WW_240", 99.9, 100,
			"Advanced methamphetamine synthesis", "Gustavo Fring", 5),
		new Student("Verchetty", "Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); ++i)
	{
		group[i]->info();

		if (typeid(*group[i]) == typeid(Human)) fout << *group[i] << endl;
		if (typeid(*group[i]) == typeid(Student)) fout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher)) fout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate)) fout << *dynamic_cast<Graduate*>(group[i]) << endl;

		cout << delimiter << endl;
	}

	fout.close();

	system("start notepad group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); ++i)
	{
		delete group[i];
	}

	return 0;
}