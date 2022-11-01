#ifndef MODEL_48_NNOM_H
#define MODEL_48_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_48_nnom
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
#define TENSOR_CONV2D_16_KERNEL_0 {56, 33, 36, 18, 49, 9, 45, 29, 26, 11, 24, 12, 4, -91, 9, -35, 16, 20, 19, 82, -10, -2, -1, -82, 63, -9, 60, 3, 30, 36, -53, 47, -63, 16, -43, -13, 10, 21, 31, 9, -9, -66, -31, 48, -14, 9, 39, 56, 65, 17, 35, 12, 19, -33, 2, -4, 29, 30, 37, 48, -14, -34, -41, 13, -12, 31, 3, -34, 11, 47, 87, -50, -54, 68, 78, -23, -9, 6, 24, -9, 7, -20, 48, -9, -28, 20, 25, -6, 0, 14, 25, -6, 36, -40, 31, -54, 74, -14, -7, -2, -36, -17, 15, 8, 63, 14, 26, 21, -24, 87, -2, 45, 57, -1, 31, -12, 0, 5, -7, 51, -16, 45, -53, -12, -4, -57, 7, 11, -13, -67, 45, -37, -75, 16, -46, -45, 30, 1, 50, 13, 49, 14, 46, 57, 63, 15, -17, -21, -18, -24, 45, 25, -3, -64, -60, -18, -5, 62, -13, 38, -18, -42, -5, 23, -30, 23, -82, -10, 23, 21, -26, 42, 22, 56, 10, 47, -23, 47, 61, 40, 66, 13, 32, -2, -5, -1, -29, 43, 6, -21, 56, -72}

#define TENSOR_CONV2D_16_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_16_BIAS_0 {-3, -24, -36, -29, -5, -37, -23, 4, -71, 5, -25, -36, -29, -4, 0, -6}

#define TENSOR_CONV2D_16_BIAS_0_DEC_BITS {8}

#define CONV2D_16_BIAS_LSHIFT {7}

