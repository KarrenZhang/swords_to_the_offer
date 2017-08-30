#ifndef CMYSTRING_H
#define CMYSTRING_H

#include <string.h>

class CMyString {
public:
    CMyString(char* pData = NULL);
    //考察点1：复制构造函数、赋值函数的形参为常量引用
    //复制构造函数
    CMyString(const CMyString& str);
    //赋值构造函数
    CMyString& operator =(const CMyString& str);
    ~CMyString(void);
private:
    char* m_pData;
};

#endif // CMYSTRING_H
