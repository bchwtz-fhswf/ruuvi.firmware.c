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
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0 {-34, 32, -31, -54, 34, 22, 39, 12, -2, -44, 9, 47, 18, -50, 28, 37, 4, 23, -7, 37, 44, 6, -1, -54, 7, -24, -12, 9, 2, -14, 1, 13, -32, -12, 40, -8, -18, -49, -5, 26, -9, 8, -1, -8, -18, -10, -7, 37, 13, -49, 11, 1, -11, -7, -13, 0, -19, -14, 4, -18, 25, 0, -14, -39, 6, -5, -13, -17, -30, -13, -6, 43, -42, 15, 14, -10, 2, -21, 70, -7, 45, 32, -8, -26, -16, 24, -27, -18, 31, -11, -15, 4, -10, 35, -3, -35, 26, -35, 37, 38, 41, 10, 48, 42, 10, 22, 9, 17, 18, -46, 48, 44, -2, -27, 37, -29, 31, 8, -8, 41, -22, -26, 43, -56, 28, -10, 25, -25, -10, -8, -11, 15, -63, -44, 25, 22, -1, -9, 28, 28, -9, -31, 11, -3, -37, 21, -19, -38, 38, -19, 12, 38, -41, -25, 22, 8, 41, -31, 24, 17, 17, 30, 16, 23, 11, -13, -27, -3, -22, -11, -4, -2, 0, 26, 21, 12, 0, 16, 37, -10, -15, -35, 0, 24, 27, 20, 3, -5, -19, -30, -18, 48}

