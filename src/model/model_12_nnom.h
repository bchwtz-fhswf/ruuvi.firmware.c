#ifndef HAR_GRU_CNN_NNOM_H
#define HAR_GRU_CNN_NNOM_H

#define APP_ACTIVITY_MODEL_NAME har_GRU_CNN_nnom
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
#define TENSOR_LSTM_12_LSTM_CELL_12_KERNEL_0 {-43, -30, -26, 34, -13, 15, -4, 8, -10, 16, -27, -42, -22, 40, 10, -21, -49, -37, -38, -30, 4, -9, 4, 26, 47, 8, 22, 23, 1, -24, 38, 37, 12, -34, -9, 14, 2, 41, -5, -35, 19, 14, -6, -1, -43, -7, -26, 4, -5, -25, 45, 14, 7, 6, 77, 10, 11, 40, 2, 12, -45, -7, -41, 34, -18, 13, -8, -42, -19, -5, -16, -6, 16, 15, 30, -56, -24, 14, 3, -11, -2, -7, 3, -9, 41, -57, 31, 37, 22, -15, 52, -44, 18, 12, -8, -9, -51, -20, -34, -13, 26, 17, -42, -41, -1, -30, 1, 6, -42, -48, -23, 19, 11, 39, 25, 15, -1, 25, -47, 1, -68, 22, 7, -27, -24, -20, -16, -17, 1, -8, 41, 22, 20, -6, 16, -1, -22, 20, 20, 15, 27, -10, 9, 32}

#define TENSOR_LSTM_12_LSTM_CELL_12_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_12_LSTM_CELL_12_RECURRENT_KERNEL_0 {-4, -65, -50, 89, 6, 16, -8, 29, 35, 24, -31, -10, -12, -18, -30, -43, 53, -15, 31, -34, 26, -26, 21, 18, 8, 19, -5, -31, 27, -9, 31, 11, 10, 36, 36, 19, 47, 75, -11, -42, -18, 95, -18, 88, -20, 26, 16, -10, -18, 58, 22, 1, 30, 26, -45, -13, 29, -35, -26, -20, 0, 41, 28, -35, 16, -36, -74, 18, 15, 17, 0, 9, 42, -28, -11, -46, 87, -8, -21, -32, -55, -3, -6, 5, -63, -18, 12, -20, -24, 4, 19, -17, -36, -2, -63, -31, 56, -25, -11, -2, 51, -72, 6, 1, 13, -19, -44, 25, -32, 92, 6, 17, -10, -36, 39, -3, -23, -5, 43, -11, -56, -17, 55, 25, -47, -23, 55, 106, 60, 6, 48, 28, 51, 7, 32, 13, -32, 7, 22, 14, 10, 19, -23, 44, -16, 6, -12, -8, -15, 43, -15, -2, -16, -1, -34, 9, 22, -49, 0, -12, -50, -7, 14, 3, -31, -45, -19, 33, -38, -29, -11, 4, -45, 27, 39, 18, 44, 16, -20, -3, 17, 49, -13, 20, 4, 10, 15, -7, 9, -27, 13, -30, 19, -32, -25, 75, 12, 1, 0, -24, -27, -17, -56, 4, -27, -31, 36, 16, 29, -17, 15, -3, -23, 21, -68, -13, -15, -9, -30, -6, -11, -19, 18, 20, -12, -24, -19, -2, 9, 12, 5, 1, -13, 24, -7, 26, 6, 37, 12, -42, 0, 9, 49, 15, 29, 19, -43, 34, -32, -18, -33, 5, -6, 4, -35, -7, -7, 9, -27, 24, 4, -8, 51, 37, 19, 13, -75, -67, 41, 22, -53, -81, -31, -8, 1, 0, -30, -1, 25, -33, 68, -5, 46, -31, -31, 28, -2, -10, -4, 16, -8, -10, -17, 5, -5, 27, 7, 11, 0, -2, 18, -21, 9, 22, 8, -3, -1, 26, -31, 3, 17, -29, 5, -7, 14, -3, -7, -7, 16, 15, -24, 9, -19, -10, 5, 9, 24, 9, 35, -22, 24, -14, -7, 28, 1, 0, -15, -18, -3, -9, 1, -11, 11, -23, 18, -12, 9, 3, 6, 9, 13, -20, 6, -6, 14, -12, -3, 16, 19, -1, 1, 5, 9, 16, -30, -4, 4, -6, -14, 17, -17, -2, 28, -14, 7, 1, -23, -5, -28, 6, 23, -9, -9, -28, 17, 45, 0, -27, -7, -13, 13, -10, -4, -28, 3, 20, 0, -6, -15, -7, 16, 18, -28, 0, 2, 10, 2, 14, 2, -4, -3, 12, -14, 46, 10, 3, -4, -11, 3, -1, 18, -27, 15, 16, 0, -31, 28, 1, -18, -18, 8, -18, -28, 22, -30, 9, 7, 1, -29, 42, 22, -20, -18, -9, -23, -44, 0, 11, -12, -17, -11, -12, 2, -9, 4, 14, -62, -2, 54, 20, -41, -2, 18, 47, 86, 10, -13, 34, 64, 22, 14, 1, 21, 19, -19, 27, -31, -3, 11, 3, 11, 36, 27, 14, 12, -4, -72, -29, 17, -9, -51, -43, 26, -3, 23, 58, 10, -51, 4, -4, 19, -2, 5, 47, -6, -13, -4, 20, -7, 22, 30, 28, -12, -2, -26, 14, -21, -12, 40, 3, -34, 58, 16, 14, -35, 39, 3, -44, 52, -14, -3, -1, 76, -25, -46, 16, 38, -2, -6, 20, -13, 56, 6, 26, -7, 52, -11, 28, 25, -4, -13, 41, -27, 32, 30, 26, -49, -28, 65, 48, -2, 29, 20, 5, -3, 65, 15, 25, 32, -37, 45, -15, -6, 6, -4, 0}

