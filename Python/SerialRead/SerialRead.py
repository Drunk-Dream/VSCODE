import serial
import xlwt

# 打开串口
serialPort = "COM6"
baudRate = 9600
ser = serial.Serial(serialPort, baudRate, timeout=0.5)

workbook = xlwt.Workbook()
worksheet = workbook.add_sheet('sheet1')
worksheet.write(0, 0, '时间/s')
worksheet.write(0, 1, '湿度/%')
worksheet.write(0, 2, '温度/oC')
worksheet.write(0, 3, '人体红外')
worksheet.write(0, 4, '声音')

time = 1
while time <= 7200:
    str = ser.readline()
    if str:
        str = ''.join(chr(i) for i in str)
        print('time: %.2f' % (time*0.5))
        print('Humidity: %.2f' % float(str[:5]))
        print('Temperature %.2f' % float(str[5:10]))
        print('isHuman: %d' % int(str[10]))
        print('soundV: %.2f' % float(str[11:-2]))
        # print()
        # 写入Excel
        worksheet.write(time, 0, time*0.5)
        worksheet.write(time, 1, float(str[:5]))
        worksheet.write(time, 2, float(str[5:10]))
        worksheet.write(time, 3, int(str[10]))
        worksheet.write(time, 4, float(str[11:-2]))
        time = time + 1

workbook.save('C:\\Users\\34756\\OneDrive\\homework\\电子线路\\期中\\SensorExperimentsData.xls')
