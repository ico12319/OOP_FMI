#include "SortedStringPool.h"


int main(int argc, const char * argv[]) {
    SortedStringPool pool;
    pool.addString("Kisenko");
    pool.addString("Bisho");
    pool.addString("Bisho");
    pool.addString("Bisho");
    pool.addString("Kaba");
    pool.addString("Jecho Cenov");
    pool.addString("Arbanasenko");
    pool.addString("Arbanasenko");
    pool.addString("Jecho Cenov");
    pool.printCollection();
}
