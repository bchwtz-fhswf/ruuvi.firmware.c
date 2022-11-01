#ifndef MODEL_15_NNOM_H
#define MODEL_15_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_15_nnom
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
#define TENSOR_CONV2D_20_KERNEL_0 {24, 42, 8, 29, 1, -23, 5, 1, 15, 11, 27, 20, 43, 15, 19, 41, -30, 39, -33, -18, -5, -30, 56, -10, 33, 52, 17, 18, -9, -15, 14, -29, -22, -63, -25, 26, 27, -8, 26, -7, 24, 6, 6, 19, 9, 45, -30, 20, 35, 32, -42, -48, -35, -1, 21, 27, 40, -17, 18, -36, 25, 16, -25, -41, -8, 18, 8, -32, 5, -34, -34, 59, -46, 63, -29, -4, -6, -21, 31, 28, 11, -31, 16, -26, -26, -2, 26, -27, 13, 0, -11, 4, -33, 24, 53, 59, -7, -29, -5, 8, -8, -40, 1, -2, -3, -33, 4, 28, -28, -21, -46, -47, -27, -3, 3, 16, 28, 48, 39, 23, -18, 39, 10, 17, 4, 7, 6, 46, -9, 44, -37, 74, -63, -4, -3, 26, -18, -19, -34, -19, -5, -10, 36, 37, -29, -10, -9, -50, 0, -8, 24, -5, 24, 23, 29, 67, -16, -47, 13, -36, 3, -33, 28, -70, -6, -53, 26, -26, 16, -33, -39, 17, -20, -20, 32, 20, 40, -32, -49, 15, 55, 7, 33, -13, 55, -32, 32, -4, -55, 2, -40, 12, 21, -58, 30, -50, 24, -12, -12, -17, 0, -41, -24, -2, 36, 7, 32, -53, -28, 32, 20, 40, -4, -8, -19, 48, -81, -6, -8, -18, -9, -16, -14, 17, -25, 1, -9, 8, -37, 41, -6, 23, 26, -26, 28, -21, 33, 14, -7, 53, -15, 44, 17, 26, 38, 31, 12, 17, 48, 43, 57, 9, 11, -52, -9, -8, -17, 0, -25, 7, -29, -6, 19, -55, -13, -19, 18, 16, 26, 51, 30, 1, -8, -12, -46, -57, 42, -40, -1, -27, -30, 33, -19, -24, -24, 67, 5, 5}

#define TENSOR_CONV2D_20_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_20_BIAS_0 {-10, -97, -10, 5, -75, -66, -40, -59, -15, -25, -11, -106, -74, -12, -76, -67, 10, -82, -6, 15, -15, 6, -8, -50}

#define TENSOR_CONV2D_20_BIAS_0_DEC_BITS {9}

#define CONV2D_20_BIAS_LSHIFT {6}

