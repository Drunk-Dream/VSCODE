import tkinter as tk
from tkinter import ttk
import os
from tkinter import messagebox


# 获取地址路径
def GetPath():
    path = cboxAddress.get()
    if not path:
        addressExit.set("")
        return False
    path = path.replace("\\", "/")
    if path[0] == '\"' and path[-1] == '\"':
        path = eval(path)
    return path


# 检查路径
def CheckAddress():
    path = GetPath()
    # memberName = ['向晚', '贝拉', '珈乐', '嘉然', '乃琳']
    # for i_name in range(0, len(memberName)):
    #     if memberName[i_name] in cboxAddress.get():
    #         cboxType.current(i_name)
    if os.path.exists(path):
        addressExit.set("√")
        return True
    else:
        addressExit.set("x")
        return False


# 拼接
def VideoStitch():
    if not CheckAddress():
        messagebox.showwarning(title="警告", message="路径错误！！！")
    path = GetPath()  # 获取路径
    ################################################################
    # 修改文件名
    allFileNames = os.listdir(path)  # 读取目录中所有文件名
    originalNameTheFileList = []  # 只包含flv视频的文件名
    modifiedFileNameList = []  # 将名字修改后的文件名

    # 遍历目录中的所有文件名
    for fileName in allFileNames:
        if os.path.splitext(fileName)[
                1] == '.flv' and fileName[:2] == '录制':  # 将录播姬默认名字的flv视频找出
            originalNameTheFileList.append(fileName)  # 将原名字加入到数组中
            splitFileName = fileName.split("-")  # 拆分文件名
            modifiedFileNameList.append('t' + ''.join(splitFileName[2:5]) +
                                        '.flv')  # 新名字
        # else:
        #     if fileName[0] == 't':
        #         modifiedFileName.append(fileName)

    # 将原名字加入到备份文件中
    if originalNameTheFileList:  # 如果原名字列表中有元素
        # 不能新增，只能直接覆盖旧文件
        OriginalFileList = open(os.path.join(path, "OriginalFileList.txt"),
                                "w")
        # 开始将原名字写入文件
        for name in originalNameTheFileList:
            print(name, file=OriginalFileList)
    else:  # 如果列表中没有，则不需要写入
        return
    # 关闭原文件名单文件
    OriginalFileList.close()

    # 开始改名
    for i_fileName in range(0, len(originalNameTheFileList)):
        os.rename(os.path.join(path, originalNameTheFileList[i_fileName]),
                  os.path.join(path, modifiedFileNameList[i_fileName]))
    # 按时间排序
    modifiedFileNameList.sort()
    # 打开新名字文件
    NewFileName = open(os.path.join(path, "NewFileNameList.txt"), "w+")
    # 将新名字录入文件
    for fileName in modifiedFileNameList:
        print("file " + "\'" + fileName + "\'", file=NewFileName)
    # 关闭文件
    NewFileName.close()

    ################################################################
    # 调用cmd进行视频拼接
    liveType = cboxType.get()  # 获取直播类型
    # 合并之后的文件名
    mergeFileName = originalNameTheFileList[0][
        12:16] + '.' + originalNameTheFileList[0][
            16:18] + '.' + originalNameTheFileList[0][
                18:20] + ' ' + liveType + ' ' + originalNameTheFileList[0][
                    originalNameTheFileList[0].find('】') + 1:]
    # cmd命令
    cmd = 'ffmpeg -f concat -i ' + os.path.join(
        path, 'NewFileNameList.txt') + ' -c copy \"' + os.path.join(
            path, mergeFileName) + '\"'
    res = os.popen(cmd)
    output_str = res.read()  # 获得输出字符串
    print(output_str)
    messagebox.showwarning(title="通知", message="拼接成功！！！")

    ################################################################
    # 恢复文件名
    def SolutionTheFileName(splitFileName, modifiedFileName):
        return '-'.join(splitFileName[:2]) + "-" + modifiedFileName[
            1:9] + "-" + modifiedFileName[9:15] + "-" + modifiedFileName[
                15:18] + "-" + ''.join(splitFileName[5:])

    if modifiedFileNameList:
        splitFileName = originalNameTheFileList[0].split("-")
        for i_modifiedFileName in range(0, len(modifiedFileNameList)):
            if modifiedFileNameList[i_modifiedFileName][1:-4] == ''.join(
                    originalNameTheFileList[i_modifiedFileName].split(
                        "-")[2:5]):
                os.rename(
                    os.path.join(path,
                                 modifiedFileNameList[i_modifiedFileName]),
                    os.path.join(
                        path,
                        SolutionTheFileName(
                            splitFileName,
                            modifiedFileNameList[i_modifiedFileName])))
            else:
                messagebox.showwarning(title="警告", message="恢复文件失败！！！")
                return


