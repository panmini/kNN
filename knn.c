/* Mertcan OZKAN ~ knn.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "csv_read.h"
#include "knn.h"

//d(a,b) = sqrt( (a1-b1)^2 + (a2-b2)^2 + (a3-b3)^2 + (a4-b4)^2 )

float nearest_neighbors(vector_t *data){

	int comparisons = 3;
//	printf("\nEnter the desired number of comparisons to nearby neighbors: ");
//	scanf("%d", &comparisons);

	int i, j, maximum = 0;
	int desicion_counter[possible_output_number];
	int data_estimate;
	for(i = 0; i < comparisons; i++){

	//	printf("Neighbor #%d\tClass: %s\tVector Length %lf\n", i+1, flower[i].type, flower[i].vectorLength/1000);
		for(j = 0; j< possible_output_number; j++) {
			if(data[i].type == j){
				desicion_counter[j]++;
			}
		}
		for(j = 0; j< possible_output_number; j++) {
			if(desicion_counter[j] > maximum){
				data_estimate = data[i].type;
				maximum = desicion_counter[j];
			}
		}
	}
		if(data_estimate > possible_output_number) {
			fprintf(stderr, "Nearest Neighbor cannot be found.\n");
			return -1;
		}else{
	printf("Out of %d nearest neighbors, the most likely classification for the input flower is type %d.\n", i+1, data_estimate);
	return data_estimate;
		}
}

void *evaluate_distance(data_t *knn_data, data_t input_data, int array_elm){

	vector_t *data = (vector_t *) calloc(TRAINING_DATA_SIZE + 1, sizeof(vector_t));

	for(int i = 0; i < array_elm; i++){
		float d_input[input_size];
		int counter = 0;
		while(counter < input_size){
		d_input[counter] = (input_data.input[counter] - knn_data[i].input[counter]);
		counter ++;
		}
		if(data == NULL){
			printf("The given node cannot be NULL");
			return 0;
		}else{
			data[i].type = knn_data[i].output;
			float d_input_sum = 0;
			for(counter = 0; counter < input_size; counter++)
			d_input_sum += d_input[counter] * d_input[counter];

			data[i].vectorLength = (sqrt(d_input_sum)*1000);
		}
	}
	// void qsort(base, num, size, comp);
	qsort(data, array_elm, sizeof(*data), sort_data);
	if(input_data.output == nearest_neighbors(data)) {
		accuracy_rate++;
	}

}

data_t read_user_input(){

	data_t user_data;
	int comparisons;
	user_data.input = malloc((input_size) * sizeof(float));
	printf("Enter the requested information in order to classify a type.\n");
	int counter = 0;
	while(counter < input_size) {
	printf("Enter the user input: ");
	scanf("%f", &user_data.input[counter]);
	counter++;
	}

	return user_data;
}


int sort_data(const void*  x, const void* y){

	int l = (int)((vector_t*)x)->vectorLength;
	int r = (int)((vector_t*)y)->vectorLength;

	return(l-r);
}


