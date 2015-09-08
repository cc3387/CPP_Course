#include "Read.h"

/******************************************* Method Class with Read_Calculate **********************************************************/

void Read_Calculate::Read_Lines(char* a, int MAX_SIZE){
	 
	 char* filename;
	 filename = a;
	 std::string number;
	 std::string::size_type sz;
	 double number_1;
	 std::ifstream price(filename);
	 int i = 0;

	 //Assigning new close_price

	 close_price = new double[MAX_SIZE];

	 if(price.is_open()){
		while(price.good()){
		getline(price,number);
		number_1 = atof(number.c_str());
		close_price[i] = number_1;
		//std::cout<<close_price[i]<<std::endl;
		i++;
		}
     }
	 else{
	 std::cout << "Unable to open file" << std::endl;
	 }

	 price.close();
}


void Read_Calculate::Calculate_Return(int MAX_SIZE, int port_size, int stock_start){
	 index_return = new double[MAX_SIZE-1];
	 for(int i = 1; i < MAX_SIZE; i++){
	 index_return[i-1] = log(close_price[i] / close_price[i-1]);
	 //std::cout<<index_return[i-1]<<std::endl;
	 }
}

//Determine the mean for index return and closing price
double Read_Calculate :: mean_i_r(int MAX_SIZE, int start, char* sym, int stocks_id){

	mean = 0;
	//Determine a close price that will take the close price values

	for(int i=start; i < MAX_SIZE-1; i++){
	mean += index_return[i];
	}
	mean /= ((MAX_SIZE-start)-1);
	mean_ir[stocks_id] = mean;
	std::cout<<"The mean of return of " << sym << " is: "<< mean << std::endl;	
	return mean;
}

double Read_Calculate :: mean_c_p(int MAX_SIZE, int start, char* sym, int stocks_id){

	mean = 0;
	//Determine a close price that will take the close price values

	for(int i=start; i < MAX_SIZE; i++){
	mean += close_price[i];
	}
	mean /= (MAX_SIZE-start);
	mean_cp[stocks_id] = mean;
	std::cout<<"The mean of closed price of " << sym << " is: "<< mean << std::endl;	
	return mean;
}

//Standard Deviation of Closed Price
double Read_Calculate :: std_c_p(double a, int start, int MAX_SIZE, int stocks_id){
	std = 0;
	for(int i = start; i < MAX_SIZE; i++){
	std += (close_price[i] - a)*(close_price[i] - a);
	}
	std /= ((MAX_SIZE-start) - 1);
	std = sqrt(std);
	std_cp[stocks_id] = std;
	return std;
}

//Variance of Closed Price
double Read_Calculate :: var_c_p(double a, int start, int MAX_SIZE){
	var = 0;
	for(int i = start; i < MAX_SIZE; i++){
	var += (close_price[i] - a)*(close_price[i] - a);
	}
	var /= ((MAX_SIZE-start) - 1);
	return var;
}


//Standard Deviation of return
double Read_Calculate :: std_i_r(double a, int start, int MAX_SIZE, int stocks_id){
	std = 0;
	for(int i = start; i < MAX_SIZE; i++){
	std += (index_return[i] - a)*(index_return[i] - a);
	}
	std /= ((MAX_SIZE-start) - 1);
	std = sqrt(std);
	std_ir[stocks_id] = std;
	return std;
}

//Variance of return
double Read_Calculate :: var_i_r(double a, int start, int MAX_SIZE){
	var = 0;
	for(int i = start; i < MAX_SIZE; i++){
	var += (index_return[i] - a)*(index_return[i] - a);
	}
	var /= ((MAX_SIZE-start) - 1);
	return var;
}


double* Read_Calculate::getcloseprice(){
return close_price;
}

double* Read_Calculate::getindexreturn(){
return index_return;
}

//Calculating Max Drawdown for the class
double Read_Calculate::max_drawdown(int b, int start){

	double max = 0;
	double Max_DD = 0;
	double DD[b];

	for(int i=start; i<b; i++){
	DD[i] = 0;	
	}
	
	for(int i=start; i<b; i++){
	
		if(close_price[i] > max){
		max = close_price[i];
		}
		
		DD[i] = 100.0 * (max - close_price[i]) / max;

		if(DD[i] > Max_DD){
		Max_DD = DD[i];
		}
	}

	return Max_DD;
}


