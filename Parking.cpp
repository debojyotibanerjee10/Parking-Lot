#include<bits/stdc++.h>
using namespace std;


class vehicle{

    protected:

        string licensePlate;
        string color;

    public:

        vehicle(string licensePlate,string color){
            this->licensePlate=licensePlate;
            this->color=color;
        }

        string LicensePlate(){
            return this->licensePlate;
        }

        string Color(){
            return this->color;
        }

        
        virtual void display(){
            cout<<"Vehicle License Plate "<<licensePlate<<" and vehicle Color "<<color<<endl;
        }


};

class car:public vehicle{

    public:
        car(string lp,string c):vehicle(lp,c){}

        void display() override{
            cout<<"Car License Plate "<<licensePlate<<" and Car Color "<<color<<endl;
        }

};


class bike:public vehicle{

    public:
        bike(string lp,string c):vehicle(lp,c){}

        void display() override{
            cout<<"Bike License Plate "<<licensePlate<<" and Bike Color "<<color<<endl;
        }

};


class ParkingLot{

    public:
        unordered_map<int,string>mp;

        ParkingLot(int n){
            for(int i=1;i<=n;i++)
                mp[i]="";
        }

        bool parkvehicle(string str){
                for(auto i:mp){
                    if(i.second==""){
                        mp[i.first]=str;
                        return true;
                    }
                }
                return false;
        }

        bool removevehicle(string str){
                for(auto i:mp){
                    if(i.second==str){
                        mp[i.first]="";
                        return true;
                    }
                }
                return false;
        }

        void showlot(){
            for(auto i:mp){
                if(i.second!=""){
                    cout<<"Vehicle Plate number "<<i.second<<" Parket at spot "<<i.first<<endl;
                }
            }
        }

        int searchvehicle(string str){
            for(auto i:mp){
                if(i.second==str){
                    return i.first;
                }
            }
            return -1;
        }

};


int main(){

    ParkingLot P(10);

    while(1){
        cout<<"Enter 1 for parking vehicle"<<endl<<"Enter 2 for removing vehicle"<<endl<<"Enter 3 to search a vehicle"<<endl<<"Enter 4 to show the Parking Lot"<<endl;
        int n;
        cin>>n;
        if(n==1){
            cout<<"Enter 1 for car and 2 for Bike"<<endl;
            int a;
            cin>>a;
            if(a==1){
                cout<<"Enter cars number plate and color"<<endl;
                string lp="",c="";
                cin>>lp>>c;
                if(P.parkvehicle(lp)){
                    cout<<"Car Parked"<<endl;
                    continue;
                }
                else{
                    cout<<"Parking Lot Full"<<endl;
                    continue;
                }
            }
            else{
                cout<<"Enter Bike number plate and color"<<endl;
                string lp="",c="";
                cin>>lp>>c;
                if(P.parkvehicle(lp)){
                    cout<<"Bike Parked"<<endl;
                    continue;
                }
                else{
                    cout<<"Parking Lot Full"<<endl;
                    continue;
                }
            }
        }
        else if(n==2){
            cout<<"Enter vehicle Plate number"<<endl;
            string lp;
            cin>>lp;
            if(P.removevehicle(lp)){
                cout<<"Vehile Removed"<<endl;
                continue;
            }
            else{
                cout<<"Vehcile Not Found"<<endl;
                continue;
            }
        }
        else if(n==3){
            string str="";
            cout<<"Enter vehicle Plate number"<<endl;
            cin>>str;
            int number=P.searchvehicle(str);
            if(number!=-1){
                cout<<"Vehcile Parked at spot "<<number<<endl;
                continue;
            }
            else{
                cout<<"Vehicle Not Found"<<endl;
                continue;
            }
        }
        else{
            P.showlot();
            continue;
        }
}
return 0;
}