#define TENSOR_LSTM_12_LSTM_CELL_12_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_12_LSTM_CELL_12_BIAS_0 {11, -28, -18, -43, 9, 45, -12, 41, -6, 2, 75, 67, 46, 36, 58, 59, 65, 41, 25, 62, 34, 61, 85, 8, 3, 6, -2, -6, -3, 4, 7, 0, 4, 4, 3, 8, 12, 33, -8, 9, 18, 65, 99, 22, 54, 5, 94, 118}

#define TENSOR_LSTM_12_LSTM_CELL_12_BIAS_0_DEC_BITS {6}

#define LSTM_12_BIAS_LSHIFT {5}

#define LSTM_12_OUTPUT_RSHIFT {4}

#define TENSOR_LSTM_13_LSTM_CELL_13_KERNEL_0 {23, 5, 16, -12, 18, 49, -58, 1, -27, 10, -2, -5, -7, 27, 38, -41, 15, 27, -25, -11, -29, 15, 96, -47, 0, 10, -39, 20, -30, 13, -13, -6, -4, -74, 3, 0, 48, -19, -33, -44, 36, -28, 34, -15, 46, -36, -28, -10, -12, -17, -46, 30, 56, -21, 6, -5, 1, -7, 32, 26, -31, 4, 8, 4, 19, 0, -24, -9, -8, 45, 17, -27, -6, -10, -15, -1, 13, -52, 11, -26, -50, 1, -14, 1, -1, 18, 5, 13, 61, -8, -46, -7, -2, -29, 25, 2, 10, -37, -30, -31, -8, 29, -33, -33, -3, 23, 29, 26, -31, 5, 18, -10, -36, 26, 56, -27, -12, -16, 25, -8, -67, -17, -1, 19, -32, -108, 21, 18, 13, -39, 65, 5, 19, -18, -24, 20, -8, -7, -66, 17, -26, -4, -44, -38, 45, -46, 13, 13, 27, 28, 2, -23, -9, -5, -40, 51, -44, 6, 17, 4, 67, 3, -7, 15, -40, -16, 44, 39, 11, -8, -43, 4, 24, -11, 6, -20, -85, -29, -34, 26, 18, -47, 3, 9, -12, -18, -15, 40, 24, -90, -8, -47}

#define TENSOR_LSTM_13_LSTM_CELL_13_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_13_LSTM_CELL_13_RECURRENT_KERNEL_0 {-36, -29, -92, -11, 6, 33, 14, -44, -23, -11, -34, -16, -22, -3, -7, 10, -5, -7, -38, 10, -2, 6, 2, -19, 9, 0, 32, -14, 8, 26, 28, 6, -14, -1, -4, 14, -23, 19, -24, -10, 18, 12, -18, 3, -15, 7, -27, -31, -38, 7, -26, 8, -1, 20, 6, -42, -2, 8, -37, 16, 8, -16, 11, -5}

#define TENSOR_LSTM_13_LSTM_CELL_13_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_13_LSTM_CELL_13_BIAS_0 {38, -14, 27, 20, 91, 52, 62, 23, 10, -20, -16, 9, 32, -28, 39, 27}

#define TENSOR_LSTM_13_LSTM_CELL_13_BIAS_0_DEC_BITS {6}

#define LSTM_13_BIAS_LSHIFT {6}

#define LSTM_13_OUTPUT_RSHIFT {5}