double Read_Calculate::find_max(int b, int start){
max = 0;
	for(int i = start; i < b; i++){
		if(close_price[i] > max){
		max = close_price[i];
		}
	}
return max;
}

double Read_Calculate::find_min(int b, int start){
double min = close_price[0];
	for(int i = start; i < b; i++){
		if(close_price[i] < min){
		min = close_price[i];
		}
	}
return min;
}

void Read_Calculate::Out_Results(int stock, char* a, char* c[], char* d[], int b, double w[], double x[], double y[], double z[], double k[], double maximum[], double minimum[]){
std::ofstream outfile(a);
outfile<<"Symbol"<<","<<"Close Price Mean" << "," << "Close Price Std" <<"," << "Return Mean" << "," << "Return Std"<<"," << "Volatile?" << "," << "Max_DD" << "," << "Max Price" << "," << "Min Price" << std::endl;
for(int i = stock; i < b; i++){
	outfile<< c[i] <<"," << w[i]<<","<<x[i]<<","<<y[i]<< "," <<z[i]<< "," << d[i] << "," << k[i] << "," << maximum[i] << "," << minimum[i] << std::endl;
};
outfile.close();
}

char* Read_Calculate::return_vol(double vol){
char* volatility;
if(vol > 0.001){
volatility = "volatile";
}
else{
volatility = "stable";
}
return volatility;
}

//Initializing the two tables that are going to be used in the future
void Read_Calculate :: init_tables(int start, int end, int no_of_stocks_start, int no_of_stocks_end){

	//Initializing the port_mean_arr with all the collected prices
	int stocks_total = no_of_stocks_end - no_of_stocks_start;

	port_mean_arr = new double*[end - start];
	
	for(int i = 0; i < (end-start); i++){
    port_mean_arr[i] = new double[stocks_total];
	}

	for(int i = 0; i < (end-start); i++){
		for(int j = 0; j < stocks_total; j++){
        port_mean_arr[i][j] = 0;
		}
	}

	//Initializing the covariance matrix 
	cov_var_mat = new double*[stocks_total];
	
	for(int i = 0; i < stocks_total; i++){
    cov_var_mat[i] = new double[stocks_total];
	}

	for(int i = 0; i < stocks_total; i++){
		for(int j = 0; j < stocks_total; j++){
        cov_var_mat[i][j] = 0;
		}
	}

	//Initializing correlation matrix 
	correlation_mat = new double*[stocks_total];
	
	for(int i = 0; i < stocks_total; i++){
    correlation_mat[i] = new double[stocks_total];
	}

	for(int i = 0; i < stocks_total; i++){
		for(int j = 0; j < stocks_total; j++){
        correlation_mat[i][j] = 0;
		}
	}

	//Initializing correlation matrix 
	inverse_cov_var_mat = new double*[stocks_total];
	
	for(int i = 0; i < stocks_total; i++){
    inverse_cov_var_mat[i] = new double[stocks_total];
	}

	for(int i = 0; i < stocks_total; i++){
		for(int j = 0; j < stocks_total; j++){
        inverse_cov_var_mat[i][j] = 0;
		}
	}


	//Initializing mean, var and std array
	mean_ir = new double[stocks_total];
	for(int i = 0; i < stocks_total; i++){
    mean_ir[i] = 0;
	}

	mean_cp = new double[stocks_total];
	for(int i = 0; i < stocks_total; i++){
    mean_cp[i] = 0;
	}

	std_ir = new double[stocks_total];
	for(int i = 0; i < stocks_total; i++){
    std_ir[i] = 0;
	}
	
	std_cp = new double[stocks_total];
	for(int i = 0; i < stocks_total; i++){
    std_cp[i] = 0;
	}

	min_var_weights = new double[stocks_total];
	for(int i = 0; i < stocks_total; i++){
    min_var_weights[i] = 0;
	}

	max_sharpe_weights = new double[stocks_total];
	for(int i = 0; i < stocks_total; i++){
    max_sharpe_weights[i] = 0;
	}

}

//Destructors initialization for Read and Calculate
/*Read_Calculate::~Read_Calculate(){
std::cout << "Initiating Destructor ... " << std::endl;
delete[] close_price;
delete[] index_return;
delete[] *port_mean_arr;
delete[] *cov_var_mat;
delete[] *correlation_mat;
}*/