#define CONV2D_20_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_21_KERNEL_0 {6, -7, -15, 10, 13, 14, -18, 3, -4, 3, -6, 10, 2, -13, 9, -1, -10, 17, -3, -1, 11, -7, -5, 1, -4, -3, -14, -7, 19, 20, 1, 25, -7, 3, -4, -33, -12, -36, -1, 15, -20, -2, 8, -19, -26, -17, -36, -23, -20, 10, 12, 3, -8, 19, 3, -3, -13, 14, 7, 19, -15, -8, -2, -27, 4, 13, 3, 3, -17, 6, -17, -5, -13, -20, 12, -34, 11, 6, -26, 15, 5, -5, -11, 7, -10, 17, 5, 7, 1, 3, -1, 0, -19, 16, 0, 3, 2, -17, 7, -3, -1, -16, 32, 4, -3, 10, -5, 32, 15, 7, -12, -4, 3, -10, 15, 6, -3, 8, 17, -1, -20, 32, -27, -14, 6, -7, 7, 7, 11, -12, 6, -14, -24, 1, -19, 5, 6, 0, 3, 7, 6, -17, 14, 12, 1, -11, 16, -7, -1, -15, 15, 10, 5, 9, 2, -21, 15, -1, 5, -12, -6, 6, -26, 10, -3, -27, 14, 13, -22, -6, 3, 2, 17, 15, -6, 5, -40, 1, -11, -8, 11, -2, 5, 13, 1, 2, 14, -40, 0, 2, -19, 22, 2, -12, -10, 6, 4, -11, 10, 1, 0, 3, -6, 22, 1, -15, -9, -11, 12, 13, 3, 9, 9, 5, -6, 8, 2, -2, 0, 3, 3, -14, 1, 8, 5, -2, 14, 5, -11, 2, -3, 0, -4, 6, -2, 4, -8, -21, 5, 9, -4, -1, 3, -1, -1, 11, 25, 12, 0, -14, -12, 18, -16, 13, 11, -9, 4, 20, -1, -3, -5, -4, 6, -3, -3, -7, -9, 1, 22, 8, 20, 6, -16, -3, -17, 4, 5, -3, 4, -18, -20, 6, 20, -4, -5, -13, -10, -12, 2, 10, 1, -1, -12, 13, 0, -5, 9, -20, 6, 13, 2, -14, 8, 2, 7, 9, -9, 11, 0, -12, 8, 6, 8, 5, -3, -18, -6, 4, 9, -2, 0, -6, -20, 12, 13, -9, -23, -59, 6, -18, 12, -13, 13, 10, -24, 2, -16, 11, 17, 12, 16, 10, 3, 17, -16, -16, -13, 7, 7, -23, 26, 1, -10, -12, 5, -27, 8, 15, 9, 0, 2, -32, 5, 20, 11, 7, -3, 2, -1, -14, 20, -5, 20, -25, 19, 18, 7, 6, -18, 1, -6, -22, 6, -16, 1, 22, -1, 1, 7, -9, -26, -19, -5, -2, -2, 8, -16, -15, -7, 4, -2, -21, -11, -5, -4, 8, 23, -4, 7, 28, -20, 10, -5, 10, 0, 8, -3, -13, 4, 1, 5, -17, -11, 8, 4, -11, 6, -2, -6, -3, 0, 8, 5, -13, 0, 1, 0, 7, 4, 16, -1, 18, -13, -1, -18, -7, 12, -14, -1, 2, -15, -13, 0, -1, 4, -7, -2, 1, 20, 6, 8, 6, -7, -11, 1, -1, 0, 4, 7, -4, 2, -5, 2, 22, -10, -5, -3, 3, -7, -12, 8, -1, 3, -7, -3, 8, 16, 0, 3, 8, -13, 4, 0, -10, -2, 11, -4, 6, -4, -1, 1, 4, 17, 3, 3, -4, -9, 0, 11, -4, -2, -1, -6, -17, -4, -16, -6, -6, -10, -3, -1, 14, -1, 7, 9, -5, 12, 6, 8, -19, 5, -25, 19, -9, -1, 2, 16, 14, 9, -8, 9, 20, 4, -6, 1, 26, -12, 19, 7, -29, 14, -3, -4, -1, -18, -5, 0, -11, -17, 10, -14, -4, -5, 2, 13, 9, -6, -8, 4, 3, 6, -31, -17, 4, 1, 9, 2, 2, 3, -5, 6, 22, 13, -5, -7, 18, -36, 7, 5, 3, 16, -18, 9, 9, 8, -1, -9, 5, 3, 9, -22, -15, -14, -5, -30, 8, 21, 5, -2, -4, 3, -14, 7, 2, 7, 5, 7, 6, 13, 9, -4, 6, -2, 22, -2, 12, 8, -25, -2, 7, 13, -14, -6, 17, 6, 9, 3, -13, 0, 15, -18, -19, 9, 1, -3, 1, 11, -27, -13, 8, -5, -2, -13, 12, -30, 1, -2, -6, 10, -17, -3, 7, -14, 14, 2, -3, -8, -1, -21, 0, 3, 9, -5, 12, 9, 2, 2, -4, 9, 14, -3, 14, -2, 12, 5, 5, 23, -4, -14, 9, 0, -1, -2, 5, 19, 9, -2, 21, -1, 2, 9, 1, -8, 6, -1, -4, 11, -1, 11, 1, 7, 8, -3, 5, -1, -11, -17, -1, -1, 11, -8, 15, 14, -2, -11, 18, 1, 5, -4, 10, 3, 7, 20, 5, 13, 15, -2, 16, -5, -3, 4, -7, 18, -2, 4, 27, 3, -12, -2, 6, 6, -4, -4, 3, 1, 5, 8, 1, 4, -15, -13, 1, -9, 7, -1, 2, -1, 8, 9, -7, -16, 0, 15, 4, -10, -5, 16, -34, 8, 45, -47, -5, 23, 8, -23, 4, 10, 8, 9, -19, 15, 10, -4, -10, -17, -7, 14, 3, -17, 19, -1, -13, -14, 19, -6, -4, 4, 2, 7, -8, -11, -11, 0, 1, -2, -4, 5, -28, 7, 9, 12, 29, 1, 27, 4, -7, 9, 33, -10, 12, 18, 4, 2, 22, 4, -8, 7, -12, -1, 7, -6, -15, -2, 4, 15, 11, -8, 3, 1, -22, -1, 22, -9, -4, 17, 6, 3, 6, -9, -5, 6, -14, -1, -23, 11, -5, 5, 7, 8, 11, 23, 7, -1, -25, -3, 21, -15, 6, -7, -6, 9, 9, -17, -10, 6, 6, -11, 22, -2, -17, 1, 5, 9, -2, -3, 2, 3, -53, -9, 3, -7, -8, 18, -2, 4, 3, 5, -2, 14, -2, -3, -6, 5, -17, 5, 1, 21, 2, -1, 7, 2, -17, 9, 15, -21, 0, 17, 1, 7, 9, -24, -1, 12, -9, 1, 10, -8, 4, -11, -12, 4, 12, 1, 15, 1, -18, -35, 16, 10, -3, 7, 2, -2, -24, -2, -25, 1, -3, -43, -19, 0, -8, -4, -9, -21, -8, -20, -10, 5, -18, 9, -17, -22, 20, -7, 4, -10, -13, 15, 12, 18, -15, -1, -18, 4, -16, -25, -7, 24, -1, -11, 13, 6, -13, -1, 15, 0, 3, -31, 2, -13, -11, -6, -5, 2, -4, 3, -19, -10, -32, -23, 11, -5, -5, 1, 17, 12, 1, 19, 0, -2, 28, -18, -28, 32, -4, 10, 8, -5, -5, -2, -11, -5, -28, -5, -1, -3, -3, -6, -13, 9, -2, -5, 6, -5, 1, 3, -8, -11, -10, 7, -3, 0, 12, -7, -32, -1, 5, -2, 18, -26, -1, 21, -18, -5, 7, -6, -3, 13, 3, -16, -7, 7, -19, -5, 0, 5, 6, -16, 21, 7, -31, 1, -7, -3, -4, -15, 25, 7, -1, 7, 12, -15, 11, -2, 7, 8, -1, -6, 14, 4, -1, -14, -33, 13, 17, -5, -3, 14, -17, -14, 0, 2, 2, 6, 6, -6, 7, -6, -4, 3, -24, -2, 7, 7, 26, -18, -3, 13, -24, -26, -9, -11, -33, -8, 34, 18, 8, 2, 0, 2, 4, -12, 15, -3, -31, 2, -3, 9, -2, -7, 4, -13, 4, 5, -5, -1, 4, 22, -5, 6, 14, -8, 13, 1, -8, -3, 31, 4, -16, 13, 8, -5, -2, 4, 12, -6, -2, 17, 0, -4, 6, 26, 8, 8, 18, -7, 0, 4, 16, -15, 11, -7, 4, 3, 5, 15, 2, 2, 12, -4, 6, 4, 5, -8, 13, 14, 14, -3, 5, 3, 3, 4, -5, 14, 13, 11, -5, 3, -1, 3, 3, 6, 11, -2, 7, -2, -3, 3, 2, 5, 4, -3, 7, 2, -7, 7, 10, 5, -20, -6, 23, 1, -1, -11, -8, -13, 0, -9, 20, 1, 3, -1, 7, 3, 3, -2, 2, 8, -8, 13, -3, 4, 16, 4, 9, 2, 2, -2, 10, 18, 4, 3, 6, -11, -8, 2, -9, 2, 3, -4, 3, 2, 11, 11, 14, -4, -14, -5, -9, -4, 0, -5, -5, 11, -2, -13, 16, 8, 4, 7, 4, -2, 6, 0, 6, 18, -4, 20, 17, 22, 7, -4, 33, 0, 5, 0, -7, 13, 25, 6, 5, -15, 3, 5, 7, -4, 29, -9, 14, 3, 27, 14, 23, 14, 12, 3, -15, -10, 2, 11, 5, 1, 0, -2, -5, 2, -5, -4, -3, 1, 0, -3, 2, 1, 2, -1, 3, -4, -4, 0, 2, 2, 2, 1, -5, -4, 0, 2, -2, -2, 2, 2, -5, 3, -3, 0, -1, -4, -3, -4, -4, -2, -2, -4, -3, 3, 3, -1, -1, 1, 2, 2, 1, -2, -2, 3, -1, -4, 1, -3, -5, -6, -2, 0, -1, -4, 3, 0, 0, -3, -2, -1, -3, -2, 1, 2, 2, -2, -3, 0, -4, -5, -2, -1, 3, -1, 1, -4, -3, -4, -4, 3, -3, -5, 1, -1, -2, 0, -5, -5, 1, -3, 3, -3, -4, -5, -2, 1, -3, -3, -3, -2, -2, -2, 0, 1, 2, -1, -2, -5, -3, -4, 1, 2, 3, 0, -3, -4, 0, 2, -5, -5, 3, 2, 2, -1, 2, -2, 1, -2, -1, -5, -6, -1, -5, -6, -5, -3, -5, 2, -5, -1, -4, 0, 2, -3, 2, 4, 3, -4, -4, 2, -3, 2, -4, 0, -2, 0, -4, -1, -2, -3, -3, -4, 0, -2, 0, 1, 4, -5, -1, -1, -3, -1, -1, 2, 1, -2, 4, -2, 0, -4, -5, 1, -1, 5, -17, -1, 3, -19, -29, -20, -20, -4, -19, 15, -33, -11, -3, -18, -6, -24, -11, 2, 11, 5, -8, -7, -20, 14, 2, -1, 3, -34, 13, 7, -25, 5, -6, 5, -25, 0, 6, 6, 17, 17, -28, -6, 7, -3, 8, 0, -12, 5, -5, -17, 9, -36, -44, -37, 7, 3, -3, 15, -14, -1, 8, -23, -8, 6, -24, 5, 1, 14, -4, 3, -21, -6, -2, -13, 11, -28, -14, 9, -14, 3, 12, 2, -19, 16, -9, -29, -1, -10, 0, 2, 3, 4, 3, 0, 0, -6, 2, -1, 8, -15, -9, 0, -5, 3, -2, -2, -7, 12, 10, -20, -8, 7, -16, -11, 1, -1, -4, -27, -26, 7, -13, 2, 5, -15, -24, -1, -3, 8, -5, -1, -2, -10, -18, -3, -26, 12, 6, 1, 16, 3, 13, 2, 6, 6, 0, -6, -16, -17, 3, -6, -22, 4, -16, -3, 2, 8, 19, 2, -3, 7, -24, 10, 16, -2, -5, -3, -16, -5, -18, 10, 4, 1, -18, 9, 5, 2, 1, 7, -19, -10, 17, -9, 4, 4, 2, 12, -7, -22, 16, 2, 4, 6, -18, -8, -7, 9, -24, 15, -4, -1, -3, 4, -6, -23, 4, 25, -13, -6, -3, 11, 10, -10, -10, 3, -9, 9, 20, 47, -3, 4, 9, -10, -6, 13, -7, -17, 20, -9, -3, 10, -12, 1, 16, 5, -2, 8, 15, 6, 31, -3, 15, -3, 0, 2, 2, -6, -14, 7, -4, 9, -22, -5, -4, -7, 1, 7, -8, 11, 2, -12, 3, 12, -6, 12, -11, 1, -5, 3, -22, 14, 12, 9, 22, 0, 8, 20, -9, -13, -16, -4, 10, -3, 20, -3, -8, 4, 2, 1, -17, -11, -11, -7, -11, -1, -14, 5, 0, 17, -6, -5, -8, -7, 0, 6, 11, 9, 14, -8, -5, -7, -9, 21, 13, 8, 2, -16, -9, 5, -10, -11, 9, -1, 20, 12, -4, -3, -10, -11, 14, 10, 0, 2, 12, -5, 19, -2, 3, -11, 19, -3, 4, -8, -20, -2, -6, 25, 2, -11, -13, -21, -13, -3, -4, 12, 2, -21, -11, 5, 12, 24, -8, -4, 0, 7, 23, -13, -13, 9, 16, -2, -5, -25, -7, -4, -30, 3, -5, -4, 29, -6, 2, -4, -6, 13, 8, 10, 1, 12, -1, 6, -6, 4, -12, 6, 16, -19, -21, -8, 19, -32, -51, 8, 2, 8, -8, 7, -4, -4, -9, -2, 13, 17, 11, -14, -27, 7, -27, -8, -7, -48, -16, -4, 16, 11, -20, -11, -11, -11, 1, -7, -15, 1, 2, 2, -4, 7, 22, 3, 24, 1, 8, 3, 22, 20, -1, -19, -25, 4, -8, 5, 7, -5, 8, -20, -26, -8, -8, -3, 2, 1, 6, -37, -14, -5, -21, 3, 13, 8, 8, 10, 11, 9, 6, -9, -7, -24, 8, -7, -16, 0, -1, 6, 13, -23, -3, 4, -16, 3, -2, -8, 19, 5, 1, -12, 17, 7, -4, -2, 5, -4, 5, 11, 21, -1, 12, -23, -8, 3, -39, 8, -4, 4, -18, -1, 1, -9, -12, -25, -7, 6, -26, 1, 5, -8, 0, -14, -6, 9, -28, 9, 7, 14, -15, -2, 11, 13, 14, 24, -4, 8, -9, 10, 9, -3, -4, 0, 10, -9, 4, -5, -12, 9, 9, -45, -7, 4, -21, 4, 17, -20, 1, -15, 0, 10, 1, -24, -13, -18, -31, -2, -16, 9, -1, -40, 4, 4, 7, 2, -18, 20, 26, -9, 25, 3, -1, -23, 36, -16, 2, -9, -23, 0, 7, 9, -1, -10, 6, 2, -4, -13, -27, -1, -1, 9, -2, 17, 2, 2, -14, 5, -2, -16, -10, -12, -11, 1, 15, -11, 1, -20, 8, 4, 19, 14, 5, 5, 0, 12, -3, 10, -16, -1, -32, 4, -15, -30, -31, 21, -9, -17, -4, 10, 4, -4, 7, -18, 5, 10, 6, -1, 0, 5, 7, 9, 6, 9, -5, 14, -15, -31, 14, -1, 4, 0, 4, -4, 22, -8, -1, 2, 28, 4, 19, -4, 12, 20, 4, 3, -12, -13, -14, 5, -16, -19, -18, 25, 5, -9, 15, 3, -1, 13, -22, 22, 16, 4, -4, -10, 17, 15, 14, 4, -31, -1, 8, 5, -31, -3, -6, 6, 14, -12, -19, -17, 7, 1, -4, -5, 7, -18, -14, -1, 4, -3, -2, -5, 12, -7, -1, -13, -2, -15, -11, 20, 7, -2, -9, -2, -11, -13, -1, -9, -8, 0, 24, 7, -2, 12, -7, 20, -22, -3, 12, -12, 7, -4, -1, -23, -22, 1, 1, 3, 1, -11, 10, -12, 3, -5, 10, 11, 11, -8, 2, 12, 4, 3, 4, 7, -9, 37, -10, -14, -16, 11, -4, -5, 1, -3, -6, -25, -5, 9, 0, -10, 14, -3, -4, -21, -6, -7, 11, 16, -1, -6, 16, -1, 3, -4, 17, -5, 7, -2, -4, 2, -9, 2, 7, -4, 14, -21, -2, -5, 2, -5, -21, 1, -7, 12, 12, -18, 19, 10, -18, -9, -9, 4, 13, -8, 0, 5, -2, 14, 8, 5, -12, -18, 15, 7, -1, 14, -9, -3, 7, 0, -16, 8, 8, 19, 1, 12, 0, 9, -9, 1, -18, -1, 1, -10, 10, -2, -2, 14, -4, 2, -10, -2, -10, 15, 2, -16, -6, -3, 0, 11, 14, -3, 4, 0, -8, 5, 10, -8, -6, 16, 29, 5, 11, 0, 23, 2, 25, -1, 8, 8, -21, -22, -10, -3, 0, 8, -8, -10, -2, 1, -13, -3, -22, 7, 29, -15, -11, -5, -6, -7, -5, -25, 8, -21, -29, 9, -11, 13, 21, -24, 6, -6, 13, 0, 4, 14, 15, 6, -3, -12, -7, 20, -3, 0, 34, 14, 18, -1, -1, -10, 9, 39, 1, 19, 11, -5, 3, -6, -3, -5, -6, 3, -9, -20, 2, -24, -15, 1, -29, 1, -13, 2, -6, -11, -64, -32, 1, 4, 3, 6, -11, 16, -1, 3, -2, -18, 5, -2, -28, 2, 0, -18, -11, 3, -19, 6, 2, 4, 0, 9, 13, -4, 20, 4, -11, 5, -8, 3, 18, -11, -11, -8, 17, -13, -17, -4, 4, 16, -11, -17, 26, -19, -8, 6, 13, 14, 7, -4, -23, -2, -2, 11, 1, -26, 8, 0, -14, -6, -11, -41, -7, 3, -17, 13, 8, -6, -3, -21, 6, 12, -1, 3, -18, -2, -37, 5, -11, -10, -15, 8, 21, -10, -20, -20, -20, -13, -15, -47, -15, -1, 6, 0, -6, 14, -11, -9, 13, -19, 2, -8, 8, -17, -6, -6, 0, 3, 9, -1, 15, 1, -6, -2, -5, -2, -11, -17, -2, 15, 7, 10, 9, 11, 7, 9, 5, 3, -3, 8, -5, 13, -3, -24, -9, 16, -12, -10, 29, -5, 13, -11, -41, 15, -12, 11, 4, -18, -3, 4, 27, -10, -9, 7, -11, 11, 7, -14, 6, 1, -41, 0, 2, -12, 27, 1, 4, 14, 7, -7, 0, 6, 3, 0, 4, 1, 3, 3, 23, -12, 21, 38, -13, -3, -13, -13, -23, -1, -11, 15, 8, 5, 20, 0, 4, -5, 8, -16, 14, 7, 0, 3, -6, 12, 13, -2, 10, 5, 19, 19, -13, 5, 2, 11, -6, -1, 12, -2, -16, 1, -19, -22, 2, -3, 16, 12, 18, 8, 4, -2, -26, -3, -3, -17, -7, 10, 0, 10, -4, 3, -8, -4, -3, -6, 8, -5, 0, 3, -19, -12, -16, 5, -30, -3, 22, -9, 5, -1, -4, -6, -13, 2, 4, -1, -10, -1, -17, 4, 12, -17, -1, 11, -1, 1, 26, 6, 9, 3, -13, 11, 5, 6, 14, 8, 6, -8, -27, 5, 9, -3, -1, -14, 7, 1, -24, -20, -10, -1, -14, -21, 2, 9, -1, -6, -4, 1, 0, -32, -14, 8, 2, -16, -8, 6, 0, -4, -1, -12, -11, 6, -17, 14, 9, 1, 17, 9, 15, 7, -1, 2, 11, -2, -3, 6, -26, 9, 13, 2, -22, -3, 6, -10, -17, -6, 10, -1, -8, -19, 12, 4, 1, 19, -56, 2, 10, -5, -23, -18, -14, -11, -7, 5, -11, 14, -1, -20, 8, 4, 4, 8, 2, 11, 15, -20, -9, -25, 18, -15, -13, 5, 5, 17, -13, 2, -1, -5, -10, -3, 4, -9, 20, -7, 4, 1, 7, -9, -18, 20, 1, -25, 10, 3, 21, -17, 0, -21, 15, -10, 7, -10, -4, -7, -4, -5, 2, 12, 12, 6, 3, 6, 13, 3, -2, -4, -23, 6, -13, 7, 3, 7, 7, -12, 2, 1, -6, -1, 1, -17, -3, -31, 13, 4, -26, 1, -3, 6, 0, 18, -7, 1, 5, -7, 6, -8, -1, 1, -26, -3, 29, 8, 2, 3, 1, 0, -11, -5, -7, -11, -7, 11, 7, 19, -4, 3, 1, -9, -9, 13, 19, 13, 2, -5, 3, -9, -3, 4, -3, -6, 18, 7, -1, 7, 16, -5, 14, 12, -3, 2, -2, -5, 16, -7, 5, 9, -19, 4, 19, -3, 0, 19, -2, -4, -6, -6, 4, 12, -24, 12, 12, 10, 17, -6, 7, 1, 1, 21, 7, 13, -8, 3, 15, -3, -3, -2, -3, 4, 20, 2, 2, -1, 10, 1, 19, 2, 22, 7, -20, 2, -5, 10, 10, 4, -1}

