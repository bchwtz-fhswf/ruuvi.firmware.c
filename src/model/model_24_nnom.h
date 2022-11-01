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
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_LSTM_27_LSTM_CELL_27_KERNEL_0 {-26, -2, 57, -2, 4, 8, -5, -14, -7, -36, -9, 7, 69, 51, 65, -56, -12, 71, -64, -52, 27, -1, -48, -45, 23, -69, -51, 60, 26, -2, 9, 15, -22, -39, 119, -12, -33, -90, -5, -63, 39, 32, 67, -2, 24, -4, -42, -28, -6, 7, -16, -31, 9, -32, -25, 7, -6, 52, -26, 35, -49, -2, -63, -5, -30, -32, 12, 39, 34, -1, 24, 13, -25, 5, 49, -105, -11, -14, 33, 15, -11, 11, -52, -22, 17, 38, -62, 82, -12, 23, -17, -24, -25, 6, 53, 45, 42, 0, -53, 43, -3, 74, -53, -59, 18, -20, -29, 16, 85, -75, 77, 55, 1, 69, -81, -90, 19, 0, -20, -23, 36, 75, -52, -76, -65, -43, -41, -34, 9, 32, -69, 2, 14, -93, 80, -84, -42, -54, -62, -70, 2, -2, 1, -7, -32, -6, 53, 17, 12, 23, 39, -17, -3, 34, 32, 46, 61, 43, 43, -71, -44, 64, -31, -62, 43, 9, -41, -53, -1, -75, -42, 51, 13, -1, 9, 45, 3, -13, 60, -21, -33, -105, -2, -33, 37, 77, 82, 15, -6, 32, 47, -14}

