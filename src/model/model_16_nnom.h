#ifndef MODEL_16_NNOM_H
#define MODEL_16_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_16_nnom
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
#define TENSOR_GRU_2_GRU_CELL_2_KERNEL_0 {-18, 17, -1, 13, 34, 0, -23, -11, 20, 0, 7, -21, -34, 13, 36, 12, -84, -57, 63, -61, -13, -10, 15, -15, 28, -34, 9, -38, 82, 5, -35, 39, -49, 48, -22, 0, 49, -25, 1, -26, -38, 68, 20, 24, -25, -11, -45, 22, -53, -40, -23, 79, 14, 26, -39, -44, -27, -23, 19, -18, 89, 33, 16, -60, -29, -82, 0, -38, 14, -18, -36, 41, 13, -28, 40, 2, -43, -25, -9, 30, -37, 10, -17, 31, 20, -40, -13, -43, 72, -33, -25, -39, -8, 17, 10, -18, 33, -25, 46, -42, -60, 28, 52, -41, -10, 6, 11, 4}

#define TENSOR_GRU_2_GRU_CELL_2_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_2_GRU_CELL_2_RECURRENT_KERNEL_0 {25, 30, 13, 19, 9, 20, -20, 20, 14, 23, -4, 21, -3, -12, 37, 13, -42, 24, 21, 3, 8, -13, -32, 47, 24, -6, -18, -40, -74, 12, 21, -13, -5, -5, -33, -23, -35, -24, -9, -16, 5, 18, -38, -7, -33, 6, 27, -5, -23, 2, -19, -20, 6, 20, -23, -11, 7, -6, -11, 7, -40, -6, -33, -4, -11, 37, 5, 10, 45, 31, -29, -7, 9, 7, 47, 13, 44, 24, -30, -14, -28, -17, 73, 12, 31, -3, -25, -33, -52, -11, 21, 21, -29, -2, 25, 3, 1, 14, 30, 1, -25, -17, 7, -13, 31, 69, 23, 34, 78, -10, 13, -11, -25, -1, 18, 12, 6, -11, 51, 15, 20, 14, 11, -44, -4, 15, 8, -25, -26, 3, 50, -32, -27, 13, 19, -11, -35, 73, 3, -65, 18, 19, -4, 11, -5, 2, 24, -27, 3, -17, 52, 15, -28, -12, -12, -10, 4, 15, -38, -29, -10, -58, 8, -31, -56, -4, 1, -26, 23, -33, 16, 31, 61, 19, -15, -8, -6, 1, 13, 27, 58, 17, 12, 34, 3, -27, 1, 15, 68, 17, -18, 14, 14, 3, 17, -9, 44, -4, 17, 4, 0, -14, 24, -16, 7, 32, 21, -3, -30, -7, -38, -31, -57, -26, -1, 27, -63, 31, 4, 1, -35, -18, 12, 21, 45, 19, -55, 9, -9, 8, -17, 14, 50, -39, -68, 14, 5, 38, -40, -10, -56, 1, -47, -2, -7, 24, -11, -2, 9, 50, -23, -11, 41, -14, 36, 2, 10, -22, 28, 9, -4, 31, -18, 21, 2, -40, 35, 35, -61, -33, 6, 10, -19, -18, 32, 18, -8, -56, 8, 6, -39, 28, 40, 5, 32, 0, -13, -12, -14, 15, 13, 17, -32, -26, -7, 26, -5, 12, 11, -13, 0, -14, 8, 3, 5, -12, 24, 19, -18, 9, 40, 16, 9, 16, 15, 21, -13, -23, 27, 29, -33, 0, 19, 0, 6, -1, 3, 3, -18, -28, -9, 19, 25, -7, -1, 18, 10, -15, 5, -7, -12, 3, 4, -12, -7, 0, -1, -10, 26, -9, -17, 2, 8, 8, -21, 2, -4, -7, 30, -19, -19, 30, -13, -14, 1, -14, 28, -7, -4, 21, -22, -3, -9, 10, 34, -8, 45, -4, -36, 17, 12, -18, -3, 8, 20, 3, 11, -10, 0, 13, 14, -14, -1, 17, -8, -2, 20, 9, 1, 10, -14, -26, -3, -3, -21, 0, -14, -19, 22, -18, -20, 9, 7, -15, 2, -6, 15, -2, -23, -1, 12, -5, 3, -24, -5, 7, -1, -7, 19, -1, -7, -18}

