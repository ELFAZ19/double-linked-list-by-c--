#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string department;
    float gpa;
    Student* prev;
    Student* next;
};

Student* createStudent(int id, string name, int age, string department, float gpa)
{
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->name = name;
    newStudent->age = age;
    newStudent->department = department;
    newStudent->gpa = gpa;
    newStudent->prev = nullptr;
    newStudent->next = nullptr;
    return newStudent;
}

void insertAtBeginning(Student*& head, Student*& tail, int id, string name, int age, string department, float gpa)
{
    Student* newStudent = createStudent(id, name, age, department, gpa);
    if (!head)
    {
        head = tail = newStudent;
    }
    else
    {
        newStudent->next = head;
        head->prev = newStudent;
        head = newStudent;
    }
    cout << "Student inserted at the beginning.\n";
}

void insertAtEnd(Student*& head, Student*& tail, int id, string name, int age, string department, float gpa)
{
    Student* newStudent = createStudent(id, name, age, department, gpa);
    if (!tail)
    {
        head = tail = newStudent;
    }
    else
    {
        newStudent->prev = tail;
        tail->next = newStudent;
        tail = newStudent;
    }
    cout << "Student inserted at the end.\n";
}

void insertAfter(Student* head, Student*& tail, int position, int id, string name, int age, string department, float gpa)
{
    Student* current = head;
    int currentPosition = 1;
    while (current && currentPosition < position)
    {
        current = current->next;
        currentPosition++;
    }
    if (current)
    {
        Student* newStudent = createStudent(id, name, age, department, gpa);
        newStudent->next = current->next;
        newStudent->prev = current;
        if (current->next)
        {
            current->next->prev = newStudent;
        }
        else
        {
            tail = newStudent;
        }
        current->next = newStudent;
        cout << "Student inserted after position " << position << ".\n";
    }
    else
    {
        cout << "Invalid position.\n";
    }
}

void deleteFirst(Student*& head, Student*& tail)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }
    Student* toDelete = head;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete toDelete;
    cout << "First student deleted.\n";
}

void deleteLast(Student*& head, Student*& tail)
{
    if (!tail)
    {
        cout << "List is empty.\n";
        return;
    }
    Student* toDelete = tail;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete toDelete;
    cout << "Last student deleted.\n";
}

void deleteAfter(Student* head, Student*& tail, int position)
{
    Student* current = head;
    int currentPosition = 1;
    while (current && currentPosition < position)
    {
        current = current->next;
        currentPosition++;
    }
    if (current && current->next)
    {
        Student* toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete->next)
        {
            toDelete->next->prev = current;
        }
        else
        {
            tail = current;
        }
        delete toDelete;
        cout << "Student after position " << position << " deleted.\n";
    }
    else
    {
        cout << "Invalid position or no node to delete.\n";
    }
}

void displayForward(Student* head)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }
    Student* current = head;
    while (current)
    {
        cout << "ID: " << current->id << "\n";
        cout << "Name: " << current->name << "\n";
        cout << "Age: " << current->age << "\n";
        cout << "Department: " << current->department << "\n";
        cout << "GPA: " << current->gpa << "\n";
        cout << "-----------------------\n";
        current = current->next;
    }
}

void searchNode(Student* head, int id)
{
    Student* current = head;
    while (current && current->id != id)
    {
        current = current->next;
    }
    if (current)
    {
        cout << "Found Student - \n";
        cout << "ID: " << current->id << "\n";
        cout << "Name: " << current->name << "\n";
        cout << "Age: " << current->age << "\n";
        cout << "Department: " << current->department << "\n";
        cout << "GPA: " << current->gpa << "\n";
    }
    else
    {
        cout << "Student with ID " << id << " not found.\n";
    }
}

void displayBackward(Student* tail)
{
    if (!tail)
    {
        cout << "List is empty.\n";
        return;
    }
    Student* current = tail;
    while (current)
    {
        cout << "ID: " << current->id << "\n";
        cout << "Name: " << current->name << "\n";
        cout << "Age: " << current->age << "\n";
        cout << "Department: " << current->department << "\n";
        cout << "GPA: " << current->gpa << "\n";
        cout << "-----------------------\n";
        current = current->prev;
    }
}

void deleteList(Student* head)
{
    Student* current = head;
    while (current)
    {
        Student* temp = current;
        current = current->next;
        delete temp;
    }
}

