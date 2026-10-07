#include<iostream>
using namespace std;
class Vehicle
{
 public:
     virtual void start()=0;
     virtual void stop()=0;
};
class car:public Vehicle
{
 public:
void start() override
{
  cout<<"Car starts with a key"<<endl;
}
void stop() override
{
  cout<<"Car stops with a key"<<endl;
}
};
class Bike:public Vehicle
{
public:
void start() override
{
  cout<<"Bike starts with a key"<<endl;
}
void stop() override
{
  cout<<"Bike stops with a key"<<endl;
} 
};
int main()
{
  Car car;
  Bike bike;

  Vehicle *v;
   v=&bike;
  v->start();
  v->stop();
  cout<<endl;
  v=&bike;
  v->start();
  v->stop();
  return 0;
}
