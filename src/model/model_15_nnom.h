#ifndef HAR_CNN_NNOM_H
#define HAR_CNN_NNOM_H

#define APP_ACTIVITY_MODEL_NAME har_CNN_nnom
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
#define TENSOR_CONV2D_24_KERNEL_0 {34, -56, 35, 5, -22, 26, 3, -11, -3, 4, -13, 14, 14, 6, 26, 34, -12, 7, -32, -21, -13, -50, 19, 10, -27, 12, -11, 25, 1, -8, 38, -1, -16, -7, 26, 50, -9, 43, -51, -18, -26, -34, 5, -12, 28, 20, 29, 34, 24, 11, -7, -12, 4, -2, 15, 15, 17, 34, -47, -63, -3, 3, -5, -2, 2, 3, 20, 5, 31, -63, -48, 18, 11, -24, -3, 4, -4, 4, -11, -18, -7, 14, -21, 10, 40, -10, -19, 1, -33, -11, 44, -13, 13, 20, -40, 14, 23, 23, -6, 8, -23, -20, -26, 7, -21, -46, 40, -56, -36, 20, -12, 19, 12, 9, -18, -28, 13, -25, 41, 24, 36, -36, -33, -23, -12, 34, 20, 15, -13, -26, 0, 8, -4, -6, 13, -4, -67, 1, 58, 4, -9, -2, -16, 0, 48, -51, 20, 6, 0, -8, -12, 5, -27, 26, -18, 12, 35, 28, 26, 15, 21, -30, 15, -6, 9, 1, 25, 4, 35, -21, -14, 18, -4, 1, 10, 6, -3, -5, -24, 8, -32, -1, -27, 8, 14, -10, -7, -17, -34, -5, -38, 61, 17, -49, -34, 8, 14, -28, -8, -22, -3, -9, 18, -19, 19, 3, -1, -6, -15, 2, 13, -2, 5, -21, -12, -4, 1, 49, -3, 11, 1, -53, 8, -45, 5, -43, -5, 19, -43, -56, 6, 0, 19, 33, -5, 3, 6, -5, 24, 1, 40, -25, -13, 30, 27, -6, 20, 1, -19, 7, -54, 8, -19, -2, -36, -10, -16, -21, -25, 17, 25, 28, 64, 1, 25, 42, 37, -26, -16, -12, -20, 3, -26, -17, -25, 6, 61, -2, -17, -5, -7, 1, -13, 1, -39, -21, -48, -14}

#define TENSOR_CONV2D_24_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_24_BIAS_0 {-11, -2, 2, -14, -2, -9, 21, -68, -21, 2, -20, -7, 6, -16, 1, -8, -2, 10, -4, -4, -53, -33, 5, -26}

#define TENSOR_CONV2D_24_BIAS_0_DEC_BITS {8}

#define CONV2D_24_BIAS_LSHIFT {5}

