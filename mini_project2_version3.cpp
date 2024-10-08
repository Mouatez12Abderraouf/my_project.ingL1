
#include <iostream>
#include <string>
using namespace std;
    const int sizeStudent=100;
    const int model=4;
    const int Max_Class=25;

    #if defined (_WIN32)
            #define clear_screen() system ("cls")
            
    #else
            #define clear_screen() system ("clear")
    #endif
                 
   
   struct date_of_birth
   {
        int Day,year;
        string month;
   };
   
   struct Student_Record
   {
         
        string firstName,lastName,address,studentClass,contactInfo;
        date_of_birth Date;
        int ID;
        float average=-1.0;


   };
   int add(Student_Record student[],int &nb_student,Student_Record newStudent)
   {
        student[nb_student].ID=newStudent.ID;
        student[nb_student].contactInfo=newStudent.contactInfo;
        student[nb_student].firstName=newStudent.firstName;
        student[nb_student].lastName=newStudent.lastName;
        student[nb_student].address=newStudent.address;
        student[nb_student].studentClass=newStudent.studentClass;
        student[nb_student].Date.Day=newStudent.Date.Day;
        student[nb_student].Date.month=newStudent.Date.month;
        student[nb_student].Date.year=newStudent.Date.year;
        
        nb_student++;
        

            return nb_student;
   }
   int search(Student_Record student[],int nb_student,string FN,string LN){

        for(int i=0;i<nb_student;i++){
            if(student[i].firstName==FN && student[i].lastName==LN){
                return i;
            }
        }
        return -1;
   }

    float fillMatrix(float Mark[][model],int indx){
        
        int result=0;
                for(int j=0;j<model;j++){
                    switch (j){
                        case 0:
                        do{
                        cout<<"Enter the grade of physics :";
                        cin>>Mark[indx][j];
                                 result+=Mark[indx][j];
                            if(Mark[indx][j]<0 || Mark[indx][j]>20)
                                cout<<"Enter number in range 0-20 \n";
                        }while (Mark[indx][j]<0 || Mark[indx][j]>20);
                              
                        break;
                        case 1:
                        do{
                        cout<<"Enter the grade of math :";
                        cin>>Mark[indx][j];
                                 result+=Mark[indx][j];
                            if(Mark[indx][j]<0 || Mark[indx][j]>20)
                                cout<<"Enter number in range 0-20 \n";
                        }while (Mark[indx][j]<0 || Mark[indx][j]>20);
                                 
                        break;
                        case 2:
                        do{
                        cout<<"Enter the grade of arabic :";
                        cin>>Mark[indx][j];
                                 result+=Mark[indx][j];
                            if(Mark[indx][j]<0 || Mark[indx][j]>20)
                                cout<<"Enter number in range 0-20 \n";
                        }while (Mark[indx][j]<0 || Mark[indx][j]>20);

                        break;
                        case 3:
                        do{
                        cout<<"Enter the grade of english :";
                        cin>>Mark[indx][j];
                                 result+=Mark[indx][j];
                            if(Mark[indx][j]<0 || Mark[indx][j]>20)
                                cout<<"Enter number in range 0-20 \n";
                            
                        }while (Mark[indx][j]<0 || Mark[indx][j]>20);

                        break;
                        
                            
                    
                }
    }
                
                return (float)result/4;
        }
    int delete_student(Student_Record student[],int &number,float Mark[][model],int indx){
            for(int i=indx;i<number;i++){
                student[indx].ID=student[indx+1].ID;
                student[indx].contactInfo=student[indx+1].contactInfo;
                student[indx].firstName=student[indx+1].firstName;
                student[indx].lastName=student[indx+1].lastName;
                student[indx].address=student[indx+1].address;
                student[indx].studentClass=student[indx+1].studentClass;
                student[indx].Date.Day=student[indx+1].Date.Day;
                student[indx].Date.month=student[indx+1].Date.month;
                student[indx].Date.year=student[indx+1].Date.year;
                student[indx].average=student[indx+1].average;

            }

                for(int i=indx;i<number;i++){
                    for(int j=0;j<model;j++){
                        Mark[i][j]=Mark[i+1][j];
                    }
                }
                
                number--;
                return number;


    }

    void display_by_Cariteria(Student_Record record[],int number,float avg,string first,string last,int id){
        bool b=false;
            for(int i=0;i<number;i++){
                if(avg==record[i].average || first==record[i].firstName && last==record[i].lastName  || id ==record[i].ID){
                        cout<<"************* student *************\n";
                        cout<<"the first name :"<<record[i].firstName<<endl;
                        cout<<"the last name :"<<record[i].lastName<<endl;
                        cout<<"the class :"<<record[i].studentClass<<endl;                        
                        cout<<"ID :"<<record[i].ID<<endl;
                        cout<<"contact informaation :"<<record[i].contactInfo<<endl;                        
                        b=true;
                }
            }
            if(b==false)
                cout<<"they not exisite\n";
    }
    void display_Report_card(Student_Record students[],int indx,float Mark_Matrix[][model]){
            
                        cout<<"the first name :"<<students[indx].firstName<<endl;
                        cout<<"the last name :"<<students[indx].lastName<<endl;
                        cout<<"the date of birth :"<<students[indx].Date.Day<<" "<<students[indx].Date.month<<" "<<students[indx].Date.year<<endl;
                        cout<<"the address :"<<students[indx].address<<endl;
                        cout<<"ID :"<<students[indx].ID<<endl;
                        cout<<"the class :"<<students[indx].studentClass<<endl;
                        cout<<"the contact :"<<students[indx].contactInfo<<endl;
                        if(students[indx].average==-1)
                        {
                            cout<<"the student's points were not recorded\n";
                        }
                        else
                        {
                        for (int j=0;j<model;j++){
                        switch (j){
                            case 0:
                            cout<<"the grade of physics is :"<<Mark_Matrix[indx][0]<<endl;
                            break;


                            case 1:
                            cout<<"the grade of math is :"<<Mark_Matrix[indx][1]<<endl;   
                            break;


                            case 2:
                            cout<<"the grade of arabic is :"<<Mark_Matrix[indx][2]<<endl;    
                            break;


                            case 3:
                            cout<< "the grade of english is :"<<Mark_Matrix[indx][3]<<endl;         
                            break;
                        }
                        }
                            
                
            
                            cout<<"the average :"<<students[indx].average<<endl;
                            if(students[indx].average<10){
                                cout<<"the note : Fail\n";
                            }
                            else{
                                if(students[indx].average<13){
                                    cout<<"the note : Pass\n";
                                }
                                else{
                                    if(students[indx].average<15){
                                        cout<<"the note : Good\n";
                                    }
                                    else{
                                        cout<<"the note : Excellent\n";
                                    }
                                }
                            }
                            }
    }
    void display_Record(Student_Record students[],int indx){
        
            cout<<"************* student *************\n";
        cout<<"the first name :"<<students[indx].firstName<<endl;
        cout<<"the last name :"<<students[indx].lastName<<endl;
        cout<<"the date of birth :"<<students[indx].Date.Day<<" "<<students[indx].Date.month<<" "<<students[indx].Date.year<<endl;
        cout<<"the address :"<<students[indx].address<<endl;
        cout<<"ID :"<<students[indx].ID<<endl;
        cout<<"the class :"<<students[indx].studentClass<<endl;
        cout<<"the contact :"<<students[indx].contactInfo<<endl;
        cout<<"the average :"<<students[indx].average<<endl;

    
    }
    bool IsFull(string nameClass,Student_Record student[],int number){
        int n_class=0;
        for(int i=0;i<number;i++){
            if(student[i].studentClass==nameClass){
                n_class++;
            }
        }
        if(n_class==Max_Class){
            return true;
        }
        return false;
    }