#define CONV2D_16_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_17_KERNEL_0 {-6, 7, -11, -9, -8, 2, 0, 1, -1, -8, -5, 2, 1, -10, 8, -6, -13, -2, -6, -5, -6, 3, -4, -3, 3, -7, -9, -7, -1, -7, -13, 3, -13, -13, -2, -4, -7, -9, -5, -6, -5, 1, -2, -9, 6, -12, -7, 7, -2, -5, -6, 0, -9, -8, -11, 4, -7, -3, -3, 9, -12, 0, -4, 5, -7, -6, -7, -2, -11, 1, -7, -7, -7, 1, 0, -2, 9, -2, -5, 4, 1, -6, -2, 4, -7, 6, -2, -2, -4, 6, 4, -3, -4, -12, 3, 5, -11, -12, 1, -6, -9, -10, 0, 2, 1, -1, -3, -8, -7, -2, -7, -13, -8, -4, -13, -4, -5, -11, 6, -12, -4, 6, -5, 4, 9, -2, -9, -1, 11, -47, 24, -17, -9, -34, -20, 20, 20, 37, 42, 36, -8, 4, 6, 29, -13, -11, 15, 10, 12, -55, -22, -30, -28, -37, -37, -65, 6, 1, 20, 8, 26, -17, -23, 16, 11, 6, -25, 12, 8, 0, -13, -68, -60, 0, -1, 21, -51, -7, -15, 5, -21, -68, 12, 9, -68, -3, 4, -10, -16, -24, 22, 2, 42, 1, 2, -69, -6, -18, -15, 37, 45, -49, 14, -46, -19, -33, -11, -20, -9, -6, 2, 7, -12, -9, -38, -13, -76, -23, 12, -1, 3, 0, 3, -1, 41, 20, 15, 37, -17, 51, 14, 31, 10, -19, -23, 61, -21, 25, -40, -2, -19, -30, 20, -34, -31, -76, -10, -22, -62, -8, -35, -95, -54, 50, -3, -1, -20, -50, 12, 36, -2, 26, -5, -17, 19, 28, 12, -20, 4, -32, -46, 27, 23, -27, -51, 36, 13, 15, 15, 0, -13, 1, -28, 30, -8, -12, -6, 49, -16, -50, -24, 44, 53, 3, 26, -31, 11, 27, -23, 2, 9, 45, 16, 42, 13, -24, -38, 19, 33, -1, 37, 19, 18, 19, -1, -7, -21, 3, -4, -8, 22, 3, -14, -8, 36, -6, 4, -17, 25, -39, -7, -5, -25, 1, 34, -8, 33, 5, -66, -8, -16, -18, 16, -1, -28, -16, -42, -20, 14, -29, 21, 17, -12, 29, -35, 12, 5, 8, 4, 8, 38, 4, -22, 13, 39, 7, -7, 50, -4, -17, -48, 3, -1, 4, 62, 13, -49, 11, -14, -9, 38, 5, 14, 20, 4, 1, 52, 34, -4, -40, 62, -8, 24, 26, 40, 48, 21, 19, -20, -16, -2, -14, 24, 43, 33, -39, 2, -66, 23, -41, -70, -10, 20, 26, -13, -2, 5, 24, 7, 37, 6, -9, -9, -6, 58, 24, 27, 9, 25, 11, -37, 18, -6, -20, 1, 10, 17, -2, -11, -34, 55, -7, -5, -23, -13, 22, -15, 14, -23, -29, 32, 25, -3, -27, 11, -41, 63, 16, -14, 14, 43, 1, 11, 3, 16, -7, 15, 16, 23, 8, 14, -10, 19, -28, -7, 1, -16, -56, 15, 15, -2, -19, 22, 0, 11, 44, 41, -13, 42, -11, 22, 51, -29, 21, 17, -3, 6, 11, -99, 0, -1, 24, -23, -8, 48, 3, 25, 26, -17, -39, 16, -9, 21, 18, 16, 19, 2, -4, -21, 0, -24, -21, 9, 25, 17, -40, 9, 14, -27, 19, 39, 3, 9, 8, 46, 7, -20, -6, 15, 25, -3, 6, 5, -32, -24, -10, 10, -40, -3, -8, -17, 0, -6, -8, -29, -4, 17, -35, -7, -13, -5, -16, 18, -20, 9, -3, -13, -8, 3, -33, 34, 15, -50, -4, -23, 9, 21, 21, 7, 30, 21, -3, -6, 6, -54, -3, 9, -3, 24, 2, 9, 15, 20, -1, -41, -24, 14, 7, 3, -24, -67, -2, 31, 6, 24, 10, 20, 30, -9, 23, -8, -43, -37, 23, 2, 8, -20, -8, 30, 11, -13, -23, -27, 2, -17, 47, 6, 10, 12, -39, -61, -41, -36, -8, 10, 10, 70, -5, -5, -27, 4, 2, -17, -24, 10, 22, 5, 23, -36, -13, 15, 4, -29, -4, -34, 3, -22, -83, -75, -5, -55, 17, -4, 5, 65, -50, 50, 50, -23, -12, -6, -26, 26, 6, -20, 4, 7, 17, 1, 18, 17, -27, 41, 3, -8, -6, -4, 2, -35, -54, -14, -21, -29, 28, 34, 15, 72, 2, -16, 31, 38, -29, 21, -19, 12, 7, -17, 22, 33, 19, -14, 6, -17, 31, 60, 32, 6, 41, 17, 4, -1, -25, -21, -7, -9, -25, -10, 30, 50, 4, 17, 35, 14, 35, 4, 23, 3, -2, 8, -16, -1, 25, 1, 26, -34, -9, 25, 17, 2, 12, 2, -7, 24, -70, 23, -37, -59, -10, -23, -13, 11, -3, -4, -23, 48, 60, -16, -18, 32, -29, 0, -22, -5, -28, 23, -18, -69, -3, -9, -27, -22, -17, 9, -40, 26, 64, -3, -31, -6, -9, 2, 27, 1, 0, 19, -27, 50, 28, 18, 7, 6, -16, 15, 15, 0, -39, 22, 12, -20, 1, 17, -47, 24, -23, -9, -16, 16, 51, -15, 19, -2, 43, 51, 19, -14, -1, 64, 24, 5, 19, -45, 0, 0, -3, 4, -4, -13, -6, 34, -6, -26, 7, -29, 23, -25, 10, 1, -22, 18, 18, -27, 5, 18, -14, 5, 22, 2, 20, 64, 9, -50, 14, 16, 2, 12, -33, -3, -10, -9, 53, 55, -11, -86, 5, 11, -3, -13, -17, 13, -44, -11, 17, -18, -4, -2, 8, 14, 30, -59, 0, 13, 43, 17, -31, 47, -18, -1, 22, 24, 20, 16, 44, 34, -25, 39, -2, 19, 32, 7, 13, -1, 1, 5, 14, -27, 3, -1, 1, 45, -4, 37, 10, 26, 20, 3, -20, 6, 6, -7, 15, 20, 47, 14, 39, 35, -17, 18, 0, 39, 27, 31, -4, 14, 25, -10, 29, -9, -8, 15, -26, 14, -13, 40, -7, 21, -4, 29, 2, 6, 8, -13, 22, 0, 34, 8, 21, 29, -9, 23, 26, 16, 44, 29, 7, 0, 7, -29, -6, 2, -17, 6, 6, -3, -8, 43, -5, 10, 5, 25, 11, 5, -15, -48, 2, 15, 29, -9, 27, 16, -30, -16, -3, 42, 23, 18, 7, 3, 26, -15, 11, 12, -4, -12, 22, 50, -13, 51, -12, 24, 16, 23, 12, 15, -1, -35, -58, -15, 23, 2, 41, 32, -1, 73, 28, -5, -27, 6, 25, 4, -52, 13, -28, -79, -3, 4, -104, 24, 3, 53, -4, -35, -53, -7, 1, 4, 13, 16, 7, -28, 32, -5, -2, 14, 13, 69, 12, 10, -16, 49, 47, -41, 23, 32, -23, -40, -68, 14, -9, 59, -10, 11, -46, -21, -49, 1, 8, 14, 19, -28, 19, -46, 1, -34, 14, -47, -6, 73, 10, 6, -79, 22, 61, -70, -10, 7, 4, -23, -14, -18, 14, 26, -3, 7, 8, -1, -3, -3, 2, 18, 9, -18, -58, -21, 2, 9, -4, 20, -33, -7, 26, 19, -61, 28, 36, 8, -74, 6, 10, -44, 34, -6, -15, 23, 18, -18, 8, 24, -12, 39, 3, 24, 36, 35, -47, 85, -14, 44, -22, -11, -14, -58, 47, 11, -49, -12, -17, 20, -17, 21, 30, 28, 23, 14, 4, -43, 6, -47, 28, -75, 1, -25, 19, 4, 40, 18, -10, 9, 11, 38, -17, -5, -4, -32, 16, -16, 24, -3, 25, 24, 32, 1, -20, 10, 29, 11, -5, -61, 1, 5, 37, 23, -3, -57, 4, -22, -11, 18, -20, -33, -19, 25, -1, 32, -7, 27, -8, -15, 38, -4, -29, 3, -25, -16, 36, 9, 0, 13, -33, -92, 5, -14, 29, -13, -31, -15, -14, 19, -9, 28, -25, 13, 41, 40, 19, 2, 3, 64, 3, -30, 31, -16, -26, 62, -21, 19, -46, 0, 11, -15, 21, -4, 30, -15, -26, -23, 2, 7, 57, 9, 8, 13, -20, -2, 24, 25, -6, -25, -7, 42, 35, -25, 26, -3, -8, -2, -7, -5, -78, 13, 42, 38, -21, -22, -30, -16, 22, -41, -61, -5, -17, 3, -12, -11, 12, -39, -15, 15, 42, 32, 8, -14, -9, 17, -4, -8, -1, -21, 9, -30, 2, 5, 43, 33, -64, -22, -88, -3, -4, -98, -31, 0, 3, 34, -48, 19, -7, -10, 1, -2, -35, 6, -14, -25, -16, 12, -9, 31, 1, -45, -11, -42, -21, -32, 53, 21, -14, -114, -60, 37, 9, 14, -13, -1, -1, 40, -13, -40, -20, 0, 2, 6, 27, 6, 0, -23, -28, 10, 29, 19, -37, -21, 4, 26, 40, -36, -41, -32, -21, -56, -7, -25, 6, 14, -31, 11, 17, 24, -50, 28, 33, 7, 18, -64, -6, -19, 26, -26, 60, -2, 38, -42, 22, -52, 16, -13, -64, 5, -20, -30, -83, -15, -2, -37, -13, -21, -65, 32, -3, 43, 78, 34, 17, 33, 1, -27, -100, -16, 0, 64, 37, -10, -2, -61, 9, -101, -33, -31, -57, 2, 4, -12, -2, 3, -6, 26, 9, 29, -102, 37, -19, 34, -3, -14, -58, 40, 10, 10, -40, -6, -31, -12, 13, -23, 40, -59, 18, -22, -85, -9, -43, 6, 27, 13, 4, 43, 10, 30, -26, 17, -44, -33, -30, -7, 0, -15, -42, 37, 11, 17, 19, 23, -40, 13, -42, 0, 31, -52, 11, 20, -43, 11, -125, -15, -23, -32, 4, 36, 7, 61, -36, 33, 19, -62, -56, 14, -4}