#define TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0 {40, 35, 55, 49, -49, 61, -6, 37, 31, 25, 3, 29, -73, 21, -50, -16, 26, 17, -10, 31, -70, -14, -40, -48, 22, 6, -23, 13, -63, -33, 51, 26, 55, 44, -31, -36, -24, 54, 21, -39, 29, 25, -9, -29, -78, 70, 62, 16, 35, 23, -11, 39, 48, -46, -1, -14, 5, 13, -10, 44, -12, -24, 0, -14, -44, 16, -17, -31, -25, -19, -23, -10, -54, -32, -29, -54, -27, -20, -26, -17, -46, -27, -13, -58, -14, -25, -15, -36, -30, -65, 35, 10, -12, -28, 40, 27, 2, -56, 42, -2, -10, -21, 10, 13, -61, 2, 82, 22, -27, -24, 78, 13, 15, -72, 1, -94, -6, 29, -44, -16, -24, -55, -62, -38, -46, 15, -49, 0, 47, 53, 23, -8, 16, 9, 59, -9, 25, 19, 23, 27, -9, -5, -12, 22, 47, 25, 2, -7, -44, 9, -13, -15, 52, -7, 12, -14, 1, 11, -24, -8, 13, -38, 10, 18, -19, -21, 9, 14, 9, 38, -39, -72, 49, 8, -49, -4, 7, -10, 47, -4, -35, -17, -5, 2, 28, 35, 29, 25, -1, 14, 12, 21, 20, 7, 75, 0, -42, -11, -48, 12, -42, -18, -20, -14, 2, 30, -15, -10, -12, -17, 14, -19, 16, 16, -5, 12, -2, -13, 8, -7, 60, 24, -21, -20, 61, -32, 16, 13, -46, 11, 81, 6, -28, -11, -11, 3, -46, -11, 29, -6, 42, -27, 45, -18, -5, -22, -18, 18, 54, 5, 27, -14, -4, 3, -12, 27, -15, 16, -32, -5, 6, 9, 32, 18, 5, -20, -5, -33, 24, -16, 16, -17, 21, -19, -4, -48, 8, -14, 19, 1, 13, -28, -21, 29, 38, -19, -18, 3, -54, -8, 24, 5, -5, 25, 14, -2, -19, -21, 23, 3, 5, 9, -21, -20, 24, -35, 15, -18, -35, -41, -11, -16, -30, 10, 4, -41, 0, 11, 10, -26, 29, 0, -51, 35, 13, -16, -13, -1, 3, -13, 23, 2, 18, 10, -10, -10, 17, -6, 42, 20, 22, -15, 6, 10, 0, 10, 14, -9, 21, 15, -10, -27, -19, 25, -8, 0, -20, -14, 2, -17, 16, 1, 39, -27, -17, -13, 33, -7, 33, 17, 8, 20, -48, 28, 11, 14, -47, 25, 16, 17, -43, -20, -28, 1, -3, -7, 7, -10, 23, 14, 7, 11, -14, 21, 3, 15, 20, -27, 29, -13, -35, 14, -25, -6, 39, -32, -4, -28, -2, 10, -14, -22, -38, -22, 7, 20, 13, 3, -7, 7, -2, 22, -6, -7, -8, 5, -19, 15, 15, -3, 0, 26, -5, -4, 29, 0, -19, 8, -8, -21, 10, 29, 29, -6, 45, -6, -15, -38, -45, 11, 25, 43, 25, 28, 10, 44, -52, -31, 6, -35, -6, -21, -54, -32, -42, -18, 34, 8, 6, -16, -8, -9, 13, -17, 13, 45, -18, -18, 24, 32, 12, 57, 1, -16, -5, 20, 33, -15, -21, -21, -38, 20, -10, 5, 29, 0, 28, 23, 0, 26, -18, 35, 3, 14, 30, 18, 42, 8, -38, 10, -8, 37, 0, -9, -4, -8, -11, 3, -4, 2, -8, -16, 1, -20, -6, -12, -9, -3, -2, -9, -19, -13, -9, 15, -1, 16, -3, -3, 13, -3, -9, -2, 14, -8, -17, -13, 17, 18, 3, -5, 11, 28, -14, -8, 11, 11, -2, 8, 0, 1, -11, -6, -5, 7, 4, 3, 7, 25, -17, -5, 12, -9, -2, -15, -5, 9, -2, 8, -8, -14, 0, 2, 1, -1, 11, -4, -11, -3, 22, -22, 14, 8, -9, -14, -4, 4, 16, 8, 8, -4, 0, -7, 6, 5, 12, 8, -6, 1, -18, -1, 5, 3, -1, 15, 8, 4, 14, 5, 8, 1, -5, 8, 2, 6, -12, -11, -19, -12, 7, 14, 20, 0, -10, 5, -9, 1, 13, 4, 14, -12, 1, -2, 0, -9, 5, -8, 1, -16, -12, -1, 0, -10, -2, 0, 9, 0, -6, -5, -19, 3, -15, 8, -25, -23, 0, 10, 4, -1, -8, -11, 5, -22, -14, 1, -7, 3, -9, -14, 4, -18, 8, -8, 13, 20, -12, 9, -2, -1, -14, -20, -22, -11, -2, -5, -3, -9, 23, -14, -19, -10, -37, 20, -7, -1, 3, -5, 15, 4, 20, -11, 21, 21, -3, 1, 3, -16, 4, -11, 10, 1, 3, -5, 14, -1, 12, 12, 15, 9, -8, -8, -4, -8, 9, 3, -22, 8, 13, -6, -2, 13, 6, 10, -5, 9, 6, -1, -3, 21, 30, 2, -19, 20, 8, -5, 7, -4, -4, 30, 10, 17, 11, -16, 1, -26, -7, -13, 7, -7, -6, -8, 4, -6, 9, 49, 36, 36, 7, -12, 3, 16, 18, 15, 5, -23, 15, -15, 1, -6, 6, -15, -9, -49, -4, -13, -25, 37, 2, -34, -21, 22, -16, -9, -13, -5, -4, 41, -6, -22, 9, -13, 12, -27, 8, 53, 6, 10, 8, 21, 6, 18, -10, -41, 0, -4, 33, 27, -15, 18, -11, -23, 34, -15, 31, 16, -30, 24, -9, -11, 1, -10, 63, -6, 29, -10, -9, 8, -15, -11, 64, 11, 8, 22, -5, -26, 6, -7, -1, 2, -20, -7, 7, -3, 11, -19, -9, 16, -13, -1, 9, -5, -13, 7, 16, 15, 8, -9, -21, 27, 57, -7, -25, -16, -17, 17, -23, 4, -5, -14, -64, -9, 6, 2, -69, -16, -51, 20, -14, 21, -12, -16, -31, -20, 22, -10, 7, 32, 29, 34, 24, -30, 5, -5, 46, 27, 23, 2, -29, -15, 6, -12, 42, 22, 6, -12, -6, 24, -41, 8, -4, -39, 0, 11, -43, 14, 24, 23, 2, 4, -29, -18, -3, -26, -36, -4, 20, 5, 19, -10, -35, -14, 9, 0, 38, 46, 52, 6, 26, 10, 4, 8, -15, 8, 51, 4, -25, -5, -21, 5, -47, -9, -45, -14, 12, 22, -19, -15, -37, -1, 19, 2, 20, 19, -48, 16, 1, -1, 6, 10, 55, 19, -7, -9, 25, -2, 15, 6, -40, -3, 77, 20, -48, -25, -33, 2, -47, -9, 16, -26, 29, 1, 27, 22, -61, -17, -39, 30, 51, 8, 47, -5, -4, -6, -7, 27}