# 修改文件名
def ModifyFileName():
    if not CheckAddress():
        messagebox.showwarning(title="警告", message="路径错误！！！")
    path = GetPath()  # 获取路径
    #################################
    # 获取路径的文件名列表，排除文件名，判断是否满足改名条件
    AllList = os.listdir(path)  # 读取目录中所有文件名
    exclusionList = ["com", "OriginalFileList.txt"]  # 要排除的文件名
    for excludeFilenames in exclusionList:
        if excludeFilenames in AllList:
            AllList.remove(excludeFilenames)
    print(AllList)
    # 如果不是只有两个文件则退出
    if not len(AllList) == 2:
        print("不满足改名条件：大于两个文件！！！")
        return
    for fileName in AllList:
        if fileName[:2] == '录制' and fileName[-4:] == '.flv':
            videoFileName = fileName
        elif fileName[:2] == '录制' and fileName[-4:] == '.xml':
            barrageFileName = fileName
        else:
            messagebox.showwarning(title="警告", message="不符合改名条件！！！")
            return
    #################################
    # 开始改名
    OriginalFileList = open(os.path.join(path, "OriginalFileList.txt"), "w")
    for name in AllList:
        print(name, file=OriginalFileList)
    OriginalFileList.close()
    # 获取直播类型
    liveType = cboxType.get()
    # 新名字
    newVideoFileName = videoFileName[12:16] + '.' + videoFileName[
        16:18] + '.' + videoFileName[
            18:20] + ' ' + liveType + ' ' + videoFileName[videoFileName.
                                                          find('】') + 1:]
    newBarrageFileName = barrageFileName[12:16] + '.' + barrageFileName[
        16:18] + '.' + barrageFileName[
            18:20] + ' ' + liveType + ' ' + barrageFileName[barrageFileName.
                                                            find('】') + 1:]
    # 开始改名
    os.rename(os.path.join(path, videoFileName),
              os.path.join(path, newVideoFileName))
    os.rename(os.path.join(path, barrageFileName),
              os.path.join(path, newBarrageFileName))
    messagebox.showinfo(title="通知", message='改名成功！！！')


# 建立tkinter窗口，设置窗口标题
root_window = tk.Tk()
root_window.geometry('640x360+700+300')
# root_window.iconbitmap('')  #加载左上角图标
root_window.title("VideoProcess")
# root_window.config(background="#c7bdc3")

# 在窗口中创建标签

labelAddress = tk.Label(root_window, text="地址：", font=('微软雅黑', 15))
labelAddress.grid(row=0, column=0, padx=10)
labelType = tk.Label(root_window, text="类型：", font=('微软雅黑', 15))
labelType.grid(row=1, column=0, padx=10)

# 地址输入框
# e1 = tk.Entry(root_window,
#               width=50,
#               validate="focusout",
#               bg="#d2d0ce",
#               validatecommand=CheckAddress)
# e1.grid(row=0, column=1, padx=10, pady=5)

# 地址选项
cboxAddress = ttk.Combobox(root_window,
                           width=50,
                           validatecommand=CheckAddress,
                           validate="focus")
cboxAddress.grid(row=0, column=1, padx=10, sticky='w')
cboxAddress['value'] = ("D:\\rec\\6154037-Asaki大人\\com",
                        "D:\\rec\\22625025-向晚大魔王\\com",
                        "D:\\rec\\22632424-贝拉kira\\com",
                        "D:\\rec\\22634198-珈乐Carol\\com",
                        "D:\\rec\\22637261-嘉然今天吃什么\\com",
                        "D:\\rec\\22625027-乃琳Queen\\com")
cboxAddress.current(1)

cboxType = ttk.Combobox(root_window, width=15, font=('微软雅黑'))
cboxType.grid(row=1, column=1, sticky='w', padx=10)
cboxType['value'] = ('向晚', '贝拉', '珈乐', '嘉然', '乃琳', 'A-SOUL夜谈', 'A-SOUL小剧场',
                     'A-SOUL游戏室', '特殊节目')

cboxType.current(0)

addressExit = tk.StringVar()
addressExit.set("")
tk.Label(root_window, textvariable=addressExit).grid(row=0, column=2)

frameButton = tk.Frame(root_window)
frameButton.grid(row=2, column=0, pady=5, columnspan=2, sticky='w')

buttonStitch = tk.Button(frameButton,
                         text='拼接',
                         font=('微软雅黑', 15),
                         width=5,
                         command=VideoStitch)
buttonStitch.grid(row=0, column=0, padx=10)
buttonName = tk.Button(frameButton,
                       text="改名",
                       font=('微软雅黑', 15),
                       width=5,
                       command=ModifyFileName)
buttonName.grid(row=0, column=1, padx=10)

# 运行并显示窗口
root_window.mainloop()
