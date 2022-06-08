/*
加上解释的地方到时候都可以删除
解释：
2022.06.07
这个程序主要有3个模式：
1.即时播放功能，即按下按键后可以在蜂鸣器中即时播放，该功能主要由函数
KeyboardRealTimeDeduction完成，该函数以及对应的功能还未完成测试
2.录音功能，本质为在录音模式下录下每次按键的顺序，存入数组中，主要由函数RecordingTune
来完成，然后将记录的数组存入存储器中（注：存入存储器部分还未实现）
3.播放录制好的音乐功能，暂时还未实现暂停功能，后续视情况考虑增加
*/
#include <LiquidCrystal_I2C.h> //LCD模块
#include <IRremote.h>          //红外模块

/*
解释：
这里将宏定义音调改为用数组来存储音调主要是为了方便在录制的时候可以之间通过按键的索引来调取
对应的音调，所以千万！！！！！不要直接改动按键的引脚！！！！！
*/
//音调
// #define C1 262
// #define C2 294
// #define C3 330
// #define C4 350
// #define C5 393
// #define C6 441
// #define C7 494
// #define C0 0
int C[] = {0, 262, 294, 330, 350, 393, 441, 494};

//定义引脚
int tonePin = 10; //蜂鸣器引脚
int recvPin = 11; //红外引脚
const int redPin=12;
const int greenPin=13;
const int bluePin=1;

LiquidCrystal_I2C lcd(0x27, 16, 2); //实例化lcd
IRrecv irrecv(recvPin);             //实例化红外
// decode_results results;

//定义变量
char state = '1';          //这个变量用来存储当前状态，默认为状态1，即开头所述的模式1
char beforeState = '0';    //这个变量用来存储上一次的变量，初始化为0没有意义，主要是为了防止在每次循环中都重新刷新LCD,不用理会
int tune[200];             //这个数组是用来存储录制的音
int buttonState = 0;       //这个变量用来在录制时存储按键状态，当没有按键按下时为0，有任意按键按下时为1
int beforeButtonState = 0; //这个按键是用来存储上一次循环时的按键状态，与上一个变量结合一次使用可以用来做判断按键是否松开，只有松开上一次按键才能按下一次
int i_tune = 0;            //曲调数组索引，即录制时做tune这个数组的索引，不用理会
int tuneLength = 0;        //曲调长度，用来记录这个数组最终记录的长度
int playFlag = 0;          //播放时终止标志，用来标记以便跳出模式3的两重循环

//因为系统的tone函数与红外模块有冲突，所以改用新的函数newtone来实现原来tone的功能
//新的tone
void newtone(byte tonePin, int frequency, int duration)
{
    int period = 1000000L / frequency;
    int pulse = period / 2;
    for (long i = 0; i < duration * 1000L; i += period)
    {
        digitalWrite(tonePin, HIGH);
        delayMicroseconds(pulse);
        digitalWrite(tonePin, LOW);
        delayMicroseconds(pulse);
    }
}
//设置调节RGB的函数
void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
 analogWrite(redPin, red);
 analogWrite(greenPin, green);
 analogWrite(bluePin, blue);
}

/*
解释：
这个函数实际上就是按下按键然后响起来的那个函数
也就是模式1下的主要函数
因为要在模式1,2中复用，所以写成内联函数的形式
还没进行测试
*/
//电子琴实时演绎的函数
inline void KeyboardRealTimeDeduction()
{
    if (digitalRead(2))
        newtone(tonePin, C[1], 100);
    if (digitalRead(3))
        newtone(tonePin, C[2], 100);
    if (digitalRead(4))
        newtone(tonePin, C[3], 100);
    if (digitalRead(5))
        newtone(tonePin, C[4], 100);
    if (digitalRead(6))
        newtone(tonePin, C[5], 100);
    if (digitalRead(7))
        newtone(tonePin, C[6], 100);
    if (digitalRead(8))
        newtone(tonePin, C[7], 100);
}

/*
解释：
这个就是将接收到的红外编码转化成对应的字符，
这个函数与之前相比有一些改动，是因为红外的那个库有个更好的实现方法，所以进行了一下改动
主要就是之前接收的十六进制变成了现在的十进制，不用管
*/
//红外解码
char InfraredDecode(unsigned long value)
{
    switch (value)
    {
    case 22:
        return '0';
        break;
    case 12:
        return '1';
        break;
    case 24:
        return '2';
        break;
    case 94:
        return '3';
        break;
    case 8:
        return '4';
        break;
    case 28:
        return '5';
        break;
    case 90:
        return '6';
        break;
    case 66:
        return '7';
        break;
    case 82:
        return '8';
        break;
    case 74:
        return '9';
        break;
    case 67:
        return 'p';
        break;
    default:
        return 'x';
        break;
    }
}

/*
解释：
这个函数是我用来判断红外接收到的信号是否是状态信号，即是否是1,2,3这三个
*/
// 判断红外输入是否是状态
int isState(char decodingResults)
{
    char stateOptions[] = {'1', '2', '3'};
    for (int i = 0; i < 4; i++)
    {
        if (decodingResults = stateOptions[i])
            return 1;
    }
    return 0;
}

