#include <QCoreApplication>
#include <iostream>

using namespace std;

bool find_in_sorted_matrix(int* matrix, int rows, int columns, int number)
{
    int i,j;
    for(i = 0, j = columns-1; i < rows && j >=0;)
    {
        if(matrix[i*columns+j] > number)
        {
            j--;
        }
        else if(matrix[i*columns+j] < number)
        {
            i++;
        }
        else
        {
            cout << "Find, i is " << i << " , j is " << j << ", matrix[i,j] is " << number << endl;
            return true;
        }
    }

    cout << "Don't Find, i is " << i << " , j is " << j << endl;
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int a2[4][4] = {{1,3,5,6}, {2,4,8,9}, {4,6,9,11}, {6,8,13,15}};

    find_in_sorted_matrix((int*)a2, 4, 4, 3);
    find_in_sorted_matrix((int*)a2, 4, 4, 8);
    find_in_sorted_matrix((int*)a2, 4, 4, 13);
    find_in_sorted_matrix((int*)a2, 4, 4, 19);

    return a.exec();
}
