//v9_T14_11
//硬件清单，将数据存储在文件hardware.dat上
/*
记录号      工具名称            数量    价格
3           Electric sander     7       57.98
17          Hammer              76      11.99
24          Jig saw             21      11.00
39          Lawn mower          3       79.50
56          Power saw           18      99.99
68          Screwdriver         106     6.99
77          Sledge hammer       11      21.50
83          Wrench              34      7.50
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Hardware.h"
using namespace std;

int enterChoice();
int enterupdateChoice();
void createTextFile(fstream &);
void updateRecord(fstream &);
void newRecord(fstream &);
void deleteRecord(fstream &);
void outputLine(ostream &, const Hardware &);
int getHardwareNumber(const char *const);
bool isempty(int, fstream &); //判断当前硬件的编号是否已经使用
void updateNumber(fstream &, Hardware &, int);

enum Choices
{
    PRINT = 1,
    UPDATE,
    NEW,
    DELETE,
    END
};
enum updateChoices
{
    NUMBER = 1,
    NAME,
    QUANTITY,
    PRICE,
    EXIT
};

int main()
{
    fstream inOutHardware("hardware.dat", ios::in | ios::out | ios::binary);

    if (!inOutHardware)
    {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    } //文件打开失败是返回错误信息，并退出

    Hardware hardwarelist; //创建空对象

    //将空对象写入文件
    for (int i = 0; i < 100; i++)
    {
        inOutHardware.write(reinterpret_cast<const char *>(&hardwarelist), sizeof(Hardware));
    }

    //声明初始化变量
    int ini_hardwareNumber[8] =
        {3, 17, 24, 39,
         56, 68, 77, 83};
    string ini_hardwareName[8] =
        {"Electric sander", "Hammer",
         "Jig saw", "Lawn mower",
         "Power saw", "Screwdriver",
         "Sledge hammer", "Wrench"};
    int ini_hardwareQuantity[8] =
        {7, 76, 21, 3,
         18, 106, 11, 34};
    double ini_hardwarePrice[8] =
        {57.98, 11.99, 11.00, 79.50,
         99.99, 6.99, 21.50, 7.50};

    //创建初始化用的对象
    Hardware ini_hardwarelist;

    //将初始化信息写入文件
    for (int i = 0; i < 8; i++)
    {
        //将初始化信息读入对象
        ini_hardwarelist.setToolNumber(ini_hardwareNumber[i]);
        ini_hardwarelist.setToolName(ini_hardwareName[i]);
        ini_hardwarelist.setToolQuantity(ini_hardwareQuantity[i]);
        ini_hardwarelist.SetToolPrice(ini_hardwarePrice[i]);

        //将指针移动到对应的位置
        inOutHardware.seekp((ini_hardwareNumber[i] - 1) * sizeof(Hardware));

        //将数据写入文件
        inOutHardware.write(reinterpret_cast<char *>(&ini_hardwarelist), sizeof(Hardware));
    }

    int choice; //store user choice

    while ((choice = enterChoice()) != END)
    {
        switch (choice)
        {
        case PRINT:
            createTextFile(inOutHardware);
            break;
        case UPDATE:
            updateRecord(inOutHardware);
            break;
        case NEW:
            newRecord(inOutHardware);
            break;
        case DELETE:
            deleteRecord(inOutHardware);
            break;
        default:
            cerr << "Incorrect choices" << endl;
            break;
        } //end switch

        inOutHardware.clear();
    } //end while
}

//enable user to input menu choice
int enterChoice()
{
    //display available options
    cout
        << "\nEnter your choice" << endl
        << "1 - store a formatted text file of hardwarelist" << endl
        << "    called \"print.txt\" for printing" << endl
        << "2 - update an hardwarelist" << endl
        << "3 - add a new hardwarelist" << endl
        << "4 - delete an hardwarelist" << endl
        << "5 - end program\n? ";

    int menuChoice;
    cin >> menuChoice; //从用户中输入选项
    return menuChoice;
}

//enable user to input choice to update
int enterupdateChoice()
{
    //display available options
    cout
        << "\nEnter your choice to update:" << endl
        << "1 - number" << endl
        << "2 - name" << endl
        << "3 - quantity" << endl
        << "4 - price" << endl
        << "5 - exit\n? ";

    int updatechoices;
    cin >> updatechoices;
    return updatechoices;
}

//creat formatted text file for printing
void createTextFile(fstream &readFromFile)
{
    //creat text File
    ofstream outPrintFile("print.txt", ios::out);

    //如果失败则退出程序
    if (!outPrintFile)
    {
        cerr << "File could not be created." << endl;
        exit(EXIT_FAILURE);
    }

    //output column heads
    outPrintFile
        << left << setw(12) << "记录号" << setw(20) << "工具名称"
        << setw(8) << "数量" << right << setw(8) << "价格" << endl;

    //将指针移向文件开头
    readFromFile.seekg(0);

    //read first record from recoed file
    Hardware hardwarelist;
    readFromFile.read(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));

    while (!readFromFile.eof())
    {
        //write single record to text File
        if (hardwarelist.getToolNumber() != 0) //跳过空记录
        {
            outputLine(outPrintFile, hardwarelist);
            // outputLine(cout, hardwarelist);
        }

        //read next record from record file
        readFromFile.read(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));
    } //end while
} //end function createTExtFile

//update hardwarelist in record
void updateRecord(fstream &updateFile)
{
    //obtain number of hardware to update
    int hardwareNumber = getHardwareNumber("Enter account to update");

    //将指针移动到对应位置
    updateFile.seekg((hardwareNumber - 1) * sizeof(Hardware));

    //read first record from file
    Hardware hardwarelist;
    updateFile.read(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));

    //update record
    if (hardwarelist.getToolNumber() != 0)
    {
        outputLine(cout, hardwarelist); //display the cord

        //要更新的数据
        int toolnumber, toolquantity;
        string toolname;
        double toolprice;
        int updatechoices;

        while ((updatechoices = enterupdateChoice()) != EXIT)
        {
            switch (updatechoices)
            {
            case NUMBER:
                cout << "Please enter tool number:";
                cin >> toolnumber;
                if (isempty(toolnumber, updateFile))
                {
                    hardwarelist.setToolNumber(toolnumber);
                    updateNumber(updateFile, hardwarelist, hardwareNumber);
                } //end if
                else
                    cout << "The current number already exists" << endl;
                break;
            case NAME:
                cout << "Please enter tool name:";
                fflush(stdin);
                getline(cin, toolname);
                // cin >> toolname;
                hardwarelist.setToolName(toolname);
                break;
            case QUANTITY:
                cout << "Please enter tool quantity:";
                cin >> toolquantity;
                hardwarelist.setToolQuantity(toolquantity);
                break;
            case PRICE:
                cout << "Please enter tool price:";
                cin >> toolprice;
                hardwarelist.SetToolPrice(toolprice);
            default:
                cerr << "Incorrect choices" << endl;
                break;
            }                           //end switch
        }                               //end while
        outputLine(cout, hardwarelist); //display the record

        //将指针移动到对应位置
        updateFile.seekp((hardwarelist.getToolNumber() - 1) * sizeof(Hardware));

        //写入数据，更新旧记录
        updateFile.write(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));
    }    //end if
    else //display error if hardnumber does not exist
        cerr << "Hardware #" << hardwareNumber << " has no information." << endl;
} //end function updateRecord

//creat and insert record
void newRecord(fstream &insertInFile)
{
    //botain number of hardware to creat
    int hardwareNumber = getHardwareNumber("Enter new hardware number");

    //将指针移动到对应的位置
    insertInFile.seekg((hardwareNumber - 1) * sizeof(Hardware));

    //read record from file
    Hardware hardwarelist;
    insertInFile.read(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));

    //如果当前位置是空的，就创建记录
    if (hardwarelist.getToolNumber() == 0)
    {
        int toolnumber, toolquantity;
        string toolname;
        double toolprice;

        toolnumber = hardwareNumber;
        //用户输入数据
        cout << "\nEnter tool name:";
        fflush(stdin);
        getline(cin, toolname);
        cout << "\nEnter tool quantity:";
        cin >> toolquantity;
        cout << "\nEnter tool price:";
        cin >> toolprice;

        //将数据存入对对象中
        hardwarelist.setToolNumber(toolnumber);
        hardwarelist.setToolName(toolname);
        hardwarelist.setToolQuantity(toolquantity);
        hardwarelist.SetToolPrice(toolprice);

        //将指针移动到对应的位置
        insertInFile.seekp((hardwareNumber - 1) * sizeof(Hardware));

        //插入数据
        insertInFile.write(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));
    }    //end if
    else //如果该位置已存在，显示错误信息
        cerr << "Hardware #" << hardwareNumber << " already contains information." << endl;
} //end function newRecord

//删除记录
void deleteRecord(fstream &deleteFromFile)
{
    //obtain number of hardware to delete
    int hardwareNumber = getHardwareNumber("Enter number to delete");

    //将指针移动到对应的位置
    deleteFromFile.seekg((hardwareNumber - 1) * sizeof(Hardware));

    //read record from file
    Hardware hardwarelist;
    deleteFromFile.read(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));

    //delete record, if record exists in file
    if (hardwarelist.getToolNumber() != 0)
    {
        Hardware hardwarelist; //create blank record

        //将指针移动到对应的位置
        deleteFromFile.seekp((hardwareNumber - 1) * sizeof(Hardware));

        //replace existing record with blank record
        deleteFromFile.write(reinterpret_cast<char *>(&hardwarelist), sizeof(Hardware));

        cout << "Hardware #" << hardwareNumber << " deleted.\n";
    } //end if
    else
        cerr << "Hardware #" << hardwareNumber << " is empty.\n";
} //end deleteRecord

//display single record
void outputLine(ostream &output, const Hardware &record)
{
    output
        << left << setw(12) << record.getToolNumber()
        << setw(20) << record.getToolName()
        << setw(8) << record.getToolQuantity()
        << setw(8) << setprecision(2) << right << fixed
        << showpoint << record.getToolPrice() << endl;
}

//obtain hardwarenumber value
int getHardwareNumber(const char *const prompt)
{
    int hardwareNumber;

    //botain hardwarenumber value
    do
    {
        cout << prompt << "(1 - 100): ";
        cin >> hardwareNumber;
    } while (hardwareNumber < 1 || hardwareNumber > 100);

    return hardwareNumber;
} //end function getAccount

bool isempty(int currentNumber, fstream &testFile)
{
    Hardware testHardware;

    //将指针移动到对应位置
    testFile.seekg((currentNumber - 1) * sizeof(Hardware));

    //将对应的记录读出
    testFile.read(reinterpret_cast<char *>(&testHardware), sizeof(Hardware));

    if (testHardware.getToolNumber() == 0)
        return true;
    else
        return false;
}

//更新编号
void updateNumber(fstream &updateNumberFile, Hardware &hardware, int deleteNumber)
{
    //将指针移动到要更新的位置
    updateNumberFile.seekp((hardware.getToolNumber() - 1) * sizeof(Hardware));
    //将数据写入文件
    updateNumberFile.write(reinterpret_cast<char *>(&hardware), sizeof(Hardware));

    //创建一个空对象
    Hardware blank_record;
    //将指针移动到要删除的位置
    updateNumberFile.seekp((deleteNumber - 1) * sizeof(Hardware));
    //将空对象写入文件，实现删除记录
    updateNumberFile.write(reinterpret_cast<char *>(&blank_record), sizeof(Hardware));
}