#define TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0 {-44, -24, -16, 28, 40, -16, -3, -3, 43, -10, 52, 58, 24, 50, 36, 49, 55, 56, 72, 47, 45, 63, 79, 69, 33, 53, 52, 57, 18, 37, 29, 44, 4, 7, -6, 3, -5, -6, 10, 2, 3, 7, -3, -2, -7, -2, 5, 1, 25, 14, 36, 41, 62, 37, 4, 27, 52, 27, 62, 59, 32, 62, 40, 50}

#define TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0_DEC_BITS {6}

#define LSTM_15_BIAS_LSHIFT {7}

#define LSTM_15_OUTPUT_RSHIFT {6}

#define TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0 {2, 15, 47, 21, -2, -34, 34, -2, 0, -25, 5, 6, -16, -3, -15, -12, 16, -30, -8, -32, -19, -34, -42, 9, 1, -8, -32, 25, -4, -10, 25, -2, 44, 10, -1, 12, 10, 29, 44, -33, -10, 2, -7, -4, -11, 22, 9, 14, -7, -7, -1, -1, 17, -12, -2, -15, 35, 18, -6, 4, 3, 21, 28, -9, 8, -20, 18, -53, -11, 2, 0, -40, 7, -9, -36, -11, -2, -49, 0, -21, -31, 16, 22, -10, -1, 13, 31, 47, -13, 0, 8, -13, 34, 20, -21, 29, 11, -17, 13, -7, 6, -28, 16, 8, -21, -6, 0, 25, -15, -36, -34, 13, 7, -63, 8, -2, 15, 25, 11, -19, -23, 23, -4, -26, 13, -17, 12, -5, -8, 7, -28, 4, -10, -7, -26, 10, -3, -18, -2, 0, -6, -17, 10, -13, 22, -17, 0, -8, 3, -30, 19, -11, -5, 37, -8, 5, 19, -1, 4, -12, -9, 20, 4, 20, -8, 8, -4, 9, 2, -30, -16, -2, -7, -1, -2, 29, -4, -19, 5, -27, -11, 10, 11, -9, -44, 22, -7, 2, -17, -3, 10, 12, 1, -19, 16, 8, -36, -24, -12, -34, -1, -4, -27, -13, 8, 5, 1, 19, -4, -8, 17, -9, -7, 33, 15, 13, 10, -24, 3, -14, -4, 18, -7, -22, -10, 20, 16, -6, -27, -15, -6, 22, -38, -5, -33, 60, 3, -16, -3, 8, -12, -13, 13, -4, 11, 12, 6, -42, 15, -15, 1, -12, -11, 10, 20, -5, 14, 9, 5, -15, -32, 28, -30, 7, -28, 25, -1, 19, 21, -19, -3, -36, -18, 5, -34, 20, 21, -28, 26, -24, 2, -3, 1, -3, -7, -18, -21, 20, 21, -36, -15, 32, -13, -6, -13, -28, -1, -16, -3, 12, -1, 14, 15, 8, -2, -13, -31, 18, 31, 3, 29, -31, 12, -7, 9, -14, -23, 14, 11, -9, 1, -21, -4, -21, -17, 17, -11, -14, -5, 26, 19, 2, 22, 4, 4, 11, -16, 19, -34, 19, 23, 8, 30, 8, -17, 34, 7, -25, 1, 31, -22, -8, 16, -13, -17, 30, -24, 4, 0, 5, 25, -43, 16, -10, -10, 3, 17, -2, 4, 5, 17, 23, 14, -30, 7, 7, -21, -16, 39, -6, 3, 7, -5, -14, -44, 33, -16, -2, -4, -13, 1, 2, 35, -15, -7, -4, 3, -25, -12, 7, 27, 7, 7, 3, 2, -13, -11, -6, 11, 20, -11, 4, -24, -15, 3, 3, -2, 4, 38, 23, 16, 18, -23, -41, -23, -17, -26, -13, 11, 33, 7, 7, -2, -22, -3, -7, 33, 7, 23, -30, -13, 29, 12, -24, -24, -7, 36, 9, 24, 2, 22, -2, -46, -14, -17, -18, 18, -39, -20, -14, 64, 22, 37, 35, 0, -5, 35, 13, 25, 17, 18, 21, 46, 19, -6, 20, -2, -2, -34, 16, -36, 5, 41, 10, -28, -6, -8, 16, -38, -19, -59, -2, 7, -2, 40, 53, -26, -12, 5, -7, 32, 39, 71, 3, 14, 32, -5, 5, -40, -27, 14, 20}

