#ifndef MODEL_21_NNOM_H
#define MODEL_21_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_21_nnom
#define APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT (0)
#define APP_ACTIVITY_RECOGNITION_SENSOR_SCALE (2)
#define APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION (8)
#define APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY (10)
#define APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER (0)
#define APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES (2)
#define APP_ACTIVITY_RECOGNITION_INPUT_SIZE (192)
#define APP_ACTIVITY_RECOGNITION_STEP_SIZE (32)
#define APP_ACTIVITY_RECOGNITION_CLASS_COUNT (6)

#ifdef INCLUDE_MODEL
static const float highpass_coefficients[] = {0.24075012569983611f, -0.24075012569983611f, 0.0f, 0.24074851273755382f, -0.0f, 0.25f, -0.5f, 0.25f, 0.49040304612512053f, -0.24075173866211835f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0 {-66, -31, -5, 14, 3, 24, 9, -38, -11, 4, -16, 6, -32, 26, 5, -16, 3, 59, 5, 28, -26, -7, 11, 16, -51, -22, -29, -26, -19, 29, -14, 10, -17, -5, -47, -4, 59, 16, -20, -18, 7, -5, -15, 0, 42, -25, -12, 14, -26, -39, -36, -16, 33, -54, 56, -35, 37, 3, 23, 3, 25, 44, -8, -3, -23, 25, 7, -25, 17, 3, -10, 1, 3, 6, 24, -17, 15, 33, 8, 4, 23, 5, -29, -21, -4, 61, 27, 16, -22, 1, -17, -47, -30, 21, -22, 29, -45, 35, -17, -24, -13, -24, -12, 29, 17, -18, 11, 0, 7, -31, -17, 30, 25, 41, -32, 28, -1, 3, 9, 10, -44, -10, -16, -26, 25, -17, -34, -32, -17, -9, -7, 8, -3, -29, -16, -27, -24, -9, 24, 15, -21, 9, -19, -1}

#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0 {-19, -16, 23, 19, -13, -7, -24, -16, 5, -5, -22, -34, -27, 1, 13, 16, 22, -6, -47, 28, -6, 7, -6, 37, -13, -23, 43, -16, -34, -7, 21, 1, -38, -3, -4, -2, 9, -22, 1, -18, 10, -23, -37, 0, -4, -44, 4, -30, 49, 33, -44, 16, -23, -22, -5, -6, -24, 21, 1, 0, -18, 11, -11, -25, 10, -48, -10, -34, -15, 47, -86, -29, 23, -11, -23, -21, -14, -8, 17, -30, 22, -7, 14, 39, -4, -21, 11, -23, 10, -18, -14, -31, -21, 8, -32, -31, 31, 8, 13, 9, 16, 9, 13, -3, 24, -72, -23, -13, -31, 50, 10, 21, 26, 31, -11, -15, -17, 0, 39, 6, 36, -34, 5, 49, 37, 15, 19, 14, 3, -15, 6, 10, -35, -43, -29, -7, -11, 9, 16, -25, -6, -11, -14, 34, -22, 16, 27, -7, 11, -31, -16, 1, -21, -8, 41, 9, -34, 31, 14, 27, -18, 6, -35, -12, 22, -30, -13, 0, -14, 24, -35, 36, -8, 40, 62, 20, 3, -33, -54, -10, 16, 15, 4, 18, -49, 9, -30, -2, 46, -6, 41, 42, -25, 28, 34, -5, 6, -11, 11, 29, 15, 5, -35, -18, 34, 61, 10, -33, 0, 51, -16, -7, -45, 30, -21, -34, 1, -13, 19, -9, 3, 22, -10, -15, -39, 5, -25, 38, 14, 7, -39, 36, -23, -7, 11, 1, 11, 38, 69, 31, 22, -2, -40, 13, 19, 0, 17, -19, 6, -48, 11, -21, 10, -13, -10, -22, 16, -3, -5, -12, -10, 1, 20, 13, -3, -7, -4, 29, -10, 23, 18, -36, -39, 15, 10, 22, -14, 18, 11, -24, -7, -28, 21, -7, 1, -3, -15, 0, 24, 26, -6, 4, -83, -1, -11, 34, -11, 7, 9, -5, -31, -11, 6, 37, -37, 0, -49, 34, -5, 20, 8, 33, 1, 5, 11, -8, -10, -10, -15, 11, 7, -26, -45, 9, -11, -12, -12, -40, 10, -3, 0, 13, 15, 0, -41, 24, 7, 41, 8, 14, 8, -21, -6, 25, -20, 25, -30, 4, -23, -18, -15, -35, -48, -39, -41, 1, 1, -23, -34, -13, 6, -20, 58, 2, 0, 0, -25, 18, -57, -5, 21, -3, -10, -4, -53, -18, -5, 1, -17, -23, 39, 21, 30, 3, -3, 6, 24, 9, 5, 4, -22, -39, 16, -6, 16, -21, -29, -6, 7, 9, 1, 18, 9, -24, -5, -11, -6, 27, -28, 22, -47, -34, 3, -45, 1, -9, 32, 3, 25, 28, 8, 25, -2, -13, 34, -5, 9, -2, 10, -26, -9, -2, 22, 27, 37, -15, -20, 2, -36, 43, 10, -17, 9, 13, -12, 34, 4, -8, -38, -38, -28, -6, -4, -21, -27, 7, -6, -13, 34, 40, -14, -30, -25, 24, 16, -6, 43, 25, -17, -8, 4, -33, -22, 20, -62, 37, -26, 21, 17, 62, 14, -7, 1, 9, 18, -42, -24, -3, -25, -5, 16, 12, 16, 2, 25, 0, 18, -1, 48, -38, -29, 3, -3, -51, 27, -22, -34, 20, 10, 2, 17, 4, 11, 12, 36, 22, -7, -7, 13, -6, 6, 1, -12, 20, -4, 37, -14, -3, 15, 4, -24, 11, -17, 2, -1, -29, 20, -24, 8, 1, -46, 4, -21, -5, -9, -1, 36, 2, -2, -2, -19, -3, -16, -27, -14, -22, -14, -3, -10, 38, 2, -16, -2, 30, 3, 27, 17, 16, -45, -1, -12, 15, -12, -26, 15, 0, -14, 6, -23, 19, -19, 7, 21, 2, 20, 14, -11, -29, 22, 35, 2, -8, 2, 2, 1, -13, 0, 8, -28, -8, -13, 5, 11, -2, 38, 1, -10, 9, 25, -33, -24, 7, -20, -3, 5, -34, -29, 4, -26, -5, 16, 2, 35, -6, 13, -7, -19, -7, 1, 13, 0, -18, -22, -35, -26, -2, -6, 14, 2, 9, -16, -16, -19, 22, 35, -13, 12, -9, -6, 0, -13, -6, 21, 15, -12, 2, -26, 25, 10, -7, 9, -4, 0, 23, -11, -3, 27, 27, -15, -22, -8, 9, -14, -9, -33, -4, 16, 20, 12, 3, -2, -5, -2, -1, 11, -3, 27, 4, -20, -6, -14, -30, 2, 17, 21, 4, -8, -18, 14, -1, 18, 21, 13, 23, 16, -2, -10, -2, 33, -7, -26, -11, -20, 9, -32, 43, 20, 5, -29, -20, -16, -4, -18, 44, 15, 54, 18, 19, -7, 0, -11, 17, 12, -10, -24, 23, 7, -27, -22, -8, 19, 29, 3, -4, -27, -4, -15, -3, 2, -14, 25, -5, 3, 5, -3, 11, 17, 12, 16, -13, -14, -12, 13, 7, -6, -18, 4, 17}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0 {-13, -37, -41, -47, -34, -84, -44, -24, -15, -52, -10, -35, -45, -49, -61, 23, 22, -14, 13, -12, 13, -27, -12, -34, -13, 12, -4, -33, -31, -34, 10, 6, 6, -3, 4, -7, -9, -1, 6, 2, 10, -4, 6, -4, -1, -1, 1, -3, -13, -37, -41, -47, -34, -84, -44, -24, -15, -52, -10, -35, -45, -49, -61, 23, 22, -14, 13, -12, 13, -27, -12, -34, -13, 12, -4, -33, -31, -34, 10, 6, 11, 7, 1, 1, 15, -8, 5, 9, 1, 5, -10, -7, -3, -3, -11, -3}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0_DEC_BITS {6}

#define GRU_3_BIAS_LSHIFT {5}

#define GRU_3_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0 {37, -8, -15, -11, 1, -10, -9, -22, -25, 0, 0, 11, 13, -9, 18, 40, -28, -15, 9, 23, -11, -10, 22, 22, 1, -34, 9, 4, -2, 2, -16, 6, 13, -22, 16, -36, -20, 1, 19, -10, -2, -7, -1, -19, 1, -4, 9, -5, -7, -12, -1, -8, -1, -22, 16, 7, -3, 0, -3, 12, 15, 17, 22, -5, 0, -11, -25, 18, 11, 4, -13, 11, 1, 20, 17, -17, 17, -1, 3, -3, -3, 1, 24, -1, -15, -3, 11, -2, 0, -11, 8, -43, 4, 7, -10, 5, 19, -12, -2, 9, 8, -15, -26, -2, -2, -10, -7, 0, 6, 16, 7, -13, -5, 37, -14, 16, 19, 11, -20, 25, 4, -8, -10, 1, 24, 5, 50, -27, 39, -14, -18, -5, -40, -3, 15, -3, -16, 6, 35, 9, 57, -9, -24, -5, -32, 4, 29, 2, 69, 17, -22, -18, -27, -10, -5, 7, 19, 11, 14, 11, 13, -19, 3, -8, -5, -26, 25, -13, -22, 0, -13, -2, 2, -13, -3, -13, -18, -2, -4, 9, 30, 1, 1, -6, 14, 2, 26, 9, -37, -8, -21, -21, 19, 1, 19, -6, -6, 9, -6, -16, -5, 4, -17, -1, -12, -10, 18, 16, -10, 7, 13, -11, 0, -33, 14, 44, -3, 8, -10, 10, -20, -7, 11, 23, -16, -8, 2, 15, 7, 10, 5, -22, 12, 23, 0, 33, 5, -4, 5, -18, 0, 4, 10, 1, 5, -19, -10, -10, 19, 19, 15, 12, 16, -14, 22, -2, -3, -15, 6, -21, 8, 7, 18, 16, 11, -11, 3, 13, 16, 10, -15, 8, -6, 11, -5, 32, -2, -5, -6, -15, -6, -5, 10, 11, -5, 11, -2, -8, 12, -30, 13, -11, 2, 8, -1, -16, -3, -28, 43, -35, 13, 40, 14, -5, 35, -16, -9, -18, 14, 24, 7, 16, 27, -19, 18, -29, 25, 6, 16, -9, -9, 21, -38, -11, -3, -4, 0, -17, -35, -1, -4, 19, 9, -8, 18, -8, 6, -7, -18, 8, 4, 13, -9, 19, 41, -6, -4, 27, -6, -11, 11, 15, 8, 11, -21, -16, -10, -2, -2, 18, 25, 34, 15, -16, -2, -33, -4, 11, 21, -11, -3, -22, 3, 2, -2, 7, 31, 14, -10, -1, -2, -8, 13, 14, 6, 10, -23, 2, 1, 11, -11, -8, -6, 5, 21, -11, 0, -6, -11, 15, 0, -11, 10, -5, 3, -4, 15, 10, -14, 12, 2, 7, 6, -15, -13, 19, 11, 3, 11, -9, 18, 20, 0, -8, -18, 9, -12, -24, 7, -2, -2, -19, -7, 12, 3, -18, -2, -13, -4, 0, 12, -9, 6, -5, 14, 10, 10, -8, -9, 8, 0, 16, -1, -21, 17, -5, 5, -3, 1, -17, 22, 3, -15, 0, 5, 14, 7, -31, 14, -20, -7, 14, -12, 19, -5, -9, 14, -15, 4, 6, -11, 1, -16, 14, -7, -3, 3, -20, 2, 18, -29, 18, 3, -10, 19, 9, -9, 4, -1, 4, 19, -1, 14, -13, -5, -5, -11, 3, -12, 15, -8, -3, 12, -14, -3, 12, -11, -1, 10, -9, -17, 7, 0, -5, 22, -1, -15, 2, -35, -8, -2, 2, 32, 14, -8, -2, -5, 4, -6, -8, 17, 11, 4, 10, -2, -3, -18, 6, 3, 9, 20, 11, 5, 0, -12, 18, 6, -12, 20, -4, -21, -13, 4, 3, 23, 2, -2, 0, 15, -4, -2, 3, -24, -13, -3, -7}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0 {-29, -28, 53, -19, -19, -23, -14, 13, -10, 29, -23, -7, -22, 13, -38, -27, -24, 2, 68, -4, 6, 16, -3, 20, 43, 20, -27, -9, 18, 17, -10, 7, -8, 6, 6, 12, 17, -10, -23, 19, 19, -14, 11, 5, 13, 42, 14, 5, -26, 23, 9, 50, -7, 14, 35, -33, -19, 17, -14, 7, 6, -24, 6, -34, -38, 9, -28, -6, -39, -21, 62, -26, 15, -28, -15, 13, 25, -53, -66, -6, -1, 26, -55, 2, 25, 13, 27, 28, -17, 3, 11, 31, 22, -18, 20, -18, 8, -17, -17, 19, -2, -5, 48, -3, 40, -5, 1, -19, 11, 8, 64, 48, -18, -32, 53, 1, 27, -20, -47, -20, -6, 17, -63, -1, -60, 0, 58, 3, -24, -14, 15, -32, 13, -8, -8, 1, 36, 7, 8, 9, -49, -1, 18, 2, 9, 1, -9, 32, -29, 28, 43, 15, -15, 16, -14, -6, 23, 14, 31, 1, -2, -46, 37, 5, 24, -3, 5, 19, 12, 28, 8, -12, -9, 35, 13, -1, 9, 13, 27, 22, 23, 13, -48, -27, 10, -1, -30, 8, -3, 4, -16, 21, 7, -14, -15, 2, 13, 19, -34, -28, -10, -56, -3, -51, 2, 44, 10, 44, -21, -15, 29, -39, -8, 14, 9, -22, -11, 16, 28, -14, -6, -21, 12, 0, 24, -15, 19, -35, 14, 25, -9, 12, 20, -11, -82, 19, 5, -5, -38, -36, -36, -2, 27, -6, 54, -38, 16, -35, -12, 39, -33, 60, 10, 5, 8, 4, 43, -11, 97, 3, 3, 17, -4, 8, -15, 9, -1, -21, 3, 15, 13, 2, 37, 11, 9, -37, 6, 12, 30, -34, 49, 6, -21, 16, 29, 9, -16, 24, 32, -8, 5, 23, -3, -8, -2, -6, 13, -19, 7, 7, -3, 23, 52, 10, -13, -14, -4, 47, 11, -5, 9, -47, -40, -12, 1, -8, 5, -7, -3, 33, -24, 9, -2, -5, -1, -1, -25, -19, 29, 18, -12, 17, -3, -8, 28, -6, 0, 11, 11, -30, 2, 3, 7, 29, 21, 4, 11, 23, -12, 3, -7, -11, 27, 23, 4, -15, 23, -12, -8, -6, -33, -19, 13, -2, 23, -55, 31, 21, 16, -8, 17, -1, -29, 3, -10, 13, 6, 7, -5, -25, -15, 9, 10, -4, 33, 18, -1, 40, 19, -3, -1, -11, 6, 43, 3, 20, -4, 20, 5, 21, -60, -9, 16, 24, 43, 16, -6, 22, 37, -23, -34, -17, -6, 17, 43, -16, 32, 9, -6, 25, 39, 15, 5, -17, 27, 16, -1, 17, 4, -7, -6, 5}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0 {88, 47, 7, 20, 34, -29, -12, -41, 24, 63, 31, 37, -2, -1, -33, -47, -38, -3, 4, -18, -37, 1, -16, -23, -5, 10, 1, 17, 6, 6, 6, -8, 8, -5, -5, 9, 88, 47, 7, 20, 34, -29, -12, -41, 24, 63, 31, 37, -2, -1, -33, -47, -38, -3, 4, -18, -37, 1, -16, -23, -2, 12, -2, 5, -11, -20, 9, -24, 6, 5, -2, 21}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0_DEC_BITS {6}

#define GRU_4_BIAS_LSHIFT {5}

#define GRU_4_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0 {-23, 1, 26, 14, -2, -31, 6, 7, 25, 18, 62, 31, 23, -17, 21, 18, -2, 27, -7, 37, 14, 21, -50, 26, 24, 37, -54, -22, 12, 14, 24, -42, -21, 6, -15, -3, -5, -16, -5, 21, -32, -12, 5, 28, -14, -10, 37, 19, 0, -4, 24, 28, 9, -42, -1, 6, -2, 5, 31, 6, -10, 26, -3, -5, -2, 26, 0, 1, 6, 15, -24, 61, -10, 1, -39, -25, 2, 57, 30, -26, -11, 9, 15, -16, 9, 14, -6, -5, -23, -34, 37, 29, -14, 29, -1, 43, -4, 4, 16, 0, 27, -57, -13, -27, 21, -44, 1, -25, 2, 5, -5, -34, -17, 5, -15, -29, -48, -24, -8, -26, 30, -6, -3, 10, -44, -6, -3, -36, -4, -28, 12, 25, 34, -33, 10, -33, -5, -6, 19, -18, 74, -41, -6, 16, -5, -15, 23, -67, -41, -55, -76, -45, 68, -33, 28, -47, 0, -60, -34, -58, 14, 5, 14, -19, 24, 22, 3, -25, 2, -20, -1, 61, 6, 35, -4, -12, 7, -13, -9, -6, -27, -33, -15, -13, 10, -16, 10, -7, -11, -42, 42, 5, -4, -45, -16, -23, -5, 19, -14, 13, 8, -38, 4, 5, -31, 13, -17, 20, -51, 22, 10, -14, -54, -4, -1, 25, 28, -12, -36, 0, 20, 8, 14, -48, 16, 23, -32, -20, 21, -60, -28, -52, 0, 19, -6, 3, -2, -10, -22, 33, -28, -4, -16, 5, -16, 17, 18, 5, -33, 12, -13, -10, 35, 12, 32, -7, -11, -11, -25, 4, 10, -10, 25, -1, 24, 19, -8, 31, 3, 25, -19, 17, -16, 5, 4, -13, 22, -2, -24, -14, -51, 12, -17, 15, 3, -21, 12, -46, -12, 0, -2, -12, 10, 19, 17, 9, -26, -1, -9, 6, 12, 1, 2, 48, -24, 6, 14, -6, -44, -10, 10, -4, 9, 3, 6, -26, 5, -8, -14, -12, -21, 3, 2, -72, 12, 9, 15, -21, -12, -8, -41, 13, 8, 24, -14, 4, 7, 12, -10, -14, 53, 2, -26, 15, 9, 11, 13, 3, 11, 26, 34, 14, -18, -11, -2, -11, -7, -13, -3, 1}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0 {4, 29, -13, -34, 33, 22, -6, 28, 23, -10, 3, -10, 8, 3, 3, 0, -13, -3, 1, 6, 37, 37, 0, -11, 4, 14, 2, -9, 26, -17, 12, -9, -26, -19, 12, 10, -30, -17, -23, 29, 13, 25, 9, 2, 5, 48, 16, 16, 0, -1, -9, 3, -6, 4, -6, -51, 20, 5, 0, -28, 3, 32, 0, 36, 19, -5, -7, -3, 16, 25, 9, -17, -4, -24, -10, -3, -9, -36, -17, 1, 28, 3, -10, -4, 35, 40, -18, -20, -1, 0, 17, 27, -22, -5, 4, 1, 1, -27, -34, 25, 14, -6, -3, 31, 12, -32, -8, 14, 1, -9, -18, -68, 1, -31, 7, 33, -7, -14, 24, 23, -13, 42, 0, -4, 27, 37, -29, 46, 38, -49, -7, -1, -31, 2, -44, 20, -11, 12, -27, 15, -19, -39, -9, 33, -16, 2, 47, -61, -27, -17, -59, -12, 13, 1, -15, -1, 9, -13, -10, -5, 5, 15, 11, 20, 9, -9, -1, -3, -17, 6, 17, -7, -22, 6, 5, 2, 18, 47, 0, -31, 23, -10, 29, 27, 35, -5, -3, -16, -18, 1, 12, -29, -39, 11, 13, -29, -1, 7, -6, 45, 38, 12, -38, 20, 7, -26, -7, -5, -21, 51, 16, -8, 5, -3, -17, 3, 30, 10, 7, -1, -8, 5, -6, -26, -13, 25, -8, 27, 21, -8, 16, 10, -11, -5, -1, -2, -8, 10, 24, -17, -15, -7, -16, -10, 4, 20, -22, 4, -32, 20, 5, 5, -25, -2, 21, 32, 24, -23, -12, 7, 28, 26, -14, -21, -29, -2, -6, -3, -3, 16, -2, -15, 11, -12, -17, 26, -13, -4, -3, -16, -12, -6, -2, 3, 9, 4, -28, 19, 29, -18, 27, -29, -23, 58, 25, 0, 23, -9, -13, -2}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0 {64, 69, 74, 65, 79, 57, 55, 50, 78, 56, -6, -14, -1, -13, -1, -19, -6, -32, -31, -18, 6, -8, 15, -6, -11, -18, 23, 9, -20, 14, 64, 69, 74, 65, 79, 57, 55, 50, 78, 56, -6, -14, -1, -13, -1, -19, -6, -32, -31, -18, 3, 11, 12, -17, -31, 18, 7, 5, -15, -9}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0_DEC_BITS {6}

#define GRU_5_BIAS_LSHIFT {6}

#define GRU_5_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_3_KERNEL_0 {22, -3, -10, 2, -5, -24, -37, 23, -44, -5, 26, 15, -31, 18, -42, 26, 33, 52, -35, 33, -10, 19, 2, -14, -49, -57, -16, 5, 30, 53, -31, 2, 67, -24, -17, -18, 7, -39, 41, 33, -46, 8, 21, -30, -9, -30, -21, 23, 70, -9, 30, 41, 23, -29, -38, 11, -31, -17, -4, -23}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_3_BIAS_0 {-78, -93, -31, 6, 16, 60}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {8}

#define DENSE_3_BIAS_LSHIFT {4}

#define DENSE_3_OUTPUT_RSHIFT {9}


/* output q format for each layer */
#define GRU_3_INPUT_OUTPUT_DEC 7
#define GRU_3_INPUT_OUTPUT_OFFSET 0
#define GRU_3_OUTPUT_DEC 7
#define GRU_3_OUTPUT_OFFSET 0
#define GRU_4_OUTPUT_DEC 7
#define GRU_4_OUTPUT_OFFSET 0
#define GRU_5_OUTPUT_DEC 7
#define GRU_5_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 3
#define DENSE_3_OUTPUT_OFFSET 0
#define SOFTMAX_3_OUTPUT_DEC 7
#define SOFTMAX_3_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {7};
const nnom_qformat_param_t tensor_Placeholder_0_offset[] = {0};
const nnom_tensor_t tensor_Placeholder_0 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_Placeholder_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_Placeholder_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_Placeholder_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_io_config_t gru_3_input_config = {
    .super = {.name = "gru_3_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_3_gru_cell_3_kernel_0_data[] = TENSOR_GRU_3_GRU_CELL_3_KERNEL_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_kernel_0_dim[] = {3, 48};
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_kernel_0_dec[] = TENSOR_GRU_3_GRU_CELL_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_3_gru_cell_3_kernel_0 = {
    .p_data = (void*)tensor_gru_3_gru_cell_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_3_gru_cell_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_data[] = TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_dim[] = {16, 48};
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_dec[] = TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_3_gru_cell_3_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_3_gru_cell_3_bias_0_data[] = TENSOR_GRU_3_GRU_CELL_3_BIAS_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_bias_0_dim[] = {2, 48};
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_bias_0_dec[] = TENSOR_GRU_3_GRU_CELL_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_3_gru_cell_3_bias_0 = {
    .p_data = (void*)tensor_gru_3_gru_cell_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_3_gru_cell_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_3_gru_cell_config = {
    .super = {.name = "gru_3"},
    .weights = (nnom_tensor_t*)&tensor_gru_3_gru_cell_3_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_3_gru_cell_3_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_3_gru_cell_3_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 16
};

const nnom_rnn_config_t gru_3_config = {
    .super = {.name = "gru_3"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_4_gru_cell_4_kernel_0_data[] = TENSOR_GRU_4_GRU_CELL_4_KERNEL_0;

const nnom_shape_data_t tensor_gru_4_gru_cell_4_kernel_0_dim[] = {16, 36};
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_kernel_0_dec[] = TENSOR_GRU_4_GRU_CELL_4_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_4_gru_cell_4_kernel_0 = {
    .p_data = (void*)tensor_gru_4_gru_cell_4_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_4_gru_cell_4_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_data[] = TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_dec[] = TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_4_gru_cell_4_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_4_gru_cell_4_bias_0_data[] = TENSOR_GRU_4_GRU_CELL_4_BIAS_0;

const nnom_shape_data_t tensor_gru_4_gru_cell_4_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_bias_0_dec[] = TENSOR_GRU_4_GRU_CELL_4_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_4_gru_cell_4_bias_0 = {
    .p_data = (void*)tensor_gru_4_gru_cell_4_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_4_gru_cell_4_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_4_gru_cell_config = {
    .super = {.name = "gru_4"},
    .weights = (nnom_tensor_t*)&tensor_gru_4_gru_cell_4_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_4_gru_cell_4_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_4_gru_cell_4_bias_0,
    .q_dec_z = 2,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_4_config = {
    .super = {.name = "gru_4"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_5_gru_cell_5_kernel_0_data[] = TENSOR_GRU_5_GRU_CELL_5_KERNEL_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_kernel_0_dim[] = {12, 30};
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_kernel_0_dec[] = TENSOR_GRU_5_GRU_CELL_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_5_gru_cell_5_kernel_0 = {
    .p_data = (void*)tensor_gru_5_gru_cell_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_5_gru_cell_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_data[] = TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_dim[] = {10, 30};
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_dec[] = TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_5_gru_cell_5_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_5_gru_cell_5_bias_0_data[] = TENSOR_GRU_5_GRU_CELL_5_BIAS_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_bias_0_dim[] = {2, 30};
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_bias_0_dec[] = TENSOR_GRU_5_GRU_CELL_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_5_gru_cell_5_bias_0 = {
    .p_data = (void*)tensor_gru_5_gru_cell_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_5_gru_cell_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_5_gru_cell_config = {
    .super = {.name = "gru_5"},
    .weights = (nnom_tensor_t*)&tensor_gru_5_gru_cell_5_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_5_gru_cell_5_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_5_gru_cell_5_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 10
};

const nnom_rnn_config_t gru_5_config = {
    .super = {.name = "gru_5"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_3_kernel_0_data[] = TENSOR_DENSE_3_KERNEL_0;

const nnom_shape_data_t tensor_dense_3_kernel_0_dim[] = {10, 6};
const nnom_qformat_param_t tensor_dense_3_kernel_0_dec[] = TENSOR_DENSE_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_3_kernel_0 = {
    .p_data = (void*)tensor_dense_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_3_bias_0_data[] = TENSOR_DENSE_3_BIAS_0;

const nnom_shape_data_t tensor_dense_3_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_3_bias_0_dec[] = TENSOR_DENSE_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_3_bias_0 = {
    .p_data = (void*)tensor_dense_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_3_output_shift[] = DENSE_3_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_3_bias_shift[] = DENSE_3_BIAS_LSHIFT;
const nnom_dense_config_t dense_3_config = {
    .super = {.name = "dense_3"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_3_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_3_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_3_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_3_bias_shift
};

const nnom_softmax_config_t softmax_3_config = {
    .super = {.name = "softmax_3"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_3_OUTPUT_DEC};
const nnom_qformat_param_t tensor_output0_offset[] = {0};
const nnom_tensor_t tensor_output0 = {
    .p_data = (void*)nnom_output_data,
    .dim = (nnom_shape_data_t*)tensor_output0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_output0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_output0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_io_config_t output0_config = {
    .super = {.name = "output0"},
    .tensor = (nnom_tensor_t*)&tensor_output0
};
/* model version */
#define NNOM_MODEL_VERSION (10000*0 + 100*4 + 3)

/* nnom model */
static nnom_model_t* nnom_model_create(nnom_status_t *state)
{
	static nnom_model_t model;
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&gru_3_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_3_gru_cell_config), &gru_3_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_4_gru_cell_config), &gru_4_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_5_gru_cell_config), &gru_5_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_3_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_3_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_21_NNOM_H