#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int string_split(string& input_string)
{
    string output_string;

    int dot_pos = input_string.find_first_of('.');
    int str_len = input_string.length();
    cout << "dot pos " << dot_pos << "str_len" << str_len <<endl;

    int underline_counts = 0;
    output_string[0] = '_';
    underline_counts++;


    for(unsigned int i = 0; i < input_string.length(); i++)
    {
        for(;i < dot_pos;i++)
        {
            output_string[i+underline_counts] = input_string[i] & 223;
        }
        if(i == dot_pos)
        {
            output_string[i+underline_counts] = '_';
            underline_counts++;
        }

        if('a' <= input_string[i] <= 'z' && 'A' <= input_string[i+1] <= 'Z')
        {
            output_string[i+underline_counts] = input_string[i] & 223;
            output_string[i+underline_counts+1] = '_';
            underline_counts++;
        }
        if('A' <= input_string[i] <= 'Z' && 'A' <= input_string[i+1] <= 'Z'
                && 'a' <= input_string[i+2] <= 'z')
        {
            output_string[i+underline_counts] = input_string[i] & 223;
            output_string[i+underline_counts+1] = '_';
            underline_counts++;
        }

        if('0' <= input_string[i] <= '9')
        {
            output_string[i+underline_counts] = input_string[i];
        }
        output_string[i+underline_counts] = input_string[i] & 223;
    }

    cout >> output_string >> endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<string> input_string;
    string temp_str;

    cin >> temp_str;
    while(!temp_str.empty())
    {
        input_string.push_back(temp_str);
        cin >> temp_str;
    }

    for(int i = 0; i < input_string.size(); i++)
    {
        string_split(input_string[i]);
    }

    return a.exec();
}
