# -*- coding: utf-8 -*-

# ---- init some data ----
# 隐藏变量， states
import xlrd
import os
states = ['AT', 'BEZ','IN','NN','VB','PERIOD']
obser_vals1 = ['BEAR', 'IS', 'MOVE','ON','THE','.']
#使用动态规划。
#11-14—>动态规划（22：33：20完成）
# 状态转移矩阵
Tr_p = {}
Tr_p['AT'] = {}
Tr_p['BEZ'] = {}
Tr_p['IN'] = {}
Tr_p['NN'] = {}
Tr_p['VB'] = {}
Tr_p['PERIOD'] = {}
ExcelFile=xlrd.open_workbook(os.getcwd()+"\TestData.xlsx")#从excel中获取
sheet0 = ExcelFile.sheet_by_index(0)
i=0
for state in states:
     row_data = sheet0.row_values(i)
     i=i+1
     j=0
     for state_last in states:
         Tr_p[state][state_last]=row_data[j]
         j=j+1
# 初始概率， star=*, 有的是用π来表示
star = {}
star['AT'] = 0.2
star['BEZ'] = 0.1
star['IN'] = 0.1
star['NN'] = 0.2
star['VB'] = 0.3
star['PERIOD'] = 0.1
# 放射矩阵
emission_p = {}
emission_p['AT'] = {}
emission_p['BEZ'] = {}
emission_p['IN'] = {}
emission_p['NN'] ={}
emission_p['VB'] = {}
emission_p['PERIOD'] ={}
ExcelFile=xlrd.open_workbook(os.getcwd()+"\TestData.xlsx")#从excel中获取
sheet1 = ExcelFile.sheet_by_index(1)
i=0
for state in states:
     col_data = sheet1.col_values(i)
     i=i+1
     j=0
     for ob in obser_vals1:
         emission_p[state][ob]=col_data[j]
         j=j+1
#print(emission_p['IN']['MOVE'])
#实际的观察值
obser_vals = ['THE', 'BEAR', 'IS','ON','THE','MOVE','.']
print(obser_vals)
def get_max_from_dict(delta):#单字典取最大值（key，value）函数
    max_val = 0
    max_key = ""
    for key in delta.keys():
        if delta[key] > max_val:
            max_key = key
            max_val = delta[key]
    return max_key, max_val
def viterbi():#动态规划维特比算法
    # delta 用于保存当前状态下
    delta_i= {}#***执行矩阵***
    delta_i['AT'] = {}
    delta_i['BEZ'] = {}
    delta_i['IN'] = {}        #***初始化字典***
    delta_i['NN'] = {}
    delta_i['VB'] = {}
    delta_i['PERIOD'] ={}
    trace_i= {}#***路径矩阵***
    trace_i['AT'] = {}
    trace_i['BEZ'] = {}
    trace_i['IN'] = {}         #***初始化字典***
    trace_i['NN'] = {}
    trace_i['VB'] = {}
    trace_i['PERIOD'] = {}
    path_i = []
    # 首先计算第一个的状态
    for state in states:
        delta_i[state][obser_vals[0]] = star[state] * emission_p[state][obser_vals[0]]#初始概率乘发射概率
        trace_i[state][0]=0
    # 从第二个开始计算，直到最后一个
    for i in range(1, len(obser_vals)):
        obser_val = obser_vals[i]
        for state in states:
             delta_j={}#***比较矩阵***
             for state_last in states:
                delta_j[state_last]=delta_i[state_last][obser_vals[i-1]]*Tr_p[state_last][state]#第三个循环里的取最大值
             key, val = get_max_from_dict(delta_j)
             delta_i[state][obser_val]=val * emission_p[state][obser_val]#填值（第二个循环）取得最大值乘发射概率
             trace_i[state][i]=key#记录路径
    max_val1=0
    max_key1 = ""
    for state in states:#***取得最后一列的最大值为最后一个词性***
         if delta_i[state][obser_vals[len(obser_vals)-1]] > max_val1:
             max_key1 = state
             max_val1 = delta_i[state][obser_vals[len(obser_vals)-1]]
    path_i.append(max_key1)
    a = max_key1
    for i in range(1,len(obser_vals)):#回溯取得路径
         b= trace_i[a][len(obser_vals)-i]
         path_i.append(b)
         a=b
    path_i=path_i[::-1]#***反转路径***
    print(path_i)#得到路径
viterbi()






