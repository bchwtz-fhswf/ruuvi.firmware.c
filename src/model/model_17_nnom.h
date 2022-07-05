#ifndef MODEL_17_NNOM_H
#define MODEL_17_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_17_nnom
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
#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0 {2, -54, -12, -12, -7, -47, 19, 34, -17, -41, -12, 60, -56, -19, 16, 32, -11, -6, -19, 15, 22, 57, -74, -51, -71, -92, 14, 50, 42, 32, -85, -26, 27, -61, 45, -22, -2, 83, -9, -43, -9, -23, 48, -1, 57, 23, 12, -41, 8, 53, 39, -7, -77, 99, 38, 62, 50, -8, -17, 41, 1, -4, -71, 16, -20, 38, -7, 56, -21, -17, -31, 49, -108, -84, 7, -29, 59, 26, 8, 34, -50, 0, 42, -4, 30, -70, 2, -90, 44, -43, 7, 52, 2, -51, 10, -26, 13, -22, 29, -1, -26, -55, -48, 40, 25, 31, 0, 9, -7, -9, -27, -41, 15, 34, 39, 39, 45, -18, 20, 0, -40, 23, 18, -46, 55, -33, 2, 42, 5, 16, 11, 12, 44, 27, -4, -40, -26, 12, -32, 35, -43, 10, 8, -25}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0 {-10, 25, -3, -4, -25, 19, 16, -32, 13, -16, -5, 24, 3, -63, 9, -28, -33, -16, 19, 0, 12, -25, 29, -7, -6, 18, -29, 15, -4, 17, -26, 50, -7, 12, 12, 5, -12, -49, 33, 25, -13, 22, 14, 12, 13, 46, -18, -12, 14, 23, -30, -9, -11, 37, 24, 15, 28, 2, 8, 13, 44, 9, -29, 7, 27, -7, -38, 17, 19, 4, 20, 4, -23, 43, -11, -30, -14, -12, 0, 1, -30, -16, -4, 19, -32, -7, 1, 25, -18, -52, 19, -34, 11, -3, -1, -11, 13, -9, 7, 12, 7, -39, -7, 28, 11, -5, 14, -34, -23, 22, 15, -12, 14, 43, -23, 17, 29, 13, -36, 5, -14, 17, 30, 2, 13, 28, 32, -13, 32, 25, -38, 1, 3, 30, -5, 15, 19, 23, 6, -2, 8, 15, 31, 1, -24, -16, -1, 19, -30, 6, -3, -29, -6, -28, -1, -31, 10, -17, -8, 9, -3, -15, -8, 15, 73, 9, -29, -40, 24, 15, 26, -13, -22, -7, 31, 18, -4, 18, 15, 19, 1, -8, -49, -17, 12, 36, 0, -2, -13, -3, 25, -14, 14, 26, -20, -12, -8, 19, -3, 3, -1, -14, 4, -24, 70, 9, -12, -19, -41, -33, 2, -7, 19, -17, 24, 1, 0, 15, -9, 23, -46, -4, -37, -13, -5, 6, -4, -30, -20, -22, 18, 4, -11, -45, 27, 15, 4, -2, -29, 13, -26, 17, -1, -41, 34, 4, 12, -8, 4, -8, 16, 21, 17, 12, -15, 6, 15, 40, 88, -18, 20, -14, 31, -20, -32, 55, -23, -45, -26, 26, 14, -30, -19, 24, -5, -38, 34, -14, -8, 6, 11, -43, 14, 18, 3, -22, 22, -26, -29, -11, -47, -2, 19, -14, -16, 2, -46, 42, 19, -63, 15, -10, -16, 5, 27, 11, -20, 44, 36, -14, 21, -3, -1, -51, -8, -8, -10, 2, 11, -5, 4, 26, 25, -17, 22, -12, 31, 14, 2, -20, 7, 29, -33, 2, 11, 24, 1, 14, -14, -29, 12, 7, -24, -6, 12, 13, -8, 28, 27, 11, 62, -6, 16, 18, -40, -26, 13, 1, -9, 3, -53, 23, 19, 22, -2, 15, -11, -2, 3, -52, -45, -9, 39, -4, -29, -7, -5, -26, 14, 21, -22, -1, 53, -12, 42, 7, -10, 0, 5, 9, -26, 26, 17, -18, 57, 28, -3, 5, -52, -46, 40, -21, -19, -11, 6, 3, 2, 33, -6, 18, -3, 6, 4, -3, 4, 6, 43, 10, -28, -38, -40, -31, 28, 4, 47, -20, 4, 35, -2, -23, -13, -53, -12, -31, 37, -19, 22, 13, 32, -8, -11, 2, 11, 7, -15, 8, -3, -12, 0, 17, -11, 48, 2, 9, -4, 23, -27, 5, -4, 58, -30, -26, 35, 6, 16, -21, 4, -3, 2, -10, -17, -16, -9, 9, 10, -66, 12, 9, 30, 20, -18, 43, 16, -47, 57, 5, -24, -25, 35, -48, -36, 61, 18, 0, 2, 3, 11, -7, 27, -34, 7, 5, 0, -49, -9, 36, -2, -11, -14, -18, 22, 25, -8, 10, -9, 14, -13, -3, 5, -18, 19, -36, 15, -4, 23, -3, -14, -4, 15, 15, -1, 0, 10, 11, -4, 1, -22, 33, -18, 38, -19, 7, -22, 11, 23, -4, -7, -20, -5, -9, 14, -5, 2, -23, -9, 10, -7, 20, -1, -10, -9, 3, 1, -27, 5, 10, 10, 22, -2, -12, -2, 25, -8, 6, -18, -2, -5, 24, -16, -15, 7, 3, 1, -14, -2, -17, -15, 13, -7, 8, 22, -13, -23, -12, 5, -13, -6, 8, 7, 1, 0, 15, 11, 11, 14, -9, 6, 3, -5, 6, 12, -21, 12, 11, -6, 0, 7, -2, -26, 26, 6, -7, 10, -15, 35, 10, 15, -24, -4, -6, -13, -13, -14, -3, 10, 24, 12, -9, 0, -14, -6, 9, -11, -7, -15, -9, -2, 7, 7, -13, -8, 7, 9, 5, 27, 6, 2, -13, -18, 3, 0, 14, 5, 15, -17, 12, 3, 2, -10, -10, -29, -18, 12, -1, -14, -7, 3, 5, -9, -6, 6, 22, -14, 21, 3, 5, 23, 9, -2, -13, 3, -11, -25, 9, 7, 18, -16, 0, -2, -1, 16, 13, -17, -7, 19, -8, 13, -10, -4, 1, -5, -2, -4, -17, 11, -10, -22, 4, 23, 25, 10, 12, -15, 12, 5, 6, 22, -17, 4, 10, 6, -3, 23, 5, 17, -11, 15, -18, -9, 31, 14, 9, -10, -6, -6, 25, 15, -5, -9, 6, 12, -1, -3, 11, 0, 31, 10, -8, 3, -7, -12, 16, 2, -1, -5, -7, 14, 1}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0 {-77, -57, -16, -29, -103, -6, -58, -72, -56, -61, 20, -73, -52, -62, -35, -79, 6, 19, -11, -51, 27, -1, -57, -34, -5, -42, -14, -37, -29, -37, 9, -39, -4, 12, 11, 3, -13, -21, 3, -3, -12, -9, 7, 1, 0, 17, -12, -4, -77, -57, -16, -29, -103, -6, -58, -72, -56, -61, 20, -73, -52, -62, -35, -79, 6, 19, -11, -51, 27, -1, -57, -34, -5, -42, -14, -37, -29, -37, 9, -39, 8, 15, 3, -11, 14, -19, -7, 9, 6, 3, 14, 13, 10, 18, -10, 2}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0_DEC_BITS {7}

