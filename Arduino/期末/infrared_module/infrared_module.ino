#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
// decode_results results;

// char IRdecode(unsigned long value)
// {
//     switch (value)
//     {
//     case 0xFFE01F:
//         return 'z';
//         break;
//     case 0xFF6897:
//         return ' ';
//         break;
//     case 0xFF30CF:
//         return 'a';
//         break;
//     case 0xFF18E7:
//         return 'b';
//         break;
//     case 0xFF7A85:
//         return 'c';
//         break;
//     case 0xFF10EF:
//         return 'd';
//         break;
//     case 0xFF38C7:
//         return 'e';
//         break;
//     case 0xFF5AA5:
//         return 'f';
//         break;
//     case 0xFF42BD:
//         return 'g';
//         break;
//     case 0xFF4AB5:
//         return 'h';
//         break;
//     case 0XFF52AD:
//         return 'i';
//         break;
//     default:
//         return 'x';
//         break;
//     }
// }

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

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    irrecv.enableIRIn();
    // pinMode(2, INPUT);
    // pinMode(11, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:

    if (irrecv.decode())
    {
        Serial.println(irrecv.decodedIRData.command);
        irrecv.resume();
    }
    if (digitalRead(2))
        newtone(11, 262, 100);
    if (digitalRead(3))
        newtone(11, 262, 100);
    if (digitalRead(4))
        newtone(11, 262, 100);
    if (digitalRead(5))
        newtone(11, 262, 100);
    if (digitalRead(6))
        newtone(11, 262, 100);
    if (digitalRead(7))
        newtone(11, 262, 100);
    if (digitalRead(8))
        newtone(11, 262, 100);
    delay(300);
}