/****************************************************Markowitz Class inheritance definition*******************************************/

//Set Methods from Markowitz - Set the arrays with mean return portfolios
void Markowitz :: set_mean_port_arr(int start_stock, int size, int port_size){
	for(int i = 0; i < size - 1; i++){
	port_mean_arr[i][port_size - start_stock] = index_return[i];
	}
}

//Set the matrix with covariance and variance matrix
void Markowitz :: set_cov_var_matrix(int stock_id, int time_size, int stock_start){
	int j = 0;
	
	while(j <= (stock_id-stock_start)){
	var = 0;
	for(int i = 0; i < time_size - 1; i++){
	var += (port_mean_arr[i][stock_id - stock_start - j] - mean_ir[stock_id- stock_start - j]) * (port_mean_arr[i][stock_id-stock_start] - mean_ir[stock_id-stock_start]); 
	}
	var /= (time_size-1);
	cov_var_mat[stock_id - stock_start-j][stock_id-stock_start] = var;
	cov_var_mat[stock_id-stock_start][stock_id-stock_start-j] = var;
	j++;
	}
}

//Inverse covariance and variance matrix
void Markowitz :: set_inverse_cov_var_mat(int no_of_stocks_start, int no_of_stocks_end){

	int stocks_final = no_of_stocks_end - no_of_stocks_start;

//Initiate the echlon matrix
	double **echlon;
	echlon = new double*[stocks_final];
	
	for(int i = 0; i < stocks_final; i++){
	    echlon[i] = new double [2*stocks_final];
	}

//Filling in the echlon array with covariance matrix
	for(int i = 0; i < stocks_final; i++){
		for(int j = 0; j < stocks_final; j++){
		echlon[i][j] = cov_var_mat[i][j];
		}
	}


//Filling in the right hand side with identity matrix
	for(int i = 0; i < stocks_final; i++){
		for(int j = stocks_final; j < (2*stocks_final); j++){
		echlon[i][j] = 0; 
		}
		echlon[i][stocks_final+i] = 1;
	}


//Running inverse transformation algorithm on echlon matrix in order to obtain inversed variance covariance matrix
	for(int i = 0; i < stocks_final; i++){
	   for(int j = 0; j < stocks_final; j++){
	   echlon[i][j + stocks_final] = echlon[i][j + stocks_final] / echlon[i][i];
	   echlon[i][j] = echlon[i][j] / echlon[i][i];
	   echlon[j][i] = echlon[j][i] / echlon[i][i];
	   }
	}


//Forward Solving of the echlon (echlon matrix solving going down)
    int k = 0;
	
	while(k < stocks_final){
	for(int j = 0; j < stocks_final-(k+1); j++){
	double temp = echlon[j+k+1][k];
	for(int i = 0; i < stocks_final; i++){
	if(k>0){
	echlon[j+k][i] /= echlon[k][k];
	echlon[j+k][i+stocks_final] /= echlon[k][k];
	}
	echlon[j+(k+1)][i] = echlon[j+(k+1)][i] - (echlon[k][i] * temp); 
	echlon[j+(k+1)][i+stocks_final] = echlon[j+(k+1)][i+stocks_final] - (echlon[k][i+stocks_final] * temp); 
	}
	}
	k++;
	}


//Last Row Entry (Forward)
    for(int i = 0; i < stocks_final; i++){
	echlon[stocks_final-1][stocks_final+i] /= echlon[stocks_final-1][stocks_final-1];
	}
	echlon[stocks_final-1][stocks_final-1] /= echlon[stocks_final-1][stocks_final-1];


//Backward Calculations
		k = 0;
		double temp_2;
		while(k < stocks_final){
			for(int i=1; i < (stocks_final-k); i++){
			   temp_2 = echlon[stocks_final-1-i-k][stocks_final-1-k];
				for(int j=0; j <=stocks_final; j++){
				echlon[stocks_final-1-i-k][stocks_final-1-k+j] -= echlon[stocks_final-1-k][stocks_final-1-k+j]*temp_2;   //echlon[stocks_final-1-i-k][stocks_final-1-k];
				}
			}
		k++;
		}
		

//Final Output to inverse covariance variance matrix
	for(int i=0; i < stocks_final; i++){
		for(int j=0; j < stocks_final; j++){
		inverse_cov_var_mat[i][j] = echlon[i][stocks_final+j];
		}
	}

//Visualization Code
	/*for(int i = 0; i < stocks_final; i++){
	  for(int j = 0; j < stocks_final; j++){
		std::cout<<echlon[i][j]<<",";
		if(j == (stocks_final - 1)){
		std::cout<<std::endl;
		}
		}
	}

	std::cout<< "                     "<<std::endl;

	for(int i = 0; i < stocks_final; i++){
		for(int j = 0; j < stocks_final; j++){
		std::cout<<echlon[i][j+stocks_final]<<",";
		if(j == (stocks_final - 1)){
		std::cout<<std::endl;
		}
		}
	}*/

delete[] *echlon; //Freeing memories that are created
}


