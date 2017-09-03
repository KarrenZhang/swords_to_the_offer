#include <QCoreApplication>
#include <string.h>
#include <iostream>

using namespace std;

int replace_blank(char* string, int length)
{
    if(string == NULL || length <= 0)
    {
        cout << "Error!" << endl;
        return -1;
    }

    cout << "raw string is: " << string << endl;

    int str_len = strlen(string);
    int blank_counts = 0;

    for(int i = 0; i < str_len; i++)
    {
        if(string[i] == ' ')
        {
            blank_counts++;
        }
    }

    if(blank_counts == 0)
    {
        cout << "There doesn't exist blank!" << endl;
        return 0;
    }

    if((str_len+blank_counts*2) >= length)
    {
        cout << "the space is not enough." << endl;
        return -1;
    }

    string[str_len+blank_counts*2] = '\0';
    char* prev = &string[str_len-1], *back = &string[str_len+blank_counts*2-1];

    //prev >= string的条件是可以去掉的，因为当back == prev时，
    //要么prev == string，要么string中的空格已经替换完了，
    //所以不会发生指针越界
    while(back != prev)
    {
        if(*prev != ' ')
        {
            *(back--) = *prev;
            back--;
        }
        else
        {
            *(back--) = '0';
            *(back--) = '2';
            *(back--) = '%';
        }
        prev--;
    }

    cout << "replaced string is: " << string << endl;

    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char str1[100] =  "I Love Xidian University!";
    char *str2 = NULL;
    char str3[100] = "I";
    char str4[100] = "    I LoveXidianUniversity   ";

    replace_blank(str1, 100);
    replace_blank(str2, 0);
    replace_blank(str3, 100);
    replace_blank(str4, 100);

    return a.exec();
}
