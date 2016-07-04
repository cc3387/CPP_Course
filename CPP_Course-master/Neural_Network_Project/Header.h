#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <sstream> //Convert Strings into integers
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

//We are going to choose a sigmoid activation function for the generation of the trained dataset

//Define the class to read all the inputs from X1 onwards
class read_input{

public:

	double **Input_X; //Will be initialized when information is read
	double **Input_X_n; //Will be initialized along with Input_X and this stores the normalized information
	double **V_weights; //Weights that will be used to create shadow layer
    double **V_delta; //Delta that will be used to sum to V_weights for iterations
	double *V_weights_final; //The Final v weights that will be recorded
	double **W_weights; //Weights that are used to calculate the final prediction
    double **W_delta; //Delta that will be used to sum to W_weights for iterations
	double *W_weights_final; //The Final w weights that will be recorded
	double **Z; //The Z values that will be used for shadow calculations
	double **Zin; //The Zin values that will used before sigmoid transformation
    double *Y; //The Y values that will be used for calculation
    double *Yin; //The Yin values that will be used
    double *Yactual; //Y actual values that are used for training
	double *Yactualn; //Y actual values that are normalized for training

	//The following two elements will be used for out sample data storage
	double *Youtsample; //Y out of sample values that are used for checking
	double *Youtsamplen; //Y out of sample normalized value
	double **Input_X_out_sample; //The out of sample with input x
	double **Input_X_out_sample_n; //The out of sample with normalized input x
	double **Z_os; //The Z values that will be used for shadow calculations
	double **Zin_os; //The Zin values that will used before sigmoid transformation
    double *Y_os; //The Y values that will be used for calculation
    double *Yin_os; //The Yin values that will be used

	//The following two elements record the length of the input for training data and number of elements
   	int length_of_input;
	int length_of_input_out_sample;
	int number_of_elements;

	//Constructors and Destructors
	read_input(); //Constructor
	~read_input();//Destructor

	//Read the input from the files
	void read(int); // This function will read all the information
	void read_out_sample();//This function reads the information in the outsample data set

	//Define functions for normalization process
	void normalize(); //This will normalize all the input data
};

//Use inheritance to continue and build what is in read_input, we can use all the tables in read_input
class shadow : public read_input{

	public:
		//Elements
		double alpha; //Set Alpha as 0.5
		double delta_y;
		double delta_y_os;
		double *delta_z;

		//Constructors
		shadow(); //Default Constructors
		~shadow(); //Default Destructor
	
	//Functions
	void create_v_weights(); //Creating shadow V weights
	void create_w_weights(); //Creating shadow W weights
    void create_z(); //Create z columns
    void create_y(); //Create y column
	void multiply_z(); //Multiply and calculate Z vlaues
    void multiply_y(); //Multiply and calculate predicted Y values

	//The function below calculates delta y
	void calc_delta_y();

	//The function below updates the W_delta values
	void calc_delta_w();

	//The function below calculates delta z
	void calc_delta_z();

	//The function below updates the V_delta values
	void calc_delta_v();

	//Update Weights
	void update_weights();

	//Return delta
	double return_delta_y();

	//The following function record and save the final weights
	void record_final_weights();

	//The following function calculate the prediction using trained weights
	void calc_oos_result();
	
	//Print Weights
	void print_weights();
};