#define TENSOR_LSTM_27_LSTM_CELL_27_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_27_LSTM_CELL_27_RECURRENT_KERNEL_0 {-2, -36, 4, -13, 9, 22, -22, 15, 1, -50, -30, 54, 17, 6, 10, -10, -19, 9, 22, 1, -15, -23, -17, 17, 29, 60, 0, 47, 15, -31, 28, -8, -9, 63, -28, -17, 23, -33, -1, -27, 34, 76, -8, 5, 3, 23, 30, 24, -11, -1, 8, 74, -53, 15, -9, -23, 0, -5, 29, -7, 21, 2, 0, 21, 14, -17, -64, -6, -9, -7, 59, 29, 25, -2, -12, -9, -35, -31, -30, -57, -86, 2, 53, -17, 58, 30, 37, 50, 40, -28, 3, 1, -39, -72, -48, -60, 0, -14, 28, -3, -21, -36, -17, -53, 54, -7, 33, -14, -27, -6, -22, 39, -54, -13, 56, -30, 70, 47, -48, -25, 78, 28, 61, -4, -56, -29, -47, -22, -1, 26, 66, -35, -28, 0, 58, -18, -14, 12, -24, 33, -17, -16, -13, 21, 45, -16, 0, -31, -10, 17, -11, 17, -3, 29, 13, 48, 6, 49, -16, 27, 10, 8, -52, 57, -10, 25, -13, -20, 5, -27, -16, -24, 0, 45, -26, 18, 13, -43, 12, 7, 11, -29, 20, 43, -50, 12, 0, 14, -21, -9, 2, 6, -23, 20, -52, 37, 7, 14, -21, -47, -3, 0, 14, 6, -24, 22, 42, -21, -11, 48, -23, -21, -38, -24, -16, 3, 28, -66, 14, -40, 79, -6, 69, 0, 51, -22, -8, 24, 41, -9, 7, 9, 31, -52, 76, -30, 56, 20, 24, 89, -49, 30, 26, -60, -24, -78, 55, 11, 39, -48, -11, -30, 44, 52, 1, 7, -13, 21, -6, 6, -12, 2, 14, -5, -1, -1, -30, -25, 1, 51, 50, -39, -14, -18, 9, 7, -4, -58, -39, 46, -12, -11, -19, -17, 16, -29, 27, -26, -6, -6, 2, 31, 24, -44, -13, 2, 2, 16, -32, 25, 18, 7, 7, -1, -3, 13, -15, -13, -21, -18, 20, -15, 22, 4, 4, 7, 5, 81, -4, 28, -8, 56, 4, -12, 8, -6, -23, -25, -21, 27, -14, 39, 10, -9, 6, 14, 6, 14, 28, -29, -12, 1, -9, -19, -30, -7, 2, 40, 36, 36, 18, 34, -11, 6, 2, 42, 19, 25, 22, -10, -23, -29, -16, -1, 29, 24, 32, -5, 19, 4, -6, -14, -23, -4, 18, 24, 1, 14, -24, -19, 18, 15, 19, -11, -13, -38, -1, 3, -12, 7, 15, -9, 11, 1, -7, -7, -5, -2, 45, -11, -28, 9, 16, 3, -8, 6, -30, -10, 21, -5, 6, 1, 13, -9, 2, -3, -6, 16, 12, -28, 18, -1, -4, 21, 13, 5, -34, -30, 3, 1, -34, -23, 10, 49, 5, 0, 3, 32, -3, -24, 35, -16, 14, 2, -20, 5, 5, -10, 6, 8, 7, 8, 12, -17, 4, 22, 28, 8, -24, 11, -8, -16, 1, 8, -30, 7, -11, 19, -7, -7, 9, 20, -24, 17, -9, 4, -16, 7, -33, 17, -2, 8, 33, -3, 2, 2, 22, -11, -25, 4, 36, 29, -4, 4, -5, -10, -30, -15, -17, 19, 37, 9, -38, 12, 28, -12, 36, 21, -5, 0, -10, -11, 0, 14, -11, -16, -10, -9, 1, -6, -3, 9, 26, -8, 2, 0, -4, 1, 6, -5, -22, 0, -28, -7, -11, -12, -1, 28, 0, 36, -2, 19, -11, 26, 5, 18, 9, 5, -3, 7, -6, 12, -4, -1, 12, 15, -5, -10, 3, -19, -3, -27, 12, 8, -12, -3, -4, -4, -2, 10, 2, 9, 3, 1, 11, -6, -1, 15, -11, 4, 3, 7, 13, -3, 13, 1, 6, 13, 3, -3, -7, -11, -5, -18, -8, -2, 16, 9, 2, 13, 1, 19, 6, -7, 1, -5, 10, -2, -9, -1, 2, -7, -9, 0, -6, -3, 3, 8, -1, 25, -3, 2, 14, 3, -9, -8, 5, 20, 14, 5, -5, 8, 6, -15, 5, 16, -6, 5, 0, -1, -3, -6, 6, 5, 9, -4, 1, -18, -4, 2, -19, -4, -2, -1, 3, 26, 22, -2, 13, 3, -1, -4, -6, -30, 10, -4, 7, -13, 10, -19, 8, -2, -14, 8, -15, 3, 2, 19, 3, 8, -1, 11, -32, -2, 2, 6, -13, -13, 1, -2, -5, -9, 16, 9, -10, 20, -8, 0, 8, 3, -7, 7, -21, 5, 8, 2, 28, 6, -2, -21, 1, 9, 0, -7, 11, -2, -15, -4, -20, 0, 5, 15, 8, -10, -18, -1, 7, -16, -7, 3, 9, 4, -17, -1, -29, -3, 4, -1, 2, -10, -14, 1, -19, -2, -3, -7, -9, -11, 18, 6, -8, 6, -6, 3, -9, -3, 32, -15, 3, -3, -8, 1, -11, -6, -11, -10, -4, 4, -9, -24, 32, -7, 7, 2, 43, 10, 3, -54, -35, 60, 7, 17, 21, -1, -28, 20, 52, -21, 2, -32, -1, 18, 17, 41, -9, 43, -4, -26, 15, 8, -17, 62, -21, -19, -3, -24, -3, -5, 23, 79, -47, 23, -5, 11, -10, 3, 18, -18, 6, 43, -4, 16, -9, -22, -2, -5, 17, -23, -16, 22, -8, 17, 4, 5, 3, -22, 22, 8, -16, -49, -16, 7, -18, 12, 8, 6, -23, -17, 5, 27, 38, -32, -11, -17, 39, 1, -11, -13, -14, 25, 36, 20, 9, 33, -6, 9, 28, 8, 2, 12, 33, -14, 0, -17, 2, -23, 17, 16, 28, 40, -8, -4, 11, -38, -17, -38, 1, 7, 9, 7, -4, -10, 9, 58, 12, -4, -27, -2, -25, 0, -21, -10, 5, -3, 7, -7, 9, -1, -7, -19, 44, 41, 17, -22, 8, 1, 32, 22, -23, -1, 18, 7, 38, 11, -5, 52, -13, 37, 35, -5, -23, -30, 7, 28, -15, -22, 2, 18, -16, 3, 10, 43, -39, 10, -20, 36, 28, 8, 21, -27, 15, 46, 7, -9, 11, 3, -37, 0, -20, 2, -20, 7, -9, -11, -10, -1, 28, 25, -8, 11, 13, 4, -30, -16, 25, 9, 14, 45, -31, 1, 9, -1, -29, 3, 24, -8, 13, -17, 40, -2, 52, 9, 40, -3, 4, 8, 23, 0, -25, 11, 35, -8, 52, -25, 27, 16, 11, 21, -20, 15, 27, 14, 0, -2, 19, 2, 5, -27, -13, 2, -8, 5, -31, -14}

