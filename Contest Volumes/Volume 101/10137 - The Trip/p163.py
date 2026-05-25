from sys import stdin
from math import ceil,floor
def minPrice(prices):
    minP, maxP = 0, 0
    pricesAvg = sum(prices)/len(prices)
    pricesAvgLow = floor(pricesAvg * 100) / 100
    pricesAvgHigh = ceil(pricesAvg * 100) / 100
    for p in prices:
        if p < pricesAvg: minP += float(pricesAvgLow - p)
        if p > pricesAvg: maxP += float(p - pricesAvgHigh)
        
    return "${:.2f}".format(max(minP,maxP)) 


if __name__ == "__main__":
    flag, priceNum,prices = True, 0, []
    #with open('pc163_inputs.txt') as f:
    for line in stdin: 
        if flag:
            priceNum = int(line)
            flag=False
        else:
            prices.append(float(line))
            priceNum -= 1
            if priceNum == 0:
                flag = True
                print(minPrice(prices))
                prices = []