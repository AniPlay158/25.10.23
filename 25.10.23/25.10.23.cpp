#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

/// <summary>
/// creating a class for day, month and year
/// </summary>

class DateTime
{
	int day;
	int month;
	int year;
	static time_t t;
	static struct tm* now;
public:
	/// <summary>
	/// function to get the value for the day variable
	/// </summary>
	/// <param name="day"> after checking, passes the value to the day variable</param>
	/// void PrintSystemTime()
	int PrintSystemHours() {
		return now->tm_hour;
	}

	int PrintSystemMinutes() {
		return now->tm_min;
	}

	int PrintSystemSeconds()
	{
		return now->tm_sec;
	}

	void SetDay(int day)
	{
		if (day > 0 && day <= 31)
		{
			this->day = day;
		}
		else
			cout << "Invalid value!" << endl;
	}

	/// <summary>
	/// function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the day function</returns>
	int GetDay() const
	{
		return day;
	}

	/// <summary>
	/// function to get the value for the month variable
	/// </summary>
	/// <param name="month">after checking, passes the value to the month variable</param>
	void SetMonth(int month)
	{
		if (month > 0 && month <= 12)
		{
			this->month = month;
		}
		else
			cout << "Invalid value!" << endl;
	}

	/// <summary>
	///  function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the month function</returns>
	int GetMonth() const
	{
		return month;
	}

	/// <summary>
	/// function to get the value for the year variable
	/// </summary>
	/// <param name="year">after checking, passes the value to the year variable</param>
	void SetYear(int year)
	{
		this->year = year;
	}

	/// <summary>
	///  function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the year function</returns>
	int GetYear() const
	{
		return year;
	}

	/// <summary>
	/// creating a constructor for a student with a delegation
	/// </summary>
	DateTime() : DateTime(23, 3, 2005) {}

	DateTime(int day, int month) : DateTime(day, month, 2004) {}

	DateTime(int day, int month, int year)
	{
		SetDay(day);
		SetMonth(month);
		SetYear(year);
	}

	/// <summary>
	/// function for printing data
	/// </summary>
	void Print() const
	{
		cout << day << "." << month << "." << year << endl;
	}
};
class Logger
{
	static Logger* instance; 
	DateTime* date_time;
	int log_сount = 0; 
	string path = "D:/log.txt";

	Logger() 
	{
	}

public:
	static Logger* GetInstance() 
	{
		return instance == nullptr ? instance = new Logger() : instance;
	}

	void Write(string message) 
	{
		log_сount++;
		int hours = date_time->PrintSystemHours(), minutes = date_time->PrintSystemMinutes(), seconds = date_time->PrintSystemSeconds();
		string time = to_string(hours);
		time += ':';
		time += to_string(minutes);
		time += ':';
		time += to_string(seconds);
		ofstream output_file(path, ios::app);
		if (output_file.is_open())
		{
			output_file << message << " in " << time << "\n";
			cout << message << " in " << time << '\n';
			output_file.close();
		}
		else
		{
			cerr << "Не удалось открыть файл для записи.";
		}
	}

	void Write(int value)
	{
		Write(to_string(value));
	}
};

/// <summary>
/// creating a student class
/// </summary>
class Student
{
	static int student_count;

	string surname;
	string name;
	string patronymic;
	string adress;
	string phone_number;
	DateTime birthday;
	DateTime study_start;

	int* hometask_rates = nullptr;
	int hometask_rates_count = 0;

	int* practice_rates = nullptr;
	int practice_rates_count = 0;

	int* exam_rates = nullptr;
	int exam_rates_count = 0;

	void SetBirthday(const DateTime& birthday)
	{
		this->birthday = birthday;
	}


public:


