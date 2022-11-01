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
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0 {3, 10, -36, 29, 13, 9, 14, -18, -5, 1, -19, 12, 34, -2, 11, 17, -40, 47, 1, 30, -23, -33, -20, 26, -25, -46, 1, -27, -13, 47, -14, -87, -10, -37, 30, 3, -17, 32, 17, -11, -73, 8, 50, 0, 39, -32, 4, -7, -18, -2, 30, -35, 19, -47, -26, 25, 80, 3, 28, 21, 0, 9, -21, -33, 37, 10, -13, -39, 39, 17, 48, 41, -29, 26, 60, 49, 14, -30, 24, 38, 14, -27, -39, 16, -56, -16, 18, -1, 13, -1, -50, 10, -46, -36, 4, 11, 29, -1, 34, 67, -31, -12, -31, -37, -3, 4, 24, 20, -49, 6, -43, -37, 3, 49, -46, 51, -20, 27, -1, 13, 6, 45, 43, 61, 11, -75, -33, 76, 4, 23, -15, -5, -27, -43, -48, 26, 77, 24, -45, -26, 8, 15, 10, 0}

#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0 {15, -7, -4, -32, -17, 31, -15, -12, -1, 29, 21, 53, 24, 6, 39, 28, 0, 33, 20, 28, 22, 13, 34, 2, 6, 16, 6, -44, 16, 23, -19, -3, -19, -29, -9, -46, -26, -5, -20, -10, 37, 74, -5, -18, 6, -6, -26, -2, 17, 60, -32, -41, 15, 4, -5, 23, -26, 14, -17, 1, 1, -12, -7, -20, -5, -6, -25, -12, 21, -10, 12, -24, 16, 4, 15, 21, -10, 29, 0, 34, 11, 0, 10, 15, -31, 30, -12, 31, 10, -1, -14, -9, -6, 43, 36, -40, -4, -6, -18, -22, -8, -27, -22, -4, 14, 40, 31, 13, 42, 15, -42, -34, 1, 17, 20, -14, 27, 16, -14, -15, -13, -20, 17, -29, -15, -7, -6, -7, -3, 46, -7, 10, 13, -4, -5, 37, 7, -41, -14, -9, 2, -14, 16, -13, -12, -60, -8, -48, -10, 50, -22, -16, 8, -47, -8, 34, 0, -13, -13, -38, -5, 46, -15, 35, -24, 10, -6, -5, 14, -20, -9, 4, -3, -15, -29, 50, 15, -37, 9, 30, -9, 2, 17, 25, -2, -13, 2, -18, -32, -52, 5, -34, 64, 17, 6, 13, 5, 12, -37, 28, -15, -31, -38, -15, 29, -6, 8, 27, -3, -31, -49, -21, -2, -25, 9, 0, -6, -36, 25, 5, 11, -6, -4, 13, 12, 10, 16, -10, 7, -47, 20, -18, -25, -20, 34, 4, -9, 34, -37, -49, -29, -23, 27, 21, -21, 30, -7, -14, -29, -31, -17, -33, 45, -39, 28, -26, 18, 4, 29, 15, 32, -23, -8, -11, 2, -19, -19, 1, -20, -20, -10, -22, 3, -33, -17, -27, -28, -17, -34, 10, -19, -50, 6, 35, 0, 17, 29, -2, -9, 8, 21, 0, -2, -39, 32, -11, -9, -11, 46, -1, -31, 2, -25, -16, -26, -8, 24, 17, -20, 11, 20, 0, 7, 24, 10, -11, 8, -11, -10, -37, 14, 7, -4, 37, -13, 10, -7, 47, 23, 3, 10, -13, -6, -30, -1, -15, 11, -5, 2, 17, -1, -47, 22, 4, -15, -12, -35, 26, -7, -27, 11, 52, 4, -9, 7, -6, 9, -9, 11, 20, 3, 3, 2, 9, -1, -14, 16, 2, -11, 0, 5, 8, -3, -15, 29, 0, -29, 14, 8, 4, -6, 13, -33, -14, -6, -18, 10, -34, -2, -1, -9, -6, -23, 19, -19, 24, 17, 8, 13, -10, -22, 9, -18, 4, 6, -2, 37, 8, -17, 14, 42, -15, 13, 22, 7, -4, 13, -14, -1, -33, -5, -15, -15, -21, 11, 20, -16, -15, 18, 9, -20, 23, 0, 51, -27, -33, 18, 7, -22, -11, -2, 14, -15, 54, 20, 27, -6, 29, -66, -4, -19, 8, -27, 16, 6, -31, 13, 14, 23, 7, 0, 21, 14, -25, 6, 12, 38, 23, 0, 20, 17, 23, -18, 23, 2, 3, 11, 8, -20, -5, 2, -21, -3, -22, -16, 13, -1, -6, 6, 21, 6, -20, -4, 0, -12, 47, 6, 28, -4, -33, -9, -4, -7, 7, 25, -1, -3, -2, 14, 34, 21, -7, 1, -9, 3, 1, 22, 11, -27, -35, 7, 18, 1, 5, 1, -8, -10, 11, 5, 10, -4, 4, 17, 3, -22, 0, -3, 21, -5, -22, 2, 4, -24, -31, -11, -9, 2, -14, 5, -9, 17, 1, -4, 5, 38, -22, 9, 12, 21, -22, -1, -3, 18, -7, -3, 12, 9, -2, -41, -6, -29, 21, 2, -5, 7, 11, -9, -1, -11, 4, -4, 6, 2, 11, -7, 8, -13, -2, 1, 3, 1, -2, 13, 16, -8, 8, 11, 9, 19, 2, -9, -13, -12, 18, 13, 10, 13, 10, 19, 7, 10, 11, -1, -1, 17, -7, 0, 21, 33, -16, -5, 9, 15, -12, -6, -6, 5, -21, -14, 7, -9, 1, -2, 17, 5, 9, 1, -19, -27, -7, 8, -15, -5, -29, 16, -10, 14, -18, 7, 17, -8, 19, -7, 5, -15, 2, -6, 24, -21, -5, -13, -16, -25, 9, -21, -5, 9, -26, -21, -7, 14, -5, 19, 1, 14, -4, 15, -4, -12, 5, -11, 19, 5, 26, 12, 16, -1, 5, -9, 15, 17, 5, 16, 6, -4, -16, -10, 9, 6, 0, 9, 7, 1, 12, 10, -16, 9, -25, 5, 24, -1, 3, -20, 2, -15, 17, 11, -8, -5, 3, -5, 13, -17, 5, -8, -12, -9, -20, 11, 11, -10, -29, 9, 18, 8, 9, -1, -26, -25, -6, 4, -18, 7, 7, 11, -4, 5, 15, -6, -16, 24, -20, 5, 13, -16, 12, -13, -19, -5, 4, -15, -4, 7, 4, 13, 25, 1, 0}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0 {-37, 27, -44, -41, -81, -42, -39, -63, -35, 0, -43, -1, -36, -23, 29, -17, 30, -5, 9, 7, -2, 10, 18, -53, 22, 2, 14, -33, -12, 17, -14, 21, -3, 6, -2, -4, 1, -3, -6, 1, -6, -5, 4, -3, 2, -2, -3, 0, -37, 27, -44, -41, -81, -42, -39, -63, -35, 0, -43, -1, -36, -23, 29, -17, 30, -5, 9, 7, -2, 10, 18, -53, 22, 2, 14, -33, -12, 17, -14, 21, 2, 2, -3, -1, 0, -3, 1, 2, 4, -3, -3, -1, 4, 2, -2, -1}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0_DEC_BITS {6}

