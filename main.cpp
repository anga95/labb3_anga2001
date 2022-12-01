#include <iostream>
#include <utility>
#include "p_queue.h"
#include <ctime>


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
    os << rhs.name << "\t[" << rhs.value << "]";
    return os;
}
void placeOrders(const std::string &name, p_queue<order> &vec){
    for (int i = 0; i < 7; i++) {
        order o = {name, ( 15+ rand() %  15)};
        vec.push(o);
    }
}
void broker(p_queue<order> &sellerList, p_queue<order> &buyerList){
    order seller = sellerList.pop();
    order buyer = buyerList.pop();
    std::vector<std::pair<order, order>> sales;
    while (!sellerList.empty() && !buyerList.empty()){

        if (buyer.value >= seller.value){

            std::cout<<"[" << buyer.value << "] >= [" << seller.value
                     <<"] --- [" << buyer.name << "] köpte från [" << seller.name <<"]"<< std::endl;
            sales.emplace_back(buyer,seller);
            seller = sellerList.pop();
        } else{
            std::cout <<"Lägsta sälj pris: ["<<seller.value<< "]. Lägsta köp pris: ["<<buyer.value<<"] kr. "<<
            buyer.name << " stryks från köp pga snåljåp" << std::endl;
        }
            buyer = buyerList.pop();

    }
    std::cout << std::endl;
    std::cout << "Köp som genomfördes: [" << sales.size() <<"]" << "\n";
    for (auto e: sales) {
        std::cout << e.first << " köpte från " << e.second << "\n";
    }
}


int main() {
    std::srand(std::time(nullptr));
    p_queue<order> seller;
    p_queue<order> buyer;

    placeOrders("Erik Pendel", buyer);
    placeOrders("Jarl Wallenburg", buyer);
    placeOrders("Joakim con Anka", buyer);

    placeOrders("Erik Pendel", seller);
    placeOrders("Jarl Wallenburg", seller);
    placeOrders("Joakim con Anka", seller);

    broker(seller,buyer);
//    while (!buyer.empty()){
//        std::cout << buyer.pop();
//    }

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
