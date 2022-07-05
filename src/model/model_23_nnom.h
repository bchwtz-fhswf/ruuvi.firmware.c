#ifndef MODEL_23_NNOM_H
#define MODEL_23_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_23_nnom
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
#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0 {-28, -29, -4, 5, 13, -27, 20, -5, 21, -5, 33, -28, -2, -26, 26, -16, 21, 7, -5, -19, 13, 16, -18, 37, 20, -20, 21, -17, 28, -46, -6, 6, -40, 65, -15, -2, 11, 22, 0, -21, -14, 8, 25, -8, -62, -40, -2, -15, 44, 3, -3, 21, 19, 24, -28, -22, -28, -3, 12, 68, -43, -42, -21, -45, 28, 0, -2, -60, 35, 25, -6, 12, -12, 9, -56, -39, 19, 11, -45, 42, -33, 5, -18, -22, -6, 54, 73, 3, -17, 21, -44, 8, -24, 22, -25, -13, 21, 58, 5, -34, 35, 21, -46, -22, -38, 19, 5, 21, 59, 3, -3, -6, 13, -11, -1, -8, 19, -20, -62, 14, 29, 26, 11, -27, -17, 15, 21, 22, 0, -9, 6, -14, 20, -23, -14, 20, -17, -2, 7, -20, -11, -5, -12, 26, -13, -14, -27, 14, -7, -27, -22, 10, 18, 30, -1, 8, -23, -9, -26, 27, 26, -17, 29, -5, -20, 20, 15, -16, 6, -5, -18, 17, -17, 2, 21, -23, -16, 8, -8, 27}

