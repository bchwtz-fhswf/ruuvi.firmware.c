#ifndef MODEL_18_NNOM_H
#define MODEL_18_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_18_nnom
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
#define TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0 {-31, -27, -75, 12, -7, -24, 13, 36, -38, 25, -1, 3, -14, -13, -10, -88, 39, 6, -9, -24, 8, -9, -16, -2, -29, -23, -22, 20, 22, 28, -31, 36, 21, -17, -10, -12, -42, -46, -9, 13, -38, -46, 27, -53, 3, 44, -32, -11, 41, 43, 17, -31, -28, 1, -7, -38, 53, 5, -28, -9, -16, -15, -18, 45, -25, 47, 27, -16, 27, -11, 29, 29, 13, -20, -50, 5, -43, 3, 4, -52, -72, 4, -47, 17, 9, -22, -17, -58, 30, 10, -31, 11, -22, -18, -12, 5, 18, 5, 69, 63, 51, 10, 33, -39, 38, -2, 31, 14, -9, -11, 13, -17, -46, 51, 22, -27, 7, 4, 7, 1, 14, 15, -3, 48, 45, 31, -28, 52, 46, -15, 9, -4, 66, 6, 29, 36, -32, 43, 38, 48, -29, 3, 9, -1, -1, -27, -44, -6, -16, -22, -51, 7, 12, 9, -35, 24, -23, -13, 26, 20, 61, 63, -51, -77, 11, -34, -4, -10, -19, -10, -59, -1, 63, 18, -78, 18, -28, 12, -13, -13, -61, 0, 55, -61, -25, -28, 16, -18, 0, 50, -9, -8}

