#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class Date
{
	private: int month;
			 int day;
			 int year;
			 char ch;
	
	public:	void getDate()
			{
				cin>>month>>ch>>day>>ch>>year;
			}
			void showDate()
			{
				cout<<month<<"/"<<day<<"/"<<year;
			}
};
class Student
{
	private: char name[80];
			 int age;
			 Date birth;
			 char courseName[30];
		
	public: void getStudent()
			{
				cout<<"\n\tEnter name: ";cin>>name;
				cout<<"\n\tEnter brithday: ";birth.getDate();
				cout<<"\n\tEnter age: ";cin>>age;
				cout<<"\n\tEnter course name: ";cin>>courseName;
			}	
			void showStudent()
			{
				cout<<"\n\n\tName: "<<name<<endl;
				cout<<"\n\tBrithday: ";birth.showDate();cout<<endl;
				cout<<"\n\tAge: "<<age<<endl;
				cout<<"\n\tCourse Name: "<<courseName<<endl;
			}
			void showstu_table()
			{
				cout<<"\t"<<name<<"\t";birth.showDate();
				cout<<"\t"<<age<<"\t"<<courseName<<"\n\n";
			}
			string getName()
			{
				return name;
			}
};
class Employee
{
	private: char name[80];
			 Date brith;
			 Date hire;
			 char jobdes[80];
			 char subj[40];
			 