#define TENSOR_GRU_2_GRU_CELL_2_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_2_GRU_CELL_2_BIAS_0 {-74, -16, -29, -75, 1, -101, -25, -92, -43, -70, -126, -120, 50, 40, 16, 38, -8, -7, 17, -28, -58, -52, -16, -22, -5, -5, -15, -14, -18, 7, -21, -1, 8, -16, -9, 5, -74, -16, -29, -75, 1, -101, -25, -92, -43, -70, -126, -120, 50, 40, 16, 38, -8, -7, 17, -28, -58, -52, -16, -22, -5, -2, 0, -11, -9, -3, -18, 20, 26, 47, -11, -1}

#define TENSOR_GRU_2_GRU_CELL_2_BIAS_0_DEC_BITS {7}

#define GRU_2_BIAS_LSHIFT {5}

#define GRU_2_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0 {-18, -51, 13, 24, 34, -20, 25, -32, -16, -20, 1, 37, 8, -9, 25, -36, 3, -28, 34, 25, 40, 23, 4, -22, 25, 4, 0, 1, 38, 8, -29, 22, -19, -4, 26, 13, -27, 16, -30, 28, -23, 0, 9, 21, 26, -36, -27, 31, -22, -15, -23, -83, 47, -22, 17, -38, 1, 73, -12, 9, -19, -33, -14, -31, 6, -50, 9, -37, -4, 27, 2, -30, -15, -73, 6, 29, 24, -6, -41, 1, 8, -16, -11, 39, 25, 27, -42, -18, -4, -6, 26, 39, 23, 16, -33, 4, -17, 30, 10, 3, 19, -35, 15, -24, 10, 29, -23, 32, 26, -30, 24, -39, 4, -4, 37, 32, -20, -7, -29, 11, -14, -9, 35, -7, -34, -5, -15, 35, -25, -29, 34, -27, 15, 17, -3, 28, -44, -19, 10, -25, 30, -13, -20, 30}

#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0 {-23, 0, -46, 12, 26, -48, 49, 25, -21, -10, -43, -2, -23, 39, -1, -34, 50, 12, -16, 72, -11, 10, 56, -67, 35, 80, 16, 66, -31, -20, -26, 36, -50, 35, -3, 48, 67, -2, 38, -34, -22, -102, -68, 67, 6, 17, -33, 7}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0 {-104, -116, -77, -92, -1, 114, 9, -56, 18, 8, 26, 26, -104, -116, -77, -92, -1, 114, 9, -56, 10, 15, 16, 37}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0_DEC_BITS {7}

#define GRU_3_BIAS_LSHIFT {5}

#define GRU_3_OUTPUT_RSHIFT {5}

