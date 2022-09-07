#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct cdata
{
	string name, surname;
	int age;
	float salary;
};

bool ext = false;
vector<cdata> workers;

void addworker(cdata wd)
{
	workers.push_back(wd);
}

int requestInt(string txt)
{
	int dt;
	printf("%s\n",txt.c_str());
	cin >> dt;
	return dt;
}

float requestFloat(string txt)
{
	float dt;
	printf("%s\n", txt.c_str());
	cin >> dt;
	return dt;
}

string requestString(string txt)
{
	string dt;
	printf("%s\n", txt.c_str());
	getline(cin,dt);
	return dt;
}

void addworkerRoutine()
{
	cdata work = {"","",0,0};
	work.name = requestString("Enter Name:");
	work.surname = requestString("Enter Surame:");
	work.age = requestInt("Enter Age:");
	work.salary = requestFloat("Enter Salary:");
	addworker(work);
}

void printworkers()
{
	int l = workers.size();
	if (l > 0)
		for (int i = 0; i < l; i++)
		{
			printf("%d) %s %s, %d yrs., $%f\n", i, workers[i].name.c_str(), workers[i].surname.c_str(),
				workers[i].age, workers[i].salary);
		}
	else
		printf("Worker DB empty\n");
}

void mainmenu()
{
	int act = requestInt("Main menu\nSelect action: 1 - Add; 2 - Print; 3 - Quit");
	switch (act)
	{
	case 1:
	{
		//add worker
		addworkerRoutine();
		break;
	}
	case 2:
	{
		printworkers();
		break;
	}
	case 3:
	{
		ext = true;
		break;
	}
	default:
	{
		printf("Unknown command\n");
	}
	}
}

int main()
{
	while (true)
	{
		mainmenu();
		if (ext) break;
	}
	system("pause");
}