#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0 {7, -36, 6, 18, 6, 43, -24, 17, 17, 14, -3, -36, 26, 13, -5, 48, 10, -37, 3, -19, -18, -25, 8, 1, 6, 35, -38, 11, 28, -12, 6, -7, -49, 8, 22, -9, 3, -1, -16, -26, 4, 13, -3, -30, -3, -34, -10, -22, 19, 22, 0, 21, 31, -27, -10, 63, 37, -35, -31, -18, 24, 21, -28, -12, 25, 38, 16, -40, 30, -21, -5, 13, 19, -3, -1, -33, -12, 21, -6, -31, -28, 13, 14, 6, -32, 12, -38, -15, -5, 16, 14, -15, 4, -49, 15, -1, 22, 11, -49, -11, -24, -1, 26, -19, -5, 12, -34, 7, 25, 3, -51, 9, -17, -29, -8, 3, -40, 27, 41, -53, -41, 4, 18, -5, -12, 5, 23, -10, -59, 13, -21, 9, -14, 29, 28, -18, 28, 23, 3, 17, -4, -19, -33, 11, -22, -9, -9, -19, 12, -2, 0, -14, 21, -14, -5, 28, 5, -6, 21, 33, -25, 19, -26, 34, 0, 18, -11, 15, -8, -44, -36, 11, -24, -33, 9, 8, -11, 20, 16, -43, -21, 1, -17, -36, -3, -24, 29, -33, 18, -31, 31, 4, 50, -9, -9, -16, 37, -6, -16, -16, 25, 34, 28, -24, 12, 1, -34, -41, 18, 40, 0, 8, -10, -24, -69, -14, -27, 32, 23, 26, -28, 13, -3, 1, 5, 12, -25, -20, -12, 24, -2, 3, -26, -31, 21, 25, -23, -24, 63, 23, 24, 32, 11, 5, 7, -25, 4, -5, 9, 28, -48, 27, -2, -15, 6, -1, 0, 3, -27, -23, -22, 37, -22, -40, -1, -23, 5, -1, -5, -21, 9, 6, -28, 4, -24, -12, -21, -7, -3, 15, 12, -6, 18, 19, 2, 5, -42, 36, 2, -18, -12, 8, -12, 4, 5, 9, -23, 25, 6, -6, -41, -42, -13, 22, 13, -27, 35, 19, 2, 30, -41, -4, -7, 22, 35, -7, 50, 0, -27, 14, -6, -42, -49, 21, 17, 22, -27, -27, -7, -87, 16, 7, 8, 8, 45, 44, -36, 19, 36, -40, -12, -25, -17, 22, 28, 4, -47, 31, -23, 8, -16, 1, -19, 43, 23, -13, -8, -36, 6, 6, -18, 24, 21, -40, -30, -21, -34, -11, -52, 4, 19, -20, -17, -13, 19, 10, 15, -29, -41, -12, 33, -2, -20, -4, -8, 12, 43, -26, 14, -16, -5, -7, 42, -27, -5, 30, 21, 42, 18, -37, -5, 62, -17, -28, 16, -38, 30, -32, -14, 17, -13, -1, 4, 27, -13, -6, 14, 2, -21, 7, 30, -15, 26, 16, -10, 26, 8, -9, -10, 6, -30, -7, -6, 12, 4, -27, 22, 9, -16, 24, 32, 17, 9, -19, 22, -5, 4, 24, -2, 14, 7, 0, 29, -5, 1, 9, -4, 13, 10, 8, -10, -1, 8, 4, 1, -22, -25, -14, 22, 23, 1, 37, -19, -13, 16, -58, 8, 44, -16, -7, -21, 16, -11, 21, 3, -13, -20, -9, -18, 10, -28, 18, 12, -13, -4, 23, 31, -17, -31, 5, 35, -19, -23, -52, -31, 23, -21, -8, 19, 26, -2, -8, 11, -10, 11, -1, -24, -15, 22, -8, -5, -12, -21, 11, 25, -38, -4, -22, -31, -58, -53, 23, -4, -5, -38, 31, -15, -25, 28, -9, -19, 37, -28, -10, 36, -15, -10, 50, 9, -3, -22, 9, -20, 11, 30, -52, 28, 58, 6, 14, 6, -10, 27, -21, 12, -30, -12, -29, -36, 2, 26, -11, -23, 9, -11, 19, 15, -26, -16, 37, 16, -43, -36, 43, -7, 22, 17, 34, -10, 50, 1, -36, 8, -17, -16, -42, 0, -47, 12, 22, -18, -4, -27, 38, 9, -22, 22, 4, -19, -21, 7, -28, 20, 6, 21, 26, 28, -45, -30, 20, 9, 13, -20, -15, 29, -27, -25, 13, 52, 26, -16, 11, -34, -10, 22, -19, -23, 8, 16, 8, -11, -45, 1, -77, 35, -7, -22, -45, -17, -11, 3, 89, 25, -1, 53, -9, 32, 16, 12, 16, -18, -34, 33, 7, -1, 12, -7, -14, 3, -1, -21, 12, 23, 48, 3, 37, 34, 2, 17, -6, 6, -23, -12, 3, -46, -18, -23, 28, -10, -65, 4, -20, -64, -3, 19, 3, 4, 13, 5, 23, 51, 5, 14, 0, 25, 40, 0, -1, -38, -24, 5, -1, -4, 24, -8, 57, 33, 21, -50, 20, -9, -30, 23, -22, -19, -58, -19, -20, 21, -24, -14, -14, 11, -17, 9, 17, -2, 30, -17, 11, -6, -15, 22, -2, -2, -18, -9, -32, 8, 38, -9, -19, -23, -29, -12, 29, 12, 9, 2, 43, 21, -20, -18, 5, 13, 4, 7, 54, 40, 11, 16, -30, 8, 4, 20, -4, -17, -22, 31, -24, -3, 6, -13, 6, 5, 55, -13, -26, -14, -29, 7, -11, -5, 7, -33, 53, 32, 2, 19, 37, 6, 15, -9, -14, -2, -16, -1, -14, -25, 25, -24, 9, 7, -1, -21, 21, -6, -5, -26, -1, 10, -2, 16, 14, 2, -2, 11, -25, -27, 5, 9, 11, 1, -7, 15, -8, 11, 33, -23, -2, 23, -3, -11, 17, 4, -4, 4, -48, 13, 15, 0, 15, 9, 12, -2, -2, 12, 15, 20, -9, 20, -4, 8, 1, 4, -12, 0, 17, 3, -6, 13, -26, -7, 12, -19, -36, -22, 10, 7, 23, 9, 22, 4, -9, -2, -13, -26, 31, 4, -15, -25, -7, 14, 1, -3, 17, 12, 18, -11, 3, 7, -8, -5, 7, -11, -16, -2, 10, -2, 2, 15, 6, -15, 15, 5, -1, 34, 23, 2, -17, -1, 2, 0, -11, 10, -1, 3, -13, -13, 1, -15, -9, 16, -20, -5, 3, 13, 18, -8, 17, 1, -26, -10, 10, 28, -1, -5, -15, -26, -1, -28, 19, 11, 11, 29, -29, -22, 12, -6, -17, 17, -3, 7, 29, -19, 45, -17, 4, -25, -4, 10, 1, 11, -16, -7, -8, 23, -9, -24, -19, 10, 7, -14, 11, -14, -1, -1, 10, -5, -8, 33, -9, 15, -16, -2, 15, -5, -21, 3, 14, -3, 1, -13, -21, 15, -36, 29, -2, -29, 7, -6, -1, -13, -33, 10, -13, 39, -7, -5, -23, -22, 12, 18, -7, 11, 1, -3, -30, -3, -14, 2, -6, 1, -15, -4, -4, -16, -5, 16, -8, -4, -27, -5, -3, -18, -19, -19, 21, -12, 15, -7, -28, -16, -13, 5, 6, 0, -11, 10, 10, 5, -6, -8, -33, -3, 2, 3, 16, -4, 15, 24, -22, 20, 9, 6, -1, 18, -17, 11, 12, 22, 8, 38, 15, 0, -28, 17, -11, 10, 38, -9, 1, -1, -33, -9, 17, -16, -42, 19, 12, -17, -5, 22, 14, -7, 2, 13, -14, -14, -6, 11, 29, -5, 5, 6, 12, 17, 26, 4, -7, -4, -1, -37, -42, -5, -4, 1, -20, 16, 6, 11, 1, -11, -2, -12, 16, -10, -15, 14, 11, -30, 5, 18, 27, -9, 8, 1, 2, 1, -2, -4, -39, -29, -18, 19, 1, 13, -32, 20, 30, -9, -17, -5, 19, -7, -25, 10, 9, -20, -6, 2, 13, 15, -15, 1, 7, 27, 33, 11, 16, 13, 16, -11, -16, -5, -20, 26, 2, 6, 11, 17, -3, 9, 17, -7, 0, 8, 8, 13, -1}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0 {-47, -75, -24, -38, -44, -71, -17, -49, -16, -9, -20, -9, -56, -67, -60, -49, 4, -32, -45, -6, -18, -20, -27, -32, -11, -11, 6, -30, -46, -4, -20, 5, -15, -31, -14, 34, -7, -13, -23, 4, -6, -7, -4, 1, -11, 7, -8, 3, -8, 3, 0, 7, 4, 0, 4, 11, 12, 5, -7, 7, -47, -75, -24, -38, -44, -71, -17, -49, -16, -9, -20, -9, -56, -67, -60, -49, 4, -32, -45, -6, -18, -20, -27, -32, -11, -11, 6, -30, -46, -4, -20, 5, -15, -31, -14, 34, -7, -13, -23, 4, 0, 11, -13, -14, -6, -2, -7, 2, -6, -3, -6, 5, -1, -15, -14, 2, 9, 0, -7, 5}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0_DEC_BITS {6}

