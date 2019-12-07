class Screen:
    def __init__(self,name,numRows,seatsPerRow,aisleSeats):
        for a in aisleSeats:
            if a > seatsPerRow or a < 0:
                print('failure')
                return
        self.name = name
        self.numRows = numRows
        self.seatsPerRow = seatsPerRow
        self.aisleSeats = aisleSeats
        self.booking = [[False]*seatsPerRow]*numRows
        print ('success')
        

    def reserveSeats(self,rowNumber,seatList):
        for s in seatList:
            if self.booking[rowNumber-1][s-1] == False:
                self.booking[rowNumber-1][s-1] = True
            else:
                self.rollBack(rowNumber,seatList,s)
                print ('failure')
                return
        print('success')
        return

    def rollBack(self,rowNumber,seatList,index):
        for s in seatList:
            if(s==index):
                return
            self.booking[rowNumber-1][s-1] = False

    def getUnreservedSeatsInARow(self,row):
        vacant = []
        for r in range(self.seatsPerRow):
            if self.booking[row-1][r] == False:
                print(r+1, end=" ")
                vacant.append(r+1)
        print('')
        return vacant
    
    def suggestSeats(self,noSeats,row,seatNumber):
        leftSuggest = True
        if seatNumber-noSeats<0:
            leftSuggest = False
        else:
            for i in range(seatNumber-noSeats,seatNumber):
                if self.booking[row][i] == True or(i != seatNumber-noSeats and i != seatNumber-1 and i in self.aisleSeats):
                    leftSuggest = False
                    break
            if leftSuggest == True:
                for seat in range(seatNumber-noSeats,seatNumber):
                    print (seat+1 ,end=' ')
                print ('')
                leftSuggest = True
        
        rightSuggest = True
        if leftSuggest==False:
            if seatNumber+noSeats>self.seatsPerRow:
                rightSuggest = False
            else:
                for i in range(seatNumber,seatNumber+noSeats):
                    if self.booking[row][i] == True or (i != seatNumber-noSeats and i != seatNumber-1 and i in self.aisleSeats):
                        rightSuggest = False
                        break
                if rightSuggest == True:
                    for seat in range(seatNumber,seatNumber+noSeats):    
                        print (seat+1 ,end=' ')
                    print ('')
                    rightSuggest = True 
        
        if rightSuggest == False and leftSuggest == False:
            print('none')


ScreenList = {}
for _ in range(int(input())):
    cmd = input()
    args = cmd.split(' ')
    if args[0] == 'add-screen':
        if not args[1] in ScreenList:
            seatL = [int(i) for i in args[4:]]
            print (seatL)
            S = Screen(args[1],int(args[2]),int(args[3]),seatL)
            ScreenList[args[1]] = S
        else:
            print('failure')

    if args[0] == 'reserve-seat':
        S = ScreenList[args[1]]
        S.reserveSeats(int(args[2]),[int(i) for i in args[3:]])
    
    if args[0] == 'get-unreserved-seats':
        S = ScreenList[args[1]]
        S.getUnreservedSeatsInARow(int(args[2]))
    
    if args[0] == 'suggest-contiguous-seats':
        S = ScreenList[args[1]]
        S.suggestSeats(int(args[2]),int(args[3]),int(args[4]))
    

