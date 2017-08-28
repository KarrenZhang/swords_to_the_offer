#include <QCoreApplication>
#include <iostream>

using namespace std;

/*!
 * \brief find_min
 *  找到旋转数组中的最小值并返回
 * \param array
 *  旋转数组
 * \param len
 *  旋转数组长度
 * \return
 *  旋转数组中的最小值
 */
int find_min(int* array, int len)
{
    //判断输入的有效性
    if(array == NULL || len <= 0)
    {
        cout << "Input Error!"<< endl;
        return -1;
    }

    //特例1，旋转数组未旋转
    if(array[0] < array[len-1])
    {
        cout << "In rotated array, min num is " << array[0] << endl;
        return array[0];
    }

    int left = 0, right = len-1;
    int mid = (left+right)/2;
    //采用二分查找法查找循环数组最小数，结束时left指针
    //指向数组中的最大值，right指向数组中的最小值
    while(right-left != 1)
    {
        if(array[left] < array[mid])
        {
            left = mid;
        }
        else if(array[right] > array[mid])
        {
            right = mid;
        }
        else if(array[left] == array[mid] && array[mid] == array[right])
        {
            int min = array[left];
            for(int i = left+1; i <= right; i++)
            {
                if(min > array[i])
                {
                    min = array[i];
                }
            }
            cout << "In rotated array, min num is " << min << endl;
            return min;
        }
        mid = (left+right)/2;
    }

    cout << "In rotated array, min num is " << array[right] << endl;
    return array[mid];
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int a1[] = {4,5,7,8,0,1,3};
    int a2[] = {1,1,1,1,0,1,1};
    int a3[] = {1,2,3,4,5,6,8};
    find_min(a1, sizeof(a1)/sizeof(int));
    find_min(a2, sizeof(a2)/sizeof(int));
    find_min(a3, sizeof(a3)/sizeof(int));

    return a.exec();
}