#define GRU_5_BIAS_LSHIFT {5}

#define GRU_5_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_6_GRU_CELL_6_KERNEL_0 {-43, 1, -12, -27, 36, -16, -24, -39, -23, 1, -116, -30, -28, 4, 12, 3, 24, -42, -11, -4, -79, -10, -34, -22, -8, 8, 69, 19, 62, -82, 59, -21, -68, -10, 48, -7, -24, -63, -34, 34, 30, 21, -62, 43, 56, -7, 58, -26, 71, -16, 54, -9, -19, -22, -64, 61, -85, -29, 34, 28, -71, 12, 38, -33, -75, -43, 63, 39, 112, -13, -45, 56, -36, 49, -4, -8, -11, 4, 31, 47, -27, 92, 58, 38, 95, 59, -35, 32, -17, -20, 44, -49, 54, -49, 9, -8, 9, -8, 1, 12, 42, -22, -37, -6, -94, 16, -50, -62, 15, -24, 60, 7, 21, 33, 17, 44, -75, 4, -30, -4, 45, 20, -18, -48, 24, 30, -41, 37, -26, 52, 31, -4, 57, -15, 26, 31, 7, 1, 2, 33, 67, -87, 11, -35, -10, -28, 100, 17, 56, -68, -69, 45, -38, 6, -34, -7, -17, 69, 11, 75, -2, 20, 73, -37, -6, -98, -67, 52, -50, -2, -35, 98, 55, 50, 12, -35, -26, -27, -15, -67, -73, 36, 12, 31, 62, 26, -43, 28, -45, 12, -26, 7, 9, 8, 21, -82, 12, -12, -44, 15, 21, 28, -37, 33, 7, 29, 17, -29, 42, -33, -1, 11, -17, -22, -74, 11, -7, 5, -34, 14, 1, -14, -8, -29, -67, 20, 24, -25, 25, -51, 38, 30, 56, 45, -53, 23, 8, -26, -17, -45, -76, -51, 66, -37, -3, -11, -29, 13, -2, 15, -80, 57, -91, -17, 4, -12, 13, 39, 2, 10, -38, -25, 5, 48, -3, -19, -19, 32, 16, -51, -14, -30, -5, -72, -27, -1, 2, 35, 37, 45, 2, 16, 57, 3, -42, -36, -39, -13, -3, 32, -25, -2, -9, -15, 27, 51, 33, -4, -35, 64, -34, 26, -19, -65, 42, -30, 34, -44, 11, 32, -4, 54, -33, -13, 22, 38, 45, 13, -28, -38, -48, 35, 9, -58, 48, 35, -19, -47, -1, 36, 6, -51, -8, -50, 31, 19, 38, 37, 46, 17, -16, -62, -98, -30, -53, 22, -57, 14, 19, 6, 48, 27, -41, 7, 49, 25, 45, 4, -56, -25, -20, -1, -50, 16, 16, 50, 41, 22, 23, -3, 29, -45, 5, 26, 0, -40, 1, -24, -29, 20, -55, -51, 34, 39}