/*
解释：
这个函数是我用来判断是否有按键按下用的
返回0或对应的引脚-1（即所对应的音调的索引）！！！强调千万不要轻易改按键的引脚！！！
*/
//返回按键状态
int KeyState()
{
    for (int i = 2; i <= 8; i++)
    {
        if (digitalRead(i))
            return i - 1;
    }
    return 0;
}

/*
这个函数是模式2所调用的函数
进入该模式即可开始录制
按1，3可结束录制并进入对应模式
注：每次进入该模式原来存储的乐谱都会被清零
*/
//录制曲调
void RecordingTune()
{
    for (int i = 0; i < 200; i++) //首先将tune这个数组全部元素置零
        tune[i] = 0;
    while (1) //然后进入录制循环
    {
        //先判断是否接收到红外信号
        if (irrecv.decode())
        {
            char decodingResults = InfraredDecode(irrecv.decodedIRData.command);
            if (decodingResults == '1' || decodingResults == '3') //如果接收到1或者3，即要转换状态
            {
                state = decodingResults; //将状态设为接收到的信号
                tuneLength = i_tune;     //录制的长度就等于索引的长度
                irrecv.resume();         //这个是用来等待下一次接收红外信号用的
                break;                   //跳出while循环，这时候这个函数也会结束
            }
            irrecv.resume(); //每次接收完信号，不管要不要进一步出来都要这个函数来等待下一次接收红外信号
        }
        KeyboardRealTimeDeduction();                        //解释：即时演绎的函数，用来实现录制时也能实时发出声音，还没测试过
        buttonState = KeyState();                           //解释：接收按键状态，0或者对应按下的引脚-1（即所对应的音调的索引）这里在此强调千万不要直接该引脚，不然这里会出错
        if ((buttonState != 0) && (beforeButtonState == 0)) //如果按键按下且上一次已经松开
        {
            tune[i_tune] = C[buttonState]; //将对应的音调存进数组
            i_tune++;
        }
        if (buttonState != beforeButtonState) //消抖
            delay(20);
        beforeButtonState = buttonState;
        delay(100);
    }
}

/*
播放音乐用的函数，即模式3所用的函数
已进入该模式就会直接播放音乐，不能暂停，按1，2可跳到对应模式
注：每次进入该模式都会从头开始播放
*/
// 播放录制好的曲子
void PlayMusic()
{
    int durt = 500; //这个是节奏，即响500ms后期可调
    while (1)
    {
        if (tuneLength == 0) //如果数组长度等于0，则不会播放音乐并返回模式1
        {
            lcd.setCursor(0, 1);
            lcd.print("NO TUNE!!!");
            delay(2000);
            state = '1';
            break;
        }
        int i = 0;
        unsigned int rgbColour[3];
        rgbColour[0] = 255;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        while (i < tuneLength) //进入播放的循环
        {
            if (irrecv.decode()) //随时可以接收红外信号进入其他两个模式，
            {
                char decodingResults = InfraredDecode(irrecv.decodedIRData.command);
                Serial.println(decodingResults);
                if (decodingResults == '1' || decodingResults == '2')
                {
                    state = decodingResults;
                    playFlag = 1; //将标记置为1
                    irrecv.resume();
                    break; //退出第2层循环
                }
                irrecv.resume();
            }
            newtone(tonePin, tune[i], durt);
            rgbColour[0] = 255-0.5*tune[i];
            rgbColour[1] = 0.5*tune[i];
            rgbColour[2] = tune[i]-255;
            setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
            // delay(durt);
            i++;
        }
        if (playFlag == 1)
        {
            playFlag = 0;
            break; //如果标记为1，则将标志置零然后跳出第1层循环
        }
        delay(2000);
    }
}

void setup()
{
    //初始化引脚
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);        // 2-8按键引脚
    pinMode(tonePin, OUTPUT); //蜂鸣器输出引脚

    lcd.init();          //初始化LCD
    lcd.backlight();     //打开背光灯
    irrecv.enableIRIn(); //初始化红外模块
    Serial.begin(9600);  //窗口监视器，这个没用的话可以注释掉
}

void loop()
{
    if (irrecv.decode())
    {
        Serial.println(irrecv.decodedIRData.command);
        char decodingResults = InfraredDecode(irrecv.decodedIRData.command);
        // Serial.println(decodingResults);
        if (isState(decodingResults))
        {
            state = decodingResults;
        } //如果红外输入的是状态，则改变状态
        irrecv.resume();
    }
    // Serial.print("state:");
    // Serial.println(state);
    // Serial.print("beforeState:");
    // Serial.println(beforeState);
    if (state == '1') //实时演绎状态
    {
        if (beforeState != '1') //防止LCD每次循环都刷新，只有在状态发生改变的时候才生效，以下同理
        {
            lcd.clear(); //刷新LCD
            lcd.setCursor(0, 0);
            lcd.print("RENDITION");
        }
        KeyboardRealTimeDeduction();
        beforeState = state;
    }
    if (state == '2') //录制状态
    {
        if (beforeState != '2')
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("RECORD");
        }
        beforeState = state;
        RecordingTune(); //调用模式2的函数
    }
    if (state == '3')
    {
        if (beforeState != '3')
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("PLAY");
        }
        beforeState = state;
        PlayMusic(); //调用模式3的函数
    }
    delay(300);
}
