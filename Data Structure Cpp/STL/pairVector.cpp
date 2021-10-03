#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class car{
public:
  string car_name;
  int x,y;
  car(){
  }
  car(string n, int x, int y){
    car_name = n;
    this->x = x;
    this->y = y;
  }
  int distance(){
    return x*x + y*y;
  }
};

bool compare(car A, car B){
  int d1 = A.distance();
  int d2 = B.distance();
  if(d1 == d2){
    return A.car_name.length() < B.car_name.length();
  }
  return d1 < d2;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  std::vector<car> v1;
  // vector<pair<int, int> >v;
  for(int i=0;i<n;i++){
    string name;
    int x, y;
    cin>>name>>x>>y;
    car temp(name, x, y);
    v1.push_back(temp);
  }

  sort(v1.begin(), v1.end(), compare);
  for(auto p:v1){
    cout<<"car: "<<p.car_name<<" "<<p.distance()<<" "<< p.x<<" "<<p.y <<endl;
  }
  
  return 0;
}