#define TENSOR_GRU_6_GRU_CELL_6_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_6_GRU_CELL_6_RECURRENT_KERNEL_0 {1, 5, -9, -28, 74, -72, -39, -76, -33, 16, 15, 72, -1, 16, 59, -28, 28, 47, -5, 13, 38, -73, -27, -10, 15, 5, 4, -35, 30, 24, 19, 63, -15, 84, 18, 23, 54, 41, -26, -42, 7, -58, -61, 29, 9, 5, 26, 7, -58, 66, 41, 41, 48, -8, -54, 23, -23, -6, 45, -19, -18, -50, 0, 14, 28, -58, -50, -15, 15, 47, -28, 7, 53, 34, 21, -16, 30, -37, 58, 49, -14, -18, 34, -34, 31, 24, -20, 16, -33, -6, 21, -2, -1, 3, -5, -23, -17, 6, -19, -25, 0, -19, -32, 21, -21, 0, -23, 46, 7, 25, -35, 7, 1, 35, 35, -3, -42, 43, 0, 3, -59, 27, -9, -16, -10, 38, 27, -56, -15, -3, 4, -21, 53, -4, 8, 51, -11, -40, 23, -28, 25, -56, 59, 7, 41, -9, -9, 4, 40, 9, 10, 18, 10, -16, -46, -11, 14, 64, -38, 4, 39, 18, 55, 7, -18, -4, -38, -13, -54, -26, -19, 25, -6, 74, 38, -32, 11, -25, 40, -17, 9, -38, -32, -77, 10, 13, 30, 47, 0, 38, -73, 0}

#define TENSOR_GRU_6_GRU_CELL_6_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_6_GRU_CELL_6_BIAS_0 {76, -11, -20, -36, -5, -11, -43, -31, -39, -17, 11, 8, 19, -9, 48, 43, 8, 6, -19, -12, 3, -6, 18, -11, 76, -11, -20, -36, -5, -11, -43, -31, -39, -17, 11, 8, 19, -9, 48, 43, 4, 6, -14, 0, 4, -5, 16, -8}

#define TENSOR_GRU_6_GRU_CELL_6_BIAS_0_DEC_BITS {6}

#define GRU_6_BIAS_LSHIFT {7}

#define GRU_6_OUTPUT_RSHIFT {6}

