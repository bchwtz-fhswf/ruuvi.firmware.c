#ifndef MODEL_24_NNOM_H
#define MODEL_24_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_24_nnom
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
#define TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0 {-41, 24, 66, 18, -57, 25, -18, 21, -44, 43, 31, 28, -30, -24, 3, -42, -10, -3, 38, -37, 29, 19, 61, -62, 4, -43, -9, 29, 40, 36, -37, 59, -63, 28, -39, 4, 34, 12, 12, 4, 38, 9, 45, -43, 28, 47, -23, 34, 27, 21, -31, -23, 15, -21, 39, -52, 5, -15, -35, 6, 69, 13, 66, -26, -17, -20, -40, -12, 4, 25, -22, 45, 5, 13, -31, -13, -23, 14, 13, -23, 39, -51, 7, -32, -1, -16, -18, 35, 26, -21, 23, 29, 15, -41, -4, -8, 33, 2, -67, 37, -64, 4, -49, 26, 25, 19, 28, 22, 48, 5, -43, 28, 0, 16, -35, -33, -7, -49, -31, 37, 7, -38, 24, 25, 50, 34, -62, 42, 20, -42, -38, 10, -40, -5, -35, 23, -46, -15, 4, -35, -10, 66, 7, -2, 14, 2, 21, -20, -43, 21, -26, -22, -24, 52, -26, 26, -39, -7, -2, -46, -11, 20, 8, -33, -2, 60, 3, 11, -22, -41, 29, 30, 28, 24, -44, 35, -61, -9, -31, 16, 50, 1, 29, 1, 66, -11, 62, -25, 17, -28, -23, 29}

