#include <iostream>
using namespace std;

//a class is made
class student{
    string name;

//anything above public is private
    public:
    //everything below this is public can be used outside the class
    int age;
    bool gender;
    //atributes set here

    student(string s,int a,int g){//parameterized constructor
        name=s;
        age=a;
        gender=g;
    }

    student(){//degault constructor
        cout<<"Default Constructor";
    }

    student(student &a){//copy constructor
        name=a.name;//attributes of object a is copied
        age=a.age;
        gender=a.gender;
    }

    ~student(){//this is a destructor to destroy an object after main function ends
        cout<<"Destructed"<<endl;
    }

    bool operator == (student &a){//operator overloading is done this way by passing the actual address
        if(name==a.name && age==a.age && gender==a.gender)
        return true;
        else 
        return false;
    }




    void setName(string s){//a set name is used for private data type accessing
        name=s;
    }

    void printInfo(){//printing the attributes of a object
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
    }
};

int main(){
    // student arr[3];
    // for(int i=0;i<3;i<i++){
    //     string s;
    //     cin>>s;
    //     arr[i].setName(s);
    //     cin>>arr[i].age;
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }
    student a("Megha",1,1);
    a.printInfo();

    student b("Neha",1,2);
    b.printInfo();

    student c=a;//copy constructor written like this or by this "student c(a);""
    c.printInfo();

    if(a==c)//for this we need operator overloading
    cout<<"Same"<<endl;
    else
    cout<<"Different"<<endl;
    return 0;
}