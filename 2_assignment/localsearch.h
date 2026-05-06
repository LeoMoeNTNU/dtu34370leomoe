#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include "types.h"
void loc_search(bucket_t* bp, info_t info, int iterations, int localsearchspace);
bucket_t* grasp(info_t info,int timetospend, int things);

#endif