#define TENSOR_CONV2D_17_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_17_BIAS_0 {-9, 39, 16, -68, 3, -5, 9, -78, 0, -8, -17, 7}

#define TENSOR_CONV2D_17_BIAS_0_DEC_BITS {7}

#define CONV2D_17_BIAS_LSHIFT {6}

#define CONV2D_17_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_18_KERNEL_0 {-7, 60, 32, -34, 31, -29, 2, 10, 48, 17, -29, -36, -21, 31, -63, 41, -19, 11, 36, -25, 28, -15, -19, -26, 15, -49, 14, -12, 15, -10, 26, -30, -18, 2, -14, -54, -24, -37, -9, -32, 23, -46, -2, -34, 13, 31, 31, -9, -16, 1, -20, 22, 4, -43, 15, 19, -25, 17, 47, 21, -8, 25, 2, -6, 3, -1, 37, -1, -14, 38, -14, 66, 10, 37, -45, 1, 2, -35, -8, 7, -15, -23, 77, 33, -7, 22, -4, 15, 15, -7, 47, 2, -9, 19, -22, 36, -11, -65, 19, 26, 46, 30, 27, 9, 44, 5, 6, 14, 13, -12, 28, -70, 21, 53, -20, 4, 21, -11, 51, 0, -6, -37, 11, 12, 4, -2, 35, -1, 21, 35, -16, -11, -8, -29, -26, -6, -22, 36, -12, -6, -12, 24, 41, 41, 12, 24, 1, 34, -43, 42, -19, 14, -103, 39, -61, 43, 2, 19, -46, 30, -7, -22, -26, 7, 18, 30, -69, 32, 11, 35, 43, 8, -19, -4, -7, -116, -27, 29, 12, -49, -16, -55, -82, 28, 34, -39, 25, -99, -39, -104, -20, -74, -2, 27, 0, 14, 0, 1, -22, 42, 11, -44, -68, -7, 15, 30, -6, 29, 22, 7, 23, 51, 59, -1, 28, 16, -5, 14, 22, -10, 33, -43, -3, -23, -54, 21, 1, -21, -17, 14, 4, -40, -24, 7, -14, -68, 8, 42, 42, -41, -25, 21, 22, -31, 9, -5, 12, 0, -3, -12, -66, -77, 5, -36, -36, 9, -13, 30, 32, -27, 51, 40, -53, -26, -4, -14, 23, 12, 31, -2, 25, -8, 35, 18, -17, -45, -19, -39, 5, 23, -36, -24, 18, -1, -24, 39, -41, -2}

