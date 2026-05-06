#ifndef BUCKET_H
#define BUCKET_H

#include "types.h"
#include <stdlib.h>
#include <stdbool.h>
#include "infotools.h"

bucket_t* init_buckets(info_t togivesize);

int* bucketp(bucket_t b, int t);

int len(bucket_t* b, int val);

int valueupuntilhere(bucket_t* bp, info_t info, int bucket, int index);
int timeupuntilhere(bucket_t* bp, info_t info, int bucket, int index);

int bucketposition(bucket_t b, int bucket, int index);
int remainingtime(bucket_t b, info_t info, int bucket);

int local_insertion_val(bucket_t b, info_t info, int bucket, int item);
bool no_overlap_in_buckets(bucket_t b, int bucketcount);
bool everything_placed_in_buckets(bucket_t b, int bucketcount);

#endif