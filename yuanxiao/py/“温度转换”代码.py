# TempConvert.py
TempStr = input("请输入带有符号的温度值：")
try:
    temperature = float(TempStr[:-1])
    if TempStr[-1] in ['F', 'f']:
        C = (temperature - 32) / 1.8
        print("转换后的温度是 {:.2f}C".format(C))
    elif TempStr[-1] in ['C', 'c']:
        F = 1.8 * temperature + 32
        print("转换后的温度是 {:.2f}F".format(F))
    else:
        print("输入格式错误")
except ValueError:
    print("输入格式错误或无法转换为数字")
