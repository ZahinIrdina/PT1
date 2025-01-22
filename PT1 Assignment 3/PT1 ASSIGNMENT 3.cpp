#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#define N 3
using namespace std;

//task 1
struct Hub{
    string code;
    string name,location;//code is Hub code,name is Hub name,location is Hub location
    int Q1,Q2,Q3,Q4;
    float rvn,pct;//rvn is annual revenue,pct is revenue contribution percentage

};

    ifstream f1,f2,f3,f4,f5;

//task 2
void readInputfiles(Hub h[],int &count){

    f1.open("hubs.txt");
    f2.open("q1.txt");
    f3.open("q2.txt");
    f4.open("q3.txt");
    f5.open("q4.txt");

    if(!f1.is_open() || !f2.is_open() || !f3.is_open() || !f4.is_open() ||!f5.is_open()){//check f1 is exist
        cout<<"Error!File is not exist";
        system("pause");
        exit(0);
    }
   
   while(f1>>h[count].code){//read f1

   if(f2.eof() ||f3.eof() || f4.eof() || f5.eof()){
        cout<<"Error!File is not exist"<<endl;
        system("pause");
        exit(0);   
   }

    f2>>h[count].Q1;
    f3>>h[count].Q2;
    f4>>h[count].Q3;
    f5>>h[count].Q4;
        count ++;
   }


   if(!f1.eof() || !f2.eof() ||!f3.eof() ||!f4.eof() ||!f5.eof()){//check all file.txt have not extra
         cout<<"Error!File is not consistent"<<endl;
        system("pause");
        exit(0);    
   }

    f1.close();
    f2.close();
    f3.close();
    f4.close();
    f5.close();


}

//Task 3
void determineHub (Hub h[],int count) {//take the array of Hub structures


   string codes[] = {"KLS", "PNS", "JBS", "IPS", "MKS", "KKS", "KTS"};
   string names[] = {"KL Sentral", "Penang Sentral", "JB Sentral", "Ipoh Sentral", "Melaka Sentral", "KK Sentral", "Kuantan Sentral"};
   string locations[] = {"Kuala Lumpur", "Penang", "Johor Bahru", "Ipoh", "Melaka", "Kota Kinabalu", "Kuantan"};

    for (int i = 0; i < count; i++) {
        string prefix = ""; // Initialize an empty string for the prefix
        for (int j = 0; j < N; j++) { //extract the first 3 characters
            prefix += h[i].code[j];
        }
        for (int j = 0; j < count; j++) {
            if (prefix == codes[j]) {
                h[i].name = names[j];
                h[i].location = locations[j];
                break;
            }
        }
    }

}

//Task 4
void RevAnalysis(Hub h[], int count, int &q1_tot, int &q2_tot, int &q3_tot, int &q4_tot,int &grand_tot,
                 float &q1_avg, float &q2_avg, float &q3_avg, float &q4_avg, float &annual_avg,
                 float &pct_tot, float &pct_avg, int &highest, int &lowest, int &highest_i,int &lowest_i,string &highest_hub,
                 string &highest_loc, string &lowest_hub, string &lowest_loc) {

    q1_tot = q2_tot = q3_tot = q4_tot = 0; 

    for (int i = 0; i < count; i++) {
        q1_tot += h[i].Q1;
        q2_tot += h[i].Q2;
        q3_tot += h[i].Q3;
        q4_tot += h[i].Q4;

        h[i].rvn = h[i].Q1 + h[i].Q2 + h[i].Q3 + h[i].Q4;
        grand_tot += h[i].rvn; 
    }
 
    q1_avg = static_cast<float>(q1_tot) / static_cast<float>(count);
    q2_avg = static_cast<float>(q2_tot) / static_cast<float>(count);
    q3_avg = static_cast<float>(q3_tot) / static_cast<float>(count);
    q4_avg = static_cast<float>(q4_tot) / static_cast<float>(count);
    annual_avg = static_cast<float>(grand_tot) / count; 

    //calculate percentage
    for(int p=0; p<count; p++) {
    h[p].pct = (h[p].rvn / grand_tot) * 100;
    pct_tot += h[p].pct;
    }
    pct_avg =pct_tot/count; //average percentage


    for (int j = 0; j < count; j++) { 
        if (h[j].rvn > highest) {
            highest = h[j].rvn;
            highest_hub = h[j].name;
            highest_loc = h[j].location;
            
        }
    }

    lowest = h[0].rvn; // Initialize lowest with the first hub's revenue
    lowest_hub = h[0].name;
    lowest_loc = h[0].location;

    for (int k = 1; k < count; k++) { 
        if (h[k].rvn < lowest) {
            lowest = h[k].rvn;
            lowest_hub = h[k].name;
            lowest_loc = h[k].location;
            
        }
    }
}
    
