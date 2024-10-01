#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<cmath>
using namespace std;

char sq=253;    //Character Set : Code page 437
int count=1;

struct quad_poly{
    struct constants{
        int num=0,den=1;
    }a,b,c,z1,z2;
}qpoly;

void generate_question();
void generate_other_question();
int random_single_int();

int main(){
    
    cout<<"Welcome to the Practice Session.\n\n";
    
    bool exit=false;
    char ch;
    
    do{
        cout<<"Press enter to continue...\n\n";
        ch=cin.get();
        if(ch=='\n'){
            cout<<"Question : "<<count<<endl;
            cout<<"\n";
            count+=1;
            generate_question();
        }
        else if(ch != 'X')
            {
                continue;
                cout<<endl<<exit<<endl;
            }
        else exit=true;
    }
    while(exit != true);
    
    return 0;
}

void generate_question(){
    qpoly.z1.num=random_single_int();
    qpoly.z2.num=random_single_int();
    if(random_single_int()%3==0)cout<<"Factorise : x"<<sq<<" - "<<qpoly.z1.num + qpoly.z2.num<<"x + "<<qpoly.z1.num*qpoly.z2.num<<endl<<endl;
    else if(random_single_int()%3==1)cout<<"Factorise : x"<<sq<<" + "<<qpoly.z1.num + qpoly.z2.num<<"x + "<<qpoly.z1.num*qpoly.z2.num<<endl<<endl;
    else generate_other_question();
}

void generate_other_question(){
    if((qpoly.z1.num - qpoly.z2.num)>0)cout<<"Factorise : x"<<sq<<" - "<<qpoly.z1.num - qpoly.z2.num<<"x - "<<qpoly.z1.num*qpoly.z2.num<<endl<<endl;
    else if((qpoly.z1.num - qpoly.z2.num)<0)cout<<"Factorise : x"<<sq<<" + "<<-(qpoly.z1.num - qpoly.z2.num)<<"x - "<<qpoly.z1.num*qpoly.z2.num<<endl<<endl;
    else generate_question();
}

int random_single_int(){
    struct tm datetime;
    time_t now;
    now = time(&now);
    datetime = *localtime(&now);
    int i;
    double d=pow(datetime.tm_sec,2)+10;
    return i = rand()%(((static_cast<int>(d)%25))+1)+1;
}
