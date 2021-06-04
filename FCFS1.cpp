
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of Processes: ";
    cin >> n;
    cout << "Enter Burst Time for processes: " << endl;
    int bt[n];
    for (int i = 0; i < n; i++)
    {

        cin >> bt[i];
    }

    int wt[n], tat[n], rt[n], ct[n], at[n];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    for (int i = 0; i < n; i++)
    {

        at[i] = 0;
    }
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        total_tat += tat[i];
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        total_wt += wt[i];
    }
    for (int i = 0; i < n; i++)
    {

        rt[i] = wt[i];
    }

    avg_tat = total_tat / float(n);
    avg_wt = total_wt / float(n);

    cout << "id" << '\t' << "AT" << '\t' << "BT" << '\t' << "CT" << '\t' << "TAT" << '\t' << "WT" << '\t' << "RT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << '\t' << at[i] << '\t' << bt[i] << '\t' << ct[i] << '\t' << tat[i] << '\t' << rt[i] << '\t' << rt[i] << '\n';
    }
    cout << "Average Turn Around Time: " << avg_tat << '\n'
         << "Average Waiting Time: " << avg_wt << '\n'
         << "Schedule Length: " << ct[n - 1];
}