#define TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0 {-9, 9, 9, 23, 30, 99, -6, -24, 4, 22, -2, 23, 11, 3, 27, -12, -24, -11, -32, -57, 32, -30, -24, -54, 8, 31, -8, 2, -17, 25, -32, 35, 38, 21, 2, 3, -5, 36, 8, 1, -13, -26, 19, -34, -28, -29, 55, 5, -3, -13, 2, -21, -69, 60, -11, 30, -31, -63, 20, 3, -16, 0, -28, 3, -7, 15, 5, 26, 30, 15, 45, -10, 8, 37, 13, -9, -7, -59, -21, 51, 28, 5, -9, -39, 31, 33, 26, 0, -48, 8, 20, 1, -7, -49, 49, 35, 2, 8, 32, -3, 19, 16, 35, -9, 16, 48, -10, 18, -10, 6, -26, -36, -7, -2, 17, -75, 15, 4, 19, -1, 5, -7, 22, -34, 7, 29, 14, -20, -3, 19, 22, 34, -17, 5, -20, 7, -11, 11, -36, -17, 3, -18, 14, -4, 2, 7, 1, -10, 6, -46, 12, -2, 28, -6, 4, -3, -14, -9, 9, -7, -19, -28, -2, -15, -9, 37, -4, 53, 15, -12, 9, -2, 28, 13, -7, 7, -24, 27, 16, 11, -9, -37, 11, 20, -4, -18, 13, 9, 11, 5, 7, 5, -22, -9, 21, 18, 36, 21, 28, -8, -3, 1, 8, 14, -1, -18, -8, 11, -53, -55, 22, 16, 59, 13, -8, -63, 4, 12, 38, -6, -22, -48, 21, 31, 38, 77, 67, 18, -21, -24, 31, 12, -17, -11, -30, -25, 24, 45, 8, -37, -49, -37, 68, -29, 2, 22, 27, 3, -26, -19, 51, 13, -9, -11, -3, -25}

#define TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0 {-1, -5, -5, -28, -21, -2, -22, -22, 97, 97, 71, 108, 51, 79, 100, 59, 8, 10, -11, -5, 13, -1, -21, -9, 10, 21, 28, 29, -4, 15, 16, -18}

#define TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0_DEC_BITS {6}

#define LSTM_16_BIAS_LSHIFT {6}

#define LSTM_16_OUTPUT_RSHIFT {5}

#define TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0 {-15, 13, -9, 16, -18, -8, -6, 11, 6, -3, -12, -22, 10, 31, -4, -19, -30, -2, 0, 19, 35, -29, 10, 17, -13, 0, -8, 35, -11, 33, -25, 21, -7, -39, -25, -1, 24, -30, -16, -2, -1, 29, 82, 6, 13, 20, 0, -9, -5, 20, -49, -29, 3, 1, -28, 16, -16, 30, -27, -1, 5, 13, -11, 8, -11, 21, 6, -1, 3, 8, 24, 16, -13, -28, 9, 16, 18, -32, -19, 58, -29, 16, 4, -23, -5, -12, 7, 4, -27, -36, 9, 8, -6, -21, 4, 7, -32, 26, 5, 19, -21, 20, 37, 8, 14, -21, 31, 34, 15, -31, 19, 8, -19, 15, -25, -7, -14, -2, -25, 27, 12, -4, 5, 19, -19, 8, 14, 50, 2, 1, -8, 19, 10, 10, -6, 14, -1, 18, -6, -15, 27, 11, -15, -16, 37, -1, -12, 8, -9, -30, 0, 19, -10, -11, 15, 1, 30, 25, 2, 17, -27, -31, -3, 14, 14, 25, 5, 1, 0, 33, -2, 19, 12, -30, -22, -12, -24, 4, 23, -22, 24, 12, 1, 7, 14, 22, -9, -9, -11, -24, 4, -17, 1, 17, 20, 8, -5, 7, 65, 25, -38, -45, -4, 37, 8, -10, -40, 19, -21, 37, 6, -30, -11, 5, 50, -26, -8, -49, 27, 2, 9, 1, 44, 5, -11, 4, 43, 7, -17, 15, 46, -3, 38, -37, -18, 0, 16, 25, -10, -25, -6, -4, 9, 1, -6, 57, -16, 34, 25, 3, 13, 12, -8, -24, 59, 3}