#define TENSOR_CONV1D_4_KERNEL_0 {-28, -6, 5, -16, -11, 22, -59, 29, -28, -12, -6, -23, 28, -2, -13, -20, -22, -47, 17, -10, 18, -40, 4, -31, -28, 3, 23, -12, 9, 3, 27, 7, -1, -28, 45, 71, 23, 2, -48, -31, -17, -41, 26, -12, 2, -99, 35, 10, 10, 1, -35, 18, 14, -20, 25, 32, -17, -17, 4, 13, 6, -12, -18, -4, 2, 4, -8, -12, 4, -11, 0, 13, -18, -53, 59, 37, 43, 7, -39, -19, -6, -24, -3, -13, -10, 20, -80, 25, -8, -21, -7, -23, 28, 19, -31, -2, -10, -22, 4, -22, 10, 10, -3, 16, -4, 20, -3, 10, 7, -8, -6, 0, 15, -42, 50, 65, 13, -1, -32, -8, -2, 7, -7, 17, 23, 18, -53, -32, -4, 13, 31, 20, 14, -18, 3, -46, 13, -10, 31, 15, 6, -57, 1, -28, -7, -16, 43, 30, 26, -35, 11, -13, 1, -38, 54, 62, 51, -32, 12, -16, 10, 30, -6, 22, 32, 38, 14, -40, -11, 11, -7, 23, 4, 11, -3, -12, -9, 10, -5, -4, -12, 6, 14, 8, 11, -13, 3, -18, 21, -34, -12, 39, -5, 0, -9, -27, 6, -14, -14, 47, -26, -16, 42, 39, -12, -11, -33, -5, -20, -27, 54, 45, 22, -18, -8, -6, -45, -39, 57, 30, -12, 4, -42, 24, -26, -24, 49, 29, -5, 12, -36, 16, -20, 6, 15, 40, 17, -30, -3, -32, -1, -15, 72, 3, -13, -44, -24, 17, 27, 21, 13, -7, 10, -8, 4, -1, 33, -7, 14, 8, 23, -34, -22, 6, 33, 29, -13, -15, 13, -29, 18, -4, 20, -53, 94, 30, 41, -23, -42, -4, -8, -65, 69, -29, -14, -24, -6, -11, -9, -1, 5, -15, -19, -3, 15, 30, -14, -28, 12, 20, 12, -3, -33, -50, -14, 4, 29, -12, 29, -11, 46, 11, -16, 6, 27, -6, 21, 4, 2, 14, -9, 18, -14, 12, 32, 16, 28, -1, -3, -17, 13, 43, 68, 43, -29, -10, 11, -14, 12, -8, -14, -11, 10, -41, 11, -2, 0, -26, -28, -3, -5, 25, 7, -9, 25, 42, 26, -17, -78, -16, -18, -44, 66, 9, 39, 29, -30, -28, -27, 0, 18, -38, -17, -8, -1, 35, -21, -17, -25, 38, 29, -25, -57, -16, 7, 27, 5, 17, 46, 21, 11, -2, -26, 26, 21, -38, -4, 6, 4, 18, -1, -33, 37, -7, 8, 8, -25, -26, 9, 37, -12, -26, -9, 6, 13, 33, 12, -27, 42, 29, -1, 16, -45, -61, 18, 22, -4, -42, -6, -48, 28, 43, -3, 1, 5, 7, 40, -16, -5, -5, -7, 1, 14, -9, -21, -7, 23, 30, -11, 9, 1, 1, 6, 3, -43, 20, -5, -12, 31, -11, 11, 9, 19, 26, -20, 36, 8, 12, 0, -6, -14, 1, -24, -6, 21, 48, 18, -25, -11, 1, 3, 4, -3, 5, -8, 9, 35, 40, 7, 3, -10, 4, 10, 20, -41, 27, -4, -32, 30, -8, -7, 22, -14, 8, -23, -27, 35, 17, 18, -4, -15, -14, -29, -31, 4, 39, 52, -37, 0, -35, 9, -3, 7, -27, -13, -6, 3, 48, 14, -33, 28, 14, 43, 29, -38, -26, 22, -22, 8, -25, -10, -36, 10, 54, 16, 9, 0, -18, 26, -11, -1, 4, 7, 13, 7, 8, -21, -35, -45, -33, -18, -6, 10, 5, 15, -12, -1, 10, 6, 6, -22, -7, 18, -1, 14, 24, 3, 4, -2, 18, 29, 6, -25, -12, -2, -18, 1, 8, -6, 10, -23, -23, 13, 10, -7, -25, -19, -10, 18, 34, 17, -43, -6, -22, 45, 4, -47, -28, 1, 6, -9, -33, -14, -1, 26, 20, -3, 1, 28, 18, 38, -1, -44, -13, 14, -6, -2, 6, -5, 1, -3, 14, 16, -42, 26, 10, -3, -20, -28, 14, -1, -43, 22, 33, 21, 14, -6, -41, -7, -7, 14, 4, 3, -14, 10, -14, 10, -4, 5, -6, 19, -23, 3, 13, -4, 11, -7, -6, 17, -4, 4, -1, 3, 31, -7, -39, -12, 14, 9, 45, 17, -22, -17, 0, 25, -34, 27, -7, 21, 16, -16, -15, 19, -11, 27, -2, 3, 5, -28, -18, 29, -6, 27, -1, 14, 26, -24, 9, 52, -5, 27, -2, 17, 22, -11, 15, 55, -15, 28, -6, 15, -20, 11, -36, -28, -1, -59, 31, 5, -7, -10, -11, 45, -13, -11, -5, 5, 20, 1, -12, 1, 11, 10, 27, -12, 35, 2, -6, 22, 6, -13, 8, 12, -26, 36, 39, 29, -10, -25, -8, -1, 4, 35, 32, 77, 19, 2, -31, -4, -18, 24, -8, 1, -9, 9, 21, 12, -8, 0, -3, -13, 3, -2, 8, 15, 7, 4, 12, 16, -21, -41, -56, 22, -37, 61, 34, 27, -27, -31, -6, 2, -11, 6, -2, 8, -49, 1, 13, 16, 8, -13, -19, 15, -1, 13, 10, 6, 11, -18, 24, 21, 8, -10, -26, -1, -18, 3, 14, 33, -9, -5, -47, 8, 9, 5, -33, -32, 9, -5, 51, -2, 11, -6, 4, 7, 22, -2, 23, 14, 0, 0, 37, 34, 15, -30, -40, 16, -11, 13, 31, -18, 2, 3, -36, -1, -1, -7, -7, -8, -22, 15, 2, 1, 6, -21, -52, -13, -28, 0, 34, -44, -52, 11, 17, 42, 20, -2, -37, -40, -47, 12, -9, -17, -6, -14, 46, -26, -29, 5, -1, -2, -3, -20, -12, -24, 44, -9, 32, 6, -26, -24, -18, -38, 26, 39, -45, -29, -71, 5, 12, -20, 20, -3, 2, 47, -20, 3, -56, -7, 15, 5, -10, -3, 20, 23, 8, -8, 2, 31, 21, 27, 7, -21, -12, -1, 3, 27, -19, 10, -13, -19, -1, 6, 24, 1, -16, -14, -53, 17, 15}

