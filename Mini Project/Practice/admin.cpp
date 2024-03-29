#include <iostream>
#include <string>   //Contain string functionality of C++.Provides class and related functions and operators
#include <cstring>  //It's is inherited from C and provides functions for working with C-style strings (arrays of char terminated by '\0').
#include <fstream>  //Header file for File HAndling
#include <time.h>   //Used to perform functions related to date and time
#include <typeinfo> //used related to operators typeid and dynamic_cast
#include <stdlib.h>
#include <sstream>
#include "admin_header.h"

using namespace std;

int adminView();
int deleteAllStudents();
int checkListOfStudentsRegistered();
int adminLogin();
int registerStudent();

int m = 0;
int k = 0;

int adminLogin()
{
    system("cls");
    cout << "\n -------------------- Admin Login --------------------";

    string username;
    string password;

    cout << "\n Enter username : ";
    cin >> username;
    cout << "\n Enter password : ";
    cin >> password;

    if (username == "admin" && password == "admin")
    {
        adminView();
        getchar();
    }
    else
    {
        cout << "\n Error ! Invalid Credintials..";
        cout << "\n Press any key for main menu ";
        getchar();
        getchar();
    }

    return 0;
}

int adminView()
{
    int goBack = 0;
    while (1)
    {
        system("cls");
        cout << "\n 1 Register a Student";
        cout << "\n 2 Delete All students name registered";
        cout << "\n 3 Check List of Student registered by username";
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerStudent();
            break;
        case 2:
            deleteAllStudents();
            break;
        case 3:
            checkListOfStudentsRegistered();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n Invalid choice. Enter again ";
            getchar();
        }
    //To go back to the previous menu.
        if (goBack == 1)
        {
            break;
        }
    }

    return 0;
}



int registerStudent()
{
    cout << "\n ----- Form to Register Student ---- \n";

    string name, username, password, rollno, branch;
    int total;

    cout << "\n Enter Name : ";
    cin >> name;

    cout << "\n Enter Username : ";
    cin >> username;

    cout << "\n Enter password : ";
    cin >> password;

    cout << "\n Enter rollno : ";
    cin >> rollno;
    getchar();

    cout << "\n Enter branch : ";
    cin >> branch;
    cout << "\n Enter initial number of presents :";
    cin >> m;

    // check if record already exist...
    ifstream read;
    read.open("db.dat");

    if (read)
    {
        int RecFound = 0;
        string line;
        while (getline(read, line))
        {
            if (line == username + ".dat")
            {
                RecFound = 1;
                break;
            }
        }
        if (RecFound == 1)
        {
            cout << "\n Username already Register. Press choose another username ";
            getchar();
            getchar();
            read.close();
            return 0;
        }
    }
    read.close();

    ofstream out;
    out.open("db.dat", ios::app);
    //Username.dat append inside db.dat
    out << username + ".dat"
        << "\n";
    out.close();

    ofstream out1;
    string str = username + ".dat";
    out1.open(str.c_str());//c_str() function returns pointer of str =username.dat so thats how out1 object could access the str file & copied the data. 
    out1 << name << "\n";
    out1 << username << "\n";
    out1 << password << "\n";
    out1 << rollno << "\n";
    out1 << branch << "\n";

    out1 << m << "\n";

    out1.close();

    cout << "\n Student Registered Successfully !!";

    cout << "\n Press any key to continue..";
    getchar();
    getchar();
    return 0;
}

int deleteAllStudents()
{
    remove("db.dat");
    cout << "\n Press any key to continue..";

    getchar();
    getchar();
    return 0;
}

int checkListOfStudentsRegistered()
{
    cout << "\n ---------- Check List of Student Registered by Username----------- ";

    // check if record already exist..
    ifstream read;
    read.open("db.dat");

    if (read)
    {
        int RecFound = 0;
        string line;
        while (getline(read, line))
        {

            char name[100];
            strcpy(name, line.c_str());
            string filename = name;
            cout << "\n"
                 << filename;

            int total_lines = 0;
            ifstream read1;
            read1.open(filename.c_str(), ios::app);
            string line;
            while (getline(read1, line))
            {
                ++total_lines;
            }
            read1.close();
            ifstream read;
            read.open(filename.c_str(), ios::app);
            string l;
            if (read)
            {
                int line_no = 0;
                while (line_no != total_lines && getline(read, l))
                {
                    ++line_no;
                }
                if (line_no == total_lines)
                {
                    cout << "-> " << l << "\n";
                }
                read.close();
                // char name[100];
                // strcpy(name, line.c_str());
                // char onlyname[100];
                // strncpy(onlyname, name, (strlen(name) - 4));
                // cout<<" \n " << onlyname;
            }
            read.close();
        }
    }
    else
    {
        cout << "\n No Record found :(";
    }

    cout << "\n Press any key to continue..";
    getchar();
    getchar();
    return 0;
}
