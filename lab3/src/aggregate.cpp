class enrollment{
    public:
        enrollment(student x){
            AllData.push_back({x.StudentId, x.CourseNumber, x.InstructorId, x.TermId, x.SectoionId, x.Grade});
        }
        void update(student x){
                for(int i=0;i<AllData.size();i++){
                    if(AllData[i].StudentId==x.StudentId){
                        AllData[i].Grade=x.Grade;
                        AllData[i].CourseNumber=x.CourseNumber;
                        AllData[i].InstructorId=x.InstructorId;
                        AllData[i].SectoionId=x.SectoionId;
                    }
                }
        }
};

bool my_cmp(const Instructor& a, const Instructor& b)
{
    // smallest comes first
    return a.Ins_ID< b.Ins_ID;
}


bool my_cmp1(const Course& a, const Course& b)
{
    // smallest comes first
    return a.Course_Number< b.Course_Number;
}


void pass_rate(){
    outputfile<<"pass rate per instructor : "<<endl;
    outputfile<<"Instructor     Pass rate"<<endl;
    set<string>::iterator it;
    for(it=INS.begin();it!=INS.end();it++){
        string x=*it;
        outputfile<<x;
        outputfile.width(12);
        outputfile<<" ";
        int total=0;
        int fail=0;
        int i;
        for(i=0;i<AllData.size();i++){
            if(AllData[i].InstructorId==x){
               if(AllData[i].Grade=="F")
               {
               	fail++;
               }
               else{
                total++;}
            }
        }
       	cout<<total<<" "<<fail<<" "<<endl;
        outputfile<<((total-fail)/((total)*1.0)*100)<<endl;
        //outputfile<<<<endl;
    }
    outputfile<<endl;
}
void Fall_rate(){
    outputfile<<"Fall pass rate: "<<endl;
    outputfile<<"Course      Pass rate"<<endl;
    set<string>::iterator it;
    for(it=CRS.begin();it!=CRS.end();it++){
        string x=*it;
        outputfile<<x<<" ";
        int fall=0;
        int fall_fail=0;
        for(int i=0;i<AllData.size();i++){
            for(int j=0;j<Fall_size;j++){
                if((AllData[i].CourseNumber==x)&&(AllData[i].TermId==Fall[j])){
                    if(AllData[i].Grade=="F"){
                        fall_fail++;
                    }
                    fall++;
                }
            }
        }
        outputfile.width(14);
        outputfile<<((fall-fall_fail)*1.0/fall)*100<<endl;
    }
    outputfile<<endl;
}
void Spring_rate(){
    outputfile<<"Spring pass rate: "<<endl;
    outputfile<<"Course      Pass rate"<<endl;
    set<string>::iterator it;
    for(it=CRS.begin();it!=CRS.end();it++){
        string x=*it;
        outputfile<<x<<" ";
        int spring=0;
        int spring_fail=0;
        for(int i=0;i<AllData.size();i++){
            for(int j=0;j<Spring_size;j++){
                if((AllData[i].CourseNumber==x)&&(AllData[i].TermId==Spring[j])){
                    if(AllData[i].Grade=="F"){
                        spring_fail++;
                    }
                    spring++;
                }
            }
        }
        outputfile.width(14);
        if(spring_fail==0){
            outputfile<<0<<endl;
        }
        else{
            outputfile<<((spring-spring_fail)*1.0/spring)*100<<endl;
        }

    }
    outputfile<<endl;
}
void W_rate(){
    outputfile<<"W rate per instructor : "<<endl;
    outputfile<<"Instructor    C-1115    C-3115    C-3130"<<endl;
    set<string>::iterator it,it2;
    for(it=INS.begin();it!=INS.end();it++){
        outputfile<<*it<<" ";
        outputfile.width(10);
        outputfile<<" ";
        map<int,vector<int> >m;
        it2=CRS.begin();
        for(it2=CRS.begin();it2!=CRS.end();it2++){
            //outputfile<<*it2<<" ";
            string xx=*it2;
            vector<int>vv(2);
            vv[0]=0;
            vv[1]=0;
            for(int i=0;i<AllData.size();i++){
                if(AllData[i].InstructorId==*it&&AllData[i].CourseNumber==*it2){
                    if(AllData[i].Grade=="W"){
                        vv[0]++;
                    }
                    vv[1]++;
                }
            }
            //outputfile.width(6);
            if(vv[0]==0){
                outputfile<<"0.00000"<<'\t';
            }
            else{
                outputfile<<std::fixed<<std::setprecision(5)<<(((vv[0]*1.0)/vv[1])*100)<<'\t';
                //outputfile<<<<" ";
            }

        }
        outputfile<<endl;
    }
    outputfile<<endl;
}

void Course_summarization(){
    int n=AllData.size();
    for(int i=0;i<n;i++){
        All_Course.push_back(Course());
        All_Course[i].Course_Number=AllData[i].CourseNumber;
        All_Course[i].student_Id=AllData[i].StudentId;
        All_Course[i].SectionCode=AllData[i].SectoionId;
        All_Course[i].Term=AllData[i].TermId;
        CRS.insert(AllData[i].CourseNumber);
    }
}

void Instructor_summarization(){
    int n=AllData.size();
    for(int i=0;i<n;i++){
        All_Instructor.push_back(Instructor());
        All_Instructor[i].Ins_ID=AllData[i].InstructorId;
        All_Instructor[i].Ins_Course=AllData[i].CourseNumber;
        All_Instructor[i].Ins_Term=AllData[i].TermId;
        INS.insert(AllData[i].InstructorId);
    }
}