#define TENSOR_CONV1D_4_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV1D_4_BIAS_0 {-26, -36, -37, -29, -49, -12, -57, -55, -33, -47, -29, -52, -45, -47, -49, -43, -49, 27, -44, -48, -42, -42, -38, -65}

#define TENSOR_CONV1D_4_BIAS_0_DEC_BITS {7}

#define CONV1D_4_BIAS_LSHIFT {6}

#define CONV1D_4_OUTPUT_RSHIFT {10}

#define TENSOR_CONV1D_5_KERNEL_0 {-4, 24, -7, -22, -13, 2, 1, -35, 7, -44, -1, -7, 12, -13, 10, -12, 3, 1, -10, 5, 11, 16, -40, -8, -8, 26, -12, -14, 4, 3, -3, -29, 3, -30, 4, -8, 10, -4, 5, -12, -1, -2, -2, 15, 12, 8, -15, 9, -23, 20, -16, -15, 9, -10, -1, -30, 14, -30, 2, -4, 7, -1, 11, 4, 1, -5, -12, 25, 12, 17, -30, 8, 0, 30, 12, 16, 15, 8, -4, -23, 3, -33, -53, 6, -26, -62, -10, 20, 17, -1, -15, -1, -9, -3, 10, 15, 4, 13, 5, -11, -4, 17, -22, -26, -10, -40, -49, 9, 23, -24, -13, -67, 8, 5, 2, 3, -9, -26, -5, -11, 15, 15, 20, 9, -29, 12, 37, -5, -42, 3, -52, 12, 13, -13, -17, -27, -46, 8, 17, -17, -16, -27, 12, -1, -20, 0, -18, -12, 10, -16, -33, -32, 17, -27, -7, -20, -8, 9, 9, -6, -4, 0, -22, 9, 9, 2, -11, 4, -16, 7, -7, -12, 9, 1, -1, -2, 11, 2, 14, -13, 4, 9, 14, 9, -9, -18, -12, 16, 1, 7, 4, 7, -23, -1, -13, -8, 6, 12, -2, -1, 10, -4, 13, -11, -10, 21, -2, 1, -1, -14, -18, 19, -4, 7, 3, 0, -20, 22, -26, -2, 0, -12, 4, 0, 20, -3, 14, -3, 14, -10, 4, -3, 6, 11, -7, 24, 7, 5, -7, 8, -26, 27, -29, -8, 2, -14, 12, 1, 18, -11, 1, -10, 11, -5, 4, -19, 9, 5, -11, 12, -2, 2, -9, 4, -14, 18, -23, -20, 1, -10, -10, -1, 13, -14, 5, 2, 7, 1, 4, -9, -3, 4, -17, 17, -8, 0, 5, -1, 15, -4, 14, 3, 7, 6, 33, -10, -7, -13, -22, -2, -4, -28, 9, 10, 5, -3, 11, -16, 7, 7, -26, 7, 8, 7, 11, 3, 15, -6, 44, -17, -13, -25, -16, 6, 2, -21, 12, 8, 6, -2, 8, -10, 8, 19, -19, 8, 10, 4, 9, 18, 19, -2, 37, -36, -10, -32, -21, 5, -4, -23, 13, 1, 14, 6, 10, -22, 16, 20, -29, 4, -12, 6, -4, -3, 0, -39, 20, -6, 8, 1, 9, 8, 15, 1, 3, 18, 6, -32, -5, 1, -4, 2, -11, 18, -4, -2, -3, 6, -3, -25, 31, -5, 12, 8, -14, -2, 10, -2, -5, 8, 13, -18, -7, 3, -5, 2, -9, -13, 5, 20, 5, 19, 0, -5, 49, -20, 0, -31, -15, 15, 15, -6, -8, 9, 6, -31, 11, 6, -7, 3, 1, -4, 9, 3, 10, -15, -10, 13, -2, 12, -6, 14, -1, -4, -3, 0, -9, -3, -9, -40, 11, 6, -6, 3, 13, -14, 9, 1, 20, -16, -8, 10, -7, 7, -7, 20, -2, -6, -8, 10, 2, 10, -2, -16, 1, 12, 12, 2, 9, -13, 17, 11, 24, 1, 1, 10, -12, 6, 0, 8, -2, 12, 9, 12, 7, 10, 4, -40, 17, 17, 11, 5, 22, -2, -2, 3, -7, -7, -12, 0, 6, 10, -6, 11, 6, -1, -1, 11, -11, -10, 3, -31, -1, -15, -11, 4, 12, -8, -6, 5, -5, -5, 4, -4, 9, 6, -17, 23, 13, -3, 3, -8, -3, -2, 4, -13, 0, 4, 1, -8, 16, -6, 5, 14, 15, 15, 11, -6, 2, 6, -11, 17, 9, 8, 7, 8, -13, 4, 7, -26, 9, -3, 0, -7, 14, -7, 5, -7, 2, -5, 0, -21, -15, 1, 13, -5, 2, 15, -5, 10, -1, 4, -9, -3, -2, -8, 0, 5, -3, -9, -2, 9, 5, -16, 7, -1, 24, 4, -9, 3, 19, -8, -25, -1, -15, 34, -4, 5, 0, -21, -13, -22, -9, -11, -1, -12, -14, -15, -13, -7, 5, 3, -3, 9, 16, -12, -10, 8, 2, 14, 1, -10, -17, -22, 3, -1, 0, 7, -6, -6, -6, -20, -17, -28, -5, 5, -21, 2, 9, -6, -17, -1, 11, 23, -18, 3, -7, 0, 9, -7, 4, 17, 8, -1, 7, -2, 1, 6, 4, -1, 22, 2, 13, -5, -30, 13, -12, 10, -7, 5, 3, 4, -6, -1, 1, -1, -8, -11, -10, -7, -6, -12, -9, 11, 9, 7, 13, -13, -14, 3, 18, 20, -14, -8, -11, 14, 26, 6, 11, 21, -8, 9, 2, 1, 4, -9, 33, -5, 9, 7, -1, 7, 9, 11, 4, -3, 3, -42, 6, 8, -6, 4, -11, 0, -3, 14, 2, -6, -3, -17, 32, -7, 5, 3, -20, -5, 13, -4, 2, 9, 19, -28, -1, -3, -6, 4, -16, 2, -5, 13, 7, 4, 7, -17, 40, -8, 6, -7, -12, 11, 14, 6, -3, 18, 13, -32, 8, -7, 14, 3, 0, -6, 13, -16, 18, -20, 4, -11, 11, 1, 10, -9, -13, -1, -27, 8, 3, 7, -20, -4, 13, -2, 11, 12, -7, -2, -2, -5, 3, -8, 7, -6, 18, -3, 0, -6, -4, -6, -12, -1, 16, 2, -22, -5, 10, 0, 6, 8, -8, 8, 14, -16, 7, -35, 2, -5, 11, -9, 19, -14, -7, -12, -13, 4, 14, -1, -19, -7, 11, 10, 7, 11, -7, 6, 5, 1, 8, -24, 4, -10, 16, 11, -6, 8, 10, 6, 14, -3, -9, 13, 4, -37, 1, 5, -8, 6, -2, -23, -3, 4, 1, -15, -9, -17, 9, -2, -12, 11, 1, 4, 7, -12, -2, 7, 13, -25, -5, -8, -1, 6, -11, -20, 15, 25, 7, -10, 3, -10, 25, 3, 1, -4, -5, 14, 10, -2, 5, 9, 5, -47, 10, 4, 3, 5, -6, -19, -20, 8, -17, -2, 6, 14, -38, 15, -3, 14, 25, -12, -7, 0, -2, -10, 11, -1, -7, 1, 9, 9, 25, -7, -19, 13, -14, -3, 13, 18, -36, 10, -15, 16, 17, -3, 0, 5, 9, -2, 11, -1, -12, 1, 6, 5, 29, 4, -13, 8, -17, 5, 15, 18, -41, 17, -9, 20, 28, -18, 0, -9, 3, -10, 11, 2, -19, 7, 12, 18, 33, 5, -20, 11, -20, -16, 16, -19, 8, -39, 21, -44, -5, -13, 8, 3, 8, 5, -6, -11, -21, 18, 4, 1, -7, 13, -17, 13, -12, -11, 10, -14, 28, -8, 13, -16, 5, -8, 14, 8, 9, 4, 4, -22, -31, 22, 3, 2, -7, 2, -28, -4, -13, -18, 0, -19, 30, 0, 4, 3, 8, -11, 0, 18, -6, 14, 9, -8, -27, 11, 0, 9, -2, -16, 13, -39, 13, 7, 12, -23, -27, -51, -42, -15, -24, -2, -5, -14, -12, -31, 6, 9, -4, -15, -6, 3, -15, 11, 16, -41, 18, 13, 22, 6, -9, -26, -28, 22, -40, -7, -11, -36, -6, -40, 1, 5, 10, -11, -10, -4, 26, -2, 22, -26, 8, 15, 7, 4, -25, -27, -39, 13, -53, -42, -25, -37, 4, -21, 10, 1, 4, 2, 3, -3, -10, 10}

