#include <iostream>
#include <fstream>
#include<conio.h>
#include <stdlib.h>

using namespace std;
class student
{
private:
    string name1,name2,id,dept,sem,address,email,contact_no;
    string user,password;
public:
    void new_user();
    void login_panel();
    void menu();
    void insert();
    void all_record();
    void modify();
    void search();
    void deleted();
    void change_password();
};



void student::new_user()
{
    system("Color E4");
    fstream file1;
    cout << "\n\t\t\t\t   Welcome to Student Database Management System  " << endl;
    cout<<"\t\t\t\tFor Next Page Please Set Your Username and Password"<<endl;
    cout << "\t\t\t--------------------------------------------------------------------";

    file1.open("Password.txt");
    if(!file1)
    {
        file1.open("Password.txt", ios::out);
        cout<<"\n\n\t\t\t\tEnter Username: ";
        cin >> user;
        cout<<"\t\t\t\tEnter Password: ";
        cin >> password;
        file1 << user << "  " << password;
        cout << "\n\t\t\t--------------------------------------------------------------------";
        cout<< "\n\t\t\t\tUsername and Password Set Successfully....."<<endl;
        cout<<"\n\t\t\t\tYour Username is: "<< user<<endl;
        cout<<"\t\t\t\tYour Password is: "<< password<<endl;
        file1.close();
        cout<< "\t\t\t\t"<<system("pause")<<endl;
        login_panel();
    }
    else
    {
        login_panel();
    }
    getch();
}



void student::login_panel()
{
login_panel:
    system("Color B1");
    system("cls");
    fstream file1;
    string user2,password2;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                  Login Panal                  |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    file1.open("Password.txt", ios::in);
    cout << "\t\t\t\tUser Name: ";
    cin>>user2;
    cout << "\t\t\t\tPassword: ";
    cin >> password2;
    file1 >> user >> password ;
    if(user == user2)
    {
        if(password == password2)
        {
            menu();
            file1.close();
        }
        else
        {
            cout<<"\n\t\t\t\tInvalid Please Check Your Password...."<<endl;
            cout<< "\t\t\t\t"<<system("pause")<<endl;
            goto login_panel;
        }
    }
    else
    {
        cout<<"\n\t\t\t\tInvalid Please Check Your User Name...."<<endl;
        cout<< "\t\t\t\t"<<system("pause")<<endl;
        goto login_panel;
    }
    getch();
}



void student::menu()
{
menustart:
    system("Color E2");
    int choice;
    system("cls");
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|           Student Management System           |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    cout << "\t\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t\t 2. All Records" << endl;
    cout << "\t\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t\t 6. Change Password" << endl;
    cout << "\t\t\t\t 7. Exit" << endl<< endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t    Enter Your Choose: " ;
    cin >> choice;
    cout << endl;

    switch(choice)
    {
    case 1:
        insert();
        break;
    case 2:
        all_record();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        change_password();
        break;
    case 7:
        exit(0);
        break;
    default:
        cout<<"\t\t\t\t    Invalid Choice Please Try Again......"<<endl;
    }
    getch();
    goto menustart;
}



void student::insert()
{
insert:
    system("Color F3");
    int add_another;
    string id_no;
    system("cls");
    fstream file;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|               Add Student Details             |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::app | ios::out);
    cout << "\t\t\t\tStudent ID: ";
    cin >> id_no;
    if(id==id_no)
    {
        cout << "\t\t\t\tSorry the ID is Already has been Taken. Please try again."<<endl;
        cout << "\t\t\t\t-------------------------------------------------"<<endl;
    }
    else
    {
        cout << "\t\t\t\tUnique Student ID is Found.Please Continue.. "<<endl;
        cout << "\t\t\t\t-------------------------------------------------" << endl;
        cout << "\t\t\t\tStudent ID: ";
        cin >> id;
        cout << "\t\t\t\tFirst Name: ";
        cin >> name1;
        cout << "\t\t\t\tLast Name: ";
        cin >> name2;
        cout << "\t\t\t\tDepartment: ";
        cin >> dept;
        cout << "\t\t\t\tSemester: ";
        cin >> sem;
        cout << "\t\t\t\tAddress: ";
        cin >> address;
        cout << "\t\t\t\tEmail Id: ";
        cin >> email;
        cout << "\t\t\t\tContact No: ";
        cin >> contact_no;
        cout << "\t\t\t\t-------------------------------------------------" << endl;
        file << id << "  " << name1 << "  " << name2 << "  " << dept << "  " << sem << "  " << address << "  " << email << "  " << contact_no << "\n";
        file.close();
    }
    cout << "\t\t\t\tDo You Want To Add Another Record: 1.YES" <<endl;
    cout << "\t\t\t\t\t\t\t\t   2.NO"<<endl;
    cout << "\t\t\t\tEnter Your Choice: ";
    cin >> add_another;

    if(add_another==1)
    {
        goto insert;
    }
    if(add_another==2)
    {
        menu();
    }
}


