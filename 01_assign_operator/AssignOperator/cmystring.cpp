#include "cmystring.h"

CMyString::CMyString(char *pData)
{
    if(pData != NULL)
    {
        this->m_pData = new char[strlen(pData)+1];
        strcpy(this->m_pData, pData);
    }
    else
    {
        this->m_pData = pData;
    }
}

CMyString::CMyString(const CMyString &str)
{
    if(str.m_pData != NULL)
    {
        this->m_pData = new char[strlen(str.m_pData)+1];
        strcpy(this->m_pData, str.m_pData);
    }
    else
    {
        this->m_pData = NULL;
    }
}

//第一种方法：初级C++程序员
/*
CMyString& CMyString::operator =(const CMyString& str)
{
    //考察点2：赋值函数的返回值为类型引用
    if(this == &str)
    {
        return *this;
    }

    //考察点3：释放对象自身已有的内存资源
    if(this->m_pData != NULL)
    {
        delete[] this->m_pData;
        this->m_pData = NULL;
    }
    //考察点4：判断传入的引用参数不是自身
    this->m_pData = new char[strlen(str.m_pData)+1];
    strcpy(this->m_pData, str.m_pData);

    return *this;
}
*/

//第二种方法：高级C++程序员
CMyString& CMyString::operator =(const CMyString& str)
{
    if(this != &str)
    {
        CMyString tempStr = str;

        char* temp = tempStr.m_pData;
        tempStr.m_pData = this->m_pData;
        this->m_pData = temp;
    }

    return *this;
}

CMyString::~CMyString()
{
    delete[] this->m_pData;
}