#define CONV2D_24_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_25_KERNEL_0 {20, 11, 4, 11, 7, 1, 2, 53, -1, 30, 7, -18, 4, -10, 1, -6, -12, -4, 9, 32, -12, 47, 14, -12, -18, 1, -13, -20, -8, 2, 3, 6, 24, 11, 11, -15, 14, -11, 14, -15, 6, -5, -16, 8, 8, -40, 2, 36, 17, 21, 23, 18, -10, 22, -9, -26, -10, 11, 8, -49, -9, 15, 9, 10, -15, 3, 1, 42, -11, 24, 21, -13, 5, 19, -31, -21, -19, -16, -8, 14, 36, -72, 5, 14, 10, -2, 5, -19, 8, 7, -22, 9, 9, -26, 19, -21, 33, 12, -29, 6, -1, 5, -20, 10, 13, 4, 4, -45, -17, 13, -7, -31, -8, -8, -3, 0, 2, -15, 13, -5, 5, -10, -30, 21, 11, -5, 16, 12, -35, -11, -2, -8, 4, -15, 14, -5, 9, -1, -26, -45, 15, 31, 3, -3, 21, 15, 9, -5, 17, 22, 0, 27, 23, 21, 11, -10, 6, 15, 11, 9, -30, 8, 6, 29, 40, 6, 25, -13, 17, -3, 4, -11, -17, -6, 0, 41, 4, 9, -10, 24, -5, -25, 4, -19, -19, 0, -9, 17, -27, -1, 6, -5, -83, -33, 1, -59, 14, -3, -7, -26, -21, -11, -35, -42, -2, 15, 2, 10, -26, -7, 8, -22, -4, -80, 35, 27, 2, -2, -4, 3, 38, -7, 3, 0, 10, -19, -10, -8, 11, 20, 10, -1, 11, 14, 15, -35, 26, -4, 15, 9, 8, -18, -38, -53, 27, 13, -6, 100, 14, -17, 2, 3, -4, 4, 16, -7, -10, 8, -23, 27, -43, -41, 11, 17, -12, -14, 16, 19, 9, -4, 1, 15, -19, 11, -6, 10, -8, 2, -9, 35, 2, -5, -6, -9, -38, -14, -10, -2, -37, -3, 23, -1, 22, 18, 3, 23, -79, 1, 10, -31, 7, 13, 13, 24, -2, 10, 19, -12, -8, 2, -3, -11, -13, 11, 7, -5, -18, 12, 0, -89, 21, -29, -22, 0, 3, -10, -6, 23, -7, 7, -20, -17, -23, 0, 17, -77, -10, -8, 9, 2, 48, 6, 10, 65, -26, 24, -19, 21, 11, 25, 4, 23, -15, 6, 14, 1, 35, -2, 15, 26, -28, 13, -13, -5, 34, 13, -7, -9, 11, 14, 10, -14, -24, -3, -13, -20, 22, -11, 7, 26, 28, 23, -39, 30, 26, 6, 18, 6, 16, 18, -22, -6, 14, -7, 19, -5, 14, -2, -9, 21, 8, -7, -7, 26, 24, -7, 13, 15, 30, -1, -22, -26, -3, 2, -19, 43, -9, -2, -5, 40, 5, 21, 3, -12, -43, -13, 14, 13, 25, -42, 9, 22, -2, -4, 6, 19, 7, 20, -24, 6, 18, -5, 11, -5, -10, 13, -10, 18, -13, -5, -9, -15, 25, -31, 18, 21, 5, -7, 4, -16, 14, 6, -14, 15, -11, 8, -11, 21, 16, 7, 14, -2, 20, -3, -4, -5, 24, -21, 16, 24, -10, -15, -7, -19, 0, 33, -2, -35, 31, 2, 15, -11, -19, -4, 8, 16, 28, -7, -1, 26, 13, 2, 7, 7, 27, 5, -8, 0, 9, 5, -12, -11, 0, 1, 5, 1, -6, 8, -7, 10, -1, -14, 9, -2, 5, 5, 9, 14, 28, 4, 18, 5, 13, 13, -10, 36, 25, 18, -11, 19, 6, 12, 2, 15, -11, 4, 1, 7, 9, -7, 14, 27, -7, 20, -9, -9, -4, 11, -12, 20, 23, -7, 15, -4, -17, 8, 1, 13, 3, -9, -10, 3, 27, 16, -4, 22, 35, 13, 28, -17, 12, 11, -7, 32, -2, 21, 16, 13, -10, 31, -3, 13, -12, 7, 11, 10, -15, -2, 16, 19, 10, -1, -17, -20, -10, -7, 6, 22, 13, -24, 15, 10, 7, 5, 20, -25, 13, 14, -23, -20, -1, 15, 3, 32, -11, 2, 0, -2, 13, 4, 9, 27, 16, 17, 4, -8, 14, 5, 0, 9, 0, -4, -6, 4, -21, -1, -8, -43, -7, -5, 1, 2, 11, 9, -5, -6, -8, 2, 27, 6, -17, -9, -7, 9, 3, 6, -16, -20, 8, 11, -10, 29, 19, 23, -3, 10, 16, 37, -8, 69, 8, 11, 38, -1, -4, -2, 7, 14, 3, 18, 3, 20, 8, 4, -1, -21, -12, 10, 5, 14, 2, 1, 11, 7, 15, -8, 5, 22, -16, -11, 0, 28, -7, 13, -11, 16, 19, -24, 3, -11, 41, 5, -9, 18, 5, 17, -14, 66, 1, 26, 36, -15, -9, 0, -6, 4, 10, 6, -8, 32, 19, 2, -19, -6, -3, 2, 8, 0, 20, 13, 21, -9, -14, -8, 14, -1, 2, -11, 17, 13, 9, 2, -29, 6, 15, 6, 2, 15, 39, 9, 21, 26, -15, 14, -8, 58, 10, 16, 33, -1, 22, 9, 13, 11, 17, -14, 1, 41, 23, 31, 3, 8, 35, 1, 4, 4, 11, 2, -16, 23, 25, 17, -17, 1, 8, -8, -20, 2, 8, -26, 19, 7, 1, 8, -7, 23, 26, -9, 3, 14, 3, 18, -18, 28, 13, -4, -2, 0, 3, -1, -9, 8, 7, -25, -10, 11, 1, 11, 7, -27, 11, -4, -6, 8, 3, 14, -14, 17, 3, 6, 9, -4, 6, 5, -2, -12, 9, -6, 37, 19, 14, 13, -3, 23, 16, -14, 10, 6, 7, 9, -27, -5, 1, 0, 15, 1, -2, 8, -6, 12, 9, -6, 1, 14, 25, 11, 10, -1, 18, -4, 4, 13, -13, 23, -4, 5, 13, 6, 9, 22, 12, 1, -10, 6, -2, -18, 3, 10, 5, -10, -11, 4, 1, 3, 17, 0, 11, -3, -10, 27, 24, 18, 10, 9, 6, 6, -6, 13, 5, -17, -2, 13, 29, 7, 17, 32, -1, 0, -12, 1, -15, 7, 2, 37, 4, 16, -1, 7, 13, 0, -4, -10, 10, -20, 1, -8, 40, 3, 13, 2, -18, -27, 21, -1, -26, -15, 21, -47, -45, -15, -7, -8, 43, 2, 13, 3, 2, 14, 24, -52, -26, 4, 2, -11, -1, 15, 3, 2, 11, -19, -4, -1, 20, -7, 28, 17, -7, 27, 7, 11, 18, 8, 9, 13, -36, 13, 21, 8, -28, -4, -31, -11, 25, -25, 2, 21, -2, 9, -1, -24, -7, 15, 7, -16, -4, 8, -29, -18, -16, 13, 5, 45, -6, -20, 15, 19, 15, -3, 22, 21, -10, -5, -17, -4, -3, -18, 9, -3, 27, 2, 9, 2, 20, -6, 10, 6, 12, -21, -6, -70, 3, 9, 1, 20, -28, 11, -5, -19, 4, 4, -5, -22, 10, 7, 12, 9, -4, -4, -12, 3, 26, -5, 6, -19, 1, 17, 22, 27, 13, -26, -37, -20, 17, 5, 20, 15, -4, 7, 0, -7, 6, -47, -2, 20, -2, -8, 65, -28, 25, 24, 2, 23, -43, 24, -14, -10, -36, -3, 3, 49, -5, 12, 11, 3, 21, -33, -56, 15, 11, 6, 19, -28, -28, -2, 6, -57, -2, 27, -44, -26, 2, 11, -11, 21, -5, 26, -6, -16, 0, 16, -7, -37, -11, 14, -1, -11, -8, -30, 14, 28, -18, -11, -5, 22, -21, -14, 10, 0, 33, 13, 13, 2, 2, -27, -18, 21, 3, 1, -13, 8, -7, 12, 9, 32, -6, 7, -5, -4, 7, 14, 0, 13, -10, 13, 6, 28, -1, 2, 13, -44, -16, -28, 1, 6, -20, -59, 10, -45, -7, -11, 12, 5, -10, 17, -2, -4, 28, 8, 12, -5, -26, 2, 5, -12, 6, 1, -3, -17, -4, -14, 6, 2, -21, 24, 7, -4, 15, 16, 12, 19, -8, 12, 13, 11, 18, -9, 21, 17, -16, -21, 11, 12, -12, -17, 20, -10, -37, -21, -23, 43, -3, -5, 8, -5, 14, 8, -1, -6, -29, 1, -16, 5, 8, 12, -5, -6, -31, -27, 11, -23, -26, -3, 2, -10, -3, 11, -8, 12, -10, 10, 21, 10, -21, -16, 8, -14, -18, -7, -12, 16, -6, -59, 10, -25, -26, -42, -21, -5, -5, -4, 11, -41, 19, 4, 28, -12, -57, -37, -9, 30, 0, -3, -9, -1, -3, -13, 8, -44, 0, 14, -6, -24, 3, 6, 17, 2, -11, 7, 28, -1, -29, -16, 6, 22, -37, -39, 2, 12, -18, -4, 11, -11, 12, -9, 4, 35, 3, 15, -36, 6, 19, 8, 3, -2, 29, -23, 24, -32, 17, 0, 18, 24, 16, -9, -7, -47, -2, 15, 7, 25, 14, 42, 16, 1, 19, -25, 32, 24, -5, 1, 12, -7, 19, 29, -7, 21, 4, 5, 4, -68, -21, -14, 30, 20, 2, -5, 4, -33, 19, -5, 22, 30, 31, 17, 10, -34, 24, 14, 14, 0, 15, 18, -2, 5, -23, -8, 6, 20, -13, 14, 15, 31, 14, 5, 11, 9, -44, -10, -9, -18, -14, 36, -29, -14, -7, 3, -4, -63, 29, -5, 8, -4, -17, -10, 1, -33, 19, -6, -24, 14, -68, -14, 29, -9, -20, 21, 19, 15, 22, -8, 6, 12, -33, 23, 44, -4, -16, -4, 14, 9, 34, 13, 21, 30, 20, -13, -9, -9, 18, -25, -35, 19, 2, -28, -18, -66, -31, -17, -6, 4, -21, -41, -18, -59, 34, -21, -63, -14, -49, 11, 11, -22, 36, 12, -8, -6, 55, 21, 31, 50, 13, -55, -13, 8, 17, -2, 17, 44, 38, 1, 14, -16, 21, -60, 7, -34, 7, 3, -26, -10, 47, -9, 10, 17, -4, 4, 4, 5, 35, 8, 19, -13, -11, 1, -24, 19, 16, -14, 42, -11, -8, -12, -14, 17, 39, 6, 8, 61, -25, 24, 31, 21, -19, -10, -4, -32, -5, -5, 0, 15, -16, 19, -14, 20, 20, 12, -27, -37, 21, 25, 13, 43, 2, 3, 47, -28, 1, -16, 23, -6, -7, -2, -23, 28, -22, -33, 4, 10, -5, 23, 11, 2, 27, 27, 9, 32, 13, -36, 1, 30, -1, -10, 9, -25, -19, 1, -12, 28, 38, -43, 2, 10, 39, -4, 2, -40, 21, 43, -13, 72, -29, 26, 19, -3, -26, -9, -18, -13, -13, 2, -32, 27, 8, -37, -6, 4, 7, -10, 6, 9, 22, 31, 14, 60, -10, -4, -1, 14, 7, 4, 19, -21, -9, 5, 3, 9, 3, -26, 7, 28, 18, 1, -4, -74, 26, 26, -5, 38, -29, 31, 1, -31, -32, -36, 8, 23, 2, 8, -20, 17, 46, -13, -51, -13, 24, 6, -3, 6, 16, 20, 0, 15, -34, 15, 1, 12, -13, -10, -3, -17, -14, 17, -4, 21, -26, -8, -1, 20, -37, 24, 6, -20, 7, -22, 6, -13, 6, -7, -20, -28, -34, 11, 1, -9, -5, 6, 5, -17, -36, -40, -16, 19, 10, 15, 3, -11, 5, -2, 13, -56, -5, 21, -42, -8, 14, 10, 7, 19, -23, 20, 16, -18, -4, -44, 0, -47, -20, -35, -2, -1, 16, -33, 5, 11, 28, -5, -31, -32, -30, 17, -5, -24, 1, 14, 6, -30, -45, -9, -15, 13, 0, 8, 17, -13, 15, 2, 16, 2, -8, 9, -1, 5, 5, 5, 30, 3, 5, 17, 17, 0, 19, -6, 2, 0, -6, -32, 13, 14, -22, -42, 16, 2, -10, -6, -25, 17, -6, 16, 12, -30, 5, 20, 6, 13, -24, 22, -15, 18, -12, -6, 0, -5, -14, -11, 17, 12, 4, -11, -19, -14, -12, -5, -4, 23, -11, 1, 29, 5, -36, -26, -1, 7, -12, -6, -6, -20, -45, -30, 17, -13, -24, -14, -26, 9, 6, 6, 28, -3, 17, 28, 39, -17, -38, -21, 10, 35, -32, 5, -1, 6, -21, -51, 0, 18, 30, 21, -11, -6, 7, 0, 2, -2, 2, 9, 13, 1, -22, -23, 24, 7, -16, -7, 20, -49, -14, -13, 13, -16, -20, -1, -8, -25, -3, -30, 0, 2, 23, -8, 11, -10, -5, -10, -44, 34, -72, 24, -2, 12, 6, -3, 2, -17, -7, 9, 5, -18, -7, -3, 0, 12, 15, -15, 21, 34, 29, 15, -13, -10, 15, -19, -16, -4, 9, 4, 6, 16, 26, -16, -21, 7, 5, 4, -8, 0, 7, -3, -16, -6, 11, -22, -24, 10, -17, -6, 35, 5, 1, -4, -18, 27, -23, 20, -58, 15, -1, -7, -7, 0, -4, -8, 7, -5, 10, 9, 0, -6, 12, -32, 13, -11, -6, -33, 4, -36, -25, -15, -13, 7, 46, -5, 17, -7, -12, -2, 29, -14, 63, -4, -12, 40, -11, 2, 15, -8, 10, 18, -3, -28, -9, 19, -16, -1, -2, 10, -7, -6, -3, -6, 8, 16, -21, 10, -17, -10, -7, 2, 23, 0, 2, 9, 24, -16, 25, -1, -1, 38, 23, -22, 21, 9, -9, 2, -29, 25, -17, 6, 2, 15, -1, -26, 27, 2, 1, -26, -20, -14, -4, 67, 21, -2, 1, 24, -4, 5, 25, -6, 3, 26, 17, 34, -24, 7, -12, 18, 5, -31, -29, -18, 12, -67, 7, 12, -27, 10, 27, -1, -14, 12, 15, -13, 11, -3, 22, -53, -2, 20, 3, 9, -13, 9, 0, -2, -4, -2, 0, -14, 6, 5, -8, 19, -4, -4, -4, -5, 12, 35, -23, -12, -14, -15, 22, 13, -2, 28, -1, -12, -10, -25, 2, -4, 26, 33, 3, 17, -2, -11, -17, 15, 1, -39, 43, -20, 6, 3, 2, 2, -14, 2, 9, -17, -7, -39, 0, -12, 8, 5, 3, 7, 1, -20, 10, 7, -9, 0, -66, 1, -8, -27, -19, 36, -12, -4, -4, 13, -4, -3, 32, -23, 6, 22, 4, 1, 22, -1, -3, 18, 5, -11, -25, -4, 12, 0, -11, 13, 0, 0, 21, -1, -4, -18, -7, 29, 4, -3, -5, 6, 9, -8, 9, -5, 1, 29, -5, 22, -3, -11, -14, -24, -23, 34, 10, 23, 7, -53, -9, -2, 6, 6, 11, -31, -2, -13, -6, 4, -25, -10, -15, 12, 25, -10, -4, 6, 23, 2, 18, 1, 12, 9, 27, -32, 20, 9, -14, -14, -6, 22, 21, -5, -4, -4, -6, 7, -5, -34, -6, 40, 27, -15, 9, 13, 0, -88, 39, 15, -12, 12, -33, 5, -20, 20, -35, -8, 15, 22, -15, 20, -44, -13, 50, -1, -16, -22, -14, -2, 7, -14, 4, 1, -12, 3, 26, 15, 14, -16, -7, 8, -10, 15, -52, 7, 20, 10, 48, -3, 16, 1, -19, -22, 8, -20, 0, 4, -10, 22, 0, 4, -9, -8, -72, 2, -3, -30, -14, -38, -8, -16, 1, 19, 16, -2, 12, 0, -10, 17, -25, -13, 12, 12, -20, 28, 6, -12, 15, 10, 40, 5, -49, -13, -6, 16, -29, -3, -5, -2, 7, 23, 11, -28, 21, -16, 28, 13, 3, 15, 11, 13, 14, 24, 12, -10, 19, 1, 36, -39, 19, 25, 1, -12, -11, -13, 3, -37, 27, -18, 15, -6, -16, 29, 16, 8, 5, 4, 24, 1, -18, -7, -17, -56, 5, 42, -6, 23, 15, 37, 12, 18, -19, 6, 9, 0, 36, -35, 14, -13, -18, 11, -25, -16, 17, -25, 54, -6, -31, 30, 2, 12, 27, 3, 1, -19, -13, -22, 29, -17, -46, 1, -4, -9, 8, 3, -10, 11, 35, 33, -29, -54, 24, -19, -19, 33, 14, -15, 5, 65, 11, 1, 4, 38, -13, 3, 13, 3, -2, 15, -20, 30, -6, -15, -12, -24, 8, 4, 8, 3, 15, 4, 14, -22, -26, 22, 9, 8, 2, 19, -3, 15, 6, -4, 24, 13, -48, 13, 8, -43, -29, 19, -1, 4, 16, -1, 7, -40, 1, -3, -24, 48, -10, -16, 10, -11, 11, 4, 12, -19, -21, 19, -11, -26, 6, -6, -21, 4, 14, 22, 19, -2, -11, 7, -6, -6, 21, 1, 7, 3, -10, 11, 29, 9, -17, -25, 6, 4, -21, -22, -5, -8, 13, -5, 7, -24, -14, 12, -15, 36, -26, -24, 4, -14, -9, -1, -14, 4, -80, -11, -9, 14, -22, 13, 5, 20, 17, -19, 4, 10, -49, 2, 10, -2, 8, -13, 12, 2, 1, 12, 27, 35, 0, -35, 4, 37, -4, -24, -8, -25, -36, -27, 13, 2, -48, -28, -11, -6, -9, -16, -9, -13, -7, -3, 5, -20, -2, -15, -28, 8, 6, 21, -17, 3, 0, -12, 22, -45, 5, -38, -54, -24, 22, 3, 3, 29, -7, 3, 30, -3, -23, -32, 10, 0, 16, -10, 4, 9, 25, 1, 9, 39, -1, -11, 18, 2, 9, -10, 23, 5, 27, 1, -31, 21, 0, -12, -6, 29, 7, -16, 21, -1, 26, 4, 10, 40, -52, 28, -24, 11, -8, -13, -15, 20, -8, -6, 0, 16, -19, 18, -8, 2, 19, -3, 8, -44, 1, 10, 2, -27, 9, 16, -21, -8, -4, -5, -4, -1, -1, -4, -4, 14, -21, 11, -15, 16, -4, -3, 10, 13, 18, 34, 0, 18, 12, 10, -19, 29, 24, 11, 4, 23, -27, -5, 23, 38, 9, -1, 0, 19, 43, -29, 29, -19, 20, -19, -12, 27, -11, 17, 23, 34, -38, 4, -14, -16, 13, -2, -11, 43, 7, -12, -12, -1, -1, -11, -6, -10, -1, 30, 7, 7, -10, 8, -16, -3, 9, -6, 4, 12, -28, 7, -11, 2, -7, -31, 6, -4, 10, -28, 46, -29, -7, -1, -6, 24, 9, -13, 3, 19, -17, 19, 13, 47, 19, 1, 26, 0, 5, -24, -13, 4, -24, 27, -6, 8, 4, 0, 9, 58, 10, 22, 15, 3, 5, 41, -14, 6, 12, 4, 21, 20, 30, -33, 16, 29, 28, 4, -17, 27, 18, 24, 15, 18, -40, 0, 8, 8, -26, -2, 20, 8, -4, 22, -18, 20, -1, 6, -34, -24, 14, -13, 14, -23, -26, 26, 16, -76, 7, 13, -48, -17, -44, -11, -23, 14, -16, 10, -17, -6, -58, -57, -24, -103, -22, 17, 4, -15, 12, 4, 16, -57, 14, 0, -47, 33, -9, 0, 10, 4, -9, 10, 7, -23, -16, -1, -28, -13, -1, -8, 0, 12, -18, -9, 10, -22, 28, -11, 29, -18, 5, 4, 7, -18, 2, 3, -5, -17, -24, 19, -1, 7, -6, 17, 8, 15, 13, -10, 15, -30, -18, 15, 34, -23, -10, 8, -9, -9, 8, 4, -16, 47, -63, -9, 7, -19, 4, 4, -10, 12, -4, 15, 15, 15, 17, -48, 23, -2, -17, 4, -4, 1, -14, 12, -28, -50, -11, -28, -28, -13, -11, 29, 2, -13, -4, -12, 12, -25, -9, -29, 7, -31, -25, -4, -4, 8, 8, 1, -13, -13, -69, -28, -20, -17, -2, 0, -1, -15, -2, -12, 15, -21, -15, -38, -12, -13, -30, 7, 29, 18, -6, 15, 10, 9, 11, -17, -13, -40}

