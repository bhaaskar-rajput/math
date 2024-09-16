#include<iostream>
#include<cmath>
using namespace std;

bool is_value_integer(float value);
char sqrt_symbol = 251;
int main(){
    int a=0,b=0,c=0;
    cout<<"Enter the coefficients of the polynomial : \n";
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<"c = ";
    cin>>c;
    int d = pow(b,2) - 4*a*c;
    float D = sqrt(d);
    float x_1 = (-b + D)/(2*a);
    float x_2 = (-b - D)/(2*a);

    int int_x_1=static_cast<int>(round(x_1));
    int int_x_2=static_cast<int>(round(x_2));
 
    //check whether the values of x are integer or not;
    bool is_int=true;
    if(x_1!=(float)int_x_1 || x_2!=(float)int_x_2){
        //cout<<"Not Integer!!";
        is_int=false;
    }
    //else cout<<"Interger!!!!\n";
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
    // cout<<x_1<<endl;
    // cout<<x_2<<endl;

    if(d<0)cout<<"No real factors exist.";
    else if(is_int==true){
        if(x_1<0)cout<<"The factors are (x - "<< -x_1 <<")";
        else cout<<"The factors are (x + "<< x_1 <<")";
        if(x_2<0)cout<<" `and (x - "<< -x_2 <<")";
        else cout<<" and (x + "<< x_2 <<")";
    }
    else if(is_int==false && is_value_integer(D)==true) cout<<"The factors are (x - "<< (b - D) <<")/"<< 2*a <<") and (x - "<< (b + D)<<")/"<< 2*a <<")";
    else if(is_int==false && is_value_integer(D)==false) cout<<"The factors are [x - ("<< b <<" - "<<sqrt_symbol<< d <<")/"<< 2*a <<"] and [x - ("<< b <<" + "<<sqrt_symbol<< d<<")/"<< 2*a <<"]";
    return 0;
}

bool is_value_integer(float value){
    return (value == static_cast<int>(value));
}