void student::all_record()
{
    system("cls");
    system("Color F1");
    fstream file;
    int total_student = 1;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|               Student Record Table            |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    file.open("studentRecord.txt",ios::in);
    if(!file)
    {
        cout << "\t\t\t\tNo Data Found... ";
        file.close();
    }
    else
    {
        file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        while (!file.eof())
        {
            cout << "\t\t\t\t Student No: " << total_student++ << endl;
            cout << "\t\t\t\t Name      : " << name1 << " " << name2 << endl;
            cout << "\t\t\t\t ID        : " << id << endl;
            cout << "\t\t\t\t Department: " << dept << endl;
            cout << "\t\t\t\t Semester  : " << sem << endl;
            cout << "\t\t\t\t Address   : " << address << endl;
            cout << "\t\t\t\t Email     : " << email << endl;
            cout << "\t\t\t\t Contact No: " << contact_no << endl<< endl<< endl;
            file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        }
    }
    if (total_student == 0)
    {
        cout << "\t\t\t\tNo Data Found... ";
    }
    file.close();
}


void student::modify()
{
    system("Color B4");
    system("cls");
    fstream file,file1;
    string id_no;
    int found = 0;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|               Student Modify Details          |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t\tNo Data Found... ";
    }
    else
    {
        cout << "\t\t\t\t Enter Student Roll No for Modify: ";
        cin >> id_no;
        file1.open("temporary.txt", ios::app | ios::out);
        file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        while (!file.eof())
        {
            if (id != id_no)
            {
                file1 << id << "  " << name1 << "  " << name2 << "  " << dept << "  " << sem << "  " << address << "  " << email << "  " << contact_no << "\n";
            }

            else
            {

                cout << "\n\t\t\t\t First Name: ";
                cin >> name1;
                cout << "\t\t\t\t Last Name: ";
                cin >> name2;
                cout << "\t\t\t\t ID: ";
                cin >> id;
                cout << "\t\t\t\t Department: ";
                cin >> dept;
                cout << "\t\t\t\t Semester: ";
                cin >> sem;
                cout << "\t\t\t\t Address: ";
                cin >> address;
                cout << "\t\t\t\t Email Id: ";
                cin >> email;
                cout << "\t\t\t\t Contact No: ";
                cin >> contact_no;

                file1 << id << "  " << name1 << "  " << name2 << "  " << dept << "  " << sem << "  " << address << "  " << email << "  " << contact_no << "\n";
                found++;
            }
            file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("temporary.txt", "studentRecord.txt");
    }
}




void student::search()
{
    system("cls");
    system("Color F4");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                Student Data Search            |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    if (!file)
    {
        cout << "\t\t\t\t No Data Found... ";
        file.close();
    }
    else
    {
        string id_no;
        cout << "\t\t\t\t Enter Student Roll No for Search: ";
        cin >> id_no;
        file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        while (!file.eof())
        {
            if(id_no == id)
            {
                cout << "\n\t\t\t\t Name: " << name1 << " " << name2 << endl;
                cout << "\t\t\t\t ID: " << id << endl;
                cout << "\t\t\t\t Department: " << dept << endl;
                cout << "\t\t\t\t Semester: " << sem << endl;
                cout << "\t\t\t\t Address: " << address << endl;
                cout << "\t\t\t\t Email: " << email << endl;
                cout << "\t\t\t\t Contact No: " << contact_no << endl;
                found++;
            }
            file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t No Data Found... ";
        }
        file.close();
    }
}



void student::deleted()
{
    system("cls");
    system("Color 2");
    fstream file, file1;
    int found = 0;
    string id_no;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|              Delete Student Details           |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t\t No Data Found... ";
        file.close();
    }
    else
    {
        cout << "\t\t\t\t Enter Student Roll No for Delete: ";
        cin >> id_no;
        file1.open("temporary.txt", ios::app | ios::out);
        file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        while (!file.eof())
        {
            if (id != id_no)
            {
                file1 << id << "  " << name1 << "  " << name2 << "  " << dept << "  " << sem << "  " << address << "  " << email << "  " << contact_no << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\t\t Successfully Delete Data...";
            }
            file >> id >> name1 >> name2  >> dept >> sem >> address >> email >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t Student Roll No Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("temporary.txt", "studentRecord.txt");
    }
}



void student::change_password()
{
    system("cls");
    ofstream file1;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|               Change Password             |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<<endl;
    cout << "\t\t\t\tEnter New Username: ";
    cin >> user;
    cout << "\t\t\t\tEnter New Password: ";
    cin >> password;
    file1.open("Password.txt");
    file1 << user << " " << password;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout<< "\t\t\t\tNew Username and Password Set Successfully"<<endl<<endl;
    cout<<"\t\t\t\tYour New Username is: "<< user<<endl;
    cout<<"\t\t\t\tYour New Password is: "<< password<<endl;
    file1.close();
    cout<< "\t\t\t\t"<<system("pause")<<endl;
    menu();
    getch();
}

int main()
{
    student project;
    project.new_user();
    return 0;
}
