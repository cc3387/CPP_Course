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
