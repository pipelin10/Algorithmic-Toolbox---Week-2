#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m){
    vector<int> res;
    vector<long long> fibo;
    fibo.push_back(0);
    res.push_back(0);
    fibo.push_back(1);
    res.push_back(1);

    long long tmp_len_seq = -1;

    // cout << "0 : 0" << "\n";
    // cout << "1 : 1" << "\n";

    for(int i = 2; i <= n; i++){
        // cout << "NOW ON FIBO " << i << "\n";
        fibo.push_back(fibo[i-1]%m + fibo[i-2]%m);
        res.push_back(fibo[i]%m);
        // cout << i << " : " << res[i] << "\n";
        if(res[i] == 1 && res[i-1] == 0){
            tmp_len_seq = (int)res.size()-2;
            break;
        }
    }

    
    long long fibo_to_compute;
    if(tmp_len_seq > -1){
        fibo_to_compute = n%tmp_len_seq;
    }else{
        fibo_to_compute = n;
    }
    // cout << "FIBO TO COMPUTE " << fibo_to_compute << "\n";
    return fibo[fibo_to_compute] % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge_fast(n,m) << "\n";
}
