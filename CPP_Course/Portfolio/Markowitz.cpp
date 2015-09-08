#include "Read.h"

//Input list to pass by reference so that the symbols and name can be passed on
void input_names(int j, char* &a, char* &b, int &z, int &k){

/************************************************US Stocks**********************************************************/
if(j == 0){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/DYN.txt";
b = "DYN";
z = 300;
k = 0;
}

if(j == 1){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/EPD.txt";
b = "EPD";
z = 300;
k = 0;
}

if(j == 2){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/KMI.txt";
b = "KMI";
z =300;
k = 0;
}

if(j == 3){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/AIG.txt";
b = "AIG";
z = 300;
k = 0;
}

if(j == 4){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BABA.txt";
b = "BABA";
z = 300;
k = 0;
}

if(j == 5){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/FANG.txt";
b = "FANG";
z =300;
k = 0;
}

if(j == 6){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/FB.txt";
b = "FB";
z =300;
k = 0;
}

if(j == 7){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/GS.txt";
b = "GS";
z =300;
k = 0;
}

if(j == 8){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/IBM.txt";
b = "IBM";
z =300;
k = 0;
}

if(j == 9){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/M.txt";
b = "Macy";
z =300;
k = 0;
}

if(j == 10){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/MS.txt";
b = "Morgan_Stanley";
z =300;
k = 0;
}

if(j == 11){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/MSFT.txt";
b = "MSFT";
z =300;
k = 0;
}

if(j == 12){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/SHLD.txt";
b = "Sears";
z =300;
k = 0;
}

/*if(j == 13){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/SP_500.txt";
b = "SP_500";
z =300;
k = 0;
}*/

if(j == 13){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/TWTR.txt";
b = "TWTR";
z =300;
k = 0;
}

if(j == 14){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/MHFI.txt";
b = "MHFI";
z =300;
k = 0;
}

if(j == 15){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/AAPL.txt";
b = "AAPL";
z =300;
k = 0;
}

if(j == 16){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BAC.txt";
b = "BAC";
z =300;
k = 0;
}

if(j == 17){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BRK-A.txt";
b = "BRK-A";
z =300;
k = 0;
}

if(j == 18){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BRK-B.txt";
b = "BRK-B";
z =300;
k = 0;
}

if(j == 19){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/GOOG.txt";
b = "GOOG";
z =300;
k = 0;
}

if(j == 20){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/INTC.txt";
b = "INTC";
z =300;
k = 0;
}

if(j == 21){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/KO.txt";
b = "KO";
z =300;
k = 0;
}



/***************************************************************HK Stocks**********************************************************************/
if(j == 22){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0001.HK.txt";
b = "0001.HK";
z = 820; //Total Size
k = 0; //Starting Point
}

if(j == 23){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0005.HK.txt";
b = "0005.HK";
z = 820;
k = 0;
}

if(j == 24){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0008.HK.txt";
b = "0008.HK";
z = 820;
k = 0;
}

if(j == 25){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0008.HK.txt";
b = "0011.HK";
z = 820;
k = 0;
}

if(j == 26){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0011.HK.txt";
b = "0016.HK";
z = 820;
k = 0;
}

if(j == 27){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0016.HK.txt";
b = "0066.HK";
z = 820;
k = 0;
}

if(j == 28){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0066.HK.txt";
b = "0087.HK";
z = 820;
k = 0;
}

if(j == 29){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0087.HK.txt";
b = "0101.HK";
z = 820;
k = 0;
}

if(j == 30){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0101.HK.txt";
b = "0165.HK";
z = 820;
k = 0;
}

if(j == 31){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0165.HK.txt";
b = "0272.HK";
z = 820;
k = 0;
}

if(j == 32){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0272.HK.txt";
b = "0293.HK";
z = 820;
k = 0;
}

if(j == 33){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0293.HK.txt";
b = "0388.HK";
z = 820;
k = 0;
}

if(j == 34){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0388.HK.txt";
b = "0494.HK";
z = 820;
k = 0;
}

if(j == 35){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0494.HK.txt";
b = "1019.HK";
z = 820;
k = 0;
}

if(j == 36){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/1019.HK.txt";
b = "1299.HK";
z = 820;
k = 0;
}

}

