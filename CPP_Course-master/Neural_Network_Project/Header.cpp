#include "Header.h"

//We first define a global Activation function
double bipolar_sigmoid(double a){
return 2/(1+exp(-a)) - 1;
}

//This is the first derivative of sigmoid
double bipolar_sigmoid_first(double a){
return 0.5*(1+bipolar_sigmoid(a))*(1-bipolar_sigmoid(a));
}

read_input :: read_input(){
std::cout << "This is default constructor... " << std::endl;
}

//Methods for default constructor
void read_input :: read(int num_elem){

	std::ifstream in_file("Brazil_CPI.txt");

	std::string line;
	double number;
	int count = 0;
	number_of_elements = num_elem;

	while(!in_file.eof()){
	getline(in_file, line);
	count++;
	}
	in_file.close();

	//Initialize the input vector 2D Array
	Input_X = new double*[count];
	Input_X_n = new double*[count];
	Yactual = new double[count];
	Yactualn = new double[count];

	for(int i=0; i < count; i++){
		Input_X[i] = new double[num_elem];
		Input_X_n[i] = new double[num_elem];
	}

	for(int i=0; i < count; i++){
		for(int j=0; j < num_elem; j++){
		Input_X[i][j] = 0;
		}
	}

	for(int i=0; i < (count-1); i++){
		for(int j=0; j < num_elem; j++){
		Input_X_n[i][j] = 0;
		}
	}

	for(int i=0; i < (count-1); i++){
		Yactual[i] = 0;
		Yactualn[i] = 0;
	}

	//Start Reading all the CPIs into the newly formed matrix
	std::ifstream in_file1("Brazil_CPI.txt");
	count = 0;
	while(!in_file1.eof()){
	getline(in_file1, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][0] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file1.close();
	

	std::ifstream in_file2("Britain_CPI.txt");
	count = 0;
	while(!in_file2.eof()){
	getline(in_file2, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][1] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file2.close();

	std::ifstream in_file3("Canada_CPI.txt");
	count = 0;
	while(!in_file3.eof()){
	getline(in_file3, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][2] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file3.close();

	std::ifstream in_file4("Chile_CPI.txt");
	count = 0;
	while(!in_file4.eof()){
	getline(in_file4, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][3] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file4.close();

	std::ifstream in_file5("China_CPI.txt");
	count = 0;
	while(!in_file5.eof()){
	getline(in_file5, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][4] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file5.close();

	std::ifstream in_file6("Germany_CPI.txt");
	count = 0;
	while(!in_file6.eof()){
	getline(in_file6, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][5] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file6.close();

	std::ifstream in_file7("India_CPI.txt");
	count = 0;
	while(!in_file7.eof()){
	getline(in_file7, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][6] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file7.close();

	std::ifstream in_file8("Indonesia_CPI.txt");
	count = 0;
	while(!in_file8.eof()){
	getline(in_file8, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][7] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file8.close();


	std::ifstream in_file10("Korea_CPI.txt");
	count = 0;
	while(!in_file10.eof()){
	getline(in_file10, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][8] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file10.close();

	std::ifstream in_file11("Swiss_CPI.txt");
	count = 0;
	while(!in_file11.eof()){
	getline(in_file11, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X[count][9] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file11.close();

	std::ifstream in_file12("Oil_Price.txt");
	count = 0;
	while(!in_file12.eof()){
	getline(in_file12, line);
	std::istringstream ss(line);
	ss >> number;
	Yactual[count] = number;
	//std::cout << Yactual[count] << std::endl;
	count++;
	}
	//std::cout << count << std::endl;
	in_file12.close();

	length_of_input = count;
}


//The following function reads the out-sample method
void read_input :: read_out_sample(){

	std::ifstream in_file("Brazil_CPI_out_sample.txt");

	std::string line;
	double number;
	int count = 0;

	while(!in_file.eof()){
	getline(in_file, line);
	count++;
	}
	in_file.close();

	//Initialize the input vector 2D Array
	Input_X_out_sample = new double*[count];
	Input_X_out_sample_n = new double*[count];
	Youtsample = new double[count];
	Youtsamplen = new double[count];

	for(int i=0; i < count; i++){
		Input_X_out_sample[i] = new double[number_of_elements];
		Input_X_out_sample_n[i] = new double[number_of_elements];
	}

	for(int i=0; i < count; i++){
		for(int j=0; j < number_of_elements; j++){
		Input_X_out_sample[i][j] = 0;
		}
	}

	for(int i=0; i < (count-1); i++){
		for(int j=0; j < number_of_elements; j++){
		Input_X_out_sample_n[i][j] = 0;
		}
	}

	for(int i=0; i < (count-1); i++){
		Youtsample[i] = 0;
		Youtsamplen[i] = 0;
	}

	//Start Reading all the CPIs into the newly formed matrix
	std::ifstream in_file1("Brazil_CPI_out_sample.txt");
	count = 0;
	while(!in_file1.eof()){
	getline(in_file1, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][0] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file1.close();
	

	std::ifstream in_file2("Britain_CPI_out_sample.txt");
	count = 0;
	while(!in_file2.eof()){
	getline(in_file2, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][1] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file2.close();

	std::ifstream in_file3("Canada_CPI_out_sample.txt");
	count = 0;
	while(!in_file3.eof()){
	getline(in_file3, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][2] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file3.close();

	std::ifstream in_file4("Chile_CPI_out_sample.txt");
	count = 0;
	while(!in_file4.eof()){
	getline(in_file4, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][3] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file4.close();

	std::ifstream in_file5("China_CPI_out_sample.txt");
	count = 0;
	while(!in_file5.eof()){
	getline(in_file5, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][4] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file5.close();

	std::ifstream in_file6("Germany_CPI_out_sample.txt");
	count = 0;
	while(!in_file6.eof()){
	getline(in_file6, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][5] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file6.close();

	std::ifstream in_file7("India_CPI_out_sample.txt");
	count = 0;
	while(!in_file7.eof()){
	getline(in_file7, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][6] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file7.close();

	std::ifstream in_file8("Indonesia_CPI_out_sample.txt");
	count = 0;
	while(!in_file8.eof()){
	getline(in_file8, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][7] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file8.close();


	std::ifstream in_file10("Korea_CPI_out_sample.txt");
	count = 0;
	while(!in_file10.eof()){
	getline(in_file10, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][8] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file10.close();

	std::ifstream in_file11("Swiss_CPI_out_sample.txt");
	count = 0;
	while(!in_file11.eof()){
	getline(in_file11, line);
	std::istringstream ss(line);
	ss >> number;
	//std::cout << number << std::endl;
	Input_X_out_sample[count][9] = number;
	count++;
	}
	//std::cout << count << std::endl;
	in_file11.close();

	std::ifstream in_file12("Oil_Price_out_sample.txt");
	count = 0;
	while(!in_file12.eof()){
	getline(in_file12, line);
	std::istringstream ss(line);
	ss >> number;
	Youtsample[count] = number;
	//std::cout << Yactual[count] << std::endl;
	count++;
	}
	//std::cout << count << std::endl;
	in_file12.close();

	length_of_input_out_sample = count;

}


//The following function normalize all the inputs
void read_input :: normalize(){
	
	double min_b = 0;
	double max_b = 0;
	double min_b_os = 0;
	double max_b_os = 0;
	double min_b_y = 0;
	double max_b_y = 0;
	double min_b_y_os = 0;
	double max_b_y_os = 0;

	//Normalize Input X
	for(int j = 0; j < number_of_elements; j++){ 
		for(int i = 0; i < length_of_input-1; i++){
		Input_X_n[i][j] = 200 * (Input_X[i+1][j] - Input_X[i][j]) / (Input_X[i+1][j] + Input_X[i][j]);
		}
	}

	//Finding min_b and max_b for Input X
	for(int j = 0; j < number_of_elements; j++){ 
		for(int i = 0; i < length_of_input-1; i++){

			if(Input_X_n[i][j] < min_b){
			min_b = Input_X_n[i][j];
			}
			
			if(Input_X_n[i][j] > max_b){
			max_b = Input_X_n[i][j];
			}
		}

		for(int i = 0; i < length_of_input-1; i++){
			Input_X_n[i][j] = (Input_X_n[i][j]-min_b)/(max_b - min_b);
		}

	max_b = 0;
	min_b = 0;
	}

	//Normalize Input X for out sample data
	for(int j = 0; j < number_of_elements; j++){ 
		for(int i = 0; i < length_of_input_out_sample-1; i++){
		Input_X_out_sample_n[i][j] = 200 * (Input_X_out_sample[i+1][j] - Input_X_out_sample[i][j]) / (Input_X_out_sample[i+1][j] + Input_X_out_sample[i][j]);
		}
	}

	//Finding min_b and max_b for Input X
	for(int j = 0; j < number_of_elements; j++){ 
	   for(int i = 0; i < length_of_input_out_sample-1; i++){
	
			if(Input_X_out_sample_n[i][j] < min_b_os){
			min_b_os = Input_X_out_sample_n[i][j];
			}
			
			if(Input_X_out_sample_n[i][j] > max_b_os){
			max_b_os = Input_X_out_sample_n[i][j];
			}
		}

		for(int i = 0; i < length_of_input_out_sample-1; i++){
			Input_X_out_sample_n[i][j] = (Input_X_out_sample_n[i][j]-min_b_os)/(max_b_os - min_b_os);
		}

	max_b_os = 0;
	min_b_os = 0;
	}

	//Normalize Y_actual
	for(int i = 0; i < (length_of_input-1); i++){
	   Yactual[i] = 200 * (Yactual[i+1]- Yactual[i]) / (Yactual[i+1] + Yactual[i]);
	}

	for(int i=0; i < (length_of_input-1); i++){

			if(Yactual[i] < min_b_y){
			min_b_y = Yactual[i];
			}
			
			if(Yactual[i] > max_b_y){
			max_b_y = Yactual[i];
			}
	}

	for(int i=0; i < (length_of_input-1);i++){
	  Yactualn[i] = (Yactual[i] - min_b_y) / (max_b_y - min_b_y);
	}

	//Normalize Youtsamplen
	for(int i = 0; i < (length_of_input_out_sample-1); i++){
	   Youtsamplen[i] = 200 * (Youtsample[i+1]- Youtsample[i]) / (Youtsample[i+1] + Youtsample[i]);
	}

	for(int i=0; i < (length_of_input_out_sample-1); i++){

			if(Youtsample[i] < min_b_y_os){
			min_b_y_os = Youtsample[i];
			}
			
			if(Youtsample[i] > max_b_y_os){
			max_b_y_os = Youtsample[i];
			}
	}

	for(int i=0; i < (length_of_input_out_sample-1);i++){
	  Youtsamplen[i] = (Youtsample[i] - min_b_y_os) / (max_b_y_os - min_b_y_os);
	}
}

//Destructor
read_input :: ~read_input(){
	std::cout << "This is read_input destructor..." <<std::endl;
	//delete Input;
	delete[] Input_X;
	delete[] Input_X_n;
	delete[] V_weights;
    delete[] V_delta;
	delete[] V_weights_final;
	delete[] W_weights;
    delete[] W_delta;
	delete[] W_weights_final; 
	delete[] Z; 
	delete[] Zin; 
    delete[] Y; 
    delete[] Yin; 
    delete[] Yactual; 
	delete[] Yactualn;
	delete[] Z_os; //The Z values that will be used for shadow calculations
	delete[] Zin_os; //The Zin values that will used before sigmoid transformation
    delete[] Y_os; //The Y values that will be used for calculation
    delete[] Yin_os; //The Yin values that will be used
}

//Creating the extended class from read_input from inheritance

shadow :: shadow(){
std::cout << "This is shadow default constructor... " << std::endl;
alpha = 0.5;
}

shadow :: ~shadow(){
	std::cout << "This is shadow destructor ..." << std::endl;
	delete[] delta_z;
}

//Create the V weights to calculate Z in the shadow
void shadow :: create_v_weights(){
    
    srand(time(0));
    
	V_weights = new double*[(number_of_elements+1)*number_of_elements];
    V_delta = new double*[(number_of_elements+1)*number_of_elements];

	for(int i = 0; i < ((number_of_elements+1)*number_of_elements); i++){
		V_weights[i] = new double[length_of_input];
        V_delta[i] = new double[length_of_input];
	}

	for(int i = 0; i < ((number_of_elements+1)*number_of_elements); i++){
		for(int j = 0; j < length_of_input; j++){
			V_weights[i][j] = (rand()%100);
            V_weights[i][j] /= 100;
            V_delta[i][j] = 0;
		}
	}

}

//Create the W weights to calculate Y in final output
void shadow :: create_w_weights(){
    
    srand(time(0));
    
    W_weights = new double*[number_of_elements+1];
    W_delta = new double*[number_of_elements+1];
    
    for(int i = 0; i < (number_of_elements+1); i++){
        W_weights[i] = new double[length_of_input];
        W_delta[i] = new double[length_of_input];
    }
    
    for(int i = 0; i < (number_of_elements+1); i++){
        for(int j = 0; j < length_of_input; j++){
            W_weights[i][j] = (rand()%100);
            W_weights[i][j] /= 100;
            W_delta[i][j] = 0;
        }
    }
}

//Create Z that is in the shadow
void shadow :: create_z(){
    
    Z = new double*[number_of_elements+1];
    Zin = new double*[number_of_elements+1];
	Z_os = new double*[number_of_elements+1];
	Zin_os = new double*[number_of_elements+1];

	//This is for creating the training data
    for(int i = 0; i < (number_of_elements+1); i++){
        Z[i] = new double[length_of_input];
		Zin[i] = new double[length_of_input];
    }
    
    for(int i = 0; i < (number_of_elements+1); i++){
        for(int j = 0; j < length_of_input; j++){
            Z[i][j] = 0;
			Zin[i][j] = 0;
        }
    }

	//This is for creating the out of sample training data
    for(int i = 0; i < (number_of_elements+1); i++){
        Z_os[i] = new double[length_of_input_out_sample];
		Zin_os[i] = new double[length_of_input_out_sample];
    }
    
    for(int i = 0; i < (number_of_elements+1); i++){
        for(int j = 0; j < length_of_input_out_sample; j++){
            Z_os[i][j] = 0;
			Zin_os[i][j] = 0;
        }
    }

}

//Create Y that is in the shadow
void shadow :: create_y(){
    
    Y = new double[length_of_input];
    Yin = new double[length_of_input];
	Y_os = new double[length_of_input_out_sample];
	Yin_os = new double[length_of_input_out_sample];
    
	//The following results are for the training input
    for(int i = 0; i < length_of_input; i++){
    Y[i] = 0;
    }
    
    for(int i = 0; i < length_of_input; i++){
    Yin[i] = 0;
    }

	//The following results are for out of sample
    for(int i = 0; i < length_of_input_out_sample; i++){
    Y_os[i] = 0;
    }
    
    for(int i = 0; i < length_of_input_out_sample; i++){
	Yin_os[i] = 0;
    }

}

//Multiply v_weights to calculate z multiply
void shadow :: multiply_z(){
    
for (int k = 0; k < (number_of_elements+1); k++){
	for(int i = 0; i < (number_of_elements+1); i++){
		for(int j = 0; j < length_of_input; j++){
		
			if(i == 0){
			Zin[k][j] += V_weights[i][j] * 1;
			}
			else{
			Zin[k][j] += V_weights[i][j] * Input_X_n[j][i];
			}
		}
	}
}

//Transform using activation function   
for(int k = 0; k < (number_of_elements+1); k++){
	for(int i = 0; i < length_of_input; i++){
        Z[k][i] = bipolar_sigmoid(Zin[k][i]);
	}
}

}


//Multiply w_weights to calculate predicted y values
void shadow :: multiply_y(){
    
    //Transform using activation function
    for(int k = 0; k < (number_of_elements+1); k++){
        for(int i = 0; i < length_of_input; i++){
            
            if(k==0){
            Yin[i] += W_weights[k][i] * 1;
            }
            else{
            Yin[i] += W_weights[k][i] * Z[k][i];
            }
        }
    }
    
    for(int i = 0; i < length_of_input; i++){
            Y[i] = bipolar_sigmoid(Yin[i]);
    }
}

//Calculate Delta Y
void shadow :: calc_delta_y(){

    /*delta_y = new double[length_of_input];

	for(int i=0; i < length_of_input; i++){
	delta_y[i] = 0;
	}*/

	for(int i=0; i < length_of_input; i++){
	delta_y += (Yactual[i] - Y[i]) * (bipolar_sigmoid_first(Yin[i]));
	}

	delta_y /= length_of_input;

    //std::cout << "This is delta_y: " << delta_y << std::endl;
}

//Calcuate the W_deltas that will be added to the W weights
void shadow :: calc_delta_w(){

	for(int i=0 ; i < (number_of_elements + 1); i++){
		for(int j=0; j < length_of_input; j++){

			if(i == 0){
			W_delta[i][j] = alpha * delta_y;
			}
			else{
			W_delta[i][j] = alpha * delta_y * Z[i][j];
			}
			//std::cout << W_delta[i][j] << std::endl;
		}
	}
}

//Calculate Delta Z
void shadow :: calc_delta_z(){

	/*delta_z = new double*[number_of_elements + 1];
	
	for(int i=0; i < (number_of_elements + 1); i++){
			delta_z[i] = new double [length_of_input];
	}

	for(int i = 0; i < (number_of_elements + 1); i++){
		for(int j = 0; j < length_of_input; j++){
			delta_z[i][j] = 0;
		}
	}*/

	delta_z = new double[number_of_elements + 1];

	for(int i = 0; i < (number_of_elements + 1); i++){
		delta_z[i] = 0;
	}

	for(int i = 0; i < (number_of_elements + 1); i++){
		for(int j=0; j < length_of_input; j++){
		delta_z[i] += delta_y * W_weights[i][j] * bipolar_sigmoid_first(Zin[i][j]);
		}
	}

	/*for(int i=0; i < (number_of_elements + 1); i++){
		for(int j=0; j < length_of_input; j++){
		delta_z[i][j] = delta_y * W_weights[i][j] * bipolar_sigmoid_first(Zin[i][j]);
		//std::cout << delta_z[i][j] << std::endl;
		}
	}*/

}

//Calcuate the V_deltas that will be added to the V weights
void shadow :: calc_delta_v(){

	for(int i=0 ; i < (number_of_elements + 1) * number_of_elements; i++){
		for(int j=0; j < length_of_input; j++){

			if(i % (number_of_elements + 1) == 0){
			V_delta[i][j] = alpha * delta_z[i % (number_of_elements+1)]/*[j]*/;
			}
			else{
			V_delta[i][j] = alpha * delta_z[i % (number_of_elements+1)]/*[j]*/ * Input_X_n[i % (number_of_elements+1)][j];
			//std::cout << V_delta[i][j] << std::endl;
			}
		}
	}
}


//The following method updates the weights
void shadow :: update_weights(){

	for(int i = 0; i < (number_of_elements + 1) * number_of_elements; i++){
		for(int j=0; j < length_of_input; j++){
		V_weights[i][j] += V_delta[i][j];
		}
	}

	for(int i = 0; i < (number_of_elements + 1); i++){
		for(int j=0; j < length_of_input; j++){
		W_weights[i][j] += W_delta[i][j];
		}
	}
}

//Return Delta
double shadow :: return_delta_y(){
return delta_y;
}


//The following method print the weights
void shadow :: print_weights(){

	/*for(int i = 0; i < (number_of_elements + 1) * number_of_elements; i++){
		for(int j=0; j < length_of_input; j++){
		V_weights[i][j] += V_delta[i][j];
		std::cout << V_weights[i][j] << std::endl;
		//if(j == (length_of_input - 1)){
		//std::cout << "Next Column ... " << std::endl;
		//}
		}
	}*/

	/*for(int i = 0; i < (number_of_elements + 1); i++){
		for(int j=0; j < length_of_input; j++){
		std::cout << W_weights[i][j] << std::endl;
		if(j == (length_of_input - 1)){
		std::cout << "Next Column ... " << std::endl;
		}
		}
	}

	std::cout << "End of print this round... " << std::endl;*/
}

//The following method records the final W and V weights
void shadow :: record_final_weights(){

	double temp;
	std::ofstream w_weights("W_weights.txt");
	std::ofstream v_weights("V_weights.txt");

	//Record all the information into W_weights_final
	W_weights_final = new double[number_of_elements+1];

	for(int i=0; i < (number_of_elements+1); i++){
		for(int j=0; j < length_of_input; j++){
		W_weights_final[i] += W_weights[i][j];
		}
	}

	std::cout << "W weights final is: " << std::endl;

	for(int i=0; i < (number_of_elements+1); i++){
		W_weights_final[i] /= length_of_input;
		temp = W_weights_final[i];
		w_weights << temp;
		w_weights << '\n';
		std::cout << W_weights_final[i] << std::endl;
	}

	//Record all the information into V_weights_final
	V_weights_final = new double[(number_of_elements+1)*number_of_elements];

	for(int i=0; i < (number_of_elements+1)*number_of_elements; i++){
		for(int j=0; j < length_of_input; j++){
		V_weights_final[i] += V_weights[i][j];
		}
	}

	std::cout << "V weights final is: " << std::endl;

	for(int i=0; i < (number_of_elements+1)*number_of_elements; i++){
		V_weights_final[i] /= length_of_input;
		temp = V_weights_final[i];
		std::cout << V_weights_final[i] << std::endl;
		v_weights << temp;
		v_weights << '\n';

		if(i % (number_of_elements + 1) == 0){
		v_weights << "Weights for next node...\n";
		}
	}

	w_weights.close();
	v_weights.close();
}

//The following method calculates the out of sample y results using trained weights
void shadow :: calc_oos_result(){

	 //First we calculate Zin using the weights we obtained from training the data
	for(int k=0; k < (number_of_elements); k++){
		for(int i=0; i < (number_of_elements); i++){
			 for(int j=0; j < (length_of_input_out_sample-1); j++){

				if(i == 0){
				Zin_os[k][j] += V_weights_final[i+11*k] * 1;
				}
				else{
				Zin_os[k][j] += V_weights_final[i+11*k] * Input_X_out_sample_n[j][i];
				}
			 }
		 }
	 }

	//Transform using activation function   
	for(int k = 0; k < (number_of_elements+1); k++){
		for(int i = 0; i < (length_of_input_out_sample-1); i++){
			Z_os[k][i] = bipolar_sigmoid(Zin_os[k][i]);
		}
	}

	//Calculate the out of sample final Y results
	for(int k = 0; k < (number_of_elements+1); k++){
        for(int i = 0; i < (length_of_input_out_sample-1); i++){
            
            if(k==0){
            Yin_os[i] += W_weights_final[k] * 1;
            }
            else{
            Yin_os[i] += W_weights_final[k] * Z[k][i];
            }
        }
    }
    
    for(int i = 0; i < (length_of_input_out_sample-1); i++){
            Y_os[i] = bipolar_sigmoid(Yin_os[i]);
			//std::cout << Y_os[i] << std::endl;
    }
	
	for(int i = 0; i < (length_of_input_out_sample-1); i++){
			//std::cout << Youtsamplen[i] << std::endl;
	}

	//Calculate the delta Y that sums up the error using the weights and the out of sample results

	for(int i=0; i < (length_of_input_out_sample-1); i++){
	delta_y += (Y_os[i]-Youtsamplen[i]) * (bipolar_sigmoid_first(Yin_os[i]));
	}

	delta_y /= (length_of_input_out_sample-1);
	
	if(delta_y < 0){
	delta_y = -(delta_y);
	}
	else{
	delta_y = delta_y;
	}

	std::cout << "The estimation error between predicted Y and normalized out of sample actual Y using averaged trained weights is: " << delta_y << std::endl;
}