#define GRU_3_BIAS_LSHIFT {5}

#define GRU_3_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0 {30, -48, -17, 13, 3, -46, -31, 3, 13, 22, 14, -41, 32, 3, 79, -9, 1, 14, -22, -1, -7, 10, 13, 31, 13, 12, -25, 27, 31, 0, -21, -9, -15, 59, 1, 2, -20, 50, 35, 18, -12, 37, -55, 2, -18, 0, -8, 62, -30, 18, 33, -10, 7, 49, 2, -32, -40, -31, 0, -17, 8, -22, -54, 17, -20, -6, 30, -32, -22, -23, -15, -27, 11, -27, -60, 14, -2, 2, -8, 16, -10, -23, 25, 31, -24, 36, 3, -36, -28, -10, -21, -51, -6, 12, -10, 8, 39, 24, -16, -16, 11, -23, -37, -1, -32, -38, 28, 40, -6, -15, -9, -12, 38, 22, -16, -32, 13, -28, 1, 19, 27, 28, -11, -5, 51, 1, -7, 18, -3, 33, -54, -49, 1, 0, -24, 15, -25, -44, -11, 39, -3, 35, 21, -1, 13, 10, -46, -14, -6, 12, 7, 62, -37, -9, 11, 36, 1, 18, 2, -12, -5, -7, 28, 42, -23, 54, -30, 41, -23, -19, -16, -6, 27, -40, 73, -33, -35, 35, -6, -9, -5, 58, 21, -10, -36, -6, 31, -3, 24, -75, -2, 26, -10, 21, 41, -15, 52, 49, -3, -1, 1, 18, 14, -37, -10, 8, -13, -27, 29, -2, 30, -13, -2, -24, 54, 31, -31, -44, 11, -33, 34, 47, -10, -7, 6, 15, 2, 1, -77, 31, 17, -24, -7, -27, 28, 3, 3, -25, -24, 39, 6, -4, 12, -60, -13, 32, 18, 22, -22, 40, 18, 14, -33, 0, -21, -41, 6, -16, -17, 11, 14, 23, -23, 13, -29, -2, -1, -7, -19, -23, 9, 19, -12, -3, -11, 23, 27, 16, 21, -39, 3, -2, -15, 12, 6, 9, 7, 4, 15, -10, 33, 69, 9, 20, -14, -20, -19, 21, 35, -1, -1, -3, -10, 13, 14, -37, 14, 2, 1, 10, -7, 6, 19, 28, 1, 12, -35, -19, 48, 12, -7, 6, 24, 9, -6, 7, -5, -5, -5, 1, 19, 10, 16, 13, -6, -7, -3, -10, 10, 17, 5, -1, 7, -48, 51, 25, 7, -4, 26, 8, -19, 22, 32, 20, -44, -1, -3, 25, 38, -1, -7, -47, 13, -24, -35, 16, 23, -18, 23, -41, 5, 18, -6, -14, 23, -13, 11, 17, -12, -44, 26, -15, -52, -17, -68, -4, -37, -9, -2, -10, 3, -4, -6, 10, -12, -48, 9, 15, 0, 16, 14, 22, -8, -26, -27, -6, 9, -6, 25, 7, -30, -7, -37, -1, 51, 11, 11, -35, -7, 14, 70, 3, 3, 30, -21, -13, -27, 31, -61, 0, -31, -8, 21, 1, 0, -8, 9, -17, -24, -11, 6, -1, -2, 9, 25, 13, -43, 1, 36, -2, 36, 64, 25, 24, -24, 31, -6, 49, -9, -3, 20, -7, -7, -32, -5, 20, 8, 17, 14, -4, -20, -14, 18, -18, -4, -4, 67, 23, 50, 3, -2, 19, -30, -7, 13, -15, 40, 17, 44, -4, 50, 23, -7, -37, -16, -10, 7, -8, 7, 23, 18, 11, -15, -47, 25, -5, -8, 33, 16, -6, 11, 29, 41, 81, -25, -8, -18, 40, 16, 2, -28, -18, -21, -10, 16, 14, 25, -5, -35, -2, 62, 6, 29, -30, 17, -21, 113, 40, -11, -13, 2, -18, -7, 17, -58, -21, 1, -9, 4, -7, -41, -37, 8, -21, -46, 10, -20, -41, -7, 8, 20, 29, -43, -13, 37, -38, 27, 6, 30, -13, 10, 24, 36, 9, -35, -14, -12, -7, -4, -40, 28, 1, 35, 2, 22, -26, 18, -38, -11, 5, -62, 42, 12, -50, 16, 29, -41, 64, 28, -5, 33, 27, -11, 0, -22, 46, 37, -28, -3, -33, -6, 10, 2, 5, -22, 14, 41, 20, 0, 14, -38, -6, -15, 23, 10, -2, 27, 29, -5, -48, 12, -23, -6, 5, -5, 36, 41, 2, -8, -28, 8, -9, -1, 28, 13, 36, -17, 14, -8, 9, 13, -2, 19, 8, 20, 2, 10, -3, -2, 0, -26, -6, 12, 6, 4, 33, -11, -13, 28, -11, -27, -2, -25, 2, 12, -15, -16, 14, -11, -6, -15, -17, 14, 2, -22, -19, 6, -8, -23, -12, 4, 5, -2, -35, 21, 9, -15, -4, -4, -37, 21, -9, -26, -2, 1, 7, 32, 1, -5, -24, 24, 17, 16, 1, -1, -21, 17, 0, -23, -26, 16, 10, 10, -9, 18, 10, 10, 11, -29, 16, -2, 17, -14, -16, -25, -34, -9, -21, -51, -16, 43, 28, 9, 22, -20, 45, 5, -29, -5, -49, 29, 39, -20, -12, 8, 2, 10, 28, 3, -6, 0, -11, 0, -9, 32, 28, 5, 14, 3, -52, -3, 37, -10, 6, -39, -52, 9, 28, 54, -17, -17, -23, -10, 26, -11, -24, 11, 23, 18, 16, -3, -12, 13, 21, 7, -2, -32, -40, -10, 7, 1, 7, -5, -2, 10, -23, 23, -40, 2, -6, -11, 7, -16, -3, -4, -3, -6, -24, 1, 9, -1, -10, -1, 17, -24, 15, 6, 8, -11, -7, 5, 6, -12, -15, 11, 18, 26, 2, -30, 3, -13, -1, 8, 5, -1, -2, -7, 28, 25, 11, 4, 3, -7, 19, 0, 2, 17, 10, 9, 12, -20, 18, 15, -18, 13, 12, 25, 14, -23, -28, -13, -4, -2, 13, 16, -35, -5, 9, 4, 1, -34, 8, 8, 10, 20, -4, -16, -23, -17, -13, -6, 1, 6, -11, 27, 12, 19, 22, -33, -21, -5, -10, -29, -4, 0, -16, 13, 10, 44, 13, 2, -25, -10, 8, 7, -17, -8, -14, 11, 10, 20, 25, -16, -35, -17, -5, -17, 0, 7, 1, -17, -14, -9, -27, 10, 20, 26, -13, 11, 24, 12, 16, -1, 0, 8, 6, -25, 3, 3, -8, -2, 12, -14, -13, 11, -15, 12, 14, -4, -3}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0 {17, 47, -47, -7, -79, -19, -29, -83, -48, -63, -95, 57, -60, 14, -93, 73, 33, -1, 57, 19, 63, -22, -53, 22, -35, -36, 2, -3, 99, -30, 87, 15, -42, 7, -11, 8, 64, -39, -77, 2, 12, 51, 67, 37, 13, 48, -63, 8, 0, -35, -42, 2, 70, -59, 84, 2, -42, -1, 49, 42, -85, 31, -53, -33, -25, 17, -35, 5, 17, 2, 7, -39, -46, -4, -14, 1, -4, -23, 57, 26, 52, 25, 10, 57, -60, -43, 4, -17, -13, 1, 7, -19, -7, -52, -64, 42, 41, 23, -91, 5, -17, -7, 55, 8, 17, -39, 42, -2, 40, -27, 45, 17, -28, -50, 1, -64, -55, 20, -81, 0, -74, 104, -33, 42, 106, 23, 26, 29, 14, -12, 3, 4, 52, 22, 23, -19, -57, -28, -27, 35, -13, 75, 17, -21, -45, 14, 3, 80, 29, -26, 68, -21, -35, -25, -32, 5, 13, -46, 19, -17, -54, -54, 17, 7, -6, -8, 52, 91, 24, -18, 14, 3, 29, 6, 29, 43, -103, -35, 35, 23, 5, -38, 10, -114, 62, 23, 62, 21, 27, 29, 54, 8, 62, 47, -77, 18, 46, -17, 27, 9, -29, 4, -26, -35, -24, -6, 27, 26, 4, -23, -35, 13, -48, -86, -8, 89, -55, 28, -22, 33, 35, -71, -9, 31, 56, -5, -20, -25, 31, -31, -35, -20, -31, -26, -9, -100, 34, -29, -48, 36, 28, 32, -48, 42, 7, -5, 7, 43, 28, -35, 3, -69, -11, 53, 8, 96, -50, -75, 9, 14, 14, 2, 40, 60, -8, -91, 39, 78, 74, 17, -24, -62, 62, -42, 5, -2, -21, -59, -68, 14, 53, 59, -12, 9, 41, 67, 42, -19, -9, -40, 8, 17, 8, 8, 32, -9, -17, 29, 7, 78, 3, -69, 6, 4, -42, -27, 111, 42, -2, 1, -83, 18, 10, -3, 48, -10, -19, 11, -4, 6, -40, 40, 14, -33, -3, 4, -79, 6, 2, 14, -16, 21, 108, -39, -15, -2, -23, 1, -31, -45, -93, 12, -102, -25, -27, -23, 24, 29, 26, 95, 29, 40, -65, -67, 41, 8, 2, 10, -23, -32, -14, -7, -16, 27, 35, 1, 4, 26, -42, -9, -24, 12, 38, 3, -34, 42, 43, -77, 102, -20, -72, -46, -43, -48, -15, 18, -93, -45, -103, -1, -65, 12, 5, 39, 26, 5, -72, -25, 13, 48, -41, -55, -44, -54, 32, 14, 0, 25, 15, 19, 22, 49, -8, 5, -13, -14, -36, -14, -16, -20, -17, -2, -20, 25, 76, 29, 20, 47, 45, 34, -52, -33, -33, 45, -29, 2, -10, -31, 13, -74, -3, 16, -10, -17, 48, 29, 11, 26, -38, 15, -12, -25, -9, -47, 32, -16, -67, -18, 21, -33, -10, -5, -26, 64, -7, 3, 6, 108, -66, -24, -73, 19, -25, -77, -8, -38, 31, 11, 58, -7, 48, -64, -11, 13, 38, -83, 10, 94, 42, 7, 0, 10, -5, 15, -63, -56, 29, -20, 5, -10, 54, 6, 22, -106, 14, -9, -45, 101, -27, -3, -23, 33, -11, 44, 4, 48, 13, 15, -24, 26, -2, -25, -38, -18, -2, -19, -23, -19, 22, 3, -11, -42, -4, -23, -45, 33, 35, -1, -26, 22, 10, 0, 23, 18, -2, 47, -4, -21, 31, 28, -19, -51, -47, -15, -23, 38, -14, 25, -28, -35, 18, 35, -45, 8, 49, -26, -6, 24, 101, -40, -53, -23, 5, -6, -26, -33, -28, 24, -7, -2, -26, 4, -52, 1, 5, 20, -17, -35, 115, 39, 25, -19, 11, -55, 28, -9, 38, -36, -14, -24, 11, 39, -54, 5, 57, -62, 33, 27, -18, 16, -31, -31, -5, -16, 4, 31, -18, 6, 7, -6, 45, 2, -58, -38, -35, 7, -39, 29, -5, 28, 16, -52, -9, 44, 23, -43, -11, 44, 8, 18, -2, -33, -11, 5, 43, -21, -20, 14, -4, -5, -40, 65, 17, -13, -10, 88, -20, -23, -23, 39, -9, -12, 84, -4, -14, -21, -9, -36, -30, 36, -36, 47, 35, -19, -42, -6, 3, 5, 26, 4, 30, 39, -12, 28, -9, 1, 27, 27, 8, -2, 25, -4, -48, -30, -14, 32, 17, 23, -48, 15, 35, 4, 9, 11, 0, -4, 20, 4, -44, -53, 55, -23, 15, -38, 17, -4, -84, -19, -18, -4, -20, -63, 0, 22, 69, -17, -10, -48, -20, -63, -61, -16, 2, -14, -29, 26, 5, 51, 51, 16, 23, -28, 39, 28, 27, 6, 54, 23, 1, -34, 5, 36, 36, -36, -41, 31, 16, 5, 40, 24, -42, 6, -14, -12, 23, -11, -43, 61}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0 {49, 56, -1, 13, 74, 15, -3, -55, 15, 47, 14, -41, -21, -19, -11, 73, 31, 5, -22, -11, -53, -16, -42, 19, -30, -38, -27, -20, 8, 2, -37, -47, 5, 9, 14, -16, 1, -15, 1, -7, 16, -2, -9, -4, 12, 9, -20, -19, 49, 56, -1, 13, 74, 15, -3, -55, 15, 47, 14, -41, -21, -19, -11, 73, 31, 5, -22, -11, -53, -16, -42, 19, -30, -38, -27, -20, 8, 2, -37, -47, 11, 19, 12, -16, 12, -19, -13, -7, 23, -4, -15, 2, 18, -2, 11, -22}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0_DEC_BITS {6}