#define TENSOR_CONV1D_2_KERNEL_0 {22, -59, -16, -2, -14, -28, 2, 3, 15, 34, -11, 15, 9, -19, -17, 8, 34, -17, -67, 20, -45, -73, 19, -41, -58, -36, 12, -18, -39, -3, -25, -11, -6, -29, -19, -23, 15, -37, -25, -6, 17, -39, -1, 22, -5, 2, 3, 7, 0, 21, -4, -3, -21, 25, 6, -16, -14, 17, 41, -25, -1, 50, -33, 7, -23, 20, -9, 1, 47, -4, 15, -8, -44, -10, -3, -4, -7, 5, 39, -29, 14, 11, -29, -30, 16, 5, -8, -31, -12, -19, -1, 2, -61, -23, 14, 6, -70, -19, 4, -2, -49, -15, -13, -36, -75, -16, -67, -56, -35, 4, -20, -43, -1, -21, -11, -24, -15, 21, 17, -6, -6, 12, 17, -3, -29, -23, 8, -4, 2, 2, 24, 11, -14, -5, -13, -3, 43, 1, -42, 12, -1, 14, -31, 30, -20, -3, -3, -9, -73, -19, 10, -35, -1, 11, -20, 9, -36, 28, 39, -53, 5, 35, -46, 13, 11, 9, -37, 22, 10, -14, 3, -5, -17, 1, 3, -20, -26, 15, 18, -19, -4, -15, -10, 25, 2, 22, 12, -3, -6, 24, 14, 3, -3, 21, 29, -23, 9, -49, -12, 2, 13, -4, -38, 38, -44, 5, -54, -27, -66, -4, -36, -37, -18, -8, -17, -19, 15, 49, 42, -18, -34, -46, -14, -54, -5, 17, 12, 17, 22, -20, -13, 19, -35, 10, -9, -33, 30, -35, -40, -15, 23, 11, -60, 14, -21, -21, -39, 9, -61, -21, -20, 8, -45, -22, 26, -6, 15, 10, 44, -19, -10, 26, 43, 27, 9, -2, 32, 48, -13, 17, 31, 26, 4, -6, 44, 54, -14, 28, 44, 41, -38, 19, 39, 7, -21, 9, -41, 28, -4, -20, -27, -10, -51, -5, 23, -45, 10, -37, -63, 2, 23, 2, 17, -7, -32, -29, 38, -9, 24, -8, -32, 25, -28, 46, 6, -24, -19, 0, 23, -13, 4, -6, 14, -64, 65, -1, 6, -31, -55, -4, -23, 36, -5, -10, -4, 3, -25, -33, -22, 31, -15, 45, -19, -18, -42, -27, 23, -19, -46, -14, -8, -11, -9, 16, -7, 10, -68, 16, -7, -22, -13, -61, -21, -6, 2, 7, -19, -49, -40, 18, 13, -9, 50, -2, 36, 21, -83, -20, 16, -19, -6, 46, 10, -69, 27, -18, -18, -40, -7, 22, -32, 6, -15, 13, 9, -5, -41, 33, 31, -48, 4, 0, 16, -41, 4, -2, 12, -16, -35, -8, -14, -14, -2, -10, -15, -10, 14, -36, -39, -4, -12, -62, -28, 10, -27, 5, 14, -38, -30, 3, 25, -20, 32, -14, -4, -14, 28, -6, -34, 7, -16, 15, -40, -15, -15, -8, -17, 0, -17, -24, -58, 20, -29, -18, 13, 8, 14, -21, -42, 4, 9, 1, 28, -38, 30, -5, 31, -35, -29, -1, 8, 8, -1, 9, 33, -38, 18, 17, 52, 3, 8, -26, -3, -50, 12, 1, -32, -1, 6, -3, -11, 10, -7, -4, -7, -6, 3, -6, -57, 18, -18, -32, -48, -65, -2, 33, 8, -25, 29, -2, -7, 32, -70, 20, 1, -27, 7, -10, 14, -17, 5, -40, 19, 9, 19, 17, -16, 10, -14, 20, -12, 0, -23, 9, 19, -13, -24, -7, 41, -12, -27, -50, -8, -13, -2, -2, -31, 25, 1, 4, 17, -19, -30, -19, 9, -43, 58, -8, -34, -13, 22, -40, -45, -9, -30, -18, 29, 1, -29, -28, -35, 5, 11, -6, 24, -49, -67, 38, 7, -29, 41, 13, -10, -8, -45, 15, 24, -6, 16, -32, -27, 38, -13, 64, 44, -18, 22, -16, -59, 0, -7, -17, -23, 25, -24, -5, -11, -36, -29, -2, 33, -15, 45, -26, -26, -9, 20, 6, -41, -15, 17, 13, -23, 6, 33, 38, -7, 8, 5, 16, -3, 13, -6, -17, -3, 8, -29, -27, 31, -18}

#define TENSOR_CONV1D_2_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV1D_2_BIAS_0 {-59, -77, -39, -66, -79, -36, -35, -36, -83, -42, -43, -46, -58, 0, -21, -29, -56, -33, -55, -50, -69, -53, -72, -18, -69, -47, -43, -39, -63, -41, -46, -39}