int main()
{
    Student_Record students[sizeStudent],new_student;
    float Mark_Matrix[sizeStudent][model];
    int number_of_student=0,indx_matrix=0;
    bool on_off=true;
    int choice;
    cout<<"*************** welcome ***************\n";
        while (on_off==true)
        {
            
                    
            
                cout<<"please enter your choice :\n";
                cout<<"(1) * Basic management operations\n";
                cout<<"(2) * Display a report card of a specific student\n";
                cout<<"(3) * Exit the program\n";
                do{
                    cin>>choice;
                        clear_screen();//clear screen
                    if(choice!=1 && choice!=2 && choice!=3)
                        cout<<"the option does not exist\nplease make another selection :\n";
                }while (choice!=1 && choice!=2 && choice!=3);
                
                
                if(choice==1){
                    cout<<"please enter your choice :\n";
                    cout<<"(1) * Add a new student record\n";
                    cout<<"(2) *  Display a student record\n";
                    cout<<"(3) * Delete a student record\n";
                    cout<<"(4) * Fill in the marks of a student\n";
                    cout<<"(5) * Display the result (s) of a search based on any information\n";

                        do{
                            cin>>choice;
                                clear_screen();
                            if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
                            cout<<"the option does not exist\nplease make another selection :\n";
                        }while (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5);
                                if(choice==1){
                                    cout<<"Enter the first name of student :";
                                    // cin>>new_student.firstName;
                                    cin.ignore(1,'\n');
                                    getline(cin,new_student.firstName);
                                    cout<<"Enter the last name of student :";
                                     //cin>>new_student.lastName;
                                     //cin.ignore(1,'\n');
                                     getline(cin,new_student.lastName);
                                    do{
                                    cout<<"Enter his day of birth :";
                                    cin>>new_student.Date.Day;
                                    if(new_student.Date.Day>31)
                                        cout<<"The error : This day does not exist.\n";
                                    }while (new_student.Date.Day>31) ;                            
                
                                    cout<<"Enter his month of birth :";
                                    cin>>new_student.Date.month;
                                    
                                    cout<<"Enter his year of birth :";
                                    do{
                                    cin>>new_student.Date.year;
                                    if(new_student.Date.year<2003 || new_student.Date.year>2006)
                                        cout<<"Reconfirm the year of birth :\n";
                                    }while (new_student.Date.year<2003 || new_student.Date.year>2006);
                                    
                                    
                                    cout<<"Enter the address of student :";
                                    // cin>>new_student.address;
                                    cin.ignore(1,'\n');
                                    getline(cin,new_student.address);
                                    cout<<"Enter the class of student :";
                                    //cin>>new_student.studentClass;
                                    //cin.ignore(1,'\n');
                                    getline(cin,new_student.studentClass);
                                    bool sizeClass;
                                    sizeClass=IsFull(new_student.studentClass,students,number_of_student);
                                    while(sizeClass){                                       
                                        cout<<"the class is full.\nplease enter the new class:";
                                        //cin>>new_student.studentClass;
                                        //cin.ignore(1,'\n');
                                        getline(cin,new_student.studentClass);
                                        sizeClass=IsFull(new_student.studentClass,students,number_of_student);
                                    }    

                                    cout<<"Enter the contact of student :";
                                    cin>>new_student.contactInfo;
                                    cout<<"Enter the ID :";
                                    cin>>new_student.ID;
                                    int number=add(students,number_of_student,new_student);                            
                                        clear_screen();
                                            cout<<"\aThe student has been added\n";
                                            
                                            
                                            
                                            
                                               
                                            

                                }
                                else{
                                        if(choice==5){
                                            
                                            cout<<"what is a information :\n[1] full name\n[2] id\n[3] avrage"<<endl;
                                            cin>>choice;
                                            float avg;
                                            string first,last;
                                            int id;
                                            clear_screen();
                                            if(choice==1){
                                                
                                                cout<<"Enter the first name of student :";
                                                // cin>>new_student.firstName;
                                                cin.ignore(1,'\n');
                                                getline(cin,first);
                                                cout<<"Enter the last name of student :";
                                                //cin>>new_student.lastName;
                                                 //cin.ignore(1,'\n');
                                                 getline(cin,last);
                                                
                                            }
                                            else if(choice==2){
                                                
                                                cout<<"enter the ID :";
                                                cin>>id;
                                            }
                                            else{
                                             
                                             cout<<"Enter the avrage of student :";
                                             cin>>avg;
                                            }
                                            clear_screen();
                                             display_by_Cariteria(students,number_of_student,avg,first,last,id); 

                                        }
                                        else{
                                            if(choice==2){
                                                string first ,last ;
                                                cout<<"enter the first name :";
                                                cin.ignore(1,'\n');
                                                getline(cin,first);
                                                cout<<"enter the last name :";
                                                //cin.ignore(1,'\n');
                                                getline(cin,last);
                                                clear_screen();
                                                int i=search(students,number_of_student,first,last);
                                                if(i<0)
                                                    cout<<"this not existed.\n";
                                                else
                                                    display_Record(students,i);

                                            }
                                            else{
                                                if(choice==3){
                                                    string firstName,lastName;
                                                    cout<<"Enter the first name :";
                                                    //cin>>firstName;
                                                    cin.ignore(1,'\n');
                                                    getline(cin,firstName);
                                                    cout<<"Enter the last name :";
                                                    //cin>>lastName;
                                                    //cin.ignore(1,'\n');
                                                    getline(cin,lastName);
                                                        clear_screen();
                                                    int indx=search(students,number_of_student,firstName,lastName);
                                                        if(indx<0)
                                                            cout<<"they are not exist\n";
                                                        else
                                                            int number=delete_student(students,number_of_student,Mark_Matrix,indx);
                                                                cout<<"Successfully deleted\n";
                                                                   
                                                
                                                
                                                
                                                   
                                                     


                                                }
                                                else{
                                                    if(choice==4){
                                                        string firstName,lastName;
                                                        cout<<"Enter the first name :";
                                                        //cin>>firstName;
                                                        cin.ignore(1,'\n');
                                                        getline(cin,firstName);
                                                        cout<<"Enter the last name :";
                                                        //cin>>lastName;
                                                        //cin.ignore(1,'\n');
                                                        getline(cin,lastName);
                                                            clear_screen();
                                                        int indx=search(students,number_of_student,firstName,lastName);
                                                        if(indx<0)
                                                            cout<<"they are not exist\n";
                                                        else{
                                                                if(students[indx].average!=-1){
                                                                    cout<<"the student points have already been entered\n";
                                                                }

                                                                else{
                                                                    float avg=fillMatrix(Mark_Matrix,indx);
                                                                    cout<<"The points have been entered\n";
                                                                    students[indx].average=avg;
                                                                }
                                                                
                                                                
                                                                
                                                                   
                                                                

                                                            }
                                                        
                                                    }
                                                }
                                            }
                                        }
                                    }

                
                    }
                    else{
                        if(choice==2){
                        string firstName,lastName;
                        cout<<"Enter the first name :";
                        //cin>>firstName;
                        cin.ignore(1,'\n');
                        getline(cin,firstName);
                        cout<<"Enter the last name :";
                        //cin>>lastName;
                        //cin.ignore(1,'\n');
                        getline(cin,lastName);
                            clear_screen();
                        int indx=search(students,number_of_student,firstName,lastName);
                        
                            if(indx<0)
                                cout<<"they are not exist\n";
                            else
                                display_Report_card(students,indx,Mark_Matrix);
                                    
                                    
                                    
                                    
                                       
                                         

                    }
                    else{
                        on_off=false;
                        cout<<"*************** Goodbye ***************\n";
                    }
                    }
        }
    
    return 0;
}
