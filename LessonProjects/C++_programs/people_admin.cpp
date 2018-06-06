#include<iostream>
#include<string>
using namespace std;
#define REDUCE 10;

static int Grades[] = { 500,600,750,1000,1400,2000,2800,4000 };

class employee {
protected:
	string name;  //姓名
	int ID;//职工号
	int grade;//工资级别
	double salary;//月
	double base_salary;//基本月薪
	double career_salary;//业绩工资
public:
	employee(string a= "", int i= 0, int j= 0) {
		name = a;
		ID = i;
		grade = Grades[j];
		base_salary = grade;
		career_salary = 0;
	};
	virtual void pay();//月薪计算函数
	void show() {cout<<"雇员信息："<< name << '\t' << ID << '\t' << grade << '\t' << salary << endl; };
	double getsalary() { return salary; }
	double getbase_salary() { return base_salary; }
	double getcareer_salary() { return career_salary; }
};

void employee::pay() {
	cout << "请输入请假天数： ";
	int day;
	cin >> day;
	salary = base_salary + career_salary - day * REDUCE;
	cout<<endl;
	cout << "employee 月薪是： " << salary << endl;
}

class technician :virtual public employee
{
protected:
	int hour; //当月工作时数
	double addition_sa;//附加酬金
public:
	technician(string a = "", int i = 0, int j = 0, int k = 0, double l= 0) :employee(a, i, j) {
		hour = k;
		addition_sa = l;
		career_salary = hour * addition_sa;
		salary = base_salary + career_salary;
	}
		void pay() {
		cout << "technician 月薪是： " << salary << endl;
	}
};

class manager :virtual public  employee
{
protected:
	double reward;
public:
	manager(string a="", int i = 0, int j = 0, double reward=0) :employee(a, i, j) {
		this->reward = reward;
		career_salary = reward;
		salary = base_salary + career_salary;
	}
	void pay() {
		cout << "manager 月薪是： " << salary << endl;
	}

};

class saler :virtual public  employee
{
protected:
	double total;
public:
	saler(string a = "", int i = 0, int j = 0, double total=0) :employee(a, i, j) 
	{
		this->total = total;
		career_salary = total * 0.1;
		salary = base_salary + career_salary;
	}
	void pay() {

		cout << "saler 月薪是： " << salary << endl;
	}
};

int main()
{
	employee em_person("Peng Tsinv", 1, 0);
	technician tech_person("Peng Tsinv", 1, 0);
	saler sal_person("Peng Tsinv", 1, 0, 1000000);
	manager man_person("Peng Tsinv", 1, 0, 2500);
	em_person.pay();
	em_person.show();
	cout<<"em_person:(get 函数调用) "<<em_person.getbase_salary()<<endl;
	sal_person.pay();
	cout << "sal_person:(get 函数调用) " << sal_person.getcareer_salary() << endl;
	man_person.pay();
	cout<<"man_person:(get 函数调用) "<<man_person.getsalary()<<endl;
	tech_person.pay();

	return 0;
}