#define TENSOR_CONV1D_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV1D_5_BIAS_0 {39, 46, -49, 96, -34, -48, -78, -64, 1, -2, -39, 9, -21, -29, -31, 43}

#define TENSOR_CONV1D_5_BIAS_0_DEC_BITS {8}

#define CONV1D_5_BIAS_LSHIFT {0}

#define CONV1D_5_OUTPUT_RSHIFT {7}

#define TENSOR_DENSE_2_KERNEL_0 {-4, -62, -2, -5, 6, 8, 6, -18, 24, -13, -34, -6, 0, -7, -3, 1, -10, 1, 5, 5, 10, 23, -22, -24, -31, 20, 10, 14, 27, -1, -16, -33, 8, -28, -4, 23, 21, -4, 20, -22, 28, -21, 9, -25, 11, -23, -3, -26, 2, 12, -11, -8, -3, 4, 25, -16, 0, 7, 13, 12, -8, 13, -8, -26, -22, 29, -10, 25, -64, -22, 0, 7, -19, -9, -16, -7, -14, -31, 24, 6, 12, -31, 15, 7, -12, -15, -21, -5, -45, 11, -29, -31, -38, 21, 21, -7}

#define TENSOR_DENSE_2_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_2_BIAS_0 {-9, 8, -12, -3, 21, -2}