#define GRU_4_BIAS_LSHIFT {6}

#define GRU_4_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0 {-40, -14, 8, 20, -21, -5, 0, 26, -31, 8, 8, -15, -44, -3, -8, 36, 15, -15, 3, -25, 23, -4, -49, -8, -1, 8, 19, -14, 65, -28, 95, 19, -3, 14, 15, 13, 18, -3, -21, 35, 17, -27, 13, 36, 35, -3, -55, 18, 4, 28, 10, 13, 32, -5, 38, 30, -8, 9, 15, 3, -38, 4, -37, -2, 20, 7, 0, 32, -10, -34, -11, 0, -7, -20, -13, -31, -25, -36, -4, 17, 12, 38, 12, -23, 26, 12, -29, 8, 19, 10, 5, 10, -11, 13, 6, 19, 17, -4, -47, -21, 16, -2, -15, 37, 1, -5, -2, -23, -11, 31, 27, 0, 53, -2, 26, 46, -7, -6, 13, 3, -21, -23, 1, -15, -33, 21, 0, 15, 24, 9, 10, 39, 4, -2, 13, 15, 7, -21, -8, 8, -12, -4, -29, -31, 24, 0, 0, 6, -13, 14, -15, -21, 9, -11, 1, 17, 13, 13, 16, 24, -15, 16, 5, 9, 32, 14, -4, -23, -17, 1, -19, -45, -30, -14, -22, -5, 55, 0, -16, 7, 26, 5, 12, 27, -9, -4, -13, -4, -3, -44, 1, -8, -8, 24, 56, -20, 12, -8, 46, -2, -28, 19, 17, -17, -23, -19, 7, 15, 29, 22, 17, -20, -38, -6, 23, -3, 33, 4, -8, -22, -55, -7, -22, 10, 1, 18, 1, -2, 1, -26, 4, -17, -1, 4, 30, 35, 0, -36, -11, -26, -15, 21, -3, -29, -2, -31, -35, 25, -17, -26, 16, -10, 16, -4, 19, 19, 13, 23, 4, -16, -5, 6, -25, 0, 12, 5, -33, -2, -5, -23, 10, -32, 8, 0, 9, -5, 69, 7, 13, 16, 16, -6, -6, 2, 10, -1, -58, -13, 25, 2, -23, -57, -1, 8, -15, -37, -1, -24, -32, 2, -1, -21, 0, 11, 9, 7, -10, -5, 3, 0, -14, -5, -24, -38, -16, 19, -5, -12, -2, 2, -10, 8, 24, -38, -76, -11, -31, -14, -26, -7, 0, -8, 34, -28, 28, 21, -10, 15, -17, -47, 7, -13, 1, -13, 15, -12, -19, 4, -11, 44, 6, -22, 9, 65, 38, -15, -2, -7, -13, -13, 0, 22, -5, -18, -1, 55, 22, -3, -10, -27, 8, -5, -27, -63, 48, -4, 38, -23, 0, -10, -22, -24, 1, 13, 4, -3, -29, 10, -21, 7, -17, -11, 46, -8, 1, 16, 13, -14, -13, 0, -17, -17, -13, 39, 13, 27, -32, 19, -3, 2, 0, -3, 63, 13, 86, -3, -5, 7, -14, -9, 6, 13, -3, -3, -2, 32, -19, -4, 1, 11, -31, -10, 17, 9, 6, 11, 7, -24, 44, -5, 4, 0, -8, -15, -3, 4, -27, 24, -4, 29, 1, 10, 15, -10, -7, -7, 1, 22, 4, -3, 23, 6, 13, 20, 0, 2, 3, -21, -24, -1, 0, 0, -17, -16, -9, -2, 13, -4, 16, 4, -38, -6, 13, -30, -9, -10, 21, 12, 3, -21, 15, -4, 27, 13, 5, 26, 6, -2, 16, 22, 1, -34, -19, -14, 6, -27, 2, -7, 2, 19, 5, 6, 10, -5, -9, 40, 37, -16, 12, -12, -8, -21, 12, 8, 17, -4, -13, 15, -13, -28, -2, -19, 5, 7, -30, -1, -9, -13, -16, -8, 24, -4, 17, 10, -12, 31, 5, 14, 16, 7, -1, 21, -3, 14, 5, -2, -30, 30, -15, -4, -10, -21, 25, 10, -11, 4, -6, -14, 8, 3, -18, -28, 0, 13, 0, -7}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0 {-29, -10, -5, -15, -4, -7, 31, -21, -11, -27, -31, -26, -52, -17, 25, 10, -24, -8, -5, -5, -31, -1, 16, 45, -14, -13, 11, -24, 3, -12, 23, -17, 28, -13, -5, -13, 4, -36, 2, -23, -21, -24, -18, 22, 11, 0, 17, -3, 4, -1, 34, -9, 0, -24, -6, 7, -39, -12, -3, -7, -15, -9, 3, 17, -25, -16, -5, -21, -16, -13, -10, 18, 9, -26, -13, 9, -8, -48, 0, -69, 3, -14, -2, 18, 10, 12, -9, -1, -16, -14, -1, 24, -19, 2, 29, -10, 0, -6, 41, -18, -6, 24, 44, 0, -41, -28, -27, 7, -44, -38, 14, -5, 5, -14, -11, 20, -9, -22, 9, -19, -12, -5, -7, -21, -11, -32, 0, -2, 16, -7, -20, -39, -5, 0, 5, -4, -39, -42, 18, 19, -13, -10, -12, 42, 8, 6, -28, -28, -11, -1, 18, -4, -13, 3, 10, 12, -18, -6, -7, 27, 4, 3, -2, 16, -54, -9, -5, 27, -2, 8, 14, 28, 20, 10, -5, 93, -20, 7, -6, -36, 5, -22, -1, 16, -7, 36, -6, -3, -4, -16, -14, -9, -32, 2, -7, 9, -26, 1, -20, -27, -6, 9, -10, 7, -15, 16, 8, -17, -7, 8, -4, 43, -20, 11, -4, -38, -47, 12, -36, 24, -44, -4, -7, -45, -5, -13, 8, 3, 26, 9, -2, -22, 8, -30, -13, -10, -9, -14, -14, 49, -2, -16, -24, -30, 37, -13, 28, 18, -13, 11, 28, 0, 29, -5, -11, 28, -12, -4, -43, 28, 34, -19, 13, 21, -9, -27, -5, -36, 21, -6, 30, 33, 22, -12, -7, 6, 25, -6, -14, 37, 10, 7, 26, -47, -4, -57, 8, 15, 20, 22, -5, 30, -10, 26, -33, 20, 20, 13, 0, -31, 34, -3, 17, 24, 30, 12, -14, -9, 7, 10, -7, -11, 17, 16, 3, -23, -1, -18, 0, -32, 6, 3, -33, -19, 4, 5, 11, -36, 12, 0, 22, 18, 4, 3, 11, 7, 16, -11, 0, 20, 17, 12, -1, 8, 37, 15, -11, 6, 23, 13, -4, 22, 36, -11, 22, 20, 9, 35, 1, 15, 8, -10, -33, -20, 17, 9, -14, 4, -12, -16, -16, 12, -16, 2, -10, 0, 19, -32, -6, 0, 16, 20, 24, -26, 1, 0, -21, 38, 3, 12, -17, 21, 7, -19, -53, 29, 13, 3, -15, 11, 10, -5, 11, -2, 2, 25, 15, -33, 32, -1, 0, 14, 3, 7, -21, 13, -5, -3, -4, 25, -32, -2, -23, -2, 4, -18, 2, -8, 51, 0, -19, 1}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0 {53, 85, 43, 55, 74, 56, 77, 33, 67, 45, 48, 57, 14, -2, 13, -11, 29, 1, -6, -15, -8, -13, -27, -6, 8, -1, -18, -8, -3, 7, -3, 28, 16, -12, -10, -11, 53, 85, 43, 55, 74, 56, 77, 33, 67, 45, 48, 57, 14, -2, 13, -11, 29, 1, -6, -15, -8, -13, -27, -6, -3, 9, -14, -9, -5, -4, -3, 13, 8, 1, -8, -19}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0_DEC_BITS {6}

