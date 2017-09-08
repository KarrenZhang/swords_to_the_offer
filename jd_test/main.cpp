#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int start_num, end_num;

    cin >> start_num >> end_num;

    int start_bits_cnt = 0, end_bits_cnt = 0;
    int start_temp = start_num, end_temp = end_num;

    while(start_temp > 0)
    {
        start_temp /= 10;
        start_bits_cnt++;
    }

    while(end_temp > 0)
    {
        end_temp /= 10;
        end_bits_cnt++;
    }

    cout << start_bits_cnt << " " << end_bits_cnt << endl;

    if(start_bits_cnt == 1 && end_bits_cnt == 1)
    {
        return 0;
    }

    if(1 <= start_bits_cnt <= 2 && 1 <= end_bits_cnt <= 2)
    {
        int counts = 0;
        for(int i = 1; 11*i <= end_num; i++)
        {
            if(11*i >= start_num)
                counts++;
        }
        cout << counts << endl;

        return counts;
    }

    return a.exec();
}
