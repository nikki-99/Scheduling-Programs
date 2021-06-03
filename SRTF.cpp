#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;

struct pinfo
{
    int id;
    int AT;
    int BT;
    int ST;
    int CT;
    int TAT;
    int WT;
};

int main()
{
    int n;
    cout << "Enter number of Processes: ";
    cin >> n;
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));
    int burst_remaining[100];
    int total_TAT, total_WT, schedule_length;
    float avg_TAT, avg_WT;
    int current_time = 0;
    int completed = 0;
    int j = 1;
    pinfo info[n];
    for (int i = 0; i < n; i++)
    {
        info[i].id = i + 1;
    }
    cout << "Enter Arrival Time for processes: " << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> info[i].AT;
    }
    cout << "Enter Burst Time for processes: " << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> info[i].BT;
        burst_remaining[i] = info[i].BT;
    }

    while (completed != n)
    {
        int index = -1;
        int mn = 1000000;
        for (int i = 0; i < n; i++)
        {
            if (info[i].AT <= current_time && is_completed[i] == 0)
            {
                if (burst_remaining[i] < mn)
                {
                    mn = burst_remaining[i];
                    index = i;
                }
            }
            if (burst_remaining[i] == mn)
            {
                if (info[i].AT < info[index].AT)
                {
                    mn = burst_remaining[i];
                    index = i;
                }
            }
        }

        if (index != -1)

        {
            if (burst_remaining[index] == info[index].BT)
            {

                info[index].ST = current_time;
            }
            burst_remaining[index] = burst_remaining[index] - 1;
            current_time = current_time + 1;
            if (burst_remaining[index] == 0)
            {

                info[index].CT = current_time;

                info[index].TAT = info[index].CT - info[index].AT;
                info[index].WT = info[index].TAT - info[index].BT;

                total_TAT += info[index].TAT;
                total_WT += info[index].WT;

                is_completed[index] = 1;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }
    avg_TAT = total_TAT / float(n);
    avg_WT = total_WT / float(n);
    int min_AT = 100000, max_CT = -999;
    for (int i = 0; i < n; i++)
    {
        if (info[i].AT < min_AT)
        {
            min_AT = info[i].AT;
        }
        if (info[i].CT > max_CT)
        {
            max_CT = info[i].CT;
        }
    }

    cout << "id" << '\t' << "AT" << '\t' << "BT" << '\t' << "CT" << '\t' << "TAT" << '\t' << "WT\n";
    for (int i = 0; i < n; i++)
    {
        cout << info[i].id << '\t' << info[i].AT << '\t' << info[i].BT << '\t' << info[i].CT << '\t' << info[i].TAT << '\t' << info[i].WT << '\n';
    }
    cout << "Average Turn Around Time: " << avg_TAT << '\n'
         << "Average Waiting Time: " << avg_WT << '\n'
         << "Schedule Length: " << max_CT - min_AT;
}
