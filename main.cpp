#include <iostream>
#include <typeinfo>
#include <vector>
#include "ring.h"
#include <memory>
#include <set>
#include <algorithm>


class Test{
private:
    int id{3};
public:
    Test()=default;
    Test(const Test &other)=default;
    Test &operator=(const Test &rhs)=default;

    Test(int id): id{id}{
        std::cout<<"Constructor for "<<id<<std::endl;
    }

    void print(){
        cout<<id<<endl;
    }
    ~Test(){
        std::cout<<"Test destructor "<<id<<std::endl;
    }
};



int main() {
    int size{};
    cin>>size;
    int count{};
    vector<int> queries(size);

    while (count<queries.size()){
        cin>>queries.at(count);
        count++;
    }
    int max{};
    for(auto &v: queries){
        if (v> max)
            max=v;
    }
    cout<<"max num is: "<<max<<endl;





    return 0;
}