#define TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0 {30, -17, -35, -12, 12, 1, 31, -16, 35, -15, -20, -12, -51, 3, 36, -41, 24, 2, -5, -12, 31, -15, 29, -18, 1, -15, 63, -1, 6, 5, -26, -28, 7, 14, -26, -3, 45, 19, -13, 1, 25, 18, 9, -6, 10, 30, 11, -20, -10, -2, -13, -10, -11, -1, -10, 40, -8, -7, 15, -12, -9, 10, -21, -3, 34, 3, 19, 17, 31, 24, -17, -13, 27, -38, -75, 21, 34, -29, -57, -6, -7, -44, 24, -4, 0, -31, 45, 4, 53, -56, 30, 35, 25, -39, 22, 6, 0, -2, -31, 44, -18, 28, 2, -61, 15, -37, -23, 30, 31, -54, -30, -19, -8, -11, -17, 17, -8, -5, 2, 49, -15, 8, -2, 15, 56, 1, 36, -7, -61, 9, -5, -72, -44, 24, 23, 8, -24, -1, -43, 25, -11, 61, 63, -40, -19, 0, 23, 29, -64, 25, -21, 2, -9, 2, -41, -31, -15, 25, -11, 23, -23, -21, 95, 14, -2, -17, 8, -1, -69, 17, -22, -24, -35, 49, -29, -31, 21, 1, 40, -44, 1, -15, 24, -8, 23, 21, 8, -23, 30, -3, -23, 0, -11, 10, -47, -9, -9, -34, -13, -22, 46, -50, -56, -46, 18, -5, 1, 20, -22, -22, 5, 43, 0, -11, -30, 12, 3, 39, 11, -2, 7, -35, 7, -38, -43, 18, 59, -17, 3, 58, 21, -46, -21, 31, -22, 39, 1, 12, 10, 54, 47, -16, -12, -21, -20, -38, -6, 9, 19, -46, 83, 18, -33, -19, 7, -16, -15, -21, 19, 2, 5, -26, -15, 15, -11, -39, -3, 3, 12, -27, 14, 36, -20, -2, 14, 28, -14, -18, 12, -13, 1, 12, 4, 20, 30, 21, 15, 3, 23, -37, 4, 0, -6, 24, 1, -31, -23, -22, -5, 4, -16, -56, -2, 21, -5, -8, -17, 20, 4, -10, -17, -9, 33, -28, 19, -24, 11, -19, -17, -38, 15, 56, 2, 28, -13, 18, 15, -11, -14, 44, 11, 4, 70, 19, 1, 4, 0, -21, 61, -8, 18, 7, -28, 32, 64, -7, 16, 122, -16, -2, -7, -9, -16, 4, -17, -2, -36, -16, -28, -33, -71, 10, 0, -24, 25, 46, 1, 0, 47, 14, -31, -7, -5, 0, 17, -54, 0, -7, -22, 109, -27, -21, 21, -25, 0, -8, -26, 23, 32, -11, -31, 54, 18, 29, -45, -29, 15, -66, 19, 63, -13, -33, 31, 34, 5, -11, -9, 9, 25, 10, 13, -6, 25, -9, 15, -13, -23, -42, 41, 34, -8, -29, -8, 23, 20, -20, 16, -26, 18, -10, -46, 28, -25, 44, 17, -4, 1, -19, -1, -19, -1, -22, 29, 6, -1, 21, 29, -31, -17, -8, 1, 3, 8, 51, 31, -26, 4, -1, 10, 15, 11, 14, 13, -11, 0, 10, -13, 23, -21, -10, 20, 37, -11, 15, -9, 7, 21, 39, 8, 57, 10, 36, 9, -21, -13, -23, -36, -26, 13, -6, -16, -21, 41, 10, -2, -42, -15, -7, -22, -13, 29, 23, -50, 6, -52, -2, 35, -27, -26, 13, 27, 19, -9, -3, 2, -12, -2, 17, 3, -22, -10, -4, -2, 17, -6, -3, -4, -11, -17, -21, 8, -7, -9, 13, -1, 8, -9, -5, -26, 2, 8, -10, 8, 28, 12, 2, 18, 24, 4, 7, 5, 4, -12, -5, -11, 29, 14, -12, 1, 12, -4, 14, 15, -1, -14, -1, -5, -3, 17, -2, -22, -5, -1, 1, -16, 7, -3, 2, 4, -9, 9, 33, 22, -15, -3, 12, 5, 9, -26, -13, 13, -15, 0, 12, -10, 14, -17, -4, -7, -1, 4, 22, 5, -15, 2, 33, -7, -24, 7, 8, -5, -18, -8, 3, -25, 17, 7, -5, 20, -12, -34, -3, -6, -8, -15, 5, 8, -16, 10, -16, 10, 15, -33, -18, -16, -22, -7, 2, -11, -9, 6, -3, -3, -25, -9, 18, 18, -13, 14, 6, -19, 21, -12, 23, 20, 6, -3, -3, 2, -2, -14, -8, -2, -2, 6, 14, 6, -10, -1, 10, -3, -9, -14, 4, -2, -7, 6, 4, 17, 3, 7, -22, 17, -4, -21, 6, 9, -17, 1, 11, 22, -9, -6, 6, 12, -2, -29, 28, 35, 9, -1, -6, 4, -22, 6, -19, 1, -13, -3, 10, 8, 26, -15, 13, -3, -1, -52, -11, 9, 2, 9, -7, -24, 1, 19, 7, 7, 17, 13, -13, 11, -25, -6, 27, -11, -3, -3, 8, 1, 15, 17, -24, -12, -18, 8, -2, 12, -8, 11, 21, 11, 19, -2, 16, -10, 2, -6, -27, -10, 21, -23, 6, 8, -15, -5, 22, -33, -6, 0, -24, -1, -4, -4, -48, -11, -61, 10, 6, -7, -6, 26, 4, -11, 10, 5, -25, 27, -56, -4, 9, 7, -11, -13, -18, 20, 18, 10, -24, 6, -44, -23, -9, -15, -26, 27, 3, -8, 43, 3, 22, -4, 19, -18, -2, -13, -2, -1, -20, 2, 0, 2, 9, -6, 21, 33, 0, 24, 33, -10, 16, -22, 6, 20, 18, 23, -6, 6, -10, 0, -27, -7, 26, -22, 12, 20, 18, -28, -15, -6, -31, 27, 3, 24, 28, 32, 11, 38, -19, 8, 16, -4, -38, 53, -16, 28, 0, -27, 41, -41, 53, -50, -80, -22, -41, -4, 22, 35, 34, -20, 4, -30, -6, -2, -7, 37, -1, -2, 3, -32, 2, -48, 50, 24, -13, 62, -2, -42, -30, -27, -23, -24, -23, -13, -17, 18, 29, -57, 15, -2, 14, 23, 22, 19, -38, 30, 14, -27, 33, -15, 11, -17, -24, -32, -39, 11, -31, -29, -16, -15, 3, 33, 19, 16, 23, -29, 7, 1, 12, 44, 37, 5, 22, -45, 51, -25, -54, 56, -6, -25, -22, -5, -10, 8, 4, -16, -37, 8, 22, -47, -52, -8, 24, 1, 4, 4, -25, -26, -54, 13, -17, -16, -6, 5, 38, 2, -43, -6, 11, -5, 44, 5, -4, -22, 27, 5, 48, -11, 29, 1, -18, 24, -6, 25, 5, 38, -36, 13, -39, 19, -25, 31, -11, -7, 43, 44, 34, 35, 54, -28, 21, -2, -3, -18, -18, -26, 32, -40, 58, -16, 53, -34, 0, 23, 53}