#define GRU_5_BIAS_LSHIFT {6}

#define GRU_5_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_1_KERNEL_0 {29, 25, -23, -8, -4, -27, 0, -17, 31, -29, -16, 10, 45, -72, 15, 25, 25, 46, 81, 3, -29, -20, -3, -6, -25, -20, 8, 9, -30, -13, -46, -16, 59, 7, 2, -3, -33, -17, -9, 30, 10, -46, 25, 29, 26, 8, 9, -30, 18, 43, 49, -24, 60, 24, 20, 22, -14, 13, 24, -22, 1, 17, -8, -4, -1, 36, -16, 44, 19, 42, -13, -41}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_1_BIAS_0 {-89, 0, -54, -24, 70, 32}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {8}

#define DENSE_1_BIAS_LSHIFT {4}

#define DENSE_1_OUTPUT_RSHIFT {9}


/* output q format for each layer */
#define GRU_3_INPUT_OUTPUT_DEC 7
#define GRU_3_INPUT_OUTPUT_OFFSET 0
#define GRU_3_OUTPUT_DEC 7
#define GRU_3_OUTPUT_OFFSET 0
#define GRU_4_OUTPUT_DEC 7
#define GRU_4_OUTPUT_OFFSET 0
#define GRU_5_OUTPUT_DEC 7
#define GRU_5_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 3
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