	public: void getEmployee()
			{
				cout<<"\n\tEnter name: ";cin>>name;
				cout<<"\n\tEnter Brithday: ";brith.getDate();
				cout<<"\n\tEnter Hired Date: ";hire.getDate();
				cout<<"\n\tEnter Job Description: ";cin>>jobdes;
				cout<<"\n\tEnter Subject: ";cin>>subj;
			}	
			void showEmployee()
			{
				cout<<"\n\n\tName: "<<name<<endl;
				cout<<"\n\tBirthday: ";brith.showDate();cout<<endl;
				cout<<"\n\tHired Date: ";hire.showDate();cout<<endl;
				cout<<"\n\tJob Description: "<<jobdes<<endl;
				cout<<"\n\tSubject: "<<subj<<endl;
			}
			string getName()
			{
				return name;
			}
			void showemp_table()
			{
				cout<<"\t"<<name<<"\t";brith.showDate();cout<<"\t";hire.showDate();
				cout<<"\t"<<jobdes<<"\t\t\t"<<subj<<"\n\n";
			}
};
void introduction();
void view_menu();
void entry_menu();
void edit_menu();
void search_menu();
void showstu();
void showemp();
void addstu();
void addemp();
void deletestudent();
void deleteemployee();
void editstudent();
void editemployee();
void searchstu();
void searchemp();
void displaystu_table();
void displayemp_table();
int main()
{
	int num;
	introduction();
	cin.get();
	do
	{
		cout<<"\n\nMain Menu\n";
		cout<<"=========\n\n";
		cout<<"1:View Information\n\n";
		cout<<"2:Add Information\n\n";
		cout<<"3:Edit/Delete Information\n\n";
		cout<<"4:Search Information\n\n";
		cout<<"5:Exit\n\n";
		cout<<"Enter option(1-5): ";
		cin>>num;
		switch(num)
		{
			case 1:view_menu();break;
			case 2:entry_menu();break;
			case 3:edit_menu();break;
			case 4:search_menu();break;
			case 5:cout<<"\n\nExisting...\n\n";break;
			default:cout<<"\a";
		}	
	}while(num!=5);
	
	return 0;
}
void introduction()
{
	cout<<"\n\t\tStudent\n\n\t\t   &\n\n\t    Teacher Project\n\n";
	cout<<"\n\tCreated By: Htun Aung Kyaw\n\n";
}
void view_menu()
{
	int n;
	do
	{
		cout<<"\n\tView Menu\n";
		cout<<"\t=========\n\n";
		cout<<"\t1:Show Student information\n\n";
		cout<<"\t2:Show Teacher information\n\n";
		cout<<"\t3:Back to Main Menu\n\n";
		cout<<"\tEnter option(1-3): ";
		cin>>n;
		switch(n)
		{
			case 1:showstu();cin.get();break;
			case 2:showemp();cin.get();break;
			case 3:break;
			default:view_menu();
		}
	}while(n!=3);
}
void entry_menu()
{
	int n;
	do
	{
		cout<<"\n\tAdd/Edit Menu\n";
		cout<<"\t=============\n\n";
		cout<<"\t1:Add Student information\n\n";
		cout<<"\t2:Add Teacher information\n\n";
		cout<<"\t3:Back to Main Menu\n\n";
		cout<<"\tEnter option(1-3): ";
		cin>>n;
		switch(n)
		{
			case 1:addstu();cin.get();break;
			case 2:addemp();cin.get();break;
			case 3:break;
			default: entry_menu();
		}
	}while(n!=3);
}
void edit_menu()
{
	int n;
	do
	{
		cout<<"\n\tEdit/Delete Menu\n";
		cout<<"\t================\n\n";
		cout<<"\t1:Delete Student Information\n\n";
		cout<<"\t2:Delete Teacher Information\n\n";
		cout<<"\t3:Edit Student Information\n\n";
		cout<<"\t4:Edit Teacher Information\n\n";
		cout<<"\t5:Back to Main Menu\n\n";
		cout<<"\tEnter option(1-5): ";cin>>n;
		switch(n)
		{
			case 1:deletestudent();cin.get();break;
			case 2:deleteemployee();cin.get();break;
			case 3:editstudent();cin.get();break;
			case 4:editemployee();cin.get();break;
			case 5:break;
			default: edit_menu();
		}
	}while(n!=5);
}
void search_menu()
{
	int n;
	do
	{
		cout<<"\n\n\tSearch Menu\n";
		cout<<"\t===========\n\n";
		cout<<"\t1:Search Student Information\n\n";
		cout<<"\t2:Search Teacher Information\n\n";
		cout<<"\t3:Back to Main Menu\n\n";
		cout<<"\tEnter option(1-3): ";cin>>n;
		switch(n)
		{
			case 1:searchstu();cin.get();break;
			case 2:searchemp();cin.get();break;
			case 3:break;
		}
	}while(n!=3);
}
void showstu()
{
	Student stu;
	ifstream infile;
	infile.open("Student.dat",ios::binary);
	infile.seekg(0,ios::end);
	int pos = infile.tellg();
	int num = pos/sizeof(Student);
	if(num==0)
	{
		cout<<"\n\tNo data to show..\n";
		cin.get();
		return;
	}
	infile.close();
	displaystu_table();
}
void showemp()
{
	Employee emp;
	ifstream infile;
	infile.open("Employee.dat",ios::binary);
	infile.seekg(0,ios::end);
	int pos = infile.tellg();
	int num = pos/sizeof(Student);
	if(num==0)
	{
		cout<<"\n\tNo data to show..\n";
		cin.get();
		return;
	}
	infile.close();
	displayemp_table();
}
void addstu()
{
	char ch;
	Student stu;
	ofstream outfile;
	outfile.open("Student.dat",ios::binary|ios::app);
	cout<<"\n\tAdding Student Information\n";
	do
	{
		stu.getStudent();
		outfile.write((char*)&stu,sizeof(stu));
		cout<<"\n\n\tEnter more(y/n): ";cin>>ch;
	}while(ch!='n');
	cout<<"\nStudent data have added into the file.";
	cin.get();
}
void addemp()
{
	char ch;
	Employee emp;
	ofstream outfile;
	outfile.open("Employee.dat",ios::binary|ios::app);
	cout<<"\n\tAdding Employee Information.\n";
	do
	{
		emp.getEmployee();
		outfile.write((char*)&emp,sizeof(emp));
		cout<<"\n\n\tEnter more(y/n): ";cin>>ch;
	}while(ch!='n');
	cout<<"\nEmployee data have added into the file.\n";
	cin.get();
}
void deletestudent()
{
	int n;
	Student stu;
	ifstream inFile;
	inFile.open("Student.dat",ios::binary);
	inFile.seekg(0,ios::end);
	int pos = inFile.tellg();
	int num = pos/sizeof(Student);
	if(num==0)
	{
		cout<<"\n\tNo record to delete..\n";
		cin.get();
		return;
	}
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.get();
		return;
	}
	displaystu_table();
	cout<<"Enter Number to Delete: ";cin>>n;
	if(n>num)
	{
		cout<<"\nWrong Number..\nThis data do not exist in the file..\n\nPlease Enter Number"<<"(1-"<<num<<"): ";
		cin>>n;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	int counter=0;
	while(inFile.read(reinterpret_cast<char*> (&stu), sizeof(Student)))
	{
		counter++;
		if(counter!=n)
		{
			outFile.write(reinterpret_cast<char*> (&stu), sizeof(Student));
		}
	}
	outFile.close();
	inFile.close();
	remove("Student.dat");
	rename("Temp.dat","Student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.get();
}
void deleteemployee()
{
	int n;
	Employee emp;
	ifstream inFile;
	inFile.open("Employee.dat",ios::binary);
	inFile.seekg(0,ios::end);
	int pos = inFile.tellg();
	int num = pos/sizeof(Student);
	if(num==0)
	{
		cout<<"\n\tNo record to delete..\n";
		cin.get();
		return;
	}
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.get();
		return;
	}
	displayemp_table();
	cout<<"Enter Number to Delete: ";cin>>n;
	if(n>num)
	{
		cout<<"\nWrong Number..\nThis data do not exist in the file..\n\nPlease Enter Number"<<"(1-"<<num<<"): ";
		cin>>n;
	}
	inFile.seekg(0);
	int counter = 0 ;
	ofstream outFile("Temp.dat",ios::binary|ios::app);
	
	while(inFile.read((char*)&emp,sizeof(emp)))
	{
		counter++;
		if(counter!=n)
		{
			outFile.write((char*)&emp,sizeof(emp));
		}
	}
	inFile.close();
	outFile.close();
	remove("Employee.dat");
	rename("Temp.dat","Employee.dat");
	cout<<"\n\n\tRecord deleted..";
	cin.get();
}
void editstudent()
{
	int n,counter=0;
	Student stu,stud;
	ifstream infile("Student.dat",ios::binary|ios::app);
	infile.seekg(0,ios::end);
	int pos = infile.tellg();
	int num = pos/sizeof(Student);
	if(num==0)
	{
		cout<<"\n\tNo record to modify..\n";
		cin.get();
		return;
	}
	displaystu_table();
	cout<<"\nEnter Number to Modify: ";cin>>n;
	if(n>num)
	{
		cout<<"\nWrong Number..\nThis data do not exist in the file..\n\nPlease Enter Number"<<"(1-"<<num<<"): ";
		cin>>n;
	}
	infile.seekg(0);
	stud.getStudent();
	ofstream outfile("Temp.dat",ios::binary|ios::app);
	while(infile.read((char*)&stu,sizeof(stu)))
	{
		counter++;
		if(counter==n)
		{
			outfile.write((char*)&stud,sizeof(stud));	
		}
		else
		{ 
			outfile.write((char*)&stu,sizeof(stu));
		}
	}
	cout<<"\n\n\tRecord modified..\n";
	infile.close();
	outfile.close();
	remove("Student.dat");
	rename("Temp.dat","Student.dat");
	cin.get();
}
void editemployee()
{
	int n,counter;
	Employee emp,empl;
	ifstream infile("Employee.dat",ios::binary);
	infile.seekg(0,ios::end);
	int pos = infile.tellg();
	int num = pos/sizeof(Employee);
	if(num==0)
	{
		cout<<"\n\tNo record to modify..\n";
		cin.get();
		return;
	}
	displayemp_table();
	cout<<"\nEnter Number to Modify: ";cin>>n;
	if(n>num)
	{
		cout<<"\nWrong Number..\nThis data do not exist in the file..\n\nPlease Enter Number"<<"(1-"<<num<<"): ";
		cin>>n;
	}
	infile.seekg(0);
	empl.getEmployee();
	ofstream outfile("Temp.dat",ios::binary|ios::app);
	while(infile.read((char*)&emp,sizeof(emp)))
	{
		counter++;
		if(counter==n)
		{
			outfile.write((char*)&empl,sizeof(empl));	
		}
		else
		{ 
			outfile.write((char*)&emp,sizeof(emp));
		}
	}
	cout<<"\n\n\tRecord modified..\n";
	infile.close();
	outfile.close();
	remove("Employee.dat");
	rename("Temp.dat","Employee.dat");
	cin.get();
}
void searchstu()
{
	char name[80];
	Student stu;
	ifstream infile("Student.dat",ios::binary);
	infile.seekg(0,ios::end);
	int pos = infile.tellg();
	int num = pos/sizeof(Student);
	infile.seekg(0);
	if(num==0)
	{
		cout<<"\n\tNo record to search..\n";
		cin.get();
		return;
	}
	else
	{
		cout<<"\n\n\tEnter Name to search: ";
		cin>>name;
		bool exist=false;
		while(infile.read((char*)&stu,sizeof(stu)))
		{
			if(stu.getName()==name)
			{
				cout<<"\n\t================";
				stu.showStudent();
				cout<<"\n\t================";
				exist=true;
			}
		}
		cout<<((exist)?"\n\n\t\"Record Exists.\"\n":"\n\n\t\"Record does not Exist.\"\n");
	}
	infile.close();
	cin.get();
}
void searchemp()
{
	char name[80];
	Employee emp;
	ifstream infile("Employee.dat",ios::binary);
	infile.seekg(0,ios::end);
	int pos = infile.tellg();
	int num = pos/sizeof(Employee);
	infile.seekg(0);
	if(num==0)
	{
		cout<<"\n\tNo record to search..\n";
		cin.get();
		return;
	}
	else
	{
		cout<<"\n\n\tEnter Name to search: ";
		cin>>name;
		bool exist=false;
		while(infile.read((char*)&emp,sizeof(emp)))
		{
			if(emp.getName()==name)
			{
				cout<<"\n\t================";
				emp.showEmployee();
				cout<<"\n\t================";
				exist=true;
			}
		}
		cout<<((exist)?"\n\n\t\"Record Exists.\"\n":"\n\n\t\"Record does not Exist.\"\n");
	}
	infile.close();
	cin.get();
}
void displaystu_table()
{
	int counter=0;
	cout<<"\n\tAll Student Information\n";
	cout<<"\t===========================================================";
	cout<<"\n\tNo."<<"\t"<<"Name"<<"\t\t"<<"Birthday"<<"\t"<<"Age"<<"\t"<<"Course Name"<<endl;
	cout<<"\t===========================================================\n\n";
	
	Student stu;
	ifstream infile;
	infile.open("Student.dat",ios::binary);
	
	while(infile.read((char*)&stu,sizeof(stu)))
	{
		counter++;
		cout<<"\t"<<counter;
		stu.showstu_table();
	}
	cout<<"\t===========================================================\n\n";
	infile.close();
	cin.get(); 
}
void displayemp_table()
{
	int counter=0;
	cout<<"\n\tAll Teacher Information\n";
	cout<<"\t=======================================================================================";
	cout<<"\n\tNo."<<"\t"<<"Name"<<"\t\t"<<"Birthday"<<"\t"<<"HireDate"<<"\t"<<"Job Description"<<"\t\t"<<"Subject"<<endl;
	cout<<"\t=======================================================================================\n\n";
	
	Employee emp;
	ifstream infile;
	infile.open("Employee.dat",ios::binary);
	infile.read((char*)&emp,sizeof(emp));
	while(infile)
	{
		counter++;
		cout<<"\t"<<counter;
		emp.showemp_table();
		infile.read((char*)&emp,sizeof(emp));
	}
	cout<<"\t=======================================================================================\n\n";
	cin.get();
	infile.close();
}