#define GRU_3_BIAS_LSHIFT {8}

#define GRU_3_OUTPUT_RSHIFT {7}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0 {-17, -1, -7, 26, -51, -9, -32, -19, 15, -34, 5, 5, 40, 16, 49, 14, 10, -36, 8, -23, 31, 2, 28, -9, 8, -11, -10, 10, 6, 12, -37, 4, 4, -28, -6, 12, -17, 2, -10, 25, 9, -32, -15, 9, 28, -13, 19, 13, -14, -8, 0, 52, 23, -13, -10, 8, -12, 25, 31, -47, 21, 18, 32, -15, 20, 47, -36, 39, 43, -4, 19, 17, -9, -70, 1, -22, -41, -14, -14, -34, -11, -83, 1, -33, -81, 12, -32, -23, 12, -27, -1, 99, 11, 17, 48, -14, -15, 12, -7, 41, 7, -21, 40, -35, 15, -29, -36, 11, -15, 19, 2, -3, 5, -24, -23, 15, -32, 24, 16, -51, 0, -28, 29, -79, 6, -24, -36, 34, -3, -1, -67, -35, -56, 19, -13, 11, 44, 0, 45, -20, 17, -4, 25, -33, 21, -11, 28, 11, 50, -3, 39, -23, 2, 23, -7, 27, 73, -15, -91, 33, -10, 7, 24, 33, -61, 29, -62, 38, 16, 5, -25, -23, 15, -4, -41, 19, 22, 2, 4, -20, 52, -34, -42, 13, 2, 27, 11, 9, 34, -2, 69, -6, -11, 26, 16, 13, -25, 15, 13, -1, -24, -10, 19, 2, -9, 2, 2, 3, -14, -19, -27, -14, -17, -15, 39, -27, -28, 0, 13, 29, 12, -56, 2, 12, -30, 4, -31, -13, -34, 8, -9, 14, 10, 28, -22, -24, 0, 27, -33, -22, 3, 11, 15, -7, -4, 3, -17, 19, -19, -24, 10, -28, 19, -13, 22, 26, -45, 2, 19, 21, 3, 3, -4, 24, -30, -33, 19, 21, 12, -22, 62, -21, -51, -47, -1, -6, -5, -27, 1, -3, 0, -15, 25, 30, 14, -15, -14, 38, -49, -47, -21, 12, -23, -4, -24, 6, 7, -4, 12, -25, 7, 2, -68, -24, 16, 10, -2, 15, 35, 2, 1, -19, 3, -39, 14, -47, -25, -15, 24, -9, -5, -4, 26, 19, -51, -1, -21, -32, -7, -20, 4, -20, 13, 18, 16, -5, -12, -14, 4, 24, 44, 41, 67, 9, 8, 9, 3, 11, 18, 0, -33, -40, -40, -5, -46, -8, -16, 4, 16, 10, 10, -2, -8, 6, 12, 18, -15, -7, 27, 7, -32, -5, 9, -11, -15, 10, -1, 18, 24, 21, 10, 21, 2, 20, 5, -16, 5, -17, -31, 4, -19, 3, 1, 17, 2, -4, 8, 7, 33, 3, 0, 19, -26, 6, 8, 10, 25, 14, -15, -2, 7, -25, -5, 39, -17, -15, 14, 16, -6, 20, -22, -17, -20, 8, 12, -3, -16, 26, 29, -18, 4, 20, -8, -4, -10, -1, 13, -15, 2, 5, -12, 5, 13, 19, 1, 5, 4, 2, 17, 18, -21, 21, 46, -16, 17, -6, -11, -18, -19, -10, -15, 23, -20, 17, -2, -21, 14, -28, 1, 19, -19, 3, 24, -5, 14, 18, -9, 13, 30, -33, -17, 11, 9, 9, 31, -10, 3, -17, -12, -19, 5, 4, -14, -8, -6, -4, -4, -20, 6, 12, -17, 12, -12, 12, 9, 8, -14, 0, 1, 6, -23, 4, -19, 22, 8, -25, -25, 14, 13, 20, 9, 7, 19, 7, 22, 12, -6, -11, 3, 1, 22, -28, 24, -3, 9, -8, 0, -16, -5, -2, -7, -5, -12, 16, -13, 16, -20, -14, 17, 18, -21, 5, 13, 0, -30, 25, 20, -5, -9, -18, 22, -3, -18, 17, 10, -3, -16, 15, -8, -12, -1, -10, -11, -11, 9, -2}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0 {22, -18, -51, 6, 47, 1, -27, 7, 25, 10, -11, 34, -86, 17, -45, -4, 16, 1, -3, -30, -23, 79, -4, -28, 33, -36, -12, 107, -13, -26, 15, 33, 31, 92, -90, -46, -12, 11, 22, -46, 16, 37, 29, 28, -69, 26, 42, 29, 36, -24, -75, 11, -77, 29, -6, 20, -39, 37, 17, 18, 64, 4, 68, -9, -10, 97, 24, -71, 115, -32, -21, 45, 46, -26, -11, -4, -38, 60, 42, 18, 5, 103, -50, -79, 85, 13, -26, -10, 19, 46, 26, -1, 15, 0, -30, 40, 69, 18, -120, 20, 4, -1, 8, 39, -80, -45, -62, -41, -55, -37, -26, -29, 9, -30, -34, -22, 17, -11, 51, 4, -3, -37, -47, -57, -23, -28, 13, -5, -80, -17, -31, 5, 5, 14, 17, -70, -21, -30, -19, 13, -92, -9, 62, 32, 34, 9, -46, -34, -23, -15, 15, -1, -2, 3, -28, -36, -9, 14, 17, 3, 16, -18, 8, 20, -14, -23, 4, 22, 9, 58, 10, -22, -9, 2, -5, -14, 35, -8, -63, -13, -11, 5, -42, -28, 5, 22, 10, 9, 27, 34, 15, -24, -41, -19, 7, -14, 44, 31, -10, 11, 21, 14, 31, 7, 24, 12, 22, -8, 43, 36, -13, 13, -7, 7, -6, -7, -3, -7, 41, 18, -7, -24, -13, -3, 19, 13, -36, -74, 20, -9, -43, -15, 4, 13, 6, 18, 1, -13, 14, 33, 0, -15, -22, 77, 6, 2, 23, 7, -9, -22, 44, 33, -6, -45, 5, -1, 17, 44, 11, 6, -48, 4, 51, -6, 34, -10, -23, -45, 16, -26, -9, -56, 22, -6, -10, 18, -18, -20, -24, -24, -17, -59, -7, -21, 4, -46, -30, -26, 4, -10, -8, 54, 19, -41, 1, 34, -45, 28, 17, 0, 27, 17, -49, 13, -5, 0, -31, 35, -26, 53, 42, 21, -17, -34, -1, 42, 11, 9, -4, -15, -23, 43, 2, 8, 8, 13, -32, -35, -48, -8, -21, 20, 14, 20, 4, -1, -12, -17, 24, -24, 0, -15, -28, -54, 29, 43, -19, -11, 1, 17, -15, 25, -2, 30, 10, 30, -8, 33, -21, -16, 29, 23, -74, -1, 0, 19, -18, 18, 31, 15, -59, -37, -4, 42, 4, -31, -15, 12, 24, 13, 47, 12, -16, 27, 29, -37, 0, 6, 1, -11, 8, -23, -8, 32, -22, 25, 1, -7, -17, -47, -7, 17, 9, 1, -15, -8, 42, -28, 40, -13, -30, 55, 37, 28, -35, 1, 18, 4, -34, 27, 6, 35, 9, -20, -22, 8, 20, -37, 16, 1, 12, 52}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0 {-35, 16, 75, -32, -33, 25, 29, -14, 67, 23, 45, 46, -7, -2, 13, 6, -14, -4, -20, 18, -8, 6, -8, 2, 5, 2, 2, -11, 0, 5, 7, -4, 11, -9, 5, 15, -35, 16, 75, -32, -33, 25, 29, -14, 67, 23, 45, 46, -7, -2, 13, 6, -14, -4, -20, 18, -8, 6, -8, 2, -1, 2, -3, -10, 4, 5, -2, -5, 12, -15, 3, 14}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0_DEC_BITS {6}

