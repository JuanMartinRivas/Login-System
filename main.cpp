#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream read("C:\\Users\\PC\\" + username + ".txt");
    if (!read.is_open())
    {
        return false;
    }
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
};

main()
{
    int choice;

    cout << "1: Register\n2: Login\nYour Choice: ";
    cin >> choice;

    if(choice == 1) //Register
    {
        string username, password;

        cout << "Choose a username: ";
        cin >> username;
        cout << "Choose a password: ";
        cin >> password;

        ofstream file;
        file.open("C:\\Users\\PC\\" + username + ".txt");
        file << username << endl;
        file << password;
        file.close();

        main();
    }
    else if(choice == 2) //Login
    {
        bool status = isLoggedIn();

        if(!status)
        {
            cout << "Username or password are incorrect!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Welcome!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}