/*Back_Testing Sets that will be read and developed*/
void input_names_BT(int j, char* &a, char* &b, int &z, int &k){

/************************************************US Stocks**********************************************************/
if(j == 0){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/DYN_BT.txt";
b = "DYN";
z = 235;
k = 0;
}

if(j == 1){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/EPD_BT.txt";
b = "EPD";
z = 235;
k = 0;
}

if(j == 2){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/KMI_BT.txt";
b = "KMI";
z = 235;
k = 0;
}

if(j == 3){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/AIG_BT.txt";
b = "AIG";
z = 235;
k = 0;
}

if(j == 4){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BABA_BT.txt";
b = "BABA";
z = 235;
k = 0;
}

if(j == 5){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/FANG_BT.txt";
b = "FANG";
z = 235;
k = 0;
}

if(j == 6){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/FB_BT.txt";
b = "FB";
z = 235;
k = 0;
}

if(j == 7){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/GS_BT.txt";
b = "GS";
z = 235;
k = 0;
}

if(j == 8){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/IBM_BT.txt";
b = "IBM";
z = 235;
k = 0;
}

if(j == 9){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/M_BT.txt";
b = "Macy";
z = 235;
k = 0;
}

if(j == 10){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/MS_BT.txt";
b = "Morgan_Stanley";
z = 235;
k = 0;
}

if(j == 11){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/MSFT_BT.txt";
b = "MSFT";
z = 235;
k = 0;
}

if(j == 12){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/SHLD_BT.txt";
b = "Sears";
z = 235;
k = 0;
}

/*if(j == 13){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/SP_500_BT.txt";
b = "SP_500";
z = 235;
k = 0;
}*/

if(j == 13){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/TWTR_BT.txt";
b = "TWTR";
z = 235;
k = 0;
}

if(j == 14){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/MHFI_BT.txt";
b = "MHFI";
z = 235;
k = 0;
}

if(j == 15){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/AAPL_BT.txt";
b = "AAPL";
z = 235;
k = 0;
}

if(j == 16){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BAC_BT.txt";
b = "BAC";
z = 235;
k = 0;
}

if(j == 17){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BRK-A_BT.txt";
b = "BRK-A";
z = 235;
k = 0;
}

if(j == 18){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BRK-B_BT.txt";
b = "BRK-B";
z = 235;
k = 0;
}

if(j == 19){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/GOOG_BT.txt";
b = "GOOG";
z = 235;
k = 0;
}

if(j == 20){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/INTC_BT.txt";
b = "INTC";
z = 235;
k = 0;
}

if(j == 21){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/KO_BT.txt";
b = "KO";
z = 235;
k = 0;
}

/***************************************************************HK Stocks**********************************************************************/
if(j == 22){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0001.HK_BT.txt";
b = "0001.HK";
z = 820; //Total Size
k = 0; //Starting Point
}

if(j == 23){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0005.HK_BT.txt";
b = "0005.HK";
z = 820;
k = 0;
}

if(j == 24){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0008.HK_BT.txt";
b = "0008.HK";
z = 820;
k = 0;
}

if(j == 25){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0008.HK_BT.txt";
b = "0011.HK";
z = 820;
k = 0;
}

if(j == 26){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0011.HK_BT.txt";
b = "0016.HK";
z = 820;
k = 0;
}

if(j == 27){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0016.HK_BT.txt";
b = "0066.HK";
z = 820;
k = 0;
}

if(j == 28){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0066.HK_BT.txt";
b = "0087.HK";
z = 820;
k = 0;
}

if(j == 29){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0087.HK_BT.txt";
b = "0101.HK";
z = 820;
k = 0;
}

if(j == 30){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0101.HK_BT.txt";
b = "0165.HK";
z = 820;
k = 0;
}

if(j == 31){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0165.HK_BT.txt";
b = "0272.HK";
z = 820;
k = 0;
}

if(j == 32){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0272.HK_BT.txt";
b = "0293.HK";
z = 820;
k = 0;
}

if(j == 33){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0293.HK_BT.txt";
b = "0388.HK";
z = 820;
k = 0;
}

if(j == 34){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0388.HK_BT.txt";
b = "0494.HK";
z = 820;
k = 0;
}

if(j == 35){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/0494.HK_BT.txt";
b = "1019.HK";
z = 820;
k = 0;
}

if(j == 36){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/Asia/1019.HK_BT.txt";
b = "1299.HK";
z = 820;
k = 0;
}

}