#define TENSOR_CONV2D_21_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_21_BIAS_0 {-17, -9, 13, -80, 12, 26, -60, -7, 29, 22, -2, -2, 5, 15, 7, -10}

#define TENSOR_CONV2D_21_BIAS_0_DEC_BITS {7}

#define CONV2D_21_BIAS_LSHIFT {4}

#define CONV2D_21_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_22_KERNEL_0 {-70, 8, -13, 23, -6, 4, 32, 11, -44, 2, -7, 18, 30, -59, 10, 20, -77, 16, -6, -53, 8, -17, 10, -16, -8, -13, -13, 1, 13, -14, -32, -1, 2, 5, 25, -30, 35, 46, -3, 20, 41, 6, 41, -29, -9, -29, 4, 39, -10, 25, -22, -68, -23, 15, -3, -17, -23, 13, -13, 17, 53, 38, -48, 46, 4, -23, -31, 19, 34, 27, -36, -2, 21, -21, 2, 4, -15, -40, 2, -46, 46, 34, 24, 37, 38, 17, 1, -17, 12, -43, 46, -3, 1, -25, 34, 1, -8, -30, -17, 16, -41, 29, -8, 18, 24, 5, 2, -60, 31, 17, 16, 4, 25, 29, 25, 28, 25, 10, 43, -2, 2, -18, 18, -18, 6, -8, 19, 17, -14, 29, 34, 37, 4, 24, 34, 5, -46, 6, 13, -21, -3, 17, 32, 4, 6, 38, 3, 16, 3, -6, 15, -1, -17, -1, 20, 34, -10, 0, 9, 24, 17, -39, 27, 16, -47, -50, 16, 0, -15, 10, -36, 6, -28, 32, 14, 8, -19, 20, -23, 21, -1, -34, 28, -20, -38, 6, -48, 5, -8, 1, 12, 29, 42, 6, 21, -27, -51, 32, -62, -4, 14, -50, -14, -76, 28, 20, 15, 20, -39, -59, 22, -3, 17, -49, 0, 15, 34, 17, -42, -2, -35, 50, 3, -24, -39, 41, -1, -17, -15, -11, 16, 11, 14, 1, 33, -11, -14, -37, 62, 23, -47, -26, -4, -2, -25, 10, 5, -3, 27, 35, -38, -43, 26, -10, -17, 12, -60, -13, 24, -43, -76, -24, 0, -3, 27, 15, -50, -3, 3, 7, 5, -13, -49, -53, 10, -14, -29, 0, -9, -4, 33, 23, -39, -25, -11, 8, 19, -12, 32, 47, 0, -39, 19, -42, 14, -4, -27, 12, -2, 46, 23, 31, 5, -10, 18, 26, -44, -28, 32, 10, -21, -12, -1, -10, -14, 16, 5, -9, -37, 4, -26, -1, 20, -16, 4, -14, -10, -7, -13, -20, -49, -15, 27, 12, -12, -10, 17, -21, 29, -11, -26, -27, 20, -3, -15, 35, 14, -17, 14, 50, 26, -20, 60, 21, -8, -40, -16, -12, 5, -13, -17, -69, 7, -44, 39, -5, 16, -23, -22, -35, 9, -40, 9, 31, 2, -12, 47, -48, -26, -106, 38, 13, -11, 2}

