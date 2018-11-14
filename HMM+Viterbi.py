# -*- coding: utf-8 -*-

# ---- init some data ----
# 隐藏变量， states
states = ['AT', 'BEZ','IN','NN','VB','PERIOD']

# 状态转移矩阵
Tr_p = {}
Tr_p['AT'] = {'AT':2.05503E-05, 'BEZ':2.05503E-05, 'IN': 2.05503E-05, 'NN': 0.999506792, 'VB':2.05503E-05, 'PERIOD':0.000411007}
Tr_p['BEZ'] = {'AT': 0.750570342, 'BEZ':0.000380228, 'IN': 0.162357414, 'NN': 0.07148289, 'VB': 0.000380228, 'PERIOD':0.014828897}
Tr_p['IN'] = {'AT':0.697060385, 'BEZ':1.60898E-05, 'IN':0.021319046, 'NN': 0.278595678, 'VB':1.60898E-05, 'PERIOD': 0.002992711}
Tr_p['NN'] = {'AT':0.013178515, 'BEZ':0.045915031, 'IN': 0.524055725, 'NN':0.145284486, 'VB':0.007588751, 'PERIOD':0.263977493}
Tr_p['VB'] = {'AT': 0.433661811, 'BEZ':0.003070551, 'IN':0.339760069, 'NN':0.105469866, 'VB':0.009283062, 'PERIOD':0.108754642}
Tr_p['PERIOD'] = {'AT':0.533222481, 'BEZ':0.005054872, 'IN':0.309677419, 'NN':0.088460259, 'VB':0.063518457, 'PERIOD':6.65115E-05}


# 初始概率， star=*, 有的是用π来表示
star = {}
star['AT'] = 0.2
star['BEZ'] = 0.1
star['IN'] = 0.1
star['NN'] = 0.2
star['VB'] = 0.3
star['PERIOD'] = 0.1

emission_p = {}
emission_p['AT'] = {'BEAR': 0.016949153, 'IS': 9.9295E-05, 'ON': 0.000182149, 'THE': 0.999927559, 'MOVE': 0.005714286, '.':2.04855E-05}
emission_p['BEZ'] = {'BEAR': 0.016949153, 'IS':0.999503525, 'ON':0.000182149, 'THE':1.44881E-05, 'MOVE':0.005714286, '.':2.04855E-05}
emission_p['IN'] = {'BEAR': 0.016949153, 'IS': 9.9295E-05, 'ON':0.999089253, 'THE':1.44881E-05, 'MOVE': 0.005714286, '.':2.04855E-05}
emission_p['NN'] = {'BEAR': 0.186440678, 'IS': 9.9295E-05, 'ON': 0.000182149, 'THE':1.44881E-05, 'MOVE':0.211428571, '.':2.04855E-05}
emission_p['VB'] = {'BEAR':0.745762712, 'IS': 9.9295E-05, 'ON': 0.000182149, 'THE': 1.44881E-05, 'MOVE': 0.765714286, '.':2.04855E-05}
emission_p['PERIOD'] ={'BEAR': 0.016949153, 'IS': 9.9295E-05, 'ON': 0.000182149, 'THE':1.44881E-05, 'MOVE': 0.005714286, '.':0.999}
# 实际的观察值
obser_vals = ['THE', 'BEAR', 'IS','ON','THE','MOVE','.']
print(obser_vals)

def get_max_from_dict(delta):
    max_val = 0
    max_key = ""

    for key in delta.keys():
        if delta[key] > max_val:
            max_key = key
            max_val = delta[key]

    return max_key, max_val


def viterbi():
    # delta 用于保存当前状态下
    delta_i = {}
    path_i = []
    prob_i = []
    # 首先计算第一天的状态
    # delta_i['h'] = star['h'] * emission_p['h']['n']
    # delta_i['f'] = star['f'] * emission_p['f']['n']
    for state in states:
        delta_i[state] = star[state] * emission_p[state][obser_vals[0]]

    key, val = get_max_from_dict(delta_i)
    path_i.append(key)
    prob_i.append(val)
    # 从第二天开始计算，直到最后一天
    for i in range(1, len(obser_vals)):
        lastState = path_i[-1]
        obser_val = obser_vals[i]

        # 防止出错，清空delta_i
        delta_i = {}
        for state in states:

            # Δ2(h)        = Δ1(h)      * Tr(h->h)               * e(h | c)
            delta_i[state] = prob_i[-1] * Tr_p[lastState][state] * emission_p[state][obser_val]
            #print("delta_i[state]=", delta_i[state])

        # 获取当前概率最大的路径
        key, val = get_max_from_dict(delta_i)
        path_i.append(key)
        prob_i.append(val)

    print(path_i)


viterbi()