#define TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0 {44, 46, 56, -68, -15, -16, -1, 35, 17, -47, -15, 50, -34, 1, 5, 35, -23, 33, -40, -52, 44, -13, -5, 55, 12, 18, -28, -17, -5, -21, 12, 25, 22, -75, 67, -10, -14, -5, -53, -8, -14, -82, 25, -87, -30, -35, -9, -13, 4, -9, 58, -60, -4, -27, -68, 26, 20, -31, 28, 22, -17, -27, -23, 0, -30, 3, -12, 3, 10, 47, 42, 19, -7, 0, 23, -34, -20, -41, -38, 1, 9, -2, 40, -1, 16, 7, 44, -34, -17, 25, 58, 3, 60, -12, -34, 52, 3, 33, -23, 5, -52, -39, 18, 19, 15, 3, 0, 37, -50, 6, -25, 39, 10, 40, -20, 10, -14, -13, 41, 20, 7, 32, -43, -9, 43, 59, 3, 9, 2, -54, 27, -22, 46, -26, 57, -23, 16, 53, -28, 30, -28, 10, -39, 5, -30, 16, -12, -86, -6, 16, -21, 52, -10, -46, 39, -1, 10, -8, -4, -13, -7, 24, 31, 6, -38, -4, 45, -10, 3, 65, 65, 1, 4, 47, -16, -45, 45, 1, 30, -41, -7, -27, 36, 9, 7, 37, 29, -42, 46, -3, 33, -48, 62, -34, 65, -25, 18, 35, -61, 5, -13, 9, -12, -2, 13, 32, 12, 12, 22, 3, -8, -53, -5, -41, 18, -16, -41, 6, 25, 5, -19, -23, 61, 18, 5, -4, 3, 27, 32, -26, -39, 22, -29, 13, 11, -15, 42, -29, -6, 45, -24, 14, 27, -37, 20, 25, -23, 36, -29, 23, 46, -36, -72, -5, 25, 24, 6, 44, -4, -10, 15, 3, -9, 20, -18, -35, 43, -7, -14, 1, 31, -20, -23, 7, -9, 0, 15, 4, 1, 3, -26, 13, -4, -19, -5, 1, -15, -15, 0, -29, -15, -22, -21, 22, 14, -9, 15, -31, -3, 2, -19, 16, -3, 20, 28, -20, 1, -9, -27, -3, 11, -9, -38, -27, 10, 34, 26, 16, 7, 4, 45, -24, 33, -5, -5, 28, 5, 28, -23, -30, 37, -6, -4, 26, -28, 4, -13, 2, -9, 25, 11, 1, 22, -46, -45, -14, 26, -25, -8, -9, -24, 14, -7, 21, -40, -57, -39, 2, 14, -21, -42, 2, -38, -30, 1, -21, 42, -9, 6, 10, 17, -16, -1, 27, 8, 13, 21, 14, 16, -21, 10, -28, 5, 58, 29, -11, 1, 5, -16, 50, -7, 45, -11, 51, 9, 38, 38, 30, 5, 0, 10, 0, 12, -24, -25, 6, -31, -23, 17, 24, -14, 18, -33, 13, -4, 26, -17, -25, 12, 14, 13, -22, -29, -10, -14, 16, 0, -14, 24, -10, 12, 3, 32, 47, 4, -5, 14, 20, 2, 14, -4, -6, 16, 12, -26, -3, 33, 20, 34, 15, 11, 10, 12, -27, 60, 16, -10, 7, -17, 8, -8, -9, -16, 22, 4, -12, -1, -31, 7, 3, -15, 22, 2, -11, 3, 2, 0, -7, 2, 1, 3, 19, -51, -10, 1, -8, -19, 8, -8, -8, -28, -8, 16, 18, 18, -10, -12, -10, 10, 4, 25, -11, -11, 17, -8, 3, 32, 21, 11, 11, -10, -36, 6, 9, -43, -3, -15, -1, -4, 2, -2, 10, 10, -9, -8, 4, -1, 2, 3, -31, -9, -4, -16, 4, 8, -17, -9, -16, 2, 34, -10, 4, -3, -4, -5, 7, -10, -4, -6, -1, -3, 12, -2, 4, -11, 20, 11, 12, -7, -2, -15, 29, -13, 22, 7, 6, 3, -42, -7, 16, -7, 3, -6, -12, -5, -11, 6, 19, 16, -22, -9, 10, 0, -6, 16, -8, -5, 12, 13, -13, -11, -5, -9, -18, -2, -16, -8, -5, 4, -1, -20, 16, 6, 26, -7, -25, 25, -7, -13, -9, 30, -11, -2, -7, 2, 7, -8, 16, 24, 14, 0, 24, 7, 9, 23, 26, 24, -24, 18, 1, 7, -11, 22, 20, 6, -9, -11, -42, 7, -13, 9, -17, 4, 9, 1, -3, -4, -16, 14, -21, 11, -3, -8, -13, -4, 6, -20, -6, 11, -8, -1, 9, -20, 11, 5, 20, -5, 8, 27, -15, -14, -6, 2, -6, 28, -25, 8, -2, 13, -11, -2, -20, 18, -9, -17, 16, -6, -3, -16, -34, 25, -2, -7, -17, -5, -2, 16, 26, 16, -12, 4, 3, 8, 1, 3, -1, 1, -18, 1, 1, -5, -6, 11, -3, -7, 6, 9, -10, 16, 7, -6, -37, -9, -10, 16, 8, -8, 4, 0, -18, 10, 21, -25, 8, 10, -7, 14, -26, 7, -17, -8, -4, -22, -9, 15, 1, 8, 2, 6, -4, 3, -19, -1, -7, -3, -21, 11, -11, -18, -17, 3, 17, 14, -4, -25, -2, -13, -7, 6, 15, 32, 0, -9, -53, -3, 16, 12, -22, 32, 37, -23, -9, -4, -29, -20, 43, -6, -60, 14, -1, 11, 23, -1, -7, -39, -11, -11, 23, 0, -47, 1, -63, 5, -16, -8, 26, 10, -5, -14, -36, -4, -64, 1, -2, 1, 4, 52, 8, 45, -21, -41, -15, -20, -2, -11, -15, 3, 8, 41, -15, -11, -42, -34, -23, -9, -16, -7, 76, 16, -6, 8, -4, 13, 2, -27, -44, -33, 8, 7, -18, 41, 30, 20, -9, 7, -10, 9, -22, -15, 8, -10, -70, -15, 40, 17, 55, 3, -36, -39, -23, 5, -12, -1, 55, 5, 2, 22, 17, 15, 17, -2, 10, -26, -82, -17, -11, -13, 22, 44, 13, -45, -20, 18, 22, -17, 20, -9, -29, 21, -26, 25, 36, 14, 6, 21, 14, -14, 39, -41, 7, -10, 39, -19, -23, 20, -22, -3, 12, -16, 4, 18, 6, -47, 14, -20, -10, -4, 19, 24, -53, 34, 37, -39, -38, 19, 15, -13, 7, 34, 2, 6, -17, -23, -6, 9, 11, 28, 14, -21, -27, 0, 32, 7, 62, 27, 0, 12, 20, 35, 29, 21, -26, 7, 17, 24, -34, -19, 7, 0, 1, 9, 10, -10, 11, 42, 9, 3, -30, 15, -19, -21, 6, -34, 41, -22, 26, 16, 17, -20, 14, 57, -24, -18, -25, -28, 88, -34, 2, -33, 2, -12, -10, -18, 18, 0, 3, -25, 0, -42, 17, -7, 32, -2, 0, 7, 10, -24, 92, 5, -33, 11, 1, 1, -35}