#define TENSOR_CONV1D_12_KERNEL_0 {-2, 9, 85, -31, -31, 9, 67, -42, -35, 19, 38, -41, -28, 19, 38, -46, -37, 19, 47, -75, 54, -33, 29, -27, 14, -19, 10, -16, 23, -17, 23, -36, 41, -24, 24, -30, 40, -12, 58, -12, -25, -7, -24, 30, -2, -32, -20, 4, -5, -37, -22, -16, -8, -38, -1, -6, -11, -72, -54, -45, -44, 7, -52, -5, 13, 0, -10, -14, 18, -25, -8, -49, 11, -50, -5, -28, -5, -39, -56, -5, 14, -49, 30, 29, -50, -27, -59, -1, -20, 0, 23, 35, -15, 9, 31, 2, -53, 43, -24, -11, 21, -15, 38, -59, 11, -16, 19, -18, 35, -28, 33, 19, 35, -10, 31, 20, 45, 7, 1, 12, -81, 3, -9, -25, -26, -19, 50, -11, 28, 3, 26, 4, 54, 1, 16, 18, 27, 1, -100, 10, -7, -32, -4, -41, -40, -20, -25, -21, -33, -25, -20, -23, -42, -20, -16, -24, -38, -30, -45, -25, -34, 49, -48, 23, 37, 32, -11, 20, 7, 27, -27, -2, -4, 30, -8, -9, 30, 31, 81, 23, 42, -12, 45, 49, 51, -26, 23, 43, 6, -22, -25, -12, -22, -6, -31, -26, -58, 12, -13, -23, -5, 9, 45, -70, 9, -8, 8, -15, 25, -1, 17, 16, 33, -13, 24, 37, 26, 4, 3, 13, -1, 14, -24, 45, -27, 27, -38, -1, 38, -9, 24, -20, 28, -6, -29, -15, 34, -11, 30, 73, 16, 22, -30, 52, 65, 11, -44, -22, 13, 10, -15, -17, -6, 17, 29, -26, 34, 22, 75, -10, 10, -14, 43, -55, -15, -16, 8, -27, -2, -16, 0, 5, 47, -15, 28, 32, 18, 5, -5, 32, 34, 70, 0, 29, -8, 54, -44, 4, -39, 47, -31, -20, 9, 23, -33, -34, -47, 14, -54, -86, 18, -27, 0, 56, -32, 6, -43, 20, -31, -9, -29, 40, -1, -4, -41, 5, 83, -8, -32, 85, 50, -47, 53, 21, 22, -16, -20, -15, -51, -16, -39, 16, -36, -24, -32, 10, 105, -4, 49, 53, 64, -29, 40, 57, 27, -13, 24, 22, -10, -5, 28, 29, -27, 1, 40, 26, 34, -9, 79, 61, 8, 17, -11, 32, 32, 13, 4, 10, 10, -7, -50, 34, 45, -14, 10, 58, 52, 22, 22, 86, -47, -19, -65, -118, 58, 6, 32, 45, 26, -8, -46, -37, -5, 22, -17, 3, -5, 27, 64, 28, 17, 46, -41, 1, 44, 21, 8, 10, 52, 22, -1, -23, 34, 14, 30, -46, 20, 14, 75, -65, -32, 3, -40, -24, -45, -13, -29, -10, -2, 2, -23, 3, 71, -16, 41, 37, 65, -2, -25, 21, -43, 22, 12, -12, -46, 7, 9, -54, 16, 17, 54, 5, 9, 11, -21, 2, -83, 33, -15, -16, 75, -22, 70, 51, 64, -23, 4, 27, 9, -11, -37, -18, -47, 14, -41, -18, -70, 22, -35, -47, 40, -12, -13, -30, 21, -13, -42, -51, 30, -7, -51, -34, 21, -5, -30, -4, 36, -4, -24, 27, -28, 16, 9, -15, -19, 32, 25, 23, -28, 37, -41, 4, -5, 34, 34, 33, -22, 50, 3, 11, -33, 11, -63, -37, -16, -13, -25, -20, -20, 8, 0, -19, 28, -8, 29, 0, 49, 2, 40, -3, -26, -9, -48, 33, -14, -36, -31, 7, 2, -30, -15, -18, 1, -48, 1, -10, -1, -71, -47, -23, -69, 15, -25, -36, -7, -19, 30, -9, 47, -22, -2, -38, 63, -14, -19, 26, 13, -18, -85, 16, 39, -21, 37, 45, 12, -1, 17, -7, -11, 2, 16, 13, -30, -8, 36, 21, 17, -11, 52, 40, -7, -18, 51, 10, 48, -25, 77, 33, 40, -20, 8, 20, -7, -11, -42, -14, -64, -8, -59, -2, -39, 39, 31, -2, -3, 14, -9, 23, -9, 20, -54, 15, -15, -7, 24, 26, -31, 24, 36, 8}