#define TENSOR_LSTM_27_LSTM_CELL_27_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_27_LSTM_CELL_27_BIAS_0 {-8, 49, -4, 66, -15, 49, -5, -28, 27, -15, -2, 57, 44, -13, 45, -29, 51, 43, 47, 58, 56, 37, 65, 74, 48, 69, 39, 56, 35, 54, 51, 58, 5, 0, -1, 6, -4, 5, -5, -5, -1, 4, -2, 0, 6, -4, 1, -3, -11, 53, -15, 66, 42, 53, 29, 16, 33, 18, 19, 55, 72, 26, 63, -1}

#define TENSOR_LSTM_27_LSTM_CELL_27_BIAS_0_DEC_BITS {6}

#define LSTM_27_BIAS_LSHIFT {8}

#define LSTM_27_OUTPUT_RSHIFT {7}

#define TENSOR_LSTM_28_LSTM_CELL_28_KERNEL_0 {64, 45, -58, -64, -8, 1, 4, 16, -6, 29, 29, 29, 29, 10, 7, 4, -44, -72, -12, -46, 42, -3, 1, -16, 30, -23, 20, 0, -4, -10, -17, 15, 13, -17, 16, 35, 0, 6, 7, 10, 19, -39, 2, 42, -30, -27, -13, -26, 25, -21, 15, -6, -25, 14, -14, -35, 42, 49, -1, 5, -27, -12, 38, 12, -29, 10, 11, 13, -30, 30, 0, -8, 25, -2, -19, -6, 11, 22, 12, 9, -60, 2, 31, -32, -3, 23, 16, 13, -1, 12, -4, 32, -7, -13, 2, -20, 9, 11, 14, 21, 9, -5, 8, 23, -18, 4, -34, -29, -5, -23, -24, -15, -27, -12, 25, 1, -18, 4, -3, -19, 7, 27, 69, -13, -9, 5, 26, 16, -10, -14, 29, -8, -3, -10, -27, 20, -2, 3, -9, -8, 3, -8, 9, -8, -5, -2, -31, 0, 15, 26, -1, 14, 0, 0, 17, -5, -20, 20, -20, 12, 7, -4, 1, -23, -2, 10, 13, -25, 24, -5, -10, 6, -18, 3, -19, -9, 18, -11, -12, 4, 13, -14, -14, 31, -9, 19, -2, -23, 14, -25, -19, 16, 12, 8, -8, 17, -31, -21, 16, 22, -12, -4, -20, -17, -5, 6, 14, -3, -50, -2, 61, 11, 1, 4, 9, -23, -1, 10, -5, -7, 34, 0, 9, 8, -1, -5, 6, 18, 16, 14, -3, -12, 16, 14, 4, 48, 3, -13, -19, -13, 39, 11, 4, -9, 13, 5, -3, 25, 11, -15, -5, -5, -36, -21, 16, 14, -14, 5, 14, 8, -34, 5, 7, -35, 25, -4, 0, 0, -24, 18, 20, -54, -31, -22, 12, 0, 6, 12, 7, 35, -20, 16, -9, 6, 5, -23, 14, -61, 0, -2, 20, 3, 18, -32, -5, 11, -11, 2, -36, -4, 24, -13, -7, 3, 11, 10, -25, 13, 16, 30, 33, -41, 7, 11, 22, -5, -9, 23, -5, 1, -20, -13, 6, 11, 3, -25, -29, -6, -10, -14, 11, 9, 14, 4, -42, -4, 1, 6, -34, -2, -15, 28, 34, 22, 12, 20, 29, 29, -3, -12, -25, -8, 19, 8, -20, -18, -15, -2, -7, -14, 24, 11, 22, -5, 2, -15, -9, -32, -14, 12, 28, 21, 22, 19, -20, -4, -9, -3, 6, -15, 26, -12, -5, -10, 25, -26, 27, -29, -6, 14, -5, -15, 3, -12, -21, 32, -16, -9, -36, -4, -8, 21, 50, -24, -21, -18, 5, 12, 2, 7, -26, 22, -1, 1, -18, -12, -13, 19, -11, -1, 5, -13, 25, 18, -19, 20, -18, 29, 22, 10, 14, 23, 34, -33, -26, 17, 5, 7, -20, -3, -4, 2, 4, 2, 3, 17, -10, -8, 12, -18, 6, 3, 2, 13, 22, -22, 35, -7, -14, 11, 10, 9, -14, -22, -45, 9, 16, -33, 0, -10, -14, -3, -16, 18, -23, 26, -12, -11, 6, -22, -25, 22, 4, -6, -11, -22, 14, 20, -17, 7, -18, -27, -21, -7, -40, 6, -16, 19, -29, 8, -8, -13, -16, -22, 4, 6, 19, -3, -7, 34, -2, 4, -14, -10, 14, 0, -7, 12, 15, 8, -25, -6, -3, -1, -19, -1, 6, -30, 12, -2, 14, 6, 29, 1, -4, -11, 26, 3, 24, 14, 14, -24, 19, -13, 19, 14, -21, -14, 31, -19, -8, 23, 15, 9, -12, -21, -10, -10, -28, -4, 29, 2, 10, 17, 11, -23, 22, -16, -16, 7, -7, 1, -34, 0, 0, 8, 29, 24, -28, -12, -29, -23, 33, 40, 1, 22, 1, -16, 4, 9, 21, -8, -60, -28, 25, -7, 20, -2, 11, -31, -9, -6, -8, -32, 36, -2, -15, 8, -14, -15, 15, 40, 9, 8, 18, -11, 14, -14, -11, 32, 0, -11, -7, -14, 35, 0, 2, -21, -11, -12, -13, 17, 18, 11, -10, 21, -37, -36, 24, 6, 4, 13, 16, 16, -27, 15, -4, -27, 10, -4, -5, -22, -40, 26, -2, -18, -49, 8, 47, -11, 29, 0, 4, 64, -10, 7, -3, 10, 16, -13, 18, -32, -4, 1, 23, -3, 21, -31, -15, 2, -3, 17, -44, -3, 12, -23, -30, 19, 11, 6, 6, 11, 23, 17, 32, -19, 4, 9, 20, -25, -10, 11, -34, 0, -22, -21, 30, 3, 12, -46, -17, -5, -7, -5, 15, 10, 12, -29, -14, -10, 14, 12, -32, -33, -21, 43, 37, 2, 12, 6, 22, 22, -20, 21, -20, 4, 15, 14, -19, -12, -5, 28, 26, -50, 9, -2, -9, -24, -6, 21, -8, -9, 5, -4, 12, 8, 24, -3, -18, 25, -20, -5, 1, -24, 18, -9, -8, -5}

