void file_input(string file){
    ifstream fin (file.c_str());
    if(fin.fail()){
        cout<<"Unable to open "<<file<<endl;//if the file is not opened then this loop will be executed
        return ;
    }
    vector<string>result;
    string line;
    getline(fin,line);
    while(fin.good()){
        result.clear();
        getline(fin,line);//taking input a row of the file
        int n=line.size();
        //cout<<line<<endl;
        string tmstring;
        for(int i=0;i<n;i++){
            if(line[i]==','){                //split the row into column
                result.push_back(tmstring);   //and storing them in vector
                //cout<<tmstring<<" ";
                tmstring="";
            }
            else{
                tmstring+=line[i];
            }
        }
        result.push_back(tmstring);
        AllData.push_back(student());
        AllData[cnt].StudentId=result[0];
        AllData[cnt].CourseNumber=result[1];
        AllData[cnt].InstructorId=result[2];
        AllData[cnt].TermId=result[3];
        AllData[cnt].SectoionId=result[4];
        AllData[cnt].Grade=result[5];
        cnt++;
    }
    fin.close();
}

void write_function(int n){
	static int file_no;
	if(n==1){
		outputfile.open("lab3/output/output1.txt");
		outputfile<<"File no: "<<++file_no<<endl;
		Instructor_summarization();
		Course_summarization();
		pass_rate();
		W_rate();
		Fall_rate();
		Spring_rate();
		outputfile.close();
	}
    else if(n==2){
		outputfile.open("lab3/output/output2.txt");
		outputfile<<"File no: "<<++file_no<<endl;
		Instructor_summarization();
		Course_summarization();
		pass_rate();
		W_rate();
		Fall_rate();
		Spring_rate();
		outputfile.close();
	}
	else if(n==3){
		outputfile.open("lab3/output/output3.txt");
		outputfile<<"File no: "<<++file_no<<endl;
		Instructor_summarization();
		Course_summarization();
		pass_rate();
		W_rate();
		Fall_rate();
		Spring_rate();
		outputfile.close();
	}
}
