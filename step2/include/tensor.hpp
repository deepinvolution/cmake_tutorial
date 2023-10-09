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
Tensor<T> operator+(const Tensor<T>& lhs, const Tensor<T>& rhs);