	Student(const Student& original)
	{
		student_count++;

		this->name = original.name;
		this->surname = original.surname;
		this->birthday = original.birthday;
		this->study_start = original.study_start;

		this->hometask_rates_count = original.hometask_rates_count;

		this->hometask_rates = new int[this->hometask_rates_count];
		for (int i = 0; i < this->hometask_rates_count; i++)
		{
			this->hometask_rates[i] = original.hometask_rates[i];
		}

		this->practice_rates_count = original.practice_rates_count;

		this->practice_rates = new int[this->practice_rates_count];
		for (int i = 0; i < this->practice_rates_count; i++)
		{
			this->practice_rates[i] = original.practice_rates[i];
		}

		this->exam_rates_count = original.exam_rates_count;

		this->exam_rates = new int[this->exam_rates_count];
		for (int i = 0; i < this->exam_rates_count; i++)
		{
			this->exam_rates[i] = original.exam_rates[i];
		}
		Logger::GetInstance()->Write("Student created at");

	}

	/// <summary>
	/// function to return birthday value
	/// </summary>
	/// <returns></returns>
	DateTime GetBirthday() const
	{
		return birthday;
	}

	/// <summary>
	/// function to get the value for the study start variable
	/// </summary>
	/// <param name="study_start">returns the value to the study start</param>
	void SetStudyStart(const DateTime& study_start)
	{
		this->study_start = study_start;
	}

	/// <summary>
	/// function to return study value
	/// </summary>
	/// <returns>returns the value that was written in the study function</returns>
	DateTime GetStudyStart() const
	{
		return study_start;
	}

	/// <summary>
	/// function to get the value for the name start variable
	/// </summary>
	/// <param name="name">returns the value to the name </param>
	void SetName(string name)
	{
		this->name = name;
	}

	/// <summary>
	/// function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the name function</returns>
	string GetName() const
	{
		return name;
	}

	/// <summary>
	/// function to get the value for the surname start variable
	/// </summary>
	/// <param name="surname">returns the value to the surname</param>
	void SetSurname(string surname)
	{
		this->surname = surname;
	}

	/// <summary>
	/// function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the surname function</returns>
	string GetSurname() const
	{
		return surname;
	}

	/// <summary>
	/// function to get the value for the surname variable
	/// </summary>
	/// <param name="patronymic">returns the value to the patronymic</param>
	void SetPatronymic(string patronymic)
	{
		this->patronymic = patronymic;
	}

	/// <summary>
	/// function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the patronymic function</returns>
	string GetPatronymic() const
	{
		return patronymic;
	}

	/// <summary>
	/// function to get the value for the adress variable
	/// </summary>
	/// <param name="adress">returns the value to the adress</param>
	void SetAdress(string adress)
	{
		this->adress = adress;
	}

	/// <summary>
	/// function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the adress function</returns>
	string GetAdress() const
	{
		return adress;
	}

	/// <summary>
	/// function to get the value for the phone number variable
	/// </summary>
	/// <param name="phone_number">adress">returns the value to the adress</param>
	void SetPhoneNumber(string phone_number)
	{
		if (phone_number.length() > 11 && phone_number.length() < 9)
		{
			cout << "Incorrect value for parameter rate. Value must be from 10" << endl;
			throw "ERROR!";
		}
		else
			this->phone_number = phone_number;
	}

	/// <summary>
	/// function to return a value to a variable
	/// </summary>
	/// <returns>returns the value that was written in the phone number function</returns>
	string GetPhoneNumber() const
	{
		return phone_number;
	}

	/// <summary>
	/// creating a constructor for a student with a delegation
	/// </summary>
	Student() : Student("Garfield", "Andrew", "Russell", "Baker street 221b", "617-254-8039")
	{
		Logger::GetInstance()->Write("Student created");
	}

	Student(string name) : Student(name, "Labida", "Oda", "Shkolnaya 987", "037-522-6725") {}

