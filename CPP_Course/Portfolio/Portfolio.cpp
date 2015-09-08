#include "Read.h"

void input_names(int j, char* &a, char* &b, int &z, int &k){

/************************************************US Stocks**********************************************************/
if(j == 0){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/DYN.txt";
b = "DYN";
z =300;
k = 0;
}

if(j == 1){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/EPD.txt";
b = "EPD";
z =300;
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
z =300;
k = 0;
}

if(j == 4){
a = "C:/Users/Clement Chan/Documents/C++/Portfolio/Stocks/US/BABA.txt";
b = "BABA";
z =300;
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

int main(){
	
	//Output file to be filled with results
	char* ofile = "Results.txt";
	
	//Size of stocks and pointers
	int number_of_stocks = 36; //Change the stock numbers for evaluating US stocks and HK stocks through Markowitz

	double mean_ir[number_of_stocks];
	double mean_cp[number_of_stocks];
	double std_ir[number_of_stocks];
	double std_cp[number_of_stocks];
	double Max_DD[number_of_stocks];
	double max[number_of_stocks];
	double min[number_of_stocks];
	char* infile;
	char* symbol;
	char* symbol_arr[number_of_stocks];
	char* vol[number_of_stocks];
	int size;
	int start;
	int stock_start = 0;


	//Define the class in int main
	Read_Calculate RC;
	
	input_names(stock_start, infile, symbol, size, start);
    
	//Initializing mean array table with all zeros to be filled in
	RC.init_tables(start, size, stock_start, number_of_stocks);

	//Change this to match with the stock numbers that we are going to evaluate
	for(int i = stock_start; i < number_of_stocks; i++){
	//Setting the file names and size of the files
	input_names(i, infile, symbol, size, start);
	
	//Calling the reading function
	RC.Read_Lines(infile, size);
	RC.Calculate_Return(size, i, stock_start);
	
	mean_ir[i] = RC.mean_i_r(size, start, symbol, (i - stock_start));
	mean_cp[i] = RC.mean_c_p(size, start, symbol, (i - stock_start));
	std_cp[i] = RC.std_c_p(mean_cp[i], start, size, (i - stock_start));
	std_ir[i] = RC.std_i_r(mean_ir[i], start, size, (i - stock_start));
	vol[i] = RC.return_vol(std_ir[i]);
	Max_DD[i] = RC.max_drawdown(size,start);
	max[i] = RC.find_max(size, start);
	min[i] = RC.find_min(size, start);
	};

	//Output Results
	for(int i = 0; i < number_of_stocks; i++){
	input_names(i, infile, symbol, size, start);
	symbol_arr[i] = symbol;
	}

	RC.Out_Results(stock_start, ofile, symbol_arr, vol, number_of_stocks, mean_cp,std_cp,mean_ir,std_ir, Max_DD, max, min);

	return 0;

}
