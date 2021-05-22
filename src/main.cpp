#include "tutorial.h"
#include <cmath>
#include <matplot/matplot.h>

using namespace std;
using namespace cv;
using namespace matplot;




int main(int argc, char *argv[]){

//    TutoLib::histogram_tutorial();
//    TutoLib::image_reader_tutorial();
//    TutoLib::image_writer_tutorial(true);
    TutoLib::low_pass_filter_tutorial(true);
    
    return 0;
}