void addDemoStudents(Student*& head, Student*& tail)
{

    insertAtEnd(head, tail, 1500785, "Abel ayele",23, "Computer Science", 4);
    insertAtEnd(head, tail,1501750, "Yeabsra Dejene",22, "Computer Science", 4);
    insertAtEnd(head, tail, 1502253, "Trhas Abrha",22, "Computer Science", 4);
    insertAtEnd(head, tail,1502273, "Hebron Solomon",21, "Computer Science", 4);
    insertAtEnd(head, tail,  1501538, "Nebiyu Ermiyas",24, "Computer Science", 4);
    insertAtEnd(head, tail,151077, "Eman Jemal", 21,"Computer Science", 4);

    cout << "Demo mode added 6 students successfully.\n";
}

int main()
{
    Student* head = nullptr;
    Student* tail = nullptr;
    int choice, id, age, locationId;
    string name, department;
    float gpa;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete After\n";
        cout << "7. Display Forward\n";
        cout << "8. Search Node\n";
        cout << "9. Display Backward\n";
        cout << "10. insert by demo\n";
        cout << "11. Exit\n";

        cout << "Enter your choice (1-11): ";
        getline(cin, name);
        cout <<"\n";

        try
        {
            choice = stoi(name);
        }
        catch (const invalid_argument& e)
        {
            cout << "Invalid choice. Please enter a number between 0 and 11.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            try
            {
                 system("CLS");
                cout << "Enter ID: ";
                getline(cin, name);
                id = stoi(name);
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Age: ";
                getline(cin, name);
                age = stoi(name);
                cout << "Enter Department: ";
                getline(cin, department);
                cout << "Enter GPA: ";
                getline(cin, name);
                gpa = stof(name);
                insertAtBeginning(head, tail, id, name, age, department, gpa);
            }
            catch (const invalid_argument& e)
            {
                cout << "Invalid input. Please enter valid values.\n";
            }
            break;

        case 2:
            try
            {
                 system("CLS");
                cout << "Enter ID: ";
                getline(cin, name);
                id = stoi(name);
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Age: ";
                getline(cin, name);
                age = stoi(name);
                cout << "Enter Department: ";
                getline(cin, department);
                cout << "Enter GPA: ";
                getline(cin, name);
                gpa = stof(name);
                insertAtEnd(head, tail, id, name, age, department, gpa);
            }
            catch (const invalid_argument& e)
            {
                cout << "Invalid input. Please enter valid values.\n";
            }
            break;

        case 3:
            try
            {
                 system("CLS");
                cout << "Enter the position for inserting after: ";
                getline(cin, name);
                locationId = stoi(name);
                cout << "Enter ID: ";
                getline(cin, name);
                id = stoi(name);
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Age: ";
                getline(cin, name);
                age = stoi(name);
                cout << "Enter Department: ";
                getline(cin, department);
                cout << "Enter GPA: ";
                getline(cin, name);
                gpa = stof(name);
                insertAfter(head, tail, locationId, id, name, age, department, gpa);
            }
            catch (const invalid_argument& e)
            {
                cout << "Invalid input. Please enter valid values.\n";
            }
            break;

        case 4:
             system("CLS");
            deleteFirst(head, tail);
            break;

        case 5:
            deleteLast(head, tail);
            break;

        case 6:
            try
            {
                 system("CLS");
                cout << "Enter the position to delete after: ";
                getline(cin, name);
                locationId = stoi(name);
                deleteAfter(head, tail, locationId);
            }
            catch (const invalid_argument& e)
            {
                cout << "Invalid input.\n";
            }
            break;

        case 7:
             system("CLS");
            displayForward(head);
            break;

        case 8:
            try
            {
                 system("CLS");
                cout << "Enter ID to search: ";
                getline(cin, name);
                id = stoi(name);
                searchNode(head, id);
            }
            catch (const invalid_argument& e)
            {
                cout << "Invalid input.\n";
            }
            break;

        case 9:
             system("CLS");
            displayBackward(tail);
            break;
        case 10:
             system("CLS");
            addDemoStudents(head, tail);
            break;
        case 11:
             system("CLS");
            cout << "Exiting...\n";
            break;

        default:
             system("CLS");
            cout << "Invalid choice. Please try again.\n";
        }

    }
    while (choice != 11);

    deleteList(head);
    return 0;
}