#define TENSOR_CONV2D_22_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_22_BIAS_0 {-64, 36, -47, -22, -95, -81, 50, 9, 62, 31, 25, 46}

#define TENSOR_CONV2D_22_BIAS_0_DEC_BITS {8}

#define CONV2D_22_BIAS_LSHIFT {2}

#define CONV2D_22_OUTPUT_RSHIFT {6}

#define TENSOR_CONV2D_23_KERNEL_0 {-30, 16, 47, -55, -18, -37, 24, -7, -30, -7, -2, 28, 13, -19, -33, -31, 0, -28, -16, -47, 23, 33, -1, -48, 2, 0, 34, 23, -65, 15, -38, -53, -72, -33, -70, -88, 44, -3, 11, -51, -6, -9, 28, 13, -6, 15, 3, 30, -10, -11, -18, -2, -12, -15, -25, -32, -3, -15, 3, 9, 15, -6, 1, -8, -2, -11, -9, -22, 15, 8, -9, -15, -3, 11, 47, -23, -1, -84, 46, 15, 27, -12, 34, -19, 14, -45, 32, -27, -52, -97, -78, -15, -3, 20, -67, 0, -111, -2, -1, -23, -25, -50, -30, 21, 4, 10, -32, 2, 7, -7, 19, 24, -37, 32, -51, -46, -51, -29, -44, -38, -13, -47, -31, 13, -46, -6, 20, 11, 6, -68, 2, 46, 7, -77, -59, -10, 13, 32, 12, -4, -9, -39, -20, 47, 9, -87, 18, -16, -7, 43, -11, -33, -41, -4, -6, -8, 5, 25, 23, 19, 0, 19, 2, 7, -26, -1, 44, -14, -4, -8, -34, 14, -22, 31, 29, -12, 11, -68, 33, 18, -5, -45, -60, -16, -5, 7, 14, -6, 17, -84, 19, -4, 5, -64, -19, -2, -3, 16, 21, -9, 28, -108, 20, 33, -12, -16, -32, -7, -12, 0, -11, 14, 15, -33, -6, -58, -14, -10, 42, 18, 13, 25, -61, -47, -79, -13, -20, -74, 10, 12, -23, -15, -13, 14, 27, -7, -25, 17, 28, 29, 5, -65, 13, 0, 6, 35, 3, -22, -38, 7, -18, 7, 15, 19, -24, -7, 4, 13, -29, -2, -51, -5, 49, -41, -15, -5, -15, -15, 1, -22, -1, 1, -2, 1, -20, -19, -5, -12, -15, -16, 3, -16, 7, -20, -3, -7, -4, 4, 23, -35, -13, 22, -23, 24, 31, -19, 20, -70, 30, 6, 11, -39, -58, -12, -13, -1, 2, 11, 26, -62, 10, -13, -18, -43, 9, -27, -9, 5, 12, 21, -12, 34, 1, 23, -3, -8, 20, 26, 1, 36, -1, -43, 19, -35, 7, 25, -14, 19, 56, -42, -23, -41, 43, -7, 2, -4, 16, -24, 34, -46, -15, -51, 1, -96, -27, -40, 16, 21, -9, -31, 3, -52, 21, 11, -2, -2, -54, -18, 7, 21, -64, -39, 25, -1, -10, -11, 21, 10, -46, 10, 25, 7, 16, -46, 5, 18, 2, -38, 24, 23, -6, 4, -11, 0, 15, -11, 21, -7, -29, 13, 16, 29, -33, -20, -118, -1, -47, -49, -30, -46, -20, -38, -28, -26, 37, -10, 28, -68, 46, -4, -78, -15, 30, -42, -67, -49, -49, 17, 11, 41, -25, 14}

