#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


struct Doctor
{
	int doc_id;
	string doc_name;
	string doc_specialization;
	double doc_salary;
};


int main()
{
	// vector<Doctor>arr;
	int n;
	cout << "Please, enter a number of doctor records: ";
	cin >> n;
    
    struct Doctor arr[n];
	for (int i = 0; i < n; i++)
{
		Doctor d;
		cout << "Please, enter an id of doctor: ";
		cin >> d.doc_id;
		cout << "Please, enter a name of doctor: ";
		cin >> d.doc_name;
		cout << "Please, enter a doc specialization of doctor: ";
		cin >> d.doc_specialization;
		cout << "Please, enter a doc salary of doctor: ";
		cin >> d.doc_salary;
		arr[i]=d;
	}

	ofstream of;
	of.open("record1.txt");
	if (!of.is_open())
		cout << "File isn`t opened!";
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i].doc_specialization == "cardiologist")
			{
				of << arr[i].doc_id << " " << arr[i].doc_name
					<< " " << arr[i].doc_specialization << " "
					<< arr[i].doc_salary << endl;
			}
		}
	}
	of.close();
	ofstream of2;
	of2.open("record2.txt");
	if (!of2.is_open())
		cout << "File isn`t opened!";
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i].doc_salary > 80000)
			{
				of2 << arr[i].doc_id << " " << arr[i].doc_name
					<< " " << arr[i].doc_specialization << " "
					<< arr[i].doc_salary << endl;
			}
		}
	}
	of2.close();
	ifstream file1("record1.txt");
	ifstream file2("record2.txt");
	ofstream out("finalrecord.txt");
	if (!file1.is_open() || !file2.is_open() || !out.is_open())
	{
		cout << "File isn`t opened!";
	}
	else
	{
		string str;
		while (getline(file1, str)) { out << str<<endl; }
		while (getline(file2, str)) { out << str<<endl; }
	}
}