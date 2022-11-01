#ifndef MODEL_28_NNOM_H
#define MODEL_28_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_28_nnom
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
#define TENSOR_CONV2D_48_KERNEL_0 {-64, 2, 45, -2, 22, 12, -25, -16, -51, -16, 63, 42, -32, -33, -16, -57, -21, 46, 4, -4, 59, -31, -4, -25, -87, -7, 51, 15, -4, 6, -2, -3, 15, 5, -63, -4, 58, -65, 20, -15, -15, 24, -37, 18, 19, 8, -21, 28, 48, -77, 88, -22, 55, -12, 26, 18, 2, 41, -40, 16, 12, -44, 25, 59, -20, 1, -37, -46, 7, 6, 67, 20, -33, -67, -3, 12, 14, -8, -18, -17, 17, 7, -9, 41, 13, -34, 12, 33, 0, 1, 10, 22, -21, 55, -54, 28, 23, -21, -41, 17, 59, 7, 11, 9, 4, 12, 89, -8, 8, 11, -20, -25, -35, -18, 58, -18, 29, 8, -73, 60, 59, 29, 8, 32, 8, -50, -6, -24, -43, -37, -81, -91, -77, 5, 4, 26, 48, 38, 47, -1, -3, -11, 4, -10, -50, -30, -61, 3, -53, -14, -25, 0, -59, 21, -94, -25, -43, 4, -54, 2, -16, 0, -24, -3, -41, -38, -42, 78, 1, -55, 7, 64, -37, -77, 12, -21, 16, -1, -10, 7, 9, -51, -11, -42, 24, 42, 22, 61, 17, -59, 8, 33, 39, -15, 7, -42, -62, 34, 16, -33, 32, -33, -16, -10, -8, 68, -3, 30, 1, -61, 21, -37, 25, -14, -4, 75, 48, 6, 50, -26, 21, -34, -31, -59, -5, -28, -6, 1, -23, -26, 13, 81, 7, 59, -30, 34, 1, -76, 7, -107, -55, 4, -78, 22, -30, 14, 19, 2, 60, 19, 46, 17, 80, 48, -32, 62, 1, 32, 2, 37, 12, 31, -34, 22, -25, 15, 3, -47, 13, -23, -8, 7, -20, 51, 72, 92, 1, 36, 40, 6, -16, -3, -34, 23, 34, -70, -58, 66}

#define TENSOR_CONV2D_48_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_48_BIAS_0 {-71, -26, -13, 4, -52, -36, 1, 7, -12, -57, -33, -48, -18, -12, -35, -13, -28, -8, -17, -11, 0, -4, -37, -35}

#define TENSOR_CONV2D_48_BIAS_0_DEC_BITS {8}

#define CONV2D_48_BIAS_LSHIFT {7}

