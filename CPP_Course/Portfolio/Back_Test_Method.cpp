#include "Read.h"

/****************************************************BackTest Class inheritance definition*******************************************/

//Back_Test Default constructors
Back_test::Back_test(){
std::cout << "This is Back_test Default Constructor ..." << std::endl;
}

//Set Methods from Back_test - Set the arrays with mean return portfolios
void Back_test :: set_mean_port_arr(int start_stock, int size, int port_size){
	for(int i = 0; i < size - 1; i++){
	port_mean_arr[i][port_size - start_stock] = index_return[i];
	}
}

//Set the matrix with covariance and variance matrix
void Back_test :: set_cov_var_matrix(int stock_id, int time_size, int stock_start){
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
void Back_test :: set_inverse_cov_var_mat(int no_of_stocks_start, int no_of_stocks_end){

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
void Back_test :: set_corr_matrix(int stock_id, int time_size, int stock_start){
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

void Back_test :: Calc_OS_Sharpe(double weights[], int stock){

	double Exp_Portfolio = 0;
	double Port_std[stock];
	double Port_std_final = 0;
	double Out_Sample_Sharpe;


	/*Initializing the portfolio standard deviation*/
	for(int i=0; i < stock; i++){
	Port_std[i] = 0;
	};


	for(int i=0; i < stock; i++){
	//std::cout<<mean_ir[i]<<std::endl;
	Exp_Portfolio += weights[i] * mean_ir[i];
	}
	
	//std::cout<<Exp_Portfolio<<std::endl;

    for(int i=0; i < stock; i++){
	   for(int j=0; j < stock; j++){
	   double temp = 0;
	   temp = weights[j] * cov_var_mat[j][i];
	   Port_std[i] += temp;
	   };
    };
	
	for(int i=0; i < stock; i++){
	Port_std_final += Port_std[i]*weights[i];
	};
	
	mean_return_opt = Exp_Portfolio;
	std_return_opt = Port_std_final;

	sharpe_ratio = Exp_Portfolio/Port_std_final;

	/*Out_Sample_Sharpe = Exp_Portfolio / Port_std_final;*/
	std::cout<<" " << std::endl;
	std::cout<<"The Back Test Sharpe Ratio is: " << std::endl;
	std::cout<<sharpe_ratio<<std::endl;
	//std::cout<<Exp_Portfolio<<std::endl;
	//std::cout<<Port_std_final<<std::endl;
	/*Delete cov_var_matrix to free memories*/
	delete[] *cov_var_mat;

}

void Back_test  :: Out_cov_var_mat(char* a, int stock_number, int stock_start){

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

//Get Information

double Back_test :: get_sharpe(){
return sharpe_ratio;
}

double Back_test :: get_mean_opt(){
return mean_return_opt;
}

double Back_test :: get_std_opt(){
return std_return_opt;
}


Back_test::~Back_test(){
std::cout << "Initiating BackTest Destructor ... " << std::endl;
delete[] close_price;
delete[] index_return;
delete[] *port_mean_arr;
delete[] *correlation_mat;
delete[] *inverse_cov_var_mat;
delete[] mean_ir;
delete[] mean_cp;
delete[] std_ir;
delete[] std_cp;
delete[] min_var_weights;
delete[] max_sharpe_weights;
}