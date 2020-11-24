/* Mertcan OZKAN - main.c */
#include <stdio.h>
#include <stdlib.h>
#include "csv_read.h"
#include "knn.h"
int input_size;
int possible_output_number;
int DATASET_SIZE;
float accuracy_rate;
//access using dataStream[x].sL
int main(){
	accuracy_rate =0;
	char selection;
	int i;
	data_t *training_data = read_csv(training_data, 1);
	data_t *test_data = read_csv(training_data, 0);
	printf("Reading CVS is successful\n");

	printf("********************\n");
	printf("* 1.User Input      *\n");
	printf("* 2.Test Data       *\n");
	printf("********************\n");
	printf("Enter Selection> ");
	scanf("%c",&selection);
	data_t *input_data;
	switch(selection) {
		case '1': input_data = malloc((input_size+1) * sizeof(float));
			input_data[0] = read_user_input();
			printf("Read User Input is successfull\n");
			evaluate_distance(training_data, *input_data, TRAINING_DATA_SIZE);
			printf("Evaluateting distance and k-NN successull\n");

			free(training_data);
			free(input_data);
			  break;
		case '2': for(i = 0; i < DATASET_SIZE - TRAINING_DATA_SIZE; i++){
			evaluate_distance(training_data, test_data[i], TRAINING_DATA_SIZE);
			printf("Evaluateting distance and k-NN successull\n");
			}
			printf("The accuracy rate is %f%.\n",(accuracy_rate * 100) / (DATASET_SIZE - TRAINING_DATA_SIZE));
			free(training_data);
			free(test_data);
			  break;
		default: printf("Not a valid selection process will be terminated!!\n");
			 return 0;
	}

	return 0;


}
