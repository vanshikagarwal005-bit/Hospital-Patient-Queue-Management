#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient
{
    int token;
    string name;
    int age;
    string disease;
};

int main()
{
    queue<Patient> q;
    int choice;
    int token = 1;

    do
    {
        cout << "\n===== Hospital Patient Queue Management =====";
        cout << "\n1. Register Patient";
        cout << "\n2. Serve Next Patient";
        cout << "\n3. Display Patient Queue";
        cout << "\n4. View Next Patient";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                Patient p;
                p.token = token++;

                cin.ignore();

                cout << "Enter Patient Name: ";
                getline(cin, p.name);

                cout << "Enter Age: ";
                cin >> p.age;

                cin.ignore();

                cout << "Enter Disease: ";
                getline(cin, p.disease);

                q.push(p);

                cout << "\nPatient Registered Successfully!";
                cout << "\nToken Number: " << p.token << endl;
                break;
            }

            case 2:
            {
                if(q.empty())
                {
                    cout << "\nNo patients in the queue.\n";
                }
                else
                {
                    Patient p = q.front();

                    cout << "\nNow Serving";
                    cout << "\nToken : " << p.token;
                    cout << "\nName  : " << p.name;
                    cout << "\nAge   : " << p.age;
                    cout << "\nDisease : " << p.disease << endl;

                    q.pop();
                }
                break;
            }

            case 3:
            {
                if(q.empty())
                {
                    cout << "\nQueue is empty.\n";
                }
                else
                {
                    queue<Patient> temp = q;

                    cout << "\nCurrent Patient Queue\n";
                    cout << "---------------------------------\n";

                    while(!temp.empty())
                    {
                        Patient p = temp.front();

                        cout << "Token : " << p.token << endl;
                        cout << "Name  : " << p.name << endl;
                        cout << "Age   : " << p.age << endl;
                        cout << "Disease : " << p.disease << endl;
                        cout << "--------------------------\n";

                        temp.pop();
                    }
                }
                break;
            }

            case 4:
            {
                if(q.empty())
                {
                    cout << "\nQueue is empty.\n";
                }
                else
                {
                    Patient p = q.front();

                    cout << "\nNext Patient";
                    cout << "\nToken : " << p.token;
                    cout << "\nName  : " << p.name;
                    cout << "\nAge   : " << p.age;
                    cout << "\nDisease : " << p.disease << endl;
                }
                break;
            }

            case 5:
            {
                cout << "\nThank You!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!\n";
            }
        }

    } while(choice != 5);

    return 0;
}