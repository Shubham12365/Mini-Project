#include "user.h"
// #include <iostream>

using namespace std; 

class admin : public user
{   
    string username,password;
    public:
        int deleteAllStudents();
        int checkListOfStudentsRegistered();
        int registerStudent();
        
};