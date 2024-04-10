#include <iostream>
#include <fstream>
#include <cstring>

struct Subject{
   char* name;
   size_t numGrades;
   int* grades;


   Subject(){
     name = nullptr;
     numGrades = 0;
     grades = nullptr;
   }

   Subject(const char* name,size_t numGrades,const int* grades){
    this->name = new char[std::strlen(name)+1];
    std::strcpy(this->name,name);
    this->numGrades = numGrades;
    this->grades = new int[numGrades];
    for(size_t i = 0; i<numGrades; i++){
        this->grades[i] = grades[i];
    }

   }

};

struct Dnevnik{
   Subject* subjects;
   size_t numSubjects;


   Dnevnik(){
    subjects = nullptr;
    numSubjects = 0;
   }

   Dnevnik(const Subject* subjects,size_t numSubjects){
    this->subjects = new Subject[numSubjects];
    for(size_t i = 0;i<numSubjects;i++){
        this->subjects[i] = subjects[i];
    }
    this->numSubjects = numSubjects;
   }

   ~Dnevnik(){
    delete[]subjects;
   }
};


void saveSubjectToBinaryFile(std::ofstream& ofs,const Subject& sub){
    int nameLen = std::strlen(sub.name);
    ofs.write((const char*) &nameLen,sizeof(nameLen));
    ofs.write(sub.name,nameLen+1);

    int gradesCount = sub.numGrades;
    ofs.write((const char*) &gradesCount, sizeof(int));
    ofs.write((const char*) sub.grades,sizeof(int) * gradesCount);
}

void saveSubjectsArrToBinaryFile(std::ofstream& ofs,const Subject* subjects,size_t size){
    ofs.write((const char*) &size,sizeof(size));

    for(int i = 0;i<size;i++){
        saveSubjectToBinaryFile(ofs,subjects[i]);
    }
}


Subject readFromBinaryFile(std::ifstream& ifs){
    Subject sub;

    int nameLen;
    ifs.read((char*) &nameLen,sizeof(nameLen));

    sub.name = new char[nameLen+1];
    ifs.read(sub.name,nameLen+1);

    int gradesCount;
    ifs.read((char*)&gradesCount,sizeof(gradesCount));
    sub.numGrades = gradesCount;

    sub.grades = new int[gradesCount];
    ifs.read((char*) sub.grades,sizeof(int) * gradesCount);

    return sub;
}

void readArrFromBinaryFile(std::ifstream& ifs, Subject*& subjects, size_t& size){
    ifs.read((char*) &size,sizeof(size));

    subjects = new Subject[size];

    for(int i = 0;i<size;i++){
        subjects[i] = readFromBinaryFile(ifs);
    }
}


void printStudent(const Subject& sub){
    std::cout<<sub.name<<std::endl;
    for(int i = 0;i<sub.numGrades;i++){
        std::cout<<sub.grades[i]<<" ";
    }
    std::cout<<std::endl;
}


void printDiary(const Dnevnik& diary,size_t size){
    for(int i = 0;i<size;i++){
        std::cout<<"Subject name: " << diary.subjects[i].name << std::endl;;
        int gradesCount = diary.subjects[i].numGrades;
        for(int j = 0;j<gradesCount;j++){
            std::cout<<diary.subjects[i].grades[j]<<" ";
        }
        std::cout<<std::endl;
    }
}


double getAvarageGradeFromSubject(const Subject& sub,int gradesCount){
    double sum = 0;

    for(int i = 0;i<gradesCount;i++){
        sum += sub.grades[i];
    }

    return sum/gradesCount;
}

double getAverageFromDiary(const Dnevnik& diary,size_t size){
    
    double sum = 0;
    for(int i = 0;i<size;i++){
       sum+=getAvarageGradeFromSubject(diary.subjects[i],diary.subjects[i].numGrades);
    }

    return round(sum/size);
}

int main(){


   std::ifstream ifs("Toq put ako ne stane nz231.dat",std::ios::binary);

   size_t size;
   Subject* subjects;
   readArrFromBinaryFile(ifs,subjects,size);




   Dnevnik diary(subjects,size);

   printDiary(diary,size);

   int average = getAverageFromDiary(diary,size);

   std::cout<< "The average grade form the Diary is: " << average<<std::endl;


 
   delete[]subjects;

}
