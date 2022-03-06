//
// Created by amirp on 1/12/2022.
//
//Problem: Development of ticket booking module for a day of typical Cinema hall.


#include "iostream"
#include "fstream"
using namespace std;
//creating Node for linked list
template<typename T>
class Node{
public:
    T ticketType;
    T phoneNumber;
    T arrivalTime;
    Node<T>* next;
    Node(T ticketType,T phoneNumber,T arrivalTime){

        this->ticketType=ticketType;
        this->phoneNumber=phoneNumber;
        this->arrivalTime=arrivalTime;
        this->next=NULL;
    }
};
//creating Queue
template<typename T>
class Queue{
    int size;
    Node<T>*head;
    Node<T>*tail;
public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    int getSize(){
        return size;
    }
    void enqueue(T ticketType,T phoneNumber,T arrivalTime){
        Node<T>*node=new Node(ticketType,phoneNumber,arrivalTime);
        if(head==NULL){
            head=node;
            tail=node;
        } else{
            tail->next=node;//inserting at tail
            tail=tail->next;
        }
        size++;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        return head->data;
    }
    void dequeue(){
        if(!isEmpty()){
            Node<T>*tempHead=head;
            head=head->next;
            tempHead=NULL;
            delete tempHead;
        }else{
            cout<<"Queue is Empty";
        }

    }
};


//class for store customer data;
class Customer{
private:
    string ticketType;
    long phoneNumber;
    long arrivalTime;
public:


    //constructor for adding data in customer
    Customer(string ticketType,long phoneNumber,long arrivalTime){
        this->ticketType=ticketType;
        this->phoneNumber=phoneNumber;
        this->arrivalTime=arrivalTime;
    }
    void showTicket(){
        cout<<ticketType;
    }
    void showPhoneNumber(){
        cout<<phoneNumber;
    }
    void showArrivalTime(){
        cout<<arrivalTime;
    }
    void setTicketType(string ticketType){
        this->ticketType=ticketType;
    }
    void setPhoneNumber(long phoneNumber){
        this->phoneNumber=phoneNumber;
    }
    void setArrivalTime(long arrivalTime){
        this->arrivalTime=arrivalTime;
    }

};


int main(){

   fstream file;
   file.open("../Lab/ticketData.txt",ios::in);
   if(file.is_open()){
       string data;
       long phoneNumber,arrivalTime;
       string ticketType;
       getline(file,data,',');
       getline(file,ticketType,',');
       cout<<data;
       cout<<endl<<ticketType;
   } else{
       cout<<"file is not open";
   }

   file.close();

   return 0;
}