// Task_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#define NOMINMAX

#include <windows.h>
using namespace std;

void print_tasks(string tasks[], int task_count)
{
    cout << "|--  TO DO TASKS   --|" << endl;
    cout << "| -----------------  |" << endl;
 
    for (int task = 0; task < task_count; task++)
    {
        cout << "| Task " << task << " : " << tasks[task] << " | " << endl;
        
    }



    cout << "| -----------------  |" << endl;
}


int main()
{
    string tasks[10] = {""};
    // counter 
    int task_count = 0;
    int max_tasks = 9;
    int min_tasks = 0;
    // end the program
    int option = -1;

    ofstream task_file;

    task_file.open("taskList.txt");

    if (task_file.is_open())
    {
        while (option != 0)
        {
            // basic ahh menu 
            cout << "|---- TO-DO LIST ----|" << endl;
            cout << "|1 --   ADD TASK   --|" << endl;
            cout << "|2 --  VIEW TASKS  --|" << endl;
            cout << "|3 -- DELETE TASKS --|" << endl;
            cout << "|e --     EXIT     --|" << endl;
            cin >> option;

            switch (option)
            {
            case 1:
            {
                if (task_count > max_tasks)
                {
                    cout << "Task List is full. Do your other tasks first and clear them." << endl;
                }
                else
                {
                    cout << "Enter a Task : ";
                    // ignore empty spaces
                    cin.ignore();
                    getline(cin, tasks[task_count]);
                    task_count++;
                    
                }
                break;
            }

            case 2:
                system("cls");
                print_tasks(tasks, task_count);
                task_file << tasks;
                
                
                break;
            case 3:
            {
                system("cls");
                print_tasks(tasks, task_count);
                int delete_task = 0;
                cout << "Enter a Task to Delete: ";
                cin >> delete_task;

                if (delete_task < min_tasks || delete_task >> max_tasks)
                {
                    cout << "INVALID TASK NO." << endl;
                    break;
                }
                for (int i = delete_task; i < task_count; i++)
                {
                    tasks[i] = tasks[i + 1];
                }
                task_count = task_count - 1;
            }
            case 'e':
                cout << "Exiting........." << endl;
                task_file.close();
                break;
            default:
                cout << "INVALID VALUE" << endl;
                break;
            }
        }
    }
    else
    {
        cout << "ERROR FINDING THE FILE.";
    }


 
    // std::cout << "Hello World!\n";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