	Student(string name, string surname, string patronymic, string adress, string phone_number)
	{
		student_count++;
		cout << "Total count of students: " << student_count << "\n"; // 0

		if (student_count > 20)
		{
			throw "Error! too much students!";
		}

		SetSurname(name);
		SetName(surname);
		SetPatronymic(patronymic);
		SetAdress(adress);
		SetPhoneNumber(phone_number);
		SetBirthday({ 18, 7, 2003 });
		SetStudyStart({ 9, 10, 2023 });
		Logger::GetInstance()->Write("Student created");

	}

	/// <summary>
	/// creating a destructor to clean up memory
	/// </summary>
	~Student()
	{

		student_count--;

		if (hometask_rates != nullptr)
		{
			delete[] hometask_rates;
			hometask_rates = nullptr;
		}
		if (practice_rates != nullptr)
		{
			delete[] practice_rates;
			practice_rates = nullptr;
		}
		if (exam_rates != nullptr)
		{
			delete[] exam_rates;
			exam_rates = nullptr;
		}
		Logger::GetInstance()->Write("Student destroyed");

	}

	/// <summary>
	/// function for adding grades from homework to an array
	/// </summary>
	/// <param name="rate">writes the value to the variable rate</param>
	void AddHometaskRate(unsigned int rate)
	{
		if (rate < 1 || rate > 12)
		{
			cout << "Incorrect value for parameter rate. Value must be from 1 to 12" << endl;
			throw "ERROR!";
		}

		if (hometask_rates_count == 0)
		{
			hometask_rates = new int[1];
			hometask_rates[0] = rate;
		}
		else
		{
			int* temp = new int[hometask_rates_count + 1];
			for (int i = 0; i < hometask_rates_count; i++)
			{
				temp[i] = hometask_rates[i];
				temp[i + 1] = rate;
			}
			delete[] hometask_rates;
			hometask_rates = temp;
		}

		hometask_rates_count++;
	}

	/// <summary>
	/// function to get the value behind the index
	/// </summary>
	/// <param name="index">writes the value to the variable штвуч</param>
	/// <returns>returns index values</returns>
	int GetHometaskRateByIndex(unsigned int index)
	{
		if (index >= hometask_rates_count)
		{
			cout << "Incorrect index when accessing the evaluation array\n";
			throw "ERROR!";
		}
		return hometask_rates[index];
	}

	/// <summary>
	/// function to get the value behind count
	/// </summary>
	/// <returns>returns hometask rates count values</returns>
	int GetHometasksRatesCount() const
	{
		return hometask_rates_count;
	}

	/// <summary>
	/// function for adding grades from practice to an array
	/// </summary>
	/// <param name="rate">writes the value to the variable rate</param>
	void AddPracticRate(int rate)
	{
		if (rate < 1 || rate > 12)
		{
			cout << "Incorrect value for parameter rate. Value must be from 1 to 12" << endl;
			throw "ERROR!";
		}

		if (practice_rates_count == 0)
		{
			practice_rates = new int[1];
			practice_rates[0] = rate;
		}
		else
		{
			int* temp = new int[practice_rates_count + 1];
			for (int i = 0; i < practice_rates_count; i++)
			{
				temp[i] = practice_rates[i];
				temp[i + 1] = rate;
			}
			delete[] practice_rates;
			practice_rates = temp;
		}

		practice_rates_count++;
	}

	/// <summary>
	/// function to get the value behind count
	/// </summary>
	/// <returns>returns practice rates count values</returns>
	int GetPracticetasksRatesCount() const
	{
		return practice_rates_count;
	}

	/// <summary>
	/// function for adding grades from exam to an array
	/// </summary>
	/// <param name="rate">writes the value to the variable rate</param>
	void AddExamRate(int rate)
	{
		if (rate < 1 || rate > 12)
		{
			cout << "Incorrect value for parameter rate. Value must be from 1 to 12" << endl;
			throw "ERROR!";
		}

		if (exam_rates_count == 0)
		{
			exam_rates = new int[1];
			exam_rates[0] = rate;
		}
		else
		{
			int* temp = new int[exam_rates_count + 1];
			for (int i = 0; i < exam_rates_count; i++)
			{
				temp[i] = exam_rates[i];
				temp[i + 1] = rate;
			}
			delete[] exam_rates;
			exam_rates = temp;
		}

		exam_rates_count++;
	}

