// Os1lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include<iostream>

using namespace std;


// Функция поиска времени ожидания для всех
// процессы

void findWaitingTime(int processes[], int n,

    int bt[], int wt[], int quantum)

{

    // Создаем копию времени всплеска bt [], чтобы сохранить оставшиеся

    // время всплеска

    int rem_bt[10];

    for (int i = 0; i < n; i++)

        rem_bt[i] = bt[i];



    int t = 0; // Текущее время



    // Сохраняем процессы обхода

    // пока все они не завершены.

    while (1)

    {

        bool done = true;



        // Пройти все процессы один за другим несколько раз

        for (int i = 0; i < n; i++)

        {

            // Если время пакета процесса больше 0

            // тогда нужно только обрабатывать дальше

            if (rem_bt[i] > 0)

            {

                done = false; // есть ожидающий процесс



                if (rem_bt[i] > quantum)

                {

                    // Увеличиваем значение t т.е. показывает

                    // сколько времени процесс был обработан

                    t += quantum;



                    // Уменьшаем burst_time текущего процесса

                    // по кванту

                    rem_bt[i] -= quantum;

                }



                // Если время пакета меньше или равно

                // квант. Последний цикл для этого процесса

                else

                {

                    // Увеличиваем значение t т.е. показывает

                    // сколько времени процесс был обработан

                    t = t + rem_bt[i];



                    // Время ожидания - текущее время минус время

                    // используется этим процессом

                    wt[i] = t - bt[i];



                    // Поскольку процесс полностью выполняется

                    // сделать оставшееся время всплеска = 0

                    rem_bt[i] = 0;

                }

            }

        }



        // Если все процессы завершены

        if (done == true)

            break;

    }

}


// Функция для вычисления времени оборота

void findTurnAroundTime(int processes[], int n,

    int bt[], int wt[], int tat[])

{

    // вычисление времени выполнения путем добавления

    // bt [i] + wt [i]

    for (int i = 0; i < n; i++)

        tat[i] = bt[i] + wt[i];

}


// Функция для расчета среднего времени

void findavgTime(int processes[], int n, int bt[], int quantum)

{ 
     

    int wt[10], tat[10], total_wt = 0, total_tat = 0;



    // Функция для определения времени ожидания всех процессов

    findWaitingTime(processes, n, bt, wt, quantum);



    // Функция поиска времени оборота для всех процессов

    findTurnAroundTime(processes, n, bt, wt, tat);



    // Отображение процессов вместе со всеми деталями

    cout << "Processes " << " Burst time "

        << " Waiting time " << " Turn around time\n";



    // Рассчитать общее время ожидания и общий оборот

    // вокруг времени

    for (int i = 0; i < n; i++)

    {

        total_wt = total_wt + wt[i];

        total_tat = total_tat + tat[i];

        cout << " " << i + 1 << "\t\t" << bt[i] << "\t "

            << wt[i] << "\t\t " << tat[i] << endl;

    }



    cout << "Average waiting time = "

        << (float)total_wt / (float)n;

    cout << "\nAverage turn around time = "

        << (float)total_tat / (float)n;

}


// Код драйвера

int main()

{

    // идентификаторы процесса

    int processes[] = { 1, 2, 3 };

    int n = sizeof processes / sizeof processes[0];



    // Время всплеска всех процессов

    int burst_time[] = { 10, 5, 8 };



    // Квант времени

    int quantum = 2;

    findavgTime(processes, n, burst_time, quantum);

    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
