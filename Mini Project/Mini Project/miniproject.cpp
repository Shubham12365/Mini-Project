#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>//Stream class to operate on strings.
using namespace std;

int total = 100;

//***********************************************ADMIN***************************************************

// class admin
// {
//     string username, password;
//     public:
//     int adminLogin();
//     int adminView();
//     int deleteAllStudents();
//     int checkListOfStudentsRegistered();
//     int registerStudent();
// };

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
        cout << "\n Error ! Invalid Username And Password..";
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
        // To go back to the previous menu.
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
            cout << "\n Username already Register. Please choose another username ";
            getchar();
            getchar();
            read.close();
            return 0;
        }
    }
    read.close();

    ofstream out;
    out.open("db.dat", ios::app);
    // Username.dat append inside db.dat
    out << username + ".dat"
        << "\n";
    out.close();

    ofstream out1;
    string str = username + ".dat";
    out1.open(str.c_str()); // c_str() function returns pointer of str =username.dat so thats how out1 object could access the str file & copied the data.
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
            cout << "\n"<< filename;

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

//*****************************************STUDENT*******************************************************
class student
{
    string username, password;

public:
    int studentLogin();
    void studentView();
    int checkUserAuthentication(string username, string password);
    int Attendance(string username);
    int sendLeaveApplication(string username);
};

int studentLogin()
{
    student s; // creating object of class studnet
    system("cls");
    cout << "\n -------------------- Student Login ----------------------";
    s.studentView();
    return 0;
}

void student::studentView()
{
    cout << "\n Enter username : ";
    cin >> username;

    cout << "\n Enter password : ";
    cin >> password;

    int res = checkUserAuthentication(username, password);

    if (res == 0)
    {
        cout << "\n Invalid Credentials !!.....NO DATA FOUND";
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
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Attendance(username);
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

int student::checkUserAuthentication(string username, string password)
{

    ifstream read; // We made object of class ifstream i.e read
    read.open("db.dat");
    int RecFound = 0;
    if (read) // Execute a loop If file successfully opened
    {
        string line;
        string str = username + ".dat";
        while (getline(read, line)) // inside read object we take line string as input..
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
            ++lineNum; // It will stop when line =password
        }
        read.close();
        if (password == line) // Verifying the password.
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
    read.open(filename); // It opens the file of username.dat..
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
            istringstream(line) >> i; // here i is storing a value from line in integer form till white spaces occured.
            cout << "\nPercentage of attendance :\t" << (i * 100 / total) << "%";
        }
    }

    cout << "\n Press any key to continue..";

    getchar();
    getchar();

    return 0;
}

//**********************************************TEACHER**************************************************
// class teacher
// {
//     string username, password;

// public:
//     int teacherlogin();
//     int Attendance();
//     int teacherView();
// };

int Attendance();
int teacherView();
int teacherlogin();

int teacherlogin()
{
    system("cls");
    cout << "\n -------------------- Teacher Login ----------------------";

    string username;
    string password;

    cout << "\n Enter username : ";
    cin >> username;
    cout << "\n Enter password : ";
    cin >> password;

    if (username == "teacher" && password == "teacher")
    {
        teacherView();
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

int Attendance()
{
    ifstream read;
    read.open("db.dat");

    if (read)
    {
        int RecFound = 0;
        string line;
        while (getline(read, line))
        {

            char name[100];
            strcpy(name, line.c_str()); // return character pointer
            string filename = name;

            int total_lines = 0;
            ifstream read1;
            read1.open(filename);
            string line;
            while (getline(read1, line))
            {
                ++total_lines;
            }
            read1.close();

            ifstream read;
            read.open(filename);
            // ifstream read;
            // read.open("db.dat");
            cout << "name:" << filename << endl;
            int c;
            cout << "1: present:"
                 << "\t" // giving tab space horizontally in your output.
                 << "O : absent:" << endl;
            cout << "enter choice:" << endl;
            cin >> c;
            switch (c)
            {
            case 1:
            {
                string line;
                if (read)
                {
                    // cout<<"inside switch"<<endl;
                    int line_no = 0;
                    while (line_no != total_lines && getline(read, line))
                    {
                        ++line_no;
                    }
                    if (line_no == total_lines)
                    {
                        int i;

                        // Convert types to string by stringstream
                        istringstream(line) >> i; // here i is storing a value from line in integer form till white spaces occured.
                        i++;
                        // cout<<"i "<<i<<endl;
                        ofstream out1;
                        string str = name;
                        out1.open(str, ios::app); // All output operations happen at the end of the file
                        out1 << i << "\n";
                        out1.close();
                    }
                }
                break;
            }
            case 0:
                break;
            }

            read.close();
        }
    }
    read.close();

    cout << "\n Press any key to continue..";

    getchar();
    getchar();

    return 0;
}

int teacherView()
{
    int goBack = 0;
    while (1)
    {
        system("cls");
        cout << "\n 1 Mark Attendance";
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Attendance();
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

    return 0;
}

int main()
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