#define TENSOR_CONV1D_2_BIAS_0_DEC_BITS {7}

#define CONV1D_2_BIAS_LSHIFT {6}

#define CONV1D_2_OUTPUT_RSHIFT {9}

#define TENSOR_CONV1D_3_KERNEL_0 {-9, 6, 4, 4, -12, -20, 8, 7, 2, 2, 1, -13, 21, -10, 13, 7, -2, -19, -10, -29, 5, -3, -4, -26, -15, -7, 7, 16, 22, 11, -9, 8, -11, -12, 8, -17, -15, -21, 4, 3, -13, 8, 7, -14, 13, -19, 14, 0, 1, -5, -1, -18, 6, 12, 3, -32, 8, -18, 4, 17, 18, 7, 7, -6, -1, -13, 3, -5, -1, -16, 11, 7, -8, -2, 6, -10, 14, -21, 19, 7, -1, 2, 3, -8, 6, 1, 12, -14, 9, -4, -3, 9, 27, 23, 11, -3, -1, -21, 3, 11, 14, -18, 1, -2, -3, 1, -10, -16, 10, -28, 1, 5, -8, 4, 33, -1, 3, 9, -3, -7, -3, -9, 8, 3, 28, -6, 6, 8, -6, -20, 4, 9, 15, -27, 3, -25, -6, 8, -14, -20, -7, -25, -1, -3, 10, -9, 28, 3, 2, 2, 8, 8, 2, -1, 3, 6, 17, 3, 1, 9, 12, -15, 10, 5, 3, -14, 12, -21, 6, 10, -22, -13, 6, -31, 5, 2, 0, -11, 11, 8, 8, 6, 6, -1, 3, 0, 2, 14, 29, 5, 5, 0, 2, -13, -2, 11, -14, -1, -14, 1, 15, 5, 7, -6, 1, -17, -3, -18, 6, 5, -13, -18, 7, 3, -25, -13, -15, 3, -6, -2, -7, 4, 1, -2, 3, -18, -1, 8, -9, 14, -24, 1, 5, -6, 9, -19, 6, -1, -10, 9, -8, 12, 3, 11, -9, -12, 1, 8, 0, -5, 5, 6, -12, -22, -10, -1, 18, -25, -9, -27, -34, -2, -7, -5, -33, 13, -13, 3, -17, 8, -16, -4, 1, -3, -15, -4, -20, 15, 1, 5, 9, 8, 5, 12, -4, 8, 8, -9, -11, -18, -13, -21, -20, -9, -9, -6, -28, 4, -5, -4, -30, 11, 10, 1, -1, 3, 5, 1, -20, 9, -12, 12, -6, -5, -9, 5, -14, 4, 2, -14, -6, -11, 6, -8, -17, -6, 2, 14, -22, 4, 4, 5, -31, -1, 14, 15, 0, 8, 3, 12, -5, 11, -8, 5, -1, -6, 1, 16, -11, 15, 12, -10, -10, -9, 5, -7, -34, -2, -10, 11, -18, 9, 5, 4, -36, -14, 23, 19, -3, 20, -8, 14, -15, 17, -7, 6, -4, 2, 6, 15, -2, 1, 10, -13, -37, -28, 13, -33, -9, -17, 1, -23, -8, 7, 7, -5, -9, -1, -10, 2, -44, -8, -13, -1, -40, -6, -21, -9, -25, -3, 10, -4, -31, -6, -9, 13, -33, -11, 15, -39, -16, -13, 9, -4, -22, 16, 24, -1, -1, 6, 13, 11, -29, 6, -24, -5, -10, -3, -32, -9, -17, 5, 15, -10, -24, 2, 1, 14, -22, -10, 22, -42, -46, 1, 9, 3, -20, 19, 20, 9, -3, -2, 13, 16, -26, 6, -37, 9, 2, 12, -9, -11, -14, 4, 12, 17, -40, 11, 16, 15, 5, -3, 2, 5, 10, -5, 1, -6, 0, 1, 1, 8, 6, -65, -6, -6, 1, 0, 36, 11, 2, 2, 11, 13, -1, 13, 5, 2, 9, -1, -1, 2, 3, -17, -6, 3, 9, -13, 10, -5, 3, -6, -5, -4, -5, -36, -4, 0, 3, -3, 27, 12, -7, -8, 5, 9, 4, 12, 2, 6, 8, 11, -7, 10, 16, -7, 8, 0, 8, -10, 21, 7, 1, 4, -4, -2, 1, -63, 15, 11, 6, 1, 20, 11, 7, 3, 5, -6, 1, 14, -2, 6, 23, 18, 16, 2, -23, -8, 7, -9, -10, -48, 1, -30, 8, 6, -23, -24, 0, 2, 12, 1, -14, -24, -5, -13, 2, -13, -6, -15, -28, -10, 6, -6, 31, 7, 5, 8, -27, -5, 7, -11, -11, -21, 12, -17, 3, 17, -4, -20, 20, -6, 17, 10, -19, -20, -2, 5, 13, 14, 1, -24, -26, -10, 8, 12, 29, 19, 15, 5, -22, -22, 11, -21, -16, -14, 9, -6, -10, 5, -4, -16, 13, -10, 28, 15, -34, 0, -16, 17, 12, 21, 19, -38, -14, -9, 11, 20, 29, 18, 21, 2, -4, 33, 2, 10, -3, 33, 19, 15, 8, -5, 47, 2, 15, 0, -3, 18, 2, 15, -13, -8, 11, -8, -9, -8, -18, 10, 3, 12, -19, 10, 2, 6, -24, -11, 12, -13, -21, 7, -7, -12, -14, 3, 12, -2, -9, -6, -12, 10, -6, 4, -6, -12, -23, -32, -32, 6, -32, 5, 9, 2, -35, 8, -30, 11, -32, -22, -4, -13, 0, 13, 9, 13, -22, -4, 11, -34, -1, 2, 2, 4, 13, 1, -13, -12, -12, -6, -24, -2, -52, -13, 11, 1, -27, 19, 1, 8, -4, -32, 11, -1, -1, -15, -14, -3, -1, 15, -6, -13, -8, -4, -13, -25, 8, -53, 21, -31, -19, -12, -21, -29, -11, -2, 3, 7, 1, -10, -3, 7, 0, 6, 0, 6, 9, -11, 7, 2, 5, -6, 6, -23, -1, 0, -2, 6, 35, 2, -43, 16, 14, -6, 13, -1, 3, 4, -1, -6, -19, 8, -2, 6, -17, -4, 17, 9, 7, 14, -19, 12, 7, 3, 12, -6, 23, -9, 11, 22, 11, 10, 32, 17, -8, -36, -16, 4, -8, 15, 21, -6, 9, -7, -24, 24, 15, -19, 5, 15, 13, -12, -1, -3, 23, -6, -6, -18, 19, 2, 1, -7, -9, -29, -9, -33, 3, -17, 9, -13, 5, -20, 5, -37, 27, -16, -11, 7, 4, -11, 11, 14, 17, 6, -4, -18, 20, 4, 8, -22, 32, -14, 3, -35, 6, -22, 29, -35, 9, 7, 18, 8, 11, 5, 0, -18, 2, -9, 3, 18, 7, 3, 1, 7, 10, -11, 11, -21, 14, -1, 14, -8, 28, -19, -26, -11, 3, -19, 15, -8, 3, 6, 19, 2, 9, -15, 3, -10, 28, -15, 0, 1, -2, 3, -6, -5, -4, 2, 3, -3, -9, -7, 4, 1, -7, -6, 2, -2, -4, -6, 0, 1, -4, -5, -1, -6, -3, -9, 5, -4, 4, 2, -7, -8, 0, -2, -5, -4, -3, -2, -7, 0, -2, -6, -2, -4, 4, 2, -7, 3, -1, 2, 1, -1, -1, -6, -1, 1, -8, 1, -2, 4, 0, 2, 0, -6, -5, -1, 1, 2, 1, -9, -8, 0, -9, -3, -6, -1, -4, -8, -4, -8, -1, 2, -2, -3, -7, -3, -3, -4, -7, -6, -5, -8, -6, 4, -5, -5, 12, 7, -2, 6, 3, -37, 13, -1, 7, 6, -65, -44, 10, 18, -21, -5, 15, -8, -44, -38, 21, -13, -38, -1, -20, -49, 0, -45, -35, -26, -35, 6, 16, 5, 5, 21, 20, 24, 4, 3, 22, -4, -17, -24, 42, 7, -22, 1, 10, 4, 4, -24, 14, -6, 1, 6, 26, -43, -1, -21, -16, -41, -32, 6, 14, 10, 3, 22, 12, -3, -5, -7, 26, -4, -15, -35, 34, 19, -49, -15, 15, -9, 11, -34, 6, -29, -26, 4, 13, -36, -9, -52, -34, -36, -55, -2, -5, 19, 3, -3, 13, -12, 13, -25, -10, 17, -31, -3, -19, -1, -8, 13, 12, -11, 18, -1, 7, 2, -15, -4, -21, -22, 14, -6, 6, 20, -8, 16, 9, 27, 9, -1, 5, -13, 12, -22, -19, 18, -32, -8, -16, 7, -2, 11, 13, -19, 20, -6, 14, -11, -5, -12, -15, -29, 18, -7, 0, 22, -18, 13, 1, 16, 17, 1, 7, 3, 14, -18, -15, 22, -27, -16, -14, -2, 2, 20, 5, -12, 16, 3, 14, -4, -10, -9, -11, -19, 12, -7, -2, 18, -6, 18, 9, -1, 0, -15, 3, -23, 8, -1, 7, -4, -4, -6, -1, -21, 10, 4, -8, 0, -15, -7, -2, -3, -2, -7, 10, -41, 6, -10, 17, 0, 0, -21, 8, -17, -2, 3, 5, -12, -11, -2, 4, 5, 1, -12, 19, -20, 13, -2, -27, 0, 7, -8, 2, 19, -3, -7, 2, -25, -3, 5, 20, -21, 10, 6, 1, -13, -3, 17, 21, -22, -4, 3, 10, 10, -6, 10, -2, -5, 6, -6, -1, -10, 23, -1, -8, 7, 13, 10, 14, 11, 4, 5, -5, 22, 5, 16, 11, 21, -5, 1, -3, -6, -7, 4, -4, -3, 9, 12, 11, -7, 9, 1, 21, -2, -4, -7, -1, -10, 17, 16, 0, 21, -9, -9, -4, 18, -18, -2, 14, 17, -11, -2, -6, 7, 4, 9, 1, -14, 28, 11, 15, -17, 3, -2, 21, -4, -11, -5, 10, 4, 21, 12, 8, 15, -5, 3, -4, 12, 5, -8, 17, 13, -4, 4, 0, 18, 0, 5, 2, -8, 21, 16, 9, -26, 2, -8, 14, -4, -10, 1, 8, -6, 17, 11, 6, 28, -6, -4, -3, 4, -11, -11, 11, -6, -36, 38, 0, 0, -5, 27, 23, -30, 2, 11, -21, 5, 9, -10, 4, 28, 5, 1, 11, -1, 1, 39, -2, 28, -41, 5, 3, 25, -4, -12, -2, -9, -38, 13, 1, -13, -27, -5, -5, -30, -11, 9, -34, 14, 7, -25, 10, 12, 3, 1, 3, 2, 6, 16, -1, 7, -41, 5, -12, 4, 0, -28, 2, 3, -49, -15, 17, 4, -30, 8, -19, -34, 13, 8, -12, 13, 11, -31, 25, 2, -5, -3, 3, 3, -3, 14, -1, 3, -55, 18, 18, 5, 8, -49}

