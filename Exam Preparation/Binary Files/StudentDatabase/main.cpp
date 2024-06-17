#include "StudentDatabase.h"

int main(int argc, const char * argv[]) {

    Student student1("Ivan", 16, 0);
    Student student2("Kisan", 11,1);
    Student student3("Chiko", 8, 0);
    
    
    StudentDatabase dataBase;
    std::ifstream ifs("BinaryExam.dat",std::ios::binary);
    dataBase.readStudentsFromDatabase(ifs);
    dataBase.printDatabase();
}
