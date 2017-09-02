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
        //特例2：左、中、右三个元素相等，采用顺序查找法
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
    return array[right];
}

/*!
 * \brief find_min_index
 *  返回旋转数组中的最小元素的下标
 * \param array
 *  旋转数组
 * \param len
 *  旋转数组长度
 * \return
 *  最小元素的下标
 */
int find_min_index(int* array, int len)
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
        cout << "In rotated array, min_index is 0" << endl;
        return 0;
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
        //特例2：左、中、右三个元素相等，采用顺序查找法
        else if(array[left] == array[mid] && array[mid] == array[right])
        {
            int min_index = left;
            for(int i = left+1; i <= right; i++)
            {
                if(array[min_index] > array[i])
                {
                    min_index = i;
                }
            }
            cout << "In rotated array, min_index is " << min_index << endl;
            return min_index;
        }
        mid = (left+right)/2;
    }

    cout << "In rotated array, min_index is " << right << endl;
    return right;
}

/*!
 * \brief binary_search
 *  二分查找算法
 * \param p
 *  待查找数组
 * \param left
 *  起始查找位置
 * \param right
 *  结束查找位置
 * \param m
 *  待查找元素
 * \return
 *  成功，返回元素下标；失败，返回-1.
 */
int binary_search(int* p, int start, int end, int num)
{
    int left = start;
    int right = end-1;
    int mid;
	//如果right = end，则以下两处需要修改：
	//1. 循环条件：while(left < right)；
	//2. 循环内p[mid] > num时，right = mid；
    while(left <= right)
    {
		//防止溢出，同时移位更高效
		//若写作"mid = (left+right)/2"，left+right的值可能会超出int类型
		//(或其它类型)的最大值，导致mid的值为负；
		mid = left + ((right-left)>>1);
        if(num > p[mid])
        {
			//p[mid]的值已经比较过，可忽略，所以可将left指向下一个值
            left = mid+1;
        }
        else if(num < p[mid])
        {
			//同num > p[mid]
            right = mid-1;
        }
        else
        {
            cout << "Find m! Its index is " << mid << endl;
            return mid;
        }
    }
    cout << "Dont't Find m!" << endl;
    return -1;
}

/*!
 * \brief find_num
 *  在旋转数组中查找元素m，若数组中存在该元素，则返回它的下标；
 *  如果不存在，则返回-1.
 * \param p
 *  旋转数组指针
 * \param len
 *  旋转数组长度
 * \param m
 *  待查找元素
 * \return
 *  成功，返回元素下标；失败，返回-1.
 */
int find_num(int* p, int len, int m)
{
    if(p == NULL || len < 0)
    {
        return -1;
    }

    int min_index = find_min_index(p, len);

    if(min_index == 0)
    {
        if(m < p[0] || m > p[len-1])
        {
            return -1;
        }
        return binary_search(p, 0, len-1, m);
    }

    if(m < p[min_index] || m > p[min_index-1])
    {
        return -1;
    }
    if(m >= p[0])
    {
        return binary_search(p, 0, min_index-1, m);
    }
    else if(m < p[len-1])
    {
        return binary_search(p, min_index, len-1, m);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int a1[] = {4,5,7,8,0,1,3};
    int a2[] = {1,1,1,1,0,1,1};
    int a3[] = {1,2,3,4,5,6,8};
//    find_min(a1, sizeof(a1)/sizeof(int));
//    find_min(a2, sizeof(a2)/sizeof(int));
//    find_min(a3, sizeof(a3)/sizeof(int));
    find_num(a1, sizeof(a1)/sizeof(int), 7);
    find_num(a2, sizeof(a2)/sizeof(int), 1);
    find_num(a3, sizeof(a3)/sizeof(int), 5);

    return a.exec();
}
