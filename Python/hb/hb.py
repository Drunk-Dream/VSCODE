import os

path = input("请输入地址：\n")
path = path.replace("\\", "/")
path = eval(path)
datanames = os.listdir(path)
newdatanames = []
datanames1 = []
BackupDirectory = open(os.path.join(path, "BackupDirectory.txt"), "w")

for i in datanames:
    if os.path.splitext(i)[1] == '.flv' and i[:2] == '录制':
        datanames1.append(i)
        ii = i.split("-")
        if i[0] == 't':
            newdatanames.append(i)
        else:
            print(i, file=BackupDirectory)
            newdatanames.append('t' + ii[2] + ii[3] + '.flv')

for i in range(0, len(newdatanames)):
    os.rename(os.path.join(path, datanames1[i]),
              os.path.join(path, newdatanames[i]))

newdatanames.sort()
myfile = open(os.path.join(path, "myfile.txt"), 'w+')

for i in newdatanames:
    print("file " + "\'" + i + "\'", file=myfile)

myfile.seek(0, 0)
print(myfile.read())
myfile.close()
os.system("pause")

# test
