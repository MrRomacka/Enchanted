#include <iostream>
#include <cstring>

using namespace std;

class Str{
    int len;
    char * str;
public:
    Str();
    Str(const char *);
    Str(const Str&);
    Str& operator= (const Str&);
    ~Str();
    int getlen() const {return len;};
    char *getstr() const {return str;};
};

Str::Str (){
    str = new char[0];
    len = 0;
}

Str::Str (const char *string){
//    int i = 0;
//    while(1){
//        if(string[i] != 0) i++;
//        else break;
//    }
//    len = i;
    len = strlen(string);
    str = new char [len+1];
    for(int i=0; i<len; i++)
        str[i] = string[i];
    str[len] = 0;
}

Str::Str (const Str &string) {
    len = string.getlen();
    char *tmp = string.getstr();
    str = new char [len+1];
    for(int i=0; i<len; i++)
        str[i] = tmp[i];
    str[len] = 0;
}

Str::~Str() {
    delete str;
}

Str & Str::operator = (const Str &string){
    this->len = string.getlen();
    delete this->str;
    this->str = new char[len+1];
    char * tmp = string.getstr();
    for(int i = 0; i<len; i++){
        this->str[i] = string.str[i];
    }
    return *this;
}

class Man {
    int age;
    Str name;
public:
    Man();
    Man(const char *, const int);
    Man(const Str, const int);
    Man& operator= (const Man&);
    int getage() const {return age;};
    Str getname() const {return name;};

};

Man::Man(){
    Str Void;
    name = Void;
    age = 0;
}

Man::Man(const char *string, const int a=0){
    Str Void(string);
    name = Void;
    age = a;
}

Man::Man(const Str A, const int a=0){
    Str Void(A);
    name = Void;
    age = a;
}

Man & Man::operator = (const Man &man){
    Str Void(man.getname());
    name = Void;
    age = man.getage();
    return *this;
}

int main(){
    Str Void;
    cout << Void.getstr() << " ";

    Str A("hey");
    cout << A.getstr() << " ";

    Str B(A);
    cout << B.getstr() << " ";

    Str C("no");
    cout << C.getstr() << " ";

    C = A;
    cout << C.getstr() << " ";

    Str D = A;
    cout << D.getstr() << " ";

    Man MisterHey(D, 13);
    cout << MisterHey.getname().getstr() << MisterHey.getage() << " ";

    Man Alex("Alex");
    cout << Alex.getname().getstr() << Alex.getage() << " ";

    Man SubAlex;
    SubAlex = Alex;
    Alex.~Man();
    cout << SubAlex.getname().getstr() << SubAlex.getage() << " ";
}