#define TENSOR_CONV2D_18_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_18_BIAS_0 {21, 45, 17, 33, 22, -44, -74, 55, -35, 31, 0, -41}

#define TENSOR_CONV2D_18_BIAS_0_DEC_BITS {7}

#define CONV2D_18_BIAS_LSHIFT {4}

#define CONV2D_18_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_19_KERNEL_0 {13, -11, -19, -12, 1, -9, 1, 4, 4, 14, 6, -1, -37, -23, 4, -5, 8, 9, 17, 0, 0, -20, -10, 3, 10, -53, -13, 2, -11, 2, 2, -39, 14, -35, -2, 1, -46, -24, 7, -6, 4, 0, 6, -8, 4, 0, 1, 1, 5, -12, 8, -2, -18, 0, -15, -30, 3, -22, -35, -34, -19, -4, 7, 21, -46, -7, -44, -41, 2, -10, -12, 2, 10, -4, -24, -35, -2, -25, -16, 33, -57, 17, 5, -11, -6, 18, -5, 7, -37, -31, 17, -6, -36, -9, 9, 2, 10, -8, -22, -27, -1, -7, 11, 9, 10, 15, 9, -5, -27, -15, 2, -11, 14, 3, 5, -14, -14, -35, -27, 7, -10, -9, -6, -3, -14, -2, -1, -10, 1, -6, 5, -11, -12, -7, -16, -12, -12, -2, 2, 10, 5, -5, -9, -4, 5, -16, 1, 10, -16, 4, -38, -27, 1, 2, -27, -29, -28, -22, 5, 18, -29, -12, -33, -13, 3, -15, -5, 7, 14, -6, -15, -26, -2, -10, 16, 4, -1, 9, 8, -9, -36, -15, 1, -7, 12, 10, 7, -3, 2, -30, -16, 2, -13, -5, 2, 3, -2, -1, -2, -8, -29, 14, 1, -18, 10, -2, -30, -12, -3, -12, 3, 47, -54, 7, -11, -17, -18, -28, 8, 13, -46, -18, -34, -72, 1, -30, -13, -7, -1, -8, 6, -4, -2, 7, 1, 7, -10, 11, 3, -9, -14, 11, -7, -22, -7, -9, -20, 7, 8, 17, -2, -53, 10, 10, -25, -19, -7, 2, -13, 55, -3, -2, 7, 7, 1, 22, -6, -11, -15, -41, -24, 23, -45, -14, -6, 4, -47, 12, 14, 16, -18, -36, -43, -46, -67, -9, -21, -24}

