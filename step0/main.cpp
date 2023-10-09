#include <iostream>
#include <vector>
#include <initializer_list>

// forward delaration of Tensor and Tensor::operator<<
// for the sake of template generation
// friend declaration only will disable compiler from generating template
// see this: https://dboyliao.medium.com/operator-overloading-for-template-class-in-c-5f45c6c5971e
// and this: https://isocpp.org/wiki/faq/templates?source=post_page-----5f45c6c5971e--------------------------------#template-friends
template <typename T>
class Tensor;
template <typename T>
std::ostream& operator<<(std::ostream& os, const Tensor<T>& rhs);

template <typename T>
class Tensor {
public:
    Tensor(int x) { data.resize(x); };
    Tensor(std::initializer_list<T> data) : data(data) {};
    void size() { return data.size(); };
    friend std::ostream& operator<< <>(std::ostream& os, const Tensor<T>& rhs);
    // friend Tensor<T> operator+(Tensor<T> lhs, Tensor<T> rhs);

private:
    std::vector<T> data;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tensor<T>& rhs) {
    for (T x : rhs.data) os << x << " ";
    return os;
}

// template <typename T>
// Tensor<T> operator+(Tensor<T> lhs, Tensor<T> rhs) {
//     int size = lhs.data.size();
//     Tensor<T> res(size);
//     for (int i = 0; i < size; i++)
//         res.data[i] = lhs.data[i] + rhs.data[i];
//     return res;
// }

int main() {
    Tensor<int> A = {1, 1, 1, 1, 1};
    Tensor<int> B = {1, 2, 3, 4, 5};
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    // Tensor<int> C = A + B;
    // C.printData();
    return 0;
}