#define TENSOR_CONV1D_12_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV1D_12_BIAS_0 {-61, -8, -14, 19, -46, -70, -30, -49, -54, -36, -66, -56, -49, -77, -38, 8, -24, -17, -80, -41, -29, -22, -62, -22, -67, -73, -27, 1, -37, -48, -50, -85}

#define TENSOR_CONV1D_12_BIAS_0_DEC_BITS {7}

#define CONV1D_12_BIAS_LSHIFT {6}

#define CONV1D_12_OUTPUT_RSHIFT {9}

#define TENSOR_CONV1D_13_KERNEL_0 {1, 0, 2, 1, 0, -5, -1, 2, 3, -7, -1, -6, -7, 3, 0, -6, 2, 3, 3, 0, 0, -5, -1, -2, 5, -5, -5, -3, -7, 0, 0, -2, 1, -9, 5, -6, -1, 2, 3, -6, -5, 1, -6, -6, -6, -6, -3, 0, 4, -7, 2, -3, 1, -2, -3, -3, 3, -7, -8, -1, -3, 5, -8, -4, -5, -1, 2, -4, 0, -5, -1, 4, 1, 0, 1, 1, 2, -2, -4, -4, 0, -7, -2, 1, 2, -7, -2, -1, -2, -5, 3, -7, -2, -1, -6, -5, 10, 1, -7, -14, 22, 5, -35, 6, -9, 19, -12, 7, 5, -28, 3, 8, 2, 18, -3, -40, 2, -23, -61, 22, -6, -37, -9, -5, -22, 8, 22, -43, 3, -2, -17, -31, -18, 16, 2, 15, 15, -27, 16, -3, 10, 23, -17, -1, 10, 8, 14, -40, 29, 16, -7, -11, 16, -15, 17, -24, -2, 8, -26, -15, 20, 19, -26, -31, -3, 17, 1, -22, -14, 6, 1, -9, -4, 10, 10, -9, -15, 3, -10, -33, 17, -4, 2, 9, -12, -13, 0, -29, -24, 5, 3, -33, -38, 12, -36, -5, 20, 20, 6, -56, 0, 8, 24, -9, -20, 22, 4, 4, 1, 5, 5, 62, -14, -1, -4, -3, -15, -1, 14, -37, 8, 6, -4, 10, -34, -1, -14, -17, 17, 15, -3, -26, 2, 3, 4, -20, -8, 15, 13, 5, -10, -6, 5, 17, -19, -13, -7, 0, -10, 8, 7, -16, -11, -5, -4, 17, 1, -24, 3, 3, 6, 2, 4, -11, -1, 3, 4, -17, -1, 8, 22, -2, -17, -23, -13, 7, -5, -19, -7, 10, -2, 9, -8, 6, -3, -26, 0, 7, -4, -3, -6, -3, -5, 6, -6, 4, 2, -7, -6, -3, -5, -7, 2, -3, -4, 1, -7, -1, -1, -4, -6, -6, -6, -9, 1, 0, -6, -6, -2, 1, 0, -5, 2, -7, 0, 0, 0, 1, 4, 0, 3, 3, 0, 4, -6, -6, 4, 0, 2, -3, -5, 2, 4, 2, -7, 0, -3, 2, -7, -2, -2, -1, -7, 2, 3, 0, -9, -6, -6, -7, -6, -7, 3, -8, 0, -1, -2, 0, -1, -2, -2, -4, 1, 2, 3, 2, -4, 0, -6, -1, -7, 0, -1, 0, 0, -2, 0, -2, -5, -2, 0, 0, 3, -3, 1, -3, -9, 2, 0, 2, -1, -3, 0, 1, -1, -5, -5, 3, -1, -5, -2, -2, -1, -8, -1, -3, 1, -5, 5, -11, -6, 5, -2, 4, 1, -4, 2, -7, -7, -1, -2, -2, -7, 1, -3, -3, 3, 1, 1, 1, 2, -8, -2, -8, -3, 0, -7, 4, -3, -2, -6, -6, -1, 1, -1, -3, -5, -8, 0, 1, 3, -5, -4, 0, -7, -4, -6, -5, -6, -5, 0, -5, 1, 2, -6, -1, 1, 2, -3, -6, -12, 9, -15, 3, -19, 2, 10, -21, -17, 9, 1, -13, -14, 3, 21, 4, 25, -3, -22, 21, 4, 6, 5, 20, 0, -25, 2, -9, 4, 7, 18, -26, -33, 8, -8, -5, -23, 9, 12, -39, -21, 11, 4, -13, -3, 3, 18, 12, 19, -8, -18, 27, -4, 14, -5, 19, 5, -34, 13, -8, 6, -7, 2, -39, -56, 6, -8, 9, -34, 10, 18, -35, -38, 20, 3, -9, -24, 4, 20, 12, 22, -14, -33, 4, -7, 16, -5, 18, 8, -45, 12, -3, 9, -17, 12, -52, -3, -5, -2, -2, -1, 1, -6, -10, -2, 3, -4, 2, -8, 1, -1, -4, -4, -1, -3, -4, -7, 0, -4, -7, -5, -7, 5, -8, -5, -4, -7, -7, 1, -8, -8, 1, -3, 4, -5, -3, -7, 2, -2, 3, -9, -5, -3, 7, -4, -3, 2, -4, -4, -8, -4, -4, 1, 2, -6, -4, -5, 1, 2, 1, -8, -8, 3, -2, 0, -7, 2, -3, -1, 2, -2, -6, -6, -1, -6, -1, 2, -1, -7, -4, 1, 4, -4, 2, -4, -4, 3, -5, -3, 6, -4, 1, 3, -8, -9, -9, -9, -1, -3, -4, -1, 3, 3, -7, 0, -5, -4, -7, 1, -3, 5, 2, 4, -8, -1, -4, -6, -6, -1, 3, -3, 6, -4, -4, 2, 4, -9, 1, 3, -3, 0, -1, -1, -2, -1, 3, -6, 0, -5, -3, -2, -3, 2, 3, -6, -6, 0, -5, 4, -4, -5, -7, -5, -2, -7, 5, -3, -6, -3, -3, -7, 0, 2, -1, 0, 2, -9, -4, 3, -8, -7, 0, -4, -7, -6, -6, 2, -1, -10, -9, -7, -7, -3, -2, -7, -8, 1, -6, 1, -8, -6, -7, -6, -5, -8, 0, 0, -6, -2, 4, -9, -3, -4, -4, 0, 1, -2, -7, -5, 2, 2, -6, -4, -3, 3, -5, -5, -7, -4, -5, -2, -6, -1, -1, -6, -2, -5, -5, -6, 2, 4, -8, -3, 1, -1, 0, -7, -2, 1, 1, -5, -8, -6, 0, -2, 2, -1, 2, 3, 3, -2, 1, 2, -10, 1, -4, 1, 3, -1, -8, -4, -4, -2, 1, -2, -6, 2, -5, -8, -6, -5, 2, -2, 3, -2, 2, 3, 0, -2, -5, -3, -4, 2, -4, 8, -28, -47, -31, 18, -14, -4, -19, -1, 8, -12, -6, 9, -7, 17, 6, 4, 9, 1, 29, 13, -14, 7, 12, 22, 13, -19, -36, 12, 2, 1, 2, 18, -25, -25, -40, 24, -28, -2, -4, 15, 0, -22, 3, 5, -18, 13, 0, 2, 6, 0, 8, 7, -1, 3, -3, 23, 16, -14, -16, 26, -4, -9, 19, 17, -35, -35, -54, 23, -17, 9, -5, 12, -17, -14, 10, 16, -5, -13, 2, 1, 15, 3, 14, 15, 7, 10, -23, 35, 27, 4, -30, 19, 3, -18, 25, -23, -8, 9, 5, -16, 8, 8, 1, 50, 8, 5, -33, 28, 13, -30, -16, -10, -72, -13, 0, 18, 13, -21, 0, 13, -11, 11, 7, -2, -50, 4, 1, -6, 3, 1, 5, -1, 19, 9, -5, 38, 15, 13, -38, 32, 16, -25, -27, -9, -63, -28, 15, 22, 7, -10, 27, 4, 5, 0, 8, 4, -42, 26, -8, -8, -12, 5, -1, -1, -1, -2, 3, 59, 22, 8, -55, 48, -2, -2, -40, -19, -61, -30, 27, 39, -14, -17, 28, 5, 12, -5, 7, -5, -52, 30, -1, -60, 10, -12, -4, -5, 2, -5, 12, -2, 10, 2, 4, 14, 6, -18, 15, 14, 8, -1, -34, 0, -5, 4, 7, 24, -14, -18, -11, 2, 1, 6, -2, -33, 5, -33, -8, -9, 10, -1, -17, -2, 5, 11, -6, 4, 12, -14, 12, 14, 8, 1, -28, -4, 4, 34, 3, 26, -11, -9, -25, 8, 8, -1, -5, -61, -8, -44, -26, -17, 11, 7, -108, -2, -6, 8, 6, 2, 14, -34, 17, 22, 15, 5, -29, 5, 16, 26, -13, 11, -19, 1, -35, 16, 6, 8, -9, -19, 34, 9, 3, 28, 2, -75, 3, 26, -36, 6, 11, 27, 44, 16, 22, -10, 25, -7, 24, 34, -56, 16, -40, -22, 2, -45, 13, -28, 32, -50, -6, -16, 29, 6, 9, 4, -18, -88, 6, 6, -49, -33, -3, 9, -14, 10, 24, -35, -2, -20, -12, 21, -50, 5, -59, -54, -15, -31, 11, -32, 3, -56, -29, -5, 40, 2, 7, 5, -46, -86, 1, -10, -66, -64, -48, 10, -65, 34, -1, -66, -25, -51, -2, 20, -83, -9, -66, -66, -16, -55, 3, -91, -32, -83, -32, 1, 14, -10, -22, 5, 22, 4, -2, -34, 23, 15, -23, -24, 17, -15, -1, 7, 12, -29, -36, -19, -6, -6, 23, 12, -6, 2, -14, -5, 3, 25, -40, 4, 4, 3, -11, 17, 11, -4, 1, -8, 0, 10, -26, -9, 6, -20, -2, -9, 6, -23, -20, -1, -6, 7, 5, 21, 7, 4, 6, -19, 11, -2, -9, 21, 4, -49, -51, 14, 10, 0, -9, 7, -10, 8, -7, 10, 8, -41, -2, -2, 24, 4, -13, 18, 7, 17, -13, 6, 20, 12, -39, -12, 26, -13, -2, 20, -3, 6, -2, 1, -4, 4, -1, 57, -18, 2, -4, 60, 10, 1, -26, -13, -6, 63, -27, 22, 7, -30, -10, 7, -34, 17, -3, -5, -3, -8, -1, 21, 9, -5, -5, 16, 10, 10, -1, 20, 5, 8, -13, 38, 6, -22, -50, -7, -5, -61, -24, -6, -2, -61, -2, 20, -32, 5, -5, 12, -1, 14, -16, 2, -1, -11, 7, -3, 16, 27, -26, -30, 0, 15, -12, -4, 16, -29, -15, 14, -17, -27, -18, -26, 21, -69, -5, 22, -38, 8, -10, 29, -8, 16, -20, -23, -10, -36, -43, 12, -23, -39, -12, 13, 17, -32, 21, 9, -4, 17, 18, 16, 18, 15, -13, -4, -12, -16, 22, -44, -19, -11, -36, -54, 9, -4, -5, -16, 11, -45, -38, -4, 19, 10, -15, 5, -7, 25, 5, -1, 23, 5, -12, -11, -4, -6, 2, 7, 26, -1, 3, -31, -6, 11, -42, -16, -10, -10, 8, -7, 26, -54, -25, 15, 18, 9, -41, -6, 15, 3, -37, -5, 11, 15, -39, -48, -4, -42, 8, 9, 7, 8, 14, 4, -6, 15, -48, -23, -6, 28, -15}