	/// <summary>
	/// function for adding grades from practice to an array
	/// </summary>
	/// <param name="rate">writes the value to the variable rate</param>
	int GetExamtasksRatesCount() const
	{
		return exam_rates_count;
	}

	int GetExamRateByIndex(unsigned int index) const
	{
		if (index >= exam_rates_count)
		{
			cout << "Incorrect index when accessing the exam rate array\n";
			throw "ERROR!";
		}
		return exam_rates[index];
	}

	/// <summary>
	/// function for printing homework grades
	/// </summary>
	void PrintHomeTaskRates() const
	{
		for (int i = 0; i < hometask_rates_count; i++)
		{
			cout << i + 1 << ")" << hometask_rates[i] << endl;
		}
	}

	/// <summary>
	/// function for printing grades for practice
	/// </summary>
	void PrintPracticeTaskRates() const
	{
		for (int i = 0; i < practice_rates_count; i++)
		{
			cout << i + 1 << ")" << practice_rates[i] << endl;
		}
	}

	/// <summary>
	/// function for printing exam grades
	/// </summary>
	void PrintExamTaskRates() const
	{
		for (int i = 0; i < exam_rates_count; i++)
		{
			cout << i + 1 << ")" << exam_rates[i] << endl;
		}
	}

	/// <summary>
	/// function for printing student details
	/// </summary>
	void Print() const // 9) добавил сведения про средний балл
	{
		cout << "Surname: " << surname << "\n";
		cout << "Name: " << name << "\n";
		cout << "Patronymic: " << patronymic << "\n";
		cout << "Address: " << adress << "\n";
		cout << "Phone number: " << phone_number << "\n";
		cout << "Average hometask rate: " << GetHometaskAverageRate() << "\n";
	}

	void PrintShort() const // 11) короткая распечатка
	{
		cout << surname << " " << name << ", average hometask rate: " << GetHometaskAverageRate() << "\n";
	}

	double GetHometaskAverageRate() const // 6) новый метод подсчёта среднего балла по ДЗ (это ответственность типа Студент)
	{
		if (hometask_rates_count == 0) return 0;

		double sum = 0;
		for (int i = 0; i < hometask_rates_count; i++)
		{
			sum += hometask_rates[i];
		}
		double average = sum / hometask_rates_count;
		return average;
	}

	int GetCountOfStudents() const
	{
		return student_count;
	}

};





/// <summary>
/// creating a group
/// </summary>




class Group
{
	static int count_groups;

	Student** students = nullptr; // 1) используется разреженный массив указателей вместо динамического массива объектов
	int count_of_students = 0;
	string name_group;
	int number_course;
	string specialization;


public:

	unsigned int GetCount() const
	{
		return count_of_students;
	}

	Group()
	{
		SetNameGroup(name_group);
		SetSpecializationGroup(specialization);
		SetNumberCourse(2);
		Logger::GetInstance()->Write("Group created");
	}

	Group(const Group& original)
	{
		this->count_of_students = original.count_of_students;
		this->name_group = original.name_group;
		this->specialization = original.specialization;
		this->number_course = original.number_course;

		this->students = new Student * [this->count_of_students]; // 2) память выделяется под массив указателей, а не объектов
		for (int i = 0; i < this->count_of_students; i++)
		{
			this->students[i] = original.students[i];
		}
		Logger::GetInstance()->Write("Group created");

	}

	~Group()
	{
		if (students != nullptr)
		{
			for (int i = 0; i < count_of_students; i++)
			{
				delete students[i]; // 3) каждый объект в массиве объектов должен быть удалён по отдельности
			}
			delete[] students;
			count_groups++;
			cout << "Total count of groups: " << count_groups << "\n";// потом чистится память от всего массива (уже указателей, а не объектов)
		}
		Logger::GetInstance()->Write("Group destroyed");

	}