#define TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0 {-40, 44, -28, -12, 17, 18, -34, 38, -1, 32, -16, 3, 37, 50, 0, -27, 72, 30, 45, 83, 58, 64, 52, 25, 83, 32, 30, 57, 62, 43, 42, 70, 8, 6, 3, 10, 10, -7, 6, -4, -4, -1, -8, -13, 1, -7, -6, 7, 39, 86, 19, 32, 4, 19, 23, 48, 17, 47, 12, 66, 39, 59, 34, 35}

#define TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0_DEC_BITS {6}

#define LSTM_3_BIAS_LSHIFT {5}

#define LSTM_3_OUTPUT_RSHIFT {4}

#define TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0 {14, 14, -13, -3, 19, 13, -1, 70, -10, -8, 6, -23, 5, -13, 50, -45, -12, -8, -8, -33, 33, -36, 5, 22, 16, 8, -4, 4, 6, 13, 7, 36, -29, -4, -21, 20, -15, 23, 32, -16, -6, 11, -14, 6, -6, -16, -29, 15, 3, 2, -36, 19, 21, 33, -8, 1, -11, -11, 23, 22, 6, -26, 15, 3, 59, -14, -11, 23, -6, -1, -41, -18, -20, 25, 42, -19, 8, 45, -8, 15, 5, 6, 19, -36, -23, -28, 16, 6, 10, -12, 9, 3, 27, -41, 30, 9, -22, 21, -22, 13, 7, -14, -11, -5, -15, -2, -13, 13, 18, 25, -14, 49, 9, 14, 6, -5, 0, 13, -28, 48, -18, 0, 44, 0, -45, 53, 6, -5, 17, 31, 17, 69, -19, 17, 9, 95, 2, -7, -16, -20, 0, 2, 21, -29, 22, 7, -28, 39, 4, -2, -5, -33, 8, 31, -11, 21, -9, 16, -8, 4, -22, -8, -6, -11, -4, 10, 16, 41, -22, -13, 4, -4, 12, -16, 24, -8, 3, 26, 10, 18, -14, 49, -16, 24, 20, -34, 52, 25, 12, -27, -27, -14, 44, 11, -15, -29, 12, 3, -18, 52, -1, -2, -2, 3, 7, -22, -59, -39, 7, 21, 38, -29, -41, 42, 41, -14, 18, -2, -3, 5, 38, 6, -9, -26, -6, -7, -19, 39, -7, -8, 8, 31, -18, -29, 27, -4, 7, -2, 48, -11, 11, -10, 1, -17, 25, 32, 1, 6, -1, 13, 33, 7, 15, -12, -2, -6, 36, 25, 10, 25, -33, 3, 1, -70, -39, -17, 9, -18, 14, 9, -4, 28, -1, 16, 3, 11, 1, 20, 9, -57, 2, 12, 40, -2, -14, -35, -7, -19, -6, -18, -13, -26, -7, -14, 23, 3, -30, -31, -25, -11, 25, -2, 20, -27, 8, -1, -16, -23, -10, -16, 6, -12, -2, -30, 28, 23, 26, 3, -16, 11, 12, -15, 5, -40, 37, -13, -7, 33, 18, -28, 40, 15, -4, 2, 27, -13, 15, 1, -35, 5, 2, 2, 1, 2, 9, -13, -38, -8, 15, -11, 5, -4, -2, -27, 0, -9, -27, 28, -6, 21, -23, 29, -39, 2, -39, 30, -49, 11, 8, -24, 26, -15, -24, -3, 12, 2, -11, -1, 11, -25, -13, 26, 30, -33, 18, 37, -18, -9, -69, 37, -25, 78, 5, -19, 21, -33, 50, -13, 14, -39, 5, 0, -18, -17, 4, -19, -11, 1, 28, 9, -7, 4, -18, 3, -10, 34, -18, -2, 3, 1, 31, 12, 29, 11, 0, -3, -5, -4, 29, -52, 26, -4, -18, 21, -15, 8, 14, 18, -10, 20, 4, -43, 38, 41, 51, -23, -63, -19, 33, -13, -37, -8, 10, 7, -36, 28, -24, 6, -1, 19, -17, -1, -73, -17, -12, 21, 25, -31, -18, -7, 28, -2, 28, -28, 3, -31, 17, -8, 6, 14, 5, -1, -20, -4, -7, -5, -8, 29, -7, -17, 29, -19, 29, 15, 46, 32, 13, -18, -7, 17, 23, 12, -26, 31, -8, 20, 24, -1, 15, 14, 20, -28}