#define TENSOR_LSTM_28_LSTM_CELL_28_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_28_LSTM_CELL_28_RECURRENT_KERNEL_0 {35, -24, -9, 19, 2, 18, -25, -32, -17, -31, 10, 8, 9, 14, 6, 15, -15, -14, -30, 46, 5, -47, -24, -26, 10, -4, 30, -18, 8, -19, -1, 0, 6, -40, -15, 53, -28, 8, 17, -1, -17, 5, 12, 31, -25, 16, -5, 18, 55, -2, 7, -26, -2, -67, -11, -33, 17, 32, -40, 17, 21, -35, -22, -4, 12, 5, -46, -39, -22, 4, -13, -9, 3, -8, -14, 50, -11, -1, 14, 28, 44, -3, -44, 18, 0, -44, -3, 1, 4, -65, 2, 19, -6, -17, 29, -8, -16, 11, 4, -38, 6, -60, 1, 19, 43, -12, 20, -9, -9, -44, 5, -60, -19, -1, 13, -21, 33, 7, 0, 7, -17, 14, 0, 49, -23, 8, 9, -32, 11, -15, -33, 37, 15, 10, 31, 14, 5, -24, 10, 19, 4, -9, -31, 3, 22, -45, -13, 35, 5, 18, 15, 20, -21, 49, -22, 51, -29, -22, -11, -17, 12, -42, 12, 9, -27, -40, -9, 17, 13, -14, -10, -58, 49, 30, -44, -52, 21, 1, 12, -55, 13, 9, 37, 6, 25, 28, 10, -4, 34, 46, 13, 20, 63, -57, 16, -26, -8, -37, 27, -10, -7, -7, 6, 17, -34, 0, -30, 17, 0, -24, -10, 2, -8, 4, 41, -14, -3, -29, -22, 19, -5, 4, -9, 17, 54, 11, -23, 14, 60, -10, 25, 24, 35, 5, -31, 1, 19, -51, 43, -2, -27, -34, -5, -3, 25, 14, 0, 28, -16, -36, -38, -28, 2, -25, 13, -33, -26, -7, 33, 14, 16, 2, -2, 2, 13, 21, 4, 1, -18, 41, 3, -45, 6, 2, 3, 56, 16, 20, -4, 17, 3, -19, 13, 37, -12, 39, -45, 44, -5, -26, 28, 27, 2, -20, 35, 8, -12, -21, -11, -42, -13, -7, 15, 0, 10, 29, -28, 44, -4, -8, 1, -5, -7, 16, 1, -3, -5, -8, 7, -14, -3, 9, -40, 41, -4, -8, -9, 4, -13, 2, -38, -10, -14, 32, 16, 8, 17, 21, -12, -17, -6, 3, 14, -7, -1, 18, -4, -24, 2, -3, 0, 4, 14, 27, -46, -4, -12, -19, 5, -18, 17, -11, -5, -7, 7, -1, 18, 7, -32, 5, -7, 30, 7, -12, -4, 12, -12, -18, 33, -2, -12, 8, 20, 10, 4, 18, 0, -33, -3, -4, -4, 19, 14, -15, -6, -11, -24, -11, -25, -25, 20, 29, -8, -6, -10, -23, 7, 1, 14, -3, -13, 20, 10, -12, -8, 0, 6, -1, -10, 7, 42, 11, -12, -8, -28, -14, -6, 21, -3, 0, -13, -13, 33, -9, -19, -1, -27, -14, 19, 3, -11, -13, -8, 20, -28, -11, -13, -22, 12, -8, -7, -1, -39, -32, -29, 0, 31, -11, 39, 7, 18, 35, 23, -10, -10, -4, 24, 7, 17, 24, 53, 28, -6, -5, 12, -3, 11, 14, 14, 35, 29, -16, -33, 4, -20, 6, -4, -46, 25, 13, 66, -5, -20, 31, -15, 22, 3, 12, -29, -3, -28, 18, 41, -58, -41, -8, -10, 80, -5, -14, -36, 32, 35, -12, -34, 19, 21, -43, 17, 0, 12, -46, -22, -8, 16, -19, 5, -8, -13, 5, -20, -29, 44, -43, -44, 35, -6, -36, -6, -27, 8, -62, 21, -52, -10, 25, 25, -3, 23, -4, -31, 39, -15, 7, -14, 50, 9, 38, 23, -11, 8, 12, 12, 46, 7, 57, 3, 43, 33, -37, -11, 43, 0, 16, -10, 22}

