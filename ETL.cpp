///heren I will focuse on building my memeber functions 

// and will not forget to include the header files 
//inside the implemention file. 
#include "ETL.h"


#include <vector> 
#include <stdlib.h> 
#include <cmath>
#include <boost/algorithm/string.hpp> 
// each of these libraries add some pre-cooked functions 
// for to use, as food for action. Thank you


//alright. the first memeber function will parse 
// the cc file for me line by line. (And do some vector of string)

std::vector<std::vector<std::string>> ETL::readSV(); 
{  // I will use to ifstream to tell the pc to open 
// the file containing the dataset. 
    std::ifstream file(dataset); 
  // now I will need to open vector  to start  
  //my  data  and where I will return
  // the data                             // named 
     std::vector<std::vector<std::string>> dataString;

   // now we need to ask the computer to iterate 
   // through each line of data, and splite thr content
   // wiht the limiter I wrote as constructor in ETL.h page
  
  while (getLine(file,line)){
      std::vector<std::string> vec; 
      boost::algorithm::split(vec,line,boost::is_any_of(delimeter)); 
      dataString.push_back(vec);
  
  }


  // now i'll tell this computer to close this file 
    file.close(); 

  // now to return my vector " vectors of strings"
    return dataStrings; 
} 

// this is like using panda to create a data frame, in python. 
// Let's tell the pc about our rows and columns 
Eingen::MatrixXD ETL::CSVtoEigen(std::vector<std::vector<std::string>> datase, int rows, int cols)
{
    // I will use the header flag to tell the computer that if we are in the true state 
    // remove right now. 
    if (header==true)
    {
      rows  = rows -1;  // Pc please use only raw numebres, no manipulation 
      
    }

    // now I will create an empty matrix 
    Eigen::MatrixXd  mat(cols, rows); 

    // to fill it I'll use a for loop 

    for( int i =0; i < rows; i++){
      for( int j = 0; j < cols; i++){
        // let's post in the numbers we'll get from strings 
        mat(j,i) = atof(dataset[i][j].c_str()); // here I need to transfor string nums into floats .c_str() is the lib func for that. 

      }

      return mat.transpose(); // Now tell the pc to return the transpose of the matrix.Transpose? mathematical concept 
    }
}    

  // now I need a fucntion that will train, test and split
  // we will return 4 diffrent Eingen Matrices, while wrapping them into Tuples 

  std::tuple<Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd> ETL::TrainTestSplit(Eigen::MatrixXd data, 
      float train_size){
        // for tran data e will calculate 
        // how many rows we'll have for train data, and for testing data
        int rows = data.rows();
        int train_rows = rows(train_size * rows); 
        int test_rows = rows - train_rows; 

        Eigen::MatrixXd train = data.topRows(train_rows); 

        Eigen::MatrixXd X_train = train.leftCols(); 
        Eigen::MatrixXd y_train = train.rightCols(1);

        Eigen::MatrixXd test = data.bottomRows (test_rows); 
        
        Eigen::MatrixXd X_test = test.leftCols(data.cols()-1); 
        Eigen::MatrixXd y_test = test.rightCols(1); 

        return std::make_tuple(X_train, y_train, X_test, y_test);
      }





  auto ETL::Mean(Eigen::MatrixXd  data  ) -> decltype(data.colwise().mean() ){ // this fucntion will calculate the mean of every column
    return data.colwise().mean(); 
  }  
   

auto ETL::Std(Eigen::MatrixXd data ) -> decltypereturn (data.array().square().colwise().sum()) / (data.rows()-1).sqrt(); {
  return (data.array().square().colwise().sum()) / (data.rows()-1).sqrt(); 
}
  // now let's normalize 
 Eigen::MatrixXd ETL::Normalize(Eigen::MatrixXd data ) {
   // first calculate the mean
   auto mean = Mean(data); 
   // now calc a variable called scaled data which is the diffrence between each observation by 
   // its mean  
   Eigen::MatrixXd scaled_data = data.rowwise() - mean; 
   // now let's use that scaled data as an input to the standard deviation 
   auto std = Std(scaled_data ); 

   // Apply the normalization 

   Eigen::MatrixXd norm = scaled_data.array().rowwise / std; 

     return norm;  
    } 