#define CONV2D_48_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_49_KERNEL_0 {-3, 7, 3, 7, -2, 0, 13, 14, -4, -1, -5, 9, -15, 4, 15, -2, -5, 1, 0, -1, 1, 20, -30, -1, 18, 1, -4, -4, 13, -3, 11, -4, 8, 14, -6, -5, 28, -2, 5, 25, 4, 10, -26, 4, -14, -14, 14, -9, -10, -19, 2, 0, -24, -32, -3, -4, 5, 4, 6, 8, -21, 1, -9, -9, 31, -9, -4, 8, -9, 16, 13, 8, -7, 8, -3, -5, 4, -7, -4, 2, -11, 0, -2, -2, 4, -2, -7, 27, -14, 7, -18, 8, -1, -8, 10, 25, -13, 10, 13, -7, 13, -3, 9, 10, 6, -22, 24, -6, -11, 4, -4, -9, 8, 4, 7, 11, 7, 6, 8, -12, -8, 0, 3, -11, 6, 19, -5, -4, 1, 6, 0, -18, 4, -9, -24, -11, 5, -16, 8, -9, 1, -11, 18, -14, 19, -5, 23, -3, 4, -16, 1, 25, 11, -10, 29, 6, 11, 5, 8, -7, 12, 5, 0, 11, 3, 8, 31, 12, -4, 5, -11, 0, -14, 4, -16, 2, 12, 22, 14, -8, -4, 2, 11, -2, 14, 5, 6, -19, 5, -15, 0, 12, 3, -18, 11, 2, 15, 13, -1, 1, 19, 3, -17, -6, -10, 8, 43, -29, 26, -42, 0, -3, -30, -3, 9, 11, 30, 0, 4, -26, -19, -16, 7, -2, -8, 10, 2, -20, 3, -1, -5, 5, -9, 30, -32, 27, 4, -22, 19, 1, 12, -20, 12, -1, 18, 11, -10, 4, 6, -11, -11, 3, -2, -2, 6, -15, -18, -5, 10, -3, 6, 1, -8, 1, 12, 14, 1, -2, 10, 16, 11, 4, -8, 28, -4, -16, 7, -13, 28, 16, -7, 3, -6, 24, -14, -1, 32, 9, 20, -6, -2, 1, -12, -1, -15, -25, 15, 3, -6, -24, 4, -21, 20, -4, 15, -10, -3, 18, -15, 7, 5, 10, 27, -17, 3, 7, -12, 15, -1, 13, -17, 8, -15, -8, 9, 10, 1, -1, -13, 16, -3, 11, 6, 17, 16, 14, 10, -5, 18, 5, -28, 24, -3, -12, -2, 10, 7, -10, 5, -1, 14, 2, -5, -10, -2, 4, -4, -1, -1, 6, 6, 24, -3, -9, -35, 35, -1, 4, -9, 0, -6, -19, 19, 13, 33, 5, 2, 25, 6, 34, 5, 4, -8, 24, 11, 44, 8, -7, 20, 2, 3, -8, -20, -15, -3, 11, 1, 0, 22, 4, -15, 10, 6, -13, 13, -9, 1, -8, 28, -5, -6, 4, 26, 20, -23, -17, -12, 26, -31, -30, -39, -33, 30, 17, 18, 3, 2, 7, -21, -1, -8, 0, 24, 16, 16, 7, 11, 12, -12, 14, -6, -6, -25, 19, 15, 7, 10, -9, -3, 13, -8, -1, -4, -18, 21, 43, -13, -2, -17, 5, 0, 6, 2, -19, -4, 1, -15, 3, -16, -5, 28, 12, 4, 13, -23, -5, -19, -7, -1, 2, 13, 8, -7, 15, 14, -5, -3, -4, 7, 32, 28, -9, -17, -2, 1, -2, 10, -20, 17, -15, 11, -7, 9, 18, 17, -2, -11, -22, 5, 13, 4, -1, -8, -35, 4, -3, -9, -25, 6, -5, 8, -11, 3, 15, 5, -12, 3, 7, 10, 6, 6, 6, -3, 11, 2, 10, -1, 31, 18, 17, 1, 1, -2, 7, 8, -18, 32, -23, -22, -13, -5, 4, 32, -2, -9, -14, -7, 1, -1, -2, -11, 4, 7, 9, -2, -7, -16, -2, 8, -1, 12, -29, 1, -19, -26, 12, -6, -16, 25, 8, -17, 16, 1, 0, 1, 13, -44, 4, -14, -15, -1, 0, 5, 5, -4, -8, -14, 24, -19, -19, 5, 2, 1, 12, -9, -7, 14, -3, -2, 13, 6, 1, 20, 0, 7, 40, -14, 61, 17, 26, 7, 1, -15, -10, -32, -11, 0, 8, -20, 8, -9, -19, 6, -33, -15, 3, -8, -11, -4, 8, 5, 7, -8, 0, 11, 21, -11, 0, 12, 6, 14, 4, 4, 9, 9, -3, -4, -17, -18, -2, 2, -8, 34, 7, 10, -4, 12, 22, -8, -11, -12, 32, -54, -2, -17, 8, 8, 25, 2, -5, -9, -24, -18, -3, -20, -15, -4, 0, 3, 6, -10, -4, -2, 2, -26, -23, -1, 0, -10, 8, -9, -4, -5, -13, -16, -14, -8, -4, 2, -14, -2, 23, 4, 12, -21, 1, 6, 5, -6, -5, -39, -12, 7, -1, -6, 10, -7, 17, -6, -32, -8, 2, -4, -20, -27, -12, 9, -14, -24, -9, -5, 1, -27, 15, -23, -4, 4, 30, -9, -2, 7, 5, 7, -17, -40, -9, -7, -8, 10, 0, -6, 24, 5, 8, 1, 0, -20, -1, -11, 9, -23, -3, -5, -12, -9, -4, -17, 3, -8, -5, 12, -6, -1, 9, 7, 0, -2, 22, 4, 0, 7, 19, -13, -17, 5, 4, 15, -28, -7, 2, -10, -2, -15, 23, -24, 6, -26, -33, -9, 6, 10, -21, -2, 28, -3, 24, -28, 4, -12, -6, 1, -6, 8, -8, 3, 9, 12, -7, 4, -6, -20, 24, -3, -4, 10, 3, 0, -7, -28, -4, 6, -9, 1, 12, 25, -6, -13, 4, 12, 22, -1, 16, -9, -2, -18, -11, 5, 14, 8, 14, 2, 17, 3, 13, 18, -2, -8, -6, 8, -4, -18, 11, 12, -7, 14, -8, 4, 2, 12, -17, -5, 3, 7, -2, -9, -1, -5, 6, 6, -6, -6, 12, 9, 3, -13, 9, 15, -1, 7, -3, 7, 7, -11, -1, 4, -30, -8, 18, -8, 17, 5, 2, 3, 6, 0, 5, 19, 9, -1, -4, 20, -2, 14, 7, 11, -5, 28, 16, -9, 0, -1, 0, 2, 2, -12, 10, 9, -6, 0, 19, 36, -12, 2, 7, -6, -8, 32, -41, 30, 4, -5, 3, 12, -18, -8, -17, -6, 24, 6, 0, -11, 21, 9, 15, -20, 11, 7, 4, 6, -34, -5, 25, 3, 18, 9, 6, 1, 16, 17, 0, 12, -3, -11, 2, 14, -6, 7, -6, -13, 4, 2, -9, 5, -7, -4, 0, 13, 20, 6, 6, 5, -11, -8, 14, -7, -3, 10, -9, 53, -6, 7, 8, 2, -4, 11, 9, -5, -1, -12, -3, -6, 8, 21, 13, -21, 0, -17, 0, -12, 15, 13, 31, 20, 15, -1, -9, -5, 4, 12, -1, -4, 3, -2, -29, 1, -15, 10, 15, -8, 7, -17, -2, 2, -4, -3, 5, -36, 17, 7, 5, -6, -23, -11, -14, -9, -8, -5, 17, 3, -23, -18, 9, 6, -7, 8, 13, -7, 27, -20, -19, -92, -4, -3, 20, -16, 11, -16, 1, 1, -35, -15, -4, 2, 0, 15, -7, 0, -8, 16, -5, 4, -3, -29, 2, 7, 1, -11, -13, -19, -5, 25, 4, -20, 11, -40, -28, -17, 17, 6, 2, 12, 11, -6, -31, -15, 4, -7, -12, 18, -3, 0, -11, -36, 6, 0, -31, -8, 12, -34, 5, -41, -5, -14, 13, 4, 3, 6, 16, 8, -19, -7, -40, -27, -24, -4, -28, 31, 6, -20, -3, -5, -21, 14, 13, -14, -11, -12, 3, -19, 12, 24, 13, 13, -6, -6, 15, -28, -1, -23, 11, -13, 8, 2, -3, 3, -29, -25, -18, -31, -16, -9, 18, 1, -26, 2, 20, 1, -27, -2, -10, -39, 11, -17, 1, 23, -15, -14, 19, 29, 6, 4, -13, -19, -12, -19, -28, 11, 3, 7, -11, 16, 10, 2, -27, -59, 0, -18, 15, -7, 10, -7, -11, -3, -38, 7, -2, 0, -18, -6, 0, 14, -10, 11, 2, -6, 13, -32, -24, 19, 6, 8, 13, -17, -19, -4, 2, -7, -18, -10, 6, -4, -12, 5, -29, 6, 5, -4, -8, -39, 15, 16, -17, -102, 8, -25, 8, -7, -11, 11, 3, -15, -17, 23, -28, 16, 9, 7, 29, 13, 8, 18, 15, 1, -13, 5, -13, -2, 6, -6, 11, -10, 0, -7, -11, -4, 30, -17, -15, 20, -13, 11, 2, -27, 15, -10, 3, -41, 12, -26, -3, -10, -15, 9, -8, 18, -11, 24, 15, -2, -23, 24, 3, 5, 18, -10, 6, -9, -8, 12, 3, 0, 11, 1, -31, -23, 17, 35, -37, -37, -14, 10, 4, -2, 20, -16, 18, -30, -5, -16, -1, -13, -8, 16, -4, -9, 2, 4, 3, -42, 16, 0, 3, -45, 30, -12, -12, -6, -7, -13, -22, -19, -9, 19, 44, -2, 27, -13, -8, 8, -7, -37, 28, -45, 10, 15, 3, -18, 10, 10, 3, 6, -26, 2, 5, -5, 6, 25, -4, 6, -9, -2, -9, 10, -28, 1, -29, -26, 9, 7, -19, -20, -15, -12, -4, -11, 10, -27, 9, -9, -25, 25, 5, -4, 15, -17, 14, 8, -26, -10, 1, -38, 21, 23, 14, -25, 9, 2, 7, -12, -64, 19, -5, -11, -8, -24, 5, -15, -33, 25, 5, -16, 15, 0, -2, 21, -14, 8, 2, 8, 19, -3, 7, 3, -1, -1, -12, 4, -7, -7, -3, -14, 19, -25, 10, 2, -16, -6, 3, -43, 11, 19, 12, -1, 18, -8, -6, -5, -21, -8, 35, -54, 2, -15, 10, 5, 10, 3, 5, -2, -1, -29, 34, -5, -33, 6, 10, -7, 6, 6, 0, -22, -1, -13, 6, 3, 13, -4, 7, -43, 15, -10, 10, -6, -16, 27, 22, -9, -1, 8, 1, -23, -4, -13, -7, 0, 4, -11, -3, -2, -45, -7, 5, 16, -17, -8, 2, 3, 6, 0, -19, 22, -5, 8, 3, -11, -18, 3, -6, -30, 8, -12, -2, -13, -3, 13, -8, -7, 11, 0, 17, -3, -20, -23, -7, -26, -12, 0, -2, -5, -9, -6, -11, -7, 2, -10, 0, 1, 0, 15, -2, -8, 3, 12, -1, 2, -3, -19, -4, 14, -7, 7, 11, -11, -11, -12, 8, -2, -6, -16, 14, 12, -12, -3, 7, 2, 8, -1, 2, -1, -11, 25, 10, 5, -9, 18, 11, -8, 5, 3, -9, 8, -2, -7, 26, -13, 7, 6, -20, 18, 6, -10, 10, -13, 0, 6, 10, -8, -5, 24, 11, -23, -5, -3, 9, 5, -74, -10, 12, 26, 11, 27, -6, 3, 12, 4, 16, -2, -2, 4, 23, -29, -3, 6, -13, 4, -6, 6, 6, -12, 6, -1, -3, 9, -4, -23, -24, 2, 10, -22, 5, 11, 10, -10, 34, -33, 0, 11, -10, -47, -5, 7, 1, 19, 14, -24, -10, 13, 16, 12, -8, 7, 17, 6, 36, -3, 8, -16, 4, 11, 0, 4, -17, -66, 19, -1, -3, 8, -29, -16, 7, -6, 7, 22, -6, 17, 10, -31, -5, -6, 3, -14, -7, 42, 3, -1, 2, -21, 10, 16, -1, -9, 7, -13, -4, -30, 4, 5, -2, 18, -35, -26, -2, -36, -5, 9, 8, 60, 12, -5, 8, 4, 7, -21, -12, -3, 11, -10, 19, -24, 14, 45, 3, -10, -3, -24, 4, -28, -8, 19, 49, -5, 18, 7, -13, -3, 9, 0, -7, 1, 6, -23, -15, 0, 12, 3, 26, 3, -19, -12, -7, 5, 0, -26, 15, 3, 8, -19, 9, -34, -5, 3, -12, -1, -9, -18, -6, -2, 20, 15, 17, 5, -16, 1, 1, -18, 9, -49, 5, 12, -11, 21, -8, -54, 16, 15, 6, 8, -21, 6, 3, 1, 4, 23, -1, -7, 8, -23, -31, -26, -8, 1, 7, 26, -8, 4, 3, -5, 13, 11, 20, -12, 14, 3, -18, 0, 19, 16, 6, -3, 12, -10, -23, -11, 10, 5, 1, 17, -14, -9, -13, -28, 7, -19, -25, 15, -50, -4, -12, -21, -5, -8, 2, -10, -26, -11, 14, -33, -33, 15, -10, -3, 11, -39, 16, 18, -6, 0, -11, -8, -24, -27, 3, -21, 9, 2, 20, 7, 3, -3, 4, -18, -10, -13, -21, 5, -13, 4, -9, -55, 2, 2, -6, 10, 1, -50, 16, -7, 21, -21, 12, -1, -1, 0, -29, -13, 17, -23, 2, 14, 9, -1, -2, -22, 4, 8, 7, -9, -13, -16, -5, -11, 15, -8, -2, -6, 11, -16, -12, -3, -7, -5, 9, 2, 21, 2, -10, -10, -1, 9, -17, 21, -3, -21, 6, -34, -3, -1, 20, 7, -8, -12, -1, -4, -2, 11, -8, 39, 6, -5, 10, -14, -22, -11, 6, 6, -9, 5, -18, -15, -2, 14, -5, -17, 10, -2, -2, -3, 4, -12, -1, 12, 7, 4, -14, 0, -4, 20, -2, 3, -28, 4, -19, -3, -25, -5, 6, 8, -11, 2, -8, 10, 12, 0, 3, 45, -3, -23, 14, -38, -2, 1, -19, 13, -14, 13, -1, -6, -35, -8, 7, -16, -19, -9, 21, -15, 0, -56, -9, 4, 3, 16, 16, -20, -45, 21, 19, -24, 0, 16, -6, 28, 2, -14, -8, 9, -15, 11, -21, -4, 11, -8, 7, 36, -11, -1, 19, -5, -21, -37, 23, 1, 7, -1, -3, 10, -11, 4, 3, -24, -7, 17, 8, -1, -14, 1, -8, 7, -57, 11, 3, -10, 2, -1, 5, -6, -42, -22, -1, 6, 3, -10, -26, 2, -12, -12, -5, -7, -7, 17, 17, -11, -6, -14, 9, 41, -27, 1, -1, -15, -8, 17, 9, -2, 12, -25, -4, -31, -2, 5, 6, 4, -27, 12, -17, -25, -38, 1, 0, 6, -53, 0, 4, 17, 26, 6, -50, 16, 15, -14, -8, 7, -2, -2, 30, 10, 10, -4, 23, 2, 9, -6, -12, 8, -15, 8, -18, -13, -1, 4, 20, -15, 9, 3, -46, -20, 5, 8, -7, -3, -38, -14, 14, 18, -10, -41, -13, -20, -9, 5, -8, -4, -11, 6, -37, -4, 4, -23, -3, 3, 11, 2, 28, -2, -1, 30, 6, 23, 9, 1, -27, 9, -31, 4, -27, -36, -20, 13, 11, -30, -3, -25, 15, -2, 0, 4, -7, 4, -19, 0, 14, 48, 2, -51, 4, 21, 0, 1, -16, 2, -78, 21, 23, -40, -58, 2, -11, -6, 18, -1, 10, 6, 5, -11, 10, -9, -3, -2, -10, -6, 10, 3, 5, -6, 3, 10, -1, 4, 11, 12, -8, 0, 12, 9, -9, -36, 2, -4, -14, 2, 1, 4, 6, 14, 23, -19, 5, 15, -7, 7, -18, -2, -16, 27, 44, 22, 30, 4, 5, 22, 5, -8, 10, 18, 32, -5, -40, 38, 16, -5, -1, -16, -4, -22, -24, -11, -1, 18, -27, 10, 1, -3, 1, -15, 11, -14, 12, 19, 21, -50, -14, 18, 7, 20, -37, -1, -16, -38, -20, 12, -24, 11, 2, 1, -21, 2, -3, 5, 9, 15, -6, 6, -5, -18, -7, 10, 19, -8, -18, -29, 11, -21, 27, -8, -13, -11, 20, -37, -8, 2, -20, -18, -2, 8, 12, 29, 22, 4, -19, 4, -3, -16, -25, 3, -37, -37, 1, -14, -41, 24, 8, 22, -8, 3, -13, 13, -2, 18, 17, -19, 5, 23, -7, 10, -11, 4, -10, 12, 21, -14, 40, -3, 1, 14, 2, -35, 22, -15, 3, -11, -14, 14, -14, 15, 1, 11, -53, -8, 6, 3, 3, 17, 19, 14, 11, 9, 6, -13, -5, 2, -3, -67, 11, 13, -9, 4, 19, 7, 10, 9, 4, 17, 16, 3, 6, 8, 17, 10, 21, 19, 1, 6, 3, 4, 12, 1, -7, 17, -5, 17, 13, 15, 0, 8, -2, 16, 5, 11, -16, -10, 2, 25, 15, -10, 5, -1, -15, 9, 2, 4, 24, 4, 10, 17, -10, 25, 15, 4, 12, 19, 12, -3, -8, -1, 10, 3, 11, 3, 3, 9, 26, 17, 3, -8, -10, 8, -2, 10, 18, 0, 6, -12, -4, 37, 2, 2, -8, -1, -1, 1, 8, 4, -1, -6, -3, 4, -12, -4, 16, 4, -7, -4, 15, 5, 20, 9, 9, 14, 11, -5, 2, -4, 15, 0, -3, 7, -8, 15, 7, 25, -1, 3, -12, 4, -6, -5, 10, 22, 3, 1, 5, 14, 0, 2, -8, -10, 16, 9, 3, 8, 2, 12, 0, 1, -10, -12, 16, -6, 10, 8, -4, 14, 14, -11, 13, 29, 10, 6, 14, 1, 35, -3, 10, -6, 0, 26, 17, 15, 1, 2, -2, 6, -9, 16, 12, 20, 11, 4, -2, 33, 6, 11, 4, -8, 12, 9, -2, -1, 7, 10, 7, 4, 5, 0, 0, -9, 0, 9, 0, -17, -22, 6, -28, 2, 8, 11, -14, -7, 2, -15, 6, 25, 0, -15, -14, 7, -11, 19, -30, -9, -2, -17, -7, -12, 17, -26, 3, -5, 2, -19, -26, -8, -21, 5, 13, 1, 2, -23, 4, -3, 27, -1, 4, 14, 12, 9, -5, 6, 2, -30, -18, -34, -29, 15, 5, -13, 4, 2, -37, 10, 15, 4, -21, 25, -5, -20, -13, 5, 12, -10, 17, -38, 19, -10, -3, -10, 3, -15, -13, 13, 14, -8, -14, -4, -18, -6, 18, 0, -16, -2, -1, 11, -8, -10, 41, -16, 1, -7, 19, -30, -15, 8, 10, 5, -5, -8, -44, 9, 15, 3, -1, 12, -16, 1, 11, 4, 1, 10, 6, -6, 6, 2, -4, 10, 3, -12, 2, -4, 28, 11, -16, -2, -9, 7, 6, -8, 33, -8, 34, 17, -35, 22, -14, -20, 10, 2, 20, -21, 17, 1, 17, 13, -7, -22, 12, 9, 9, -8, -3, 21, 10, -12, 13, -22, -4, 28, -9, -3, 12, -5, 0, -1, -10, -6, 3, -25, -19, 19, 6, 4, 3, -4, -1, -21, 1, 12, 24, 17, 6, 5, -27, 25, 12, -2, -14, -4, 11, -14, -19, -16, -8, 15, 10, 11, 15, 13, 4, 11, 14, -9, 8, -17, 5, -9, 22, -14, 4, -1, 9, 29, 11, 2, 1, -29, 13, 10, 13, -3, 4, 17, -11, 21, -14, 2, -9, -13, -2, -22, -7, 31, 9, -18, 4, 6, -1, -17, -16, -14, 7, 0, -5, -16, 4, -5, 27, 8, 3, -4, 9, -7, -19, 30, 2, -20, 11, 7, -5, 22, 13, -3, -5, -9, 12, 6, 6, 3, 2, 12, 10, 12, 12, -6, -9, 13, -15, -22, 3, 9, 0, -9, -1, -1, -8, -13, 1, 3, 25, 15, -6, 10, -10, -1, -10, 16, 0, 5, 9, 0, -6, 17, -1, -16, -8, 12, 10, 28, 3, 1, 12, -17, 11, 17, 6, -8, -6, 10, -26, 3, -17, 2, 16, 11, -11, -17, -1, 22, -1, -11, -4, 20, 0, -3, 0, -12, 28, 14, -14, 1, 1, 4, -12, 2, 12, 0, 12, 2, -15, 16, 19, 7, 1, 1, -3, 30, 9, -15, 5, -12, 37, 29, 1, -24, -26, -7, 12, -1, 7, 8, 3, 0, -16, 4, -16}