#define GRU_4_BIAS_LSHIFT {6}

#define GRU_4_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0 {13, 5, -14, -27, 13, -19, -29, 14, -23, -9, 3, 3, -14, 0, -22, 26, -14, 48, 9, -4, -16, 35, 33, -7, 14, 13, -17, -20, 33, -31, -10, -9, -27, -24, -11, -1, 12, -4, 21, -21, -25, -26, 15, 24, -20, 5, 28, 18, 34, 28, -44, -15, -46, -33, 19, 14, -6, -25, -59, -30, 49, 15, 9, 52, -14, -6, 21, 49, 34, 22, 19, -14, 42, 56, 5, -6, -22, -29, 11, -4, -23, -15, 39, 9, 32, 7, -67, 10, -9, -8, 43, 18, 27, -2, 1, -23, 4, 8, -1, -12, 21, 17, -12, 23, -3, -13, -3, -28, -6, 2, -11, 3, -11, 8, -14, 14, 4, 7, -9, -15, -28, 22, -22, -17, -6, -29, 25, -46, 3, 5, 0, -4, -4, -16, -1, -13, 18, -8, -32, 23, -10, -22, -17, -20, 30, 18, -1, 30, -14, 5, 8, -22, -4, -14, -20, -3, 20, -6, -14, -19, -15, 17, -9, -26, 5, -21, 32, 11, -19, -34, 12, -3, 34, 10, 7, 39, 36, 7, -4, -13, 17, 25, -13, -15, -9, -49, -5, -2, 40, -1, 14, -2, 0, -17, -28, -5, 10, 9, 0, -7, -8, 14, -4, 18, -16, 13, 14, -13, -29, 15, -17, 9, 2, -4, -17, 16, -9, -21, -3, 24, -37, 1, -13, -31, -54, 2, 14, -16, -38, 1, -2, -47, 9, 23, 8, -3, -32, -2, -10, 53, -13, 5, -4, 14, -4, 19, 6, -10, 16, 7, -10, 22, -13, -2, 27, -22, 8, -25, 2, 3, -4, -31, -3, 0, -3, -4, 16, 23, -5, 12, -9, -11, 12, -5, 3, 17, -25, -1, -9, 16, 15, -9, -11, -20, -14, -2, -6, 12, -10, 23, -3, -17, 6, 11, -18, 13, -22, 1, 24, -26, 8, 4, 3, 3, 27, -10, -17, 2, -10, 8, -4, -13, -15, 4, 16, 10, 12, -4, 5, 6, -1, 36, -33, -18, -13, 12, 0, -15, 0, 5, -7, 6, 22, -17, 6, 22, -11, -5, 5, -6, -6, -15, 13, 16, -1, 7, -8, 5, -19, 19, -4, 19, -6, 15, 0, 24, -3, 42, 5, -15}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0 {7, 0, 17, 0, 26, 3, -8, -39, 38, 28, 31, 56, 60, -5, -31, 91, 28, 37, 1, -22, 66, 11, -45, 14, -8, -12, -6, -42, 41, -19, 8, -31, 37, 20, -2, -4, 4, -3, -35, -18, 93, -20, -44, -18, -12, 27, -71, 0, 24, 24, 14, -8, -66, 16, 38, -17, 104, 42, -67, -48, -54, 24, -22, 1, -38, -4, 21, 3, -15, -26, 39, -37, -1, -1, -1, -42, 30, 12, 37, 44, -12, 40, -88, -53, 4, -15, 15, 13, -28, 37, -38, 44, 22, 33, 69, -37, 33, 9, 59, -37, 36, 44, 13, -22, -9, 10, -4, 21, 3, -99, -32, 28, -38, 13, 2, 21, 15, -38, -19, -27, -2, -28, 2, 13, 49, 2, 8, -27, 5, 13, -17, 15, -40, 32, -2, -54, 18, 30, 62, 24, -31, 10, -17, 28, 24, -42, 21, 4, 50, 19, -55, 13, 1, -1, -21, -29, 43, -21, 42, 3, -21, -16, 14, 4, 12, -44, 36, -47, -1, 4, 44, -52, 127, -24, 25, -17, -6, -35, 4, 11, 26, -23, -88, 41, 0, -14, -1, 12, -49, 2, 24, 54, 23, -45, -42, 6, -32, -26, -16, -27, 8, 3, -9, 48, 32, 3, 5, 12, 10, -13, 24, -57, 6, 12, 10, 36, 8, -30, -8, -2, 19, -14, -42, -39, -16, 5, -61, 22, -62, 15, -27, -53, 6, 2, 37, 5, -2, 34, -2, -23, 21, -39, -20, -3, -26, 20, -5, 1, 2, 32, 76, 7, -5, 17, 22, 12, 48, 5, 81, 29, 25, 4, 12, -16, -39, -18, 16, 16, -5, -31, 16, -24, 10, -44, -25, -24, 36, 8, -25, -18, 33, 40, 15, -28, 18, 3, -6, -51, 17, 54, 34, 18, -20, -16, 5, 0, 6, 10, -6, 75}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0 {10, 47, 67, 42, 64, 34, 61, -4, 63, 58, -15, -15, 4, -21, 22, -3, -21, -25, -26, 7, -1, -32, -16, 1, 18, 6, -7, 2, 1, 8, 10, 47, 67, 42, 64, 34, 61, -4, 63, 58, -15, -15, 4, -21, 22, -3, -21, -25, -26, 7, -4, -27, -9, 0, 14, 5, -2, -7, -4, -6}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0_DEC_BITS {6}