#define TENSOR_CONV2D_23_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_23_BIAS_0 {4, -2, -19, 5, 15, 6, -73, 1, 35, -45, -66, -10, 8, -30, 3, -19, -76, 6}

#define TENSOR_CONV2D_23_BIAS_0_DEC_BITS {7}

#define CONV2D_23_BIAS_LSHIFT {3}

#define CONV2D_23_OUTPUT_RSHIFT {8}

#define TENSOR_DENSE_5_KERNEL_0 {-3, -47, -10, 5, -8, -36, -1, -13, 14, -20, 3, -33, 19, -9, 8, 10, 15, -29, 14, 13, 20, -23, -25, -55, -30, 13, -29, -3, 14, 21, 2, 4, -37, -1, 13, 12, 7, 11, -25, -52, 15, 11, 1, 2, 9, -23, -6, 12, -26, 4, 2, -49, 9, 12, 3, -2, -1, -6, 1, -3, -11, -23, -34, -73, 18, 15, -13, -40, -28, -21, 12, 14, -79, -61, 0, -63, -60, -81, -30, -55, -69, -23, -28, 5, -52, -54, -76, -46, -20, -60, -4, -28, -4, 18, -51, -20, -33, 0, 5, -32, -35, 12, 8, -74, 14, -11, -18, 16}

