#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <sstream>

#include "student_header.h"

using namespace std;

void studentView();
int studentLogin();
int checkUserAuthentication(string userName, string password);
int adminLogin();
int teacherlogin();
int Attendance(string username);
int sendLeaveApplication(string username);

int total = 100;

// student part
void student::studentView()
{
    cout << "\n Enter username : ";
    cin >> username;

    cout << "\n Enter password : ";
    cin >> password;

    int res = checkUserAuthentication(username, password);

    if (res == 0)
    {
        cout << "\n Invalid Credentials !!";
        cout << "\n Press any key for Main Menu..";
        getchar();
        getchar();
        return;
    }

    int goBack = 0;
    while (1)
    {

        system("cls");
        cout << "\n 1 Count my Attendance";
        cout << "\n 2 Send a leave application";
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Attendance(username);
            break;
        case 2:
            sendLeaveApplication(username);
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n Invalid choice. Enter again ";
            getchar();
        }

        if (goBack == 1)
        {
            break;
        }
    }
}

int studentLogin()
{
    student s; // creating object of class studnet
    system("cls");
    cout << "\n -------------------- Student Login ----------------------";
    s.studentView();
    return 0;
}

int student::checkUserAuthentication(string username, string password)
{

    ifstream read;//We made object of class ifstream i.e read
    read.open("db.dat");
    int RecFound = 0;
    if (read)// Execute a loop If file successfully opened
    {
        string line;
        string str = username + ".dat";
        while (getline(read, line))//inside read object we take line string as input..
        {
            if (line == str)
            {
                RecFound = 1;
            }
        }
    }
    read.close();
    cout << "RecFound " << RecFound << " username " << username << " password " << password << endl;
    if (RecFound == 1)
    {
        ifstream read;
        string filename = username + ".dat";
        read.open(filename);
        int lineNum = 0;
        string line;
        while (lineNum != 3 && getline(read, line))
        {
            cout << "Line " << line << endl;
            ++lineNum;//It will stop when line =password
        }
        read.close();
        if (password == line)//Verifying the password.
            return 1; 
        else
            return 0;
    }
    else
        return 0;
}

int student::Attendance(string username) // Function OVERLOADING
{
    int total_lines = 0;
    string filename = username + ".dat";
    ifstream read;
    read.open(filename);//It opens the file of username.dat..
    string line;
    while (getline(read, line))
    {
        ++total_lines;
    }

    read.close();
    ifstream read1;
    read1.open(filename);
    if (read1)
    {
        int line_no = 0;
        while (line_no != total_lines && getline(read1, line))
        {
            ++line_no;
        }
        if (line_no == total_lines)
        {
            cout << "\nTotal present: " << line;
            int i;
            istringstream(line) >> i;//here i is storing a value from line in integer form till white spaces occured.
            cout << "\nPercentage of attendance :\t" << (i * 100 / total) << "%";
        }
    }

    cout << "\n Press any key to continue..";

    getchar();
    getchar();

    return 0;
}

int student::sendLeaveApplication(string username)
{
    char add[100];
    cout << "\n Write your application here: ";
    getchar();
    cin.getline(add, 100);

// 
    time_t now = time(0);
    tm *ltm = localtime(&now);

    ofstream out;
    out.open("application.dat", ios::app);
    out << add << " -> " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " -> " << username << "\n";
    out.close();
    cout << "\n Application successfully sent !!";
    cout << "\n Press any key to continue..";
    getchar();
    return 0;
}

int main(int argc, char **argv)
{

    while (1)
    {
        system("cls");

        cout << "\t\t\t\t\t Attendance Management System \n";
        cout << "-------------------------------------------------------------------------\n\n";

        cout << "1. Student Login\n";
        cout << "2. Admin Login\n";
        cout << "3. teacher Login\n";
        cout << "0. Exit\n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentLogin();
            break;
        case 2:
            adminLogin();
            break;
        case 3:
            teacherlogin();
            break;
        case 0:
            while (1)
            {
                system("cls");
                cout << "\n Are you sure, you want to exit? y | n \n";
                char ex;
                cin >> ex;
                if (ex == 'y' || ex == 'Y')
                    exit(0);
                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }
                else
                {

                    cout << "\n Invalid choice !!!";
                    getchar();
                }
            }
            break;

        default:
            cout << "\n Invalid choice. Enter again ";
            getchar();
        }
    }

    return 0;
}