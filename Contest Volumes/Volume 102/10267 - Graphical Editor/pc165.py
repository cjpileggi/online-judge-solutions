from sys import stdin

#from pandas import DataFrame

# x left ro right, y top to bottom
#test to see if max min needed
class Image:
    
    def __init__(self):
        self.img = []
        
    def command(self, cmd):
        if cmd[0] == "I": 
            self.newImgI(int(cmd[1]), int(cmd[2]))
        if cmd[0] == "C":
            self.clearC()
        if cmd[0] == "L":
            self.locationL(int(cmd[1]), int(cmd[2]), cmd[3])
        if cmd[0] == "V":
            self.vertV(int(cmd[1]), int(cmd[2]), int(cmd[3]), cmd[4])
        if cmd[0] == "H":
            self.horizH(int(cmd[1]), int(cmd[2]), int(cmd[3]), cmd[4])
        if cmd[0] == "K":
            self.rectK(int(cmd[1]), int(cmd[2]), int(cmd[3]), int(cmd[4]), cmd[5])
        if cmd[0] == "F":
            self.fillF(int(cmd[1]), int(cmd[2]), cmd[3])
        if cmd[0] == "S":
            self.saveS(cmd[1])
        
    def newImgI(self, M, N):
        #return [["0"] * int(cmd[1])] * int(cmd[2]) 
        #creates duplicates of same list(all elements in column affected)
        self.img = []
        for i in range(0,N):
            self.img.append(["O" for x in range(0,M)])

    def locationL(self, X, Y, C):
        self.img[Y - 1][X - 1] = C
        
    def clearC(self):
        self.img = [["O" for x in self.img[0]] for x in self.img]
        
    def vertV(self, X, Y1, Y2, C):
        
        for y in range((min(Y2,Y1) - 1 ), (max(Y1,Y2))):
            self.img[y][X-1] = C  

    def horizH(self, X1, X2, Y, C):
        lower = min(X2,X1) - 1
        upper = max(X1,X2) - 1
        
        """for x in range(lower, upper + 1):
        
            self.img[Y-1][x] = C #* (upper + 1) - lower)"""
        

        self.img[Y-1][lower:upper + 1] = C * ((upper - lower) + 1)



    def rectK(self, X1, Y1, X2, Y2, C):
    
        lower = min(X1,X2) - 1
        upper = max(X2,X1) - 1
        
        for y in range(min(Y1,Y2) - 1, max(Y2,Y1)):
        
            self.img[y][lower:upper + 1] = C * ((upper - lower) + 1)
    
    def fillF(self, X, Y, C):
        
        maxX = len(self.img[0])
        maxY = len(self.img)
        
        origX = X - 1
        origY = Y - 1
        
        oldColor = self.img[origY][origX]
        
        
        if oldColor != C:
            
            queueCur = 0
            
            queue = []
            visited = set()
            
            #img[origY][origX] = newColor
            queue.append((origX,origY))
            visited.add((origX,origY))
            
            nextX = 0
            nextY = 0
            
            self.img[queue[queueCur][1]][queue[queueCur][0]] = C
            if (queue[queueCur][0], queue[queueCur][1]) not in visited: 
                visited.add((queue[queueCur][0], queue[queueCur][1]))
         
        
            if (queue[queueCur][0], queue[queueCur][1]) not in visited: 
                visited.add((queue[queueCur][0], queue[queueCur][1]))
         
            while queueCur < len(queue):
                for i in range(-1,2):
                    for j in range(-1,2):
                            nextX = queue[queueCur][0] + j
                            nextY = queue[queueCur][1] + i
                            
                            if nextX in range(0, maxX) and nextY in range(0,maxY):
                                if self.img[nextY][nextX] == oldColor:
                                    self.img[nextY][nextX] = C
                                    if (nextX,nextY) not in visited:
                                        queue.append((nextX,nextY))
                queueCur += 1


    def saveS(self,Name):
        print(Name)
        
        for x in self.img:
            print(''.join(x))

# Class End            
    
if __name__ == "__main__":
    img = Image()

    for line in stdin: 
        if line != 'X':
            img.command([x for x in line.split()])
        else:
            break
    

    """with open('pc165_inputs.txt') as f:
        for line in f:#stdin:#f: 
            if line != 'X':
                img.command([x for x in line.split()])
            else:
                break"""
    print("")
    del img

    exit(0)