const nnom_io_config_t gru_3_input_config = {
    .super = {.name = "gru_3_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_3_gru_cell_3_kernel_0_data[] = TENSOR_GRU_3_GRU_CELL_3_KERNEL_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_kernel_0_dim[] = {3, 60};
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

const nnom_shape_data_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_dim[] = {20, 60};
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

const nnom_shape_data_t tensor_gru_3_gru_cell_3_bias_0_dim[] = {2, 60};
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
    .units = 20
};

const nnom_rnn_config_t gru_3_config = {
    .super = {.name = "gru_3"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_4_gru_cell_4_kernel_0_data[] = TENSOR_GRU_4_GRU_CELL_4_KERNEL_0;

const nnom_shape_data_t tensor_gru_4_gru_cell_4_kernel_0_dim[] = {20, 48};
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

const nnom_shape_data_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_dim[] = {16, 48};
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

const nnom_shape_data_t tensor_gru_4_gru_cell_4_bias_0_dim[] = {2, 48};
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
    .units = 16
};

const nnom_rnn_config_t gru_4_config = {
    .super = {.name = "gru_4"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_5_gru_cell_5_kernel_0_data[] = TENSOR_GRU_5_GRU_CELL_5_KERNEL_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_kernel_0_dim[] = {16, 36};
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

const nnom_shape_data_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_dim[] = {12, 36};
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

const nnom_shape_data_t tensor_gru_5_gru_cell_5_bias_0_dim[] = {2, 36};
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
    .units = 12
};

const nnom_rnn_config_t gru_5_config = {
    .super = {.name = "gru_5"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {12, 6};
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

#endif //MODEL_23_NNOM_H