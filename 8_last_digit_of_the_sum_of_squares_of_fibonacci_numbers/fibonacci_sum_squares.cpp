#include <iostream>
#include <vector>
using namespace std;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%10;
        previous = current%10;
        current = (tmp_previous + current)%10;
        sum += (current%10 * current%10)%10;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n){
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
        fibo.push_back((fibo[i-1] + fibo[i-2])%10);
        res.push_back(fibo[i]%10);
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
    long long tmp_size = n/tmp_len_seq;
    // cout << "TMP_SIZE: " << tmp_size << "\n";
    // cout << "FIBO_TO_COMPUTE: " << fibo_to_compute << "\n";
    // cout << "FIBO TO COMPUTE " << fibo_to_compute << "\n";
    int ans = 0;
    if (tmp_len_seq > -1){
        for(int i = 0; i <= tmp_len_seq; i++){
            ans += (fibo[i]%10*fibo[i]%10)%10;
        }
        ans = (ans)%10;
    }

    for(int i = 0; i <= fibo_to_compute; i++){
        ans += (fibo[i]%10*fibo[i]%10)%10;
    }
    ans %= 10;
    return ans;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n) << "\n";
    std::cout << fibonacci_sum_squares_fast(n) << "\n";
}
