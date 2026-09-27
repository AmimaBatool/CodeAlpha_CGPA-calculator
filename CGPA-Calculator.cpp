// CGPA Calculator 

#include<iostream>
#include<vector>
using namespace std;

class subject
{
    public:
        string subject_name;
        int credits;
        float Grade;
        
        //constructor
        subject(string name, int c, float g)
        {
            subject_name = name;
            credits = c;
            Grade = g;
        }
};

class student
{
    public:
        string name;
        int current_semester;
        vector<subject> subjects;

        //constructor
        student(string n, int sem)
        {
            name = n;
            current_semester= sem;
        }

        //function to add subject
        void add_subject(string sub_name, int c, float g)
        {
            subject s(sub_name, c, g);
            subjects.push_back(s); //pusing in vector
        }

        //function to calculate total credits
        float total_credit()
        {
            float total_credits = 0;
            for(const subject & s: subjects)
            {
                total_credits += s.credits;
            }
            return total_credits;
        }

        //function to calculate total grade points
        float total_grades()
        {
            float total_grade = 0;
            for(const subject & s: subjects)
            {
                total_grade += s.Grade * s.credits;
            }
            return total_grade;
        }

        //function to calculate  current semester GPA
        float calculate_GPA()
        {
            float total_credits = total_credit();
            float total_grade = total_grades();

            return (total_credits > 0) ? (total_grade / total_credits) : 0;
        }

        //function to calculate CGPA
        float calculate_CGPA()
        {
            float total_CGPA = 0;
            
            for(int i=1; i<current_semester; i++)
            {
                float pre_sem_GPA= 0;
                cout<<"Enter GPA of Semester "<<i<<": ";
                cin>>pre_sem_GPA;
                total_CGPA += pre_sem_GPA;
            }
            
            total_CGPA += calculate_GPA();
            int total_semesters = current_semester;
            return total_CGPA/total_semesters;
        }

        //function to display Course details
        void result()
        {
            cout<<"==========--RESULT--==========="<<endl;

            cout << "Student Name: " << name << endl;
            cout<< "Current Semester: "<< current_semester<<endl;

            cout<<endl;
            cout<<"-----Course Details-----"<<endl;

            cout << "Subjects: " << endl;
            for(const subject & s: subjects)
            {
                cout << "Course Name: " << s.subject_name <<endl;
                cout<< "Credit Hours: " << s.credits <<endl;
                cout<< "Grade: " << s.Grade << endl;
                cout<<"Grade Points: " << s.Grade * s.credits << endl;
                cout<<endl;
            }

            cout<<"-----Current Semester GPA Details-----"<<endl;
            cout<<"Total Credits: " << total_credit() << endl;
            cout<<"Total Grade Points: " << total_grades() << endl;
            cout<<"Semester GPA: " << calculate_GPA() << endl;
            cout<<endl;

            cout<<"-------CGPA Details-------"<<endl;
            float cgpa = calculate_CGPA();
            cout << "CGPA of " << name << " is: " << cgpa;
            cout<<endl;
        }

};


int main()
{
    cout<<endl;
    cout<<"---==---CGPA Calculator---==---"<<endl;

    string student_name;
    int current_semester;
    int name_cou;

    cout<<"Enter name of Student: ";
    getline(cin , student_name);

    cout<<"Enter current semester: ";
    cin>>current_semester;

    cout<<"Enter number of Courses: ";
    cin>>name_cou;
    cout<<endl;

    student student(student_name, current_semester);

    for(int i=0; i<name_cou; i++)
    {
        string subject_name;
        int credits;
        float Grade;

        cout<<"Course "<<i+1<<": "<<endl;
        cout<<"Enter name of course "<<i+1<<": ";
        cin.ignore();              // To ignore the newline character left in the input buffer
        getline(cin , subject_name);

        cout<<"Enter credits for course '"<<subject_name<<"': ";
        cin>>credits;

        cout<<"Enter Grade for course '"<<subject_name<<"': ";
        cin>>Grade;
        cout<<endl;

        student.add_subject(subject_name, credits, Grade);
    }

    cout<<endl;
    student.result();
    cout<<endl;
    
}