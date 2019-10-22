#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "event.h"

void test_sort( int32_t data[], uint32_t len)
{
    uint32_t idx;
    for (idx = 1; idx <= len; ++idx) {
        assert (data[idx] >= data[idx+1]);        
    }
}

Event** create_random_flights(){
    Event** data  = (Event**) malloc(6*sizeof(Event*));
    

data[1] = malloc(sizeof(Event));
    data[1]->timestamp = 200;
    data[1]->plane_no = 123;
    data[1]->t_or_l = TAKEOFF;

data[2] = malloc(sizeof(Event));

    data[2]->timestamp = 100;
    data[2]->plane_no = 124;
    data[2]->t_or_l = LANDING;

data[3] = malloc(sizeof(Event));

    data[3]->timestamp = 550;
    data[3]->plane_no = 134;
    data[3]->t_or_l = LANDING;

data[4] = malloc(sizeof(Event));
    data[4]->timestamp = 50;
    data[4]->plane_no = 234;
    data[4]->t_or_l = TAKEOFF;

    data[5] = malloc(sizeof(Event));
    data[5]->timestamp = 0;
    data[5]->plane_no = 12;
    data[5]->t_or_l = LANDING;
    return data;
}

void test_heap()
{
    Event** evnt = create_random_flights();
    Heap heap = heap_new(evnt, 5);    
    assert(heap_get_min(&heap)->timestamp == 0);
    assert(heap_extract_min(&heap)->timestamp == 0);
    // heap_insert(&heap, 47);
    // assert(heap_size(&heap) == 11);
    // heap_test(&heap);
    // assert(heap_get_min(&heap) == 7);
    // assert(heap_extract_min(&heap) == 7);
    // heap_test(&heap);
}