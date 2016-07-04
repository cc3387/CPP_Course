#include "Header.h"

int main(){

	int count = 0;
	double delta_y_prev;
	double delta_y;
	double delta_y_diff = 100;

	//This is the procedure
	shadow s;
	s.read(10); //Read the 11 files for training purposes
	s.read_out_sample(); //Reading the out of sample data
	s.normalize(); //This normalize the data so that the range is between 0 and 1
    s.create_z();//This function creates z
    s.create_y();//This function creates y
    s.create_v_weights(); //This function initializes the v weights vectors
    s.create_w_weights();//This function initializes the w weights vectors
	
    //The following procedure will train the data
    //while(delta_y_diff > 0.000000000001){
	while(count < 10000){
	s.multiply_z(); //Create Z values for the shadow layers
    s.multiply_y(); //Create Y values for the predicted value
    s.calc_delta_y(); //Calculate the delta y that shows the diff between actual and in sample fit predicted
	s.calc_delta_w(); //Calculate the delta w weights for shadow level
	s.calc_delta_z(); //Calculate delta z for the final level
	s.calc_delta_v(); //Calcualte delta v for the shadow level
	s.update_weights();

	if(count == 0){
	delta_y = s.return_delta_y();
	delta_y_prev = 0;
	delta_y_diff = delta_y - delta_y_prev;
	}
	else{
	delta_y_prev = delta_y;
	delta_y = s.return_delta_y();
	delta_y_diff = delta_y - delta_y_prev;
	}
	
	count++;
	}

	//Record all the final weights
	s.record_final_weights();

	//This function estimates the out of sample normalized y and calculate the error
	s.calc_oos_result();

	//Print the Weights in terminal
	s.print_weights();

	return 0;

}