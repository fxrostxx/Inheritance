#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;


#define delimiter "\n---------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
private:
	static const int TYPE_WIDTH = 12;
	static const int NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static int count;
	std::string last_name;
	std::string first_name;
	int age;

public:
	static int get_count()
	{
		return count;
	}
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

		++count;

		cout << "HConstructor: " << this << endl;
	}
	virtual ~Human()
	{
		--count;

		cout << "HDestructor: " << this << endl;
	}

	virtual std::ostream& info(std::ostream& os) const
	{
		os << std::left;
		os.width(TYPE_WIDTH);
		os << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";
		os.width(NAME_WIDTH);
		os << last_name;
		os.width(NAME_WIDTH);
		os << first_name;
		os.width(AGE_WIDTH);
		os << age;
		return os;
	}
	virtual std::istream& scan(std::istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
};

int Human::count = 0;

std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return obj.info(os);
}
std::istream& operator>>(std::istream& is, Human& obj)
{
	return obj.scan(is);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student : public Human
{
private:
	static const int SPECIALITY_WIDTH = 32;
	static const int GROUP_WIDTH = 8;
	static const int RAT_WIDTH = 8;
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

	std::ostream& info(std::ostream& os) const override
	{
		Human::info(os);
		os << std::left;
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(GROUP_WIDTH);
		os << group;
		os.width(RAT_WIDTH);
		os << rating;
		os.width(RAT_WIDTH);
		os << attendance;
		return os;
	}
	std::istream& scan(std::istream& is) override
	{
		Human::scan(is);
		char sz_buffer[SPECIALITY_WIDTH + 1] = {};
		is.read(sz_buffer, SPECIALITY_WIDTH);

		for (int i = SPECIALITY_WIDTH - 1; sz_buffer[i] == ' '; --i) sz_buffer[i] = 0;
		while (sz_buffer[0] == ' ')
			for (int i = 0; sz_buffer[i]; ++i) sz_buffer[i] = sz_buffer[i + 1];

		speciality = sz_buffer;

		is >> group >> rating >> attendance;

		return is;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher : public Human
{
private:
	static const int SPECIALITY_WIDTH = 32;
	static const int EXPERIENCE_WIDTH = 5;
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

	std::ostream& info(std::ostream& os) const override
	{
		Human::info(os);
		os << std::left;
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(EXPERIENCE_WIDTH);
		os << experience;
		return os;
	}
	std::istream& scan(std::istream& is) override
	{
		Human::scan(is);
		char sz_buffer[SPECIALITY_WIDTH + 1] = {};
		is.read(sz_buffer, SPECIALITY_WIDTH);

		for (int i = SPECIALITY_WIDTH - 1; sz_buffer[i] == ' '; --i) sz_buffer[i] = 0;
		while (sz_buffer[0] == ' ')
			for (int i = 0; sz_buffer[i]; ++i) sz_buffer[i] = sz_buffer[i + 1];

		speciality = sz_buffer;

		is >> experience;

		return is;
	}
};

#define GRADUATE_TAKE_PARAMETERS const std::string& thesis_topic, const std::string& supervisor, int grade
#define GRADUATE_GIVE_PARAMETERS thesis_topic, supervisor, grade

class Graduate : public Student
{
private:
	static const int THESIS_WIDTH = 38;
	static const int SUPERVISOR_WIDTH = 22;
	static const int GRADE_WIDTH = 8;
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

	std::ostream& info(std::ostream& os) const override
	{
		Student::info(os);
		os << std::left;
		os.width(THESIS_WIDTH);
		os << thesis_topic;
		os.width(SUPERVISOR_WIDTH);
		os << supervisor;
		os.width(GRADE_WIDTH);
		return os;
	}
	std::istream& scan(std::istream& is) override
	{
		Student::scan(is);
		char tz_buffer[THESIS_WIDTH + 1] = {};
		is.read(tz_buffer, THESIS_WIDTH);

		for (int i = THESIS_WIDTH - 1; tz_buffer[i] == ' '; --i) tz_buffer[i] = 0;
		while (tz_buffer[0] == ' ')
			for (int i = 0; tz_buffer[i]; ++i) tz_buffer[i] = tz_buffer[i + 1];

		thesis_topic = tz_buffer;

		char sz_buffer[SUPERVISOR_WIDTH + 1] = {};
		is.read(sz_buffer, SUPERVISOR_WIDTH);

		for (int i = SUPERVISOR_WIDTH - 1; sz_buffer[i] == ' '; --i) sz_buffer[i] = 0;
		while (sz_buffer[0] == ' ')
			for (int i = 0; sz_buffer[i]; ++i) sz_buffer[i] = sz_buffer[i + 1];

		supervisor = sz_buffer;

		is >> grade;

		return is;
	}
};

void Print(Human* group[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		group[i]->info(cout);
		cout << delimiter << endl;
	}

	cout << "Количество объектов: " << group[0]->get_count() << endl;
	cout << "Количество объектов: " << Human::get_count() << endl;
}

void Save(Human* group[], const int size, const std::string& filename)
{
	std::ofstream fout(filename);

	for (int i = 0; i < size; ++i)
	{
		fout << *group[i] << endl;
	}

	fout.close();

	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
}

Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;

	if (strstr(type.c_str(), "Human")) human = new Human("", "", 0);
	else if (strstr(type.c_str(), "Student")) human = new Student("", "", 0, "", "", 0, 0);
	else if (strstr(type.c_str(), "Graduate")) human = new Graduate("", "", 0, "", "", 0, 0, "", "", 0);
	else if (strstr(type.c_str(), "Teacher")) human = new Teacher("", "", 0, "", 0);

	return human;
}

Human** Load(const std::string& filename, int& size)
{
	Human** group = nullptr;
	std::ifstream fin(filename);

	if (fin.is_open())
	{
		size = 0;
		std::string buffer;

		while (!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.size() < 32) continue;
			++size;
		}
		cout << "Количество объектов: " << size << endl;

		group = new Human*[size];

		cout << "Position " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Position " << fin.tellg() << endl;

		for (int i = 0; i < size;)
		{
			std::string buffer;

			std::getline(fin, buffer, ':');
			if (buffer.size() < 5) continue;
			group[i] = HumanFactory(buffer);
			fin >> *group[i];
			++i;
		}
	}
	else std::cerr << "Error: File not found" << endl;

	fin.close();

	return group;
}

void Clear(Human* group[], const int size)
{
	for (int i = 0; i < size; ++i) delete group[i];
}

//#define INHERITANCE
//#define POLYMORPHISM
//#define READ_FROM_FILE_OLD
#define READ_FROM_FILE

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

#ifdef POLYMORPHISM
	Human* group[]
	{
		new Student("Pincman", "Jessie", 22, "Chemistry", "WW_240", 99, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Boetticher", "Gale", 30, "Chemistry", "WW_240", 99.9, 100,
			"Advanced methamphetamine synthesis", "Gustavo Fring", 5),
		new Student("Verchetty", "Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	Print(group, sizeof(group) / sizeof(group[0]));

	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");

	Clear(group, sizeof(group) / sizeof(group[0]));
#endif // POLYMORPHISM

#ifdef READ_FROM_FILE_OLD
	int count{ 0 };
	const int size{ 10 };
	Human* group[size]{};

	std::ifstream fin("group.csv");

	if (fin.is_open())
	{
		while (!fin.eof() && count < size)
		{
			const int bsize{ 256 };
			char buffer[bsize]{};

			char* fields[15]{};
			int field_count{ 0 };

			fin.getline(buffer, bsize);

			for (char* token = strtok(buffer, ","); token && field_count < 10; token = strtok(NULL, ","))
				fields[field_count++] = token;

			if (field_count == 3) group[count++] = new Human(fields[0], fields[1], atoi(fields[2]));

			else if (field_count == 7) group[count++] = new Student
			(fields[0], fields[1], atoi(fields[2]), fields[3], fields[4], atof(fields[5]), atof(fields[6]));

			else if (field_count == 5) group[count++] = new Teacher
			(fields[0], fields[1], atoi(fields[2]), fields[3], atoi(fields[4]));

			else if (field_count == 10) group[count++] = new Graduate
			(fields[0], fields[1], atoi(fields[2]), fields[3], fields[4], atof(fields[5]), atof(fields[6]),
				fields[7], fields[8], atoi(fields[9]));
		}
	}
	else std::cerr << "Error: File not found" << endl;

	fin.close();

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); ++i)
	{
		if (group[i] != nullptr)
		{
			group[i]->info(cout);
			cout << delimiter << endl;
		}
	}

	for (int i = 0; i < count; ++i) delete group[i];
#endif // READ_FROM_FILE_OLD

#ifdef READ_FROM_FILE

	int size = 0;
	Human** group = Load("group.txt", size);

	Print(group, size);

	Clear(group, size);
#endif // READ_FROM_FILE


	return 0;
}