#define TENSOR_CONV1D_13_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV1D_13_BIAS_0 {-22, -57, 63, -17, -25, 96, -23, -27, -20, -19, -38, 18, 59, -64, -116, 39}

#define TENSOR_CONV1D_13_BIAS_0_DEC_BITS {8}

#define CONV1D_13_BIAS_LSHIFT {1}

#define CONV1D_13_OUTPUT_RSHIFT {8}

#define TENSOR_DENSE_6_KERNEL_0 {19, -16, 0, 19, -13, 22, -50, -62, -54, 4, -17, -1, 47, 9, 14, 26, 22, 18, -38, -18, -24, 9, -11, -8, -77, -81, -8, -36, 16, 35, -5, -4, 8, -29, 10, 54, 15, -2, -9, 18, 36, -6, 12, -52, -81, -50, 27, -27, -62, -23, -29, 4, -39, -46, -15, 55, 30, 13, -122, 83, 27, -96, 36, -32, 3, -82, -101, 22, -7, -43, -21, -24, 22, -29, -54, -39, 84, -98, 10, -106, -24, -97, 76, 9, -9, 48, 12, 3, -8, -66, -47, -28, -41, -86, -48, -57}

#define TENSOR_DENSE_6_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_6_BIAS_0 {-21, 1, -38, -107, 64, 77}