#define TENSOR_CONV2D_25_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_25_BIAS_0 {-30, -9, -84, -20, -99, 74, 61, 1, 16, 74, 12, -1, 6, 74, 8, 56}

#define TENSOR_CONV2D_25_BIAS_0_DEC_BITS {8}

#define CONV2D_25_BIAS_LSHIFT {2}

#define CONV2D_25_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_26_KERNEL_0 {-28, 28, 7, -20, -11, 59, 9, 16, 25, 11, 25, 26, -6, 24, -3, -30, -24, 30, -23, -11, 5, -6, 36, 11, -11, 36, -12, -15, 14, 20, 33, 29, 32, 31, 51, 26, 8, 25, -21, -26, 12, 6, 9, 4, 32, -12, -19, -37, -2, 7, -4, 17, 14, -9, -6, -8, -3, 38, 36, 8, -5, -14, 9, -11, -26, -73, -4, 17, -47, -16, 21, 16, -56, 7, 3, 0, 29, -6, -59, -1, 52, -76, -14, -13, -53, 18, -3, 32, 15, -2, -5, 17, -24, 26, -14, 38, -3, -62, -10, -58, -22, 14, 21, -7, 40, -7, -27, -22, -65, 29, 17, 15, 16, -13, -10, -14, 12, -28, 30, -35, -37, 24, -1, 1, 15, -25, 4, 43, -16, 32, 13, 2, -20, 12, 15, 18, 28, 1, -33, -7, -55, 22, 34, -18, 13, 52, 15, -20, 20, 22, -4, 6, 7, -4, 24, -5, 13, -5, 38, -22, 7, -2, 31, 9, 48, -15, -13, 1, -34, -36, 25, 24, 16, -18, 19, -32, 1, -43, 11, 8, 28, -32, -38, 35, -27, -41, -25, 23, 23, -22, -5, 4, 24, 31, 24, 22, 8, 9, -2, 23, 22, -37, -38, 15, 34, 40, 9, 17, 27, 26, -26, -6, 15, 25, -24, -20, 50, 28, 11, -2, -12, -13, 27, 20, 46, -39, 9, -24, 9, 12, 21, 2, -15, 9, -13, -12, -13, 17, 8, -1, -1, 1, 22, -7, 0, -20, 39, -3, -48, 40, -7, -1, 14, 3, -8, 4, -6, 0, -12, 0, -17, 9, 20, -15, 9, 19, 6, 37, 26, -7, 24, -6, -11, -21, 4, 30, 10, -22, 20, 35, -16, -33, 25, 33, 3, 29, -11, -25, 34, 35, 12, 3, -26, 11, 49, 11, -28, 38, 39, 8, -24, -17, -23, -31, -4, -9, 18, -2, -26, 29, -15, 13, -31, 19, 4, 15, 5, -23, 20, -15, -20, -23, -43, 23, -51, -4, 15, -18, -28, -10, -3, 4, 16, 21, 24, 37, -29, 11, -47, 12, -57, -15, -8, 57, -10, -10, -2, 26, 26, 10, -31, -19, 14, -13, -14, 13, 15, -36, -28, -11, 10, 14, -23, -3, -16, 39, 12, 36, 12, 33, 15, 30, -5, 3, 3, -29, -4, 12, 26, -2, 44, -23, 10, -9}

