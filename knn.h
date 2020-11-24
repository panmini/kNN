/* Mertcan OZKAN - kNN.h */

#ifndef KNN_h
#define KNN_h
extern int intput_size;
extern int possible_output_number;
extern int DATASET_SIZE;
extern float accuracy_rate;
typedef struct vector_t{

	double vectorLength;
	int type;

} vector_t;

void *evaluate_distance(data_t*, data_t, int);
float nearest_neighbors(vector_t*);
data_t read_user_input();
int sort_data(const void*, const void*);



#endif