/*int main for executing the functions*/
int main(){
	srand(time(NULL));
	//Output file to be filled with results
	char* ofile = "Results.txt";
	char* mean_return_port = "Mean_Port.txt";
	char* cov_var_mat = "cov_var_mat.txt";
	char* cov_var_mat_BT = "cov_var_mat_BT.txt";
	char* corr_mat = "correlation_mat.txt";
	char* inv_cov_var_mat = "inverse_cov_var_mat.txt";
	char* min_variance_weights = "minimum_variance_weights.txt";
	char* opt_port_weights = "sharpe_opt_weights.txt";
	int optimal_number_of_stock;
	double sharpe_final = 0;
	double sharpe_final_out = 0;
	double port_mean_opt = 0;
	double port_std_opt = 0;
	int number_of_stocks_out;
	double *sharpe_weight_final_out;
	char* *sym_arr_out;


	int counter_init = 8;
	int counter = counter_init;
	int stock_start = 3;
	while(counter <= 20){
	//Size of stocks and pointers
	int number_of_stocks = counter + 1; //Change the stock numbers for evaluating US stocks and HK stocks through Markowitz
	
	//Arrays for analytics
	double mean_ir[number_of_stocks];
	double mean_ir_BT[number_of_stocks];
	double mean_cp[number_of_stocks];
	double std_ir[number_of_stocks];
	double std_cp[number_of_stocks];
	double Max_DD[number_of_stocks];
	double max[number_of_stocks];
	double min[number_of_stocks];
	char* infile;
	char* infile_BT;
	char* symbol;
	char* symbol_arr[number_of_stocks];
	char* vol[number_of_stocks];
	int size; //Size for in sample data
	int size_BT; //Size for out sample data
	int start; //Start value for in sample data
	int start_BT; //Start value for out sample data

	//Define the class in int main
	Markowitz MK;
	/*Initializing Back_test class*/
	Back_test BT;

	input_names(stock_start, infile, symbol, size, start);
    input_names_BT(stock_start, infile, symbol, size_BT, start_BT);

	//Initializing mean array table with all zeros to be filled in
	MK.init_tables(start, size, stock_start, number_of_stocks);
	BT.init_tables(start_BT, size_BT, stock_start, number_of_stocks);

	//Change this to match with the stock numbers that we are going to evaluate
	for(int i = stock_start; i < number_of_stocks; i++){
	//Setting the file names and size of the files
	input_names(i, infile, symbol, size, start);
	input_names_BT(i, infile_BT, symbol, size_BT, start_BT);


	//Calling the reading function
	MK.Read_Lines(infile, size);
	BT.Read_Lines(infile_BT, size_BT);
	MK.Calculate_Return(size, i, stock_start);
	BT.Calculate_Return(size_BT, i, stock_start);
	MK.set_mean_port_arr(stock_start, size, i);
	BT.set_mean_port_arr(stock_start, size_BT, i);

	mean_ir[i] = MK.mean_i_r(size, start, symbol, (i - stock_start));
	mean_ir_BT[i] = BT.mean_i_r(size_BT, start_BT, symbol, (i - stock_start));
	mean_cp[i] = MK.mean_c_p(size, start, symbol, (i - stock_start));
	std_cp[i] = MK.std_c_p(mean_cp[i], start, size, (i - stock_start));
	std_ir[i] = MK.std_i_r(mean_ir[i], start, size, (i - stock_start));
	vol[i] = MK.return_vol(std_ir[i]);
	Max_DD[i] = MK.max_drawdown(size,start);
	max[i] = MK.find_max(size, start);
	min[i] = MK.find_min(size, start);
	
	//Calculate covariance and varianvce matrix
	MK.set_cov_var_matrix(i, size, stock_start);
	MK.set_corr_matrix(i, size, stock_start);
	BT.set_cov_var_matrix(i, size_BT, stock_start);
	BT.set_corr_matrix(i, size_BT, stock_start);
	};

	MK.set_inverse_cov_var_mat(stock_start, number_of_stocks);
	BT.set_inverse_cov_var_mat(stock_start, number_of_stocks);
	
	//Finding the weights for minimum variance portfolio
	MK.find_min_var_weights(number_of_stocks - stock_start, 0); // "0" does not allow short sell, "1" allows short sell
	MK.find_opt_weights(number_of_stocks - stock_start, 0, 1);

	//Output Results
	for(int i = 0; i < number_of_stocks; i++){
	input_names(i, infile, symbol, size, start);
	symbol_arr[i] = symbol;
	}

	MK.Dis_opt_port_weights(symbol_arr, number_of_stocks, stock_start);
	
	/*Checking and finding the most optimal weights that can be used and perform back testing*/

	sharpe_final = MK.get_sharpe();
	optimal_number_of_stock = (number_of_stocks-stock_start);
	
	double sharpe_weight_final[number_of_stocks-stock_start]; 
	
	for(int i = 0; i < (number_of_stocks-stock_start); i++){
	sharpe_weight_final[i] = 0;
	}

	std::cout<<" "<<std::endl;
	std::cout<<"The new weight that maximize sharpe ratio (in-sample) is: "<<std::endl;
	
	for(int i = 0; i < (number_of_stocks-stock_start); i++){
	sharpe_weight_final[i] = MK.check_sharpe_opt_port_weights(number_of_stocks, stock_start, i);
	std::cout<<symbol_arr[i+stock_start] << " " <<sharpe_weight_final[i]<<std::endl;
	}

	std::cout<<" "<<std::endl;
	std::cout<<"The optimal maximized sharpe ratio (in-sample) is: "<<std::endl;
	std::cout<<sharpe_final<<std::endl;
	
	BT.Calc_OS_Sharpe(sharpe_weight_final, (number_of_stocks-stock_start));

	if(BT.get_sharpe() > sharpe_final_out){
	
	number_of_stocks_out = number_of_stocks;
	sharpe_final_out = BT.get_sharpe();
	port_mean_opt = BT.get_mean_opt();
	port_std_opt = BT.get_std_opt();

	sharpe_weight_final_out = new double[number_of_stocks-stock_start];
	sym_arr_out = new char*[number_of_stocks-stock_start];
	
	for(int i = 0; i < (number_of_stocks-stock_start); i++){
	sharpe_weight_final_out[i] = sharpe_weight_final[i];
	sym_arr_out[i] = symbol_arr[i+stock_start];
	}
	
	}
			
	//Write Mean Results out
	/*MK.Out_Mean_Return(mean_return_port, symbol_arr, size, stock_start, number_of_stocks);
	MK.Out_cov_var_mat(cov_var_mat, number_of_stocks, stock_start);
	MK.Out_corr_mat(corr_mat, number_of_stocks, stock_start);
	MK.Out_inverse_cov_var_mat(inv_cov_var_mat, number_of_stocks, stock_start);
	MK.Out_min_var_weights(min_variance_weights, symbol_arr, number_of_stocks, stock_start);
	MK.Out_opt_port_weights(opt_port_weights, symbol_arr, number_of_stocks, stock_start);*/
	
	BT.Out_cov_var_mat(cov_var_mat_BT, number_of_stocks, stock_start);

	counter++;
	}

	/*Showing the most optimal sharpe out of all the sets*/
	std::cout<<" "<<std::endl;
	std::cout<<"**********************************************************"<<std::endl;
	std::cout<<" "<<std::endl;
	std::cout<<"The optimal sharpe ratio is: "<<std::endl;
	std::cout<< sharpe_final_out<< std:: endl;
	std::cout<<" " << std::endl;
	std::cout<<"The optimal portfolio mean return is: "<<std::endl;
	std::cout<< port_mean_opt << std:: endl;
	std::cout<<" " << std::endl;
	std::cout<<"The optimal portfolio std return is: "<<std::endl;
	std::cout<< port_std_opt << std:: endl;
	std::cout<<" " << std::endl;
	std::cout<<"The optimal weights is: "<<std::endl;
	
	for(int i=0; i < (number_of_stocks_out-stock_start); i++){
	std::cout<<sym_arr_out[i] << " " << sharpe_weight_final_out[i]<<std::endl;
	};

	//Testing Risk Management
	std::cout<<" "<<std::endl;
	std::cout<<"**********************************************************"<<std::endl;
	std::cout<<" "<<std::endl;
	std::cout<<"--------------Risk Management Calculation-----------------"<<std::endl;
	Risk_Management RM;
	std::cout<<" " <<std::endl;
	std::cout<<"The Randomly Generated Uniform Distribution number is: " << RM.uniform_random() << std::endl;
	std::cout<<" " <<std::endl;
	std::cout<<"The Randomly Generated Normal Distribution number is: " << RM.normal_random() << std::endl;

	//Running simulations
	RM.simulation(port_mean_opt, port_std_opt,10000);

	return 0;
}