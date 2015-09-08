#include<fstream>
#include<string>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<iostream>

// This is the function templates that will be used for the calculations of the portfolios, it includes:
// 1. Read_Calculate class - This class reads and perform the operation to intake information from minute stocks data
// 2. Markowitz class - This class performs the Markowitz theorem operations, which provide the optimal weights for each stock
// 3. Normal distribution simulations within the class of risk management

/******************************************************************************************************/

class Read_Calculate{

protected:
	  double mean;
	  double *mean_ir;
	  double *mean_cp;
	  double var;
	  double std;
	  double *std_ir;
	  double *std_cp;
	  double max;
	  double *min_var_weights;
	  double *max_sharpe_weights;
	  double sharpe_ratio;
	  
	  //Define the two pointers that can be used publicly by other classes
	  double *close_price;
	  double *index_return;
	  double **cov_var_mat;
	  double **inverse_cov_var_mat;
	  double **correlation_mat;
	  double **port_mean_arr;
public:
	  void Read_Lines(char*, int);
	  //Out Results, determining the open of file first
	  void Calculate_Return(int, int, int);
	  double* getcloseprice();
	  double* getindexreturn();
	  
	  //Initializing talbes
	  void init_tables(int,int,int,int); //Function to initialize tables that will be used for calculations
	  
	  //Statistics calculations
	  double mean_i_r(int,int,char*,int);
	  double mean_c_p(int,int,char*,int);
	  double std_i_r(double,int,int,int);
	  double var_i_r(double,int,int);
	  double std_c_p(double,int,int,int);
	  double var_c_p(double,int,int);

	  //Data information
	  double max_drawdown(int,int);
	  double find_max(int,int);
	  double find_min(int,int);
	  char* return_vol(double);
	  //~Read_Calculate();
	  
	  //Output
	  void Out_Results(int, char*, char*[], char*[], int, double*, double*, double*, double*, double[], double[], double[]);

};

//Class Markowitz extension from Read_Calculate
class Markowitz : public Read_Calculate{
	
public:

	Markowitz(); //Default Constructor

	//Setting mean portfolio values for portfolio
	void set_mean_port_arr(int, int, int);
	void set_cov_var_matrix(int, int, int);
	void set_corr_matrix(int, int, int);
	void set_inverse_cov_var_mat(int, int);
	void find_min_var_weights(int,int);
	void find_opt_weights(int,int,double);
	void set_sharpe_ratio_final();

	//Output all the results
	void Out_Mean_Return(char*, char*[],int,int,int);
	void Out_cov_var_mat(char*, int, int);
	void Out_corr_mat(char*, int, int);
	void Out_inverse_cov_var_mat(char*, int, int);
	void Out_min_var_weights(char*, char*[], int,int);
	void Out_opt_port_weights(char*, char*[], int,int);
	void Dis_opt_port_weights(char*[], int,int);
	double check_sharpe_opt_port_weights(int,int,int);
	void Dis_final_weights_sharpe(char*[], double, int,int);
	
	//Get informations
	double get_var();
	double get_mean();
	double get_std();
	double get_sharpe();
	~Markowitz();
};

//Out of sample testing
class Back_test : public Read_Calculate{

private:

	double mean_return_opt;
	double std_return_opt;

public:

	Back_test(); //Back_test Default constructors

	//Setting mean portfolio values for portfolio
	void set_mean_port_arr(int, int, int);
	void set_cov_var_matrix(int, int, int);
	void set_corr_matrix(int, int, int);
	void set_inverse_cov_var_mat(int, int);
	
	//Function that calculates out of sample results
	void Calc_OS_Sharpe(double[], int);
	
	//Output all the results
	void Out_cov_var_mat(char*, int, int);
	
	//Get information, Sharpe and optimal mean portfolio value
	double get_sharpe();
	double get_mean_opt();
	double get_std_opt();

	//Destructor
	~Back_test();
};

class Risk_Management : public Read_Calculate{

double pi;
double *sim_arr;

public:
	
	//The following functions generate the random variables that will be applied into the stochastic process

	double uniform_random(); //Generate uniform random numbers
	double normal_random(); //Generate normal random numbers
	double normal_pdf(); //Generate normal pdf numbers
	double normal_cdf(); //Generate normal cdf numbers

	//The following section will perform the simulations
	void simulation(double mean, double std, int no_sim);
	void merge(int arr[], int l, int m, int r);
	void mergeSort(int arr[], int l, int r);

	//Destructor
	~Risk_Management();
};