#define TENSOR_LSTM_28_LSTM_CELL_28_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_28_LSTM_CELL_28_BIAS_0 {1, -1, -43, -35, -8, -10, -37, -14, 6, -25, 16, -23, 58, 77, 64, 76, 74, 62, 62, 68, 68, 57, 93, 61, 1, -10, -1, 15, 1, -5, -2, -9, -6, -12, 14, -4, 13, 35, -11, -5, 22, -4, -8, -13, 15, -9, 22, -8}

#define TENSOR_LSTM_28_LSTM_CELL_28_BIAS_0_DEC_BITS {6}

#define LSTM_28_BIAS_LSHIFT {6}

#define LSTM_28_OUTPUT_RSHIFT {5}

#define TENSOR_LSTM_29_LSTM_CELL_29_KERNEL_0 {29, -21, 106, -14, 6, 3, 44, 5, 29, -51, 9, 12, 32, 65, -24, 32, -11, -17, 4, -7, -40, -9, -8, 18, 69, 0, -36, -23, 38, -56, -55, -43, 19, -14, -40, -14, 69, 72, -38, -25, 39, 19, 109, 6, 29, 8, 61, -48, -50, 11, 5, -70, -22, 13, -41, -19, 18, -8, 16, 25, -38, -7, -17, 11, -46, 26, -15, -20, 7, 34, -30, -32, -31, 7, -5, 27, 13, -45, 18, -23, 33, -43, -9, 81, -48, -31, 40, 9, 10, -37, -45, 10, -17, -12, 23, 8, 24, 15, -67, 18, -28, -17, -37, 9, 37, -48, 7, 30, -36, 30, -16, 29, 11, 28, -56, 7, -17, 47, 4, 17, 21, 12, 48, 2, 13, -59, 40, 50, 39, -17, 18, 49, 58, 7, 89, -3, -31, -9, 29, -11, -22, -39, -23, -51, -46, -44, 18, 28, 7, 1, -9, 34, -22, -20, -2, -17, -67, 39, 15, 8, 31, 26, -17, 64, 19, 44, 14, -7, 54, -7, 27, -5, -19, -33, 70, -49, 43, 41, 14, 61, -43, -1, 41, -8, -19, 22, 5, -13, -25, 40, 27, -33, 2, -25, 95, 2, -49, -53, 43, -8, 40, -18, -26, -51, 18, 26, 4, 10, 27, 18, -16, 20, -58, -69, -15, -5, 10, 4, 2, 41, 33, -21, 9, 21, 16, 21, -34, 8, 23, 29, -19, -3, 35, -48, 26, -2, 23, 15, 47, -31, 41, -13, -9, -14, 14, 14, 14, 15, 16, 41, 3, 38, -22, -1, -81, -39, -2, 45, -9, -32, 25, -8, -4, 44, -2, 9, 16, 38, 3, -44, 17, -9, -49, -16, 16, -2, 4, 43, 28, 1, -41, -26, 26, 13, -9, -20, 33, 3, -16, -3, -11, -81, -62, -10, 16, 16, -3, -94, 14, -6, -20, 62, 1, -16, 19, 58, -5, -27, -8, 44, 26, 27, 77, -36, 31, 61, -8, -87, 10, 52, -22, -6, 16, 31, 76, 36, -22, 10, -25, -17, 59, 4, 11, -14, -5, -71, -7, -73, 59, -8, -75, -35, -19, 36, 74, -93, -44, 14, -51, -19, -4, -29, 34, -47, -31, 14, -45, 76, 20, 45, 105, -45, 46, -51, -51, -49, -11, -36, 19, 111, 1, 66, 80, 3, 30, 18, -31, 38, 93, -22, -4, 27, -9, -11}

