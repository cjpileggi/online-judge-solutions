from sys import stdin

def horizLayer(s,n,sect):
    layer = ""
    for num in n:
        if num in sect:
            layer += " " + ("-" * s) + " "
        else:
            layer += " " + (" " * s) + " "
        layer += " "
    print(layer[:-1])
    
def vertLayer(s,n,leftSect,rightSect):
    layer = ""
    for num in n:
        if num in leftSect:
            layer += "|"
        else:
            layer += " "
        layer += " " * s
        if num in rightSect:
            layer += "|"
        else:
            layer += " "
        layer += " "
    for i in range(0,s):
        print(layer[:-1])

def mapLCD(s,n,numMap):

    horizLayer(s,n,numMap["top"])
    vertLayer(s,n,numMap["topLeft"],numMap["topRight"])
    horizLayer(s,n,numMap["mid"])
    vertLayer(s,n,numMap["bottomLeft"],numMap["bottomRight"])
    horizLayer(s,n,numMap["bottom"])

if __name__ == "__main__":
    numMap = {}
    numMap["top"] = ["2","3","5","6","7","8","9","0"]
    numMap["topLeft"] = ["4","5","6","8","9","0"]
    numMap["topRight"] = ["1","2","3","4","7","8","9","0"]
    numMap["mid"] = ["2","3","4","5","6","8","9"]
    numMap["bottomLeft"] = ["2","6","8","0"]
    numMap["bottomRight"] = ["1","3","4","5","6","7","8","9","0"]
    numMap["bottom"] = ["2","3","5","6","8","9","0"]
    #with open('pc164_inputs.txt') as f:
    for line in stdin:#f: 
        s, n = map(str, line.split())
        if s == "0":
            break
        mapLCD(int(s),n, numMap)
        print()