#define GRU_5_BIAS_LSHIFT {6}

#define GRU_5_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_1_KERNEL_0 {6, 66, 42, 43, -14, -47, 43, -36, 102, -42, -63, 36, -51, -27, 35, 60, 65, 25, -13, -61, 20, 21, 24, 50, -31, -4, 20, -52, -58, 28, 29, 33, 62, 52, -80, -4, 29, 43, -37, -47, 37, -11, -51, -98, -94, 21, 43, -17, -10, 85, -26, -38, -29, -81, 29, 70, -38, 35, -5, -24}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_1_BIAS_0 {36, -91, 38, -128, 42, 92}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {9}

#define DENSE_1_BIAS_LSHIFT {4}

#define DENSE_1_OUTPUT_RSHIFT {9}


/* output q format for each layer */
#define GRU_3_INPUT_OUTPUT_DEC 9
#define GRU_3_INPUT_OUTPUT_OFFSET 0
#define GRU_3_OUTPUT_DEC 7
#define GRU_3_OUTPUT_OFFSET 0
#define GRU_4_OUTPUT_DEC 7
#define GRU_4_OUTPUT_OFFSET 0
#define GRU_5_OUTPUT_DEC 7
#define GRU_5_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 4
#define DENSE_1_OUTPUT_OFFSET 0
#define SOFTMAX_1_OUTPUT_DEC 7
#define SOFTMAX_1_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {9};
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
    .q_dec_z = 4,
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
    .q_dec_z = 3,
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
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {10, 6};
const nnom_qformat_param_t tensor_dense_1_kernel_0_dec[] = TENSOR_DENSE_1_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_1_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_1_kernel_0 = {
    .p_data = (void*)tensor_dense_1_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_1_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_1_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_1_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_1_bias_0_data[] = TENSOR_DENSE_1_BIAS_0;

const nnom_shape_data_t tensor_dense_1_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_1_bias_0_dec[] = TENSOR_DENSE_1_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_1_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_1_bias_0 = {
    .p_data = (void*)tensor_dense_1_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_1_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_1_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_1_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_1_output_shift[] = DENSE_1_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_1_bias_shift[] = DENSE_1_BIAS_LSHIFT;
const nnom_dense_config_t dense_1_config = {
    .super = {.name = "dense_1"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_1_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_1_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_1_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_1_bias_shift
};

const nnom_softmax_config_t softmax_1_config = {
    .super = {.name = "softmax_1"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_1_OUTPUT_DEC};
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
	layer[4] = model.hook(dense_s(&dense_1_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_1_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_21_NNOM_H