#define TENSOR_DENSE_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_5_BIAS_0 {-31, 3, -41, -7, 88, -4}

#define TENSOR_DENSE_5_BIAS_0_DEC_BITS {5}

#define DENSE_5_BIAS_LSHIFT {2}

#define DENSE_5_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define CONV2D_20_INPUT_OUTPUT_DEC 9
#define CONV2D_20_INPUT_OUTPUT_OFFSET 0
#define CONV2D_20_OUTPUT_DEC 6
#define CONV2D_20_OUTPUT_OFFSET 0
#define RE_LU_20_OUTPUT_DEC 6
#define RE_LU_20_OUTPUT_OFFSET 0
#define CONV2D_21_OUTPUT_DEC 4
#define CONV2D_21_OUTPUT_OFFSET 0
#define RE_LU_21_OUTPUT_DEC 4
#define RE_LU_21_OUTPUT_OFFSET 0
#define CONV2D_22_OUTPUT_DEC 4
#define CONV2D_22_OUTPUT_OFFSET 0
#define RE_LU_22_OUTPUT_DEC 4
#define RE_LU_22_OUTPUT_OFFSET 0
#define CONV2D_23_OUTPUT_DEC 2
#define CONV2D_23_OUTPUT_OFFSET 0
#define RE_LU_23_OUTPUT_DEC 2
#define RE_LU_23_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_5_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_5_OUTPUT_OFFSET 0
#define FLATTEN_5_OUTPUT_DEC 2
#define FLATTEN_5_OUTPUT_OFFSET 0
#define DROPOUT_5_OUTPUT_DEC 2
#define DROPOUT_5_OUTPUT_OFFSET 0
#define DENSE_5_OUTPUT_DEC 1
#define DENSE_5_OUTPUT_OFFSET 0
#define SOFTMAX_5_OUTPUT_DEC 7
#define SOFTMAX_5_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3, 1};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {9};
const nnom_qformat_param_t tensor_Placeholder_0_offset[] = {0};
const nnom_tensor_t tensor_Placeholder_0 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_Placeholder_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_Placeholder_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_Placeholder_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};

