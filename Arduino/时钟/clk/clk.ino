#include <DS1302.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DS1302 rtc(2, 3, 4); //对应DS1302的RST,DAT,CLK

String state = "";
String changeState = "";
int *times;

void initRTCTime(void) //初始化RTC时钟
{
    rtc.writeProtect(false);            //关闭写保护
    rtc.halt(false);                    //清除时钟停止标志
    Time t(2020, 4, 25, 21, 50, 50, 7); //新建时间对象 最后参数位星期数据，周日为1，周一为2以此类推
    rtc.time(t);                        //向DS1302设置时间数据
}

void printTime() //打印时间数据
{
    Time tim = rtc.time(); //从DS1302获取时间数据
    char buf[50];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d",
             tim.yr, tim.mon, tim.date,
             tim.hr, tim.min, tim.sec);
    Serial.println(buf);
}

void ChangeRTCTime(void) //设置时间
{
    while (1)
    {
        if (Serial.available())
        {
            changeState = Serial.readString();
            if (changeState == "end\n")
            {
                state = "";
                lcd.clear();
                break;
            }
            else
            {
                times = StringIsConvertedToDate(changeState);
                rtc.writeProtect(false);                                               //关闭写保护
                rtc.halt(false);                                                       //清除时钟停止标志
                Time t(times[0], times[1], times[2], times[3], times[4], times[5], 1); //新建时间对象 最后参数位星期数据，周日为1，周一为2以此类推
                rtc.time(t);                                                           //向DS1302设置时间数据
                PrintRTCTime();
            }
        }
    }
}

void PrintRTCTime(void)
{
    Time tim = rtc.time();
    char dateTheBuffer[20];
    snprintf(dateTheBuffer, sizeof(dateTheBuffer), "%04d-%02d-%02d",
             tim.yr, tim.mon, tim.date);
    char timeToBuffer[20];
    snprintf(timeToBuffer, sizeof(timeToBuffer), "%02d:%02d:%02d",
             tim.hr, tim.min, tim.sec);
    lcd.setCursor(0, 0);
    lcd.print(dateTheBuffer);
    lcd.setCursor(0, 1);
    lcd.print(timeToBuffer);
}

int *StringIsConvertedToDate(String str)
{
    int position;
    String temps[str.length()];
    static int numTemps[6];
    int i = 0;
    do
    {
        position = str.indexOf("-");
        if (position != -1)
        {
            temps[i] = str.substring(0, position);
            str = str.substring(position + 1, str.length());
            numTemps[i] = temps[i].toInt();
            i++;
        }
        else
        {
            if (str.length() > 0)
                temps[i] = str;
            numTemps[i] = temps[i].toInt();
        }
    } while (position >= 0);

    return numTemps;
}

void setup()
{
    Serial.begin(9600);

    //新模块上电需要设置一次当前时间，
    //下载完成后需屏蔽此函数再次下载，否则每次上电都会初始化时间数据
    initRTCTime();
    lcd.init();
    lcd.backlight();
}

void loop()
{
    printTime();
    if (Serial.available())
    {
        state = Serial.readString();
    }

    if (state == "set\n")
    {
        lcd.setCursor(13, 1);
        lcd.print("SET");
        ChangeRTCTime();
    }
    PrintRTCTime();

    delay(1000);
}