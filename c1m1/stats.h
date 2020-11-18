/**
 * @file stats.h
 * @brief Declare functions to analyze and manipulate an array.
 *
 * Declare a series of functions which will be implemented in the stats.c
 * source file such as print statistics, print array, find mean, etc.
 *
 * @author Arian Deimling
 * @date November 10, 2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Sorts an array of unsigned chars.
 *
 * Provided and array of unsigned chars and its size, the function
 * sort the data using the bubble sort method. The list will be 
 * modified in place with larger numbers towards the beginning of
 * the list.
 *
 * @param arr an array of unsigned char types
 * @param size the number of elements in the array
 *
 * @return void
 */
void sort_array(unsigned char arr[], unsigned short size);

/**
 * @brief Prints out values of an array.
 * 
 * Print out an array of a specified size with 3 width spacing
 * for each number, and with 10 numbers displayed per line.
 * 
 * @param arr an array of unsigned char types
 * @param size the number of elements in the array
 * 
 * @return void
 */
void print_array(unsigned char arr[], unsigned short size);

/**
 * @brief (Sorts and) finds the median of an array.
 * 
 * This function relies on how the median is positioned in a
 * sorted array, and thus, to ensure correct calculation, the
 * function calls the sort_array() function. It returns the 
 * (half up) rounded median to the closest integer.
 * 
 * @param arr an array of unsigned char types
 * @param size the number of elements in the array
 * 
 * @return the median of the sorted list
 */
unsigned char find_median(unsigned char arr[], unsigned short size);

/**
 * @brief Calculate the average of an array.
 * 
 * This function calculates and returns the average value of an 
 * array rounded (half up) to the closest integer. The function
 * will overflow if the sum of the values in the array reaches
 * 65,536.
 * 
 * @param arr an array of unsigned char types
 * @param size the number of elements in the array
 * 
 * @return the mean/average of the sorted list
 */
unsigned char find_mean(unsigned char arr[], unsigned short size);

/**
 * @brief Find the largest value in an array.
 * 
 * Finds and returns the largest value in a given array.
 * 
 * @param arr an array of unsigned char types
 * @param size the number of elements in the array
 * 
 * @return the largest/maximum value of an array
 */
unsigned char find_maximum(unsigned char arr[], unsigned short size);

/**
 * @brief Find the smallest value in an array.
 * 
 * Finds and returns the smallest value in a given array.
 * 
 * @param arr an array of unsigned char types
 * @param size the number of elements in the array
 * 
 * @return the smallest/minimum value of an array
 */
unsigned char find_minimum(unsigned char arr[], unsigned short size);

/**
 * @brief Print median, mean, max, and min of an array.
 * 
 * By making calls to the find_ZZZZ() functions above, this function
 * gathers values of various statistics associated with the array and
 * prints out the values along with indicators of what value is being shown.
 * 
 * @param arr an array of unsigned char types
 * @param size the number of elements in the array
 * 
 * @return Void
 */
void print_statistics(unsigned char arr[], unsigned short size);

#endif /* __STATS_H__ */

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
