//v9_T14_13
//判断计算机系统上各种数据类型的大小，以字节为单位
//将结果写入datasize.dat
#include<fstream>
#include<iomanip>
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    fstream outData("datasize.dat",ios::out);

    if(!outData)
    {
        cerr<<"File could not be opened"<<endl;
        exit(EXIT_FAILURE);
    }//打开文件失败并返回错误信息。并退出

    outData
    <<setw(20)<<left<<"char"<<setw(4)<<right<<sizeof(char)<<endl
    <<setw(20)<<left<<"unsigned char"<<setw(4)<<right<<sizeof(unsigned char)<<endl
    <<setw(20)<<left<<"short int"<<setw(4)<<right<<sizeof(short int)<<endl
    <<setw(20)<<left<<"unsigned short int"<<setw(4)<<right<<sizeof(unsigned short int)<<endl
    <<setw(20)<<left<<"int"<<setw(4)<<right<<sizeof(int)<<endl
    <<setw(20)<<left<<"unsigned int"<<setw(4)<<right<<sizeof(unsigned int)<<endl
    <<setw(20)<<left<<"long int"<<setw(4)<<right<<sizeof(long int)<<endl
    <<setw(20)<<left<<"unsigned long int"<<setw(4)<<right<<sizeof(unsigned long int)<<endl
    <<setw(20)<<left<<"float"<<setw(4)<<right<<sizeof(float)<<endl
    <<setw(20)<<left<<"double"<<setw(4)<<right<<sizeof(double)<<endl
    <<setw(20)<<left<<"long double"<<setw(4)<<right<<sizeof(long double)<<endl;
    system("pause");
}