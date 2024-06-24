#include "ArrayView.hpp"

int main(int argc, const char * argv[]) {
    int data[] = {1,2,3,5,12,5};
    ArrayView<int> viewer(data, 6);
    auto newViewer = viewer.subArray(1, 4);
    std::cout<<newViewer<<std::endl;
}