#define TENSOR_LSTM_29_LSTM_CELL_29_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_29_LSTM_CELL_29_RECURRENT_KERNEL_0 {-50, -34, 14, 14, -27, -55, 13, -12, -7, 9, -1, 27, -51, -9, -47, -46, -15, -23, -47, -12, 3, 57, -7, -25, 8, -37, 38, 14, 18, 26, 31, 21, -37, -45, -5, 19, -9, -34, 2, 6, -16, -30, 42, -28, 0, -18, 17, -8, 21, 12, 11, -6, 12, 27, -19, -28, -45, -14, 12, -37, -4, 6, 11, 9, 10, -19, -22, 30, 50, 33, -38, 4, -3, -25, -35, -51, 20, 24, 12, 15, -10, -4, 46, -5, -38, -18, 31, 59, -21, 8, -42, -28, 8, -30, -16, -1, 17, 39, 6, -8, 14, 18, -10, -35, -1, 46, -28, 31, -1, 6, -10, -19, -10, -27, 25, 10, -58, -22, 26, 16, -14, -22, -29, -22, 16, -44, -13, -3, 9, -7, 3, -2, -8, 19, 14, -5, 25, 0, -11, 35, -12, 6, -1, 28, -4, 7, -4, 8, -5, 10, -3, -27, -15, -10, 22, 35, -2, 3, 8, -5, 1, -9, -3, -17, 14, 2, -27, 33, 10, 16, -6, 4, 6, 10, 12, 12, 19, -23, -21, 9, 12, 31, -14, -24, 4, -6, 15, -18, 8, -13, 8, -4, -22, -41, -17, 3, 0, -16, -33, 21, 14, 53, -4, -52, 31, 7, 56, 5, -22, -35, 87, 32, -82, 18, 19, 12, -30, -18, -51, -53, -34, -2, -3, 0, 15, 9, 24, -3, 44, 41, -43, -7, 15, 55, 14, 40, 24, -18, 12, 9, -27, -50, 22, 17, -97, -39, 49, -4, 10, -31, -6, 2, -23, 9, -73, -8}

#define TENSOR_LSTM_29_LSTM_CELL_29_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_29_LSTM_CELL_29_BIAS_0 {-31, -4, -48, -47, -35, -35, -35, -22, 110, 93, 116, 125, 120, 126, 91, 90, 16, -16, 1, -1, -9, 14, -12, 3, 80, 78, 32, 39, 26, 32, 67, 29}