#define TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0 {10, -11, 28, 4, 17, -21, 32, -2, -33, -60, 16, -3, 14, -49, 24, 9, 57, -32, 25, -8, 61, -16, 21, 40, 9, -31, -92, 4, 40, 2, -67, -49, -29, -62, 41, -42, -50, 14, -22, 25, 44, 36, 31, -59, 14, 13, -25, -5, -6, -57, 8, -15, -5, 1, -28, 1, -26, -115, 33, 13, -2, -8, -38, 77, 22, -12, -5, 30, 8, 3, 69, 15, -3, -28, -25, 0, 23, -50, -23, -10, 56, -14, 6, -45, 6, -22, 37, 22, 13, -41, -68, -9, 44, -12, 12, -1, 19, 40, 30, 12, -10, -16, -40, -2, -19, -8, 7, -42, 15, -8, -41, -47, -5, 31, -13, 55, -19, 14, -14, -7, 10, -12, -13, -11, -2, -10, -16, 26, -31, 17, 16, 0, -58, 0, -38, 14, 14, 0, 6, -15, -24, -53, 13, 0, 15, -14, 15, 24, -9, -13, -16, 23, 28, 7, -44, 8, -9, 7, 18, 10, -17, -21, 10, -14, -9, 41, -10, -21, -36, -7, -21, -9, 3, -26, 8, -49, -7, -8, 30, 7, 26, 15, 13, -31, -11, -40, -1, 39, 18, 13, 7, -11, 24, 8, 25, 34, -41, 49, -12, 7, -38, -91, 9, 17, 23, -44, -36, 27, 49, -4, 51, -22, -12, -16, 94, 41, 13, -43, -31, -29, -53, -5, 74, -42, -32, 25, -11, -24, -20, -8, -6, -3, -18, 1, -19, -29, -14, 3, -69, -22, -23, 14, 4, 5, -30, -3, 4, 74, -15, -22, -28, 4, -8, -20, -2, 29}

#define TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0 {-5, -8, -4, -3, -4, -16, -7, 0, 31, 31, 33, 36, 35, 69, 35, 36, 5, -2, -13, -4, 3, 10, 1, -3, 1, 9, 2, 18, 17, 17, 8, 17}

#define TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0_DEC_BITS {5}

#define LSTM_4_BIAS_LSHIFT {7}

#define LSTM_4_OUTPUT_RSHIFT {5}