#define TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0 {0, 48, 10, 31, 47, -26, -48, 77, -42, 20, -12, 13, -48, 1, 32, 79, 73, 59, 57, 49, 33, 59, 95, 38, 58, 46, 39, 43, 87, 67, 31, 51, 12, -1, -3, -2, 2, 3, 1, 4, 9, -10, -8, -7, 0, 3, 3, -1, 47, 58, 64, 72, 56, -11, -5, 108, -1, 56, 40, 76, 16, 20, 36, 83}

#define TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0_DEC_BITS {6}

#define LSTM_3_BIAS_LSHIFT {5}

#define LSTM_3_OUTPUT_RSHIFT {4}

#define TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0 {-20, 69, 5, -5, 0, -15, 16, -19, -3, 19, 9, 9, 20, 32, -47, -10, 5, 18, -7, -13, 24, 0, 7, 38, -14, 6, 20, 24, 38, -27, -12, -6, 23, -3, 2, -1, -33, 22, -6, -12, -64, -20, -51, -17, -2, 30, 16, 3, -2, 26, 16, -4, 17, -23, 28, -21, 22, -7, -11, -16, -19, -66, 18, 25, 53, -54, -39, 10, 23, 36, -57, 1, 36, -6, -2, -52, 16, -28, -29, 31, 35, -55, 3, 15, -34, -1, 43, 20, 32, 9, 26, -59, 32, 5, 2, 16, 22, -20, -31, 50, 9, 7, 20, 5, -29, 6, -9, -23, -1, -15, 3, 7, 52, -30, -24, 1, -32, -48, -39, 8, -34, 27, 9, 10, -69, 42, 4, -62, 0, 7, 46, -25, 14, 47, -9, 43, -2, 13, -1, -2, 4, -27, 7, -5, -58, -14, -28, 36, -5, 33, 15, 11, -8, 29, 8, -3, 16, 65, 2, 37, 6, 17, 1, -20, -7, -12, 32, 17, -45, -58, 26, -27, 10, 20, -30, 14, 37, 18, 42, -21, -16, -9, 8, -16, 54, 9, -7, 24, 62, -20, -5, -6, -4, 65, 14, 10, -14, -28, 12, -8, 6, -3, -32, 0, -27, -44, -24, -3, 55, -10, -27, 26, 44, -11, -38, 4, -7, -2, -8, 4, -24, -32, 6, -40, -10, 17, -17, 8, -22, -23, 5, 45, 21, -18, 51, 58, 11, 34, 8, 16, 13, -2, 14, 8, 25, -59, 48, 6, 1, 8, 15, 20, 13, -10, -8, -34, 18, -5, 12, 7, -9, -4, -13, -12, -2, -53, 28, -27, -41, -2, 0, -9, -10, -5, 19, 1, -15, -18, 25, 38, 13, 5, 30, -16, 29, 30, -22, 12, -24, -28, 30, -41, 33, 13, 18, -65, -32, 31, -9, 37, 4, -4, 46, 11, 59, -11, -69, 7, 19, -19, -49, -30, -14, -12, 48, -13, -24, -41, 30, 22, -15, -16, 61, 9, -29, -18, 5, 10, -63, -2, 2, -3, 22, -13, -4, -20, 8, -44, 10, 31, 27, 16, 14, -43, 15, 41, -7, 2, -26, -6, -28, -19, -7, 20, -27, 12, 3, -15, -3, 31, -17, -56, 42, -27, 42, 8, 22, 13, 5, -4, 14, 4, -29, -16, 10, -6, 12, 21, -46, 14, 8, -52, -7, -7, 35, -13, 17, 42, 18, -18, 32, 12, 9, -31, 27, 51, -28, 2, 13, -4, 11, -13, -4, 22, 12, 13, -30, -24, 19, 18, 51, -9, 30, -26, 52, -2, 24, -4, 16, 7, -15, 2, 8, -14, -24, -56, -18, 0, -38, 9, -1, 4, -12, -3, 13, -45, 43, -8, -12, 34, 49, -11, -23, -4, -3, 0, 2, 25, 11, -21, 17, 1, -3, -34, 5, -29, -24, -9, 6, -15, 17, 31, -28, 5, -6, 19, 30, 4, -9, 2, -7, -3, -3, -10, -36, -31, 20, -12, 30, -2, -31, -38, -14, 55, -34, 33, 40, -29, -25, 21, -41, -5, -21, 27, -1, 4, -12, 23, 22, 3, 28, -25, -11, 4, 42, 0, -53, 0, -7, 5, -34, -1, 20, -61, -33, -20, -40, 10, -4, -12, 15, 5, -8, -21, 16, -4, -25, 3, 26, 42, 14, -22, 23, -14, -2, 19, 26, 9, 6, -29, -11, 8, -9, -7, 1, 3, -31, -1, -18, -3, -3, -15, -12, 17, -63, -7, 33, -27, -14, -50, -30, -8, -5, 30, -1, 4, 15, 12, -14, -12, 22, 19, -9, 37, 18, -14, -18, 85, -3, -14, 12, -2, -5, -5, 3, -9, -2, 34, -37, -9, -4, 19, 10, -26, -42, 21, 22, -3, -20, 31, 9, 28, 11, 59, 14, -19, 17, 9, -22, -2, 11, 14, 0, -17, 15, 32, 30, -32, 11, -15, -21, 35, -46, -3, 26, 2, -10, -14, 23, -63, -34, 6, -11, 6, 17, 11, 5, -37, -12, -26, 15, 46, -4, -5, 23, 34, -9, -19, 16, -9, -9, 13, 4, 10, 8, -18, -22, -14, -6, 50, -55, -12, 40, 25, 40, 31, 26, 23, 46, 10, 15, 8, 56, -1, -27, 5, 38, 7, 53, -19, -59, -3, -21, 14, 15, 42, 49, 29, 70, 1, -13, -27, -14, -35, -44, -7, -48, -16, 39, 18, -38, -7, 64, 12, -53, 29, 36, -15, -22, 5, -40, 31, 8, 15, -6, 25, -18, 36, -31, 15, -65, -76, -51, 32, 50, 27, -21, -17, -42, 19, -8, 78, -28, 12, -27, 1, -10, 14, -1, -4, -17, 18, 34, 26, -16, -26, 28, -57, 77, 41, -8, 58, 18, -7, 23, -2, -39, -43, 15, -5, 13, -11, -33, 14, 3, -45, 21, -20}

