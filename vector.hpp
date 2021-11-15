#include <iostream>
#include <vector>
using namespace std;
namespace myvec {

  class Vector {
  private:
    float *v; // Puntero v
    int len;   // Longitud del vector
    
  public:

    //El constructor:
    Vector( int len_ ){
      SetSize(len_);
      v = new float[len_]{0};  //"Vector" lista con len_ espacios
    };  

    //Métodos:
    void SetSize( int len_ ){   //Setter
      len = len_;
    }

    int GetSize(){              //Getter
      return len;
    }

    float GetPos(int p){
      if(p<=len & p>0){
        cout<< v[p-1] <<endl;
        return v[p-1];
      }
      else{
        cout<< "El índice se sale de la longitud del vector."<<endl;
        return 0;
        //exit(0);
      }
    }

    void SetPos(int i, float x) {
        if (i < 0 || i > len-1){
          cout<< "Index out of bounds"<<endl;
        }
        else{
          v[i] = x;
        }
    }

    void PrintVec(){
      cout << "|";
      for(int i = 0; i < len; i++){
        cout << v[i] << "|";
      }
      cout<<endl;
    }

    //Sobrecarga de operadores: 

    Vector& operator=(Vector& obj){
      for (auto i = 0; i < 3; i++)
          this->v[i] = obj.v[i];
      return *this;
    }

    Vector& operator+(Vector& obj){
      for (auto i = 0; i < 3; i++)
          this->v[i] = this->v[i] + obj.v[i];
      return *this;
    }

    Vector& operator-(Vector& obj){
      for (auto i = 0; i < 3; i++)
          this->v[i] = this->v[i] - obj.v[i];
      return *this;
    }

    float& operator[](int index){
      if (index >= len) {
          cout << "Array index out of bound, exiting";
          //exit(0);
      }
    return v[index];
    }
  };



}