#define TENSOR_CONV2D_49_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_49_BIAS_0 {-15, -1, -36, 1, -36, -3, 9, 6, -3, 1, 16, 10, -43, -82, 9, -91}

#define TENSOR_CONV2D_49_BIAS_0_DEC_BITS {7}

#define CONV2D_49_BIAS_LSHIFT {5}

#define CONV2D_49_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_50_KERNEL_0 {-3, 21, 4, 18, -16, 7, 17, -16, 3, -26, -2, 40, -5, 3, -17, -10, 11, 2, -27, 11, 10, -9, 6, -11, 22, -39, 9, 26, -38, -15, -12, -3, 14, 15, -46, 18, -9, -7, -11, 25, 1, -1, -20, -12, -20, -9, 34, -8, -2, 14, -35, 15, 0, 22, 11, 1, 8, -17, -8, -10, -23, -3, 5, -6, 22, 0, -7, 18, 0, 19, -10, 13, 1, -31, 10, 4, -15, -37, 22, -43, -1, 5, -38, -4, -5, 11, 15, 21, 17, 27, -5, -23, -36, -5, 4, 11, -22, -38, 10, -13, 3, -24, 29, 21, 10, 25, 13, 24, 2, -34, -2, -16, -17, -12, 15, 25, -40, -5, 3, 22, 1, 10, 22, -6, 13, -22, -1, -12, 3, 12, 9, 13, 6, 11, 11, 9, 3, -33, 3, 8, 1, 4, 2, -30, 3, -4, -1, 5, -8, 12, -29, -33, 15, -46, -19, 25, 35, -3, -23, -10, 26, 10, 6, 21, -35, 21, 0, -21, -8, 7, -3, 6, -7, 3, 22, 1, 22, 9, -43, -14, 0, -26, 3, 10, 32, 8, 14, -10, -21, -20, -5, 10, 9, 12, 23, 2, -4, -16, -1, 0, 1, 12, 4, -1, 20, -5, 15, -21, 13, 2, -40, -16, 6, 14, -7, -1, 14, 1, 10, 0, -24, -5, 3, 25, 0, 3, -26, 22, -18, -24, -19, 15, 13, 3, -2, 3, -37, -20, -1, -6, -10, 8, 23, 5, -19, 15, -79, -7, 8, -41, -23, 24, 18, -55, -61, -61, -3, 28, -9, -2, -3, 15, -19, -28, -3, 43, 16, -6, -21, 2, -12, 13, -6, 6, 2, 11, -20, 7, 0, -3, 16, 38, -4, -5, -29, 2, -10, 22, 10, -7, 6, -1, 4, 11, 4, 7, -12, 23, 5, -10, 15, 11, 20, 29, -9, 15, 10, 26, 18, -2, 4, -6, -4, -14, 0, 13, -6, 13, -7, 16, 3, -9, -13, 9, 8, 12, 8, -5, 17, 39, -20, 20, 9, 21, 4, -22, -12, -34, 6, 15, -13, 13, -1, -5, 4, -2, -10, 14, 19, 8, -5, -21, 3, 4, 16, 2, -1, 8, 4, 11, 0, 34, -15, -9, 9, 0, -5, 9, 9, 6, 18, -9, 9, -9, 0, 10, 5, -11, 29, -33, 5, 9, 6, 16}

