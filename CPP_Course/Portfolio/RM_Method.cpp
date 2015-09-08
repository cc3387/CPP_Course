#include "Read.h"

/****************************************************Risk Management Class inheritance definition*******************************************/

double Risk_Management :: uniform_random(){
/*Initialize random seed, if not initialized, the numbers will be the same: */
return ((double)(rand()) + 1.)/((double)(RAND_MAX)+1.);
}

//Box Cox transformation
double Risk_Management :: normal_random(){
pi = 3.1415692;
double u1 = uniform_random();
double u2 = uniform_random();
double normal_num = cos(2*pi*u2)*sqrt(-2*log(u1));
return normal_num;
}

void Risk_Management :: simulation(double mean, double std, int no_sim){

	 int sim = no_sim;
	 double delta_mean;
	 double total_loss;
	 sim_arr = new double[sim];

	 for(int i=0; i<sim; i++){
	 delta_mean = mean * 1 + std * normal_random();
	 total_loss = mean + delta_mean;
	 sim_arr[i] = total_loss;
	 std::cout<<"The Simulated Losses -> " << i + 1 << " simulations are: " << sim_arr[i]<<std::endl;
	 }

}

/*******************Merge Sort Method******************************/

//Unsorted array, low, mid, and end
void Risk_Management :: merge(int arr[], int l, int m, int r){

	 int i, j, k;
	 int n1 = m - l + 1;
	 int n2 = r - m;

	 int L[n1], R[n2]; //Define the left hand side number and right hand side number

	 for(i=0; i<n1; i++){
	 L[i] = arr[l+i]; 
	 }
	 
	 for(j=0; j<n2; j++){
	 R[j] = arr[m+1+j]; 
	 }

	 i=0;
	 j=0;
	 k=l;

	 while(i<n1 && j<n2){

		 if(L[i] < R[j]){
		 arr[k] = L[i];
		 i++;
		 }
		 else{
		 arr[k] = R[j];
		 j++;
		 }
	k++;
	}

	/*Copy the remaining element of L[], if there are any*/
	while(i<n1){
	arr[k] = L[i];
	i++;
	k++;
	}

	while(j<n2){
	arr[k] = R[j];
	j++;
	k++;
	}

}

void Risk_Management :: mergeSort(int arr[], int l, int r){
	int m;

	if(l < r){
	m = l + (r - l)/2;
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m , r);
	}
}

/**************************************************************************/

Risk_Management::~Risk_Management(){
std::cout<<"Initializaing the Risk Management Destructor ... " << std::endl;
delete[] sim_arr;
}