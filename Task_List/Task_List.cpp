// Task_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

#define NOMINMAX

#include <windows.h>


using namespace std;

void printTasks(string tasks[], int task_count)
{
    cout << "|--  TO DO TASKS   --|" << endl;
    cout << "| -----------------  |" << endl;
 
    for (int task = 0; task < task_count; task++)
    {
        cout << "| Task " << task << " : " << tasks[task] << " | " << endl;
        
    }



    cout << "| -----------------  |" << endl;
}

static void showLoadingScreen()
{
    
        Sleep(300);
        cout << R"(_________ _______  _______  _          _       _________ _______ _________)" << "\n" << flush;
        Sleep(300);
        cout << R"(\__   __/(  ___  )(  ____ \| \    /\  ( \      \__   __/(  ____ \\__   __/)" << "\n" << flush;
        Sleep(300);
        cout << R"(   ) (   | (   ) || (    \/|  \  / /  | (         ) (   | (    \/   ) (   )" << "\n" << flush;
        Sleep(300);
        cout << R"(   | |   | (___) || (_____ |  (_/ /   | |         | |   | (_____    | |   )" << "\n" << flush;
        Sleep(300);
        cout << R"(   | |   |  ___  |(_____  )|   _ (    | |         | |   (_____  )   | |   )" << "\n" << flush;
        Sleep(300);
        cout << R"(   | |   | (   ) |      ) ||  ( \ \   | |         | |         ) |   | |   )" << "\n" << flush;
        Sleep(300);
        cout << R"(   | |   | )   ( |/\____) ||  /  \ \  | (____/\___) (___/\____) |   | |   )" << "\n" << flush;
        Sleep(300);
        cout << R"(   )_(   |/     \|\_______)|_/    \/  (_______/\_______/\_______)   )_(   )" << "\n" << flush;
        Sleep(300);
        cout << " ";
        Sleep(300);
        cout << R"(  ___        __  __     _        _   _   _           )" << "\n" << flush;
        cout << R"( | _ )_  _  |  \/  |_ _| |____ _| |_| |_(_)_ _  __ _ )" << "\n" << flush;
        cout << R"( | _ \ || | | |\/| | '_| / / _` |  _| / / | ' \/ _` |)" << "\n" << flush;
        cout << R"( |___/\_, | |_|  |_|_| |_\_\__,_|\__|_\_\_|_||_\__, |)" << "\n" << flush;
        cout << R"(      |__/                                     |___/ )" << "\n" << flush;
        Sleep(1000);
        system("cls");
    
}


int main()
{
	string tasks[10] = { "" };
	// counter 
	int task_count = 0;
	int max_tasks = 6;
	int min_tasks = 0;
	
	// end the program
	int option = -1;
	showLoadingScreen();

	while (option != 0)
	{
		// basic ahh menu 
		cout << "|---- TO-DO LIST ----|" << endl;
		cout << "|1 --   ADD TASK   --|" << endl;
		cout << "|2 --  VIEW TASKS  --|" << endl;
		cout << "|3 -- DELETE TASKS --|" << endl;
		cout << "|0 --     EXIT     --|" << endl;
		cin >> option;

		switch (option)
		{
		case 1:
		{
			if (task_count >= max_tasks)
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
			printTasks(tasks, task_count);
			break;
		case 3:
		{
			system("cls");
			printTasks(tasks, task_count);
			int delete_task;
			cout << "Enter a Task to Delete: ";
			cin >> delete_task;

			if (delete_task < min_tasks || delete_task > max_tasks)
			{
				cout << "INVALID TASK NO." << endl;
				break;
			}
			else
			{
				for (int i = delete_task; i < task_count; i++)
				{
					tasks[i] = tasks[i + 1];
				}
				task_count = task_count - 1;
			}

		}
		case 0:
			break;
		default:
			cout << "INVALID INPUT" << endl;
			break;
		}
	}
}

