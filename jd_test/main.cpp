#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int start_num, end_num;

    cout << "haha" << endl;
    cin >> start_num >> end_num;

    int start_bits_cnt = 0, end_bits_cnt = 0;
    int start_temp = start_num, end_temp = start_num;

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

    return a.exec();
}
