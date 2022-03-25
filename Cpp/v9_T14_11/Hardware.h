#ifndef _HARDWARE_H
#define _HARDWARE_H

#include <string>
#include <stdexcept>
using namespace std;

class Hardware
{
public:
    //构造函数
    Hardware(int = 0, const string & = "", int = 0, double = 0.0);

    //设置记录号
    void setToolNumber(int);
    //返回记录号
    int getToolNumber() const;

    //设置工具名称
    void setToolName(const string &);
    //返回工具名称
    string getToolName() const;

    //设置工具数量
    void setToolQuantity(int);
    //返回工具数量
    int getToolQuantity() const;

    //设置工具价格
    void SetToolPrice(double);
    //返回工具价格
    double getToolPrice() const;

private:
    int ToolNumber_;    //工具编号
    char ToolName_[50]; //工具名称
    int ToolQuantity_;  //工具数量
    double ToolPrice_;   //工具价格
};

Hardware::Hardware(int tool_number, const string &tool_name, int tool_quantity, double tool_price)
    : ToolNumber_(tool_number)
{
    setToolName(tool_name);
    setToolQuantity(tool_quantity);
    SetToolPrice(tool_price);
}

//设置记录号
void Hardware::setToolNumber(int tool_number)
{
    ToolNumber_ = tool_number;
}
//返回记录号
int Hardware::getToolNumber() const
{
    return ToolNumber_;
}

//设置工具名称
void Hardware::setToolName(const string &tool_name)
{
    int length = tool_name.size();
    length = (length < 50 ? length : 49);
    tool_name.copy(ToolName_, length);
    ToolName_[length] = '\0';
}
//返回工具名称
string Hardware::getToolName() const
{
    return ToolName_;
}

//设置工具数量
void Hardware::setToolQuantity(int tool_quantity)
{
    if (tool_quantity >= 0)
        ToolQuantity_ = tool_quantity;
    else
        throw invalid_argument("quantity of tool should be greater than 0");
}
//返回工具数量
int Hardware::getToolQuantity() const
{
    return ToolQuantity_;
}

//设置工具价格
void Hardware::SetToolPrice(double tool_price)
{
    if (tool_price >= 0.0)
        ToolPrice_ = tool_price;
    else
        throw invalid_argument("price of tool should be greater than 0");
}
//返回工具价格
double Hardware::getToolPrice() const
{
    return ToolPrice_;
}
#endif