//Task 5
int main(){

    Hub h[1000];
    int a=0;//number of hubs

    cout<<fixed<<setprecision(2);
    cout << left << setw(12) << "HUB CODE" 
         << setw(20) << "HUB NAME" 
         << setw(15) << "LOCATION"
         << right << setw(7) << "Q1" 
         << right<< setw(11) << "Q2" 
         << right<<setw(11) << "Q3" 
         << right<<setw(11) << "Q4"
         <<right<< setw(15) << "ANNUAL REV" 
         <<right<< setw(16) << "CONTRIBUTION" << endl;

    for(int i=0;i<118;i++){
        cout<<"-";
    }
    cout<<endl;
    int grand_tot = 0, //initialize grand total
        q1_tot = 0, //initialize q1 total
        q2_tot = 0, //initialize q2 total
        q3_tot = 0, //initialize q3 total
        q4_tot = 0, //initialize q4 total
        highest = -99999, 
        lowest = 99999,
        highest_i,
        lowest_i;

    string highest_hub, highest_loc, lowest_hub, lowest_loc; // highest/lowest_hub is name. highest/lowest_loc is location.
    float q1_avg, q2_avg, q3_avg, q4_avg, annual_avg=0.0, pct_avg=0.0, pct_tot=0;

    readInputfiles(h,a);//read data from input files

    determineHub(h,a);//map to the hub name and hub location

    RevAnalysis (h,a,q1_tot,q2_tot,q3_tot,q4_tot,grand_tot,q1_avg,q2_avg,q3_avg,q4_avg,
                  annual_avg,pct_tot,pct_avg,highest,lowest,highest_i,lowest_i,highest_hub, highest_loc, lowest_hub, lowest_loc);
    

    for (int i = 0; i < a; i++) {
        cout << left << setw(12) << h[i].code 
             << setw(20) << h[i].name 
             << setw(15) << h[i].location
             << right << setw(9) << h[i].Q1 
             << setw(11) << h[i].Q2 
             << setw(11) << h[i].Q3 << setw(11) << h[i].Q4
             << setw(11) << static_cast<int>(h[i].rvn) 
             << setw(14) << fixed << setprecision(2) << h[i].pct << "%" << endl;
    }
    

    
    for(int i=0;i<118;i++){
        cout<<"-";
    }
    cout<<endl;

    cout<<fixed<<setprecision(2);
    cout<<right<<setw(31)<<"AVERAGE "<<right<<setw(25)<<q1_avg<<right<<setw(11)<<q2_avg<<right<<setw(11)<<q3_avg<<right<<setw(11)<<q4_avg<<right<<setw(11)<<annual_avg<<right<<setw(14)<<pct_avg<<"%"<<endl;
    for(int i=0;i<118;i++){
        cout<<"-";
    }
    cout<<endl<<endl;

    cout<<"OVERALL REPORT"<<endl;
    cout<<"=============="<<endl;
    cout<<"GRAND TOTAL REVENUE    ="<<grand_tot<<endl;
    cout<<"HIGHEST ANNUAL REVENUE ="<<highest<<" "<<"("<<highest_hub<<","<<highest_loc<<")"<<endl;
    cout<<"LOWEST ANNUAL REVENUE  ="<<lowest<<" "<<"("<<lowest_hub<<","<<lowest_loc<<")"<<endl;
    int highest_quarter = q1_tot; // Initialize with q1_tot

    // Compare with other quarters
    if (q2_tot > highest_quarter) {
        highest_quarter= q2_tot;
    }

    if (q3_tot > highest_quarter) {
        highest_quarter = q3_tot;
    }

    if (q4_tot > highest_quarter) {
        highest_quarter = q4_tot;
    }

    int highest_q;

    if (highest_quarter == q1_tot) {
        highest_q = 1;

    } else if (highest_quarter == q2_tot) {
        highest_q = 2;
    } else if (highest_quarter == q3_tot) {
        highest_q = 3;
    } else {
        highest_q = 4;
    }

    // lowest
    int lowest_quarter = q1_tot;
    if (q2_tot < lowest_quarter) {
        lowest_quarter= q2_tot;
    }

    if (q3_tot < lowest_quarter) {
        lowest_quarter = q3_tot;
    }

    if (q4_tot < lowest_quarter) {
        lowest_quarter = q4_tot;
    }

    int lowest_q;

    if (lowest_quarter == q1_tot) {
        lowest_q = 1;

    } else if (lowest_quarter == q2_tot) {
        lowest_q = 2;
    } else if (lowest_quarter == q3_tot) {
        lowest_q = 3;
    } else {
        lowest_q = 4;
    }

    cout<<"QUARTER WITH HIGHEST TOTAL REVENUE: Quarter "<<highest_q<<" "<<"("<<highest_quarter<<")"<<endl;
    cout<<"QUARTER WITH LOWEST TOTAL REVENUE : Quarter "<<lowest_q<<" "<<"("<<lowest_quarter<<")"<<endl;
    
    
    system("pause");
    return 0;

}