#define TENSOR_CONV2D_26_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_26_BIAS_0 {11, -6, 15, 3, -6, -14, -10, 4, 5, 15, 5, -1}

#define TENSOR_CONV2D_26_BIAS_0_DEC_BITS {6}

#define CONV2D_26_BIAS_LSHIFT {0}

#define CONV2D_26_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_27_KERNEL_0 {-6, 15, 12, 1, -18, 16, -21, 9, -12, 3, -11, -16, 5, 7, 7, 2, -9, 7, -21, 11, 1, 12, -16, -12, -24, -19, 11, -10, 11, -13, 0, -35, -2, -6, 14, 4, 0, 2, 2, -14, -16, 5, 9, -31, -8, 13, -24, -9, -16, -9, -20, -11, 0, -8, 8, 14, -15, -27, 3, 12, -9, 11, -52, 14, 8, 2, -5, 1, 1, -21, -12, 1, -7, -4, 28, 10, -5, 1, -3, 8, -5, -15, 4, 2, -43, -3, 11, -15, -5, 16, -19, -29, 10, 11, 4, 1, -3, 9, -1, -23, 4, 10, -1, 22, -2, -33, -5, -6, -13, -15, -28, -14, 4, -5, 11, 9, -22, -19, -3, 4, 8, -40, -8, 6, 13, -14, 4, -8, 3, -7, -19, -3, -5, -13, -17, -5, -29, -64, -27, 5, 14, -6, 17, -8, -12, 4, 31, 13, 1, -1, -5, 10, -4, -10, -2, 5, -37, -10, 3, -17, 1, 9, -21, -24, 11, 13, 6, -1, -12, 8, -18, -13, -3, 7, 6, 0, -12, 0, -8, 8, -15, -4, -13, -9, -17, 11, -19, 19, 0, 6, -7, -2, -8, -17, 26, -6, 6, -7, 5, -18, -15, 6, -19, -34, 11, -17, -13, 14, -7, -5, 8, -1, -6, -10, -21, -10, -4, -3, 2, 15, -23, 21, -20, 12, -15, 7, -2, -8, 1, 3, 3, 23, -4, 9, 6, 6, 3, -8, -17, -35, 8, -2, -15, -12, 2, 8, 2, 4, -11, -2, -5, -12, -17, -5, 17, -6, -1, 3, 8, 0, -22, -43, 15, 13, -6, -35, -13, 9, -10, -45, -10, 5, 8, -16, 5, 15, -5, -13, 16, -18, 21, -32, -6, -5, 10, -1, 9, -18, -9, 3, 19, -13, -46, 5, -28, 5, -8, 18, 7, 2, 7, 2, 14, -9, -5, 2, 4, -7, 5, -8, -4, -27, -8, -9, 14, -5, -1, 5, 6, -22, -10, -10, 12, 11, 1, 10, -15, -21, 5, 12, -2, -25, 0, 2, 3, -8, 2, 5, -12, 18, -25, -5, -22, 16, 2, -3, 11, 15, -11, -8, 9, -10, -20, 2, -1, 1, 6, 2, 0, -11, -27, 1, -12, -36, 9, 10, 9, -10, -16, -3, -10, 13, -3, 1, -5, -11, -3, 3, -3, -4, 6, -8, 9, -5, -13, -34, 15, -5, -1, -58, 8, 2, 12, -1, 16, 11, 1, 8, 14, 7, -7, 5, 1, -7, -15, 2, -21, -23, -6, -2, -1, -8, 0, -6, -5, -8, -9, 5, -3, -9, 2, 3, 3, 3, -6, 1, -8, 1, -10, -3, -8, -8}

