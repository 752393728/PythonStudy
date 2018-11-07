# coding:utf-8
'''
自动生成标题评估方法_计算语言学实验室2018项目
'''
import math

#输入的两个字符串长度不应为0；
def Recall_lcs_Gram(str1, str2):
    lstr1 = len(str1)
    lstr2 = len(str2)
    record = [[0 for i in range(lstr2 + 1)] for j in range(lstr1 + 1)]  # 多一位
    maxNum = 0  # 最长匹配长度
    p = 0  # 匹配的起始位
    for i in range(lstr1):
        for j in range(lstr2):
            if str1[i] == str2[j]:
                # 相同则累加
                record[i + 1][j + 1] = record[i][j] + 1
                if record[i + 1][j + 1] > maxNum:
                    # 获取最大匹配长度
                    maxNum = record[i + 1][j + 1]
                    # 记录最大匹配长度的终止位置
                    p = i + 1
    Recall_lcs=maxNum/lstr2
    return Recall_lcs
def Precision_lcs_Gram(str1, str2):
    lstr1 = len(str1)
    lstr2 = len(str2)
    record = [[0 for i in range(lstr2 + 1)] for j in range(lstr1 + 1)]  # 多一位
    maxNum = 0  # 最长匹配长度
    p = 0  # 匹配的起始位
    for i in range(lstr1):
        for j in range(lstr2):
            if str1[i] == str2[j]:
                # 相同则累加
                record[i + 1][j + 1] = record[i][j] + 1
                if record[i + 1][j + 1] > maxNum:
                    # 获取最大匹配长度
                    maxNum = record[i + 1][j + 1]
                    # 记录最大匹配长度的终止位置
                    p = i + 1
    Precision_lcs=maxNum/lstr1
    return Precision_lcs

def Beta(Recall_lcs,Precision_lcs):
    beta = Precision_lcs/(Recall_lcs+(math.e)**(-12))
    return beta

def Rough(Recall_lcs,Precision_lcs,beta):
    rough = ((1+beta**2)*Recall_lcs*Precision_lcs)/(Recall_lcs+(beta**2*Precision_lcs))
    return rough

def Pinggu(str1,str2):
    ser = Precision_lcs_Gram(str1, str2)
    res = Recall_lcs_Gram(str1, str2)
    if (ser > 0)and(res > 0):
        beta = Beta(res, ser)
        rough = Rough(res, ser, beta)
        print("Recall_{lcs}=" + str(res))
        print("Precision_{lcs}=" + str(ser))
        print("beta=" + str(beta))
        print("Rough=" + str(rough))
    else:
        print("Recall_{lcs}=0")
        print("Precision_{lcs}=0")

Pinggu("X","Y")


# if __name__ == '__main__':
#     str1 = input()
#     str2 = input()
#     ser = Precision_lcs_Gram(str1, str2)
#     res = Recall_lcs_Gram(str1, str2)
#     beta = Beta(res,ser)
#     rough = Rough(res,ser,beta)
#     print("Recall_{lcs}=" + str(res))
#     print("Precision_{lcs}=" + str(ser))
#     print("beta="+str(beta))
#     print("Rough="+str(rough))
