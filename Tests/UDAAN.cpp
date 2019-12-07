#include<bits/stdc++.h>
using namespace std;
class screen{
    public:
    int no_rows, seats_pr;
    unordered_map<int, int>aisle;
    vector<vector<bool> > occupied;
    screen(int a, int b, unordered_map<int, int> new_aisle){
        no_rows = a;
        seats_pr = b;
        occupied.clear();
        occupied.resize(no_rows+1, vector<bool>(seats_pr+1, false));
        aisle.clear();
        aisle = new_aisle;
    }
    int booktickets(int row_no, vector<int> seats_to_book){
        if(row_no >= no_rows || seats_to_book.size() > seats_pr){
            return -1;
        }
        vector<vector<bool> >temp = occupied;
        for(int i=0; i<seats_to_book.size(); i++){
            int seat_num = seats_to_book[i];
            if(occupied[row_no][seat_num] == true){
                occupied = temp;
                return -1;
            }
            occupied[row_no][seat_num] = true;
        }
        return 0;
    }
    vector<int> get_unreserved(int row_no){
        vector<int> unreserved_seats;
        if(row_no > no_rows){
            return unreserved_seats;
        }
        for(int j=1; j<=seats_pr; j++){
            if(!occupied[row_no][j]){
                unreserved_seats.push_back(j);
            }
        }
        return unreserved_seats;
    }
    vector<int> list_contiguous(int no_of_seats_to_be_booked, int row_no, int choice_seat_number){
        vector<int> seats;
        if(row_no > no_rows || choice_seat_number > seats_pr || occupied[row_no][choice_seat_number]){
            return seats;
        }
        if(aisle.find(choice_seat_number) != aisle.end() && aisle.find(choice_seat_number - 1) != aisle.end() && aisle.find(choice_seat_number + 1) != aisle.end()){
            seats.push_back(choice_seat_number);
            seats.push_back(choice_seat_number - 1);
            return seats;
        }
        if( (choice_seat_number == 1) || (aisle.find(choice_seat_number) != aisle.end() && aisle.find(choice_seat_number - 1) != aisle.end())){
            seats.clear();
            int cnt = 0;
            for(int i=choice_seat_number; i<=seats_pr; i++){
                if(seats.size() == no_of_seats_to_be_booked){
                    return seats;
                }
                if(!occupied[row_no][i]){
                    if(cnt != 0 && i > 1 && aisle.find(i) != aisle.end() && aisle.find(i-1) != aisle.end()){
                        break; 
                    }
                    else{
                        if(aisle.find(i) != aisle.end()){
                            cnt++;
                        }
                        seats.push_back(i);
                    }
                }
                else{
                    break;
                }
            }
            if(seats.size() == no_of_seats_to_be_booked){
                return seats;
            }
        }
        else if( (choice_seat_number == seats_pr) || (aisle.find(choice_seat_number) != aisle.end() && aisle.find(choice_seat_number + 1) != aisle.end()) ){
            seats.clear();
            int cnt = 0;
            for(int i=choice_seat_number; i>=1; i--){
                if(seats.size() == no_of_seats_to_be_booked){
                    return seats;
                }
                if(!occupied[row_no][i]){
                    if(cnt != 0 && i < seats_pr && aisle.find(i) != aisle.end() && aisle.find(i+1) != aisle.end()){
                        break; 
                    }
                    else{
                        if(aisle.find(i) != aisle.end()){
                            cnt++;
                        }
                        seats.push_back(i);
                    }
                }
                else{
                    break;
                }
            }
            if(seats.size() == no_of_seats_to_be_booked){
                return seats;
            }
        }
        else{
            seats.clear();
            int cnt1 = 0;
            int cnt2 = 0;
            int i = choice_seat_number;
            int j = choice_seat_number - 1;
            while(true){
                if(i > seats_pr && j < 1){
                    break;
                }
                if(seats.size() == no_of_seats_to_be_booked){
                    return seats;
                }
                if(occupied[row_no][i] && occupied[row_no][j]){
                    break;
                }
                if(cnt1 != 0 && cnt2 != 0){
                    break;
                }
                if(aisle.find(i) != aisle.end()){
                    if(cnt1 == 0 && i <= seats_pr){
                        cnt1++;
                        seats.push_back(i);
                    }
                }
                else{
                    if(i <= seats_pr){
                        seats.push_back(i);
                    }
                }
                if(aisle.find(j) != aisle.end()){
                    if(cnt2 == 0 && j >= 1){
                        cnt2++;
                        seats.push_back(j);
                    }
                }
                else{
                    if(j >= 1){
                        seats.push_back(j);
                    }
                }
                i++;
                j--;
            }
            if(seats.size() == no_of_seats_to_be_booked){
                return seats;
            }
        }
        return seats;
    }
};
int main(){
    int q;
    cin>>q;
    map<string, screen*>screens;
    int temp = 0;
    while(q--){
        string query;
        if(temp == 0){
            cin.ignore();
        }
        getline(cin, query);
        temp++;
        stringstream ss(query);
        string cmd;
        ss>>cmd;
        // cout<<"cmd = "<<cmd<<endl;
        if(cmd == "add-screen"){
            string name;
            int no_rows, seats_pr;
            ss>>name;
            ss>>no_rows>>seats_pr;
            unordered_map<int, int>  aisle;
            while(ss){
                int seat;
                ss>>seat;
                // cout<<"here"<<endl;
                aisle[seat] = 1;
            }
            if(screens.find(name) != screens.end()){
                cout<<"failure"<<endl;
            }
            screen* s = new screen(no_rows, seats_pr, aisle);
            screens[name] = s;
            cout<<"success"<<endl;
        }
        else if(cmd == "reserve-seat"){
            string name;
            ss>>name;
            int f = 0;
            if(screens.find(name) == screens.end()){
                f = 1;
            }
            screen* s = screens[name];
            int row_no;
            ss>>row_no;
            vector<int> to_reserve;
            while(ss){
                int seat;
                ss>>seat;
                to_reserve.push_back(seat);
            }
            to_reserve.pop_back();
            if(f){
                cout<<"failure"<<endl;
                continue;
            }
            int result = s->booktickets(row_no, to_reserve);
            if(result == -1){
                cout<<"failure"<<endl;
            }
            else{
                
               cout<<"success"<<endl; 
            }
        }
        else if(cmd == "get-unreserved-seats"){
            string name;
            ss>>name;
            int f = 0;
            if(screens.find(name) == screens.end()){
                f = 1;
            }
            screen *s = screens[name];
            int row_no;
            ss>>row_no;
            if(f){
                cout<<"none"<<endl;
                continue;
            }
            vector<int> seats_free = s->get_unreserved(row_no);
            if(seats_free.size() == 0){
                cout<<"none"<<endl;
                continue;
            }
            for(int i=0; i<seats_free.size(); i++){
                cout<<seats_free[i]<<" ";
            }
            cout<<endl;
        }
        else{
            string name;
            ss>>name;
            int f = 0;
            if(screens.find(name) == screens.end()){
                f = 1;
            }
            screen* s = screens[name];
            int no_of_seats_to_be_booked, row_no, choice_seat_number;
            ss>>no_of_seats_to_be_booked>>row_no>>choice_seat_number;
            if(f){
                cout<<"none"<<endl;
                continue;
            }
            vector<int> seats = s->list_contiguous(no_of_seats_to_be_booked, row_no, choice_seat_number);
            if(seats.size() != no_of_seats_to_be_booked){
                cout<<"none"<<endl;
            }
            else{
                sort(seats.begin(), seats.end());
                for(int i=0; i<seats.size(); i++){
                    cout<<seats[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}

/*
9
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguous-seats Screen2 4 10 3
*/




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
    