#define TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0 {13, 3, -50, -29, 60, -4, 49, -32, 25, 6, -42, 20, 32, 34, -25, -36, 47, 25, -59, -32, 24, 57, -23, -29, 10, -8, 33, 20, -2, 3, 22, -48, 20, 25, -21, -2, 15, 13, -14, -17, -5, 40, -18, -3, 28, 56, -31, -18, 16, 28, 25, -30, 7, 24, -49, -51, -15, -43, -35, -11, -7, -12, 15, 32, 22, 9, 7, 5, -3, 51, 67, 25, 9, -63, -24, -13, 5, -6, 35, 15, -19, -34, -2, 22, 14, -2, 28, 52, 21, 26, 43, 30, -17, 21, -21, 8, -4, 56, -2, 10, -29, -29, 32, 34, -1, -16, 45, 7, 38, 30, 18, 61, -5, 2, 41, 54, -23, -33, 55, 46, 22, 15, -44, 33, 15, 43, -2, -13, -2, 12, -4, 16, -12, -10, -28, 6, -13, -24, -7, -13, -6, 5, 1, 23, 15, -10, -17, -2, 8, 5, -22, -5, -44, 0, 10, 3, -7, 17, 16, -28, 8, 16, 0, 24, 3, -5, 7, 29, 21, -3, -14, 15, 21, 1, -22, 10, -4, -7, -20, -7, -9, -4, 3, -2, 11, 0, -7, -11, 8, 10, -11, -3, 20, 32, -4, -12, -36, 10, 37, -1, -54, -55, -11, -31, 35, 21, 79, 32, -8, -67, 6, -10, 1, -28, 19, 77, 29, 27, 28, 24, -8, 22, 13, 23, -8, 25, 86, 47, -2, 28, 24, 38, -11, -14, 58, 37, 3, 2, 52, 14, 32, 13, 24, 8, -25, -63, -10, -14, 45, 35, 73, 16, 21, 25, 4, -14}

#define TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0 {-30, -38, -45, -46, -29, -17, -54, -16, 106, 103, 108, 102, 81, 114, 91, 111, 8, 17, -12, -1, -12, 6, 8, -12, 17, 29, 9, 25, 10, 38, 23, 40}

#define TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0_DEC_BITS {6}

#define LSTM_17_BIAS_LSHIFT {6}

#define LSTM_17_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_5_KERNEL_0 {-50, -12, 41, 67, -1, -25, -36, -18, -19, -34, 29, 0, 7, 35, 35, -44, 67, -2, -65, 44, -44, -40, -22, 35, 9, 5, 7, -33, 7, -2, 8, 32, 39, -62, 40, -41, 19, -69, -34, 20, 26, 40, -27, -13, 38, -38, 13, 55}

#define TENSOR_DENSE_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_5_BIAS_0 {-37, 70, -71, -116, -21, 120}

#define TENSOR_DENSE_5_BIAS_0_DEC_BITS {8}

#define DENSE_5_BIAS_LSHIFT {4}

#define DENSE_5_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_15_INPUT_OUTPUT_DEC 9
#define LSTM_15_INPUT_OUTPUT_OFFSET 0
#define LSTM_15_OUTPUT_DEC 7
#define LSTM_15_OUTPUT_OFFSET 0
#define LSTM_16_OUTPUT_DEC 7
#define LSTM_16_OUTPUT_OFFSET 0
#define LSTM_17_OUTPUT_DEC 7
#define LSTM_17_OUTPUT_OFFSET 0
#define DENSE_5_OUTPUT_DEC 4
#define DENSE_5_OUTPUT_OFFSET 0
#define SOFTMAX_5_OUTPUT_DEC 7
#define SOFTMAX_5_OUTPUT_OFFSET 0

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