#define TENSOR_CONV2D_19_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_19_BIAS_0 {-60, -105, 27, 27, -50, -35, -13, -54, -26, 47, -27, 91}

#define TENSOR_CONV2D_19_BIAS_0_DEC_BITS {8}

#define CONV2D_19_BIAS_LSHIFT {1}

#define CONV2D_19_OUTPUT_RSHIFT {7}

#define TENSOR_DENSE_4_KERNEL_0 {9, -1, -20, 12, -2, -48, 9, 12, 16, 10, -35, -34, -18, -47, 10, 7, 8, -2, -31, 3, 1, -36, -3, 2, -12, -12, 11, 0, -9, 4, 1, -42, -20, -19, -12, -41, 16, 13, -3, -7, -32, 16, -50, -35, 17, 20, 12, 14, -60, -40, -67, -82, -60, -5, -96, -63, -67, -96, -79, -94, -51, -22, -25, 11, -38, -15, -43, -47, 15, -12, -3, 13}

#define TENSOR_DENSE_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_4_BIAS_0 {-15, 3, -49, -16, 84, 7}

#define TENSOR_DENSE_4_BIAS_0_DEC_BITS {5}

#define DENSE_4_BIAS_LSHIFT {2}

#define DENSE_4_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define CONV2D_16_INPUT_OUTPUT_DEC 9
#define CONV2D_16_INPUT_OUTPUT_OFFSET 0
#define CONV2D_16_OUTPUT_DEC 7
#define CONV2D_16_OUTPUT_OFFSET 0
#define RE_LU_16_OUTPUT_DEC 7
#define RE_LU_16_OUTPUT_OFFSET 0
#define CONV2D_17_OUTPUT_DEC 5
#define CONV2D_17_OUTPUT_OFFSET 0
#define RE_LU_17_OUTPUT_DEC 5
#define RE_LU_17_OUTPUT_OFFSET 0
#define CONV2D_18_OUTPUT_DEC 4
#define CONV2D_18_OUTPUT_OFFSET 0
#define RE_LU_18_OUTPUT_DEC 4
#define RE_LU_18_OUTPUT_OFFSET 0
#define CONV2D_19_OUTPUT_DEC 2
#define CONV2D_19_OUTPUT_OFFSET 0
#define RE_LU_19_OUTPUT_DEC 2
#define RE_LU_19_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_4_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_4_OUTPUT_OFFSET 0
#define FLATTEN_4_OUTPUT_DEC 2
#define FLATTEN_4_OUTPUT_OFFSET 0
#define DROPOUT_4_OUTPUT_DEC 2
#define DROPOUT_4_OUTPUT_OFFSET 0
#define DENSE_4_OUTPUT_DEC 1
#define DENSE_4_OUTPUT_OFFSET 0
#define SOFTMAX_4_OUTPUT_DEC 7
#define SOFTMAX_4_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_16_input_config = {
    .super = {.name = "conv2d_16_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_16_kernel_0_data[] = TENSOR_CONV2D_16_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_16_kernel_0_dim[] = {6, 2, 1, 16};
const nnom_qformat_param_t tensor_conv2d_16_kernel_0_dec[] = TENSOR_CONV2D_16_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_16_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_16_kernel_0 = {
    .p_data = (void*)tensor_conv2d_16_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_16_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_16_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_16_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_16_bias_0_data[] = TENSOR_CONV2D_16_BIAS_0;

const nnom_shape_data_t tensor_conv2d_16_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_16_bias_0_dec[] = TENSOR_CONV2D_16_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_16_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_16_bias_0 = {
    .p_data = (void*)tensor_conv2d_16_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_16_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_16_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_16_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_16_output_shift[] = CONV2D_16_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_16_bias_shift[] = CONV2D_16_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_16_config = {
    .super = {.name = "conv2d_16"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_16_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_16_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_16_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_16_bias_shift, 
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_17_kernel_0_data[] = TENSOR_CONV2D_17_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_17_kernel_0_dim[] = {4, 2, 16, 12};
const nnom_qformat_param_t tensor_conv2d_17_kernel_0_dec[] = TENSOR_CONV2D_17_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_17_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_17_kernel_0 = {
    .p_data = (void*)tensor_conv2d_17_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_17_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_17_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_17_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_17_bias_0_data[] = TENSOR_CONV2D_17_BIAS_0;

const nnom_shape_data_t tensor_conv2d_17_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_17_bias_0_dec[] = TENSOR_CONV2D_17_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_17_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_17_bias_0 = {
    .p_data = (void*)tensor_conv2d_17_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_17_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_17_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_17_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_17_output_shift[] = CONV2D_17_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_17_bias_shift[] = CONV2D_17_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_17_config = {
    .super = {.name = "conv2d_17"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_17_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_17_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_17_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_17_bias_shift, 
    .filter_size = 12,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_18_kernel_0_data[] = TENSOR_CONV2D_18_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_18_kernel_0_dim[] = {2, 1, 12, 12};
const nnom_qformat_param_t tensor_conv2d_18_kernel_0_dec[] = TENSOR_CONV2D_18_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_18_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_18_kernel_0 = {
    .p_data = (void*)tensor_conv2d_18_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_18_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_18_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_18_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_18_bias_0_data[] = TENSOR_CONV2D_18_BIAS_0;

const nnom_shape_data_t tensor_conv2d_18_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_18_bias_0_dec[] = TENSOR_CONV2D_18_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_18_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_18_bias_0 = {
    .p_data = (void*)tensor_conv2d_18_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_18_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_18_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_18_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_18_output_shift[] = CONV2D_18_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_18_bias_shift[] = CONV2D_18_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_18_config = {
    .super = {.name = "conv2d_18"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_18_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_18_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_18_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_18_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_19_kernel_0_data[] = TENSOR_CONV2D_19_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_19_kernel_0_dim[] = {2, 1, 12, 12};
const nnom_qformat_param_t tensor_conv2d_19_kernel_0_dec[] = TENSOR_CONV2D_19_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_19_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_19_kernel_0 = {
    .p_data = (void*)tensor_conv2d_19_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_19_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_19_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_19_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_19_bias_0_data[] = TENSOR_CONV2D_19_BIAS_0;

const nnom_shape_data_t tensor_conv2d_19_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_19_bias_0_dec[] = TENSOR_CONV2D_19_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_19_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_19_bias_0 = {
    .p_data = (void*)tensor_conv2d_19_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_19_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_19_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_19_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_19_output_shift[] = CONV2D_19_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_19_bias_shift[] = CONV2D_19_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_19_config = {
    .super = {.name = "conv2d_19"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_19_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_19_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_19_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_19_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_4_config = {
    .super = {.name = "global_max_pooling2d_4"},
    .output_shift = 0,
};

const nnom_flatten_config_t flatten_4_config = {
    .super = {.name = "flatten_4"}
};
const int8_t tensor_dense_4_kernel_0_data[] = TENSOR_DENSE_4_KERNEL_0;

const nnom_shape_data_t tensor_dense_4_kernel_0_dim[] = {12, 6};
const nnom_qformat_param_t tensor_dense_4_kernel_0_dec[] = TENSOR_DENSE_4_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_4_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_4_kernel_0 = {
    .p_data = (void*)tensor_dense_4_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_4_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_4_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_4_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_4_bias_0_data[] = TENSOR_DENSE_4_BIAS_0;

const nnom_shape_data_t tensor_dense_4_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_4_bias_0_dec[] = TENSOR_DENSE_4_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_4_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_4_bias_0 = {
    .p_data = (void*)tensor_dense_4_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_4_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_4_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_4_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_4_output_shift[] = DENSE_4_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_4_bias_shift[] = DENSE_4_BIAS_LSHIFT;
const nnom_dense_config_t dense_4_config = {
    .super = {.name = "dense_4"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_4_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_4_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_4_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_4_bias_shift
};

const nnom_softmax_config_t softmax_4_config = {
    .super = {.name = "softmax_4"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_4_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_16_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_16_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_17_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_18_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_19_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_4_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_4_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_4_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_4_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_48_NNOM_H