#define TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0 {-24, 5, 19, -7, 30, -17, 39, 0, -27, 20, 8, 1, 0, -36, -23, -23, 39, -72, -37, -13, -54, -71, -19, -21, 5, -8, -81, -72, 61, 28, -36, -12, 75, -24, -45, -15, -25, -17, -33, 1, -12, 25, -9, 18, 13, 45, 12, -47, -43, -78, -75, -5, 27, 7, -40, -65, -34, 3, 11, 67, -50, -104, -33, -6, -31, -32, 1, 3, -4, 39, 20, -46, -33, 4, -11, 43, 14, -84, 13, -14, 51, -88, 71, 36, -45, 1, 52, 30, -36, 67, -15, 9, 21, -23, -58, 38, 42, 34, -35, 0, 44, -29, -20, -25, -9, -10, 25, -5, -43, -26, -20, -19, 31, 1, -7, -21, -15, 0, -25, -28, 42, 9, -51, -15, -8, 35, 24, 21, -27, 22, -12, -11, 26, 28, 13, 39, 52, -10, 78, 20, 35, -71, 68, -20, -32, 52, -16, -15, -3, -8, -13, -3, -10, 20, 70, 1, 30, -15, 31, 37, -6, 13, 23, 15, 10, -13, 57, 83, -34, 15, 1, -20, 9, 56, 35, -52, -47, 30, -10, -1, 14, 7, 47, 0, 20, 31, 30, 35, 25, -63, 50, 42, 17, -18, -19, -9, -24, 4, -32, 11, 0, 19, 16, 60, 10, 2, -11, -13, 24, 43, 46, 30, 30, 56, 76, 46, 38, -18, -16, 2, 63, -3, 26, -32, 34, 11, -10, 15, 21, -7, -2, 9, 9, -17, -8, 43, 19, -75, -1, 15, 57, 32, 24, 14, -47, -16, 47, -29, -21, 10, 13, -14, 17, 18, -35, 43, 16, 88, -6, 36, 21, -27, 9, 91, -9, 3, -8, 4, 11, 13, -10, 42, 33, 52, -70, -9, -48, 7, -42, 58, -26, -8, 46, -2, -1, -60, -70, 36, -4, 17, -35, -14, -2, 8, 24, 11, -13, 50, 22, -15, -16, 8, 1, 20, 24, -1, 3, 11, 8, -5, -2, 34, 13, 14, -15, 15, 35, 22, 12, 20, 1, 43, 6, -13, 6, 22, -24, 9, -33, -54, 13, -4, 15, -9, 16, -6, -40, -28, 9, 0, 32, 26, -26, 5, -11, -4, 8, -3, -26, 34, -4, -23, 31, -23, 36, 57, -13, 23, 0, 13, -10, 5, -18, -4, 32, -2, -15, -11, 24, 20, 31, -2, -20, 5, 14, 29, 1, -7, 28, 40, -69, -9, -20, 35, 12, -49, -29, 11, 13, 12, 43, -21, 1, 5, 15, 7, 25, 0, 8, 11, -4, -5, 28, 3, 46, -21, -16, 8, -3, -33, 10, -4, 33, 25, 0, 1, -3, -20, 8, -1, 8, 11, -47, -12, 4, 44, 25, -12, -10, -31, 22, 22, 6, -43, 50, -22, 36, 29, -19, -67, -35, 56, 72, -37, 24, -13, 12, -5, -41, 15, -20, 21, 26, 4, 21, 38, 8, -2, -47, -68, -29, 68, 72, 22, -19, 9, -67, 28, 84, 35, 79, 37, 68, -19, 31, -11, 61, -66, 57, 11, -32, 1, -18, 21, 22, 3, -54, -25, 4, 46, -16, -37, -21, -44, -72, 12, 31, -39, 56, 2, 14, 40, 41, 60, -19, -18, -50, -12, 52, -35, 44, -10, 38, -33, -27, -42, 1, -5, -19, 41, 6, -36, -33, -49, -11, -38, -26, -50, 9, 6, -8, 15, 30, -17, -74, -14, -44, 8, 38, -4, -72, -5, 5, -17, 37, 25, -14, -17, -86, -39, 27, 39, -22, -2, -31, -65, -43, 22, 27, 68, -18, 76, -27, -28, -43, -26, 81, 20, 45, -37, 55, 26, 46, -34, -25, -38}

