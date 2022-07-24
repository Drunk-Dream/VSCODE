import os

path = r"E:\rec\22637261-嘉然今天吃什么\com"

try:  # 尝试将备份的文件名导出到列表中
    BackupDirectory = open(os.path.join(path, "BackupDirectory.txt"), "r")
    backup_file = BackupDirectory.readlines()
    for i in range(0, len(backup_file)):
        backup_file[i] = backup_file[i].strip('\n')
    BackupDirectory.close()
except FileNotFoundError:  # 如果文件名不存在
    print('备份文件名不存在！！！')

mergeFileName = backup_file[0][12:16] + '.' + backup_file[0][
    16:18] + '.' + backup_file[0][18:20] + ' ' + backup_file[0][36::]

cmd = 'ffmpeg -f concat -i ' + os.path.join(
    path, 'NewFileName.txt') + ' -c copy \"' + os.path.join(
        path, mergeFileName) + '\"'
res = os.popen(cmd)
output_str = res.read()  # 获得输出字符串
print(output_str)