	void SetNumberCourse(int number_course)
	{
		if (number_course > 0)
		{
			this->number_course = number_course;
		}
		else
		{
			cout << "Invalid value!" << endl;
			throw "ERROR!\n";
		}
	}

	int GetNumberCourse() const
	{
		return number_course;
	}

	void SetNameGroup(string name_group)
	{
		if (name_group != " ")
		{
			this->name_group = name_group;
		}
		else
		{
			cout << "Invalid value!" << endl;
			throw "ERROR!\n";
		}
	}

	string GetNameGroup() const
	{
		return name_group;
	}

	void SetSpecializationGroup(string specialization)
	{
		if (specialization != " ")
		{
			this->specialization = specialization;
		}
		else
		{
			cout << "Invalid value!" << endl;
			throw "ERROR!\n";
		}
	}

	string GetSpecializationGroup() const
	{
		return specialization;
	}

	int GetCountOfStudents() const
	{
		return count_of_students;
	}

	void AddStudent(const Student& new_student)
	{
		Student** temp = new Student * [count_of_students + 1];
		for (int i = 0; i < count_of_students; i++)
		{
			temp[i] = new Student(*students[i]); 
		}

		temp[count_of_students] = new Student(new_student);
		delete[] students;
		students = temp;
		count_of_students++;
	}

	void TransferStudent(Group& other, int index)
	{
		if (index >= 0 && index < count_of_students)
		{
			other.AddStudent(*students[index]);
			for (int i = index; i < count_of_students - 1; i++)
			{
				students[i] = students[i + 1];
			}
			count_of_students--;
		}
	}

	void MergeWithGroup(Group& another_group)
	{
		for (int i = 0; i < another_group.GetCountOfStudents(); i++)
		{
			this->AddStudent(another_group.GetStudentByIndex(i));
		}

		int k = another_group.GetCountOfStudents();
		for (int i = 0; i < k; i++)
		{
			another_group.RemoveStudentWithMinHomeworkAverage();
		}
	}

	void RemoveStudentsWithFailedExams()
	{
		for (int i = 0; i < count_of_students; i++)
		{
			if (students[i]->GetExamtasksRatesCount() > 0)
			{
				int minExamRate = students[i]->GetExamRateByIndex(0);
				for (int j = 1; j < students[i]->GetExamtasksRatesCount(); j++)
				{
					if (students[i]->GetExamRateByIndex(j) < minExamRate)
					{
						minExamRate = students[i]->GetExamRateByIndex(j);
					}
				}

				if (minExamRate < 3)
				{
					cout << "Removing student " << students[i]->GetName() << " " << students[i]->GetSurname() << " due to failed exams." << endl;
					for (int k = i; k < count_of_students - 1; k++)
					{
						students[k] = students[k + 1];
					}
					count_of_students--;
					i--;
				}
			}
		}
	}

	void RemoveStudentWithMinHomeworkAverage()
	{
		if (count_of_students == 0)
		{
			cout << "Group is empty. Cannot remove a student." << endl;
			return;
		}

		int lowestIndex = 0;
		double lowestAverage = students[0]->GetHometaskAverageRate(); // 7) теперь тут красивый вызов метода из класса Студент :)

		for (int i = 1; i < count_of_students; i++)
		{
			double currentAverage = students[i]->GetHometaskAverageRate();
			if (currentAverage < lowestAverage)
			{
				lowestAverage = currentAverage;
				lowestIndex = i;
			}
		}

		for (int i = lowestIndex; i < count_of_students - 1; i++)
		{
			students[i] = students[i + 1];
		}
		count_of_students--;

		//cout << "Removed student with the lowest homework average." << endl;
	}