#define TENSOR_CONV2D_50_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_50_BIAS_0 {61, 33, -4, 64, 42, 58, 4, 76, 25, -14, 13, -115}

#define TENSOR_CONV2D_50_BIAS_0_DEC_BITS {8}

#define CONV2D_50_BIAS_LSHIFT {1}

#define CONV2D_50_OUTPUT_RSHIFT {6}

#define TENSOR_CONV2D_51_KERNEL_0 {-35, 13, 3, 23, 12, 7, -12, 53, -89, 6, 21, -102, 2, 2, -20, -90, 16, -11, 24, 39, -12, -45, -25, -110, -60, -73, 22, 24, 68, -82, -36, 37, -71, -37, 4, 5, -69, -33, 22, -5, 28, 22, 16, -50, -63, 4, -44, 3, -30, -30, 2, -52, 12, -53, 11, -20, 20, -12, 3, 7, 4, -13, -2, -97, -3, 10, -17, 10, -7, 9, -6, 28, 42, 30, 23, -44, -32, -5, -45, 32, 4, -33, 16, -58, -25, -35, 18, 39, -42, 11, 13, 58, -105, -88, -67, 18, 9, -26, 17, 38, -2, -103, -36, 45, -104, -41, 37, 61, -3, -34, 16, 30, -3, -58, 2, -12, -39, -63, 14, -25, -101, -28, -59, 21, -79, -5, -3, 57, 24, 13, 7, 17, 20, -5, 1, 13, -37, 10, 8, -71, -14, -16, -104, 0, -112, -13, -56, 23, -25, -22, 4, 42, 32, 19, 4, 14, 16, -18, 11, 9, -35, 8, 18, -75, -17, -29, -105, 4, -28, -5, -31, 36, -102, -6, -12, -42, -88, 7, -22, -6, 26, 15, -9, -12, 41, -10, 13, 74, -22, 0, -9, -28, 24, -17, -49, 27, 24, 11, -21, -44, 10, -6, -3, -9, -8, -66, -71, 13, 42, -82, -52, 60, -39, -46, 23, 16, 23, -78, -62, 27, 11, -7, -25, -4, 22, 9, 20, 39, 24, -48, -94, 0, 7, -41, -10, 69, -16, -31, -17, 3, -46, -3, 11, 24, 1, 8, -14, 25, -82, 5, 24, -82, 13, 22, -23, -76, 10, -14, 8, 48, -3, -46, -18, -57, 2, -16, 30, -38, -31, 11, -15, 19, 3, 11, -8, -16, -54, -61, -12, 39, -16, -95, -10, 44, 21, -47, -49, -3}