#define TENSOR_CONV1D_3_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV1D_3_BIAS_0 {-82, -26, 33, 27, -63, -46, -34, 58, -31, -47, -16, 60, -24, -81, -79, 87}

#define TENSOR_CONV1D_3_BIAS_0_DEC_BITS {8}

#define CONV1D_3_BIAS_LSHIFT {1}

#define CONV1D_3_OUTPUT_RSHIFT {9}

#define TENSOR_DENSE_1_KERNEL_0 {-28, 14, 32, -33, 19, -58, 7, 64, -13, 10, 45, -36, 30, -14, 26, -37, 56, -16, -73, -79, 8, -13, 34, -21, 18, 34, -36, -26, 3, -23, -47, 17, -101, 14, 0, -10, -13, 37, -35, -2, 70, -7, 10, 64, 48, 4, -8, -11, -34, -29, 21, 17, 27, 50, -56, -29, -2, 23, -43, -82, 27, -69, -19, -43, -4, -38, -16, -1, -68, -11, -6, 14, 4, -63, 10, 30, -66, -31, -55, 40, 0, -74, -69, 15, 43, -73, 39, 37, 24, -68, 28, -45, 21, -10, 3, 28}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_1_BIAS_0 {-26, -6, -20, -4, 38, 9}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {6}