//Set correlation matrix
void Markowitz :: set_corr_matrix(int stock_id, int time_size, int stock_start){
	int j = 0;
	
	while(j <= (stock_id-stock_start)){
	var = 0;
	for(int i = 0; i < time_size - 1; i++){
	var += (port_mean_arr[i][stock_id - stock_start - j] - mean_ir[stock_id- stock_start - j]) * (port_mean_arr[i][stock_id-stock_start] - mean_ir[stock_id-stock_start]); 
	}
	var /= (time_size - 1);
	var /= (std_ir[stock_id - stock_start - j]*std_ir[stock_id - stock_start]);
	correlation_mat[stock_id - stock_start-j][stock_id-stock_start] = var;
	correlation_mat[stock_id-stock_start][stock_id-stock_start-j] = var;
	j++;
	}
}


//Find the minimum variance weights from the portfolio
void Markowitz :: find_min_var_weights(int stocks_final, int short_sell){
	 
	 double total_sum = 0;
	 double sum;

	 for(int i=0; i<stocks_final; i++){
		 sum = 0;
		 for(int j=0; j<stocks_final; j++){
		 sum += inverse_cov_var_mat[i][j];
		 }
	 min_var_weights[i] = sum;
	 if(short_sell == 1){
	 total_sum += min_var_weights[i];
	 }else{
	 if(min_var_weights[i] < 0){
	 min_var_weights[i] = 0;
	 }
	 total_sum += min_var_weights[i];
	 }
	 }
	 //Calculating the sums
	 for(int i = 0; i < stocks_final; i++){
	 min_var_weights[i] /= total_sum;
	 }
}

//Find the minimum variance weights from the portfolio
void Markowitz :: find_opt_weights(int stocks_final, int short_sell, double lambda){

	 double total_sum = 0;
	 double sum;
     double *A;
	 double *temp;
	 //Initializing temporary array with A
	 A = new double [stocks_final];
	 for(int i = 0; i < stocks_final; i++){
	 A[i] = 0;
	 }

	 //Initializing temporary array with A
	 temp = new double [stocks_final];
	 for(int i = 0; i < stocks_final; i++){
	 temp[i] = 0;
	 }

	 //Find A values
	 for(int i=0; i<stocks_final; i++){
		 sum = 0;
		 for(int j=0; j<stocks_final; j++){
		 sum += inverse_cov_var_mat[i][j] * mean_ir[j];
		 }
	 A[i] = sum;
	 if(short_sell == 1){
	 total_sum += A[i];
	 }else{
	 if(A[i] < 0){
	 A[i] = 0;
	 }
	 total_sum += A[i];
	 }
	 }
	 
	 //Find the weights for A
	 for(int i = 0; i < stocks_final; i++){
	 A[i] /= total_sum;
	 }

	 //Find B values
	 double B = 0;
	 double B_below = 0;
	 for(int i = 0; i < stocks_final; i++){
	 B += A[i] * mean_ir[i];
	 }

	 for(int i = 0; i < stocks_final; i++){
		sum = 0;
		 for(int j = 0; j < stocks_final; j++){
		 sum += cov_var_mat[j][i] * A[j]; 
		 }
	     temp[i] = sum;
	 }

	 for(int i = 0; i < stocks_final; i++){
	 B_below += temp[i] * A[i];
	 }
	 B /= B_below;
	 sharpe_ratio = B;

	 //Find Maximized Sharpe Ratio Weights
	 total_sum = 0;
	 for(int i=0; i<stocks_final; i++){
		 sum = 0;
		 for(int j=0; j<stocks_final; j++){
		 sum += (1/lambda)*inverse_cov_var_mat[i][j] * mean_ir[j]*B;
		 }
	 max_sharpe_weights[i] = sum;
	 if(short_sell == 1){
	 total_sum += max_sharpe_weights[i];
	 }else{
	 if(max_sharpe_weights[i] < 0){
	 max_sharpe_weights[i] = 0;
	 }
	 total_sum += max_sharpe_weights[i];
	 }
	 }
	 
	 //Find the weights for A
	 for(int i = 0; i < stocks_final; i++){
	 max_sharpe_weights[i] /= total_sum;
	 }

	 //Clear up the memories
	 delete[] A;
	 delete[] temp;
}