#define TENSOR_DENSE_6_BIAS_0_DEC_BITS {7}

#define DENSE_6_BIAS_LSHIFT {0}

#define DENSE_6_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define LSTM_12_INPUT_OUTPUT_DEC 7
#define LSTM_12_INPUT_OUTPUT_OFFSET 0
#define LSTM_12_OUTPUT_DEC 7
#define LSTM_12_OUTPUT_OFFSET 0
#define LSTM_13_OUTPUT_DEC 7
#define LSTM_13_OUTPUT_OFFSET 0
#define CONV1D_12_OUTPUT_DEC 4
#define CONV1D_12_OUTPUT_OFFSET 0
#define RE_LU_12_OUTPUT_DEC 4
#define RE_LU_12_OUTPUT_OFFSET 0
#define MAX_POOLING1D_6_OUTPUT_DEC 4
#define MAX_POOLING1D_6_OUTPUT_OFFSET 0
#define CONV1D_13_OUTPUT_DEC 1
#define CONV1D_13_OUTPUT_OFFSET 0
#define RE_LU_13_OUTPUT_DEC 1
#define RE_LU_13_OUTPUT_OFFSET 0
#define GLOBAL_AVERAGE_POOLING1D_6_OUTPUT_DEC 1
#define GLOBAL_AVERAGE_POOLING1D_6_OUTPUT_OFFSET 0
#define DENSE_6_OUTPUT_DEC 2
#define DENSE_6_OUTPUT_OFFSET 0
#define SOFTMAX_6_OUTPUT_DEC 7
#define SOFTMAX_6_OUTPUT_OFFSET 0

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