#define TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0 {3, -19, -17, -9, -32, -51, -63, 3, -21, -15, 31, 17, -16, 36, -11, 5, 42, -18, -11, 15, -15, -41, -26, 0, 10, 19, -8, -9, -16, -64, -2, 5, 25, -14, 53, 10, 2, -16, 6, -24, 27, -2, 52, 16, 30, 56, 21, 7, -9, -17, -16, 42, 16, 3, 31, -3, 19, -33, 23, 26, 37, 17, 9, 30, 6, 17, -14, 51, -7, 10, -22, 23, 18, -18, 3, 9, -17, -12, -46, 71, 46, 17, 30, 46, 19, 38, 30, 25, -25, 0, 36, -17, -24, -9, -14, -68, 12, 2, 6, 11, 28, 15, 19, 20, 15, 10, -22, 26, 7, 4, -20, -10, 28, 2, 14, 28, 58, 40, 29, 49, 36, -13, 19, -2, 37, 6, 64, -5, -21, -1, -12, 21, 0, -13, 20, -5, -26, 36, -1, 6, 9, 23, -19, -33, 5, -20, -6, 0, -33, -11, -13, 17, -24, -11, -21, -11, -22, -25, 28, -31, 26, 1, 30, -16, 15, -14, 35, 9, -9, -15, -5, -18, 26, -11, 35, -28, 4, -7, -11, 20, 5, 5, 2, -31, -10, -19, -20, 12, -4, 25, -9, 4, -14, -4, -20, 42, -24, 18, -39, 43, 41, -21, 14, 1, 13, -10, -19, 63, 15, 35, 35, 36, 34, 34, 48, 55, -16, -22, 11, 3, -14, -42, 52, -22, 32, -1, 26, 33, 48, -19, 56, -10, 0, 2, 17, 25, 51, 30, 7, -3, 37, 43, 34, 13, 67, 19, 4, 48, 88, 53, -12, 16, 55, -41, 34, 10}

#define TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0 {-32, -24, -4, 4, -9, -18, 15, 23, -26, -18, -6, -10, 7, 4, -12, -24, -4, -18, -31, -31, -21, -20, 2, -8, -8, -26, 18, 32, -23, -2, 8, 24, -23, 29, 5, 16, 4, -25, 15, 6, -21, 6, 1, -9, -19, -4, 3, -3, -15, -9, -26, -5, -27, -20, -25, -16, 21, -6, 27, -9, -1, -10, 10, 24, 3, 1, -26, -11, 34, 11, -21, -13, 7, -8, 29, 32, -15, -16, 41, 14, 8, 23, 14, 33, 19, 33, 60, 30, 4, 7, -17, -41, -14, -4, -40, -36, 9, 2, -29, -11, -27, 1, -5, -35, -42, -23, 13, 0, -11, -8, 18, 60, 24, 14, 7, -2, 44, 19, 9, 23, -21, -9, -1, -31, 2, -5, -3, -36, -11, -12, -5, -4, 2, -11, 4, 3, -9, 0, 8, -9, -8, 4, -3, -6, -9, -21, 2, 2, 7, 5, -5, 9, 1, 21, -7, 6, -3, 6, -7, 4, -10, -4, -8, -17, 2, 6, 7, 5, -9, -15, 0, 4, 1, 5, 1, -4, -2, 6, -3, -10, -1, -5, -8, 0, 10, -4, 21, -41, -2, -9, -14, -3, -15, -19, -25, -8, 20, 10, -34, -19, 2, 2, 65, 35, -9, 0, 39, 15, -7, 18, -9, -8, 8, 40, 50, 29, 16, -7, -29, -19, -4, -6, -73, -33, -32, -25, 2, -14, -20, -21, -5, 2, -48, -31, 9, -16, -8, 6, 18, 3, 17, 37, 4, 6, 24, 17, 0, 4, -8, -41, 7, 12, 5, -21, 3, -7}

#define TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0 {-35, -49, -58, -34, -40, -14, -42, -48, 43, 65, 65, 51, 33, 36, 39, 54, 2, -3, -5, 0, -4, 7, 1, 2, -8, 10, 12, 27, 11, 1, 0, 2}

#define TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0_DEC_BITS {5}

#define LSTM_5_BIAS_LSHIFT {7}

#define LSTM_5_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_1_KERNEL_0 {-65, -8, 28, 102, 51, 1, -44, -35, 67, -5, 40, 22, -7, -19, 41, 6, -62, 22, 37, -4, 16, 18, 4, -42, 24, -30, -5, -32, -1, 9, 9, 50, 4, 56, 4, -74, -7, -51, 37, 18, 9, -12, -45, -55, -27, 29, -8, -3}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_1_BIAS_0 {-40, 109, -93, 20, -96, -6}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {8}