#define TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0 {-25, 1, -70, -65, -6, -18, -35, 3, 5, -17, -22, -70, 87, 62, 100, 118, 72, 115, 95, 78, 60, 57, 51, 107, 1, -17, 1, -10, 2, 16, 2, -9, 6, 6, -27, 15, -4, 18, -5, 7, 42, -5, 11, 18, -9, 1, -33, 1}

#define TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0_DEC_BITS {6}

#define LSTM_4_BIAS_LSHIFT {6}

#define LSTM_4_OUTPUT_RSHIFT {5}

#define TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0 {11, 0, 15, -7, 10, 9, -9, 0, 1, 2, 7, 22, 13, 7, -5, 5, -4, 27, -12, 3, 15, 12, -12, -23, -9, -9, 1, -2, -6, -13, -11, -2, -8, 13, 18, 5, -3, 22, -5, -20, 44, 10, -4, -5, -1, 11, 2, 16, 8, 8, 3, 6, -7, -1, -20, -8, -8, -1, 15, 5, -5, -12, -9, 10, 5, 1, -7, -17, -19, -5, -10, -7, -21, 5, 2, -14, -7, -7, -9, -10, 0, 11, 2, 10, -8, 2, 19, 13, 14, -4, 12, -5, 35, 3, -3, 1, 4, -2, 3, 15, -6, 0, 0, 7, 2, 20, 32, 13, -5, 3, 18, 11, 11, 27, 9, 13, 9, 23, 0, 0, 3, -14, -1, -22, -15, -5, 1, 7, 13, 3, 4, -10, 8, 15, -2, -12, 8, 10, 3, 11, 4, 24, 14, 9, -4, -3, 0, -5, -2, 2, 7, 4, -11, -7, 29, 17, 11, -16, 5, 30, 13, 14, -1, 14, 20, 18, 16, 12, -13, -13, -16, -18, 14, -4, -16, 1, 6, 0, -3, 3, 11, -3, 6, -7, -7, -8, 8, -2, 17, 8, 9, -6, -1, -11, 1, 6, 7, 9, -6, 2, -24, -17, 5, -11, 14, 1, 2, -23, -4, -9, 3, -5, 11, -2, 9, -11, -30, -12, -4, 0, 0, 11, -24, 3, 9, -15, -17, -8, 4, 0, -9, -10, 25, 1, -1, -19, -16, -10, 5, -4, 1, 5, 12, -19, -30, -1, -4, 4, 9, -4, -15, 3, -9, -5, 9, 3, -3, 1, -8, -2, -16, -21, 1, 4, -4, -5, -14, 1, 5, 4, -3, 9, -15, 5, -4, 33, 0, -34, 10, -7, -5, -4, 0, 13, -5, 10, -10, -17, 2, 1, 15, 20, -23, -4, 4, 20, 16, 17, 12, 19, 7, 25, 15, 5, 22, 10, -19, -9, -10, -3, 12, 2, -15, -17, 13, -20, -14, -7, 5, -10, 17, 21, -9, -19, 0, -12, -6, -12, 28, 8, 19, 35, -3, 24, -9, 2, -10, 0, 13, 3, -26, -19, -20, -3, -28, 5, 24, 38, -18, -31, 68, 51, -1, 7, -9, -3, 1, -2, 17, 2, -26, 3, 1, -12, -6, -15, 4, 28, 1, 6, -11, -10, -2, 5, 27, -18, 17, 10, 6, -3, 16, 20, -1, 0}