#define TENSOR_CONV2D_51_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_51_BIAS_0 {-12, 37, -119, -32, -10, -32, -17, -24, -34, -86, 0, 108}

#define TENSOR_CONV2D_51_BIAS_0_DEC_BITS {8}

#define CONV2D_51_BIAS_LSHIFT {1}

#define CONV2D_51_OUTPUT_RSHIFT {7}

#define TENSOR_DENSE_12_KERNEL_0 {-38, -41, 14, 10, 7, 7, -24, -59, -9, 21, -34, -38, 16, -4, 10, 7, -46, -10, 11, 5, 20, 23, 4, -26, 7, 1, -32, 5, -1, -32, 11, 12, -19, 19, -35, -36, 6, 16, 11, 12, 9, 5, 15, -31, -12, 3, 14, -12, -74, -90, -47, -90, -86, -47, -43, -56, -66, -54, -73, -116, 11, -31, -29, 12, -17, -45, -39, 16, -26, -35, 16, -30}

#define TENSOR_DENSE_12_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_12_BIAS_0 {-19, 6, -41, -19, 83, 4}

#define TENSOR_DENSE_12_BIAS_0_DEC_BITS {5}

#define DENSE_12_BIAS_LSHIFT {2}

#define DENSE_12_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define CONV2D_48_INPUT_OUTPUT_DEC 9
#define CONV2D_48_INPUT_OUTPUT_OFFSET 0
#define CONV2D_48_OUTPUT_DEC 7
#define CONV2D_48_OUTPUT_OFFSET 0
#define RE_LU_48_OUTPUT_DEC 7
#define RE_LU_48_OUTPUT_OFFSET 0
#define CONV2D_49_OUTPUT_DEC 4
#define CONV2D_49_OUTPUT_OFFSET 0
#define RE_LU_49_OUTPUT_DEC 4
#define RE_LU_49_OUTPUT_OFFSET 0
#define CONV2D_50_OUTPUT_DEC 3
#define CONV2D_50_OUTPUT_OFFSET 0
#define RE_LU_50_OUTPUT_DEC 3
#define RE_LU_50_OUTPUT_OFFSET 0
#define CONV2D_51_OUTPUT_DEC 2
#define CONV2D_51_OUTPUT_OFFSET 0
#define RE_LU_51_OUTPUT_DEC 2
#define RE_LU_51_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_12_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_12_OUTPUT_OFFSET 0
#define FLATTEN_12_OUTPUT_DEC 2
#define FLATTEN_12_OUTPUT_OFFSET 0
#define DROPOUT_12_OUTPUT_DEC 2
#define DROPOUT_12_OUTPUT_OFFSET 0
#define DENSE_12_OUTPUT_DEC 1
#define DENSE_12_OUTPUT_OFFSET 0
#define SOFTMAX_12_OUTPUT_DEC 7
#define SOFTMAX_12_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_48_input_config = {
    .super = {.name = "conv2d_48_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_48_kernel_0_data[] = TENSOR_CONV2D_48_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_48_kernel_0_dim[] = {6, 2, 1, 24};
const nnom_qformat_param_t tensor_conv2d_48_kernel_0_dec[] = TENSOR_CONV2D_48_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_48_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_48_kernel_0 = {
    .p_data = (void*)tensor_conv2d_48_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_48_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_48_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_48_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_48_bias_0_data[] = TENSOR_CONV2D_48_BIAS_0;

const nnom_shape_data_t tensor_conv2d_48_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_conv2d_48_bias_0_dec[] = TENSOR_CONV2D_48_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_48_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_48_bias_0 = {
    .p_data = (void*)tensor_conv2d_48_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_48_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_48_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_48_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_48_output_shift[] = CONV2D_48_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_48_bias_shift[] = CONV2D_48_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_48_config = {
    .super = {.name = "conv2d_48"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_48_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_48_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_48_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_48_bias_shift, 
    .filter_size = 24,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_49_kernel_0_data[] = TENSOR_CONV2D_49_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_49_kernel_0_dim[] = {4, 2, 24, 16};
const nnom_qformat_param_t tensor_conv2d_49_kernel_0_dec[] = TENSOR_CONV2D_49_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_49_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_49_kernel_0 = {
    .p_data = (void*)tensor_conv2d_49_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_49_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_49_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_49_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_49_bias_0_data[] = TENSOR_CONV2D_49_BIAS_0;

const nnom_shape_data_t tensor_conv2d_49_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_49_bias_0_dec[] = TENSOR_CONV2D_49_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_49_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_49_bias_0 = {
    .p_data = (void*)tensor_conv2d_49_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_49_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_49_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_49_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_49_output_shift[] = CONV2D_49_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_49_bias_shift[] = CONV2D_49_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_49_config = {
    .super = {.name = "conv2d_49"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_49_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_49_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_49_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_49_bias_shift, 
    .filter_size = 16,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_50_kernel_0_data[] = TENSOR_CONV2D_50_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_50_kernel_0_dim[] = {2, 1, 16, 12};
const nnom_qformat_param_t tensor_conv2d_50_kernel_0_dec[] = TENSOR_CONV2D_50_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_50_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_50_kernel_0 = {
    .p_data = (void*)tensor_conv2d_50_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_50_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_50_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_50_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_50_bias_0_data[] = TENSOR_CONV2D_50_BIAS_0;

const nnom_shape_data_t tensor_conv2d_50_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_50_bias_0_dec[] = TENSOR_CONV2D_50_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_50_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_50_bias_0 = {
    .p_data = (void*)tensor_conv2d_50_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_50_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_50_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_50_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_50_output_shift[] = CONV2D_50_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_50_bias_shift[] = CONV2D_50_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_50_config = {
    .super = {.name = "conv2d_50"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_50_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_50_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_50_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_50_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_51_kernel_0_data[] = TENSOR_CONV2D_51_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_51_kernel_0_dim[] = {2, 1, 12, 12};
const nnom_qformat_param_t tensor_conv2d_51_kernel_0_dec[] = TENSOR_CONV2D_51_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_51_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_51_kernel_0 = {
    .p_data = (void*)tensor_conv2d_51_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_51_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_51_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_51_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_51_bias_0_data[] = TENSOR_CONV2D_51_BIAS_0;

const nnom_shape_data_t tensor_conv2d_51_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_51_bias_0_dec[] = TENSOR_CONV2D_51_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_51_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_51_bias_0 = {
    .p_data = (void*)tensor_conv2d_51_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_51_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_51_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_51_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_51_output_shift[] = CONV2D_51_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_51_bias_shift[] = CONV2D_51_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_51_config = {
    .super = {.name = "conv2d_51"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_51_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_51_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_51_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_51_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_12_config = {
    .super = {.name = "global_max_pooling2d_12"},
    .output_shift = 0,
};

const nnom_flatten_config_t flatten_12_config = {
    .super = {.name = "flatten_12"}
};
const int8_t tensor_dense_12_kernel_0_data[] = TENSOR_DENSE_12_KERNEL_0;

const nnom_shape_data_t tensor_dense_12_kernel_0_dim[] = {12, 6};
const nnom_qformat_param_t tensor_dense_12_kernel_0_dec[] = TENSOR_DENSE_12_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_12_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_12_kernel_0 = {
    .p_data = (void*)tensor_dense_12_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_12_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_12_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_12_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_12_bias_0_data[] = TENSOR_DENSE_12_BIAS_0;

const nnom_shape_data_t tensor_dense_12_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_12_bias_0_dec[] = TENSOR_DENSE_12_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_12_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_12_bias_0 = {
    .p_data = (void*)tensor_dense_12_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_12_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_12_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_12_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_12_output_shift[] = DENSE_12_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_12_bias_shift[] = DENSE_12_BIAS_LSHIFT;
const nnom_dense_config_t dense_12_config = {
    .super = {.name = "dense_12"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_12_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_12_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_12_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_12_bias_shift
};

const nnom_softmax_config_t softmax_12_config = {
    .super = {.name = "softmax_12"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_12_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_48_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_48_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_49_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_50_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_51_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_12_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_12_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_12_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_12_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_28_NNOM_H