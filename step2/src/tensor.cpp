#include "tensor.hpp"

template <typename T>
class Tensor {
public:
    Tensor(int x) { data.resize(x); };
    Tensor(std::initializer_list<T> data) : data(data) {};
    void size() { return data.size(); };
    friend std::ostream& operator<< <>(std::ostream& os, const Tensor<T>& rhs);
    friend Tensor<T> operator+ <>(const Tensor<T>& lhs, const Tensor<T>& rhs);

private:
    std::vector<T> data;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tensor<T>& rhs) {
    for (T x : rhs.data) os << x << " ";
    return os;
}

template <typename T>
Tensor<T> operator+(const Tensor<T>& lhs, const Tensor<T>& rhs) {
    int n = std::min(lhs.data.size(), rhs.data.size());
    Tensor<T> res(n);
    for (int i = 0; i < n; i++)
        res.data[i] = lhs.data[i] + rhs.data[i];
    return res;
}