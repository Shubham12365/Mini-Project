#include "iostream"
using namespace std; 

class  user
{   
    string username,password;
    public:
        int adminLogin();
        int adminView();
        int teacherlogin();
        int studentView();
        int studentLogin();
        
};