#define TENSOR_LSTM_29_LSTM_CELL_29_BIAS_0_DEC_BITS {6}

#define LSTM_29_BIAS_LSHIFT {7}

#define LSTM_29_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_9_KERNEL_0 {5, 17, -24, 29, 22, 32, 31, -19, 15, 32, 71, -31, -2, -27, 13, -22, 21, -18, 21, 51, -21, -22, -16, -14, -32, -40, 55, 14, 40, 11, 4, -39, -66, 33, -7, -32, 62, 1, 7, 6, -32, -54, -22, -8, 18, 24, -39, -1}

#define TENSOR_DENSE_9_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_9_BIAS_0 {9, 30, 3, -103, -100, 100}

#define TENSOR_DENSE_9_BIAS_0_DEC_BITS {8}

#define DENSE_9_BIAS_LSHIFT {4}

#define DENSE_9_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_27_INPUT_OUTPUT_DEC 9
#define LSTM_27_INPUT_OUTPUT_OFFSET 0
#define LSTM_27_OUTPUT_DEC 7
#define LSTM_27_OUTPUT_OFFSET 0
#define LSTM_28_OUTPUT_DEC 7
#define LSTM_28_OUTPUT_OFFSET 0
#define LSTM_29_OUTPUT_DEC 7
#define LSTM_29_OUTPUT_OFFSET 0
#define DENSE_9_OUTPUT_DEC 4
#define DENSE_9_OUTPUT_OFFSET 0
#define SOFTMAX_9_OUTPUT_DEC 7
#define SOFTMAX_9_OUTPUT_OFFSET 0

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