#define DENSE_1_BIAS_LSHIFT {0}

#define DENSE_1_OUTPUT_RSHIFT {4}


/* output q format for each layer */
#define GRU_2_INPUT_OUTPUT_DEC 7
#define GRU_2_INPUT_OUTPUT_OFFSET 0
#define GRU_2_OUTPUT_DEC 7
#define GRU_2_OUTPUT_OFFSET 0
#define GRU_3_OUTPUT_DEC 7
#define GRU_3_OUTPUT_OFFSET 0
#define CONV1D_2_OUTPUT_DEC 4
#define CONV1D_2_OUTPUT_OFFSET 0
#define RE_LU_2_OUTPUT_DEC 4
#define RE_LU_2_OUTPUT_OFFSET 0
#define MAX_POOLING1D_1_OUTPUT_DEC 4
#define MAX_POOLING1D_1_OUTPUT_OFFSET 0
#define CONV1D_3_OUTPUT_DEC 0
#define CONV1D_3_OUTPUT_OFFSET 0
#define RE_LU_3_OUTPUT_DEC 0
#define RE_LU_3_OUTPUT_OFFSET 0
#define GLOBAL_AVERAGE_POOLING1D_1_OUTPUT_DEC 0
#define GLOBAL_AVERAGE_POOLING1D_1_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 2
#define DENSE_1_OUTPUT_OFFSET 0
#define SOFTMAX_1_OUTPUT_DEC 7
#define SOFTMAX_1_OUTPUT_OFFSET 0

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

