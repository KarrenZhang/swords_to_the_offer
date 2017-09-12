#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

/*!
 * \brief one_counts_in_binary_error
 * 错误的算法思想：对输入数字采用右移的方法和
 * 无符号数1进行相与，如果值为1，counts加1；为
 * 了避免有符号数右移引入的1补位问题，先对有符号
 * 数取绝对值，计算取绝对值后的数字的1的个数，最
 * 后再加1；这样做的错误原因是，计算机中有符号数
 * 的表示并非采用原码，因为其有“a+(-a)!=0”、“0
 * 的表示法有正0和负0”两个问题，反码解决了第一个
 * 问题，补码在反码的基础上，解决了第二个问题。所
 * 以，计算机中有符号数采用补码表示。
 * \param number
 * \return
 */
int one_counts_in_binary_error(int number)
{
    unsigned int counts = 0;
    int signed_flag = 0;
    unsigned int and_flag = 1;
    if(number < 0)
    {
        number = abs(number);
        signed_flag = 1;
    }
    while(number>0)
    {
        if(number&and_flag)
            counts++;
        number = number>>1;
    }
    if(signed_flag)
        counts++;
    cout << counts << endl;
    return counts;

}


/*!
 * \brief one_counts_in_binary_right
 * 算法思想：不改变输入数字，对相与标志采用左移的
 * 思路，如果相与后结果为1，表明输入数字的该位置上
 * 值为1，累加计数；
 * \param number
 * \return
 */
int one_counts_in_binary_right(int number)
{
    unsigned int counts = 0;
    unsigned int and_flag = 1;

    while(and_flag != 0)
    {
        if(number&and_flag)
            counts++;
        and_flag = and_flag<<1;
    }

    cout << counts << endl;

    return counts;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    one_counts_in_binary_error(5);
    one_counts_in_binary_right(10);
    cout << endl;

    one_counts_in_binary_error(-1);
    one_counts_in_binary_right(-1);
    cout << endl;

    one_counts_in_binary_error(-7483);
    one_counts_in_binary_right(-7483);
    cout << endl;

    one_counts_in_binary_error(-2147483648);
    one_counts_in_binary_right(-2147483648);
    cout << endl;


    return a.exec();
}