#define TENSOR_DENSE_2_BIAS_0_DEC_BITS {5}

#define DENSE_2_BIAS_LSHIFT {0}

#define DENSE_2_OUTPUT_RSHIFT {4}


/* output q format for each layer */
#define GRU_5_INPUT_OUTPUT_DEC 7
#define GRU_5_INPUT_OUTPUT_OFFSET 0
#define GRU_5_OUTPUT_DEC 7
#define GRU_5_OUTPUT_OFFSET 0
#define GRU_6_OUTPUT_DEC 7
#define GRU_6_OUTPUT_OFFSET 0
#define CONV1D_4_OUTPUT_DEC 3
#define CONV1D_4_OUTPUT_OFFSET 0
#define RE_LU_4_OUTPUT_DEC 3
#define RE_LU_4_OUTPUT_OFFSET 0
#define MAX_POOLING1D_2_OUTPUT_DEC 3
#define MAX_POOLING1D_2_OUTPUT_OFFSET 0
#define CONV1D_5_OUTPUT_DEC 1
#define CONV1D_5_OUTPUT_OFFSET 0
#define RE_LU_5_OUTPUT_DEC 1
#define RE_LU_5_OUTPUT_OFFSET 0
#define GLOBAL_AVERAGE_POOLING1D_2_OUTPUT_DEC 1
#define GLOBAL_AVERAGE_POOLING1D_2_OUTPUT_OFFSET 0
#define DENSE_2_OUTPUT_DEC 2
#define DENSE_2_OUTPUT_OFFSET 0
#define SOFTMAX_2_OUTPUT_DEC 7
#define SOFTMAX_2_OUTPUT_OFFSET 0

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

