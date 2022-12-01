#include <iostream>
#include <utility>
#include "p_queue.h"

//template<typename T>
struct order{
    std::string name;
    int value;
};

template<>
struct std::less<order> {
    bool operator()(const order& lhs, const order& rhs) {
        return lhs.value < rhs.value;
    }
};
std::ostream& operator <<(std::ostream &os, const order& rhs){
    os << rhs.name << "\t[" << rhs.value << "]\n";
    return os;
}
void placeOrders(std::string name, p_queue<order> &vec){
    for (int i = 0; i < 7; i++) {
        order o = {name, ( 15+ rand() %  15)};
        vec.push(o);
    }
}
int main() {
    p_queue<order> seller;
    p_queue<order> buyer;
    placeOrders("Erik Pendel", buyer);
    placeOrders("Jarl Wallenburg", buyer);
    placeOrders("Joakim con Anka", buyer);

    placeOrders("Erik Pendel", seller);
    placeOrders("Jarl Wallenburg", seller);
    placeOrders("Joakim con Anka", seller);

    std::cout << "size: " << buyer.size() << std::endl << std::endl;
    int count = 0;
    while (!buyer.empty()){
        std::cout << buyer.pop();
    }

    std::cout << "size: " << buyer.size() << std::endl << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//struct compare_by_price{
//    bool operator()(const order& lhs, const order& rhs) {
//        return lhs.value < rhs.value ;
//    }
//};
//template<typename T>
//class broker{
//    p_queue<T> buffer;
//    std::string name;
//public:
//    explicit broker(std::string name) : buffer(), name(std::move(name)){ }
//    T sell(){
//        return buffer.pop();
//    }
//    void add(T e){
//        buffer.push(e);
//    }
//    int size() {
//        return buffer.size();
//    }
//    bool empty(){
//        return buffer.empty();
//    }
//    const std::string getName()const{
//        return name;
//    }
//
//};
//
//template<typename T>
//class seller{
//    p_queue<T> buffer;
//    std::string name;
//
//};
