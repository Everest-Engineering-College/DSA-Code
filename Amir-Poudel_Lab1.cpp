#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
//#include "limits"

using namespace std;

class Result{
protected:
    string name[5],line,tempstring,division[5];
    float crn[5],programming[5],math[5],physics[5];
    int i=0;
public:
    //Read Data from file
    void DataRead(){
        ifstream MarksFile("marks.txt");//Read file
        if(!MarksFile.is_open()){ //check file open or not
            cout<<"File failed to open"<<endl;
//            return 0;
        }



        while (getline(MarksFile,line)){ //read one line in file & store in variables
            stringstream ss(line);
            getline(ss,tempstring,',');
            crn[i] = stoi(tempstring); //converting string value to int value and then store it
            getline(ss,name[i],',');
            getline(ss,tempstring,',');
            programming[i]= stoi(tempstring);
            getline(ss,tempstring,',');
            math[i] = stoi(tempstring);
            getline(ss,tempstring,',');
            physics[i] = stoi(tempstring);
            i++;



        }
        MarksFile.close();

    }

    void FailEachSubject(){ //check the how many student fails in each subject

        int programming_count=0;
        int math_count=0;
        int physics_count=0;

        for(int i=0;i<5;i++){
            if(programming[i]<45){
                programming_count++;
            }
            if(math[i]<45){
                math_count++;
            }
            if(physics[i]<45){
                physics_count++;
            }
        }
        if(programming_count>0){
            cout<<programming_count<<" Students failed in programming"<<endl;
        }
        if(math_count>0){
            cout<<math_count<<" Students failed in Math"<<endl;
        }
        if(physics_count){
            cout<<physics_count<<" Students failed in Physics"<<endl;
        }

    }
//Calculate Division
    void CalculateDivision(){
        float total[5],percentage[5];
        for(int i=0;i<5;i++){
            total[i]=programming[i]+math[i]+physics[i];
            percentage[i]=total[i]/3;

        }

//        string division[5];
        for (int i=0;i<5;i++){          //Divided into Division on the basis of percentage && check if anyone fail in one subject
            if(percentage[i]<45){
                if(programming[i]>=45&&math[i]>=45&&physics[i]>=45){
                    division[i]="Fail";
                }
                else division[i]="Fail";
            }
            else if(percentage[i]>=45&&percentage[i]<50){
                if(programming[i]>=45&&math[i]>=45&&physics[i]>=45){
                    division[i]="Pass";
                }else division[i]="Fail";

            }
            else if(percentage[i]>=50&&percentage[i]<75){
                if(programming[i]>=45&&math[i]>=45&&physics[i]>=45){
                    division[i]="Second Division";
                }else division[i]="Fail";

            }
            else if(percentage[i]>=75&&percentage[i]<90){
                if(programming[i]>=45&&math[i]>=45&&physics[i]>=45){
                    division[i]="First Division";
                }else division[i]="Fail";

            }
            else{
                if(programming[i]>=45&&math[i]>=45&&physics[i]>=45){
                    division[i]="Distinction";
                }else division[i]="Fail";

            }


        }



    }

    //Write Data in a text file
    void SaveData(){
        fstream ResultFile;
        ResultFile.open("result.txt",ios::out);//define writing mode
        if(ResultFile.is_open()){
            for(int i=0;i<5;i++){
                ResultFile <<crn[i]<<","<<name[i]<<","<<division[i]<<endl;
            }

        }


    }

    //return the divison to the user

    string DivisionCheck(){

        int InputNumber;

        cout<<"Enter The CRN Number : ";
        //Receive user input
        while (!(cin>>InputNumber)){

            {
                cout<<"Wrong Input !!! Please Enter the CRN Numbers: ";
                cin.clear();//clear the value
                cin.ignore(123,'\n'); //ignore previously enter wrong input


            }
        }

        for(int i=0;i<5;i++){
            if(crn[i]==InputNumber){
                return division[i];
            }
        }
        return "CRN Number Not Found.";
    }

    //Display the Result
    void DisplayResult(){
        cout<<"CRN"<<"  "<<"Name"<<"    "<<"       "<<"Division "<<endl;
        cout<<"------------------------------------------"<<endl;
        for(int i=0;i<5;i++){
            cout<<crn[i]<<"  "<<name[i]<<"    "<<division[i]<<endl;
        }

    }

};



int main(){



    Result result;
    result.DataRead();
    result.FailEachSubject();
    result.CalculateDivision();
    result.SaveData();
    result.DisplayResult();
    string division=result.DivisionCheck();
    cout<<endl<<division;








    return 0;
}
