#include "ETL/ETL.h"

#include <iostream> 
#include <string> 

#include <eigen3/Eigen/Dense> 

#include <boost/algorithm/string.hpp> 

//never forget the most important 
// Eigen/dense this is what makes the ai go. 

#include <vector> 


int main( int argc, char *argv[]){
    
    ETL etl(argv[1], argv[2], argv[3]);


    std::vector<std::vector<std::string>> 
    data = etl.readCSV();

   //now let's define the amount of data: rowas and columns for the pc 

   int rows = dataset.size(); 
   int cols = dataset[0].size(); 
   
   Eigen::MatrixXd >> datMat = etl.CSVtoEigen(dataset, rows, cols); 
   Eigen::MatrixXd norm = etl.Normalize(dataMat); 
  // this is to test the code   Eigen::MatrixXd << dataMat << std::endl; 

    /* this is only for testing  = std::cout << dataMat << std::endl;  */


    return EXIT_SUCCESS;    

}


