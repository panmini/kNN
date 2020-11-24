/*Mertcan OZKAN csvRead.c*/
#include "csv_read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void set_dataset_size(FILE *file) {
	DATASET_SIZE = 0;
  	char buf[BUFFER_SIZE];
	while (fgets(buf, BUFFER_SIZE, file) ) {
		DATASET_SIZE++;
  }
	printf("%d\n\n\n\n",DATASET_SIZE);
	fseek(file, 0, SEEK_SET);
}
void set_possible_output_number(data_t* arr)
{
    int res = 1;
    // Pick all elements one by one
    for (int i = 1; i < TRAINING_DATA_SIZE; i++) {
        int j = 0;
        for (j = 0; j < i; j++)
            if (arr[i].output == arr[j].output)
                break;

        // If not printed earlier, then print it
        if (i == j)
            res++;
    }
    possible_output_number = res;
}
void set_input_size(FILE *file) {
  	char buf[BUFFER_SIZE];
	fgets(buf, BUFFER_SIZE, file);

	int field_count = 0;
        char *field = strtok(buf, ",");

	while (field) {
		field_count++;
		field = strtok(NULL, ",");

	}
	input_size = field_count - 1;
	fseek(file, 0, SEEK_SET);
}


data_t *read_csv(data_t *csv_data, int read_mode) {
  int counter = 0;
  char buf[BUFFER_SIZE + 1];
  FILE *file_csv = fopen("random.csv", "r");
  set_input_size(file_csv);
  set_dataset_size(file_csv);

  if(read_mode) {
  	csv_data = malloc(((TRAINING_DATA_SIZE) * ((input_size + 1)*sizeof(float))));
  } else {
	int i = 0;
	for(; i<TRAINING_DATA_SIZE; i++){
		fgets(buf, BUFFER_SIZE, file_csv);
	}
  	csv_data = malloc(((DATASET_SIZE-TRAINING_DATA_SIZE ) * ((input_size + 1)*sizeof(float))));
  }
  if (!file_csv) {

    printf("File could not be found\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(buf, BUFFER_SIZE, file_csv) ) {
	  if(read_mode == 1 && counter >=  TRAINING_DATA_SIZE)
		  break;
        char *field = strtok(buf, ",");
	int column = 0;
  	csv_data[counter].input = malloc(( ((input_size)*sizeof(float))));
        while (field) {
		if(column < input_size ) {
			csv_data[counter].input[column] = atof(field);
			column++;
		}else {
			csv_data[counter].output = atof(field);
		}
        		field = strtok(NULL, ",");
	}
	counter++;
  }
  if(read_mode)
  set_possible_output_number(csv_data);

  fclose(file_csv);


  return csv_data;

}