const nnom_io_config_t lstm_15_input_config = {
    .super = {.name = "lstm_15_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_15_lstm_cell_15_kernel_0_data[] = TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0;

const nnom_shape_data_t tensor_lstm_15_lstm_cell_15_kernel_0_dim[] = {3, 64};
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_kernel_0_dec[] = TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_15_lstm_cell_15_kernel_0 = {
    .p_data = (void*)tensor_lstm_15_lstm_cell_15_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_15_lstm_cell_15_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_data[] = TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dim[] = {16, 64};
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dec[] = TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_15_lstm_cell_15_bias_0_data[] = TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0;

const nnom_shape_data_t tensor_lstm_15_lstm_cell_15_bias_0_dim[] = {64};
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_bias_0_dec[] = TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_15_lstm_cell_15_bias_0 = {
    .p_data = (void*)tensor_lstm_15_lstm_cell_15_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_15_lstm_cell_15_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_15_lstm_cell_config = {
    .super = {.name = "lstm_15"},
    .weights = (nnom_tensor_t*)&tensor_lstm_15_lstm_cell_15_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_15_lstm_cell_15_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_15_lstm_cell_15_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 4,
    .units = 16
};

const nnom_rnn_config_t lstm_15_config = {
    .super = {.name = "lstm_15"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_16_lstm_cell_16_kernel_0_data[] = TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0;

const nnom_shape_data_t tensor_lstm_16_lstm_cell_16_kernel_0_dim[] = {16, 32};
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_kernel_0_dec[] = TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_16_lstm_cell_16_kernel_0 = {
    .p_data = (void*)tensor_lstm_16_lstm_cell_16_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_16_lstm_cell_16_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_data[] = TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dec[] = TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_16_lstm_cell_16_bias_0_data[] = TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0;

const nnom_shape_data_t tensor_lstm_16_lstm_cell_16_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_bias_0_dec[] = TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_16_lstm_cell_16_bias_0 = {
    .p_data = (void*)tensor_lstm_16_lstm_cell_16_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_16_lstm_cell_16_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_16_lstm_cell_config = {
    .super = {.name = "lstm_16"},
    .weights = (nnom_tensor_t*)&tensor_lstm_16_lstm_cell_16_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_16_lstm_cell_16_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_16_lstm_cell_16_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .q_dec_c = 3,
    .units = 8
};

const nnom_rnn_config_t lstm_16_config = {
    .super = {.name = "lstm_16"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_17_lstm_cell_17_kernel_0_data[] = TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0;

const nnom_shape_data_t tensor_lstm_17_lstm_cell_17_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_kernel_0_dec[] = TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_17_lstm_cell_17_kernel_0 = {
    .p_data = (void*)tensor_lstm_17_lstm_cell_17_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_17_lstm_cell_17_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_data[] = TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dec[] = TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_17_lstm_cell_17_bias_0_data[] = TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0;

const nnom_shape_data_t tensor_lstm_17_lstm_cell_17_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_bias_0_dec[] = TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_17_lstm_cell_17_bias_0 = {
    .p_data = (void*)tensor_lstm_17_lstm_cell_17_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_17_lstm_cell_17_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_17_lstm_cell_config = {
    .super = {.name = "lstm_17"},
    .weights = (nnom_tensor_t*)&tensor_lstm_17_lstm_cell_17_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_17_lstm_cell_17_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_17_lstm_cell_17_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 8
};

const nnom_rnn_config_t lstm_17_config = {
    .super = {.name = "lstm_17"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_5_kernel_0_data[] = TENSOR_DENSE_5_KERNEL_0;

const nnom_shape_data_t tensor_dense_5_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_5_kernel_0_dec[] = TENSOR_DENSE_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_5_kernel_0 = {
    .p_data = (void*)tensor_dense_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_5_bias_0_data[] = TENSOR_DENSE_5_BIAS_0;

const nnom_shape_data_t tensor_dense_5_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_5_bias_0_dec[] = TENSOR_DENSE_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_5_bias_0 = {
    .p_data = (void*)tensor_dense_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_5_output_shift[] = DENSE_5_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_5_bias_shift[] = DENSE_5_BIAS_LSHIFT;
const nnom_dense_config_t dense_5_config = {
    .super = {.name = "dense_5"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_5_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_5_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_5_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_5_bias_shift
};

const nnom_softmax_config_t softmax_5_config = {
    .super = {.name = "softmax_5"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_5_OUTPUT_DEC};
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

	layer[0] = input_s(&lstm_15_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_15_lstm_cell_config), &lstm_15_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_16_lstm_cell_config), &lstm_16_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_17_lstm_cell_config), &lstm_17_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_5_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_5_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_18_NNOM_H