#define TENSOR_CONV2D_27_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_27_BIAS_0 {-2, 3, -11, -1, -9, 2, 4, -2, 0, -6, -2, 4, 4, -9, 5, -14, 1, 0}

#define TENSOR_CONV2D_27_BIAS_0_DEC_BITS {5}

#define CONV2D_27_BIAS_LSHIFT {0}

#define CONV2D_27_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_6_KERNEL_0 {-12, 11, 18, 13, -8, 12, -17, -33, 8, -38, -14, 16, 8, -24, 20, -5, 19, 13, -23, 10, -18, -37, 12, -8, -23, -24, -9, 3, 11, 9, -30, -32, -24, -2, 14, 7, 7, 10, 1, -31, -7, 20, -33, -32, -15, -39, 8, 7, -20, 4, -20, 5, 7, 9, 13, 13, 12, 5, 4, -2, 1, -34, -23, -50, -1, -23, 4, 1, -9, 11, 12, -11, 7, -77, -28, -73, -33, -62, -92, -55, -57, 15, -36, -68, -44, -36, -50, -39, -71, -4, -32, -22, -24, -22, -30, 15, -30, -29, 8, -30, -35, 9, 6, -4, 13, -30, 3, 3}

#define TENSOR_DENSE_6_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_6_BIAS_0 {-14, -10, -32, -3, 75, 4}