const nnom_io_config_t lstm_12_input_config = {
    .super = {.name = "lstm_12_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_12_lstm_cell_12_kernel_0_data[] = TENSOR_LSTM_12_LSTM_CELL_12_KERNEL_0;

const nnom_shape_data_t tensor_lstm_12_lstm_cell_12_kernel_0_dim[] = {3, 48};
const nnom_qformat_param_t tensor_lstm_12_lstm_cell_12_kernel_0_dec[] = TENSOR_LSTM_12_LSTM_CELL_12_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_12_lstm_cell_12_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_12_lstm_cell_12_kernel_0 = {
    .p_data = (void*)tensor_lstm_12_lstm_cell_12_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_12_lstm_cell_12_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_12_lstm_cell_12_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_12_lstm_cell_12_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_data[] = TENSOR_LSTM_12_LSTM_CELL_12_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_dim[] = {12, 48};
const nnom_qformat_param_t tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_dec[] = TENSOR_LSTM_12_LSTM_CELL_12_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_12_lstm_cell_12_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_12_lstm_cell_12_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_12_lstm_cell_12_bias_0_data[] = TENSOR_LSTM_12_LSTM_CELL_12_BIAS_0;

const nnom_shape_data_t tensor_lstm_12_lstm_cell_12_bias_0_dim[] = {48};
const nnom_qformat_param_t tensor_lstm_12_lstm_cell_12_bias_0_dec[] = TENSOR_LSTM_12_LSTM_CELL_12_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_12_lstm_cell_12_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_12_lstm_cell_12_bias_0 = {
    .p_data = (void*)tensor_lstm_12_lstm_cell_12_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_12_lstm_cell_12_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_12_lstm_cell_12_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_12_lstm_cell_12_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_12_lstm_cell_config = {
    .super = {.name = "lstm_12"},
    .weights = (nnom_tensor_t*)&tensor_lstm_12_lstm_cell_12_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_12_lstm_cell_12_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_12_lstm_cell_12_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 3,
    .units = 12
};

const nnom_rnn_config_t lstm_12_config = {
    .super = {.name = "lstm_12"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_13_lstm_cell_13_kernel_0_data[] = TENSOR_LSTM_13_LSTM_CELL_13_KERNEL_0;

const nnom_shape_data_t tensor_lstm_13_lstm_cell_13_kernel_0_dim[] = {12, 16};
const nnom_qformat_param_t tensor_lstm_13_lstm_cell_13_kernel_0_dec[] = TENSOR_LSTM_13_LSTM_CELL_13_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_13_lstm_cell_13_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_13_lstm_cell_13_kernel_0 = {
    .p_data = (void*)tensor_lstm_13_lstm_cell_13_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_13_lstm_cell_13_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_13_lstm_cell_13_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_13_lstm_cell_13_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_data[] = TENSOR_LSTM_13_LSTM_CELL_13_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_dim[] = {4, 16};
const nnom_qformat_param_t tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_dec[] = TENSOR_LSTM_13_LSTM_CELL_13_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_13_lstm_cell_13_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_13_lstm_cell_13_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_13_lstm_cell_13_bias_0_data[] = TENSOR_LSTM_13_LSTM_CELL_13_BIAS_0;

const nnom_shape_data_t tensor_lstm_13_lstm_cell_13_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_lstm_13_lstm_cell_13_bias_0_dec[] = TENSOR_LSTM_13_LSTM_CELL_13_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_13_lstm_cell_13_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_13_lstm_cell_13_bias_0 = {
    .p_data = (void*)tensor_lstm_13_lstm_cell_13_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_13_lstm_cell_13_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_13_lstm_cell_13_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_13_lstm_cell_13_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_13_lstm_cell_config = {
    .super = {.name = "lstm_13"},
    .weights = (nnom_tensor_t*)&tensor_lstm_13_lstm_cell_13_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_13_lstm_cell_13_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_13_lstm_cell_13_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 4,
    .units = 4
};

const nnom_rnn_config_t lstm_13_config = {
    .super = {.name = "lstm_13"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_conv1d_12_kernel_0_data[] = TENSOR_CONV1D_12_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_12_kernel_0_dim[] = {5, 4, 32};
const nnom_qformat_param_t tensor_conv1d_12_kernel_0_dec[] = TENSOR_CONV1D_12_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_12_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_12_kernel_0 = {
    .p_data = (void*)tensor_conv1d_12_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_12_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_12_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_12_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_12_bias_0_data[] = TENSOR_CONV1D_12_BIAS_0;

const nnom_shape_data_t tensor_conv1d_12_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_conv1d_12_bias_0_dec[] = TENSOR_CONV1D_12_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_12_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_12_bias_0 = {
    .p_data = (void*)tensor_conv1d_12_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_12_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_12_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_12_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_12_output_shift[] = CONV1D_12_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_12_bias_shift[] = CONV1D_12_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_12_config = {
    .super = {.name = "conv1d_12"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_12_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_12_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_12_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_12_bias_shift, 
    .filter_size = 32,
    .kernel_size = {5},
    .stride_size = {1},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling1d_6_config = {
    .super = {.name = "max_pooling1d_6"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2},
    .stride_size = {2},
    .num_dim = 1
};
const int8_t tensor_conv1d_13_kernel_0_data[] = TENSOR_CONV1D_13_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_13_kernel_0_dim[] = {3, 32, 16};
const nnom_qformat_param_t tensor_conv1d_13_kernel_0_dec[] = TENSOR_CONV1D_13_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_13_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_13_kernel_0 = {
    .p_data = (void*)tensor_conv1d_13_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_13_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_13_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_13_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_13_bias_0_data[] = TENSOR_CONV1D_13_BIAS_0;

const nnom_shape_data_t tensor_conv1d_13_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv1d_13_bias_0_dec[] = TENSOR_CONV1D_13_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_13_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_13_bias_0 = {
    .p_data = (void*)tensor_conv1d_13_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_13_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_13_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_13_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_13_output_shift[] = CONV1D_13_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_13_bias_shift[] = CONV1D_13_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_13_config = {
    .super = {.name = "conv1d_13"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_13_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_13_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_13_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_13_bias_shift, 
    .filter_size = 16,
    .kernel_size = {3},
    .stride_size = {1},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_average_pooling1d_6_config = {
    .super = {.name = "global_average_pooling1d_6"},
    .output_shift = 0,
};
const int8_t tensor_dense_6_kernel_0_data[] = TENSOR_DENSE_6_KERNEL_0;

const nnom_shape_data_t tensor_dense_6_kernel_0_dim[] = {16, 6};
const nnom_qformat_param_t tensor_dense_6_kernel_0_dec[] = TENSOR_DENSE_6_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_6_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_6_kernel_0 = {
    .p_data = (void*)tensor_dense_6_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_6_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_6_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_6_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_6_bias_0_data[] = TENSOR_DENSE_6_BIAS_0;

const nnom_shape_data_t tensor_dense_6_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_6_bias_0_dec[] = TENSOR_DENSE_6_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_6_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_6_bias_0 = {
    .p_data = (void*)tensor_dense_6_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_6_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_6_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_6_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_6_output_shift[] = DENSE_6_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_6_bias_shift[] = DENSE_6_BIAS_LSHIFT;
const nnom_dense_config_t dense_6_config = {
    .super = {.name = "dense_6"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_6_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_6_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_6_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_6_bias_shift
};

const nnom_softmax_config_t softmax_6_config = {
    .super = {.name = "softmax_6"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_6_OUTPUT_DEC};
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

	layer[0] = input_s(&lstm_12_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_12_lstm_cell_config), &lstm_12_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_13_lstm_cell_config), &lstm_13_config), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv1d_12_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(maxpool_s(&max_pooling1d_6_config), layer[4]);
	layer[6] = model.hook(conv2d_s(&conv1d_13_config), layer[5]);
	layer[7] = model.active(act_relu(), layer[6]);
	layer[8] = model.hook(global_avgpool_s(&global_average_pooling1d_6_config), layer[7]);
	layer[9] = model.hook(dense_s(&dense_6_config), layer[8]);
	layer[10] = model.hook(softmax_s(&softmax_6_config), layer[9]);
	layer[11] = model.hook(output_s(&output0_config), layer[10]);
	*state = model_compile(&model, layer[0], layer[11]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //HAR_GRU_CNN_NNOM_H