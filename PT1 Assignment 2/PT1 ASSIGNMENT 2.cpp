//Leader:EII ZHI HUI A24CS0246
//Member:ZAHIN IRDINA BINTI MOHD ZABIDY A24CS0216
//DATE OF COMPLEMENT:8 JANUARY 2025

#include <iostream>
#include<fstream>
#include <iomanip>
using namespace std;


//Task 1
const int SIZE = 50;
string name[SIZE]; //n
char grades[SIZE]; //g
int assgmnt[SIZE], //a
    le[SIZE], //b
    midterm[SIZE], //c
    final[SIZE], //d
    tot_marks[SIZE]; //e

ifstream f1;

//Task 2
int readInput(string n[],int a[],int b[],int c[],int d[]){
    
    f1.open("inputfile.txt");

        if(!f1.is_open()){
    cout << "ERROR!! Input file could not be opened\n";
         exit(1);
        }

    int numstudent=0;

    while(!f1.eof()){
         
        getline(f1,n[numstudent],',');//to read the name until comma
        
        f1>>a[numstudent]>>b[numstudent]>>c[numstudent]>>d[numstudent];//copy data from f1 to variables
        f1.ignore();//to avoid skip a line when read the data from f1
        numstudent++;
    }

    f1.close();
    return numstudent;

}

//Task 3
void calculateTotalAndGrade(string [], int [], int [], int [], int [], int [], char [], int);

void calculateTotalAndGrade(string n[], int a[], int b[], int c[], int d[], int e[], char g[], int num) { //num is total number of students
    int total;

    for(int i=0; i<num; i++) {
        total = a[i] + b[i] + c[i] + d[i];
        e[i] = total;

        if((e[i]>84)&&(e[i]<=100)) {
            g[i] = 'A';
        }
        else if((e[i]>69)&&(e[i]<85)) {
            g[i] = 'B';
        }
        else if((e[i]>54)&&(e[i]<70)) {
            g[i] = 'C';
        }
        else if((e[i]>39)&&(e[i]<55)) {
            g[i] = 'D';
        }
        else {
            g[i] = 'F';
        }

    } 
    
}

//Task 4
void displayOutput(string n[],int a[],int b[],int c[],int d[],int e[],char g[],int num){


    cout<<"Student Name        Assignments   Lab Exercises   Midterm Tests   Final Exams   Total Marks   Grade "<<endl;
    for(int i=0;i<100;i++){
        cout<<"-";
    }
    cout<<endl;
    

    for(int i=0;i<num;i++) 
        cout << setw(20)<<left<<n[i]
             << setw(7)  << right << fixed << setprecision(1) << static_cast<double>(a[i])
             << setw(16) << right << fixed << setprecision(1) << static_cast<double>(b[i])
             << setw(16) << right << fixed << setprecision(1) << static_cast<double>(c[i])
             << setw(15) << right << fixed << setprecision(1) << static_cast<double>(d[i])
             << setw(13) << right << fixed << setprecision(1) << static_cast<double>(e[i])
             <<setw(10)<<g[i]<<endl;
            
    }

//Task 5
void displayAnalysis(string n[],int e[],char g[],int num);

void displayAnalysis(string n[],int e[],char g[],int num) {
    int highest = -99999, lowest = 99999;
    string highest_name, lowest_name;
    double sum=0, percentage;

    for(int j=0; j<num; j++) {
         sum += e[j];
    }
    cout << "Class Average Marks: " << fixed << setprecision(2) << sum/num << endl;
  
    for(int i=0; i<num; i++) {  //to find highest mark
        if(e[i] > highest) {
            highest = e[i];
            highest_name = n[i];
        }
    }
    cout << "Highest Score: " << highest_name << " (" << fixed << setprecision(2) << static_cast<double>(highest) << ")" << endl;

    for(int k=1; k<num; k++) {  //to find lowest mark
        if(e[k] < lowest) {
            lowest = e[k];
            lowest_name = n[k];
        }
    }
    cout << "Lowest Score: " << lowest_name << " (" << fixed << setprecision(2) << static_cast<double>(lowest) << ")" << endl;

    cout << "\nGrade Histogram" << endl;

    int aa=0,bb=0,cc=0,dd=0,ee=0,ff=0;//to calculate number of students in each grades
    
    for(int v=0;v<num;v++){
        if(g[v]=='A')//to caculate person who get A
            aa++;
        if(g[v]=='B')//to caculate person who get B
            bb++;       
        if(g[v]=='C')//to caculate person who get C
            cc++;
        if(g[v]=='D')//to caculate person who get D
            dd++;               
        if(g[v]=='E')//to caculate person who get E
            ee++;
        if(g[v]=='F')//to caculate person who get F
            ff++;
    
        
    }

        cout<<"A:";
    for (int q=0;q<aa;q++)
        cout<<"++";
        
        cout << " (" << aa/static_cast<float>(num)*100.00 << "%)" <<endl ;//to calculate percentage that who get grade A from all students

        cout<<"B:";
    for (int q=0;q<bb;q++)
        cout<<"++";
        
        cout << " (" << bb/static_cast<float>(num)*100.00 << "%)" <<endl ;//to calculate percentage that who get grade B from all students

        cout<<"C:";
    for (int q=0;q<cc;q++)
        cout<<"++";
        
        cout << " (" << cc/static_cast<float>(num)*100.00 << "%)" <<endl ;//to calculate percentage that who get grade C from all students

        cout<<"D:";
    for (int q=0;q<dd;q++)
        cout<<"++";
        
        cout << " (" << dd/static_cast<float>(num)*100.00 << "%)" <<endl ;//to calculate percentage that who get grade E from all students

        cout<<"F:";
    for (int q=0;q<ff;q++)
        cout<<"++";
        
        cout << " (" << ff/static_cast<float>(num)*100.00 << "%)" <<endl ;//to calculate percentage that who get grade F from all students


}


//Task 6
int main() {

    const int SIZE = 50;
    string name[SIZE]; //n
    char grades[SIZE]; //g
    int assgmnt[SIZE], //a
    le[SIZE], //b
    midterm[SIZE], //c
    final[SIZE], //d
    tot_marks[SIZE]; //e

    int number,i;
    char m;

    //read input data
    number=readInput(name,assgmnt, le, midterm, final);

    for (i=0;i<number;i++){
    //calculate total marks and grade
    calculateTotalAndGrade(name, assgmnt, le, midterm, final, tot_marks, grades, number);

    }

    //to display individual student information
    displayOutput(name,assgmnt,le, midterm, final, tot_marks, grades,number);
    cout<<endl;

    //to display student performance analysis
    displayAnalysis(name,tot_marks,grades,number);

    system("pause");
    return 0;
}