#ifndef ETL_h
#define ETL_h 
#include <iostream> 
#include <fstream> 
#include <eigen3/Eigen/Dense> // I wonder what is going on here 
// this is an C++ library for linear algebra
// it will be useful when we pulling of matrices
// note:download the gcc compiler
class ETL
{
   // this where I will put the data set, and the name. 
   std::string  dataset; 

   // the limiter, is useful to answer the question: 
   // what should seperate our columns a coma, or semi-colon
   std::string delimiter;  

   //this bollean statement will determine the state of 
   // the Header. 
    bool Header; 


    public: 
    // here in Public, there will be an the constructor 
    // arguments 

      ETL(std::srting data, std::string bool head) : 
      dataset(data), delimeter(separater),  header(head)
      {}
  std::vector<std::vector<std::string>> readSV();
  Eingen::MatrixXd CSVtoEigen(std::vector<std::vector<std::string>> datase, int rows, int cols)

  Eigen::MatrixXd Normalize(Eigen::MatrixXd data ); 
  auto Mean(Eigen::MatrixXd  data  ) -> decltype(data.colwise().mean() ); 
  auto Std(Eigen::MatrixXd data) -> decltype(data.array().square().colwise().sum()) / (data.rows()-1)).sqrt();
std::tuple<Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd> ETL::TrainTestSplit(Eigen::MatrixXd data, 
      float train_size); 

}; 

#endif 

// these are compiler statements