#define TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0 {1, 8, 31, 41, -19, -1, 29, 6, -26, -19, -8, -41, 7, 3, 12, -7, 33, -27, -5, 23, 11, 28, 4, 11, 1, -2, 4, -12, -9, -34, -16, -9, 8, -19, 31, 31, -12, -25, 18, 31, 4, 4, -7, 28, -14, -10, 6, 14, -10, 12, -5, 8, 14, 16, -15, -13, 5, -5, 1, -3, -22, -12, -6, -27, 5, 13, -19, -15, 50, 8, -50, -24, 7, 20, -61, 9, 18, 11, -39, -38, -29, 6, 19, -1, -48, -3, -8, -6, -25, -4, 2, -16, 12, -12, 20, 1, 8, 4, -20, -25, 16, 34, -27, -19, 40, 18, -6, -15, 10, 20, -30, -40, -27, -30, 4, 4, -25, -70, 19, -9, 6, 3, -4, 10, -2, 11, 3, 13, -17, 8, -4, 15, -7, 1, 1, 6, -3, 1, 1, -2, -7, -2, 11, 11, -18, 11, -7, 3, -9, 16, -2, -4, 8, 6, 1, 6, 2, -11, 5, -15, -21, -15, 0, -8, -9, -4, -2, 8, -9, -14, 11, -10, -6, -3, -1, 3, 5, -5, 8, -11, 1, -5, 0, 12, -12, -4, 12, -13, -16, 5, -6, -9, 4, -15, -21, -26, 15, -11, -9, -5, -12, 33, -42, -3, 12, 41, -43, -10, 5, -2, 22, -3, -15, 12, -8, -13, -28, -5, -2, -18, 45, 20, 20, 23, 5, -6, -1, -35, 47, 39, -38, -17, 7, 19, -25, -19, 10, 14, -50, -42, -18, -45, -14, -6, -83, -71, 18, -18, 6, 29, 14, 16, 9, 13, 5, 10}

