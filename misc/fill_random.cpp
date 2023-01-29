#include <bits/stdc++.h>

// T is a numeric type
template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class generator {
    using distribution_type = typename std::conditional<
        std::is_integral<T>::value,
        std::uniform_int_distribution<T>,
        std::uniform_real_distribution<T>
    >::type;
    std::default_random_engine engine;
    distribution_type distribution;
public:
    auto operator()() {
        return distribution(engine);
    }
};

template <typename T>
void fill_random(std::vector<T>& vec) {
    std::generate(vec.begin(), vec.end(), generator<T>());
}

int main() {
    std::vector<unsigned long long> vec(10);
    fill_random(vec);
    for (auto v : vec) std::cout << v << ' ';
    std::cout << '\n';
}