/******************** Markowitz Output Method from Markowitz ********************************/
void Markowitz  :: Out_Mean_Return(char* a, char* c[], int size, int start_stock, int no_stocks){

std::ofstream outfile(a);


    for(int j = start_stock ; j < no_stocks; j++){
	outfile << c[j] << ",";
	if(j == (no_stocks -1)){
	outfile << std::endl;
	}
	}
	
	for(int i = 0; i < size-1; i++){
	     for(int j = 0; j < (no_stocks-start_stock); j++){
		 outfile << port_mean_arr[i][j] << ",";
		 if(j == (no_stocks - start_stock - 1)){
		 outfile << std::endl;
		 }
	  }
   }

   outfile.close();
}


void Markowitz  :: Out_cov_var_mat(char* a, int stock_number, int stock_start){

std::ofstream outfile(a);

    for(int i = 0 ; i < (stock_number - stock_start); i++){
	   for(int j = 0; j < (stock_number - stock_start); j++){
	       outfile << cov_var_mat[i][j] << ",";
	       if(j == (stock_number - stock_start - 1)){
	       outfile << std::endl;
	       }
	   }
	}

outfile.close();
}

void Markowitz  :: Out_corr_mat(char* a, int stock_number, int stock_start){

std::ofstream outfile(a);

    for(int i = 0 ; i < (stock_number - stock_start); i++){
	   for(int j = 0; j < (stock_number - stock_start); j++){
	       outfile << correlation_mat[i][j] << ",";
	       if(j == (stock_number - stock_start - 1)){
	       outfile << std::endl;
	       }
	   }
	}

outfile.close();
}

void Markowitz  :: Out_inverse_cov_var_mat(char* a, int stock_number, int stock_start){

std::ofstream outfile(a);

    for(int i = 0 ; i < (stock_number - stock_start); i++){
	   for(int j = 0; j < (stock_number - stock_start); j++){
	       outfile << inverse_cov_var_mat[i][j] << ",";
	       if(j == (stock_number - stock_start - 1)){
	       outfile << std::endl;
	       }
	   }
	}

outfile.close();
}

void Markowitz  :: Out_min_var_weights(char* a, char* b[], int stock_number, int stock_start){

std::ofstream outfile(a);
outfile << "Minimum variance portfolio weights" << std::endl;
	 for(int j = 0; j < (stock_number - stock_start); j++){
	 outfile << b[j+stock_start] << "," << min_var_weights[j] << std::endl;
	 }
outfile.close();
}

void Markowitz  :: Out_opt_port_weights(char* a, char* b[], int stock_number, int stock_start){

std::ofstream outfile(a);
outfile << "Max Sharpe portfolio weights" << std::endl;
	 for(int j = 0; j < (stock_number - stock_start); j++){
	 outfile << b[j+stock_start] << "," << max_sharpe_weights[j] << std::endl;
	 }

outfile << "Maximized Sharpe Ratio is:" << std::endl;
outfile << sharpe_ratio;

outfile.close();
}


//Attribution and Collection

double Markowitz :: get_mean(){
return mean;
}

double Markowitz :: get_std(){
return std;
}


//Destructors initialization for Read and Calculate
Markowitz::~Markowitz(){
std::cout << "Initiating Destructor ... " << std::endl;
delete[] close_price;
delete[] index_return;
delete[] *port_mean_arr;
delete[] *cov_var_mat;
delete[] *correlation_mat;
}