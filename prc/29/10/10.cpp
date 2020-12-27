#include <iostream>
#include<windows.h>//для видимости таблицы
#include <string>//для работы со строками

using namespace std;
struct Classes
{
    const int Student = 10;
    char history;
    char informatic;
    char physics;
    char math;
};
struct Student
{
    char name[32];
    int group;
    Classes marking;
    int exams;
    bool loaner;
};
void showData(const Student Obj[], int amount)
{
    system("cls");
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Имя |\t" << "Группа |" << " Физика |" << " Маткматика |" << " История  |" << " Информатика |" << " Должник |" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << Obj[i].name << '\t' << Obj[i].group << '\t' << '\t' << Obj[i].marking.history << '|' << '\t' << '\t' << Obj[i].marking.informatic << '|' << '\t' << '\t' << Obj[i].marking.physics << '|' << '\t' << '\t' << Obj[i].marking.math << '|' << '\t' << Obj[i].loaner << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    int l;
    l = 0;
    
    const int n = 10;
    Student Student[n] = {};

    for (int i = 0; i < n; i++)
    {

        cout << "ФИО студента";
        cin.getline(Student[i].name, 32);
        cout << "Група";
        cin >> Student[i].group;
        cout << "Оценка по истории";
        cin >> Student[i].exams;
        if ((Student[i].exams >= 2) && (Student[i].exams <= 5)) 
        {
            cin >> Student[i].marking.history;
            if (Student[i].exams == 2)
            {
                Student[i].loaner = 1;
                l++;
            }
            else 
                if (Student[i].exams != 2)
                {
                Student[i].loaner = 0;
            }
        }
        cout << "Оценка по информатике";
        cin >> Student[i].exams;
        if ((Student[i].exams >= 2) && (Student[i].exams <= 5))
        {
            cin >> Student[i].marking.informatic;
            if (Student[i].exams == 2)
            {
                Student[i].loaner = 1;
                l++;
            }
            else if (Student[i].exams != 2)
            {
                Student[i].loaner = 0;
            }
        }
        cout << "Оценка по физике";
        cin >> Student[i].exams;
        if ((Student[i].exams >= 2) && (Student[i].exams <= 5))
        {
            cin >> Student[i].marking.physics;
            if (Student[i].exams == 2) {
                Student[i].loaner = 1;
                l++;
            }
            else if (Student[i].exams != 2)
            {
                Student[i].loaner = 0;
            }
        }
        cout << "Оценка по математике";
        cin >> Student[i].exams;
        if ((Student[i].exams >= 2) && (Student[i].exams <= 5)) 
        {
            cin >> Student[i].marking.math;
            if (Student[i].exams == 2)
            {
                Student[i].loaner = 1;
                l++;
            }
            else if (Student[i].exams != 2) 
            {
                Student[i].loaner = 0;
            }
        }
        cin.get();
    }
    showData(Student, n);//вывод на экран результата
}