#define TENSOR_DENSE_6_BIAS_0_DEC_BITS {5}

#define DENSE_6_BIAS_LSHIFT {0}

#define DENSE_6_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define CONV2D_24_INPUT_OUTPUT_DEC 7
#define CONV2D_24_INPUT_OUTPUT_OFFSET 0
#define CONV2D_24_OUTPUT_DEC 4
#define CONV2D_24_OUTPUT_OFFSET 0
#define RE_LU_24_OUTPUT_DEC 4
#define RE_LU_24_OUTPUT_OFFSET 0
#define CONV2D_25_OUTPUT_DEC 2
#define CONV2D_25_OUTPUT_OFFSET 0
#define RE_LU_25_OUTPUT_DEC 2
#define RE_LU_25_OUTPUT_OFFSET 0
#define CONV2D_26_OUTPUT_DEC 1
#define CONV2D_26_OUTPUT_OFFSET 0
#define RE_LU_26_OUTPUT_DEC 1
#define RE_LU_26_OUTPUT_OFFSET 0
#define CONV2D_27_OUTPUT_DEC 0
#define CONV2D_27_OUTPUT_OFFSET 0
#define RE_LU_27_OUTPUT_DEC 0
#define RE_LU_27_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_6_OUTPUT_DEC 0
#define GLOBAL_MAX_POOLING2D_6_OUTPUT_OFFSET 0
#define FLATTEN_6_OUTPUT_DEC 0
#define FLATTEN_6_OUTPUT_OFFSET 0
#define DROPOUT_6_OUTPUT_DEC 0
#define DROPOUT_6_OUTPUT_OFFSET 0
#define DENSE_6_OUTPUT_DEC -1
#define DENSE_6_OUTPUT_OFFSET 0
#define SOFTMAX_6_OUTPUT_DEC 7
#define SOFTMAX_6_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3, 1};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {7};
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