#define DENSE_1_BIAS_LSHIFT {4}

#define DENSE_1_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_3_INPUT_OUTPUT_DEC 7
#define LSTM_3_INPUT_OUTPUT_OFFSET 0
#define LSTM_3_OUTPUT_DEC 7
#define LSTM_3_OUTPUT_OFFSET 0
#define LSTM_4_OUTPUT_DEC 7
#define LSTM_4_OUTPUT_OFFSET 0
#define LSTM_5_OUTPUT_DEC 7
#define LSTM_5_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 4
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

const nnom_io_config_t lstm_3_input_config = {
    .super = {.name = "lstm_3_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_3_lstm_cell_3_kernel_0_data[] = TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0;

const nnom_shape_data_t tensor_lstm_3_lstm_cell_3_kernel_0_dim[] = {3, 64};
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_kernel_0_dec[] = TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_3_lstm_cell_3_kernel_0 = {
    .p_data = (void*)tensor_lstm_3_lstm_cell_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_3_lstm_cell_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_data[] = TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dim[] = {16, 64};
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dec[] = TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_3_lstm_cell_3_bias_0_data[] = TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0;

const nnom_shape_data_t tensor_lstm_3_lstm_cell_3_bias_0_dim[] = {64};
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_bias_0_dec[] = TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_3_lstm_cell_3_bias_0 = {
    .p_data = (void*)tensor_lstm_3_lstm_cell_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_3_lstm_cell_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_3_lstm_cell_config = {
    .super = {.name = "lstm_3"},
    .weights = (nnom_tensor_t*)&tensor_lstm_3_lstm_cell_3_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_3_lstm_cell_3_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_3_lstm_cell_3_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 3,
    .units = 16
};

const nnom_rnn_config_t lstm_3_config = {
    .super = {.name = "lstm_3"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_4_lstm_cell_4_kernel_0_data[] = TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0;

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_kernel_0_dim[] = {16, 32};
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_kernel_0_dec[] = TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_4_lstm_cell_4_kernel_0 = {
    .p_data = (void*)tensor_lstm_4_lstm_cell_4_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_4_lstm_cell_4_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_data[] = TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dec[] = TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_4_lstm_cell_4_bias_0_data[] = TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0;

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_bias_0_dec[] = TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_4_lstm_cell_4_bias_0 = {
    .p_data = (void*)tensor_lstm_4_lstm_cell_4_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_4_lstm_cell_4_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_4_lstm_cell_config = {
    .super = {.name = "lstm_4"},
    .weights = (nnom_tensor_t*)&tensor_lstm_4_lstm_cell_4_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_4_lstm_cell_4_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_4_lstm_cell_4_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 8
};

const nnom_rnn_config_t lstm_4_config = {
    .super = {.name = "lstm_4"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_5_lstm_cell_5_kernel_0_data[] = TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0;

const nnom_shape_data_t tensor_lstm_5_lstm_cell_5_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_kernel_0_dec[] = TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_5_lstm_cell_5_kernel_0 = {
    .p_data = (void*)tensor_lstm_5_lstm_cell_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_5_lstm_cell_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_data[] = TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dec[] = TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_5_lstm_cell_5_bias_0_data[] = TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0;

const nnom_shape_data_t tensor_lstm_5_lstm_cell_5_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_bias_0_dec[] = TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_5_lstm_cell_5_bias_0 = {
    .p_data = (void*)tensor_lstm_5_lstm_cell_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_5_lstm_cell_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_5_lstm_cell_config = {
    .super = {.name = "lstm_5"},
    .weights = (nnom_tensor_t*)&tensor_lstm_5_lstm_cell_5_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_5_lstm_cell_5_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_5_lstm_cell_5_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 8
};

const nnom_rnn_config_t lstm_5_config = {
    .super = {.name = "lstm_5"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {8, 6};
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

	layer[0] = input_s(&lstm_3_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_3_lstm_cell_config), &lstm_3_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_4_lstm_cell_config), &lstm_4_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_5_lstm_cell_config), &lstm_5_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_1_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_1_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_18_NNOM_H