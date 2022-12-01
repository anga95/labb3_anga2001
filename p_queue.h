//
// Created by AnGa on 2022-11-29.
//

#ifndef LABB3_ANGA2001_P_QUEUE_H
#define LABB3_ANGA2001_P_QUEUE_H

#include <vector>

template<typename T, typename Comp = std::less<T>>
class p_queue {
private:
    std::vector<T> vec;
    Comp cmp;
public:
    T pop(){
        T value = vec.front();
        vec.erase(vec.begin());
        return value;
    }
    void push(T e){
        vec.push_back(e);
        if (vec.size() > 1){
            std::sort(vec.begin(), vec.end(), cmp);
        }
    }
    int size() {
        return vec.size();
    }
    bool empty(){
        return vec.empty();
    }
};



//template<typename T, typename comp>
//T p_queue<T, comp>::pop(){
//    T value = vec.front();
//    vec.erase(vec.begin());
//    return value;
//}
//template<typename T, typename comp>
//void p_queue<T, comp>::push(T e) {
//    vec.push_back(e);
//    if (vec.size() > 1){
//        std::sort(vec.begin(), vec.end(), comp());
//    }
//}

//template<typename T, typename comp>
//int p_queue<T,comp>::size() {
//    return vec.size();
//}

//template<typename T, typename comp>
//bool p_queue<T,comp>::empty() {
//    return vec.empty();
//}

#endif //LABB3_ANGA2001_P_QUEUE_H
