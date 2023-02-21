//
// Created by Bakhtiyor on 20/01/2023.
//

#ifndef FEATURES_RING_H
#define FEATURES_RING_H
#include <iostream>
using namespace std;

template <class T>

class ring {
private:
    int m_pos;
    T *m_value;
    int m_size;
public:
    class iterator;
    ring(int size):
    m_pos{0}, m_size{size}, m_value{0}{
        m_value=new T[size];
    }

    ~ring(){
        delete [] m_value;
    }

    int size(){
        return m_size;
    }

    void add(T value){
        this->m_value[m_pos]=value;
        m_pos++;

        if(m_pos==m_size){
            m_pos=0;
        }
    }

    T &get(int pos){
        return m_value[pos];
    }

    iterator begin(){
        return iterator(0, *this);
    }

    iterator end(){
        return iterator(m_size, *this);
    }

};


template <class T>

        class ring<T>::iterator{
        private:
            int m_pos;
            ring m_ring;
public:
    iterator(int pos, ring &ringObj): m_pos(pos), m_ring(ringObj){

    }
    iterator &operator++(){
        m_pos++;
        return *this;
    }

    T &operator*(){
        return m_ring.get(m_pos);
    }
};
#endif //FEATURES_RING_H