const nnom_io_config_t lstm_27_input_config = {
    .super = {.name = "lstm_27_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_27_lstm_cell_27_kernel_0_data[] = TENSOR_LSTM_27_LSTM_CELL_27_KERNEL_0;

const nnom_shape_data_t tensor_lstm_27_lstm_cell_27_kernel_0_dim[] = {3, 64};
const nnom_qformat_param_t tensor_lstm_27_lstm_cell_27_kernel_0_dec[] = TENSOR_LSTM_27_LSTM_CELL_27_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_27_lstm_cell_27_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_27_lstm_cell_27_kernel_0 = {
    .p_data = (void*)tensor_lstm_27_lstm_cell_27_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_27_lstm_cell_27_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_27_lstm_cell_27_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_27_lstm_cell_27_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_data[] = TENSOR_LSTM_27_LSTM_CELL_27_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_dim[] = {16, 64};
const nnom_qformat_param_t tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_dec[] = TENSOR_LSTM_27_LSTM_CELL_27_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_27_lstm_cell_27_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_27_lstm_cell_27_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_27_lstm_cell_27_bias_0_data[] = TENSOR_LSTM_27_LSTM_CELL_27_BIAS_0;

const nnom_shape_data_t tensor_lstm_27_lstm_cell_27_bias_0_dim[] = {64};
const nnom_qformat_param_t tensor_lstm_27_lstm_cell_27_bias_0_dec[] = TENSOR_LSTM_27_LSTM_CELL_27_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_27_lstm_cell_27_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_27_lstm_cell_27_bias_0 = {
    .p_data = (void*)tensor_lstm_27_lstm_cell_27_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_27_lstm_cell_27_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_27_lstm_cell_27_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_27_lstm_cell_27_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_27_lstm_cell_config = {
    .super = {.name = "lstm_27"},
    .weights = (nnom_tensor_t*)&tensor_lstm_27_lstm_cell_27_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_27_lstm_cell_27_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_27_lstm_cell_27_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 4,
    .units = 16
};

const nnom_rnn_config_t lstm_27_config = {
    .super = {.name = "lstm_27"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_28_lstm_cell_28_kernel_0_data[] = TENSOR_LSTM_28_LSTM_CELL_28_KERNEL_0;

const nnom_shape_data_t tensor_lstm_28_lstm_cell_28_kernel_0_dim[] = {16, 48};
const nnom_qformat_param_t tensor_lstm_28_lstm_cell_28_kernel_0_dec[] = TENSOR_LSTM_28_LSTM_CELL_28_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_28_lstm_cell_28_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_28_lstm_cell_28_kernel_0 = {
    .p_data = (void*)tensor_lstm_28_lstm_cell_28_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_28_lstm_cell_28_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_28_lstm_cell_28_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_28_lstm_cell_28_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_data[] = TENSOR_LSTM_28_LSTM_CELL_28_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_dim[] = {12, 48};
const nnom_qformat_param_t tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_dec[] = TENSOR_LSTM_28_LSTM_CELL_28_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_28_lstm_cell_28_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_28_lstm_cell_28_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_28_lstm_cell_28_bias_0_data[] = TENSOR_LSTM_28_LSTM_CELL_28_BIAS_0;

const nnom_shape_data_t tensor_lstm_28_lstm_cell_28_bias_0_dim[] = {48};
const nnom_qformat_param_t tensor_lstm_28_lstm_cell_28_bias_0_dec[] = TENSOR_LSTM_28_LSTM_CELL_28_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_28_lstm_cell_28_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_28_lstm_cell_28_bias_0 = {
    .p_data = (void*)tensor_lstm_28_lstm_cell_28_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_28_lstm_cell_28_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_28_lstm_cell_28_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_28_lstm_cell_28_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_28_lstm_cell_config = {
    .super = {.name = "lstm_28"},
    .weights = (nnom_tensor_t*)&tensor_lstm_28_lstm_cell_28_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_28_lstm_cell_28_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_28_lstm_cell_28_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 12
};

const nnom_rnn_config_t lstm_28_config = {
    .super = {.name = "lstm_28"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_29_lstm_cell_29_kernel_0_data[] = TENSOR_LSTM_29_LSTM_CELL_29_KERNEL_0;

const nnom_shape_data_t tensor_lstm_29_lstm_cell_29_kernel_0_dim[] = {12, 32};
const nnom_qformat_param_t tensor_lstm_29_lstm_cell_29_kernel_0_dec[] = TENSOR_LSTM_29_LSTM_CELL_29_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_29_lstm_cell_29_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_29_lstm_cell_29_kernel_0 = {
    .p_data = (void*)tensor_lstm_29_lstm_cell_29_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_29_lstm_cell_29_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_29_lstm_cell_29_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_29_lstm_cell_29_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_data[] = TENSOR_LSTM_29_LSTM_CELL_29_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_dec[] = TENSOR_LSTM_29_LSTM_CELL_29_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_29_lstm_cell_29_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_29_lstm_cell_29_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_29_lstm_cell_29_bias_0_data[] = TENSOR_LSTM_29_LSTM_CELL_29_BIAS_0;

const nnom_shape_data_t tensor_lstm_29_lstm_cell_29_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_lstm_29_lstm_cell_29_bias_0_dec[] = TENSOR_LSTM_29_LSTM_CELL_29_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_29_lstm_cell_29_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_29_lstm_cell_29_bias_0 = {
    .p_data = (void*)tensor_lstm_29_lstm_cell_29_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_29_lstm_cell_29_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_29_lstm_cell_29_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_29_lstm_cell_29_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_29_lstm_cell_config = {
    .super = {.name = "lstm_29"},
    .weights = (nnom_tensor_t*)&tensor_lstm_29_lstm_cell_29_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_29_lstm_cell_29_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_29_lstm_cell_29_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 8
};

const nnom_rnn_config_t lstm_29_config = {
    .super = {.name = "lstm_29"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_9_kernel_0_data[] = TENSOR_DENSE_9_KERNEL_0;

const nnom_shape_data_t tensor_dense_9_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_9_kernel_0_dec[] = TENSOR_DENSE_9_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_9_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_9_kernel_0 = {
    .p_data = (void*)tensor_dense_9_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_9_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_9_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_9_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_9_bias_0_data[] = TENSOR_DENSE_9_BIAS_0;

const nnom_shape_data_t tensor_dense_9_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_9_bias_0_dec[] = TENSOR_DENSE_9_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_9_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_9_bias_0 = {
    .p_data = (void*)tensor_dense_9_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_9_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_9_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_9_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_9_output_shift[] = DENSE_9_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_9_bias_shift[] = DENSE_9_BIAS_LSHIFT;
const nnom_dense_config_t dense_9_config = {
    .super = {.name = "dense_9"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_9_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_9_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_9_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_9_bias_shift
};

const nnom_softmax_config_t softmax_9_config = {
    .super = {.name = "softmax_9"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_9_OUTPUT_DEC};
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

	layer[0] = input_s(&lstm_27_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_27_lstm_cell_config), &lstm_27_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_28_lstm_cell_config), &lstm_28_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_29_lstm_cell_config), &lstm_29_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_9_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_9_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_24_NNOM_H