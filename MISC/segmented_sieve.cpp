//efficient way to get all the prime numbers upto A, can be modified to find the primes in a given range
//find all the prime numbers upto limit, to further use them to find primes upto A
void simpleSieve(int limit, vector<int> &base){
    vector<bool> mark(limit+1, true);
    for(int i=2; i<=floor(sqrt(limit)); i++){
        if(mark[i] == false){
            continue;
        }
        for(int j=i*i; j<=limit; j+=i){
            mark[j] = false;
        }
    }
    for(int i=2; i<=limit; i++){
        if(mark[i]){
            base.push_back(i);
        }
    }
    return;
}
vector<int> segmentedSieve(int A) {
    int limit = floor(sqrt(A));
    vector<int> base;
    simpleSieve(limit, base);

    //can be used to find the primes in given range
    //now using base primes find next primes computing upto a limit at a time
    int low = limit;
    int high = 2*limit;

    vector<int> ans;
    for(int i=0; i<ans.size(); i++){
        ans.push_back(base[i]);
    }
    while(low<A){
        high = min(high, A);
        vector<bool> mark(limit+1, true);
        for(int i=0; i<base.size(); i++){
            int x = base[i];
            int left = low;
            left = left - (left%x);
            if(left<low){
                left += low;//smallest composite greater than lower limit
            }
            for(int j=left; j<A; j+=x){
                mark[j - low] = false;
            }
        }
        for(int i=low; i<high; i++){
            if(mark[i-low]){
                ans.push_back(i);
            }
        }
        low += limit;
        high += limit;
    }
    return ans;
}
/*
if it's asked to find primes between 100 and 200, find the primes till sqrt(200)
{you can further optimize to find primes til sqrt(200), 
by running the loop till sqrt(200) to mark the primes}. 
Now use these primes till sqrt(200) to find the primes between 100 and 200 using that while loop
*/
