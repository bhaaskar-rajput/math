#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int number_inside_sq,remaining_sq=0,sq;
    cout<<"Enter the number inside the square root : ";
    cin>>number_inside_sq;

    if(number_inside_sq<0){
        cout<<"Square root of negative number is not supported yet.";
    }
    else{
        remaining_sq=number_inside_sq;

        for(int i=2;i<=number_inside_sq;i++){
            
            sq=(i*i);

            if(remaining_sq%sq==0 && remaining_sq>=sq){
                do{remaining_sq=remaining_sq/sq;}
                while(remaining_sq%sq==0);
            }
        }
        cout<<sqrt(number_inside_sq/remaining_sq)<<"sqrt("<<remaining_sq<<")";
    }
    return 0;
}
