int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> s;//the stack holds the indices of the array in inncreasing order(top to bottom)
    int ans = 0;
    int curr_highest;//stores top of stack
    int area_with_top;//area with top bar as the smallest bar
    int i = 0;
    int n = A.size();
    while(i<n){
        
        //keep pushing bars if current value is higher than top of stack, 
        //because we can extend the width of lowest bar in the stack(which is of least height)
        //until a lower height bar is encountered
        if(s.empty() || A[i] >= A[s.top()]){
            s.push(i);
            i++;
        }
        
        // area is calculated everytime stack is popped
        //this else{} basically keeps popping the stack top while it is greater than current bar(i is constant)
        else{
            curr_highest = s.top();
            s.pop();
            //calculate the area with A[top] as smallest bar
            if(s.empty()){
                area_with_top = A[curr_highest] * i;
            }
            else{
                area_with_top = A[curr_highest] * (i - 1 - s.top());//height*width; 
                                                    //s.top() represents the curr_highest of left limiting bar
                                                    //i-1 represents the curr_highest of current bar
                
            }
            ans = max(ans, area_with_top);
        }
    }
    
    //following loop is for the bars which are of lower height than last bar
    // Now pop the remaining bars(and find area for them) from stack and calculate 
    // area with every popped bar as the smallest bar 
    while(!s.empty()){
        curr_highest = s.top();
        s.pop();
        if(s.empty()){
            area_with_top = A[curr_highest]*i;
        }
        else{
            area_with_top = A[curr_highest]*(i-s.top()-1);
        }
        ans = max(ans, area_with_top);
    }
    return ans;
}
