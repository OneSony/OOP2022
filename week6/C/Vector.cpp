#include<iostream>
#include"Vector.h"
#include"Node.h"
using namespace std;

Vector::Vector(int n){
    capacity=n;
    len=0;//目前结尾实际存在的序号，从1开始
    array=new Node[n];
}

Vector::~Vector(){
    delete[] array;
}

Vector::Vector(const Vector & other){
    //printf("c:%d l:%d\n",other.capacity,other.len);
    capacity=other.capacity;
    len=other.len;
    array=new Node[capacity];

    for(int i=0;i<=len-1;i++){
        array[i]=other.array[i];
    }

    //for(int i=0;i<=len-1;i++){
    //    cout<<"$"<<array[i]<<endl;
    //}
}

Vector::Vector(Vector && other){
    capacity=other.capacity;
    len=other.len;
    array=other.array;
    other.array=nullptr;
    other.capacity=0;
    other.len=0;
}

Vector& Vector::operator=(const Vector& other){
    delete[] array;
    capacity=other.capacity;
    len=other.len;
    array=new Node[capacity];

    for(int i=0;i<=len-1;i++){
        array[i]=other.array[i];
    }

    return *this;
}

Vector& Vector::operator=(Vector&& other){
    delete[] array;
    capacity=other.capacity;
    len=other.len;
    array=other.array;
    other.array=nullptr;
    other.capacity=0;
    other.len=0;

    return *this;
}

Node& Vector::operator[](int pos){
    return array[pos];
}

void Vector::append(int value){
    len++;
    array[len-1]=move(Node(value));//??
}

void Vector::insert(int pos,int value){//需要把原本pos位置的数据往后移
    len++;
    for(int i=len-1;i>=pos+1;i--){//pos位不用动
        array[i]=move(array[i-1]);
    }
    array[pos]=Node(value);
    
    
    //append(value);
    //for(int i=len-1;i>=pos+1;i--){
    //    swap(i,i-1);
    //}

}

void Vector::swap(int pos1,int pos2){
    Node temp(move(array[pos1]));
    array[pos1]=move(array[pos2]);
    array[pos2]=move(temp);
}

void Vector::dilatation(){
    Node* old;
    old=array;

    array=new Node[2*capacity];

    for(int i=0;i<=len-1;i++){
        array[i]=move(old[i]);
    }

    delete[] old;

    capacity*=2;
}

int Vector::getlen(){
    return len;
}