const nnom_io_config_t gru_2_input_config = {
    .super = {.name = "gru_2_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_2_gru_cell_2_kernel_0_data[] = TENSOR_GRU_2_GRU_CELL_2_KERNEL_0;

const nnom_shape_data_t tensor_gru_2_gru_cell_2_kernel_0_dim[] = {3, 36};
const nnom_qformat_param_t tensor_gru_2_gru_cell_2_kernel_0_dec[] = TENSOR_GRU_2_GRU_CELL_2_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_2_gru_cell_2_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_2_gru_cell_2_kernel_0 = {
    .p_data = (void*)tensor_gru_2_gru_cell_2_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_2_gru_cell_2_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_2_gru_cell_2_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_2_gru_cell_2_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_2_gru_cell_2_recurrent_kernel_0_data[] = TENSOR_GRU_2_GRU_CELL_2_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_2_gru_cell_2_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_2_gru_cell_2_recurrent_kernel_0_dec[] = TENSOR_GRU_2_GRU_CELL_2_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_2_gru_cell_2_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_2_gru_cell_2_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_2_gru_cell_2_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_2_gru_cell_2_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_2_gru_cell_2_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_2_gru_cell_2_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_2_gru_cell_2_bias_0_data[] = TENSOR_GRU_2_GRU_CELL_2_BIAS_0;

const nnom_shape_data_t tensor_gru_2_gru_cell_2_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_2_gru_cell_2_bias_0_dec[] = TENSOR_GRU_2_GRU_CELL_2_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_2_gru_cell_2_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_2_gru_cell_2_bias_0 = {
    .p_data = (void*)tensor_gru_2_gru_cell_2_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_2_gru_cell_2_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_2_gru_cell_2_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_2_gru_cell_2_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_2_gru_cell_config = {
    .super = {.name = "gru_2"},
    .weights = (nnom_tensor_t*)&tensor_gru_2_gru_cell_2_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_2_gru_cell_2_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_2_gru_cell_2_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_2_config = {
    .super = {.name = "gru_2"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_3_gru_cell_3_kernel_0_data[] = TENSOR_GRU_3_GRU_CELL_3_KERNEL_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_kernel_0_dim[] = {12, 12};
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

const nnom_shape_data_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_dim[] = {4, 12};
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

const nnom_shape_data_t tensor_gru_3_gru_cell_3_bias_0_dim[] = {2, 12};
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
    .units = 4
};

const nnom_rnn_config_t gru_3_config = {
    .super = {.name = "gru_3"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_conv1d_2_kernel_0_data[] = TENSOR_CONV1D_2_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_2_kernel_0_dim[] = {5, 4, 32};
const nnom_qformat_param_t tensor_conv1d_2_kernel_0_dec[] = TENSOR_CONV1D_2_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_2_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_2_kernel_0 = {
    .p_data = (void*)tensor_conv1d_2_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_2_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_2_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_2_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_2_bias_0_data[] = TENSOR_CONV1D_2_BIAS_0;

const nnom_shape_data_t tensor_conv1d_2_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_conv1d_2_bias_0_dec[] = TENSOR_CONV1D_2_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_2_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_2_bias_0 = {
    .p_data = (void*)tensor_conv1d_2_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_2_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_2_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_2_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_2_output_shift[] = CONV1D_2_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_2_bias_shift[] = CONV1D_2_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_2_config = {
    .super = {.name = "conv1d_2"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_2_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_2_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_2_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_2_bias_shift, 
    .filter_size = 32,
    .kernel_size = {5},
    .stride_size = {1},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling1d_1_config = {
    .super = {.name = "max_pooling1d_1"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2},
    .stride_size = {2},
    .num_dim = 1
};
const int8_t tensor_conv1d_3_kernel_0_data[] = TENSOR_CONV1D_3_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_3_kernel_0_dim[] = {3, 32, 16};
const nnom_qformat_param_t tensor_conv1d_3_kernel_0_dec[] = TENSOR_CONV1D_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_3_kernel_0 = {
    .p_data = (void*)tensor_conv1d_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_3_bias_0_data[] = TENSOR_CONV1D_3_BIAS_0;

const nnom_shape_data_t tensor_conv1d_3_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv1d_3_bias_0_dec[] = TENSOR_CONV1D_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_3_bias_0 = {
    .p_data = (void*)tensor_conv1d_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_3_output_shift[] = CONV1D_3_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_3_bias_shift[] = CONV1D_3_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_3_config = {
    .super = {.name = "conv1d_3"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_3_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_3_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_3_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_3_bias_shift, 
    .filter_size = 16,
    .kernel_size = {3},
    .stride_size = {1},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_average_pooling1d_1_config = {
    .super = {.name = "global_average_pooling1d_1"},
    .output_shift = 0,
};
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {16, 6};
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
	nnom_layer_t* layer[12];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&gru_2_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_2_gru_cell_config), &gru_2_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_3_gru_cell_config), &gru_3_config), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv1d_2_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(maxpool_s(&max_pooling1d_1_config), layer[4]);
	layer[6] = model.hook(conv2d_s(&conv1d_3_config), layer[5]);
	layer[7] = model.active(act_relu(), layer[6]);
	layer[8] = model.hook(global_avgpool_s(&global_average_pooling1d_1_config), layer[7]);
	layer[9] = model.hook(dense_s(&dense_1_config), layer[8]);
	layer[10] = model.hook(softmax_s(&softmax_1_config), layer[9]);
	layer[11] = model.hook(output_s(&output0_config), layer[10]);
	*state = model_compile(&model, layer[0], layer[11]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_16_NNOM_H