#define TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0 {-89, -38, -53, -78, -49, -56, -68, -80, 88, 106, 92, 59, 87, 118, 109, 108, 6, -39, 13, -13, -15, -9, -7, -10, 2, 39, 7, 2, 4, 50, 24, 11}

#define TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0_DEC_BITS {6}

#define LSTM_5_BIAS_LSHIFT {5}

#define LSTM_5_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_3_KERNEL_0 {51, -28, -85, 45, 18, -51, 30, 8, -5, 12, -48, 13, -6, -25, -2, -20, 11, -17, 40, 21, 3, 17, 54, -24, -56, -52, 53, 60, 29, 32, -35, -7, 42, 75, -6, 35, 49, -24, -23, -25, 28, -6, -37, 17, -23, 17, -61, -31}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_3_BIAS_0 {-46, -32, -118, -13, 122, 47}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {8}

#define DENSE_3_BIAS_LSHIFT {4}

#define DENSE_3_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_3_INPUT_OUTPUT_DEC 7
#define LSTM_3_INPUT_OUTPUT_OFFSET 0
#define LSTM_3_OUTPUT_DEC 7
#define LSTM_3_OUTPUT_OFFSET 0
#define LSTM_4_OUTPUT_DEC 7
#define LSTM_4_OUTPUT_OFFSET 0
#define LSTM_5_OUTPUT_DEC 7
#define LSTM_5_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 4
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

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_kernel_0_dim[] = {16, 48};
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

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dim[] = {12, 48};
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

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_bias_0_dim[] = {48};
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
    .units = 12
};

const nnom_rnn_config_t lstm_4_config = {
    .super = {.name = "lstm_4"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_5_lstm_cell_5_kernel_0_data[] = TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0;

const nnom_shape_data_t tensor_lstm_5_lstm_cell_5_kernel_0_dim[] = {12, 32};
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
    .q_dec_c = 1,
    .units = 8
};

const nnom_rnn_config_t lstm_5_config = {
    .super = {.name = "lstm_5"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_3_kernel_0_data[] = TENSOR_DENSE_3_KERNEL_0;

const nnom_shape_data_t tensor_dense_3_kernel_0_dim[] = {8, 6};
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

	layer[0] = input_s(&lstm_3_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_3_lstm_cell_config), &lstm_3_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_4_lstm_cell_config), &lstm_4_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_5_lstm_cell_config), &lstm_5_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_3_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_3_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_24_NNOM_H