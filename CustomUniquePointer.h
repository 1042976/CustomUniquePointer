//
// Created by Xiaodong Liu on 8/22/22.
//

#ifndef CUSTOMUNIQUEPOINTER_CUSTOMUNIQUEPOINTER_H
#define CUSTOMUNIQUEPOINTER_CUSTOMUNIQUEPOINTER_H

#include <memory>

using namespace std;
namespace ns{
    //unique_ptr<T>
    template<class T, class Deleter = default_delete<T> >
    class unique_ptr{
    private:
        T* ptr;
        Deleter deleter;
    public:
        //default
        unique_ptr():ptr(nullptr){}

        //construct with a value
        unique_ptr(T* _ptr, const Deleter& _deleter=default_delete<T>()):ptr(_ptr), deleter(_deleter){}

        //copy constructor - delete
        unique_ptr(const unique_ptr& other) = delete;

        //copy assignment operator - delete
        unique_ptr& operator = (const unique_ptr& other) = delete;

        //move constructor
        unique_ptr(unique_ptr&& other){
            this->ptr = other.ptr;
            other.ptr = nullptr;
        }

        //move assignment operator
        unique_ptr& operator = (unique_ptr&& other){
            if(this != &other){
                delete ptr;
                this->ptr = other.ptr;
                other.ptr = nullptr;
            }
            return *this;
        }

        //reference
        T* operator->(){
            return ptr;
        }

        //dereference
        T& operator*(){
            return *ptr;
        }

        //if is empty
        explicit operator bool() const noexcept{
            return ptr != nullptr;
        }

        //get stored pointer
        T* get() const noexcept{
            return ptr;
        }

        //destructor

        ~unique_ptr(){
            deleter(ptr);
        }

    };

    //unique_ptr<T[]>
    template<class T, class Deleter>
    class unique_ptr<T[], Deleter>{
    private:
        T* ptr;
        Deleter deleter;
    public:
        //default
        unique_ptr():ptr(nullptr){}

        //construct with a value
        unique_ptr(T* _ptr, const Deleter& _deleter=default_delete<T[]>()):ptr(_ptr), deleter(_deleter){}

        //copy constructor - delete
        unique_ptr(const unique_ptr& other) = delete;

        //copy assignment operator - delete
        unique_ptr& operator = (const unique_ptr& other) = delete;

        //move constructor
        unique_ptr(unique_ptr&& other){
            this->ptr = other.ptr;
            other.ptr = nullptr;
        }

        //move assignment operator
        unique_ptr& operator = (unique_ptr&& other){
            if(this != &other){
                delete ptr;
                this->ptr = other.ptr;
                other.ptr = nullptr;
            }
            return *this;
        }

        //reference
        T* operator->(){
            return ptr;
        }

        //dereference
        T& operator*(){
            return *ptr;
        }

        T& operator[](size_t i){
            return *(ptr+i);
        }
        //if is empty
        explicit operator bool() const noexcept{
            return ptr != nullptr;
        }

        //get stored pointer
        T* get() const noexcept{
            return ptr;
        }

        //destructor

        ~unique_ptr(){
            deleter(ptr);
        }

    };
}
#endif //CUSTOMUNIQUEPOINTER_CUSTOMUNIQUEPOINTER_H