const nnom_io_config_t conv2d_20_input_config = {
    .super = {.name = "conv2d_20_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_20_kernel_0_data[] = TENSOR_CONV2D_20_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_20_kernel_0_dim[] = {6, 2, 1, 24};
const nnom_qformat_param_t tensor_conv2d_20_kernel_0_dec[] = TENSOR_CONV2D_20_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_20_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_20_kernel_0 = {
    .p_data = (void*)tensor_conv2d_20_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_20_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_20_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_20_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_20_bias_0_data[] = TENSOR_CONV2D_20_BIAS_0;

const nnom_shape_data_t tensor_conv2d_20_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_conv2d_20_bias_0_dec[] = TENSOR_CONV2D_20_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_20_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_20_bias_0 = {
    .p_data = (void*)tensor_conv2d_20_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_20_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_20_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_20_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_20_output_shift[] = CONV2D_20_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_20_bias_shift[] = CONV2D_20_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_20_config = {
    .super = {.name = "conv2d_20"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_20_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_20_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_20_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_20_bias_shift, 
    .filter_size = 24,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_21_kernel_0_data[] = TENSOR_CONV2D_21_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_21_kernel_0_dim[] = {4, 2, 24, 16};
const nnom_qformat_param_t tensor_conv2d_21_kernel_0_dec[] = TENSOR_CONV2D_21_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_21_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_21_kernel_0 = {
    .p_data = (void*)tensor_conv2d_21_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_21_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_21_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_21_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_21_bias_0_data[] = TENSOR_CONV2D_21_BIAS_0;

const nnom_shape_data_t tensor_conv2d_21_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_21_bias_0_dec[] = TENSOR_CONV2D_21_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_21_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_21_bias_0 = {
    .p_data = (void*)tensor_conv2d_21_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_21_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_21_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_21_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_21_output_shift[] = CONV2D_21_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_21_bias_shift[] = CONV2D_21_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_21_config = {
    .super = {.name = "conv2d_21"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_21_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_21_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_21_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_21_bias_shift, 
    .filter_size = 16,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_22_kernel_0_data[] = TENSOR_CONV2D_22_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_22_kernel_0_dim[] = {2, 1, 16, 12};
const nnom_qformat_param_t tensor_conv2d_22_kernel_0_dec[] = TENSOR_CONV2D_22_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_22_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_22_kernel_0 = {
    .p_data = (void*)tensor_conv2d_22_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_22_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_22_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_22_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_22_bias_0_data[] = TENSOR_CONV2D_22_BIAS_0;

const nnom_shape_data_t tensor_conv2d_22_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_22_bias_0_dec[] = TENSOR_CONV2D_22_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_22_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_22_bias_0 = {
    .p_data = (void*)tensor_conv2d_22_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_22_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_22_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_22_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_22_output_shift[] = CONV2D_22_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_22_bias_shift[] = CONV2D_22_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_22_config = {
    .super = {.name = "conv2d_22"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_22_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_22_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_22_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_22_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_23_kernel_0_data[] = TENSOR_CONV2D_23_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_23_kernel_0_dim[] = {2, 1, 12, 18};
const nnom_qformat_param_t tensor_conv2d_23_kernel_0_dec[] = TENSOR_CONV2D_23_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_23_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_23_kernel_0 = {
    .p_data = (void*)tensor_conv2d_23_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_23_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_23_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_23_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_23_bias_0_data[] = TENSOR_CONV2D_23_BIAS_0;

const nnom_shape_data_t tensor_conv2d_23_bias_0_dim[] = {18};
const nnom_qformat_param_t tensor_conv2d_23_bias_0_dec[] = TENSOR_CONV2D_23_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_23_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_23_bias_0 = {
    .p_data = (void*)tensor_conv2d_23_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_23_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_23_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_23_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_23_output_shift[] = CONV2D_23_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_23_bias_shift[] = CONV2D_23_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_23_config = {
    .super = {.name = "conv2d_23"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_23_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_23_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_23_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_23_bias_shift, 
    .filter_size = 18,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_5_config = {
    .super = {.name = "global_max_pooling2d_5"},
    .output_shift = 0,
};

const nnom_flatten_config_t flatten_5_config = {
    .super = {.name = "flatten_5"}
};
const int8_t tensor_dense_5_kernel_0_data[] = TENSOR_DENSE_5_KERNEL_0;

const nnom_shape_data_t tensor_dense_5_kernel_0_dim[] = {18, 6};
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
	nnom_layer_t* layer[14];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_20_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_20_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_21_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_22_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_23_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_5_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_5_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_5_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_5_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_15_NNOM_H