const nnom_io_config_t conv2d_24_input_config = {
    .super = {.name = "conv2d_24_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_24_kernel_0_data[] = TENSOR_CONV2D_24_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_24_kernel_0_dim[] = {6, 2, 1, 24};
const nnom_qformat_param_t tensor_conv2d_24_kernel_0_dec[] = TENSOR_CONV2D_24_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_24_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_24_kernel_0 = {
    .p_data = (void*)tensor_conv2d_24_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_24_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_24_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_24_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_24_bias_0_data[] = TENSOR_CONV2D_24_BIAS_0;

const nnom_shape_data_t tensor_conv2d_24_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_conv2d_24_bias_0_dec[] = TENSOR_CONV2D_24_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_24_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_24_bias_0 = {
    .p_data = (void*)tensor_conv2d_24_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_24_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_24_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_24_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_24_output_shift[] = CONV2D_24_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_24_bias_shift[] = CONV2D_24_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_24_config = {
    .super = {.name = "conv2d_24"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_24_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_24_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_24_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_24_bias_shift, 
    .filter_size = 24,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_25_kernel_0_data[] = TENSOR_CONV2D_25_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_25_kernel_0_dim[] = {4, 2, 24, 16};
const nnom_qformat_param_t tensor_conv2d_25_kernel_0_dec[] = TENSOR_CONV2D_25_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_25_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_25_kernel_0 = {
    .p_data = (void*)tensor_conv2d_25_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_25_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_25_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_25_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_25_bias_0_data[] = TENSOR_CONV2D_25_BIAS_0;

const nnom_shape_data_t tensor_conv2d_25_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_25_bias_0_dec[] = TENSOR_CONV2D_25_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_25_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_25_bias_0 = {
    .p_data = (void*)tensor_conv2d_25_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_25_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_25_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_25_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_25_output_shift[] = CONV2D_25_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_25_bias_shift[] = CONV2D_25_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_25_config = {
    .super = {.name = "conv2d_25"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_25_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_25_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_25_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_25_bias_shift, 
    .filter_size = 16,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_26_kernel_0_data[] = TENSOR_CONV2D_26_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_26_kernel_0_dim[] = {2, 1, 16, 12};
const nnom_qformat_param_t tensor_conv2d_26_kernel_0_dec[] = TENSOR_CONV2D_26_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_26_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_26_kernel_0 = {
    .p_data = (void*)tensor_conv2d_26_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_26_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_26_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_26_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_26_bias_0_data[] = TENSOR_CONV2D_26_BIAS_0;

const nnom_shape_data_t tensor_conv2d_26_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_26_bias_0_dec[] = TENSOR_CONV2D_26_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_26_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_26_bias_0 = {
    .p_data = (void*)tensor_conv2d_26_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_26_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_26_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_26_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_26_output_shift[] = CONV2D_26_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_26_bias_shift[] = CONV2D_26_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_26_config = {
    .super = {.name = "conv2d_26"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_26_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_26_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_26_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_26_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_27_kernel_0_data[] = TENSOR_CONV2D_27_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_27_kernel_0_dim[] = {2, 1, 12, 18};
const nnom_qformat_param_t tensor_conv2d_27_kernel_0_dec[] = TENSOR_CONV2D_27_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_27_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_27_kernel_0 = {
    .p_data = (void*)tensor_conv2d_27_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_27_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_27_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_27_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_27_bias_0_data[] = TENSOR_CONV2D_27_BIAS_0;

const nnom_shape_data_t tensor_conv2d_27_bias_0_dim[] = {18};
const nnom_qformat_param_t tensor_conv2d_27_bias_0_dec[] = TENSOR_CONV2D_27_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_27_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_27_bias_0 = {
    .p_data = (void*)tensor_conv2d_27_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_27_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_27_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_27_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_27_output_shift[] = CONV2D_27_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_27_bias_shift[] = CONV2D_27_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_27_config = {
    .super = {.name = "conv2d_27"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_27_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_27_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_27_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_27_bias_shift, 
    .filter_size = 18,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_6_config = {
    .super = {.name = "global_max_pooling2d_6"},
    .output_shift = 0,
};

const nnom_flatten_config_t flatten_6_config = {
    .super = {.name = "flatten_6"}
};
const int8_t tensor_dense_6_kernel_0_data[] = TENSOR_DENSE_6_KERNEL_0;

const nnom_shape_data_t tensor_dense_6_kernel_0_dim[] = {18, 6};
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
	nnom_layer_t* layer[14];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_24_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_24_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_25_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_26_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_27_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_6_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_6_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_6_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_6_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //HAR_CNN_NNOM_H