const nnom_io_config_t gru_5_input_config = {
    .super = {.name = "gru_5_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_5_gru_cell_5_kernel_0_data[] = TENSOR_GRU_5_GRU_CELL_5_KERNEL_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_kernel_0_dim[] = {3, 48};
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

const nnom_shape_data_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_dim[] = {16, 48};
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

const nnom_shape_data_t tensor_gru_5_gru_cell_5_bias_0_dim[] = {2, 48};
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
    .units = 16
};

const nnom_rnn_config_t gru_5_config = {
    .super = {.name = "gru_5"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_6_gru_cell_6_kernel_0_data[] = TENSOR_GRU_6_GRU_CELL_6_KERNEL_0;

const nnom_shape_data_t tensor_gru_6_gru_cell_6_kernel_0_dim[] = {16, 24};
const nnom_qformat_param_t tensor_gru_6_gru_cell_6_kernel_0_dec[] = TENSOR_GRU_6_GRU_CELL_6_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_6_gru_cell_6_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_6_gru_cell_6_kernel_0 = {
    .p_data = (void*)tensor_gru_6_gru_cell_6_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_6_gru_cell_6_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_6_gru_cell_6_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_6_gru_cell_6_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_6_gru_cell_6_recurrent_kernel_0_data[] = TENSOR_GRU_6_GRU_CELL_6_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_6_gru_cell_6_recurrent_kernel_0_dim[] = {8, 24};
const nnom_qformat_param_t tensor_gru_6_gru_cell_6_recurrent_kernel_0_dec[] = TENSOR_GRU_6_GRU_CELL_6_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_6_gru_cell_6_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_6_gru_cell_6_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_6_gru_cell_6_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_6_gru_cell_6_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_6_gru_cell_6_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_6_gru_cell_6_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_6_gru_cell_6_bias_0_data[] = TENSOR_GRU_6_GRU_CELL_6_BIAS_0;

const nnom_shape_data_t tensor_gru_6_gru_cell_6_bias_0_dim[] = {2, 24};
const nnom_qformat_param_t tensor_gru_6_gru_cell_6_bias_0_dec[] = TENSOR_GRU_6_GRU_CELL_6_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_6_gru_cell_6_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_6_gru_cell_6_bias_0 = {
    .p_data = (void*)tensor_gru_6_gru_cell_6_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_6_gru_cell_6_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_6_gru_cell_6_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_6_gru_cell_6_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_6_gru_cell_config = {
    .super = {.name = "gru_6"},
    .weights = (nnom_tensor_t*)&tensor_gru_6_gru_cell_6_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_6_gru_cell_6_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_6_gru_cell_6_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 8
};

const nnom_rnn_config_t gru_6_config = {
    .super = {.name = "gru_6"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_conv1d_4_kernel_0_data[] = TENSOR_CONV1D_4_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_4_kernel_0_dim[] = {5, 8, 24};
const nnom_qformat_param_t tensor_conv1d_4_kernel_0_dec[] = TENSOR_CONV1D_4_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_4_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_4_kernel_0 = {
    .p_data = (void*)tensor_conv1d_4_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_4_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_4_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_4_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_4_bias_0_data[] = TENSOR_CONV1D_4_BIAS_0;

const nnom_shape_data_t tensor_conv1d_4_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_conv1d_4_bias_0_dec[] = TENSOR_CONV1D_4_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_4_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_4_bias_0 = {
    .p_data = (void*)tensor_conv1d_4_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_4_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_4_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_4_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_4_output_shift[] = CONV1D_4_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_4_bias_shift[] = CONV1D_4_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_4_config = {
    .super = {.name = "conv1d_4"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_4_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_4_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_4_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_4_bias_shift, 
    .filter_size = 24,
    .kernel_size = {5},
    .stride_size = {1},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling1d_2_config = {
    .super = {.name = "max_pooling1d_2"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2},
    .stride_size = {2},
    .num_dim = 1
};
const int8_t tensor_conv1d_5_kernel_0_data[] = TENSOR_CONV1D_5_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_5_kernel_0_dim[] = {3, 24, 16};
const nnom_qformat_param_t tensor_conv1d_5_kernel_0_dec[] = TENSOR_CONV1D_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_5_kernel_0 = {
    .p_data = (void*)tensor_conv1d_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_5_bias_0_data[] = TENSOR_CONV1D_5_BIAS_0;

const nnom_shape_data_t tensor_conv1d_5_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv1d_5_bias_0_dec[] = TENSOR_CONV1D_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_5_bias_0 = {
    .p_data = (void*)tensor_conv1d_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_5_output_shift[] = CONV1D_5_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_5_bias_shift[] = CONV1D_5_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_5_config = {
    .super = {.name = "conv1d_5"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_5_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_5_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_5_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_5_bias_shift, 
    .filter_size = 16,
    .kernel_size = {3},
    .stride_size = {1},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_average_pooling1d_2_config = {
    .super = {.name = "global_average_pooling1d_2"},
    .output_shift = 0,
};
const int8_t tensor_dense_2_kernel_0_data[] = TENSOR_DENSE_2_KERNEL_0;

const nnom_shape_data_t tensor_dense_2_kernel_0_dim[] = {16, 6};
const nnom_qformat_param_t tensor_dense_2_kernel_0_dec[] = TENSOR_DENSE_2_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_2_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_2_kernel_0 = {
    .p_data = (void*)tensor_dense_2_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_2_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_2_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_2_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_2_bias_0_data[] = TENSOR_DENSE_2_BIAS_0;

const nnom_shape_data_t tensor_dense_2_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_2_bias_0_dec[] = TENSOR_DENSE_2_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_2_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_2_bias_0 = {
    .p_data = (void*)tensor_dense_2_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_2_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_2_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_2_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_2_output_shift[] = DENSE_2_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_2_bias_shift[] = DENSE_2_BIAS_LSHIFT;
const nnom_dense_config_t dense_2_config = {
    .super = {.name = "dense_2"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_2_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_2_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_2_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_2_bias_shift
};

const nnom_softmax_config_t softmax_2_config = {
    .super = {.name = "softmax_2"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_2_OUTPUT_DEC};
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
	nnom_layer_t* layer[12];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&gru_5_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_5_gru_cell_config), &gru_5_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_6_gru_cell_config), &gru_6_config), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv1d_4_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(maxpool_s(&max_pooling1d_2_config), layer[4]);
	layer[6] = model.hook(conv2d_s(&conv1d_5_config), layer[5]);
	layer[7] = model.active(act_relu(), layer[6]);
	layer[8] = model.hook(global_avgpool_s(&global_average_pooling1d_2_config), layer[7]);
	layer[9] = model.hook(dense_s(&dense_2_config), layer[8]);
	layer[10] = model.hook(softmax_s(&softmax_2_config), layer[9]);
	layer[11] = model.hook(output_s(&output0_config), layer[10]);
	*state = model_compile(&model, layer[0], layer[11]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_17_NNOM_H