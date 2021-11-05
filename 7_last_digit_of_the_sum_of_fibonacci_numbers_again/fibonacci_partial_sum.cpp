#include <iostream>
#include <vector>
using std::vector;
using std::cout;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current%10;
        }

        long long new_current = next%10;
        next = next + current%10;
        current = new_current%10;
    }

    return sum % 10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to){
    vector<int> res;
    vector<long long> fibo;
    fibo.push_back(0);
    res.push_back(0);
    fibo.push_back(1);
    res.push_back(1);

    long long tmp_len_seq = -1;

    // cout << "0 : 0" << "\n";
    // cout << "1 : 1" << "\n";

    for(int i = 2; i <= to; i++){
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
        fibo_to_compute = to%tmp_len_seq;
    }else{
        fibo_to_compute = to;
    }
    long long tmp_size = to/tmp_len_seq;
    long long from_size = from % tmp_len_seq;
    // cout << "TMP_SIZE: " << tmp_size << "\n";
    // cout << "TMP_LEN_SEQ: " << tmp_len_seq << "\n";
    // cout << "FIBO_TO_COMPUTE: " << fibo_to_compute << "\n";
    // cout << "FROM_SIZE: " << from_size << "\n";
    int ans = 0;
    if (tmp_len_seq > -1){
        for(int i = from_size; i <= tmp_len_seq; i++){
            ans += fibo[i]%10;
        }
        if(tmp_size > 1){
            for(int i = 0; i <= tmp_len_seq; i++){
                ans += fibo[i]%10;
            }
            ans = (ans )%10;
        }
    }

    for(int i = (tmp_len_seq < 0 ? from : 0); i <= fibo_to_compute; i++){
        ans += fibo[i]%10;
    }
    ans %= 10;
    return ans;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
