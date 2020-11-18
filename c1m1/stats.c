/**
 * @file stats.c
 * @brief Display an array as well as its max, min, mean, and median.
 *
 * Program defines an array of 40 unsigned chars. The values are displayed,
 * sorted, and then displayed again. Finally, some statistics, maximum value,
 * minimum value, mean, and median are calculated and displayed.
 *
 * @author Arian Deimling
 * @date November 11, 2020
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* print the array before any changes are made */
  printf("Original Array:\n\n");
  print_array(test, SIZE);
  puts("\n");

  /* sort the array */
  sort_array(test, SIZE);

  /* print the sorted array */
  printf("Sorted Array:\n\n");
  print_array(test, SIZE);
  puts("\n");

  /* print statistics for the array */
  print_statistics(test, SIZE);
}

void sort_array(unsigned char arr[], unsigned short size) {

  /* holds one value from the array while swapping two values */
  unsigned char temp;

  /* boolean value to determine when the list is sorted */
  unsigned short sorted = 0;

  /* the max number of iterations of bubble sort required is
   * `size - 1` for the worst case scenario
   */
  for (unsigned short iter = 0; (iter < size - 1) && 
                                (!sorted); iter++) {

    /* list is assumed to be sorted unless proven otherwise */
    sorted = 1;

    /* iterate over all of the values in the array except the last
     * value because we are looking at pairs; no need to iterate
     * over values that have already be sorted
     */
    for (unsigned short i = 0; i < size - 1 - iter; i++) {

      /* if the current value is smaller than the next, swap them
       * so the smallest values in the array move towards teh end
       */
      if (arr[i] < arr[i + 1]) {

        /* the list was not sorted before this iteration started */
        sorted = 0;

        /* temporarily store the smaller value to be swapped */
        temp = arr[i];

        /* move the larger value into the smaller index */
        arr[i] = arr[i + 1];

        /* move the smaller value into the larger index */
        arr[i + 1] = temp;
      }
    }
  }
}

void print_array(unsigned char arr[], unsigned short size) {

  /* print open bracket which indicates the start of the array */
  printf("%s", "[");

  /* iterate over all the indices of the array except the last */
  for (unsigned short i = 0; i < size - 1; i++) {

    /* print the value of the array at index i */
    printf("%3d, ", arr[i]);

    /* print a newline after each 10 numbers unless we just printed
     * the last number in the array
     */
    if (((i + 1) % 10 == 0) && (i + 1 < size)) {
      printf("%s", "\n ");
    }
  }

  /* print final element in the array with closing bracket */
  printf("%3d]\n", arr[size - 1]);
}

unsigned char find_median(unsigned char arr[], unsigned short size) {

  /* make sure the array is sorted */
  sort_array(arr, size);

  /* list has an odd number of elements, return the middle one */
  if (size % 2 == 1) {
    return arr[size / 2];
  
  /* list has an even number of elements, return the half rounded
   * up average of the two middle values
   */
  } else {
    return (arr[size / 2] + arr[size / 2 - 1] + 1) / 2;
  }
}

unsigned char find_mean(unsigned char arr[], unsigned short size) {

  unsigned short sum = 0;

  /* sum all the numbers in the array into `sum` */
  for (unsigned short i = 0; i < size; i++) {
    sum += arr[i];
  }

  /* return the half rounded up average */
  return (sum + size / 2) / size;
}

unsigned char find_maximum(unsigned char arr[], 
                           unsigned short size) {
  
  /* set the value of `maximum` to the value of the 0th element
   * and then replace it with any value found to be higher
   */
  unsigned char maximum = arr[0];
  for (unsigned short i = 0; i < size; i++) {
    if (arr[i] > maximum) {
      maximum = arr[i];
    }
  }

  return maximum;
}

unsigned char find_minimum(unsigned char arr[],
                           unsigned short size) {

  /* set the value of `minimum` to the value of the 0th element
   * and then replace it with any value found to be lower
   */
  unsigned char minimum = arr[0];
  for (unsigned short i = 0; i < size; i++) {
    if (arr[i] < minimum) {
      minimum = arr[i];
    }
  }

  return minimum;
}

void print_statistics(unsigned char arr[], unsigned short size) {

  printf("%s", "Here is a summary of statistics for the array:\n");
  printf("%-8s %d\n", "Mean:", find_mean(arr, size));
  printf("%-8s %d\n", "Median:", find_median(arr, size));
  printf("%-8s %d\n", "Maximum:", find_maximum(arr, size));
  printf("%-8s %d\n", "Minimum:", find_minimum(arr, size));
}

/******************************************************************************
 * File format and guidelines were provided by the Coursera teacher; the
 * implementation of the features of this program were added by the author
 * noted above.
 *****************************************************************************/

/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