	Student GetStudentByIndex(unsigned int index) const
	{
		if (index < count_of_students)
		{
			return *students[index];
		}
		else
		{
			cout << "Index out of bounds when accessing student array." << endl;
			throw "ERROR!";
		}
	}

	void PrintAllStudents()
	{
		cout << "Group name: " << name_group << "\n";
		cout << "Group specialization: " << specialization << "\n";
		cout << "Course: " << number_course << "\n";

		if (count_of_students == 0)
		{
			cout << "Group is empty (no students yet)\n";
			return; // если в группе нет студентов - на этом распечатка завершена
		}

		cout << "Students: \n";

		for (int i = 0; i < count_of_students - 1; i++)
		{
			for (int j = i + 1; j < count_of_students; j++)
			{
				if (students[j]->GetSurname() < students[i]->GetSurname())
				{
					Student* temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}

		for (int i = 0; i < count_of_students; i++)
		{
			cout << i + 1 << ") ";
			students[i]->PrintShort(); // 10) показываем всё инфо про студента
		}
		cout << "-------------------------------\n";
	}
};

string names[] = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hank", "Ivy", "Jack" };
string surnames[] = { "Smith", "Johnson", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Lewis", "Hill" };

int Group::count_groups = 0;
int Student::student_count = 0;
time_t DateTime::t = time(0);
tm* DateTime::now = localtime(&t);
Logger* Logger::instance = nullptr;
int main()
{
	Logger::GetInstance()->Write("Angelina logged in in");
	Group group;
	Student a;
	Student b;
	Student c;
	Logger::GetInstance()->Write("Angelina exited ");

	//Group group1;
	//group1.SetNameGroup("KND-221");
	//group1.SetSpecializationGroup("Designers");
	//group1.SetNumberCourse(2);

	//for (int i = 0; i < 5; i++)
	//{
	//	Student s(names[rand() % 10], surnames[rand() % 10], "", "", "");
	//	for (int ht = 0; ht < 5; ht++)
	//		s.AddHometaskRate(rand() % 12 + 1);
	//	for (int pr = 0; pr < 5; pr++)
	//		s.AddPracticRate(rand() % 12 + 1);
	//	for (int ex = 0; ex < 5; ex++)
	//		s.AddExamRate(rand() % 12 + 1);

	//	group1.AddStudent(s);
	//}

	//group1.PrintAllStudents();

	/*if (group1.GetCount() >= 7)
	{
		throw "ERROR!\n";
	}*/


	///////////////////////////////////////////////////

	/*Group group2;
	group2.SetNameGroup("KNP-222");
	group2.SetSpecializationGroup("Programmers");
	group2.SetNumberCourse(2);

	for (int i = 0; i < 5; i++)
	{
		Student s(names[rand() % 10], surnames[rand() % 10], "", "", "");
		for (int ht = 0; ht < 5; ht++)
			s.AddHometaskRate(rand() % 12 + 1);
		for (int pr = 0; pr < 5; pr++)
			s.AddPracticRate(rand() % 12 + 1);
		for (int ex = 0; ex < 5; ex++)
			s.AddExamRate(rand() % 12 + 1);

		group2.AddStudent(s);
	}

	group2.PrintAllStudents();*/

	/*group2.PrintAllStudents();

	if (group2.GetCount() >= 7)
	{
		throw "ERROR!\n";
	}*/

	///////////////////////////////////////////////////

	//group1.RemoveStudentWithMinHomeworkAverage();
	//group1.PrintAllStudents();
	//cout << endl;

	//group2.RemoveStudentWithMinHomeworkAverage();
	//group2.PrintAllStudents();

	/////////////////////////////////////////////////////

	//group1.RemoveStudentsWithFailedExams();
	//group1.PrintAllStudents();
	//cout << endl;

	//group2.RemoveStudentsWithFailedExams();
	//group2.PrintAllStudents();

	/////////////////////////////////////////////////////

	//group1.MergeWithGroup(group2);
	//group1.PrintAllStudents();
	//group2.PrintAllStudents();

}